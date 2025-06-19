.include "lib/kernel.exp"
.org text_org

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
  mov d, $FFC0
  mov al, 2       ; setparam call
  mov bl, %00001010     ; %00001001 : turn LED on, disable double density, select side 0, select drive 0, do not select drive 1
  syscall sys_system

  mov d, str1
  call _puts
; wait a little
  mov c, $FF
loop1:
  dec c
  jnz loop1


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
  syscall sys_terminate_proc
step_in:
  mov d, $FFC8    ; wd1770
  mov al, 2       ; setparam call
  mov bl, %01010011     ; step in
  syscall sys_system
  jmp menu
restore:
; send restore command
  mov d, $FFC8    ; wd1770
  mov al, 2       ; setparam call
  mov bl, $03     ; restore command, 30ms rate
  syscall sys_system
  jmp menu
step_out:
  mov d, $FFC8    ; wd1770
  mov al, 2       ; setparam call
  mov bl, %01110011     ; step out
  syscall sys_system
  jmp menu
status1:
  call printnl
  mov d, $FFC1    ; wd1770 status 1
  mov al, 4       ; getparam call
  syscall sys_system
  call print_u8x   ; print bl
  call printnl
  jmp menu
status2:
  call printnl
  mov d, $FFC8    ; wd1770 status 
  mov al, 4       ; getparam call
  syscall sys_system
  call print_u8x   ; print bl
  call printnl
  jmp menu
format:
  mov d, s_track
  call _puts
  call scan_u8x   ; in al
  mov bl, al      ; track needs to be in bl
  mov al, 0       ; 0 = format
  syscall sys_fdc 
  mov d, s_format_done
  call _puts
  jmp menu

s_format_done: .db "\nformatting done.\n", 0
s_track: .db "\ntrack: ", 0

s_menu: .db "\n0. step in\n"
        .db "1. step out\n", 
        .db "2. restore\n", 
        .db "3. read status 1\n", 
        .db "4. read status 2\n", 
        .db "5. format track\n", 
        .db "6. exit\n", 
        .db "\nselect option: ", 0

str0:   .db "\nselecting drive 1...\n", 0
str1:   .db "\nwaiting...\n", 0

.include "lib/stdio.asm"
.end
