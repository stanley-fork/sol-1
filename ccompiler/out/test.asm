; --- FILENAME: test.c
; --- DATE:     25-10-2025 at 05:25:02
.include "lib/asm/kernel.exp"
.include "lib/asm/bios.exp"

; --- BEGIN TEXT SEGMENT
.org text_org
main:
  mov bp, $FFE0 ;
  mov sp, $FFE0 ; Make space for argc(2 bytes) and for 10 pointers in argv (local variables)
; int data[10]; 
  sub sp, 20
; int ok = 1; 
  sub sp, 2
; --- START LOCAL VAR INITIALIZATION
  lea d, [bp + -21] ; $ok
  push d
  mov32 cb, $00000001
  pop d
  mov [d], b
; --- END LOCAL VAR INITIALIZATION
; printf("=== Compiler Self-Test ===\n"); 
; --- START FUNCTION CALL
  mov b, _s0 ; "=== Compiler Self-Test ===\n"
  swp b
  push b
  call printf
  add sp, 2
; --- END FUNCTION CALL
; fill_array(data, 10); 
; --- START FUNCTION CALL
  mov32 cb, $0000000a
  swp b
  push b
  lea d, [bp + -19] ; $data
  mov b, d
  mov c, 0
  swp b
  push b
  call fill_array
  add sp, 4
; --- END FUNCTION CALL
; if (!check_array(data, 10)) ok = 0; 
_if1_cond:
; --- START FUNCTION CALL
  mov32 cb, $0000000a
  swp b
  push b
  lea d, [bp + -19] ; $data
  mov b, d
  mov c, 0
  swp b
  push b
  call check_array
  add sp, 4
; --- END FUNCTION CALL
  cmp b, 0
  je _if1_exit
_if1_TRUE:
; ok = 0; 
  lea d, [bp + -21] ; $ok
  push d
  mov32 cb, $00000000
  pop d
  mov [d], b
  jmp _if1_exit
_if1_exit:
; if (!check_factorial()) ok = 0; 
_if2_cond:
; --- START FUNCTION CALL
  call check_factorial
  cmp b, 0
  je _if2_exit
_if2_TRUE:
; ok = 0; 
  lea d, [bp + -21] ; $ok
  push d
  mov32 cb, $00000000
  pop d
  mov [d], b
  jmp _if2_exit
_if2_exit:
; if (!check_structs()) ok = 0; 
_if3_cond:
; --- START FUNCTION CALL
  call check_structs
  cmp b, 0
  je _if3_exit
_if3_TRUE:
; ok = 0; 
  lea d, [bp + -21] ; $ok
  push d
  mov32 cb, $00000000
  pop d
  mov [d], b
  jmp _if3_exit
_if3_exit:
; if (!check_pointers(data)) ok = 0; 
_if4_cond:
; --- START FUNCTION CALL
  lea d, [bp + -19] ; $data
  mov b, d
  mov c, 0
  swp b
  push b
  call check_pointers
  add sp, 2
; --- END FUNCTION CALL
  cmp b, 0
  je _if4_exit
_if4_TRUE:
; ok = 0; 
  lea d, [bp + -21] ; $ok
  push d
  mov32 cb, $00000000
  pop d
  mov [d], b
  jmp _if4_exit
_if4_exit:
; if (ok) 
_if5_cond:
  lea d, [bp + -21] ; $ok
  mov b, [d]
  mov c, 0
  cmp b, 0
  je _if5_else
_if5_TRUE:
; printf("\n*** ALL TESTS PASSED ***\n"); 
; --- START FUNCTION CALL
  mov b, _s1 ; "\n*** ALL TESTS PASSED ***\n"
  swp b
  push b
  call printf
  add sp, 2
; --- END FUNCTION CALL
  jmp _if5_exit
_if5_else:
; printf("\n*** TEST FAILED ***\n"); 
; --- START FUNCTION CALL
  mov b, _s2 ; "\n*** TEST FAILED ***\n"
  swp b
  push b
  call printf
  add sp, 2
; --- END FUNCTION CALL
_if5_exit:
; return ok ? 0 : 1; 
_ternary6_cond:
  lea d, [bp + -21] ; $ok
  mov b, [d]
  mov c, 0
  cmp b, 0
  je _ternary6_FALSE
_ternary6_TRUE:
  mov32 cb, $00000000
  jmp _ternary6_exit
_ternary6_FALSE:
  mov32 cb, $00000001
_ternary6_exit:
  leave
  syscall sys_terminate_proc

factorial:
  enter 0 ; (push bp; mov bp, sp)
; if (n <= 1) return 1; 
_if7_cond:
  lea d, [bp + 5] ; $n
  mov b, [d]
  mov c, 0
; --- START RELATIONAL
  push a
  mov a, b
  mov32 cb, $00000001
  cmp a, b
  sle ; <= (signed)
  pop a
; --- END RELATIONAL
  cmp b, 0
  je _if7_exit
_if7_TRUE:
; return 1; 
  mov32 cb, $00000001
  leave
  ret
  jmp _if7_exit
_if7_exit:
; return n * factorial(n - 1); 
  lea d, [bp + 5] ; $n
  mov b, [d]
  mov c, 0
; --- START FACTORS
  push a
  push g
  mov a, b
  mov g, c
; --- START FUNCTION CALL
  lea d, [bp + 5] ; $n
  mov b, [d]
  mov c, 0
; --- START TERMS
  push a
  mov a, b
  mov32 cb, $00000001
  sub a, b
  mov b, a
  pop a
; --- END TERMS
  swp b
  push b
  call factorial
  add sp, 2
; --- END FUNCTION CALL
  push a     ; save left operand
  xor a, b   ; xor sign bits
  swp a      ; swap bytes
  mov cl, al ; save result of xor into 'dl'
  pop a      ; restore left side operator
  push cl    ; save result of xor above
  swp a  
  test al, $80  
  swp a  
  jz skip_invert_a_9  
  neg a 
skip_invert_a_9:   
  swp b
  test bl, $80  
  swp b
  jz skip_invert_b_9  
  neg b 
skip_invert_b_9:   
  mul a, b ; *
  mov g, a
  mov a, b
  pop bl
  test bl, $80
  jz _same_signs_9
  mov bl, al
  not a
  neg b
  adc a, 0
  mov g, a
  mov a, b
_same_signs_9:
  mov c, g
  mov b, a
  pop g
  pop a
; --- END FACTORS
  leave
  ret

fill_array:
  enter 0 ; (push bp; mov bp, sp)
; int i; 
  sub sp, 2
; for (i = 0; i < n; i++) { 
_for10_init:
  lea d, [bp + -1] ; $i
  push d
  mov32 cb, $00000000
  pop d
  mov [d], b
_for10_cond:
  lea d, [bp + -1] ; $i
  mov b, [d]
  mov c, 0
; --- START RELATIONAL
  push a
  mov a, b
  lea d, [bp + 7] ; $n
  mov b, [d]
  mov c, 0
  cmp a, b
  slt ; < (signed)
  pop a
; --- END RELATIONAL
  cmp b, 0
  je _for10_exit
_for10_block:
; arr[i] = (i * i + 3 * i + 7) % 97; 
  lea d, [bp + 5] ; $arr
  mov d, [d]
  push a
  push d
  lea d, [bp + -1] ; $i
  mov b, [d]
  mov c, 0
  pop d
  mma 2 ; mov a, 2; mul a b; add d, b
  pop a
  push d
  lea d, [bp + -1] ; $i
  mov b, [d]
  mov c, 0
; --- START FACTORS
  push a
  push g
  mov a, b
  mov g, c
  lea d, [bp + -1] ; $i
  mov b, [d]
  mov c, 0
  push a     ; save left operand
  xor a, b   ; xor sign bits
  swp a      ; swap bytes
  mov cl, al ; save result of xor into 'dl'
  pop a      ; restore left side operator
  push cl    ; save result of xor above
  swp a  
  test al, $80  
  swp a  
  jz skip_invert_a_18  
  neg a 
skip_invert_a_18:   
  swp b
  test bl, $80  
  swp b
  jz skip_invert_b_18  
  neg b 
skip_invert_b_18:   
  mul a, b ; *
  mov g, a
  mov a, b
  pop bl
  test bl, $80
  jz _same_signs_18
  mov bl, al
  not a
  neg b
  adc a, 0
  mov g, a
  mov a, b
_same_signs_18:
  mov c, g
  mov b, a
  pop g
  pop a
; --- END FACTORS
; --- START TERMS
  push a
  push g
  mov a, b
  mov g, c
  mov32 cb, $00000003
; --- START FACTORS
  push a
  push g
  mov a, b
  mov g, c
  lea d, [bp + -1] ; $i
  mov b, [d]
  mov c, 0
  push a     ; save left operand
  xor a, b   ; xor sign bits
  swp a      ; swap bytes
  mov cl, al ; save result of xor into 'dl'
  pop a      ; restore left side operator
  push cl    ; save result of xor above
  swp a  
  test al, $80  
  swp a  
  jz skip_invert_a_19  
  neg a 
skip_invert_a_19:   
  swp b
  test bl, $80  
  swp b
  jz skip_invert_b_19  
  neg b 
skip_invert_b_19:   
  mul a, b ; *
  mov g, a
  mov a, b
  pop bl
  test bl, $80
  jz _same_signs_19
  mov bl, al
  not a
  neg b
  adc a, 0
  mov g, a
  mov a, b
_same_signs_19:
  mov c, g
  mov b, a
  pop g
  pop a
; --- END FACTORS
  add32 cb, ga
  mov a, b
  mov g, c
  mov32 cb, $00000007
  mov c, 0
  add32 cb, ga
  pop g
  pop a
; --- END TERMS
; --- START FACTORS
  push a
  push g
  mov a, b
  mov g, c
  mov32 cb, $00000061
  push g ; save 'g' as the div instruction uses it
  div a, b ; %, a: quotient, b: remainder
  mov a, b
  pop g
  mov c, g
  mov b, a
  pop g
  pop a
; --- END FACTORS
  pop d
  mov [d], b
_for10_update:
  lea d, [bp + -1] ; $i
  mov b, [d]
  mov c, 0
  mov a, b
  inc b
  lea d, [bp + -1] ; $i
  mov [d], b
  mov b, a
  jmp _for10_cond
_for10_exit:
  leave
  ret

check_array:
  enter 0 ; (push bp; mov bp, sp)
; int i; 
  sub sp, 2
; for (i = 0; i < n; i++) { 
_for21_init:
  lea d, [bp + -1] ; $i
  push d
  mov32 cb, $00000000
  pop d
  mov [d], b
_for21_cond:
  lea d, [bp + -1] ; $i
  mov b, [d]
  mov c, 0
; --- START RELATIONAL
  push a
  mov a, b
  lea d, [bp + 7] ; $n
  mov b, [d]
  mov c, 0
  cmp a, b
  slt ; < (signed)
  pop a
; --- END RELATIONAL
  cmp b, 0
  je _for21_exit
_for21_block:
; if (arr[i] != expected[i]) { 
_if22_cond:
  lea d, [bp + 5] ; $arr
  mov d, [d]
  push a
  push d
  lea d, [bp + -1] ; $i
  mov b, [d]
  mov c, 0
  pop d
  mma 2 ; mov a, 2; mul a b; add d, b
  pop a
  mov b, [d]
  mov c, 0
; --- START RELATIONAL
  push a
  mov a, b
  mov d, _expected_data ; $expected
  push a
  push d
  lea d, [bp + -1] ; $i
  mov b, [d]
  mov c, 0
  pop d
  mma 2 ; mov a, 2; mul a, b; add d, b
  pop a
  mov b, [d]
  mov c, 0
  cmp a, b
  sneq ; !=
  pop a
; --- END RELATIONAL
  cmp b, 0
  je _if22_exit
_if22_TRUE:
; printf("Array mismatch at %d: got %d expected %d\n", i, arr[i], expected[i]); 
; --- START FUNCTION CALL
  mov d, _expected_data ; $expected
  push a
  push d
  lea d, [bp + -1] ; $i
  mov b, [d]
  mov c, 0
  pop d
  mma 2 ; mov a, 2; mul a, b; add d, b
  pop a
  mov b, [d]
  mov c, 0
  swp b
  push b
  lea d, [bp + 5] ; $arr
  mov d, [d]
  push a
  push d
  lea d, [bp + -1] ; $i
  mov b, [d]
  mov c, 0
  pop d
  mma 2 ; mov a, 2; mul a b; add d, b
  pop a
  mov b, [d]
  mov c, 0
  swp b
  push b
  lea d, [bp + -1] ; $i
  mov b, [d]
  mov c, 0
  swp b
  push b
  mov b, _s3 ; "Array mismatch at %d: got %d expected %d\n"
  swp b
  push b
  call printf
  add sp, 8
; --- END FUNCTION CALL
; return 0; 
  mov32 cb, $00000000
  leave
  ret
  jmp _if22_exit
_if22_exit:
_for21_update:
  lea d, [bp + -1] ; $i
  mov b, [d]
  mov c, 0
  mov a, b
  inc b
  lea d, [bp + -1] ; $i
  mov [d], b
  mov b, a
  jmp _for21_cond
_for21_exit:
; return 1; 
  mov32 cb, $00000001
  leave
  ret

check_factorial:
  enter 0 ; (push bp; mov bp, sp)
; int f = factorial(6); 
  sub sp, 2
; --- START LOCAL VAR INITIALIZATION
  lea d, [bp + -1] ; $f
  push d
; --- START FUNCTION CALL
  mov32 cb, $00000006
  swp b
  push b
  call factorial
  add sp, 2
; --- END FUNCTION CALL
  pop d
  mov [d], b
; --- END LOCAL VAR INITIALIZATION
; if (f != 720) { 
_if23_cond:
  lea d, [bp + -1] ; $f
  mov b, [d]
  mov c, 0
; --- START RELATIONAL
  push a
  mov a, b
  mov32 cb, $000002d0
  cmp a, b
  sneq ; !=
  pop a
; --- END RELATIONAL
  cmp b, 0
  je _if23_exit
_if23_TRUE:
; printf("Factorial failed: got %d expected 720\n", f); 
; --- START FUNCTION CALL
  lea d, [bp + -1] ; $f
  mov b, [d]
  mov c, 0
  swp b
  push b
  mov b, _s4 ; "Factorial failed: got %d expected 720\n"
  swp b
  push b
  call printf
  add sp, 4
; --- END FUNCTION CALL
; return 0; 
  mov32 cb, $00000000
  leave
  ret
  jmp _if23_exit
_if23_exit:
; return 1; 
  mov32 cb, $00000001
  leave
  ret

check_structs:
  enter 0 ; (push bp; mov bp, sp)
; struct Point pts[3]; 
  sub sp, 12
; int i; 
  sub sp, 2
; for (i = 0; i < 3; i++) { 
_for24_init:
  lea d, [bp + -13] ; $i
  push d
  mov32 cb, $00000000
  pop d
  mov [d], b
_for24_cond:
  lea d, [bp + -13] ; $i
  mov b, [d]
  mov c, 0
; --- START RELATIONAL
  push a
  mov a, b
  mov32 cb, $00000003
  cmp a, b
  slt ; < (signed)
  pop a
; --- END RELATIONAL
  cmp b, 0
  je _for24_exit
_for24_block:
; pts[i].x = i; 
  lea d, [bp + -11] ; $pts
  push a
  push d
  lea d, [bp + -13] ; $i
  mov b, [d]
  mov c, 0
  pop d
  mma 4 ; mov a, 4; mul a, b; add d, b
  pop a
  add d, 0
  push d
  lea d, [bp + -13] ; $i
  mov b, [d]
  mov c, 0
  pop d
  mov [d], b
; pts[i].y = i * i; 
  lea d, [bp + -11] ; $pts
  push a
  push d
  lea d, [bp + -13] ; $i
  mov b, [d]
  mov c, 0
  pop d
  mma 4 ; mov a, 4; mul a, b; add d, b
  pop a
  add d, 2
  push d
  lea d, [bp + -13] ; $i
  mov b, [d]
  mov c, 0
; --- START FACTORS
  push a
  push g
  mov a, b
  mov g, c
  lea d, [bp + -13] ; $i
  mov b, [d]
  mov c, 0
  push a     ; save left operand
  xor a, b   ; xor sign bits
  swp a      ; swap bytes
  mov cl, al ; save result of xor into 'dl'
  pop a      ; restore left side operator
  push cl    ; save result of xor above
  swp a  
  test al, $80  
  swp a  
  jz skip_invert_a_26  
  neg a 
skip_invert_a_26:   
  swp b
  test bl, $80  
  swp b
  jz skip_invert_b_26  
  neg b 
skip_invert_b_26:   
  mul a, b ; *
  mov g, a
  mov a, b
  pop bl
  test bl, $80
  jz _same_signs_26
  mov bl, al
  not a
  neg b
  adc a, 0
  mov g, a
  mov a, b
_same_signs_26:
  mov c, g
  mov b, a
  pop g
  pop a
; --- END FACTORS
  pop d
  mov [d], b
_for24_update:
  lea d, [bp + -13] ; $i
  mov b, [d]
  mov c, 0
  mov a, b
  inc b
  lea d, [bp + -13] ; $i
  mov [d], b
  mov b, a
  jmp _for24_cond
_for24_exit:
; if (pts[2].x != 2 || pts[2].y != 4) { 
_if27_cond:
  lea d, [bp + -11] ; $pts
  push a
  push d
  mov32 cb, $00000002
  pop d
  mma 4 ; mov a, 4; mul a, b; add d, b
  pop a
  add d, 0
  mov b, [d]
  mov c, 0
; --- START RELATIONAL
  push a
  mov a, b
  mov32 cb, $00000002
  cmp a, b
  sneq ; !=
  pop a
; --- END RELATIONAL
; --- START LOGICAL OR
  push a
  mov a, b
  lea d, [bp + -11] ; $pts
  push a
  push d
  mov32 cb, $00000002
  pop d
  mma 4 ; mov a, 4; mul a, b; add d, b
  pop a
  add d, 2
  mov b, [d]
  mov c, 0
; --- START RELATIONAL
  push a
  mov a, b
  mov32 cb, $00000004
  cmp a, b
  sneq ; !=
  pop a
; --- END RELATIONAL
  sor a, b ; ||
  pop a
; --- END LOGICAL OR
  cmp b, 0
  je _if27_exit
_if27_TRUE:
; printf("Struct check failed: (%d,%d)\n", pts[2].x, pts[2].y); 
; --- START FUNCTION CALL
  lea d, [bp + -11] ; $pts
  push a
  push d
  mov32 cb, $00000002
  pop d
  mma 4 ; mov a, 4; mul a, b; add d, b
  pop a
  add d, 2
  mov b, [d]
  mov c, 0
  swp b
  push b
  lea d, [bp + -11] ; $pts
  push a
  push d
  mov32 cb, $00000002
  pop d
  mma 4 ; mov a, 4; mul a, b; add d, b
  pop a
  add d, 0
  mov b, [d]
  mov c, 0
  swp b
  push b
  mov b, _s5 ; "Struct check failed: (%d,%d)\n"
  swp b
  push b
  call printf
  add sp, 6
; --- END FUNCTION CALL
; return 0; 
  mov32 cb, $00000000
  leave
  ret
  jmp _if27_exit
_if27_exit:
; return 1; 
  mov32 cb, $00000001
  leave
  ret

check_pointers:
  enter 0 ; (push bp; mov bp, sp)
; int *p = arr; 
  sub sp, 2
; --- START LOCAL VAR INITIALIZATION
  lea d, [bp + -1] ; $p
  push d
  lea d, [bp + 5] ; $arr
  mov b, [d]
  mov c, 0
  pop d
  mov [d], b
; --- END LOCAL VAR INITIALIZATION
; if (*p != 7 || *(p + 5) != 47) { 
_if28_cond:
  lea d, [bp + -1] ; $p
  mov b, [d]
  mov c, 0
  mov d, b
  mov b, [d]
  mov c, 0
; --- START RELATIONAL
  push a
  mov a, b
  mov32 cb, $00000007
  cmp a, b
  sneq ; !=
  pop a
; --- END RELATIONAL
; --- START LOGICAL OR
  push a
  mov a, b
  lea d, [bp + -1] ; $p
  mov b, [d]
  mov c, 0
; --- START TERMS
  push a
  mov a, b
  mov32 cb, $00000005
  add b, a
  pop a
; --- END TERMS
  mov d, b
  mov b, [d]
  mov c, 0
; --- START RELATIONAL
  push a
  mov a, b
  mov32 cb, $0000002f
  cmp a, b
  sneq ; !=
  pop a
; --- END RELATIONAL
  sor a, b ; ||
  pop a
; --- END LOGICAL OR
  cmp b, 0
  je _if28_exit
_if28_TRUE:
; printf("Pointer check failed: *p=%d *(p+5)=%d\n", *p, *(p + 5)); 
; --- START FUNCTION CALL
  lea d, [bp + -1] ; $p
  mov b, [d]
  mov c, 0
; --- START TERMS
  push a
  mov a, b
  mov32 cb, $00000005
  add b, a
  pop a
; --- END TERMS
  mov d, b
  mov b, [d]
  mov c, 0
  swp b
  push b
  lea d, [bp + -1] ; $p
  mov b, [d]
  mov c, 0
  mov d, b
  mov b, [d]
  mov c, 0
  swp b
  push b
  mov b, _s6 ; "Pointer check failed: *p=%d *(p+5)=%d\n"
  swp b
  push b
  call printf
  add sp, 6
; --- END FUNCTION CALL
; return 0; 
  mov32 cb, $00000000
  leave
  ret
  jmp _if28_exit
_if28_exit:
; return 1; 
  mov32 cb, $00000001
  leave
  ret

printf:
  enter 0 ; (push bp; mov bp, sp)
; char *p, *format_p; 
  sub sp, 1
  sub sp, 2
; format_p = format; 
  lea d, [bp + -2] ; $format_p
  push d
  lea d, [bp + 5] ; $format
  mov b, [d]
  mov c, 0
  pop d
  mov [d], b
; p = &format + 2; 
  lea d, [bp + 0] ; $p
  push d
  lea d, [bp + 5] ; $format
  mov b, d
; --- START TERMS
  push a
  mov a, b
  mov32 cb, $00000002
  add b, a
  pop a
; --- END TERMS
  pop d
  mov [d], bl
; for(;;){ 
_for29_init:
_for29_cond:
_for29_block:
; if(!*format_p) break; 
_if30_cond:
  lea d, [bp + -2] ; $format_p
  mov b, [d]
  mov c, 0
  mov d, b
  mov bl, [d]
  mov bh, 0
  mov c, 0
  cmp b, 0
  seq ; !
  cmp b, 0
  je _if30_else
_if30_TRUE:
; break; 
  jmp _for29_exit ; for break
  jmp _if30_exit
_if30_else:
; if(*format_p == '%'){ 
_if31_cond:
  lea d, [bp + -2] ; $format_p
  mov b, [d]
  mov c, 0
  mov d, b
  mov bl, [d]
  mov bh, 0
  mov c, 0
; --- START RELATIONAL
  push a
  mov a, b
  mov32 cb, $00000025
  cmp a, b
  seq ; ==
  pop a
; --- END RELATIONAL
  cmp b, 0
  je _if31_else
_if31_TRUE:
; format_p++; 
  lea d, [bp + -2] ; $format_p
  mov b, [d]
  mov c, 0
  inc b
  lea d, [bp + -2] ; $format_p
  mov [d], b
  dec b
; switch(*format_p){ 
_switch32_expr:
  lea d, [bp + -2] ; $format_p
  mov b, [d]
  mov c, 0
  mov d, b
  mov bl, [d]
  mov bh, 0
  mov c, 0
_switch32_comparisons:
  cmp bl, $6c
  je _switch32_case0
  cmp bl, $4c
  je _switch32_case1
  cmp bl, $64
  je _switch32_case2
  cmp bl, $69
  je _switch32_case3
  cmp bl, $75
  je _switch32_case4
  cmp bl, $78
  je _switch32_case5
  cmp bl, $70
  je _switch32_case6
  cmp bl, $63
  je _switch32_case7
  cmp bl, $73
  je _switch32_case8
  jmp _switch32_default
  jmp _switch32_exit
_switch32_case0:
_switch32_case1:
; format_p++; 
  lea d, [bp + -2] ; $format_p
  mov b, [d]
  mov c, 0
  inc b
  lea d, [bp + -2] ; $format_p
  mov [d], b
  dec b
; if(*format_p == 'd' || *format_p == 'i') 
_if33_cond:
  lea d, [bp + -2] ; $format_p
  mov b, [d]
  mov c, 0
  mov d, b
  mov bl, [d]
  mov bh, 0
  mov c, 0
; --- START RELATIONAL
  push a
  mov a, b
  mov32 cb, $00000064
  cmp a, b
  seq ; ==
  pop a
; --- END RELATIONAL
; --- START LOGICAL OR
  push a
  mov a, b
  lea d, [bp + -2] ; $format_p
  mov b, [d]
  mov c, 0
  mov d, b
  mov bl, [d]
  mov bh, 0
  mov c, 0
; --- START RELATIONAL
  push a
  mov a, b
  mov32 cb, $00000069
  cmp a, b
  seq ; ==
  pop a
; --- END RELATIONAL
  sor a, b ; ||
  pop a
; --- END LOGICAL OR
  cmp b, 0
  je _if33_else
_if33_TRUE:
; print_signed_long(*(long int*)p); 
; --- START FUNCTION CALL
  lea d, [bp + 0] ; $p
  mov bl, [d]
  mov bh, 0
  mov c, 0
  mov d, b
  mov b, [d + 2] ; Upper Word of the Long Int
  mov c, b ; And place it into C
  mov b, [d] ; Lower Word in B
  mov a, c
  swp a
  push a
  swp b
  push b
  call print_signed_long
  add sp, 4
; --- END FUNCTION CALL
  jmp _if33_exit
_if33_else:
; if(*format_p == 'u') 
_if34_cond:
  lea d, [bp + -2] ; $format_p
  mov b, [d]
  mov c, 0
  mov d, b
  mov bl, [d]
  mov bh, 0
  mov c, 0
; --- START RELATIONAL
  push a
  mov a, b
  mov32 cb, $00000075
  cmp a, b
  seq ; ==
  pop a
; --- END RELATIONAL
  cmp b, 0
  je _if34_else
_if34_TRUE:
; print_unsigned_long(*(unsigned long int*)p); 
; --- START FUNCTION CALL
  lea d, [bp + 0] ; $p
  mov bl, [d]
  mov bh, 0
  mov c, 0
  mov d, b
  mov b, [d + 2] ; Upper Word of the Long Int
  mov c, b ; And place it into C
  mov b, [d] ; Lower Word in B
  mov a, c
  swp a
  push a
  swp b
  push b
  call print_unsigned_long
  add sp, 4
; --- END FUNCTION CALL
  jmp _if34_exit
_if34_else:
; if(*format_p == 'x') 
_if35_cond:
  lea d, [bp + -2] ; $format_p
  mov b, [d]
  mov c, 0
  mov d, b
  mov bl, [d]
  mov bh, 0
  mov c, 0
; --- START RELATIONAL
  push a
  mov a, b
  mov32 cb, $00000078
  cmp a, b
  seq ; ==
  pop a
; --- END RELATIONAL
  cmp b, 0
  je _if35_else
_if35_TRUE:
; printx32(*(long int *)p); 
; --- START FUNCTION CALL
  lea d, [bp + 0] ; $p
  mov bl, [d]
  mov bh, 0
  mov c, 0
  mov d, b
  mov b, [d + 2] ; Upper Word of the Long Int
  mov c, b ; And place it into C
  mov b, [d] ; Lower Word in B
  mov a, c
  swp a
  push a
  swp b
  push b
  call printx32
  add sp, 4
; --- END FUNCTION CALL
  jmp _if35_exit
_if35_else:
; err("Unexpected format in printf."); 
; --- START FUNCTION CALL
  mov b, _s7 ; "Unexpected format in printf."
  swp b
  push b
  call err
  add sp, 2
; --- END FUNCTION CALL
_if35_exit:
_if34_exit:
_if33_exit:
; p = p + 4; 
  lea d, [bp + 0] ; $p
  push d
  lea d, [bp + 0] ; $p
  mov bl, [d]
  mov bh, 0
  mov c, 0
; --- START TERMS
  push a
  mov a, b
  mov32 cb, $00000004
  add b, a
  pop a
; --- END TERMS
  pop d
  mov [d], bl
; break; 
  jmp _switch32_exit ; case break
_switch32_case2:
_switch32_case3:
; print_signed(*(int*)p); 
; --- START FUNCTION CALL
  lea d, [bp + 0] ; $p
  mov bl, [d]
  mov bh, 0
  mov c, 0
  mov d, b
  mov b, [d]
  mov c, 0
  swp b
  push b
  call print_signed
  add sp, 2
; --- END FUNCTION CALL
; p = p + 2; 
  lea d, [bp + 0] ; $p
  push d
  lea d, [bp + 0] ; $p
  mov bl, [d]
  mov bh, 0
  mov c, 0
; --- START TERMS
  push a
  mov a, b
  mov32 cb, $00000002
  add b, a
  pop a
; --- END TERMS
  pop d
  mov [d], bl
; break; 
  jmp _switch32_exit ; case break
_switch32_case4:
; print_unsigned(*(unsigned int*)p); 
; --- START FUNCTION CALL
  lea d, [bp + 0] ; $p
  mov bl, [d]
  mov bh, 0
  mov c, 0
  mov d, b
  mov b, [d]
  mov c, 0
  swp b
  push b
  call print_unsigned
  add sp, 2
; --- END FUNCTION CALL
; p = p + 2; 
  lea d, [bp + 0] ; $p
  push d
  lea d, [bp + 0] ; $p
  mov bl, [d]
  mov bh, 0
  mov c, 0
; --- START TERMS
  push a
  mov a, b
  mov32 cb, $00000002
  add b, a
  pop a
; --- END TERMS
  pop d
  mov [d], bl
; break; 
  jmp _switch32_exit ; case break
_switch32_case5:
_switch32_case6:
; printx16(*(int*)p); 
; --- START FUNCTION CALL
  lea d, [bp + 0] ; $p
  mov bl, [d]
  mov bh, 0
  mov c, 0
  mov d, b
  mov b, [d]
  mov c, 0
  swp b
  push b
  call printx16
  add sp, 2
; --- END FUNCTION CALL
; p = p + 2; 
  lea d, [bp + 0] ; $p
  push d
  lea d, [bp + 0] ; $p
  mov bl, [d]
  mov bh, 0
  mov c, 0
; --- START TERMS
  push a
  mov a, b
  mov32 cb, $00000002
  add b, a
  pop a
; --- END TERMS
  pop d
  mov [d], bl
; break; 
  jmp _switch32_exit ; case break
_switch32_case7:
; putchar(*(char*)p); 
; --- START FUNCTION CALL
  lea d, [bp + 0] ; $p
  mov bl, [d]
  mov bh, 0
  mov c, 0
  mov d, b
  mov bl, [d]
  mov bh, 0
  mov c, 0
  push bl
  call putchar
  add sp, 1
; --- END FUNCTION CALL
; p = p + 2; 
  lea d, [bp + 0] ; $p
  push d
  lea d, [bp + 0] ; $p
  mov bl, [d]
  mov bh, 0
  mov c, 0
; --- START TERMS
  push a
  mov a, b
  mov32 cb, $00000002
  add b, a
  pop a
; --- END TERMS
  pop d
  mov [d], bl
; break; 
  jmp _switch32_exit ; case break
_switch32_case8:
; print(*(char**)p); 
; --- START FUNCTION CALL
  lea d, [bp + 0] ; $p
  mov bl, [d]
  mov bh, 0
  mov c, 0
  mov d, b
  mov b, [d]
  swp b
  push b
  call print
  add sp, 2
; --- END FUNCTION CALL
; p = p + 2; 
  lea d, [bp + 0] ; $p
  push d
  lea d, [bp + 0] ; $p
  mov bl, [d]
  mov bh, 0
  mov c, 0
; --- START TERMS
  push a
  mov a, b
  mov32 cb, $00000002
  add b, a
  pop a
; --- END TERMS
  pop d
  mov [d], bl
; break; 
  jmp _switch32_exit ; case break
_switch32_default:
; print("Error: Unknown argument type.\n"); 
; --- START FUNCTION CALL
  mov b, _s8 ; "Error: Unknown argument type.\n"
  swp b
  push b
  call print
  add sp, 2
; --- END FUNCTION CALL
_switch32_exit:
  jmp _if31_exit
_if31_else:
; putchar(*format_p); 
; --- START FUNCTION CALL
  lea d, [bp + -2] ; $format_p
  mov b, [d]
  mov c, 0
  mov d, b
  mov bl, [d]
  mov bh, 0
  mov c, 0
  push bl
  call putchar
  add sp, 1
; --- END FUNCTION CALL
_if31_exit:
_if30_exit:
; format_p++; 
  lea d, [bp + -2] ; $format_p
  mov b, [d]
  mov c, 0
  inc b
  lea d, [bp + -2] ; $format_p
  mov [d], b
  dec b
_for29_update:
  jmp _for29_cond
_for29_exit:
  leave
  ret

print_signed_long:
  enter 0 ; (push bp; mov bp, sp)
; char digits[10];  // fits 2,147,483,647 
  sub sp, 10
; int i = 0; 
  sub sp, 2
; --- START LOCAL VAR INITIALIZATION
  lea d, [bp + -11] ; $i
  push d
  mov32 cb, $00000000
  pop d
  mov [d], b
; --- END LOCAL VAR INITIALIZATION
; unsigned long int absval; 
  sub sp, 4
; if (num < 0) { 
_if36_cond:
  lea d, [bp + 5] ; $num
  mov b, [d + 2] ; Upper Word of the Long Int
  mov c, b ; And place it into C
  mov b, [d] ; Lower Word in B
; --- START RELATIONAL
  push a
  push g
  mov a, b
  mov g, c
  mov32 cb, $00000000
  mov c, 0
  cmp32 ga, cb
  slt ; <
  pop g
  pop a
; --- END RELATIONAL
  cmp b, 0
  je _if36_else
_if36_TRUE:
; putchar('-'); 
; --- START FUNCTION CALL
  mov32 cb, $0000002d
  push bl
  call putchar
  add sp, 1
; --- END FUNCTION CALL
; absval = (unsigned long int)(-(num + 1)) + 1; 
  lea d, [bp + -15] ; $absval
  push d
  lea d, [bp + 5] ; $num
  mov b, [d + 2] ; Upper Word of the Long Int
  mov c, b ; And place it into C
  mov b, [d] ; Lower Word in B
; --- START TERMS
  push a
  push g
  mov a, b
  mov g, c
  mov32 cb, $00000001
  mov c, 0
  add32 cb, ga
  pop g
  pop a
; --- END TERMS
  mov a, c
  not a
  not b
  add b, 1
  adc a, 0
  mov c, a
  mov bh, 0
  mov c, 0
; --- START TERMS
  push a
  push g
  mov a, b
  mov g, c
  mov32 cb, $00000001
  mov c, 0
  add32 cb, ga
  pop g
  pop a
; --- END TERMS
  pop d
  mov [d], b
  mov b, c
  mov [d + 2], b
  jmp _if36_exit
_if36_else:
; absval = (unsigned long int)num; 
  lea d, [bp + -15] ; $absval
  push d
  lea d, [bp + 5] ; $num
  mov b, [d + 2] ; Upper Word of the Long Int
  mov c, b ; And place it into C
  mov b, [d] ; Lower Word in B
  mov bh, 0
  mov c, 0
  pop d
  mov [d], b
  mov b, c
  mov [d + 2], b
_if36_exit:
; if (absval == 0) { 
_if37_cond:
  lea d, [bp + -15] ; $absval
  mov b, [d + 2] ; Upper Word of the Long Int
  mov c, b ; And place it into C
  mov b, [d] ; Lower Word in B
; --- START RELATIONAL
  push a
  push g
  mov a, b
  mov g, c
  mov32 cb, $00000000
  mov c, 0
  cmp32 ga, cb
  seq ; ==
  pop g
  pop a
; --- END RELATIONAL
  cmp b, 0
  je _if37_exit
_if37_TRUE:
; putchar('0'); 
; --- START FUNCTION CALL
  mov32 cb, $00000030
  push bl
  call putchar
  add sp, 1
; --- END FUNCTION CALL
; return; 
  leave
  ret
  jmp _if37_exit
_if37_exit:
; while (absval > 0) { 
_while38_cond:
  lea d, [bp + -15] ; $absval
  mov b, [d + 2] ; Upper Word of the Long Int
  mov c, b ; And place it into C
  mov b, [d] ; Lower Word in B
; --- START RELATIONAL
  push a
  push g
  mov a, b
  mov g, c
  mov32 cb, $00000000
  mov c, 0
  cmp32 ga, cb
  sgu
  pop g
  pop a
; --- END RELATIONAL
  cmp b, 0
  je _while38_exit
_while38_block:
; digits[i++] = '0' + (absval % 10); 
  lea d, [bp + -9] ; $digits
  push a
  push d
  lea d, [bp + -11] ; $i
  mov b, [d]
  mov c, 0
  mov a, b
  inc b
  lea d, [bp + -11] ; $i
  mov [d], b
  mov b, a
  pop d
  add d, b
  pop a
  push d
  mov32 cb, $00000030
; --- START TERMS
  push a
  mov a, b
  lea d, [bp + -15] ; $absval
  mov b, [d + 2] ; Upper Word of the Long Int
  mov c, b ; And place it into C
  mov b, [d] ; Lower Word in B
; --- START FACTORS
  push a
  push g
  mov a, b
  mov g, c
  mov32 cb, $0000000a
  push g ; save 'g' as the div instruction uses it
  div a, b ; %, a: quotient, b: remainder
  mov a, b
  pop g
  mov c, g
  mov b, a
  pop g
  pop a
; --- END FACTORS
  mov g, 0
  add32 cb, ga
  pop a
; --- END TERMS
  pop d
  mov [d], bl
; absval = absval / 10; 
  lea d, [bp + -15] ; $absval
  push d
  lea d, [bp + -15] ; $absval
  mov b, [d + 2] ; Upper Word of the Long Int
  mov c, b ; And place it into C
  mov b, [d] ; Lower Word in B
; --- START FACTORS
  push a
  push g
  mov a, b
  mov g, c
  mov32 cb, $0000000a
  push g ; save 'g' as the div instruction uses it
  div a, b ; /, a: quotient, b: remainder
  pop g
  mov c, g
  mov b, a
  pop g
  pop a
; --- END FACTORS
  pop d
  mov [d], b
  mov b, c
  mov [d + 2], b
  jmp _while38_cond
_while38_exit:
; while (i > 0) { 
_while45_cond:
  lea d, [bp + -11] ; $i
  mov b, [d]
  mov c, 0
; --- START RELATIONAL
  push a
  mov a, b
  mov32 cb, $00000000
  cmp a, b
  sgt ; >
  pop a
; --- END RELATIONAL
  cmp b, 0
  je _while45_exit
_while45_block:
; putchar(digits[--i]); 
; --- START FUNCTION CALL
  lea d, [bp + -9] ; $digits
  push a
  push d
  lea d, [bp + -11] ; $i
  mov b, [d]
  dec b
  lea d, [bp + -11] ; $i
  mov [d], b
  pop d
  add d, b
  pop a
  mov bl, [d]
  mov bh, 0
  mov c, 0
  push bl
  call putchar
  add sp, 1
; --- END FUNCTION CALL
  jmp _while45_cond
_while45_exit:
  leave
  ret

putchar:
  enter 0 ; (push bp; mov bp, sp)
; --- BEGIN INLINE ASM SEGMENT
  lea d, [bp + 5] ; $c
  mov al, [d]
  mov ah, al
  mov al, 0
  syscall sys_io      ; char in AH
; --- END INLINE ASM SEGMENT
  leave
  ret

print_unsigned_long:
  enter 0 ; (push bp; mov bp, sp)
; char digits[10]; 
  sub sp, 10
; int i = 0; 
  sub sp, 2
; --- START LOCAL VAR INITIALIZATION
  lea d, [bp + -11] ; $i
  push d
  mov32 cb, $00000000
  pop d
  mov [d], b
; --- END LOCAL VAR INITIALIZATION
; if(num == 0){ 
_if46_cond:
  lea d, [bp + 5] ; $num
  mov b, [d + 2] ; Upper Word of the Long Int
  mov c, b ; And place it into C
  mov b, [d] ; Lower Word in B
; --- START RELATIONAL
  push a
  push g
  mov a, b
  mov g, c
  mov32 cb, $00000000
  mov c, 0
  cmp32 ga, cb
  seq ; ==
  pop g
  pop a
; --- END RELATIONAL
  cmp b, 0
  je _if46_exit
_if46_TRUE:
; putchar('0'); 
; --- START FUNCTION CALL
  mov32 cb, $00000030
  push bl
  call putchar
  add sp, 1
; --- END FUNCTION CALL
; return; 
  leave
  ret
  jmp _if46_exit
_if46_exit:
; while (num > 0) { 
_while47_cond:
  lea d, [bp + 5] ; $num
  mov b, [d + 2] ; Upper Word of the Long Int
  mov c, b ; And place it into C
  mov b, [d] ; Lower Word in B
; --- START RELATIONAL
  push a
  push g
  mov a, b
  mov g, c
  mov32 cb, $00000000
  mov c, 0
  cmp32 ga, cb
  sgu
  pop g
  pop a
; --- END RELATIONAL
  cmp b, 0
  je _while47_exit
_while47_block:
; digits[i++] = '0' + (num % 10); 
  lea d, [bp + -9] ; $digits
  push a
  push d
  lea d, [bp + -11] ; $i
  mov b, [d]
  mov c, 0
  mov a, b
  inc b
  lea d, [bp + -11] ; $i
  mov [d], b
  mov b, a
  pop d
  add d, b
  pop a
  push d
  mov32 cb, $00000030
; --- START TERMS
  push a
  mov a, b
  lea d, [bp + 5] ; $num
  mov b, [d + 2] ; Upper Word of the Long Int
  mov c, b ; And place it into C
  mov b, [d] ; Lower Word in B
; --- START FACTORS
  push a
  push g
  mov a, b
  mov g, c
  mov32 cb, $0000000a
  push g ; save 'g' as the div instruction uses it
  div a, b ; %, a: quotient, b: remainder
  mov a, b
  pop g
  mov c, g
  mov b, a
  pop g
  pop a
; --- END FACTORS
  mov g, 0
  add32 cb, ga
  pop a
; --- END TERMS
  pop d
  mov [d], bl
; num = num / 10; 
  lea d, [bp + 5] ; $num
  push d
  lea d, [bp + 5] ; $num
  mov b, [d + 2] ; Upper Word of the Long Int
  mov c, b ; And place it into C
  mov b, [d] ; Lower Word in B
; --- START FACTORS
  push a
  push g
  mov a, b
  mov g, c
  mov32 cb, $0000000a
  push g ; save 'g' as the div instruction uses it
  div a, b ; /, a: quotient, b: remainder
  pop g
  mov c, g
  mov b, a
  pop g
  pop a
; --- END FACTORS
  pop d
  mov [d], b
  mov b, c
  mov [d + 2], b
  jmp _while47_cond
_while47_exit:
; while (i > 0) { 
_while54_cond:
  lea d, [bp + -11] ; $i
  mov b, [d]
  mov c, 0
; --- START RELATIONAL
  push a
  mov a, b
  mov32 cb, $00000000
  cmp a, b
  sgt ; >
  pop a
; --- END RELATIONAL
  cmp b, 0
  je _while54_exit
_while54_block:
; putchar(digits[--i]); 
; --- START FUNCTION CALL
  lea d, [bp + -9] ; $digits
  push a
  push d
  lea d, [bp + -11] ; $i
  mov b, [d]
  dec b
  lea d, [bp + -11] ; $i
  mov [d], b
  pop d
  add d, b
  pop a
  mov bl, [d]
  mov bh, 0
  mov c, 0
  push bl
  call putchar
  add sp, 1
; --- END FUNCTION CALL
  jmp _while54_cond
_while54_exit:
  leave
  ret

printx32:
  enter 0 ; (push bp; mov bp, sp)
; --- BEGIN INLINE ASM SEGMENT
  lea d, [bp + 5] ; $hex
  mov b, [d+2]
  call print_u16x_printx32
  mov b, [d]
  call print_u16x_printx32
; --- END INLINE ASM SEGMENT
; return; 
  leave
  ret
; --- BEGIN INLINE ASM SEGMENT
print_u16x_printx32:
  push a
  push b
  push bl
  mov bl, bh
  call _itoa_printx32        ; convert bh to char in A
  mov bl, al        ; save al
  mov al, 0
  syscall sys_io        ; display AH
  mov ah, bl        ; retrieve al
  mov al, 0
  syscall sys_io        ; display AL
  pop bl
  call _itoa_printx32        ; convert bh to char in A
  mov bl, al        ; save al
  mov al, 0
  syscall sys_io        ; display AH
  mov ah, bl        ; retrieve al
  mov al, 0
  syscall sys_io        ; display AL
  pop b
  pop a
  ret
_itoa_printx32:
  push d
  push b
  mov bh, 0
  shr bl, 4  
  mov d, b
  mov al, [d + s_hex_digits_printx32]
  mov ah, al
  pop b
  push b
  mov bh, 0
  and bl, $0F
  mov d, b
  mov al, [d + s_hex_digits_printx32]
  pop b
  pop d
  ret
s_hex_digits_printx32: .db "0123456789ABCDEF"  
; --- END INLINE ASM SEGMENT
  leave
  ret

err:
  enter 0 ; (push bp; mov bp, sp)
; print(e); 
; --- START FUNCTION CALL
  lea d, [bp + 5] ; $e
  mov b, [d]
  mov c, 0
  swp b
  push b
  call print
  add sp, 2
; --- END FUNCTION CALL
  leave
  ret

print:
  enter 0 ; (push bp; mov bp, sp)
; --- BEGIN INLINE ASM SEGMENT
  lea d, [bp + 5] ; $s
  mov d, [d]
_puts_L1_print:
  mov al, [d]
  cmp al, 0
  jz _puts_END_print
  mov ah, al
  mov al, 0
  syscall sys_io
  inc d
  jmp _puts_L1_print
_puts_END_print:
; --- END INLINE ASM SEGMENT
  leave
  ret

print_signed:
  enter 0 ; (push bp; mov bp, sp)
; char digits[5];  // enough for "-32768" 
  sub sp, 5
; int i = 0; 
  sub sp, 2
; --- START LOCAL VAR INITIALIZATION
  lea d, [bp + -6] ; $i
  push d
  mov32 cb, $00000000
  pop d
  mov [d], b
; --- END LOCAL VAR INITIALIZATION
; unsigned int absval; 
  sub sp, 2
; if (num < 0) { 
_if55_cond:
  lea d, [bp + 5] ; $num
  mov b, [d]
  mov c, 0
; --- START RELATIONAL
  push a
  mov a, b
  mov32 cb, $00000000
  cmp a, b
  slt ; < (signed)
  pop a
; --- END RELATIONAL
  cmp b, 0
  je _if55_else
_if55_TRUE:
; putchar('-'); 
; --- START FUNCTION CALL
  mov32 cb, $0000002d
  push bl
  call putchar
  add sp, 1
; --- END FUNCTION CALL
; absval = (unsigned int)(-(num + 1)) + 1;  // safe for -32768 
  lea d, [bp + -8] ; $absval
  push d
  lea d, [bp + 5] ; $num
  mov b, [d]
  mov c, 0
; --- START TERMS
  push a
  mov a, b
  mov32 cb, $00000001
  add b, a
  pop a
; --- END TERMS
  neg b
; --- START TERMS
  push a
  mov a, b
  mov32 cb, $00000001
  add b, a
  pop a
; --- END TERMS
  pop d
  mov [d], b
  jmp _if55_exit
_if55_else:
; absval = (unsigned int)num; 
  lea d, [bp + -8] ; $absval
  push d
  lea d, [bp + 5] ; $num
  mov b, [d]
  mov c, 0
  pop d
  mov [d], b
_if55_exit:
; if (absval == 0) { 
_if56_cond:
  lea d, [bp + -8] ; $absval
  mov b, [d]
  mov c, 0
; --- START RELATIONAL
  push a
  mov a, b
  mov32 cb, $00000000
  cmp a, b
  seq ; ==
  pop a
; --- END RELATIONAL
  cmp b, 0
  je _if56_exit
_if56_TRUE:
; putchar('0'); 
; --- START FUNCTION CALL
  mov32 cb, $00000030
  push bl
  call putchar
  add sp, 1
; --- END FUNCTION CALL
; return; 
  leave
  ret
  jmp _if56_exit
_if56_exit:
; while (absval > 0) { 
_while57_cond:
  lea d, [bp + -8] ; $absval
  mov b, [d]
  mov c, 0
; --- START RELATIONAL
  push a
  mov a, b
  mov32 cb, $00000000
  cmp a, b
  sgu ; > (unsigned)
  pop a
; --- END RELATIONAL
  cmp b, 0
  je _while57_exit
_while57_block:
; digits[i++] = '0' + (absval % 10); 
  lea d, [bp + -4] ; $digits
  push a
  push d
  lea d, [bp + -6] ; $i
  mov b, [d]
  mov c, 0
  mov a, b
  inc b
  lea d, [bp + -6] ; $i
  mov [d], b
  mov b, a
  pop d
  add d, b
  pop a
  push d
  mov32 cb, $00000030
; --- START TERMS
  push a
  mov a, b
  lea d, [bp + -8] ; $absval
  mov b, [d]
  mov c, 0
; --- START FACTORS
  push a
  push g
  mov a, b
  mov g, c
  mov32 cb, $0000000a
  push g ; save 'g' as the div instruction uses it
  div a, b ; %, a: quotient, b: remainder
  mov a, b
  pop g
  mov c, g
  mov b, a
  pop g
  pop a
; --- END FACTORS
  add b, a
  pop a
; --- END TERMS
  pop d
  mov [d], bl
; absval = absval / 10; 
  lea d, [bp + -8] ; $absval
  push d
  lea d, [bp + -8] ; $absval
  mov b, [d]
  mov c, 0
; --- START FACTORS
  push a
  push g
  mov a, b
  mov g, c
  mov32 cb, $0000000a
  push g ; save 'g' as the div instruction uses it
  div a, b ; /, a: quotient, b: remainder
  pop g
  mov c, g
  mov b, a
  pop g
  pop a
; --- END FACTORS
  pop d
  mov [d], b
  jmp _while57_cond
_while57_exit:
; while (i > 0) { 
_while64_cond:
  lea d, [bp + -6] ; $i
  mov b, [d]
  mov c, 0
; --- START RELATIONAL
  push a
  mov a, b
  mov32 cb, $00000000
  cmp a, b
  sgt ; >
  pop a
; --- END RELATIONAL
  cmp b, 0
  je _while64_exit
_while64_block:
; putchar(digits[--i]); 
; --- START FUNCTION CALL
  lea d, [bp + -4] ; $digits
  push a
  push d
  lea d, [bp + -6] ; $i
  mov b, [d]
  dec b
  lea d, [bp + -6] ; $i
  mov [d], b
  pop d
  add d, b
  pop a
  mov bl, [d]
  mov bh, 0
  mov c, 0
  push bl
  call putchar
  add sp, 1
; --- END FUNCTION CALL
  jmp _while64_cond
_while64_exit:
  leave
  ret

print_unsigned:
  enter 0 ; (push bp; mov bp, sp)
; char digits[5]; 
  sub sp, 5
; int i = 0; 
  sub sp, 2
; --- START LOCAL VAR INITIALIZATION
  lea d, [bp + -6] ; $i
  push d
  mov32 cb, $00000000
  pop d
  mov [d], b
; --- END LOCAL VAR INITIALIZATION
; if(num == 0){ 
_if65_cond:
  lea d, [bp + 5] ; $num
  mov b, [d]
  mov c, 0
; --- START RELATIONAL
  push a
  mov a, b
  mov32 cb, $00000000
  cmp a, b
  seq ; ==
  pop a
; --- END RELATIONAL
  cmp b, 0
  je _if65_exit
_if65_TRUE:
; putchar('0'); 
; --- START FUNCTION CALL
  mov32 cb, $00000030
  push bl
  call putchar
  add sp, 1
; --- END FUNCTION CALL
; return; 
  leave
  ret
  jmp _if65_exit
_if65_exit:
; while (num > 0) { 
_while66_cond:
  lea d, [bp + 5] ; $num
  mov b, [d]
  mov c, 0
; --- START RELATIONAL
  push a
  mov a, b
  mov32 cb, $00000000
  cmp a, b
  sgu ; > (unsigned)
  pop a
; --- END RELATIONAL
  cmp b, 0
  je _while66_exit
_while66_block:
; digits[i++] = '0' + (num % 10); 
  lea d, [bp + -4] ; $digits
  push a
  push d
  lea d, [bp + -6] ; $i
  mov b, [d]
  mov c, 0
  mov a, b
  inc b
  lea d, [bp + -6] ; $i
  mov [d], b
  mov b, a
  pop d
  add d, b
  pop a
  push d
  mov32 cb, $00000030
; --- START TERMS
  push a
  mov a, b
  lea d, [bp + 5] ; $num
  mov b, [d]
  mov c, 0
; --- START FACTORS
  push a
  push g
  mov a, b
  mov g, c
  mov32 cb, $0000000a
  push g ; save 'g' as the div instruction uses it
  div a, b ; %, a: quotient, b: remainder
  mov a, b
  pop g
  mov c, g
  mov b, a
  pop g
  pop a
; --- END FACTORS
  add b, a
  pop a
; --- END TERMS
  pop d
  mov [d], bl
; num = num / 10; 
  lea d, [bp + 5] ; $num
  push d
  lea d, [bp + 5] ; $num
  mov b, [d]
  mov c, 0
; --- START FACTORS
  push a
  push g
  mov a, b
  mov g, c
  mov32 cb, $0000000a
  push g ; save 'g' as the div instruction uses it
  div a, b ; /, a: quotient, b: remainder
  pop g
  mov c, g
  mov b, a
  pop g
  pop a
; --- END FACTORS
  pop d
  mov [d], b
  jmp _while66_cond
_while66_exit:
; while (i > 0) { 
_while73_cond:
  lea d, [bp + -6] ; $i
  mov b, [d]
  mov c, 0
; --- START RELATIONAL
  push a
  mov a, b
  mov32 cb, $00000000
  cmp a, b
  sgt ; >
  pop a
; --- END RELATIONAL
  cmp b, 0
  je _while73_exit
_while73_block:
; putchar(digits[--i]); 
; --- START FUNCTION CALL
  lea d, [bp + -4] ; $digits
  push a
  push d
  lea d, [bp + -6] ; $i
  mov b, [d]
  dec b
  lea d, [bp + -6] ; $i
  mov [d], b
  pop d
  add d, b
  pop a
  mov bl, [d]
  mov bh, 0
  mov c, 0
  push bl
  call putchar
  add sp, 1
; --- END FUNCTION CALL
  jmp _while73_cond
_while73_exit:
  leave
  ret

printx16:
  enter 0 ; (push bp; mov bp, sp)
; --- BEGIN INLINE ASM SEGMENT
  lea d, [bp + 5] ; $hex
  mov b, [d]
print_u16x_printx16:
  push bl
  mov bl, bh
  call _itoa_printx16        ; convert bh to char in A
  mov bl, al        ; save al
  mov al, 0
  syscall sys_io        ; display AH
  mov ah, bl        ; retrieve al
  mov al, 0
  syscall sys_io        ; display AL
  pop bl
  call _itoa_printx16        ; convert bh to char in A
  mov bl, al        ; save al
  mov al, 0
  syscall sys_io        ; display AH
  mov ah, bl        ; retrieve al
  mov al, 0
  syscall sys_io        ; display AL
; --- END INLINE ASM SEGMENT
; return; 
  leave
  ret
; --- BEGIN INLINE ASM SEGMENT
_itoa_printx16:
  push d
  push b
  mov bh, 0
  shr bl, 4  
  mov d, b
  mov al, [d + s_hex_digits_printx16]
  mov ah, al
  pop b
  push b
  mov bh, 0
  and bl, $0F
  mov d, b
  mov al, [d + s_hex_digits_printx16]
  pop b
  pop d
  ret
s_hex_digits_printx16:    .db "0123456789ABCDEF"  
; --- END INLINE ASM SEGMENT
  leave
  ret
; --- END TEXT SEGMENT

; --- BEGIN DATA SEGMENT
_expected_data: .dw $0007,$000b,$0011,$0019,$0023,$002f,$003d,$004d,$005f,$000f,

.fill 20, 0
_s0: .db "=== Compiler Self-Test ===\n", 0
_s1: .db "\n*** ALL TESTS PASSED ***\n", 0
_s2: .db "\n*** TEST FAILED ***\n", 0
_s3: .db "Array mismatch at %d: got %d expected %d\n", 0
_s4: .db "Factorial failed: got %d expected 720\n", 0
_s5: .db "Struct check failed: (%d,%d)\n", 0
_s6: .db "Pointer check failed: *p=%d *(p+5)=%d\n", 0
_s7: .db "Unexpected format in printf.", 0
_s8: .db "Error: Unknown argument type.\n", 0

_heap_top: .dw _heap
_heap: .db 0
; --- END DATA SEGMENT

.end
