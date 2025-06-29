; ------------------------------------------------------------------------------------------------------------------;
; Solarium - Sol-1 Homebrew Minicomputer Operating System Kernel.
; ------------------------------------------------------------------------------------------------------------------;

; memory map
; ------------------------------------------------------------------------------------------------------------------;
; 0000 ... 7fff - rom space
; 8000 ... f7ff - ram space
; f7ff          - stack root

; i/o map
; ------------------------------------------------------------------------------------------------------------------;
; ff80 - uart 0 (16550)
; ff90 - uart 1 (16550)
; ffa0 - rtc    (m48t02)
; ffb0 - pio 0  (8255)
; ffc0 - fdd    (5.25" floppy drive block)
;   - ffc0      output port (377 flip-flop)                  
;   - ffc1      input port  (244 buffer)                     
;   - ffc8      wd1770 status/command    
;   - ffc9      wd1770 track register
;   - ffca      wd1770 sector register
;   - ffcb      wd1770 data register
;      
; ffd0 - ide    (compact flash / pata)
; ffe0 - timer  (8253)
; fff0 - bios configuration nv-ram store area
; ------------------------------------------------------------------------------------------------------------------;

; ------------------------------------------------------------------------------------------------------------------;
; system constants
; ------------------------------------------------------------------------------------------------------------------;
_uart0_data       .equ $ff80         ; data
_uart0_dlab_0     .equ $ff80         ; divisor latch low byte
_uart0_dlab_1     .equ $ff81         ; divisor latch high byte
_uart0_ier        .equ $ff81         ; interrupt enable register
_uart0_fcr        .equ $ff82         ; fifo control register
_uart0_lcr        .equ $ff83         ; line control register
_uart0_lsr        .equ $ff85         ; line status register

_uart1_data       .equ $ff90         ; data
_uart1_dlab_0     .equ $ff90         ; divisor latch low byte
_uart1_dlab_1     .equ $ff91         ; divisor latch high byte
_uart1_ier        .equ $ff91         ; interrupt enable register
_uart1_fcr        .equ $ff92         ; fifo control register
_uart1_lcr        .equ $ff93         ; line control register
_uart1_lsr        .equ $ff95         ; line status register

_ide_base         .equ $ffd0         ; ide base
_ide_r0           .equ _ide_base + 0 ; data port
_ide_r1           .equ _ide_base + 1 ; read: error code, write: feature
_ide_r2           .equ _ide_base + 2 ; number of sectors to transfer
_ide_r3           .equ _ide_base + 3 ; sector address lba 0 [0:7]
_ide_r4           .equ _ide_base + 4 ; sector address lba 1 [8:15]
_ide_r5           .equ _ide_base + 5 ; sector address lba 2 [16:23]
_ide_r6           .equ _ide_base + 6 ; sector address lba 3 [24:27 (lsb)]
_ide_r7           .equ _ide_base + 7 ; read: status, write: command       

_7seg_display     .equ $ffb0         ; bios post code hex display (2 digits) (connected to pio a)
_bios_post_ctrl   .equ $ffb3         ; bios post display control register, 80h = as output
_pio_a            .equ $ffb0    
_pio_b            .equ $ffb1
_pio_c            .equ $ffb2
_pio_control      .equ $ffb3         ; pio control port

_fdc_config       .equ $ffc0         ; 0 = select_0, 1 = select_1, 2 = side_select, 3 = dden, 4 = in_use_or_head_load, 5 = wd1770_rst
_fdc_status_1     .equ $ffc1         ; 0 = drq, 1 = ready
_fdc_stat_cmd     .equ $ffc8         ; status / command register
_fdc_track        .equ $ffc9         ; track register
_fdc_sector       .equ $ffca         ; sector register
_fdc_data         .equ $ffcb         ; data register

_timer_c_0        .equ $ffe0         ; timer counter 0
_timer_c_1        .equ $ffe1         ; timer counter 1
_timer_c_2        .equ $ffe2         ; timer counter 2
_timer_ctrl       .equ $ffe3         ; timer control register

stack_begin       .equ $f7ff         ; beginning of stack
fifo_size         .equ 1024

text_org          .equ $400          ; code origin address for all user processes


; ------------------------------------------------------------------------------------------------------------------;
; global system variables
; ------------------------------------------------------------------------------------------------------------------;

; ------------------------------------------------------------------------------------------------------------------;
; irq table
; highest priority at lowest address
; ------------------------------------------------------------------------------------------------------------------;
.dw int_0_fdc
.dw int_1
.dw int_2
.dw int_3
.dw int_4
.dw int_5
.dw int_6
.dw int_7_uart0

; ------------------------------------------------------------------------------------------------------------------;
; kernel reset vector
; ------------------------------------------------------------------------------------------------------------------;
.dw kernel_reset_vector

; ------------------------------------------------------------------------------------------------------------------;
; exception vector table
; total of 7 entries, starting at address $0012
; ------------------------------------------------------------------------------------------------------------------;
.dw trap_privilege
.dw trap_div_zero
.dw trap_undef_opcode
.dw 0
.dw 0
.dw 0
.dw 0

; ------------------------------------------------------------------------------------------------------------------;
; system call vector table
; starts at address $0020
; ------------------------------------------------------------------------------------------------------------------;
.dw syscall_break
.dw syscall_rtc
.dw syscall_ide
.dw syscall_io
.dw syscall_datetime
.dw syscall_reboot
.dw syscall_system
.dw syscall_fdc

; ------------------------------------------------------------------------------------------------------------------;
; system call aliases
; ------------------------------------------------------------------------------------------------------------------;
sys_break            .equ 0
sys_rtc              .equ 1
sys_ide              .equ 2
sys_io               .equ 3
sys_datetime         .equ 4
sys_reboot           .equ 5
sys_system           .equ 6
sys_fdc              .equ 7

; ------------------------------------------------------------------------------------------------------------------;
; alias exports
; ------------------------------------------------------------------------------------------------------------------;
.export text_org
.export sys_break
.export sys_rtc
.export sys_ide
.export sys_io
.export sys_datetime
.export sys_reboot
.export sys_system
.export sys_fdc

; ------------------------------------------------------------------------------------------------------------------;
; irqs' code block
; ------------------------------------------------------------------------------------------------------------------;
; 5.25" floppy drive controller irq
int_0_fdc:
  mov d, s_fdc_irq
  call _puts
  sysret
int_1:
  sysret
int_2:
  sysret
int_3:
  sysret
int_4:
  sysret
int_5:
  sysret

; ------------------------------------------------------------------------------------------------------------------;
; process swapping
; ------------------------------------------------------------------------------------------------------------------;
int_6:  
  sysret

; ------------------------------------------------------------------------------------------------------------------;
; uart0 interrupt
; ------------------------------------------------------------------------------------------------------------------;
int_7_uart0:
  push a
  push d
  pushf
  mov a, [fifo_in]
  mov d, a
  mov al, [_uart0_data]       ; get character
  mov [d], al                 ; add to fifo
  mov a, [fifo_in]
  inc a
  cmp a, fifo + fifo_size     ; check if pointer reached the end of the fifo
  jne int_7_continue
  mov a, fifo  
int_7_continue:  
  mov [fifo_in], a            ; update fifo pointer
  popf
  pop d
  pop a  
  sysret

; ------------------------------------------------------------------------------------------------------------------;
; floppy drive syscalls
; ------------------------------------------------------------------------------------------------------------------;
; data for formatting a floppy drive in single density mode (128 bytes per sector):
; fdc_40_ff:
;   .fill 40,  $ff    ; or 00                                                                                
; fdc_128_format_inner:
;   .fill 6,   $00    ;                                                                            <--|        
;   .fill 1,   $fe    ; id address mark                                                               |        
;   .fill 1,   $00    ; track number  0 thru 39                                                       |                    
;   .fill 1,   $00    ; side number 00 or 01                                                          |                
;   .fill 1,   $01    ; sector number  0x01 through 0x10                                              |                              
;   .fill 1,   $00    ; sector length                                                                 |                        
;   .fill 1,   $f7    ; 2 crc's written                                                               | write 16 times                 
;   .fill 11,  $ff    ; or 00                                                                         |                      
;   .fill 6,   $00    ;                                                                               |                        
;   .fill 1,   $fb    ; data address mark                                                             |                                  
;   .fill 128, $e5    ; data (ibm uses e5)                                                            |                                      
;   .fill 1,   $f7    ; 2 crc's written                                                               |                                                        
;   .fill 10,  $ff    ; or 00                                                                      <--|                                                  
; fdc_128_format_end:
;   .fill 369, $ff    ; or 00. continue writing until wd1770 interrupts out. approx 369 bytes.                                                                
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
fdc_jmptbl:
  .dw syscall_fdc_restore
  .dw syscall_fdc_step
  .dw syscall_fdc_step_in
  .dw syscall_fdc_step_out
  .dw syscall_fdc_seek
  .dw syscall_fdc_format
  .dw syscall_fdc_read_addr
  .dw syscall_fdc_read_track
  .dw syscall_fdc_read_sect
  .dw syscall_fdc_write_sect
  .dw syscall_fdc_force_int
syscall_fdc:
  jmp [fdc_jmptbl + al]

syscall_fdc_restore:
  mov byte [_fdc_stat_cmd], %00001000
  sysret

syscall_fdc_step:
  sysret

syscall_fdc_step_in:
  mov byte [_fdc_stat_cmd], %01010000
  sysret

syscall_fdc_step_out:
  mov byte [_fdc_stat_cmd], %01111000
  sysret

syscall_fdc_seek:
  sysret

syscall_fdc_read_addr:
  sysret

syscall_fdc_force_int:
  sysret

; when writing the actual code for formatting multiple tracks, remember to change the track number byte
; in the ram formatting block because they are all set as 00 right now
; bl: track number
syscall_fdc_format:
  mov [_fdc_track], bl
  mov byte [_fdc_stat_cmd], %11111010 ; write track command: {1111, 0: enable spin-up seq, 1: settling delay, 1: no write precompensation, 0}
;fdc_wait_busy_high:
;  mov al, [_fdc_wd_stat_cmd]      ; 
;  test al, $01                ; 
;  jz fdc_wait_busy_high
  mov si, transient_area
  lodsb
  mov [_fdc_data], al      ; 10   
  call fdc_wait_64us
fdc_format_drq:
  mov al, [_fdc_stat_cmd]  ; 10
  test al, $01                ; 4
  jz fdc_format_end           ; 8
  test al, $02                ; 4
  jz fdc_format_drq           ; 8
  lodsb                       ; 7
  mov [_fdc_data], al      ; 10   
  jmp fdc_format_drq
fdc_format_end:
  sysret

syscall_fdc_read_track:
  mov byte [_fdc_stat_cmd], %11101000
  call fdc_wait_64us
;fdc_wait_busy_high1:
;  mov al, [_fdc_wd_stat_cmd]      ; 
;  test al, $01                    ; 
;  jz fdc_wait_busy_high1
  mov di, transient_area
fdc_read_track_l0: ; for each byte, we need to wait for drq to be high
  mov al, [_fdc_stat_cmd]      ; 
  test al, $01                ; check busy bit
  jz fdc_read_track_end
  test al, $02                ; check drq bit
  jz fdc_read_track_l0
  mov al, [_fdc_data]     ; 
  stosb
  jmp fdc_read_track_l0
;we need to check if writing to data reg causes a spurious read. so lets check inside the writing loop, how many times we actually write the bytes
;say the 40 byte loop. if we find that we only write ~20 times, then this indcates this problem.
;because for every write, if it also reads, then that clears drq, so we need to wait for next drq.
fdc_read_track_end:
  mov a, di
  sub a, transient_area
  sysret

; sector in al
; track in ah
syscall_fdc_read_sect:
  mov [_fdc_sector], al
  mov al, ah
  mov [_fdc_track], al
  mov byte [_fdc_stat_cmd], %10001000
  call fdc_wait_64us
;fdc_wait_busy_high2:
;  mov al, [_fdc_wd_stat_cmd]      ; 
;  test al, $01                ; 
;  jz fdc_wait_busy_high2
  mov di, transient_area
fdc_read_sect_l0: ; for each byte, we need to wait for drq to be high
  mov al, [_fdc_stat_cmd]      ; read lost data flag 10+3+5+8+5+8
  test al, $01                ; check drq bit
  jz fdc_read_sect_end
  test al, $02                ; check drq bit
  jz fdc_read_sect_l0
  mov al, [_fdc_data]     ; 
  stosb
  jmp fdc_read_sect_l0
fdc_read_sect_end:
  mov a, di
  sub a, transient_area
  sysret

; sector in al
; track in ah
; data pointer in si
syscall_fdc_write_sect:
  mov [_fdc_sector], al
  mov al, ah
  mov [_fdc_track], al
  mov byte [_fdc_stat_cmd], %10101010            ; 101, 0:single sector, 1: disable spinup, 0: no delay, 1: no precomp, 0: normal data mark
;fdc_wait_busy_high2:
;  mov al, [_fdc_wd_stat_cmd]    
;  test al, $01                
;  jz fdc_wait_busy_high2
  lodsb                      
  mov [_fdc_data], al      
  call fdc_wait_64us
fdc_write_sect_l0: ; for each byte, we need to wait for drq to be high
  mov al, [_fdc_stat_cmd]  ; 10
  test al, $01                ; 4
  jz fdc_write_sect_end           ; 8
  test al, $02                ; 4
  jz fdc_write_sect_l0           ; 8
  lodsb                       ; 7
  mov [_fdc_data], al      ; 10   
  jmp fdc_write_sect_l0
fdc_write_sect_end:
  sysret

fdc_format_mem:
  mov d, 1
  mov di, transient_area
; 40 * FF
  mov c, 40
  mov al, $ff
fdc_l0: 
  stosb
  dec c
  jnz fdc_l0
; 6 * 00
fdc_inner_loop:
  mov c, 6
  mov al, $00
fdc_l1:
  stosb
  dec c
  jnz fdc_l1
; FE address mark
fdc_l2:
  mov al, $fe
  stosb
; track number
fdc_l3:
  mov al, $00
  stosb
; side number
fdc_l4:
  mov al, $00
  stosb
; sector number
fdc_l5:
  mov a, d
  stosb
; sector length 128 bytes
fdc_l6:
  mov al, $00
  stosb
; 2 crc's
fdc_l7:
  mov al, $f7
  stosb
; 11 times $ff
  mov c, 11
  mov al, $ff
fdc_l8:
  stosb
  dec c
  jnz fdc_l8
; 6 times 00
  mov c, 6
  mov al, $00
fdc_l9:
  stosb
  dec c
  jnz fdc_l9
; FB data address mark
  mov al, $fb
fdc_l10:
  stosb
; 128 bytes sector data
  mov c, 128
  mov al, $E5
fdc_l11:
  stosb
  dec c
  jnz fdc_l11
; 2 crc's
fdc_l12:
  mov al, $f7
  stosb
; 10 * $FF
  mov c, 10
  mov al, $ff
fdc_l13:
  stosb
  dec c
  jnz fdc_l13
; check whether we did this 16 times
  inc d
  cmp d, 17
  jne fdc_inner_loop
; 500 bytes of FF for end filler. wd1770 writes these until it finishes, so the number varies. usually it writes ~450 bytes
  mov c, 500
  mov al, $ff
fdc_format_footer:
fdc_footer_drq_loop:
  stosb
  dec c
  jnz fdc_footer_drq_loop
  ret

; fetch is 2 cycles long when 'display_reg_load' is false.
; 64us amounts to 160 cycles of the 2.5mhz clock
; call u16 is 14 cycles long
; 160 - 5 - 14 = 
fdc_wait_64us:
  mov cl, 13                       ; 5 cycles
fdc_wait_64_loop:
  dec cl                           ; 3 cycles
  jnz fdc_wait_64_loop             ; 8 cycles
  ret

; ------------------------------------------------------------------------------------------------------------------;
; system syscalls
; ------------------------------------------------------------------------------------------------------------------;
system_jmptbl:
  .dw system_uname
  .dw system_whoami
  .dw system_setparam
  .dw system_bootloader_install
  .dw system_getparam
syscall_system:
  jmp [system_jmptbl + al]

; param register address in register d
; param value in register bl
system_getparam:
  mov bl, [d]
  sysret

; param register address in register d
; param value in register bl
system_setparam:
  mov [d], bl
  sysret

; kernel LBA address in 'b'
system_bootloader_install:
  push b
  mov b, 0
  mov c, 0
  mov ah, $01                 ; 1 sector
  mov d, transient_area
  call ide_read_sect          ; read sector
  pop b
  mov [d + 510], b            ; update LBA address
  mov b, 0
  mov c, 0
  mov ah, $01                 ; 1 sector
  mov d, transient_area
  call ide_write_sect         ; write sector
  sysret

system_uname:
  mov d, s_uname
  call _puts
  sysret

system_whoami:
  sysret

; reboot system
syscall_reboot:
  push word $ffff 
  push byte %00000000             ; dma_ack = 0, interrupts disabled, mode = supervisor, paging = off, halt=0, display_reg_load=0, dir=0
  push word bios_reset_vector     ; and then push reset vector of the shell to the stack
  sysret

; ------------------------------------------------------------------------------------------------------------------;
; exceptions code block
; ------------------------------------------------------------------------------------------------------------------;
; privilege exception
; ------------------------------------------------------------------------------------------------------------------;
trap_privilege:
  jmp syscall_reboot
  push d
  mov d, s_priviledge
  call _puts
  pop d
  sysret

; ------------------------------------------------------------------------------------------------------------------;
; breakpoint
; important: values in the stack are being pushed in big endian. i.e.: msb at low address
; and lsb at high address. *** need to correct this in the microcode and make it little endian again ***
; ------------------------------------------------------------------------------------------------------------------;
syscall_break:
  pusha
syscall_break_prompt:
  mov d, s_break1
  call _puts
  call printnl
  call scan_u16d
  cmp a, 0
  je syscall_break_regs
  cmp a, 1
  je syscall_break_mem
syscall_break_end:  
  popa
  sysret
syscall_break_regs:
  mov a, sp
  add a, 14               ; back-track 7 registers
  mov d, a
  mov cl, 7
syscall_regs_l0:
  mov b, [d]
  swp b
  call print_u16x         ; print register value
  call printnl
  sub d, 2
  sub cl, 1
  cmp cl, 0
  jne syscall_regs_l0
  jmp syscall_break_prompt
  call printnl
  jmp syscall_break_prompt
syscall_break_mem:
  call printnl
  call scan_u16x
  mov si, a               ; data source from user space
  mov di, scrap_sector    ; destination in kernel space
  mov c, 512
  load                    ; transfer data to kernel space!
  mov d, scrap_sector     ; dump pointer in d
  mov c, 0
dump_loop:
  mov al, cl
  and al, $0f
  jz print_base
back:
  mov al, [d]             ; read byte
  mov bl, al
  call print_u8x
  mov a, $2000
  syscall sys_io          ; space
  mov al, cl
  and al, $0f
  cmp al, $0f
  je print_ascii
back1:
  inc d
  inc c
  cmp c, 512
  jne dump_loop
  call printnl
  jmp syscall_break_prompt  ; go to syscall_break return point
print_ascii:
  mov a, $2000
  syscall sys_io
  sub d, 16
  mov b, 16
print_ascii_l:
  inc d
  mov al, [d]               ; read byte
  cmp al, $20
  jlu dot
  cmp al, $7e
  jleu ascii
dot:
  mov a, $2e00
  syscall sys_io
  jmp ascii_continue
ascii:
  mov ah, al
  mov al, 0
  syscall sys_io
ascii_continue:
  loopb print_ascii_l
  jmp back1
print_base:
  call printnl
  mov b, d
  sub b, scrap_sector      ; remove this later and fix address bases which display incorrectly
  call print_u16x          ; display row
  mov a, $3a00
  syscall sys_io
  mov a, $2000
  syscall sys_io
  jmp back

s_break1:  
  .db "\ndebugger entry point.\n"
  .db "0. show registers\n"
  .db "1. show 512b ram block\n"
  .db "2. continue execution", 0

; ------------------------------------------------------------------------------------------------------------------;
; divide by zero exception
; ------------------------------------------------------------------------------------------------------------------;
trap_div_zero:
  push a
  push d
  pushf
  mov d, s_divzero
  call _puts
  popf
  pop d
  pop a
  sysret ; enable interrupts

; ------------------------------------------------------------------------------------------------------------------;
; undefined opcode exception
; ------------------------------------------------------------------------------------------------------------------;
trap_undef_opcode:
  sysret

; ------------------------------------------------------------------------------------------------------------------;
; real-time clock services syscall
; rtc i/o bank = ffa0 to ffaf
; ffa0 to ffa7 is scratch ram
; control register at $ffa8 [ w | r | s | cal4..cal0 ]
; al = 0..6 -> get
; al = 7..d -> set
; ------------------------------------------------------------------------------------------------------------------;
syscall_rtc:
  push al
  push d
  cmp al, 6
  jgu syscall_rtc_set
syscall_rtc_get:
  add al, $a9             ; generate rtc address to get to address a9 of clock
  mov ah, $ff    
  mov d, a                ; get to ffa9 + offset
  mov byte[$ffa8], $40    ; set r bit to 1
  mov al, [d]             ; get data
  mov byte[$ffa8], 0      ; reset r bit
  mov ah, al
  pop d
  pop al
  sysret
syscall_rtc_set:
  push bl
  mov bl, ah              ; set data aside
  add al, $a2             ; generate rtc address to get to address a9 of clock
  mov ah, $ff    
  mov d, a                ; get to ffa9 + offset
  mov al, bl              ; get data back
  mov byte[$ffa8], $80    ; set w bit to 1
  mov [d], al             ; set data
  mov byte[$ffa8], 0      ; reset write bit
  pop bl
  pop d
  pop al
  sysret

datetime_serv_tbl:
  .dw print_date
  .dw set_date
syscall_datetime:
  jmp [datetime_serv_tbl + al]      
print_date:
  mov a, $0d00           ; print carriage return char
  mov al, 3
  syscall sys_rtc        ; get week
  mov al, ah
  mov ah, 0
  shl a, 2          
  mov d, s_week
  add d, a
  call _puts
  mov a, $2000
  syscall sys_io         ; display ' '
  mov al, 4
  syscall sys_rtc        ; get day
  mov bl, ah
  call print_u8x
  mov a, $2000
  syscall sys_io         ; display ' '
; there is a problem with the month displaying
; the month is stored as bcd. so when retrieving the month, the value will be in binary
; even though it is to be understood as bcd.
; when retrieving the value and adding the string table address offset the value will go overboard!  
  mov al, 05
  syscall sys_rtc        ; get month
  mov al, ah
  mov ah, 0
  shl a, 2          
  mov d, s_months
  add d, a
  call _puts
  mov a, $2000
  syscall sys_io         ; display ' '
  mov bl, $20
  call print_u8x         ; print 20 for year prefix
  mov al, 06
  syscall sys_rtc        ; get year
  mov bl, ah
  call print_u8x
  mov a, $2000  
  syscall sys_io         ; display ' '
  mov al, 2
  syscall sys_rtc        ; get hours
  mov bl, ah
  call print_u8x
  mov a, $3a00    
  syscall sys_io         ; display ':'
  mov al, 01
  syscall sys_rtc        ; get minutes
  mov bl, ah
  call print_u8x
  mov a, $3a00  
  syscall sys_io         ; display ':'
  mov al, 0
  syscall sys_rtc        ; get seconds
  mov bl, ah
  call print_u8x
  call printnl
  sysret
set_date:
  mov d, s_set_year
  call _puts
  call scan_u8x          ; read integer into a
  shl a, 8               ; only al used, move to ah
  mov al, 0dh            ; set rtc year
  syscall sys_rtc        ; set rtc
  mov d, s_set_month
  call _puts
  call scan_u8x          ; read integer into a
  shl a, 8               ; only al used, move to ah
  mov al, 0ch            ; set rtc month
  syscall sys_rtc        ; set rtc
  mov d, s_set_day
  call _puts
  call scan_u8x          ; read integer into a
  shl a, 8               ; only al used, move to ah
  mov al, 0bh            ; set rtc month
  syscall sys_rtc        ; set rtc
  mov d, s_set_week
  call _puts
  call scan_u8x          ; read integer into a
  shl a, 8               ; only al used, move to ah
  mov al, 0ah            ; set rtc month
  syscall sys_rtc        ; set rtc
  mov d, s_set_hours
  call _puts
  call scan_u8x          ; read integer into a
  shl a, 8               ; only al used, move to ah
  mov al, 09h            ; set rtc month
  syscall sys_rtc        ; set rtc
  mov d, s_set_minutes
  call _puts
  call scan_u8x          ; read integer into a
  shl a, 8               ; only al used, move to ah
  mov al, 08h            ; set rtc month
  syscall sys_rtc        ; set rtc
  mov d, s_set_seconds
  call _puts
  call scan_u8x          ; read integer into a
  shl a, 8               ; only al used, move to ah
  mov al, 07h            ; set rtc month
  syscall sys_rtc        ; set rtc
  sysret

; ------------------------------------------------------------------------------------------------------------------;
; ide services syscall
; al = option
; 0 = ide reset, 1 = ide sleep, 2 = read sector, 3 = write sector
; ide read/write sector
; 512 bytes
; user buffer pointer in d
; ah = number of sectors
; cb = lba bytes 3..0
; ------------------------------------------------------------------------------------------------------------------;
ide_serv_tbl:
  .dw ide_reset
  .dw ide_sleep
  .dw ide_read_sect_wrapper
  .dw ide_write_sect_wrapper
syscall_ide:
  jmp [ide_serv_tbl + al]    
  
ide_reset:      
  mov byte[_ide_r7], 4            ; reset ide
  call ide_wait                   ; wait for ide ready             
  mov byte[_ide_r6], $e0          ; lba3= 0, master, mode= lba        
  mov byte[_ide_r1], 1            ; 8-bit transfers      
  mov byte[_ide_r7], $ef          ; set feature command
  sysret
ide_sleep:
  call ide_wait                   ; wait for ide ready             
  mov byte [_ide_r6], %01000000   ; lba[3:0](reserved), bit 6=1
  mov byte [_ide_r7], $e6         ; sleep command
  call ide_wait                   ; wait for ide ready
  sysret
ide_read_sect_wrapper:
  call ide_read_sect
  sysret
ide_write_sect_wrapper:
  call ide_write_sect
  sysret
ide_read_sect:
  mov al, ah
  mov ah, bl
  mov [_ide_r2], a                ; number of sectors (0..255)
  mov al, bh
  mov [_ide_r4], al
  mov a, c
  mov [_ide_r5], al
  mov al, ah
  and al, %00001111
  or al, %11100000                ; mode lba, master
  mov [_ide_r6], al
ide_read_sect_wait:
  mov al, [_ide_r7]  
  and al, $80                     ; busy flag
  jnz ide_read_sect_wait
  mov al, $20
  mov [_ide_r7], al               ; read sector cmd
  call ide_read  
  ret
ide_write_sect:
  mov al, ah
  mov ah, bl
  mov [_ide_r2], a                ; number of sectors (0..255)
  mov al, bh
  mov [_ide_r4], al
  mov a, c
  mov [_ide_r5], al
  mov al, ah
  and al, %00001111
  or al, %11100000                ; mode lba, master
  mov [_ide_r6], al
ide_write_sect_wait:
  mov al, [_ide_r7]  
  and al, $80                     ; busy flag
  jnz ide_write_sect_wait
  mov al, $30
  mov [_ide_r7], al               ; write sector cmd
  call ide_write      
  ret

;----------------------------------------------------------------------------------------------------;
; read ide data
; pointer in d
;----------------------------------------------------------------------------------------------------;
ide_read:
  push d
ide_read_loop:
  mov al, [_ide_r7]  
  and al, 80h                     ; busy flag
  jnz ide_read_loop               ; wait loop
  mov al, [_ide_r7]
  and al, %00001000               ; drq flag
  jz ide_read_end
  mov al, [_ide_r0]
  mov [d], al
  inc d
  jmp ide_read_loop
ide_read_end:
  pop d
  ret

;----------------------------------------------------------------------------------------------------;
; write ide data
; data pointer in d
;----------------------------------------------------------------------------------------------------;
ide_write:
  push d
ide_write_loop:
  mov al, [_ide_r7]  
  and al, 80h             ; busy flag
  jnz ide_write_loop      ; wait loop
  mov al, [_ide_r7]
  and al, %00001000       ; drq flag
  jz ide_write_end
  mov al, [d]
  mov [_ide_r0], al
  inc d 
  jmp ide_write_loop
ide_write_end:
  pop d
  ret

;----------------------------------------------------------------------------------------------------;
; wait for ide to be ready
;----------------------------------------------------------------------------------------------------;
ide_wait:
  mov al, [_ide_r7]  
  and al, 80h        ; busy flag
  jnz ide_wait
  ret

;----------------------------------------------------------------------------------------------------;
; io syscall
;----------------------------------------------------------------------------------------------------;
; baud  divisor
; 50    2304
; 110   1047
; 300    384
; 600    192
; 1200    96
; 9600    12
; 19200    6
; 38400    3
syscall_io_jmp:
  .dw syscall_io_putchar
  .dw syscall_io_getch
  .dw syscall_io_uart_setup
syscall_io:
  jmp [syscall_io_jmp + al]
; bit7 is the divisor latch access bit (dlab). it must be set high (logic 1) to access the divisor latches
; of the baud generator during a read or write operation. it must be set low (logic 0) to access the receiver
; buffer, the transmitter holding register, or the interrupt enable register.
syscall_io_uart_setup:
  mov al, [sys_uart0_lcr]
  or al, $80                ; set dlab access bit
  mov [_uart0_lcr], al      ; 8 data, 2 stop, no parity by default
  mov al, [sys_uart0_div0]
  mov [_uart0_dlab_0], al   ; divisor latch byte 0
  mov al, [sys_uart0_div1]
  mov [_uart0_dlab_1], al   ; divisor latch byte 1      

  mov al, [sys_uart0_lcr]
  and al, $7f               ; clear dlab access bit 
  mov [_uart0_lcr], al
  mov al, [sys_uart0_inten]
  mov [_uart0_ier], al      ; interrupts
  mov al, [sys_uart0_fifoen]
  mov [_uart0_fcr], al      ; fifo control
  sysret

; char in ah
syscall_io_putchar:
syscall_io_putchar_l0:
  mov al, [_uart0_lsr]         ; read line status register
  and al, $20
  jz syscall_io_putchar_l0    
  mov al, ah
  mov [_uart0_data], al        ; write char to transmitter holding register
  sysret

; char in ah
; al = sucess code
syscall_io_getch:
  push b
  push d
  sti
syscall_io_getch_l0:  
  mov a, [fifo_out]
  mov b, [fifo_in]
  cmp a, b
  je syscall_io_getch_l0
  mov d, a
  inc a
  cmp a, fifo + fifo_size      ; check if pointer reached the end of the fifo
  jne syscall_io_getch_cont
  mov a, fifo  
syscall_io_getch_cont:  
  mov [fifo_out], a             ; update fifo pointer
  mov al, [d]                   ; get char
  mov ah, al
  mov al, [sys_echo_on]
  cmp al, 1
  jne syscall_io_getch_noecho 
; here we just echo the char back to the console
syscall_io_getch_echo_l0:
  mov al, [_uart0_lsr]         ; read line status register
  and al, $20                 ; isolate transmitter empty
  jz syscall_io_getch_echo_l0
  mov al, ah
  mov [_uart0_data], al        ; write char to transmitter holding register
syscall_io_getch_noecho:
  mov al, 1                    ; al = 1 means a char successfully received
  pop d
  pop b
  sysret

; ---------------------------------------------------------------------
; kernel reset vector
; ---------------------------------------------------------------------
kernel_reset_vector:  
  mov bp, stack_begin
  mov sp, stack_begin
  
  mov al, %10000001             ; mask out timer interrupt for now - enable uart and fdc irqs 
  stomsk                        
  sti  

  lodstat
  and al, %11011111             ; disable display register loading
  stostat
  
; reset fifo pointers
  mov a, fifo
  mov d, fifo_in
  mov [d], a
  mov d, fifo_out
  mov [d], a  
  mov al, 2
  syscall sys_io                ; enable uart in interrupt mode

  mov d, s_fdc_config
  call _puts
  mov byte [_fdc_config], %00011110  ; %00001001 : turn led on / head load, disable double density, select side 0, select drive 0, do not select drive 1
  
  mov d, s_kernel_started
  call _puts

; file includes
.include "bios.exp"         ; to obtain the bios_reset_vector location (for reboots)
.include "lib/stdio.asm"
.include "lib/ctype.asm"
.include "lib/token.asm"

; kernel parameters
sys_echo_on:
  .db 1
sys_uart0_lcr:
  .db $07 ; 8 data bits, 2 stop bit, no parity
sys_uart0_inten:
  .db 1
sys_uart0_fifoen:
  .db 0
sys_uart0_div0:
  .db 12  ;
sys_uart0_div1:
  .db 0   ; default baud = 9600
; baud  divisor
; 50    2304
; 110   1047
; 300    384
; 600    192
; 1200    96
; 9600    12
; 19200    6
; 38400    3

fifo_in:
  .dw fifo
fifo_out:
  .dw fifo

s_uname:
  .db "solarium v.1.0", 0
s_dataentry:
  .db "> ", 0

s_int_en:
  .db "irqs enabled\n", 0
s_kernel_started:
  .db "kernel started(version 1.0)\n", 0
s_prompt_init:
  .db "starting init\n", 0
s_priviledge:
  .db "\nexception: privilege\n", 0
s_divzero:
  .db "\nexception: zero division\n", 0

s_set_year:
  .db "year: ", 0
s_set_month:
  .db "month: ", 0
s_set_day:
  .db "day: ", 0
s_set_week:
  .db "weekday: ", 0
s_set_hours:
  .db "hours: ", 0
s_set_minutes:
  .db "minutes: ", 0
s_set_seconds:
  .db "seconds: ", 0
s_months:      
  .db "   ", 0
  .db "jan", 0
  .db "feb", 0
  .db "mar", 0
  .db "apr", 0
  .db "may", 0
  .db "jun", 0
  .db "jul", 0
  .db "aug", 0
  .db "sep", 0
  .db "oct", 0
  .db "nov", 0
  .db "dec", 0

s_week:        
  .db "sun", 0 
  .db "mon", 0 
  .db "tue", 0 
  .db "wed", 0 
  .db "thu", 0 
  .db "fri", 0 
  .db "sat", 0

s_fdc_irq: .db "\nIRQ0 Executed.\n", 0
s_fdc_config:
  .db "\nselecting diskette drive 0, side 0, single density, head loaded\n", 0

proc_state_table:   
  .fill 16 * 20, 0  ; for 15 processes max
proc_availab_table: 
  .fill 16, 0       ; space for 15 processes. 0 = process empty, 1 = process taken
proc_names:
  .fill 16 * 32, 0  ; process names
filename:
  .fill 128, 0      ; holds a path for file search
user_data:
  .fill 512, 0      ;  user space data
fifo:
  .fill fifo_size

scrap_sector:
  .fill 512         ; scrap sector
transient_area:
  .db 0             ; beginning of the transient memory area. used for disk reads and other purposes    

.end
