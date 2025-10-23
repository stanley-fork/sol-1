; --- FILENAME: test.c
; --- DATE:     23-10-2025 at 11:47:12
.include "lib/asm/kernel.exp"
.include "lib/asm/bios.exp"

; --- BEGIN TEXT SEGMENT
.org text_org
main:
  mov bp, $FFE0 ;
  mov sp, $FFE0 ; Make space for argc(2 bytes) and for 10 pointers in argv (local variables)
; return 0; 
  mov32 cb, $00000000
  leave
  syscall sys_terminate_proc
; --- END TEXT SEGMENT

; --- BEGIN DATA SEGMENT
_rng_state: .dw $0000

_heap_top: .dw _heap
_heap: .db 0
; --- END DATA SEGMENT

.end
