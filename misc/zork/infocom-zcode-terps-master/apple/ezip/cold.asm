	PAGE	
	SBTTL "--- MACHINE COLDSTART: APPLE II ---"

	; ---------
	; COLDSTART
	; ---------


SIG:	DB	0		; IIc FLAG
STRYSL:	DB	0		; BOOT SLOT
STRYDR:	DB	0		; BOOT DRIVE

	; FINISH LOADING THE ZIP

COLD:	LDA	BSLOT		; SET UP
	STA	DCBSLT		; CURRENT AND
	STA	DCBPSL		; PREVIOUS SLOT IDS

	LDA	#>COUT1	; SET SCREEN OUTPUT
	STA	CSW+HI		; IN CASE OF PR#6
	LDA	#<COUT1	; WHICH SETS ALL IN & OUTPUT 
	STA	CSW+LO		; TO PR #6

	LDX	#0
	STX	DCBSEC		; START WITH SECTOR 0
	STX	DBUFF+LO	; CLEAR LSB OF [DBUFF]
	INX			; = 1
	STX	DCBTRK		; START WITH TRACK 1
	STX	DCBDRV		; SET UP CURRENT
	STX	DCBPDR		; AND PREVIOUS DRIVE ID
	LDA	#$DF		; START LOAD AT $DF00
	STA	DBUFF+HI
	LDA	#25		; LOAD ALL OF
	STA	I+LO		; TRACK 1 AND PART OF 2 (EZIP)
COLD0:	JSR	GETRES		; GO THRU ZDOS
	DEC	I+LO		; DONE LOADING?
	BNE	COLD0		; NO, SO LOOP BACK
	LDA	#$FF		; SET TO NORMAL DISPLAY
	STA	INVFLG

	; DETERMINE SCREEN CONFIGURATION

	LDA	$FBB3		; CHECK ID BYTE
	CMP	#$06		; IS IT A IIE OR IIC?
	BEQ	COLD2
	JMP	NORAM		; NO, IT'S NOT 128K (EZIP)
COLD2:	LDA	$FBC0		; IS IT A IIE OR! A IIC
	STA	SIG		; 0 = IIC
	BEQ	DO80		; IIC, SKIP CHECK
COLD1:	JSR	MEMCHK		; CHECK IF 128K OF MEMORY
	BCS	NORAM		; NOPE
DO80:	JSR	$C300		; INIT 80 COL (PR#3)


	END