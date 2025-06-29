.include "lib/kernel.exp"
.org text_org

; sys_fdc_restore
; sys_fdc_step
; sys_fdc_step_in
; sys_fdc_step_out
; sys_fdc_seek
; sys_fdc_format
; sys_fdc_read_addr
; sys_fdc_read_track
; sys_fdc_read_sect
; sys_fdc_write_sect
; sys_fdc_force_int

main:
  mov bp, $ffff
  mov sp, $ffff

  mov d, str0
  call _puts
  ; First, select drive 1 and de-select drive 0
  mov d, $FFC0
  mov al, 2       ; setparam call
  mov bl, %00001010     ; %00001001 : turn LED on, disable double density, select side 0, select drive 0, do not select drive 1
  syscall sys_system

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
  je read_track
  cmp ah, '7'
  je read_sect
  cmp ah, '8'
  je fdc_options
  cmp ah, '9'
  je fdc_write_sec
  jmp menu
restore:
  mov al, 0
  syscall sys_fdc
  jmp menu
step:
  mov al, 1
  syscall sys_fdc
  jmp menu
step_in:
  mov al, 2
  syscall sys_fdc
  jmp menu
step_out:
  mov al, 3
  syscall sys_fdc
  jmp menu
seek:
  mov al, 4
  syscall sys_fdc
  jmp menu
format:
  mov d, s_track
  call _puts
  call scan_u8x   ; in al
  mov bl, al      ; track needs to be in bl
  mov al, 5
  syscall sys_fdc
  mov d, s_format_done
  call _puts
  jmp menu
read_track:
  mov al, 6
  syscall sys_fdc
  jmp menu
read_sect:
  mov d, s1
  call _puts
  call scan_u8x
  mov bh, al
  mov d, s2
  call _puts
  call scan_u8x ; in al 
  mov bl, al
  mov al, 7
  syscall sys_fdc
  jmp menu
fdc_write_sec:
  mov d, s1
  call _puts
  call scan_u8x
  mov bh, al
  mov d, s2
  call _puts
  call scan_u8x ; in al
  mov bl, al
  mov al, 8
  syscall sys_fdc
  jmp menu
fdc_options:
  mov d, ss3
  call _puts
  call scan_u8x
  mov bl, al
  mov al, 2
  syscall sys_system
  jmp menu
status1:
  call printnl
  mov al, 11       ; getparam call
  syscall sys_fdc
  mov bl, al
  call print_u8x   ; print bl
  call printnl
  jmp menu
status2:
  call printnl
  mov al, 12      ; getparam call
  syscall sys_fdc
  mov bl, al
  call print_u8x   ; print bl
  call printnl
  jmp menu

; b : len
; d: data address
cmd_hexd:
  mov a, d
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

start:   .dw 0
length:  .dw 1024


s_track: .db "\ntrack: ", 0

s_menu:  .db "\n0. step in\n"
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

s_format_done: .db "\nformat done.\n", 0
str0:    .db "\nselecting drive 0...\n", 0
str1:    .db "\nwaiting...\n", 0
s1:      .db "\ntrack: ", 0
s2:      .db "\nsector: ", 0
ss3:     .db "\nvalue: ", 0

.include "lib/stdio.asm"
.end
