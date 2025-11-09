#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

/*
  ------------------------------------------------------------------------------------------------------------------;
  DISK LAYOUT:
  Metadata               | Size (bytes)      | Blocks (2048 bytes)              |Start Block |  Comment
  ---------------------- | ----------------- | -------------------------------- |------------|-----------------------------------
  Bootloader/MBR         | 512 bytes         | 0.25 (1 sector)                  |  0         |
  Superblock             | 1024 bytes        | 1 block (2048 bytes, must align) |  0         |
                         |                   | 1 block (2048 bytes)             |  1         | reserved
  Block Bitmap           | 8,192 bytes       | 4 blocks                         |  2         | 4*2048*8 = 4*16384 = 65536 raw data blocks.  65536*2048 bytes = 134217728 bytes of disk space = 128MB
  Inode Bitmap           | 2,048 bytes       | 1 block                          |  6         | 2048*8=16384. total of 16384 bits, meaning 16384 inodes, which is 1 inode per 8KB of disk space
  Inode Table            | 2,097,152 bytes   | 1024 blocks                      |  7         | 128bytes per inode entry. 2097152 / 128 = 16384 inodes
  Data Blocks            | 134,217,728 bytes | 65536 blocks                     | 1031       | 65536 blocks = 134,217,728 bytes
  
  first 512 bytes: bootloader from 0 to 445, MBR partition table from 446 to 511 (64 bytes)
  up to 4 partitions, each 16 bytes long
  MBR:
  Byte | Description
  -----|----------------------------
  0    | Boot flag (0x80 active, 0x00 inactive)
  1-3  | Start CHS (head, sector, cylinder)
  4    | Partition type (filesystem ID)
    0x83 = Linux native (ext2/3/4)
    0x07 = NTFS/exFAT
    0x0B = FAT32 CHS
    0x0C = FAT32 LBA
    0x05 = Extended partition
    0x86 = Sol-1 partition
  5-7  | End CHS
  8-11 | Start LBA (little endian)
  12-15| Size in sectors (little endian)
  
  
  the superblock describers the filesystem as a whole such as inode count, free inode count, location of the raw data bitmap, 
  inode table, etc.  
  SUPERBLOCK:
  | Field               | Description                               | Typical Size (bytes) | Notes                           |
  | ------------------- | ----------------------------------------- | -------------------- | ------------------------------- |
  | inodes_count        | Total number of inodes in the filesystem  | 4                    | 32-bit unsigned int             |
  | blocks_count        | Total number of data blocks               | 4                    | 32-bit unsigned int             |
  | free_inodes_count   | Number of free inodes                     | 4                    | 32-bit unsigned int             |
  | free_blocks_count   | Number of free blocks                     | 4                    | 32-bit unsigned int             |
  | block_bitmap        | Block ID of the **block bitmap**          | 4                    | 32-bit unsigned int
  | inode_bitmap        | Block ID of the **inode bitmap**          | 4                    | 32-bit unsigned int
  | inode_table         | Starting block of **inode table**         | 4                    | 32-bit unsigned int
  | first_data_block    | Block number of the first data block      | 4                    | 32-bit unsigned int             |
  | used_dirs_count     | Number of inodes allocated to directories | 4
  | log_block_size      | Block size = 1024 << `s_log_block_size    | 4                    | 32-bit unsigned int             |
  | mtime               | Last mount time                           | 4                    | 32-bit unsigned int (Unix time) |
  | wtime               | Last write time                           | 4                    | 32-bit unsigned int (Unix time) |
  | uuid                | Unique ID of the filesystem               | 16                   | 128-bit UUID                    |
  | volume_name         | Label of the filesystem                   | 16                   | Usually ASCII, padded           |
  | feature_flags       | Compatibility flags                       | 4                    | 32-bit unsigned int             |
  
  inode for root dir is #2, #0 and #1 not used
  raw data block #0 is not used. because 0 as a block ID means not used
  block size: 2048
  inode-table format:
  | Field         | Size (bytes) | Description                                                                                  |
  | ------------- | ------------ | -------------------------------------------------------------------------------------------- |
  | `mode`        | 2            | File type and permissions                                                                    |
  | `uid`         | 2            | Owner user ID                                                                                |
  | `size`        | 4            | Size of the file in bytes                                                                    |
  | `atime`       | 4            | Last access time (timestamp)                                                                 |
  | `ctime`       | 4            | Creation time (timestamp)                                                                    |
  | `mtime`       | 4            | Last modification time (timestamp)                                                           |
  | `dtime`       | 4            | Deletion time (timestamp)                                                                    |
  | `gid`         | 2            | Group ID                                                                                     |
  | `links_count` | 2            | Number of hard links                                                                         |
  | `blocks`      | 4            | Number of 512-byte blocks allocated                                                          |
  | `flags`       | 4            | File flags                                                                                   |
  | `block`       | 15 x 4 = 60  | Pointers to data blocks (12 direct, 1 single indirect, 1 double indirect, 1 triple indirect) |


  DIRECTORY ENTRY
  this is the structure for file entries inside a directory.

   | Value | Meaning           |
   | ----- | ----------------- |
   | 0     | Unknown           |
   | 1     | Regular file      |
   | 2     | Directory         |
   | 3     | Character device  |
   | 4     | Block device      |
   | 5     | FIFO (named pipe) |
   | 6     | Socket            |
   | 7     | Symbolic link     |

  | FIELD   | SIZE     | DESCRIPTION
  | inode   |  4       | inode number (0 if entry is unused)
  | rec_len |  2       | total size of this entry, in bytes = 6 + len(name)
  | name    | variable | name (non null-terminated)

*/

#define BLOCK_SIZE 2048
#define BOOTLOADER_START 0
#define BOOTLOADER_SIZE 446  

#define MBR_START 446
#define MBR_SIZE 64

#define SIGNATURE_START 510
#define SIGNATURE_SIZE 2 

#define SUPERBLOCK_START 1024 // starts at block 0, position 1024
#define SUPERBLOCK_SIZE 1024  // 1024 bytes long

#define BLOCK_GROUP_DESCRIPTOR_START (1 * 2048) // starts a block 1
#define BLOCK_GROUP_DESCRIPTOR_SIZE 32          // 32 bytes long

#define BLOCKS_BITMAP_START (2 * 2048) // starts at block 2
#define BLOCKS_BITMAP_SIZE (4 * 2048)  // 4 blocks long

#define INODE_BITMAP_START (6 * 2048) // starts at block 6
#define INODE_BITMAP_SIZE 2048        // 1 block long

#define INODE_TABLE_START (7 * 2048)  // starts at block 7
#define INODE_TABLE_NUM_ENTRIES 16384 // 16384 entries of 128bytes
#define INODE_TABLE_SIZE (1024 * 2048)      // 1024 blocks long

#define DATA_BLOCKS_START (1031 * 2048) // start of disk data blocks
#define DATA_BLOCKS_SIZE (65536 * 2048)

#define TOTAL_DISK_SIZE (BOOTLOADER_SIZE + MBR_SIZE + SIGNATURE_SIZE + 512\
                       + SUPERBLOCK_SIZE + BLOCK_GROUP_DESCRIPTOR_SIZE + 2016\
                       + BLOCKS_BITMAP_SIZE + INODE_BITMAP_SIZE + INODE_TABLE_SIZE + DATA_BLOCKS_SIZE)

size_t loadfile_bootloader(const char *filename, uint8_t *dest);
size_t loadfile(const char *filename, char *dest);

struct superblock{
  uint32_t inodes_count     ; // Total number of inodes in the filesystem  
  uint32_t blocks_count     ; // Total number of data blocks         
  uint32_t free_inodes_count; // Number of free inodes                 
  uint32_t free_blocks_count; // Number of free blocks                
  uint32_t block_bitmap     ; // Block ID of the **block bitmap**
  uint32_t inode_bitmap     ; // Block ID of the **inode bitmap**
  uint32_t inode_table      ; // Starting block of **inode table**
  uint32_t first_data_block ; // Block number of the first data block   
  uint32_t used_dirs_count  ; // Number of inodes allocated to directories
  uint32_t log_block_size   ; // Block size = 1024 << `s_log_block_size` 
  uint32_t mtime            ; // Last mount time (unix time)              
  uint32_t wtime            ; // Last write time (unix time)              
  uint8_t  uuid[16]         ; // Unique ID of the filesystem            
  uint8_t  volume_name[16]  ; // Label of the filesystem               
  uint32_t feature_flags    ; // Compatibility flags                  
};

struct inode_table_entry{
  uint16_t mode       ; // File type and permissions 
  uint16_t uid        ; // Owner user ID
  uint32_t size       ; // Size of the file in bytes
  uint32_t atime      ; // Last access time (timestamp)
  uint32_t ctime      ; // Creation time (timestamp)
  uint32_t mtime      ; // Last modification time (timestamp)
  uint32_t dtime      ; // Deletion time (timestamp) 
  uint16_t gid        ; // Group ID         
  uint16_t links_count; // Number of hard links
  uint32_t blocks     ; // Number of blocks allocated (2048 blocks)
  uint32_t flags      ; // File flags
  uint32_t block[15]  ; // Pointers to data blocks (14 direct, 1 single indirect)
  uint8_t  padding[32]; // Padding
};

// | Value | Meaning           |
// | ----- | ----------------- |
// | 0     | Unknown           |
// | 1     | Regular file      |
// | 2     | Directory         |
// | 3     | Character device  |
// | 4     | Block device      |
// | 5     | FIFO (named pipe) |
// | 6     | Socket            |
// | 7     | Symbolic link     |
// each directory entry has a rec_len field which is its size. the last entry must take the remaining bytes of the block
// so that we can tell when the block ended. so in terms of entries, a block is virtually always filled totally.
// if a directory needs more than one block, we know that by the number of blocks attribute in the inode, as
// well as by checking which block pointers are used.
struct directory_entry {
    uint32_t inode;      // Inode number (0 if entry is unused)
    uint16_t rec_len;    // Total size of this directory entry, in bytes
    uint8_t  name_len;   // Length of the filename
    uint8_t  file_type;  // File type (see table below)
    char     name[];     // File name (NOT null-terminated)
};

void read_partition();

unsigned char disk[TOTAL_DISK_SIZE];
unsigned char mbr_data[] = {
  // partition 0
  0x80, 
  0x00, 0x00, 
  0x00,
  0x83,
  0x00, 0x00,
  0x00,
  0x01, 0x00,
  0x00, 0x00,
  0x00, 0x00,
  0x08, 0x00,
  // partition 1
  0x00, 
  0x00, 0x00, 
  0x00,
  0x83,
  0x00, 0x00,
  0x00,
  0x00, 0x00,
  0x00, 0x00,
  0x00, 0x00,
  0x00, 0x00,
  // partition 2
  0x00, 
  0x00, 0x00, 
  0x00,
  0x83,
  0x00, 0x00,
  0x00,
  0x00, 0x00,
  0x00, 0x00,
  0x00, 0x00,
  0x00, 0x00,
  // partition 3
  0x00, 
  0x00, 0x00, 
  0x00,
  0x83,
  0x00, 0x00,
  0x00,
  0x00, 0x00,
  0x00, 0x00,
  0x00, 0x00,
  0x00, 0x00
};

  unsigned char *p = disk;
  unsigned char *mbr_p = disk + MBR_START;
  unsigned char *signature_p = disk + SIGNATURE_START;
  unsigned char *superblock_p = disk + SUPERBLOCK_START;
  unsigned char *group_descriptor_p = disk + BLOCK_GROUP_DESCRIPTOR_START;
  unsigned char *data_blocks_p = disk + DATA_BLOCKS_START;
  unsigned char *inode_table_p = disk + INODE_TABLE_START;
  unsigned char *inode_bitmap_p = disk + INODE_BITMAP_START;
  unsigned char *blocks_bitmap_p = disk + BLOCKS_BITMAP_START;

int main(int argc, char **argv){

  struct superblock superblock;
  struct inode_table_entry inode_table_entry;
  struct inode_table_entry root_inode;
  struct inode_table_entry *inode_table_p = (struct inode_table_entry *)(disk + INODE_TABLE_START);
  
  if(argc > 1 && !strcmp(argv[1], "-r")){
    read_partition();
    exit(1);
  }

  // LOAD BOOTLOADER AND WRITE TO BOOT SECTOR
  if(loadfile_bootloader("../software/obj/boot.obj", disk) == -1){
    printf("Exiting...\n");
    return 0;
  };

  // COPY MBR TABLE TO DISK
  for(int i = 0; i < sizeof(mbr_data); i++){
    *(mbr_p + i) = mbr_data[i];
  }

  // SET BOOTLOADER SIGNATURE
  *(uint16_t *)(signature_p) = 0x55AA;

  // SUPERBLOCK
  // start block: 0
  // start offset: 1024
  // size: 1024 bytes
  superblock.inodes_count      = 16384; // Total number of inodes in the filesystem  
  superblock.blocks_count      = 65535; // Total number of data blocks         
  superblock.free_inodes_count = 16384; // Number of free inodes                 
  superblock.free_blocks_count = 65535; // Number of free blocks                
  superblock.block_bitmap      = 2; // Block ID of the **block bitmap**
  superblock.inode_bitmap      = 6; // Block ID of the **inode bitmap**
  superblock.inode_table       = 7; // Starting block of **inode table**
  superblock.first_data_block  = 0; // Block number of the first data block   
  superblock.used_dirs_count   = 1; // Number of inodes allocated to directories
  superblock.log_block_size    = 1; // Block size = 1024 << `s_log_block_size` 
  superblock.mtime             = 0; // Last mount time (unix time)              
  superblock.wtime             = 0; // Last write time (unix time)              
  memset(superblock.uuid, 0, 16); // Unique ID of the filesystem            
  strcpy(superblock.volume_name, "Sol-1 Volume"); // Label of the filesystem               
  superblock.feature_flags     = 0; // Compatibility flags                  
  *(struct superblock *)(superblock_p) = superblock;

  
  // BLOCK BITMAP
  // start block: 2
  // start offset: 4096
  // size = 4 * 2048 = 8192 bytes
  for(int i = 0; i < BLOCKS_BITMAP_SIZE; i++){
    *(blocks_bitmap_p + i) = 0; // set each bitmap byte to 0
  }

  // INODE BITMAP
  // start block: 6
  // start offset: 12288
  // size = 1 block = 2048 bytes
  for(int i = 0; i < 2048; i++){
    *(inode_bitmap_p + i) = 0; // set each bitmap byte to 0
  }

  // INODE TABLE
  // start block: 7
  // start offset: 14336
  // size = 1024 blocks = 2,097,152 bytes
  inode_table_entry.mode        = 0; // File type and permissions 
  inode_table_entry.uid         = 0; // Owner user ID
  inode_table_entry.size        = 0; // Size of the file in bytes
  inode_table_entry.atime       = 0; // Last access time (timestamp)
  inode_table_entry.ctime       = 0; // Creation time (timestamp)
  inode_table_entry.mtime       = 0; // Last modification time (timestamp)
  inode_table_entry.dtime       = 0; // Deletion time (timestamp) 
  inode_table_entry.gid         = 0; // Group ID         
  inode_table_entry.links_count = 0; // Number of hard links
  inode_table_entry.blocks      = 0; // Number of 512-byte blocks allocated 
  inode_table_entry.flags       = 0; // File flags
  memset(inode_table_entry.block, 0, 15 * 4); // Pointers to data blocks (12 direct, 1 single indirect, 1 double indirect, 1 triple indirect)
  memset(inode_table_entry.padding, 0, 32); // Padding

  // reset entire inode table to unused
  for(int i = 0; i < INODE_TABLE_NUM_ENTRIES; i++){
    *(inode_table_p + i) = inode_table_entry;
    //*(struct inode_table_entry *)(p + INODE_TABLE_START + sizeof(inode_table_entry) * i) = inode_table_entry;
  }

  // CREATE ROOT DIRECTORY
  memset(&root_inode, 0, sizeof(root_inode)); // reset entire inode
  root_inode.mode        = 0x41ED;   // directory (0x4000) + rwxr-xr-x (0x1ED)
  root_inode.uid         = 0;        // root user
  root_inode.gid         = 0;
  root_inode.size        = 2048;     // one block for the directory
  root_inode.atime       = root_inode.ctime = root_inode.mtime = time(NULL);
  root_inode.links_count = 2;        // "." and parent ("..")
  root_inode.blocks      = (2048 / 512); // 4 (number of 512-byte sectors)
  root_inode.block[0]    = 1;
  *(inode_table_p + 2) = root_inode; // write to inode #2 for root

  // SET INODE #2 BITMAP BIT TO USED
  *(inode_bitmap_p + 2) = 1;

  // SET DATA BLOCK BITMAP BIT #1 TO USED (BLOCK #0 IS NEVER USED, SO STARTING AT #1)
  *(blocks_bitmap_p + 1) = 1; 

  // ADD . AND .. ENTRIES TO DATA BLOCK
  memset(p + DATA_BLOCKS_START, 0, BLOCK_SIZE);
  int offset = 0;

  // Entry 1: "."
  struct directory_entry *dot = (struct directory_entry *)(data_blocks_p + offset);
  dot->inode = 2;
  dot->rec_len = 12;
  dot->name_len = 1;
  dot->file_type = 2;
  memcpy(dot->name, ".", 1);
  offset += dot->rec_len;

  // Entry 2: ".."
  struct directory_entry *dotdot = (struct directory_entry *)(data_blocks_p + offset);
  dotdot->inode = 2;
  dotdot->rec_len = BLOCK_SIZE - offset;
  dotdot->name_len = 2;
  dotdot->file_type = 2;
  memcpy(dotdot->name, "..", 2);


  // generate disk image file
  FILE *f = fopen("disk.bin", "wb"); // open for writing in binary mode
  if (!f) {
      perror("Failed to open file");
      return 1;
  }

  // fwrite(pointer, size_of_each_item, number_of_items, file_pointer)
  size_t written = fwrite(disk, 1, TOTAL_DISK_SIZE, f);
  if (written != TOTAL_DISK_SIZE) {
      perror("Failed to write all bytes");
      fclose(f);
      return 1;
  }
  fclose(f);

  return 1;
}

size_t loadfile_bootloader(const char *filename, uint8_t *dest) {
  FILE *fp = fopen(filename, "rb");
  if (!fp) {
      printf("ERROR: '%s' not found.\n", filename);
      exit(1);
  }
  size_t size = fread(dest, 1, 446, fp); // only read up to bootloader size
  fclose(fp);
  return size;
}

size_t loadfile(const char *filename, char *dest) {
  FILE *fp = fopen(filename, "rb");
  if (!fp) {
    printf("ERROR: '%s' not found.\n", filename);
    exit(1);
  }

  // Get file size
  fseek(fp, 0, SEEK_END);
  size_t filesize = ftell(fp);
  rewind(fp);

  // Read entire file
  size_t read_bytes = fread(dest, 1, filesize, fp);
  fclose(fp);

  if (read_bytes != filesize) {
    printf("ERROR: Could not read entire file.\n");
    exit(1);
  }
  return filesize;
}

void read_partition(){
  uint32_t inodes_count     ; // Total number of inodes in the filesystem  
  uint32_t blocks_count     ; // Total number of data blocks         
  uint32_t free_inodes_count; // Number of free inodes                 
  uint32_t free_blocks_count; // Number of free blocks                
  uint32_t block_bitmap     ; // Block ID of the **block bitmap**
  uint32_t inode_bitmap     ; // Block ID of the **inode bitmap**
  uint32_t inode_table      ; // Starting block of **inode table**
  uint32_t first_data_block ; // Block number of the first data block   
  uint32_t used_dirs_count  ; // Number of inodes allocated to directories
  uint32_t log_block_size   ; // Block size = 1024 << `s_log_block_size` 
  uint32_t mtime            ; // Last mount time (unix time)              
  uint32_t wtime            ; // Last write time (unix time)              
  uint8_t  uuid[16]         ; // Unique ID of the filesystem            
  uint8_t  volume_name[16]  ; // Label of the filesystem               
  uint32_t feature_flags    ; // Compatibility flags                  

  time_t t_mtime;
  time_t t_wtime;

  struct superblock *superblock = (struct superblock *)superblock_p;

  int size = loadfile("disk.bin", disk);

  inodes_count      = superblock->inodes_count      ; // Total number of inodes in the filesystem  
  blocks_count      = superblock->blocks_count      ; // Total number of data blocks         
  free_inodes_count = superblock->free_inodes_count ; // Number of free inodes                 
  free_blocks_count = superblock->free_blocks_count ; // Number of free blocks                
  block_bitmap      = superblock->block_bitmap      ; // Block ID of the **block bitmap**
  inode_bitmap      = superblock->inode_bitmap      ; // Block ID of the **inode bitmap**
  inode_table       = superblock->inode_table       ; // Starting block of **inode table**
  first_data_block  = superblock->first_data_block  ; // Block number of the first data block   
  used_dirs_count   = superblock->used_dirs_count   ; // Number of inodes allocated to directories
  log_block_size    = superblock->log_block_size    ; // Block size = 1024 << `s_log_block_size` 
  mtime             = superblock->mtime             ; // Last mount time (unix time)              
  wtime             = superblock->wtime             ; // Last write time (unix time)              
  feature_flags     = superblock->feature_flags     ; // Compatibility flags                  
  memcpy(volume_name, superblock->volume_name, 16)  ; // Label of the filesystem               
  memcpy(uuid, superblock->uuid, 16)                ; // Unique ID of the filesystem            
 
  t_mtime = (time_t)mtime;
  t_wtime = (time_t)wtime;

  printf("\n");
  printf("Volume name: %s\n", volume_name);
  printf("Inodes Count: %d\n", inodes_count);
  printf("Blocks Count: %d\n", blocks_count);
  printf("Free Inodes Count: %d\n", free_inodes_count);
  printf("Free Blocks Count: %d\n", free_blocks_count);
  printf("Block Bitmap: %d\n", block_bitmap);
  printf("Inode Bitmap: %d\n", inode_bitmap);
  printf("Inode Table: %d\n", inode_table);
  printf("First Data Block: %d\n", first_data_block);
  printf("Used Dirs Count: %d\n", used_dirs_count);
  printf("Log Block Size: %d\n", log_block_size);
  printf("mtime: %s", ctime((time_t*)&t_mtime));
  printf("wtime: %s", ctime((time_t*)&t_wtime));
  printf("Feature Flags: %x\n", feature_flags);
  printf("uuid: ");
  for(int i = 15; i >= 0; i--){
    printf("%02x ", uuid[i]);
  }

  printf("\n\n");
}