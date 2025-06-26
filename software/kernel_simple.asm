; ------------------------------------------------------------------------------------------------------------------;
; Solarium - Sol-1 Homebrew Minicomputer Operating System Kernel.
; ------------------------------------------------------------------------------------------------------------------;

; Memory Map
; ------------------------------------------------------------------------------------------------------------------;
; 0000 ... 7FFF - ROM SPACE
; 8000 ... F7FF - RAM SPACE
; F7FF          - Stack root

; I/O MAP
; ------------------------------------------------------------------------------------------------------------------;
; FF80 - UART 0 (16550)
; FF90 - UART 1 (16550)
; FFA0 - RTC    (M48T02)
; FFB0 - PIO 0  (8255)
; FFC0 - FDD    (5.25" Floppy Drive Block)
;   - FFC0      Output Port (377 Flip-Flop)                  
;   - FFC1      Input Port  (244 Buffer)                     
;   - FFC8      WD1770 Status/Command    
;   - FFC9      WD1770 Track Register
;   - FFCA      WD1770 Sector Register
;   - FFCB      WD1770 Data Register
;      
; FFD0 - IDE    (Compact Flash / PATA)
; FFE0 - Timer  (8253)
; FFF0 - BIOS CONFIGURATION NV-RAM STORE AREA
; ------------------------------------------------------------------------------------------------------------------;

; ------------------------------------------------------------------------------------------------------------------;
; System Constants
; ------------------------------------------------------------------------------------------------------------------;
_UART0_DATA       .equ $FF80            ; data
_UART0_DLAB_0     .equ $FF80            ; divisor latch low byte
_UART0_DLAB_1     .equ $FF81            ; divisor latch high byte
_UART0_IER        .equ $FF81            ; Interrupt enable register
_UART0_FCR        .equ $FF82            ; FIFO control register
_UART0_LCR        .equ $FF83            ; line control register
_UART0_LSR        .equ $FF85            ; line status register

_UART1_DATA       .equ $FF90            ; data
_UART1_DLAB_0     .equ $FF90            ; divisor latch low byte
_UART1_DLAB_1     .equ $FF91            ; divisor latch high byte
_UART1_IER        .equ $FF91            ; Interrupt enable register
_UART1_FCR        .equ $FF92            ; FIFO control register
_UART1_LCR        .equ $FF93            ; line control register
_UART1_LSR        .equ $FF95            ; line status register

_ide_BASE         .equ $FFD0            ; ide base
_ide_R0           .equ _ide_BASE + 0    ; data port
_ide_R1           .equ _ide_BASE + 1    ; read: error code, write: feature
_ide_R2           .equ _ide_BASE + 2    ; number of sectors to transfer
_ide_R3           .equ _ide_BASE + 3    ; sector address lba 0 [0:7]
_ide_R4           .equ _ide_BASE + 4    ; sector address lba 1 [8:15]
_ide_R5           .equ _ide_BASE + 5    ; sector address lba 2 [16:23]
_ide_R6           .equ _ide_BASE + 6    ; sector address lba 3 [24:27 (lsb)]
_ide_R7           .equ _ide_BASE + 7    ; read: status, write: command       

_7SEG_DISPLAY     .equ $FFB0            ; bios post code hex display (2 digits) (connected to pio a)
_BIOS_POST_CTRL   .equ $FFB3            ; bios post display control register, 80h = as output
_PIO_A            .equ $FFB0    
_PIO_B            .equ $FFB1
_PIO_C            .equ $FFB2
_PIO_CONTROL      .equ $FFB3            ; pio control port

_FDC_CONFIG       .equ $FFC0            ; 0 = select_0, 1 = select_1, 2 = side_select, 3 = dden, 4 = in_use_or_head_load, 5 = wd1770_rst
_FDC_STATUS_1     .equ $FFC1            ; 0 = drq, 1 = ready
_FDC_WD_STAT_CMD  .equ $FFC8            ; status / command register
_FDC_WD_TRACK     .equ $FFC9            ; track register
_FDC_WD_SECTOR    .equ $FFCA            ; sector register
_FDC_WD_DATA      .equ $FFCB            ; data register

_TIMER_C_0        .equ $FFE0            ; timer counter 0
_TIMER_C_1        .equ $FFE1            ; timer counter 1
_TIMER_C_2        .equ $FFE2            ; timer counter 2
_TIMER_CTRL       .equ $FFE3            ; timer control register

STACK_BEGIN       .equ $F7FF            ; beginning of stack
FIFO_SIZE         .equ 1024

text_org          .equ $400             ; code origin address for all user processes


; ------------------------------------------------------------------------------------------------------------------;
; GLOBAL SYSTEM VARIABLES
; ------------------------------------------------------------------------------------------------------------------;

; ------------------------------------------------------------------------------------------------------------------;
; IRQ table
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
.dw syscall_io
.dw syscall_reboot
.dw syscall_fdc_format
.dw syscall_fdc_read
.dw syscall_fdc_read_sec

; ------------------------------------------------------------------------------------------------------------------;
; system call aliases
; ------------------------------------------------------------------------------------------------------------------;
sys_io               .equ 0
sys_reboot           .equ 1
sys_fdc_format       .equ 2
sys_fdc_read         .equ 3
sys_fdc_read_sec     .equ 4

; ------------------------------------------------------------------------------------------------------------------;
; IRQs' code block
; ------------------------------------------------------------------------------------------------------------------;
; 5.25" Floppy Drive Controller IRQ
int_0_fdc:
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
; UART0 Interrupt
; ------------------------------------------------------------------------------------------------------------------;
int_7_uart0:
  push a
  push d
  pushf
  mov a, [fifo_in]
  mov d, a
  mov al, [_UART0_DATA]       ; get character
  mov [d], al                 ; add to fifo
  mov a, [fifo_in]
  inc a
  cmp a, fifo + FIFO_SIZE     ; check if pointer reached the end of the fifo
  jne int_7_continue
  mov a, fifo  
int_7_continue:  
  mov [fifo_in], a            ; update fifo pointer
  popf
  pop d
  pop a  
  sysret


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; floppy drive system calls
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; data for formatting a floppy drive in single density mode (128 bytes per sector):
; fdc_40_FF:
;   .fill 40,  $FF    ; or 00                                                                                
; fdc_128_format_inner:
;   .fill 6,   $00    ;                                                                            <--|        
;   .fill 1,   $FE    ; ID Address Mark                                                               |        
;   .fill 1,   $00    ; Track Number  0 thru 39                                                       |                    
;   .fill 1,   $00    ; Side Number 00 or 01                                                          |                
;   .fill 1,   $01    ; Sector Number  0x01 through 0x10                                              |                              
;   .fill 1,   $00    ; Sector Length                                                                 |                        
;   .fill 1,   $F7    ; 2 CRC's Written                                                               | Write 16 times                 
;   .fill 11,  $FF    ; or 00                                                                         |                      
;   .fill 6,   $00    ;                                                                               |                        
;   .fill 1,   $FB    ; Data Address Mark                                                             |                                  
;   .fill 128, $E5    ; Data (IBM uses E5)                                                            |                                      
;   .fill 1,   $F7    ; 2 CRC's Written                                                               |                                                        
;   .fill 10,  $FF    ; or 00                                                                      <--|                                                  
; fdc_128_format_end:
;   .fill 369, $FF    ; or 00. Continue writing until wd1770 interrupts out. approx 369 bytes.                                                                
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; _FDC_CONFIG       .equ $FFC0 
; _FDC_STATUS_1     .equ $FFC1
; _FDC_WD_STAT_CMD  .equ $FFC8
; _FDC_WD_TRACK     .equ $FFC9
; _FDC_WD_SECTOR    .equ $FFCA
; _FDC_WD_DATA      .equ $FFCB
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

syscall_fdc_read:
  mov al, [_FDC_WD_DATA]      ; read data register to clear any errors
  mov al, [_FDC_WD_STAT_CMD]      ; read status register to clear any errors
  mov al, %11101000         
  mov [_FDC_WD_STAT_CMD], al
  call fdc_wait_64us

;fdc_wait_busy_high1:
;  mov al, [_FDC_WD_STAT_CMD]      ; 
;  test al, $01                ; 
;  jz fdc_wait_busy_high1

  mov di, transient_area
fdc_read_loop: ; for each byte, we need to wait for DRQ to be high
  mov al, [_FDC_WD_STAT_CMD]      ; 
  test al, $01                ; check busy bit
  jz fdc_read_end
  test al, $02                ; check drq bit
  jz fdc_read_loop
  mov al, [_FDC_WD_DATA]     ; 
  stosb
  jmp fdc_read_loop

;we need to check if writing to data reg causes a spurious read. so lets check inside the writing loop, how many times we actually write the bytes
;say the 40 byte loop. if we find that we only write ~20 times, then this indcates this problem.
;because for every write, if it also reads, then that clears DRQ, so we need to wait for next DRQ.
fdc_read_end:
  mov a, di
  sub a, transient_area
  mov d, sss
  call _puts
  call print_u16d
  call printnl
  mov b, 3090
  call cmd_hexd
  sysret
sss:.db "\ntrack read\n", 0


; sector in al
; track in ah
syscall_fdc_read_sec:
  mov [_FDC_WD_SECTOR], al
  mov al, ah
  mov [_FDC_WD_TRACK], al
  mov al, %10001000         
  mov [_FDC_WD_STAT_CMD], al
  call fdc_wait_64us

;fdc_wait_busy_high2:
;  mov al, [_FDC_WD_STAT_CMD]      ; 
;  test al, $01                ; 
;  jz fdc_wait_busy_high2

  mov di, transient_area
fdc_read_loop2: ; for each byte, we need to wait for DRQ to be high
  mov al, [_FDC_WD_STAT_CMD]      ; read lost data flag 10+3+5+8+5+8
  test al, $01                ; check drq bit
  jz fdc_read_end2
  test al, $02                ; check drq bit
  jz fdc_read_loop2
  mov al, [_FDC_WD_DATA]     ; 
  stosb
  jmp fdc_read_loop2
fdc_read_end2:
  mov a, di
  sub a, transient_area
  mov d, sss
  call _puts
  call print_u16d
  call printnl
  mov b, 128
  call cmd_hexd
  sysret

; when writing the actual code for formatting multiple tracks, remember to change the track number byte
; in the RAM formatting block because they are all set as 00 right now
; bl: track number
syscall_fdc_format:
  mov [_FDC_WD_TRACK], bl
  mov d, s_format_begin
  call _puts
  mov al, [_FDC_WD_DATA]      ; read data register to clear any errors
  mov al, [_FDC_WD_STAT_CMD]      ; read status register to clear any errors
fdc_header_loop_start:
  mov al, %11111010               ; Write Track Command: {1111, 0: Enable Spin-up Seq, 1: Settling Delay, 1: No Write Precompensation, 0}
  mov [_FDC_WD_STAT_CMD], al
; write the first data block for formatting which is 40 bytes of 0xFF:
  call fdc_wait_64us


;fdc_wait_busy_high:
;  mov al, [_FDC_WD_STAT_CMD]      ; 
;  test al, $01                ; 
;  jz fdc_wait_busy_high

  mov si, transient_area
fdc_format_drq:
  mov al, [_FDC_WD_STAT_CMD]  ; 10
  test al, $01                ; 4
  jz fdc_format_end           ; 8
  test al, $02                ; 4
  jz fdc_format_drq           ; 8
  lodsb                       ; 7
  mov [_FDC_WD_DATA], al      ; 10   
  jmp fdc_format_drq
fdc_format_end:
  mov d, sss1
  call _puts
  sysret

sss1:.db "\nformat done\n", 0






fdc_format_mem:
  mov d, 1
  mov di, transient_area
  mov c, 40
  mov al, $FF
fdc_l0: 
  stosb
  dec c
  jnz fdc_l0

fdc_inner_loop:
  mov c, 6
  mov al, $00
fdc_l1:
  stosb
  dec c
  jnz fdc_l1

; address mark
fdc_l2:
  mov al, $FE
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
  mov al, $F7
  stosb

; 11 times $FF
  mov c, 11
  mov al, $FF
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

; data address mark
  mov al, $FB
fdc_l10:
  stosb

; sector data
  mov c, 0
fdc_l11:
  mov al, cl
  stosb
  inc c
  cmp c, 128
  jne fdc_l11

; 2 crc's
fdc_l12:
  mov al, $F7
  stosb

; 10 times $FF
  mov c, 10
  mov al, $FF
fdc_l13:
  stosb
  dec c
  jnz fdc_l13

; check whether we did this 16 times
  inc d
  cmp d, 17
  jne fdc_inner_loop

; loop ~369 times
  mov c, 400
  mov al, $FF
fdc_format_footer:
fdc_footer_drq_loop:
  stosb
  dec c
  jnz fdc_footer_drq_loop

  ret

; fetch is 2 cycles long when 'display_reg_load' is false.
; 64us amounts to 160 cycles of the 2.5MHz clock
; call u16 is 14 cycles long
; 160 - 5 - 14 = 
fdc_wait_64us:
  mov cl, 1                       ; 5 cycles
fdc_wait_64_loop:
  dec cl                           ; 3 cycles
  jnz fdc_wait_64_loop             ; 8 cycles
  ret

fdc_irq: .db 0
s_format_begin:   .db "\nformatting starting...\n", 0
s_format_done:    .db "\nformatting done.\n", 0
s_fdc_status:     .db "\nfdc status: ", 0

; REBOOT SYSTEM
syscall_reboot:
  push word $FFFF 
  push byte %00000000             ; dma_ack = 0, interrupts disabled, mode = supervisor, paging = off, halt=0, display_reg_load=0, dir=0
  push word BIOS_RESET_VECTOR     ; and then push RESET VECTOR of the shell to the stack
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



;----------------------------------------------------------------------------------------------------;
; IO Syscall
;----------------------------------------------------------------------------------------------------;
; Baud  Divisor
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
; bit7 is the Divisor Latch Access Bit (DLAB). It must be set high (logic 1) to access the Divisor Latches
; of the Baud Generator during a Read or Write operation. It must be set low (logic 0) to access the Receiver
; Buffer, the Transmitter Holding Register, or the Interrupt Enable Register.
syscall_io_uart_setup:
  mov al, [sys_uart0_lcr]
  or al, $80                ; set DLAB access bit
  mov [_UART0_LCR], al      ; 8 data, 2 stop, no parity by default
  mov al, [sys_uart0_div0]
  mov [_UART0_DLAB_0], al   ; divisor latch byte 0
  mov al, [sys_uart0_div1]
  mov [_UART0_DLAB_1], al   ; divisor latch byte 1      

  mov al, [sys_uart0_lcr]
  and al, $7F               ; clear DLAB access bit 
  mov [_UART0_LCR], al
  mov al, [sys_uart0_inten]
  mov [_UART0_IER], al      ; interrupts
  mov al, [sys_uart0_fifoen]
  mov [_UART0_FCR], al      ; FIFO control
  sysret

; char in ah
syscall_io_putchar:
syscall_io_putchar_L0:
  mov al, [_UART0_LSR]         ; read Line Status Register
  and al, $20
  jz syscall_io_putchar_L0    
  mov al, ah
  mov [_UART0_DATA], al        ; write char to Transmitter Holding Register
  sysret

; char in ah
; al = sucess code
syscall_io_getch:
  push b
  push d
  sti
syscall_io_getch_L0:  
  mov a, [fifo_out]
  mov b, [fifo_in]
  cmp a, b
  je syscall_io_getch_L0
  mov d, a
  inc a
  cmp a, fifo + FIFO_SIZE      ; check if pointer reached the end of the fifo
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
syscall_io_getch_echo_L0:
  mov al, [_UART0_LSR]         ; read Line Status Register
  and al, $20                 ; isolate Transmitter Empty
  jz syscall_io_getch_echo_L0
  mov al, ah
  mov [_UART0_DATA], al        ; write char to Transmitter Holding Register
syscall_io_getch_noecho:
  mov al, 1                    ; AL = 1 means a char successfully received
  pop d
  pop b
  sysret






; ---------------------------------------------------------------------
; kernel reset vector
; ---------------------------------------------------------------------
kernel_reset_vector:  
  mov bp, STACK_BEGIN
  mov sp, STACK_BEGIN
  
  mov al, %10000000             ; mask out timer interrupt
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
  
  mov d, s_kernel_started
  call _puts

  mov d, str0
  call _puts
  ; First, select drive 1 and de-select drive 0
  mov d, $FFC0
  mov bl, %00001101     ; %00001001 : turn LED on, disable double density, select side 0, select drive 0, do not select drive 1
  mov [d], bl


menu:
  mov d, s_menu
  call _puts
  call getch
  cmp ah, '0'
  je step_in
  cmp ah, '1'
  je step_out
  cmp ah, '2'
  je restore
  cmp ah, '3'
  je status1
  cmp ah, '4'
  je status2
  cmp ah, '5'
  je format
  cmp ah, '6'
  je read
  cmp ah, '7'
  je read_sec
  cmp ah, '8'
  je fdc_options
  jmp menu
step_in:
  mov d, $FFC8    ; wd1770
  mov al, 2       ; setparam call
  mov bl, %01010011     ; step in
  mov [d], bl
  jmp menu
restore:
; send restore command
  mov d, $FFC8    ; wd1770
  mov al, 2       ; setparam call
  mov bl, $03     ; restore command, 30ms rate
  mov [d], bl
  jmp menu
step_out:
  mov d, $FFC8    ; wd1770
  mov al, 2       ; setparam call
  mov bl, %01110011     ; step out
  mov [d], bl
  jmp menu
status1:
  call printnl
  mov d, $FFC1    ; wd1770 status 1
  mov al, 4       ; getparam call
  mov bl, [d]
  call print_u8x   ; print bl
  call printnl
  jmp menu
status2:
  call printnl
  mov d, $FFC8    ; wd1770 status 
  mov al, 4       ; getparam call
  mov bl, [d]
  call print_u8x   ; print bl
  call printnl
  jmp menu
format:
  call fdc_format_mem ; fill ram with format
  mov d, s_track
  call _puts
  call scan_u8x   ; in al
  mov bl, al      ; track needs to be in bl
  mov al, 0       ; 0 = format
  syscall sys_fdc_format
  mov d, s_format_done
  call _puts
  jmp menu
read:
  mov di, transient_area
  mov c, 4000
  mov al, $33
read_l0:
  stosb
  dec c
  jnz read_l0
  syscall sys_fdc_read
  jmp menu
read_sec:
  mov di, transient_area
  mov c, 128
  mov al, $55
read_l1:
  stosb
  dec c
  jnz read_l1
  mov d, s1
  call _puts
  call scan_u8x
  mov ah, al
  mov d, s2
  call _puts
  call scan_u8x ; in al
  
  syscall sys_fdc_read_sec
  jmp menu
s1:.db "\ntrack: ", 0
s2:.db "\nsector: ", 0
ss3:.db "\nvalue: ", 0

fdc_options:
  mov d, ss3
  call _puts
  call scan_u8x
  mov [_FDC_CONFIG], al
  jmp menu

; b : len
cmd_hexd:
  mov a, transient_area
  mov [start], a
  mov a, b
  mov [length], a

	mov a, [start]
  mov d, a        ; dump pointer in d
  mov c, 0
dump_loop:
  mov al, cl
  and al, $0F
  jz print_base
back:
  mov al, [d]        ; read byte
  mov bl, al
  call print_u8x
  mov a, $2000
  syscall sys_io      ; space
  mov al, cl
  and al, $0F
  cmp al, $0F
  je print_ascii
back1:
  inc d
  inc c
  mov a, [length]
  cmp a, c
  jne dump_loop
  
  mov a, $0A00
  syscall sys_io
  mov a, $0D00
  syscall sys_io
  ;call printnl

  ret
print_ascii:
  sub d, 16
  mov b, 16
print_ascii_L:
  inc d
  mov al, [d]        ; read byte
  cmp al, $20
  jlu dot
  cmp al, $7E
  jleu ascii
dot:
  mov a, $2E00
  syscall sys_io
  jmp ascii_continue
ascii:
  mov ah, al
  mov al, 0
  syscall sys_io
ascii_continue:
  loopb print_ascii_L
  jmp back1
print_base:
  mov a, $0A00
  syscall sys_io
  mov a, $0D00
  syscall sys_io
  mov b, d
  sub b, transient_area
  call print_u16x        ; display row
  add b, transient_area
  mov a, $2000
  syscall sys_io
  jmp back

  ret

start:  .dw 0
length: .dw 1024


s_track: .db "\ntrack: ", 0

s_menu: .db "\n0. step in\n"
        .db "1. step out\n", 
        .db "2. restore\n", 
        .db "3. read status 1\n", 
        .db "4. read status 2\n", 
        .db "5. format track\n", 
        .db "6. read track\n", 
        .db "7. read sector\n", 
        .db "8. config\n", 
        .db "\nselect option: ", 0

str0:   .db "\nselecting drive 1...\n", 0
str1:   .db "\nwaiting...\n", 0



; FILE INCLUDES
.include "bios.exp"         ; to obtain the BIOS_RESET_VECTOR location (for reboots)
.include "lib/stdio.asm"
.include "lib/ctype.asm"

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
; Baud  Divisor
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


s_kernel_started:
  .db "kernel started(version 1.0)\n", 0
s_priviledge:
  .db "\nexception: privilege\n", 0
s_divzero:
  .db "\nexception: zero division\n", 0

; This is the format of a sector for the 128 byte per sector format.
; Write the bracketed data 16 times per track.
; The recommended single-density format with 128
; bytes/sector is shown. In order to format a diskette,
; the user issues the Write Track Command, and loads
; the Data Register with the following values. For every
; byte to be written, there is one Data Request.
fdc_irq_event:
  .fill 1,  $00       ; keeps status of fdc irq event
fdc_128_format:                                                                       
fdc_40_FF:
  .fill 40,  $FF    ; or 00                                                                                
fdc_128_format_inner:
  .fill 6,   $00    ;                                                                            <--|        
  .fill 1,   $FE    ; ID Address Mark                                                               |        
fdc_128_format_track:
  .fill 1,   $00    ; Track Number   0 thru 39                                                      |                    
  .fill 1,   $00    ; Side Number 00 or 01                                                          |                
fdc_128_format_sect:
  .fill 1,   $01    ; Sector Number  0x01 through 0x10                                              |                              
  .fill 1,   $00    ; Sector Length                                                                 |                        
  .fill 1,   $F7    ; 2 CRC's Written                                                               | Write 16 times                 
  .fill 11,  $FF    ; or 00                                                                         |                      
  .fill 6,   $00    ;                                                                               |                        
  .fill 1,   $FB    ; Data Address Mark                                                             |                                  
  .fill 128, $E5    ; Data (IBM uses E5)                                                            |                                      
  .fill 1,   $F7    ; 2 CRC's Written                                                               |                                                        
  .fill 10,  $FF    ; or 00                                                                      <--|                                                  
fdc_128_format_end:
  .fill 369, $FF    ; or 00. Continue writing until wd1770 interrupts out. approx 369 bytes.                                                                

fifo:
  .fill FIFO_SIZE

scrap_sector:
  .fill 512         ; scrap sector
transient_area:
  .db 0             ; beginning of the transient memory area. used for disk reads and other purposes    

.end
