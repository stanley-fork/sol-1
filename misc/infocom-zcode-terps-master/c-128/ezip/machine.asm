
	PAGE
	STTL "--- MACHINE-DEPENDENT I/O: CBM64 ---"

	; ----------------------------
	; FETCH ASCII KEYCODE INTO [A]
	; ----------------------------

	; EXIT: ASCII IN [A] & [IOCHAR]

GETKEY:	SEC
	JSR	PLOT
	STX	OLDX
	STY	OLDY

	LDA	#$E4
	STA	ULINE
	JSR	CHROUT

	LDX	OLDX
	LDY	OLDY
	CLC
	JSR	PLOT

	LDX	#0
	STX	BLINK+LO	; RESET THE BLINK COUNTER
	STX	BLINK+HI	; FOR A LONG DELAY

GKEY1:	INC	BLINK+LO	; TIME TO BLINK YET?
	BNE	NOBLIN		; NOT TILL BLINK TIMERS
	INC	BLINK+HI	; EQUAL $400
	LDA	BLINK+HI
	CMP	#$B
	BNE	NOBLIN
	LDA	#0
	STA	BLINK+HI	; FOR NEXT ROUND

	LDA	ULINE
	EOR	#$C4		; MAKE _ OR BLANK, SO "BLINKS"
	STA	ULINE
	JSR	CHROUT

	LDX	OLDX
	LDY	OLDY
	CLC
	JSR	PLOT

NOBLIN:	JSR	GETIN		; GET A KEY
	TAY			; ANYTHING ENTERED?
	BEQ	GKEY1		; NOT YET

	; CONVERT & MASK KEYCODE IN [A]

GOTKEY:	; ENTRY POINT FROM INPUT

	CMP	#'A'		; CONVERT UNSHIFTED ALPHA
	BCC	MASK		; TO ASCII LOWER CASE
	CMP	#'Z'+1
	BCS	MASK
	ADC	#$20

	;CHECK FOR "ARROWS", CONVERT FOR USE (EZIP)
	;ALSO : CHANGE < > TO , .

MASK:	LDX	#ENDKEY		; GET LENGTH OF LIST
MASK0:	CMP	HAVE,X		; CHECK AGAINST LIST OF UNWANTED KEYS
	BEQ	MASK1		; FOUND IT
	DEX
	BPL	MASK0		; CHECK THEM ALL
	BMI	MASK2		; NOT FOUND, CONTINUE OTHER CHECKS
MASK1:	LDA	WANT,X		; GET KEY TO USE INSTEAD
	BNE	TICK		; JMP

MASK2:	AND	#%01111111	; SCREEN OUT SHIFTS

	CMP	#EOL		; EOL?
	BEQ	TICK
	CMP	#BACKSP
	BEQ	TICK
	CMP	#SPACE		; ANYTHING ELSE < "SPACE"
	BCC	BADKEY		; IS BAD

	LDX	#BLISTL		; IGNORE OBSTINATE NON ALLOWED KEYS
BADL:	CMP	BADLIST,X
	BEQ	BADKEY
	DEX
	BNE	BADL

	CMP	#'z'+1		; PASS L-C ALPHA
	BCS	BADKEY
	CMP	#'a'
	BCS	TICK

	CMP	#'Z'+1		; PASS U-C ALPHA
	BCC	TICK		; AND OTHER ASCII CHARS

BADKEY:	JSR	BOOP		; REJECT BAD KEYPRESS
	JMP	GETKEY		; AND TRY AGAIN

TICK:	STA	IOCHAR		; HOLD ON TO IT
	LDA	#SPACE
	JSR	CHROUT		; ERASE CURSOR
	LDX	OLDX
	LDY	OLDY
	CLC
	JSR	PLOT

	ADC	RNUM1		; FUTZ WITH RANDOM
	STA	RNUM1
	EOR	RNUM2
	STA	RNUM2
	LDA	IOCHAR		; GET CHAR INTO [A]
	RTS			; AND RETURN IT

HAVE:	DB	'<','>',$11,$1D,$91,$5E,$9D
WANT:	DB	',','.',13,07,14,14,11
ENDKEY	EQU	$-WANT-1

BADLIST: DB	'%','&','=','@'
BLISTL	EQU	$-BADLIST-1

	; -------------------------
	; OUTPUT AN ASCII CHARACTER
	; -------------------------

LETTER:	CMP	#'a'		; LOWER-CASE?
	BCC	LET0		; NO, CONTINUE
	CMP	#'z'+1
	BCS	LETEX		; CTRL CHARS
	AND	#%01011111	; ELSE MASK FOR LOWER-CASE
	JMP	CHROUT

LET0:	CMP	#'A'		; UPPER-CASE?
	BCC	LETEX
	CMP	#'Z'+1
	BCS	LETEX
	ORA	#%00100000	; MAKE UPPER
LETEX:	JMP	CHROUT


	; -----------------
	; PRINT CHAR IN [A]
	; -----------------

CHAR:	STA	IOCHAR		; SAVE HERE
	TXA			; SAVE [X] AND [Y]
	PHA
	TYA
	PHA

NOSCRL:	LDA	IOCHAR		; RESTORE CHAR
	CMP	#$22
	BNE	NOQUOT
	JSR	LETTER		; QUOTE MARKS SCREW
	LDA	#0		; UP SYSTEM, SO
	STA	QUOTMOD		; TURN OFF QUOTE MODE FLAG
	JMP	CHDUN

NOQUOT:	JSR	LETTER		; OFF TO THE SCREEN!
CHDUN:	PLA			; RESTORE [X] AND [Y]
	TAY
	PLA
	TAX
	RTS


	; ---------------------
	; FETCH A LINE OF INPUT
	; ---------------------

	; ENTRY: ABS ADDR OF READ BUFFER IN [ARG1]
	; EXIT: # CHARS READ IN [A]

INPUT:	JSR	LINOUT	; FLUSH [LBUFF]
	LDA	#0	; RESET LINE COUNT
	STA	LENGTH	
	STA	CHRCNT	
	LDY	TOP	
	STY	LINCNT	; RESET LINE COUNT
	STA	NDX	; CLEAR INPUT QUEUE

	DEC	NARGS	; CHECK IF TIME LIMIT (EZIP)
	DEC	NARGS	
	BEQ	INP2	; NO
	LDA	ARG3+LO	; GET DELAY WANTED
	STA	I+HI	
	LDA	#0	
	STA	J+HI	
	STA	J+LO	
	DEC	NARGS	; IS THERE A FCN?
	BEQ	INP4	; NO
	LDA	ARG4+LO	; YES, SET IT
	STA	J+LO	
	LDA	ARG4+HI	
	STA	J+HI	

INP4:	LDA	I+HI	
	STA	I+LO	; RESET EA TIME THRU

INP0:	LDA	#249	; = 7, TIME COUNTS UP
	STA	TIME
INP1:	LDA	TIME
	BNE	INP1

	JSR	GETIN
	CMP	#0
	BEQ	INP6	; NO KEY YET
	JSR	GOTKEY	; OK, GO DO THE VOODOO
	LDY	#0
	STY	CHARCNT
	JMP	INLP1	; [A] NOW HAS PROPER CODE

INP6:	DEC	I+LO	
	BNE	INP0	; SOME TIME LEFT, TRY AGAIN

	; TIME OUT, CHECK IF THERE IS A FCN TO CALL

	LDA	J+LO	; IS THERE A FCN
	ORA	J+HI	
	BNE	INP3	
	JMP	LEXBAD	; NO FCN, LEAVE WITH NOTHING

INP3:	JSR	INTCLL	; INTERNALLY CALL THE FCN
	LDA	VALUE+LO	; CHECK RESULTS
	BEQ	INP4	; ELSE TRY AGAIN (END EZIP)
	JMP	LEXBAD	; ELSE ABORT

INP2:	LDY	#0	; AND CHAR COUNT
	STY	CHARCNT

INLOOP:	JSR	GETKEY	; GET ASCII INTO [A] AND [IOCHAR]
INLP1:	CMP	#14	
	BEQ	CBAD	; CLEAR OFF ARROWS (EZIP)
	CMP	#11
	BEQ	CBAD
	CMP	#7	
	BEQ	CBAD	
	CMP	#EOL	; EOL?
	BEQ	ENDLIN	; LINE DONE IF SO
	CMP	#BACKSP	; BACKSPACE?
	BEQ	BACKUP	; SPECIAL HANDLING

	LDY	CHARCNT
	STA	LBUFF,Y	; ELSE ADD CHAR TO INPUT BUFFER
	INC	CHARCNT	; NEXT POSITION IN LINE
SHOWIT:	JSR	CHAR	; SEND TO SCREEN
	LDY	CHARCNT
	CPY	#77	; ALL THE CHARS ALLOWED?
	BCC	INLOOP	; NO, GET ANOTHER CHAR

	; HANDLE LINE OVERFLOW

NOMORE:	JSR	GETKEY	
	CMP	#EOL	; IF EOL,
	BEQ	ENDLIN	; WRAP UP THE LINE
	CMP	#BACKSP	; BACKSPACE
	BEQ	BACKUP	; IS OKAY TOO
	JSR	BEEP	; ELSE COMPLAIN
	JMP	NOMORE	; AND INSIST

	; HANDLE BACKSPACE

BACKUP:	DEC	CHARCNT	; BACK UP THE POINTER
	BPL	SHOWIT	; JMP
	LDY	#0	; RESET POINTER
	STY	CHARCNT
CBAD:	JSR	BEEP	; ELSE SCREAM WITH PAIN
	JMP	INLOOP	; AND WAIT FOR SOMETHING BETTER

	; HANDLE END OF LINE

ENDLIN:	LDY	CHARCNT
	STA	LBUFF,Y	; SHIP EOL TO BUFFER
	INY		; UPDATE INDEX
	STY	LINLEN	; SAVE HERE FOR "READ"
	STY	PRLEN	; AND HERE FOR "PPRINT"

	LDX	TOP	; SET TOP SO SCROLLS CORRECTLY
	STX	WTOP
	JSR	CHAR	; AND SEND EOL TO SCREEN
	LDX	#0
	STX	WTOP	; AND SET BACK TO EASY USE

	; MOVE [LBUFF] TO [ARG1] W/LC CONVERSION

LEX0:	LDA	LBUFF-1,Y	; GET A CHAR FROM [LBUFF]
	CMP	#'A'	; IF CHAR IS ALPHA,
	BCC	LEX2	; CONVERT TO LOWER CASE
	CMP	#'Z'+1	
	BCS	LEX2	
	ADC	#$20	
LEX2:	STA	(RDTBL1),Y	; MOVE CHAR TO INPUT BUFFER AT [ARG1]
	DEY		; LOOP TILL
	BNE	LEX0	; ALL CHARS MOVED
	JSR	PPRINT	; SCRIPT [LBUFF] IF ENABLED
	LDA	LINLEN	; RESTORE # CHARS
	RTS		; INTO [A]
LEXBAD:	LDA	#0	; TIME OUT OCCURRED (EZIP)
	RTS		; ZERO CHARS OBTAINED

CHARCNT:	DB	0

; -----------------------
; DIRECT PRINT LINE [X/A]
; -----------------------
; ENTRY: STRING ADDRESS IN [X/A] (LSB/MSB)
; STRING LENGTH IN [Y]

DLINE:	STX	STRING+LO	; DROP STRING ADDRESS
	STA	STRING+HI	; INTO DUMMY BYTES
	STY	J		; COUNTER

	LDA	TOP		; RETAIN STATUS LINE(S)
	STA	WTOP

	LDX	#0		; INIT CHAR-FETCH INDEX
DOUT:	DB	$BD		; 6502 "LDA nnnn,X" OPCODE
STRING:	DW	$0000		; DUMMY OPERAND BYTES
	JSR	CHAR
	INX
	DEC	J		; LOOP TILL
	BNE	DOUT		; OUT OF CHARS

	LDA	#0
	STA	WTOP

	RTS		


	; -----------------------
	; SEND [LBUFF] TO PRINTER
	; -----------------------

	; ENTRY: LENTH OF LINE IN [PRLEN]
	; NOW WITH IMPROVED ERROR PROTECTION! (BM 11/24/84)

PPRINT:	LDA	SCRIPT		; SCRIPTING INTERNALLY ENABLED?
	BEQ	PEX		; NO, SCRAM IMMEDIATELY

	LDA	ZBEGIN+ZSCRIP+1	; CHECK SCRIPT FLAG
	AND	#%00000001	; SCRIPTING ON?
	BEQ	PP3		; NO, CHECK FOR "UNSCRIPT"

	LDA	PSTAT		; CHECK PRINTER STATUS
	BMI	PEX		; CAN'T OPEN IF NEGATIVE
	BNE	PP1		; ALREADY OPEN, SCRIPT THE LINE

	; OPEN THE PRINTER FOR OUTPUT

PP0:	LDX	#1
	STX	PSTAT		; SET STATUS TO "PRINTER OPENED" (1)

	LDA	#4		; LOGICAL FILE #4
	TAX			; DEVICE #4
	LDY	#7		; ALLOW UPPER/LOWER CASE
	JSR	SETLFS		; SET UP LOGICAL FILE
	LDA	#0
	JSR	SETNAM		; NO FILENAME REQUIRED
	JSR	OPEN		; OPEN THE CHANNEL
	BCC	PP1		; OPEN OKAY IF CARRY CLEAR

PPERR:	LDA	#$FF		; ELSE SET PRINTER STATUS
	STA	PSTAT		; TO "CAN'T OPEN"
	BNE	PP5		; AND SIMULATE AN "UNSCRIPT"

PP1:	LDX	#4		; SET PRINTER CHANNEL
	JSR	CHKOUT		; TO "OUTPUT"
	BCS	PPERR		; ERROR IF CARRY SET

	LDY	#0		; INIT INDEX
PP2:	LDA	LBUFF,Y
	CMP	#$0D
	BEQ	PP6
	AND	#%01111111
	CMP	#$20
	BCC	PP4		; NO CONTROLS
PP6:	JSR	LETTER
	BCS	PPERR		; ERROR IF CARRY SET
PP4:	INY
	DEC	PRLEN
	BNE	PP2
	BEQ	PEX		; RESET & RETURN

	; CHECK FOR "UNSCRIPT"

PP3:	LDA	PSTAT		; CHECK PRINTER STATUS
	BEQ	PEX		; EXIT IF PRINTER WAS OFF
	BMI	PEX		; OR UNOPENABLE

PCLOSE:	LDA	#0		; RESET PRINTER STATUS FLAG
	STA	PSTAT		; TO "CLOSED"

	; ENTRY FOR PRINTER ERROR

PP5:	LDA	#4
	JSR	CLOSE		; CLOSE THE PRINTER CHANNEL
PEX:	JMP 	CLRCHN

PSTAT:	DB	0		; HERE SO RESTART WON'T ALTER


	; ------------
	; SPLIT SCREEN
	; ------------

	; SPLIT SCREEN AT LINE [ARG1]
	; DISABLE SPLIT IF [ARG1] = 0
	; IGNORE IF SPLIT ALREADY ENABLED OR [ARG1] >= 23

	; ON C-128, I AM USING KERNAL RTNS TO ACCESS SCREEN MEMORY
	; AS SCREEN MEMORY IS IN ITS OWN WORLD. IN ORDER NOT TO
	; SCROLL THE TOP WINDOW WHEN SCREEN IS SPLIT, THE C-128
	; TOP OF SCREEN INDICATOR MUST BE USED, BUT: NO ACCESS IS
	; ALLOWED ABOVE THAT INDICATOR. THAT INDICATOR (WTOP) WILL
	; THEREFORE BE SET ONLY WHEN SCROLLING MIGHT OCCUR, LEAVING
	; [WTOP] SET TO #0 OTHERWISE. THE SPLIT LINE IS KEPT TRACK
	; OF IN [TOP].

ZSPLIT:	LDA	ZBEGIN+ZMODE	
	AND	#%00100000	;CHECK IF ENABLED (EZIP)
	BEQ	ZSPOUT		;NOT, LEAVE
	LDA	ARG1+LO		;GET # OF LINES FOR SCREEN
	BEQ	NORL		;IF 0 THEN RESTORE SCREEN
	CMP	#24		;IS SPLIT REALLY = WHOLE SCREEN
	BCS	ZSPOUT		;YES, IGNORE

	CMP	TOP		; IF SCREEN 1 SHRINKING
	BCS	ZSLVIT		; SET LINCNT - (TOP - [A])
	PHA			; HOLD IT
	SEC
	SBC	TOP
	ADC	LINCNT
	STA	LINCNT
	PLA

ZSLVIT:	STA	TOP		; SET THE TOP OF THE SECOND SCREEN
	STA	SPSTAT		; NON ZERO = SCREEN IS SPLIT
	CMP	LINCNT		; IS SCROLLING SCREEN NOW MORE THAN LINCNT?
	BCC	ZSPL3		; NO
	STA	LINCNT		; YES, RESET LINCNT
ZSPL3:	LDX	WBOTM
	LDY	LENGTH		; get where y used to be #0
	CLC
	JSR	PLOT		; RESTORE CURSOR AFTER HOME CALL
ZSPOUT:
	RTS

NORL:	;RESTORE SCREEN	TO FULL SCREEN MODE

	LDA	#0		; PUT CURSOR AT TOP OF SCREEN
	STA	WTOP		; RESTORE FULL SCREEN ALIGNMENT
	STA	TOP		; JIC
	STA	LINCNT
	STA	SPSTAT		; FLAG NOT SPLIT
	RTS


; ------
; SCREEN
; ------
; GO TO TOP WINDOW (TOP OF SCREEN) IF [A] = 1
; GO TO BOTTOM OF SCREEN IF [A] = 0
; IGNORE IF SPLIT NOT ENABLED OR [A] <> 0 OR 1
; FLAG SPLITF WILL BE SET FOR OUTPUT TO DETERMINE
; IF AND WHICH WINDOW TO DISPLAY TO
; (0=BOTTOM 1=TOP)

SAVEX:	DB	23	; save spot for current cursor pos
SAVEY:	DB	0

ZSCRN:	LDA	ZBEGIN+ZMODE	
	AND	#%00000001	; CHECK IF ENABLED (EZIP)
	BEQ	ZSPOUT		; NOT, LEAVE
	LDA	SPSTAT		; CHECK IF SCREEN IS SPLIT
	BEQ	ZSPOUT		; NO, SO JUST LEAVE

	LDA	ARG1+LO		; CHECK WHICH WINDOW
	BNE	SCRN1		; TOP SCREEN
	LDA	#$FF		; SCROLLING SCREEN SO
	STA	SCRIPT		; ALLOW SCRIPTING

	LDA	#23		; recreate bottom of screen
	STA	WBOTM		; and save it
	LDA	#0
	STA	SPLITF		; SET FLAG TO SPLIT SCREEN (0)
;	TAY			; PUT CURSOR AT BOTTOM OF SCREEN
;	LDX	WBOTM

	LDY	SAVEY		; get where it used to be
	LDX	SAVEX		; get where it used to be

	JMP	SCRNP		; JMP TO HIGH CRLOW  RTN

SCRN1:	CMP	#01
	BNE	ZSPOUT		; INVALID SCREEN ID

	STA	SPLITF		; SET FLAG TO UNSCROLLING SCREEN (1)

	SEC
	JSR	PLOT		; get where cursor currently resides
	STY	SAVEY		; save the y,
	STX	SAVEX		; x spots

	LDA	TOP		; make bottom of screen the top of
;	SEC			; scrolling screen - 1
;	SBC	#1		; to get bottom of screen
;	STA	WBOTM		; and save it
;	LDA	#2		;DBG
	STA	WBOTM		;DBG
	LDA	#0		; TOP, NON SCROLLING SCREEN
	STA	WTOP		; (C-128 WON'T GO BEYOND WTOP)
	STA	SCRIPT		; SET SCRIPTNG OFF, NOT ALLOWED THIS SCREEN
	TAY
	TAX			; ALIGN AT TOP OF SCREEN
SCRNP:
	CLC
	JMP	PLOT		; SET CURSOR (+ LEAVE)


	; -----
	; SOUND
	; -----
	; ARG1 = BOOP (2) BEEP (1) ALL OTHERS INVALID
	; (EZIP)

ZSOUND:	LDA	ZBEGIN+ZMODE	
	AND	#%00100000	
	BEQ	ZSOEX	; NOT ENABLED
	LDX	ARG1+LO	; GET SOUND WANTED
	DEX		
	BNE	ZSO1
	JMP	BEEP	
ZSO1:	DEX		
	BNE	ZSOEX	; INVALID
	JMP	BOOP	; DOWN IN COMMON MEMORY

ZSOEX:	RTS		


	END
