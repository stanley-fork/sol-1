	PAGE
	SBTTL	"--- TIME-STAMP PAGING ROUTINE ---"

	; -------------------------
	; FETCH NEXT BYTE OF Z-CODE
	; -------------------------

	; EXIT: BYTE AT [ZPC] IN [A] & [Y]; FLAGS SET

NEXTPC:	LDA	ZPCFLG		; IS [ZPCPNT] VALID?
	BNE	NPC2		; YES, GET THE BYTE

	; Z-PAGE HAS CHANGED!

	LDA	ZPCM		; GET TOP
	LDY	ZPCH		; 9 BITS OF [ZPC]
	BNE	NPC0		; SWAP PAGE IF TOP BIT IS SET

	CMP	ZPURE		; IS THIS PAGE PRELOADED?
	BCS	NPC0		; NO, SWAP IT IN

	ADC	ZCODE		; ELSE MAKE IT ABSOLUTE
	BNE	NPC1		; AND GIVE IT TO [ZPCPNT]

NPC0:	LDX	#0
	STX	MPCFLG		; INVALIDATE [MPC]
	JSR	PAGE		; AND GET ABS PAGE ADDR INTO [A]

NPC1:	STA	ZPCPNT+HI	; SET ABS PAGE ADDRESS
	LDX	#$FF
	STX	ZPCFLG		; VALIDATE [ZPCPNT]
	INX			; = 0
	STX	ZPCPNT+LO	; CLEAR LSB OF POINTER

NPC2:	LDY	ZPCL		; FETCH PAGE INDEX
	LDA	(ZPCPNT),Y	; GET Z-BYTE

	INC	ZPCL		; END OF PAGE YET?
	BNE	NPC3		; NO, EXIT

	LDY	#0
	STY	ZPCFLG		; ELSE INVALIDATE [ZPCPNT]

	INC	ZPCM		; POINT [ZPC] TO
	BNE	NPC3		; THE NEXT
	INC	ZPCH		; Z-PAGE

NPC3:	TAY			; SET FLAGS
	RTS			; AND RETURN

	; -------------------------------
	; GET NEXT BYTE OF VIRTUAL MEMORY
	; -------------------------------

	; EXIT: BYTE AT [MPC] IN [A] & [Y]; FLAGS SET

GETBYT:	LDA	MPCFLG		; IS [MPCPNT] VALID?
	BNE	GTBT2		; YES, GET THE BYTE

	; Z-PAGE HAS CHANGED!

	LDA	MPCM		; GET TOP
	LDY	MPCH		; 9 BITS OF [MPC]
	BNE	GTBT0		; SWAP PAGE IF TOP BIT IS SET

PATCH	EQU	$+1		; PATCH POINT FOR "VERIFY"

	CMP	ZPURE		; IS THIS PAGE PRELOADED?
	BCS	GTBT0		; NO, SWAP IT IN

	ADC	ZCODE		; ELSE MAKE IT ABSOLUTE
	BNE	GTBT1		; AND GIVE IT TO [MPCPNT]

GTBT0:	LDX	#0
	STX	ZPCFLG		; INVALIDATE [ZPC]
	JSR	PAGE		; AND GET ABS PAGE ADDR INTO [A]

GTBT1:	STA	MPCPNT+HI	; SET ABS PAGE ADDRESS
	LDX	#$FF
	STX	MPCFLG		; VALIDATE [MPCPNT]
	INX			; = 0
	STX	MPCPNT+LO	; CLEAR LSB OF POINTER

GTBT2:	LDY	MPCL		; FETCH PAGE INDEX
	LDA	(MPCPNT),Y	; GET Z-BYTE

	INC	MPCL		; END OF PAGE YET?
	BNE	GTBT3		; NO, EXIT

	LDY	#0
	STY	MPCFLG		; ELSE INVALIDATE [MPCPNT]

	INC	MPCM		; POINT [MPC] TO
	BNE	GTBT3		; THE NEXT
	INC	MPCH		; Z-PAGE

GTBT3:	TAY			; SET FLAGS
	RTS			; AND RETURN

	; ------------------------
	; LOCATE A SWAPABLE Z-PAGE
	; ------------------------

	; ENTRY: TARGET Z-PAGE IN [A/Y] (9 BITS)
	; EXIT: ABSOLUTE PAGE IN [A]

PAGE:	STA	TARGET+LO	; SAVE THE
	STY	TARGET+HI	; TARGET Z-PAGE HERE

	; IS THIS Z-PAGE ALREADY PAGED IN?

	LDX	#0
	STX	ZPAGE		; START AT BUFFER #0

PG1:	CMP	PTABL,X		; LSB MATCHED?
	BNE	PG2		; NO, TRY NEXT BUFFER
	TYA			; ELSE CHECK
	CMP	PTABH,X		; TOP BIT
	BEQ	PG4		; MATCHED! BUFFER IN [ZPAGE]
	LDA	TARGET+LO	; ELSE RESTORE LSB
PG2:	INC	ZPAGE		; UPDATE TALLY
	INX
	CPX	PMAX		; OUT OF BUFFERS YET?
	BCC	PG1		; NO, KEEP SEARCHING

	; SWAP IN THE TARGET PAGE

PG3:	JSR	EARLY		; GET EARLIEST PAGE
	LDX	SWAP		; INTO [SWAP] & [X]
	STX	ZPAGE		; SAVE FOR LATER

	LDA	TARGET+LO	; ASSIGN THE TARGET PAGE
	STA	PTABL,X		; TO THE EARLIEST BUFFER
	STA	DBLOCK+LO	; ALSO GIVE IT TO ZDOS

	LDA	TARGET+HI	; SAME FOR TOP BIT
	AND	#%00000001	; USE ONLY BIT 0
	STA	PTABH,X
	STA	DBLOCK+HI

	TXA
	CLC
	ADC	PAGE0		; CALC ABS ADDR OF BUFFER
	STA	DBUFF+HI	; GIVE IT TO ZDOS

	JSR	GETDSK		; SWAP IN THE NEW PAGE
	BCS	DKERR		; ERROR IF CARRY SET

	; UPDATE THE TIMESTAMP

PG4:	LDY	ZPAGE		; GET THE BUFFER INDEX
	LDA	LRUMAP,Y	; GET THIS BUFFER'S STAMP
	CMP	STAMP		; SAME AS CURRENT STAMP?
	BEQ	PG8		; YES, EXIT

	INC	STAMP		; UPDATE STAMP
	BNE	PG7		; CONTINUE IF NO OVERFLOW

	; HANDLE STAMP OVERFLOW

	JSR	EARLY2		; GET EARLIEST STAMP INTO [LRU]

	LDX	#0		; INIT INDEX
PG5:	LDA	LRUMAP,X	; GET A STAMP READING
	BEQ	PG6		; EXIT IF ALREADY ZERO
	SEC			; ELSE SUBTRACT OFF
	SBC	LRU		; THE EARLIEST TIMESTAMP
	STA	LRUMAP,X	; AND REPLACE THE STAMP
PG6:	INX
	CPX	PMAX		; END OF SWAPPING SPACE?
	BCC	PG5		; LOOP TILL ALL STAMPS FIXED

	LDA	#0		; TURN BACK THE CLOCK
	SEC			; TO REFLECT NEW
	SBC	LRU		; STAMP READING
	STA	STAMP

PG7:	LDA	STAMP		; FETCH STAMP
	STA	LRUMAP,Y	; STAMP TARGET PAGE WITH IT

PG8:	LDA	ZPAGE		; GET BUFFER INDEX
	CLC			; MAKE IT
	ADC	PAGE0		; ABSOLUTE
	RTS			; AND RETURN IT IN [A]

	; *** ERROR #14: DRIVE ACCESS ***

DKERR:	LDA	#14
	JMP	ZERROR

	; -------------------------
	; LOCATE EARLIEST TIMESTAMP
	; -------------------------

	; EXIT: [LRU] - EARLIEST TIMESTAMP
	;	[SWAP] = INDEX TO EARLIEST BUFFER

EARLY:	LDX	#0		; INIT INDEX
	STX	SWAP		; AND [SWAP]
	LDA	LRUMAP		; GET STAMP OF BUFFER #0
	INX			; START COMPARE WITH BUFFER #1
EAR0:	CMP	LRUMAP,X	; IS THIS STAMP EARLIER THAN [A]?
	BCC	EAR1		; NO, TRY NEXT STAMP
	LDA	LRUMAP,X	; ELSE FETCH EARLIER ENTRY
	STX	SWAP		; AND REMEMBER WHERE WE FOUND IT
EAR1:	INX			; POINT TO NEXT STAMP
	CPX	PMAX		; OUT OF STAMPS YET?
	BCC	EAR0		; LOOP TILL EMPTY

	STA	LRU		; SAVE EARLIEST STAMP HERE
	RTS

	; ------
	; EARLY2
	; ------

	; THIS IS FOR OVERFLOW, IGNORES 0 ENTRIES

SAVEY:	DB	0

EARLY2:	LDX	#0		; INIT INDEX
	STX	SWAP
	STY	SAVEY
EAR23:	LDA	LRUMAP,X	; GET TIMESTAMP OF BUFFER #0
	CMP	#0		; DON'T USE A ZERO VALUE
	BNE	EAR22		; OK, NOT 0
	INX
	CPX	PMAX		; OUT OF BUFFERS?
	BCC	EAR23		; NO, KEEP LOOKING
	BCS	EAR24		; YUP, SO WILL HAVE TO USE 0

EAR22:	INX			; START COMPARE WITH NEXT BUFFER

EAR20:	CMP	LRUMAP,X	; IS THIS STAMP EARLIER THAN [A]?
	BCC	EAR21		; IF STILL SMALLER, TRY NEXT STAMP

	LDY	LRUMAP,X
	BEQ	EAR21
	TYA
	STX	SWAP

EAR21:	INX
	CPX	PMAX		; OUT OF BUFFERS?
	BCC	EAR20		; LOOP TILL EMPTY

EAR24:	STA	LRU		; [A] HAS EARLIEST STAMP
	LDY	SAVEY
	RTS			; [SWAP] HAS INDEX TO EARLIEST BUFFER

	; -------------------------
	; POINT [MPC] TO V-ADDR [I]
	; -------------------------

SETWRD:	LDA	I+LO
	STA	MPCL
	LDA	I+HI
	STA	MPCM

	LDA	#0
	STA	MPCH		; ZERO TOP BIT
	STA	MPCFLG		; INVALIDATE [MPC]
	RTS

	; ----------------------------
	; GET Z-WORD AT [MPC] INTO [I]
	; ----------------------------

;GETWRD:	JSR	GETBYT
;	STA	I+HI
;	JSR	GETBYT
;	STA	I+LO
;	RTS

	END

		