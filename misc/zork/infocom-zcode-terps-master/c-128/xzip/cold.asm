	PAGE
	STTL "--- MACHINE COLDSTART: CBM64 ---"

	ORG	$1200

	; ---------
	; COLDSTART
	; ---------

	; BANK CONFIGURING IS LIKE THIS:
	; BIT 0		$D000 - $DFFF  1 = RAM  0 = IO
	; BIT 1		$4000 - $7FFF  1 = RAM  0 = SYSTEM ROM
	; BIT 2 & 3 	$8000 - $BFFF  11 = RAM  00 = SYSTEM ROM
	; BITS 4 & 5	$C000 - $FFFF  11 = RAM  00 = SYSTEM ROM
	; BIT 6		RAM BANK  0 = BANK0  1 = BANK1
	; BIT 7		UNUSED, WILL BE FOR BANKS 2 & 3

COLD1:	LDA	#%00001110	; SET UP CONFIGURATIONS FOR 
	STA	BANK0		; PROPER USE OF MEMORY
	LDA	#%01111111	; SAVING TO BE USED AS NEEDED
	STA	BANK1
	LDA	#%00111110
	STA	BANK2		; RAM FROM $C000 - $FFFF IN BANK0

	LDA	#$0E
	JSR	CHROUT		; USE UPPER/LOWER CHARS
	LDA	#$80		; PROHIBIT FURTHER
	STA	MODE		; CHARSET CHANGES

	JSR	CLALL		; CLOSE EVERYTHING
	JSR	MEMCHK		; check for ram expansion

	JMP	WARM1

	; ---------------
	; WARMSTART ENTRY
	; ---------------

SLOAD:	DB	"The story is loading ..."
	DB	EOL
SLOADL	EQU	$-SLOAD

WARM1:	CLD
	LDX	#$FF
	TXS			; RESET MACHINE STACK

	LDA	#CLS		; CLEAR SCREEN, ETC.
	JSR	CHROUT

	LDA	#1		; SET FONT TO 1 SO
	STA	FONT		; CHARS WILL BE DISPLAYED

	LDY	#28		; POSITION "STORY LOADING" MESSAGE
	LDX	#11		; AT (8,11)
	CLC
	JSR	PLOT

	LDX	#<SLOAD
	LDA	#>SLOAD
	LDY	#SLOADL
	JSR	DLINE		; "THE STORY IS LOADING ..."

	LDA	#8		; MAKE BOOT DRIVE
	JSR	DOPEN		; AND OPEN IT

	JMP	WARM2		; JMP OVER TEXT STRINGS

	END

