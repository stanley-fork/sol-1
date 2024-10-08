/*
 *	string functions for Small-C/Plus
 * 	based on corresponding unix functions
 */

#include <stdio.h>
#include <string.h>

#ifndef Z80

strlen( string )
char *string ;
{
	int counter ;

	counter = 0 ;
	while( *string++ )
		counter++ ;
	return counter ;
}

#else

#asm
qstrlen:
	POP HL
	POP BC
	PUSH BC
	PUSH HL
	LD HL,0
ccstr3:
	LD A,(BC)
	OR A
	RET Z
	INC BC
	INC HL
	JP ccstr3
#endasm

#endif


#ifndef Z80

strcat( to, from )
char *to, *from ;
{
	char *temp ;

	temp = to ;
	while( *to++ ) ;
	to-- ;
	while( *to++ = *from++ ) ;
	return temp ;
}

#else

#asm
qstrcat:
	POP HL
	POP BC		;BC is from
	POP DE		;DE is to
	PUSH DE
	PUSH BC
	PUSH HL
	LD H,D		;return to
	LD L,E
ccstr4:
	LD A,(DE)
	OR A
	INC DE
	JP NZ,ccstr4
	DEC DE
ccstr5:
	LD A,(BC)
	LD (DE),A
	INC DE
	INC BC
	OR A
	RET Z
	JP ccstr5
#endasm

#endif


#ifndef Z80

strcpy( to, from )
char *to, *from ;
{
	char *temp ;

	temp = to ;
	while( *to++ = *from++ ) ;
	return temp ;
}

#else

#asm
qstrcpy:
	POP HL
	POP DE		;DE is from
	POP BC		;BC is to
	PUSH BC
	PUSH DE
	PUSH HL
	LD H,B		;return to
	LD L,C
ccstr2:
	LD A,(DE)
	LD (BC),A
	INC DE
	INC BC
	OR A		;test char for zero
	JP NZ,ccstr2
	RET
#endasm

#endif


#ifndef Z80

strcmp( s1, s2 )
char *s1, *s2 ;
{
	while( *s1 == *s2 ) {
		if( *s1 == 0 )
			return 0 ;
		s1++ ;
		s2++ ;
	}
	return *s1 - *s2 ;
}

#else

#asm
qstrcmp:
	POP BC
	POP HL		;HL is s2
	POP DE		;DE is s1
	PUSH DE
	PUSH HL
	PUSH BC
ccstr1:
	LD A,(DE)	;fetch *s1
	CP (HL)
	JP NZ,ccstr6	;quit if *s1 != *s2
	OR A		;check *s1 for zero
	INC DE
	INC HL
	JP NZ,ccstr1	;loop if *s1 != 0
	LD HL,0
	RET
ccstr6:
	SUB (HL)
	JP ccsxt	;else return *s1-*s2
#endasm

#endif
