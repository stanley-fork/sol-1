.include "lib/kernel.exp"
.org text_org

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; FFC0    5.25" Floppy Drive Block
;   - FFC0  (Last 4 bits: 0000)    Output Port (377 Flip-Flop)                       Note: A3 Address line = 0
;   - FFC1  (Last 4 bits: 0001)    Input Port  (244 Buffer)                          Note: A3 Address line = 0
;   - FFC8  (Last 4 bits: 1000)    FDC         (WD1770 Floppy Drive Controller)      Note: A3 Address line = 1
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; floppy drive system calls
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; fdc_40_FF:     .fill 40,  $FF  ; or 00                                                                                
; fdc_6_00_0:    .fill 6,   $00  ;                                                                            <--|        
; fdc_id_fe:     .fill 1,   $FE  ; ID Address Mark                                                               |        
; fdc_track:     .fill 1,   $00  ; Track Number                                                                  |                    
; fdc_side:      .fill 1,   $00  ; Side Number 00 or 01                                                          |                
; fdc_sector:    .fill 1,   $01  ; Sector Number  1 through 10                                                   |                              
; fdc_length:    .fill 1,   $00  ; Sector Length                                                                 |                        
; fdc_2_crc_0:   .fill 1,   $F7  ; 2 CRC's Written                                                               | Write 16 times                 
; fdc_11_ff:     .fill 11,  $FF  ; or 00                                                                         |                      
; fdc_6_00_1:    .fill 6,   $00  ;                                                                               |                        
; fdc_data_addr: .fill 1,   $FB  ; Data Address Mark                                                             |                                  
; fdc_data:      .fill 128, $E5  ; Data (IBM uses E5)                                                            |                                      
; fdc_2_crc_1:   .fill 1,   $F7  ; 2 CRC's Written                                                               |                                                        
; fdc_10_ff:     .fill 10,  $FF  ; or 00                                                                      <--|                                                  
; fdc_369_ff:    .fill 369, $FF  ; or 00. Continue writing until wd1770 interrupts out. approx 369 bytes.                                                                
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; _FDC_CONFIG       .equ $FFC0 
; _FDC_STATUS_1     .equ $FFC1
; _FDC_WD_STAT_CMD  .equ $FFC8
; _FDC_WD_TRACK     .equ $FFC9
; _FDC_WD_SECTOR    .equ $FFCA
; _FDC_WD_DATA      .equ $FFCB
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
main:
  mov bp, $FFFF
  mov sp, $FFFF

  mov d, str0
  call _puts
  ; First, select drive 1 and de-select drive 0
  mov d, $FFC0    ; floppy configuration output port
  mov al, 2       ; setparam call
  mov bl, $09     ; %00001001 : turn LED on, disable double density, select side 0, select drive 1, do not select drive 0
  syscall sys_system

  mov d, str1
  call _puts
; wait a little
  mov c, $FF
loop1:
  dec c
  cmp c, 0
  jnz loop1

  mov d, str2
  call _puts
; send restore command
  mov d, $FFC8    ; wd1770
  mov al, 2       ; setparam call
  mov bl, $03     ; restore command, 30ms rate
  syscall sys_system

  mov d, str1
  call _puts
; wait a little
  mov c, $FF
loop2:
  dec c
  cmp c, 0
  jnz loop2

  mov d, $FFC1    ; floppy input port
  mov al, 4       ; getparam
  syscall sys_system
  mov d, str3
  call _puts
  call print_u8x  ; print vlue in 'bl'
  call printnl

  syscall sys_terminate_proc

str0: .db $a, $d, "selecting drive 1...", $a, $d, 0
str1: .db $a, $d, "waiting...", $a, $d, 0
str2: .db $a, $d, "sending restore command...", $a, $d, 0
str3: .db $a, $d, "floppy status register: ", 0

.include "lib/stdio.asm"
.end
