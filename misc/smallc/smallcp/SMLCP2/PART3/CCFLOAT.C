#include <stdio.h>
#include "ccfloat.h"
#asm
;
;	name...
;		float
;
;	purpose...
;		floating point routines for C programs
;
;	note...
;		stripped down version for compiler
;
EXTRA:	DEFS	6
FA:	DEFS	6	;floating point accumulator
FASIGN:	DEFS	1	;msb indicates sign of FA
;			0 => negative, 1 => positive
;
;
DIVZERO: CALL	GRIPE
	DEFB	'can''t /0',0
OFLOW:	CALL	GRIPE
	DEFB	'Arithmetic overflow',0
GRIPE:	CALL	QERR	;top word on stack points to message
	JP	0	;error was fatal
;
;
DLOAD:	LD	DE,FA
	LD	BC,6
	LDIR
	RET
;
;	load FA from (HL) and push FA
DLDPSH:
	LD	DE,FA
	LD	BC,6
	LDIR
;
;	push the floating point accumulator
;	(preserving return address)
;
DPUSH:	POP	DE
	LD	HL,(FA+4)
	PUSH	HL
	LD	HL,(FA+2)
	PUSH	HL
	LD	HL,(FA)
	PUSH	HL
	EX	DE,HL
	JP	(HL)
;
;	convert the integer in hl to
;	a floating point number in FA
;
QFLOAT:	LD	A,H	;fetch MSB
	CPL		;reverse sign bit
	LD	(FASIGN),A ;save sign (msb)
	RLA		;move sign into cy
	JR	C,FL4	;c => nonnegative number
	EX	DE,HL
	SBC	HL,HL	;clear hl
	SBC	HL,DE	;get positive number into hl
FL4:	LD	A,L
	DEFB	0DDH
	LD	H,A	;move LSB to hx
	LD	C,H	;move MSB to c
	LD	DE,0	;clear rest of registers
	LD	B,D
	DEFB	0DDH
	LD	L,D	;clear lx
	LD	A,16+128
	LD	(FA+5),A ;preset exponent
	JP	NORM	;go normalize c ix de b
;
;
;	subtract the floating point accumulator from the value
;	on the stack (under the return address), leave result
;	in the floating point accumulator.
;
DSUB:	CALL	MINUSFA
;
;	add the value on the stack (under the return address)
;	to the floating point accumulator
;
DADD:	POP	HL	;save return address
	POP	DE
	POP	IX
	POP	BC
	PUSH	HL	;replace return address
;
;	add bc ix de to floating point accumulator
;
FADD:	LD	A,B
	OR	A
	RET	Z	;z => number to be added is zero
	LD	A,(FA+5)
	OR	A
	JP	Z,LDFABC ;z => accumulator is zero,
;				just load number
	SUB	B
	JR	NC,ADD2 ;nc => accumulator has larger number
	NEG		;reverse accumulator & bc ix de...
	EXX
	PUSH	IX
	CALL	LDBCFA
	EXX
	EX	(SP),IX
	CALL	LDFABC
	EXX
	POP	IX	;...end of reversing
ADD2:	CP	29H
	RET	NC	;nc => addition makes no change
	PUSH	AF	;save difference of exponents
	CALL	UNPACK	;restore hidden bit & compare signs
	LD	H,A	;save difference in signs
	POP	AF	;recall difference of exponents
	CALL	RSHIFT	;shift  c ix de b  right by (a)
	OR	H
	LD	HL,FA
	JP	P,ADD4	;p => opposite signs, must subtract
	CALL	FRADD	;c ix de += FA
	JR	NC,PACK	;nc => adding caused no carry
	INC	HL
	INC	(HL)	;increment exponent
	JP	Z,OFLOW
	LD	L,1
	CALL	RSH8	;shift  c ix de b  right by 1
	JR	PACK	;round, hide msb, & load into FA
;
ADD4:	XOR	A	;negate b...
	SUB	B
	LD	B,A
	LD	A,(HL)	;c ix de -= FA...
	SBC	A,E
	LD	E,A
	INC	HL
	LD	A,(HL)
	SBC	A,D
	LD	D,A
	INC	HL
	LD	A,(HL)
	DEFB	0DDH
	SBC	A,L
	DEFB	0DDH
	LD	L,A
	INC	HL
	LD	A,(HL)
	DEFB	0DDH
	SBC	A,H
	DEFB	0DDH
	LD	H,A
	INC	HL
	LD	A,(HL)
	SBC	A,C
	LD	C,A	;...end of subtraction, fall into...
;
;	reverse sign if necessary (cy set) and normalize
;	(sign reversal necessary because we're using
;	sign-magnitude representation rather than
;	twos-complement)
;
NORMA:	CALL	C,MINUSBC
;
;	normalize the 48 bit number in c ix de b
;	current exponent is in FA+5
;
;	result loaded into FA
;
NORM:	LD	L,B
	LD	H,E
	XOR	A
NORM2:	LD	B,A
	LD	A,C
	OR	A
	JR	NZ,NORM12  ;nz => 7 or fewer shifts needed
;			shift c ix d hl  left by one byte
	DEFB	0DDH
	LD	C,H
	DEFB	0DDH
	LD	A,L
	DEFB	0DDH
	LD	H,A
	DEFB	0DDH
	LD	L,D
	XOR	A
	LD	D,H
	LD	H,L
	LD	L,A	;...end of shifting
;
	LD	A,B
	SUB	8	;adjust exponent
	CP	0D0H
	JR	NZ,NORM2
;
NORM4:	XOR	A
NORM6:	LD	(FA+5),A
	RET
;
NORM8:	DEC	B
;			shift  c ix d hl  left one bit...
	ADD	HL,HL
	RL	D
	EX	AF,AF'
	ADD	IX,IX
	EX	AF,AF'
	JR	NC,NORM10
	INC	IX
NORM10:	EX	AF,AF'
	RL	C	;...end of shifting
;
NORM12:	JP	P,NORM8	;p => high order bit still zero
	LD	A,B
;			move number to  c ix de b
	LD	E,H
	LD	B,L
	OR	A
	JR	Z,PACK	;z => exponent unchanged
	LD	HL,FA+5		;update exponent
	ADD	A,(HL)
	LD	(HL),A
	JR	NC,NORM4	;nc => underflow (set to 0)
	RET	Z		;z => underflow (leave as 0)
;
PACK:	LD	A,B
PACK2:	LD	HL,FA+5	;round c ix de b to 40 bits
	OR	A
	CALL	M,INCR
	LD	B,(HL)	;load exponent
	INC	HL
	LD	A,(HL)	;recover sign
	AND	80H	;mask out all but sign
	XOR	C	;add to high
	LD	C,A	;   order byte
	JP	LDFABC	;place answer in FA
;
INCR:	INC	E	;increment c ix de
	RET	NZ
	INC	D
	RET	NZ
	DEFB	0DDH
	INC	L
	RET	NZ
	DEFB	0DDH
	INC	H
	RET	NZ
	INC	C
	RET	NZ	;z => carry
	LD	C,80H	;set high order bit
	INC	(HL)	;   and increment exponent
	RET	NZ
	JP	OFLOW
;
;	fraction add: c ix de += (hl)
;
FRADD:	LD	A,(HL)
	ADD	A,E
	LD	E,A
	INC	HL
	LD	A,(HL)
	ADC	A,D
	LD	D,A
	INC	HL
	LD	A,(HL)
	DEFB	0DDH
	ADC	A,L
	DEFB	0DDH
	LD	L,A
	INC	HL
	LD	A,(HL)
	DEFB	0DDH
	ADC	A,H
	DEFB	0DDH
	LD	H,A
	INC	HL
	LD	A,(HL)
	ADC	A,C
	LD	C,A
	RET
;
;	complement FASIGN and negate the fraction c ix de b
;
MINUSBC: LD	HL,FASIGN
	LD	A,(HL)
	CPL
	LD	(HL),A
	XOR	A
	LD	L,A
	LD	H,A
	SUB	B
	LD	B,A
	LD	A,L
	SBC	HL,DE
	EX	DE,HL
	LD	L,A
	DEFB	0DDH
	SBC	A,L
	DEFB	0DDH
	LD	L,A
	LD	A,L
	DEFB	0DDH
	SBC	A,H
	DEFB	0DDH
	LD	H,A
	LD	A,L
	SBC	A,C
	LD	C,A
	RET
;
;	shift  c ix de b  right by (a)
;
RSHIFT:	LD	B,0
RSH2:	SUB	8
	JR	C,RSH4	;c => 7 or fewer shifts remain
	LD	B,E	;shift  c ix de b  right by 8...
	LD	E,D
	DEFB	0DDH
	LD	D,L
	EX	AF,AF'
	DEFB	0DDH
	LD	A,H
	DEFB	0DDH
	LD	L,A
	EX	AF,AF'
	DEFB	0DDH
	LD	H,C
	LD	C,0	;...end of shifting
	JR	RSH2
;
RSH4:	ADD	A,9
	LD	L,A
RSH6:	XOR	A
	DEC	L
	RET	Z	;z => requested shift is complete
	LD	A,C
RSH8:	RRA		;shift  c ix de b  right by one...
	LD	C,A
	DEFB	0DDH
	LD	A,H
	RRA
	DEFB	0DDH
	LD	H,A
	DEFB	0DDH
	LD	A,L
	RRA
	DEFB	0DDH
	LD	L,A
	RR	D
	RR	E
	RR	B	;...end of shifting
	JR	RSH6
;
;	multiply the floating point accumulator by the value
;	on the stack (under the return address), leave result
;	in the floating point accumulator.
;
DMUL:	POP	HL	;return addr
	POP	DE	;multiplier...
	POP	IX
	POP	BC
	PUSH	HL	;replace return addr
;
;	multiply floating point accumulator by  bc ix de
;
FMUL:	CALL	SGN
	RET	Z	; z => accumulator has zero
	LD	L,0	;"product" flag
	CALL	DIV14	;find exponent of product
	LD	A,C  ;c' h'l' d'e' (multiplicand) = c ix de...
	PUSH	DE
	EXX
	LD	C,A
	POP	DE
	PUSH	IX
	POP	HL
	EXX		;...end of multiplicand loading
	LD	BC,0	; c ix de b (product) = 0...
	LD	D,B
	LD	E,B
	LD	IX,0
	LD	HL,NORM	; push addr of normalize routine
	PUSH	HL
	LD	HL,MULLOOP	; push addr of top of loop
	PUSH	HL	; (5 iterations wanted,
	PUSH	HL	; once per byte of fraction)
	PUSH	HL
	PUSH	HL
	LD	HL,FA	;point to LSB
MULLOOP: LD	A,(HL)	;get next byte of multiplier
	INC	HL
	OR	A
	JR	NZ,MUL2	; z => next 8 bits of multiplier are 0
	LD	B,E	;shift  c ix de b  right by 8...
	LD	E,D
	DEFB	0DDH
	LD	D,L
	EX	AF,AF'
	DEFB	0DDH
	LD	A,H
	DEFB	0DDH
	LD	L,A
	EX	AF,AF'
	DEFB	0DDH
	LD	H,C
	LD	C,A	;...end of shifting
	RET		;go to top of loop or NORM
;
MUL2:	PUSH	HL	;save multiplier pointer
	EX	DE,HL
	LD	E,8	;8 iterations (once per bit)
MUL4:	RRA		;rotate a multiplier bit into cy
	LD	D,A
	LD	A,C
	JR	NC,MUL6	; nc => no addition needed
	PUSH	HL	; c ix hl (product)  +=
	EXX		;	c' h'l' d'e' (multiplicand)
	EX	(SP),HL
	ADD	HL,DE
	EX	(SP),HL
	EX	DE,HL
	PUSH	IX
	EX	(SP),HL
	ADC	HL,DE
	EX	(SP),HL
	POP	IX
	EX	DE,HL
	ADC	A,C
	EXX
	POP	HL
;
MUL6:	RRA	   ;shift  c ix hl b (product)  right by 1...
	LD	C,A
	DEFB	0DDH
	LD	A,H
	RRA
	DEFB	0DDH
	LD	H,A
	DEFB	0DDH
	LD	A,L
	RRA
	DEFB	0DDH
	LD	L,A
	RR	H
	RR	L
	RR	B		;...end of shifting
	DEC	E
	LD	A,D
	JR	NZ,MUL4		; z => 8 iterations complete
	EX	DE,HL
MUL8:	POP	HL		;recover multiplier pointer
	RET			;go to top of loop or NORM
;
;	divide the value on the stack (under the return
;	address) by the floating point accumulator, leave
;	result in the floating point accumulator.
;
DDIV:	POP	HL	;save return address
	POP	DE
	POP	IX
	POP	BC
	PUSH	HL	;replace return address
;
;	divide  bc ix de  by FA, leave result in FA
;
FDIV:	CALL	SGN
	JP	Z,DIVZERO ; z => attempting to divide by 0
	LD	L,0FFH	;"quotient" flag
	CALL	DIV14	;find quotient exponent
	PUSH	IY
	INC	(HL)
	INC	(HL)
	DEC	HL
	PUSH	HL	; c' h'l' d'e' (divisor) = FA...
	EXX
	POP	HL
	LD	C,(HL)
	DEC	HL
	LD	D,(HL)
	DEC	HL
	LD	E,(HL)
	DEC	HL
	LD	A,(HL)
	DEC	HL
	LD	L,(HL)
	LD	H,A
	EX	DE,HL
	EXX
	LD	B,C	; b iy hl (dividend) = c ix de...
	EX	DE,HL
	PUSH	IX
	POP	IY
	XOR	A	; c ix de (quotient) = 0...
	LD	C,A
	LD	D,A
	LD	E,A
	LD	IX,0
	LD	(EXTRA),A
DIV2:	PUSH	HL	;save b iy hl in case the subtraction
	PUSH	IY	; proves to be unnecessary
	PUSH	BC
	PUSH	HL	; EXTRA b iy hl (dividend)  -=
	LD	A,B	;	c' h'l' d'e' (divisor)...
	EXX
	EX	(SP),HL
	OR	A
	SBC	HL,DE
	EX	(SP),HL
	EX	DE,HL
	PUSH	IY
	EX	(SP),HL
	SBC	HL,DE
	EX	(SP),HL
	POP	IY
	EX	DE,HL
	SBC	A,C
	EXX
	POP	HL
	LD	B,A
	LD	A,(EXTRA)
	SBC	A,0
	CCF
	JR	NC,DIV4	; nc => subtraction caused carry
	LD	(EXTRA),A
	POP	AF	;discard saved value of dividend...
	POP	AF
	POP	AF
	SCF
	JR	DIV6
DIV4:	POP	BC	;restore dividend...
	POP	IY
	POP	HL
;
DIV6:	INC	C
	DEC	C
	RRA
	JP	M,DIV12
	RLA	  ;shift  c ix de a (quotient)  left by 1...
	RL	E
	RL	D
	EX	AF,AF'	;(these 6 lines are  adc ix,ix...)
	ADD	IX,IX
	EX	AF,AF'
	JR	NC,DIV8
	INC	IX
DIV8:	EX	AF,AF'
	RL	C	;...end of  c ix de a  shifting
	ADD	HL,HL	;shift  EXTRA b iy hl  left by 1...
	EX	AF,AF'
	ADD	IY,IY
	EX	AF,AF'
	JR	NC,DIV9
	INC	IY
DIV9:	EX	AF,AF'
	RL	B
	LD	A,(EXTRA)
	RLA
	LD	(EXTRA),A  ;...end of  EXTRA b iy hl  shifting
	LD	A,C	;test  c ix de...
	OR	D
	OR	E
	DEFB	0DDH
	OR	H
	DEFB	0DDH
	OR	L	;...end of  c ix de  testing
	JR	NZ,DIV2	;nz => dividend nonzero
	PUSH	HL
	LD	HL,FA+5
	DEC	(HL)
	POP	HL
	JR	NZ,DIV2
	JR	OFLOW2
;
DIV12:	POP	IY
	JP	PACK2
;
;	find exponent for product (L=0) or quotient (L=ff)
;
DIV14:	LD	A,B
	OR	A
	JR	Z,DIV20
	LD	A,L	;get product/quotient flag
	LD	HL,FA+5
	XOR	(HL)	;get +-FA exponent
	ADD	A,B	;find and...
	LD	B,A	;...load new exponent
	RRA
	XOR	B
	LD	A,B
	JP	P,DIV18
	ADD	A,80H
	LD	(HL),A
	JP	Z,MUL8
	CALL	UNPACK	;restore hidden bits & compare signs
	LD	(HL),A	;save difference of signs
	DEC	HL	;point to MSB of fraction
	RET
;
DIV17:	CALL	SGN
	CPL
	OR	A
	DEFB	21H	;"ignore next 2 bytes"
DIV18:	OR	A
DIV20:	POP	HL
	JP	P,NORM4
OFLOW2:	JP	OFLOW
;
;
;	set z & s flags per FA
;
SGN:	LD	A,(FA+5)
	OR	A
	RET	Z
	LD	A,(FA+4)
	DEFB	0FEH	;"ignore next byte"
SETFLGS: CPL
	RLA
	SBC	A,A
	RET	NZ
	INC	A
	RET
;
MINUSFA: LD	HL,FA+4
	LD	A,(HL)
	XOR	80H
	LD	(HL),A
	RET
;
;	FA = bc ix de
;
LDFABC:	LD	(FA),DE
	LD	(FA+2),IX
	LD	(FA+4),BC
	RET
;
;	bc ix de = FA
;
LDBCFA:	LD	DE,(FA)
	LD	IX,(FA+2)
	LD	BC,(FA+4)
	RET
;
;	(hl) = FA
;
DSTORE:	LD	DE,FA
	LD	BC,6
	EX	DE,HL
	LDIR
	EX	DE,HL
	RET
;
UNPACK:	LD	HL,FA+4
	LD	A,(HL)	;get MSB of fraction
	RLCA		;rotate sign bit into lsb
	SCF		;set carry
	RRA		;rotate sign bit into cy, cy into msb
	LD	(HL),A	;restore MSB (with hidden bit restored)
	CCF		;complement sign bit...
	RRA
	INC	HL
	INC	HL
	LD	(HL),A	;...and save in msb of FASIGN
	LD	A,C	;similarly, get sign bit of bc ix de...
	RLCA
	SCF
	RRA
	LD	C,A	;...restore hidden bit...
	RRA
	XOR	(HL)	;...and compare with sign of FA.
	RET
;
INT2:	LD	B,A	;if a==0, return with  bc ix de = 0...
	LD	C,A
	LD	D,A
	LD	E,A
	DEFB	0DDH
	LD	H,A
	DEFB	0DDH
	LD	L,A
	OR	A
	RET	Z
	PUSH	HL
	CALL	LDBCFA	;copy FA into bc ix de,
	CALL	UNPACK	; restore hidden bits
	XOR	(HL)
	LD	H,A	;put sign in msb of h
	JP	P,INT4 ;p => positive number
	DEC	DE	;decrement c ix de...
	LD	A,D
	AND	E
	INC	A
	JR	NZ,INT4
	DEC	IX
	DEFB	0DDH
	LD	A,H
	DEFB	0DDH
	AND	L
	INC	A
	JR	NZ,INT4
	DEC	C	;...end of c ix de decrementing
;
INT4:	LD	A,0A8H	;shift  c ix de  right so bits to
	SUB	B	; the right of the binary point
	CALL	RSHIFT	; are discarded
	LD	A,H
	RLA
	CALL	C,INCR	;c => negative, increment  c ix de
	LD	B,0
	CALL	C,MINUSBC ;negate the fraction c ix de
	POP	HL
	RET
;
#endasm
