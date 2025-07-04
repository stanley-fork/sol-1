; ------------------------------------------------------------------------------------------------------------------;
; solarium - sol-1 homebrew minicomputer operating system kernel.
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
_uart0_data       .equ $ff80            ; data
_uart0_dlab_0     .equ $ff80            ; divisor latch low byte
_uart0_dlab_1     .equ $ff81            ; divisor latch high byte
_uart0_ier        .equ $ff81            ; interrupt enable register
_uart0_fcr        .equ $ff82            ; fifo control register
_uart0_lcr        .equ $ff83            ; line control register
_uart0_lsr        .equ $ff85            ; line status register

_uart1_data       .equ $ff90            ; data
_uart1_dlab_0     .equ $ff90            ; divisor latch low byte
_uart1_dlab_1     .equ $ff91            ; divisor latch high byte
_uart1_ier        .equ $ff91            ; interrupt enable register
_uart1_fcr        .equ $ff92            ; fifo control register
_uart1_lcr        .equ $ff93            ; line control register
_uart1_lsr        .equ $ff95            ; line status register

_ide_base         .equ $ffd0            ; ide base
_ide_r0           .equ _ide_base + 0    ; data port
_ide_r1           .equ _ide_base + 1    ; read: error code, write: feature
_ide_r2           .equ _ide_base + 2    ; number of sectors to transfer
_ide_r3           .equ _ide_base + 3    ; sector address lba 0 [0:7]
_ide_r4           .equ _ide_base + 4    ; sector address lba 1 [8:15]
_ide_r5           .equ _ide_base + 5    ; sector address lba 2 [16:23]
_ide_r6           .equ _ide_base + 6    ; sector address lba 3 [24:27 (lsb)]
_ide_r7           .equ _ide_base + 7    ; read: status, write: command       

_7seg_display     .equ $ffb0            ; bios post code hex display (2 digits) (connected to pio a)
_bios_post_ctrl   .equ $ffb3            ; bios post display control register, 80h = as output
_pio_a            .equ $ffb0    
_pio_b            .equ $ffb1
_pio_c            .equ $ffb2
_pio_control      .equ $ffb3            ; pio control port

_fdc_config       .equ $ffc0            ; 0 = select_0, 1 = select_1, 2 = side_select, 3 = dden, 4 = in_use_or_head_load, 5 = wd1770_rst
_fdc_status_1     .equ $ffc1            ; 0 = drq, 1 = ready
_fdc_wd_stat_cmd  .equ $ffc8            ; status / command register
_fdc_wd_track     .equ $ffc9            ; track register
_fdc_wd_sector    .equ $ffca            ; sector register
_fdc_wd_data      .equ $ffcb            ; data register

_timer_c_0        .equ $ffe0            ; timer counter 0
_timer_c_1        .equ $ffe1            ; timer counter 1
_timer_c_2        .equ $ffe2            ; timer counter 2
_timer_ctrl       .equ $ffe3            ; timer control register

stack_begin       .equ $f7ff            ; beginning of stack
fifo_size         .equ 1024

text_org          .equ $400             ; code origin address for all user processes


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
.dw syscall_io
.dw syscall_reboot
.dw syscall_fdc_format
.dw syscall_fdc_read
.dw syscall_fdc_read_sec
.dw syscall_fdc_write_sec

; ------------------------------------------------------------------------------------------------------------------;
; system call aliases
; ------------------------------------------------------------------------------------------------------------------;
sys_io               .equ 0
sys_reboot           .equ 1
sys_fdc_format       .equ 2
sys_fdc_read         .equ 3
sys_fdc_read_sec     .equ 4
sys_fdc_write_sec    .equ 5

; ------------------------------------------------------------------------------------------------------------------;
; irqs' code block
; ------------------------------------------------------------------------------------------------------------------;
; 5.25" floppy drive controller irq
int_0_fdc:
  mov d, s_fdc1
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

s_fdc1:.db "\n\rirq0 serviced.\n\r",0

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; floppy drive system calls
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
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
; _fdc_config       .equ $ffc0 
; _fdc_status_1     .equ $ffc1
; _fdc_wd_stat_cmd  .equ $ffc8
; _fdc_wd_track     .equ $ffc9
; _fdc_wd_sector    .equ $ffca
; _fdc_wd_data      .equ $ffcb
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

syscall_fdc_read:
  mov al, [_fdc_wd_data]      ; read data register to clear any errors
  mov al, [_fdc_wd_stat_cmd]      ; read status register to clear any errors
  mov al, %11101000         
  mov [_fdc_wd_stat_cmd], al
  call fdc_wait_64us
;fdc_wait_busy_high1:
;  mov al, [_fdc_wd_stat_cmd]      ; 
;  test al, $01                ; 
;  jz fdc_wait_busy_high1
  mov di, transient_area
fdc_read_loop: ; for each byte, we need to wait for drq to be high
  mov al, [_fdc_wd_stat_cmd]      ; 
  test al, $01                ; check busy bit
  jz fdc_read_end
  test al, $02                ; check drq bit
  jz fdc_read_loop
  mov al, [_fdc_wd_data]     ; 
  stosb
  jmp fdc_read_loop
;we need to check if writing to data reg causes a spurious read. so lets check inside the writing loop, how many times we actually write the bytes
;say the 40 byte loop. if we find that we only write ~20 times, then this indcates this problem.
;because for every write, if it also reads, then that clears drq, so we need to wait for next drq.
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
  mov [_fdc_wd_sector], al
  mov al, ah
  mov [_fdc_wd_track], al
  mov al, %10001000         
  mov [_fdc_wd_stat_cmd], al
  call fdc_wait_64us
;fdc_wait_busy_high2:
;  mov al, [_fdc_wd_stat_cmd]      ; 
;  test al, $01                ; 
;  jz fdc_wait_busy_high2
  mov di, transient_area
fdc_read_loop2: ; for each byte, we need to wait for drq to be high
  mov al, [_fdc_wd_stat_cmd]      ; read lost data flag 10+3+5+8+5+8
  test al, $01                ; check drq bit
  jz fdc_read_end2
  test al, $02                ; check drq bit
  jz fdc_read_loop2
  mov al, [_fdc_wd_data]     ; 
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
; in the ram formatting block because they are all set as 00 right now
; bl: track number
syscall_fdc_format:
  mov [_fdc_wd_track], bl
  mov d, s_format_begin
  call _puts
  mov al, [_fdc_wd_data]      ; read data register to clear any errors
  mov al, [_fdc_wd_stat_cmd]      ; read status register to clear any errors
fdc_header_loop_start:
  mov al, %11111010               ; write track command: {1111, 0: enable spin-up seq, 1: settling delay, 1: no write precompensation, 0}
  mov [_fdc_wd_stat_cmd], al
; write the first data block for formatting which is 40 bytes of 0xff:
  call fdc_wait_64us
;fdc_wait_busy_high:
;  mov al, [_fdc_wd_stat_cmd]      ; 
;  test al, $01                ; 
;  jz fdc_wait_busy_high
  mov si, transient_area
fdc_format_drq:
  mov al, [_fdc_wd_stat_cmd]  ; 10
  test al, $01                ; 4
  jz fdc_format_end           ; 8
  test al, $02                ; 4
  jz fdc_format_drq           ; 8
  lodsb                       ; 7
  mov [_fdc_wd_data], al      ; 10   
  jmp fdc_format_drq
fdc_format_end:
  mov d, sss1
  call _puts
  sysret

sss1:.db "\nformat done\n", 0


; sector in al
; track in ah
syscall_fdc_write_sec:
  mov [_fdc_wd_sector], al
  mov al, ah
  mov [_fdc_wd_track], al
  mov al, %10101010            ; 101, 0:single sector, 1: disable spinup, 0: no delay, 1: no precomp, 0: normal data mark
  mov [_fdc_wd_stat_cmd], al
  call fdc_wait_64us
;fdc_wait_busy_high2:
;  mov al, [_fdc_wd_stat_cmd]      ; 
;  test al, $01                ; 
;  jz fdc_wait_busy_high2
  mov si, fdc_sec_data
fdc_write_loop2: ; for each byte, we need to wait for drq to be high
  mov al, [_fdc_wd_stat_cmd]  ; 10
  test al, $01                ; 4
  jz fdc_write_end           ; 8
  test al, $02                ; 4
  jz fdc_write_loop2           ; 8
  lodsb                       ; 7
  mov [_fdc_wd_data], al      ; 10   
  jmp fdc_write_loop2
fdc_write_end:
  mov d, sss2
  call _puts
  sysret
sss2:.db "\nsector written\n",0


fdc_format_mem:
  mov d, 1
  mov di, transient_area
  mov c, 40
  mov al, $ff
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

; data address mark
  mov al, $fb
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
  mov al, $f7
  stosb

; 10 times $ff
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

; loop ~369 times
  mov c, 400
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
  mov cl, 1                       ; 5 cycles
fdc_wait_64_loop:
  dec cl                           ; 3 cycles
  jnz fdc_wait_64_loop             ; 8 cycles
  ret

fdc_irq: .db 0
s_format_begin:   .db "\nformatting starting...\n", 0
s_format_done:    .db "\nformatting done.\n", 0
s_fdc_status:     .db "\nfdc status: ", 0

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
  
  mov al, %10000001             ; mask out timer interrupt
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
  ; first, select drive 1 and de-select drive 0
  mov d, $ffc0
  mov bl, %00001110     ; %00001001 : turn led on, disable double density, select side 0, select drive 0, do not select drive 1
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
  cmp ah, '9'
  je fdc_write_sec
  jmp menu
step_in:
  mov d, $ffc8    ; wd1770
  mov al, 2       ; setparam call
  mov bl, %01010011     ; step in
  mov [d], bl
  jmp menu
restore:
; send restore command
  mov d, $ffc8    ; wd1770
  mov al, 2       ; setparam call
  mov bl, $03     ; restore command, 30ms rate
  mov [d], bl
  jmp menu
step_out:
  mov d, $ffc8    ; wd1770
  mov al, 2       ; setparam call
  mov bl, %01110011     ; step out
  mov [d], bl
  jmp menu
status1:
  call printnl
  mov d, $ffc1    ; wd1770 status 1
  mov al, 4       ; getparam call
  mov bl, [d]
  call print_u8x   ; print bl
  call printnl
  jmp menu
status2:
  call printnl
  mov d, $ffc8    ; wd1770 status 
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


fdc_write_sec:
  mov d, s1
  call _puts
  call scan_u8x
  mov ah, al
  mov d, s2
  call _puts
  call scan_u8x ; in al
  syscall sys_fdc_write_sec
  jmp menu

fdc_options:
  mov d, ss3
  call _puts
  call scan_u8x
  mov [_fdc_config], al
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
  and al, $0f
  jz print_base
back:
  mov al, [d]        ; read byte
  mov bl, al
  call print_u8x
  mov a, $2000
  syscall sys_io      ; space
  mov al, cl
  and al, $0f
  cmp al, $0f
  je print_ascii
back1:
  inc d
  inc c
  mov a, [length]
  cmp a, c
  jne dump_loop
  
  mov a, $0a00
  syscall sys_io
  mov a, $0d00
  syscall sys_io
  ;call printnl

  ret
print_ascii:
  sub d, 16
  mov b, 16
print_ascii_l:
  inc d
  mov al, [d]        ; read byte
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
  mov a, $0a00
  syscall sys_io
  mov a, $0d00
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
        .db "9. write sector\n", 
        .db "\nselect option: ", 0

str0:   .db "\nselecting drive 1...\n", 0
str1:   .db "\nwaiting...\n", 0



; file includes
.include "bios.exp"         ; to obtain the bios_reset_vector location (for reboots)
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


s_kernel_started:
  .db "kernel started(version 1.0)\n", 0
s_priviledge:
  .db "\nexception: privilege\n", 0
s_divzero:
  .db "\nexception: zero division\n", 0

fdc_sec_data:
  .db $ff, $ee, $e0, $55, $66, $33, $42, $aa, $ae, $67, $23, $11, $23, $56, $88, $99,
  .db $1f, $2e, $40, $53, $63, $43, $52, $1a, $a4, $67, $03, $31, $43, $56, $48, $f9,
  .db $2f, $3e, $50, $57, $62, $53, $21, $2a, $a3, $17, $73, $41, $53, $46, $38, $b9,
  .db $6f, $4e, $20, $56, $67, $63, $20, $6a, $a2, $27, $53, $61, $23, $16, $28, $e9,
  .db $af, $7e, $10, $52, $62, $73, $18, $5a, $a1, $37, $43, $51, $13, $26, $18, $a9,
  .db $6f, $3e, $90, $51, $63, $03, $18, $4a, $a5, $67, $33, $41, $43, $36, $68, $c9,
  .db $8f, $5e, $60, $55, $68, $23, $18, $3a, $a3, $57, $23, $31, $73, $36, $48, $b9,
  .db $2f, $1e, $40, $53, $69, $13, $19, $3a, $a1, $48, $23, $21, $53, $46, $38, $a9


fifo:
  .fill fifo_size

scrap_sector:
  .fill 512         ; scrap sector
transient_area:
  .db 0             ; beginning of the transient memory area. used for disk reads and other purposes    

.end
