

	.FUNCT	CRAB-F,CONTEXT,X
	ZERO?	CONTEXT /?CCL3
	EQUAL?	CONTEXT,M-CONT \FALSE
	INTBL?	PRSA,TOUCHVERBS,NTOUCHES >X \FALSE
	ICALL2	CTHE-PRINT,CRAB
	PRINTR	" snaps at your fingers. Yow!"
?CCL3:	EQUAL?	PRSA,V?HIT,V?MUNG /?CCL9
	INTBL?	PRSA,TOUCHVERBS,NTOUCHES >X \?CCL9
	ICALL1	SHY-CRAB
	RTRUE	
?CCL9:	ZERO?	NOW-PRSI? /?CCL13
	EQUAL?	PRSA,V?THROW,V?THROW-OVER \?CCL16
	ICALL1	MONSTER-THROW
	RTRUE	
?CCL16:	EQUAL?	PRSA,V?PUT-ON,V?EMPTY-INTO \FALSE
	ICALL1	PRSO-SLIDES-OFF-PRSI
	RTRUE	
?CCL13:	EQUAL?	PRSA,V?EXAMINE,V?LOOK-ON \?CCL19
	ICALL1	CTHE-PRINT
	PRINTI	" adjusts the crown on its head, and glares at you defiantly. "
	ICALL1	DIAGNOSE-MONSTER
	RTRUE	
?CCL19:	EQUAL?	PRSA,V?WHAT,V?WHO \FALSE
	ICALL1	REFER-TO-PACKAGE
	RETURN	2


	.FUNCT	SHY-CRAB
	ICALL2	CTHE-PRINT,CRAB
	PRINTR	" sidesteps out of your reach."


	.FUNCT	RAT-F,CONTEXT,X
	ZERO?	CONTEXT \FALSE
	ZERO?	NOW-PRSI? /?CCL5
	EQUAL?	PRSA,V?THROW,V?THROW-OVER \FALSE
	ICALL1	MONSTER-THROW
	RTRUE	
?CCL5:	EQUAL?	PRSA,V?EXAMINE \FALSE
	ICALL1	CTHE-PRINT
	PRINTI	" glares back at you, snarling. "
	ICALL1	DIAGNOSE-MONSTER
	RTRUE	


	.FUNCT	DESCRIBE-HEAP,OBJ
	PRINTI	"heap of bones"
	RTRUE	


	.FUNCT	SKELETON-F,CONTEXT
	EQUAL?	CONTEXT,M-OBJDESC \?CCL3
	ICALL2	PRINTCA,SKELETON
	ZERO?	CHOKE /?CCL6
	PRINTI	" is clutching your throat."
	JUMP	?CND4
?CCL6:	PRINT	STR?507
	FSET?	AMULET,TOUCHED /?CND7
	FSET	AMULET,NODESC
?CND7:	CALL2	SEE-ANYTHING-IN?,SKELETON
	ZERO?	STACK /?CND9
	PRINTI	" On it you see "
	ICALL2	CONTENTS,SKELETON
	PRINTC	PER
?CND9:	FCLEAR	AMULET,NODESC
?CND4:	FSET?	AMULET,TOUCHED /TRUE
	PRINTI	" An amulet dangles from its neck."
	RTRUE	
?CCL3:	CALL2	STRANGLE?,SKELETON
	ZERO?	STACK /?CCL14
	RETURN	2
?CCL14:	ZERO?	NOW-PRSI? \FALSE
	EQUAL?	PRSA,V?TAKE,V?KICK,V?HIT /?CTR19
	EQUAL?	PRSA,V?SHAKE,V?MOVE,V?PUSH /?CTR19
	EQUAL?	PRSA,V?PULL,V?ADJUST \?CCL20
?CTR19:	FSET?	PRSO,MUNGED \?CND24
	ICALL1	WASTE-OF-TIME
	RTRUE	
?CND24:	BOR	NEW-DBOX,SHOWING-ROOM >NEW-DBOX
	FSET	PRSO,MUNGED
	FSET	PRSO,SEEN
	PUTP	PRSO,P?SDESC,DESCRIBE-HEAP
	FSET	AMULET,TOUCHED
	ICALL	REPLACE-SYN?,PRSO,W?BODY,W?PILE
	ICALL	REPLACE-SYN?,PRSO,W?CORPSE,W?HEAP
	ICALL	REPLACE-SYN?,PRSO,W?NECK,W?ZZZP
	ICALL	REPLACE-ADJ?,PRSO,W?SKELETON,W?ZZZP
	PRINTI	"With a sigh of exhaustion, "
	ICALL1	THE-PRINT
	ZERO?	CHOKE /?CND26
	SET	'CHOKE,0
	ICALL2	DEQUEUE,I-STRANGLE
	PRINTI	" releases its strangle hold and"
?CND26:	PRINTI	" crumbles into a useless "
	ICALL2	DPRINT,PRSO
	PRINT	PERIOD
	GETP	SKELETON,P?VALUE
	ICALL	UPDATE-STAT,STACK,EXPERIENCE
	RTRUE	
?CCL20:	EQUAL?	PRSA,V?LOOK-ON,V?LOOK-INSIDE,V?SEARCH /?CTR28
	EQUAL?	PRSA,V?LOOK-UNDER,V?DIG,V?DIG-UNDER \?CCL29
?CTR28:	PRINTI	"You find "
	FSET?	AMULET,TOUCHED /?CND32
	FSET	AMULET,NODESC
?CND32:	ICALL1	CONTENTS
	FCLEAR	AMULET,NODESC
	PRINT	PERIOD
	RTRUE	
?CCL29:	EQUAL?	PRSA,V?EXAMINE,V?LOOK-ON \FALSE
	FSET?	PRSO,MUNGED /FALSE
	PRINTI	"It grins at you horribly. "
	ICALL1	DIAGNOSE-MONSTER
	RTRUE	


	.FUNCT	SNIPE-F,CONTEXT,X
	ZERO?	CONTEXT \FALSE
	ZERO?	NOW-PRSI? /?CCL5
	EQUAL?	PRSA,V?THROW,V?THROW-OVER \FALSE
	ICALL1	MONSTER-THROW
	RTRUE	
?CCL5:	EQUAL?	PRSA,V?EXAMINE \FALSE
	ICALL1	CTHE-PRINT
	PRINTI	"'s beak is almost a foot long, and sharp as a needle. "
	ICALL1	DIAGNOSE-MONSTER
	RTRUE	


	.FUNCT	VAPOR-F,CONTEXT,X
	ZERO?	CONTEXT \FALSE
	ZERO?	NOW-PRSI? /?CCL5
	EQUAL?	PRSA,V?THROW,V?THROW-OVER \FALSE
	ICALL1	MONSTER-THROW
	RTRUE	
?CCL5:	INTBL?	PRSA,TALKVERBS,NTVERBS >X \?CCL9
	ICALL1	PCLEAR
	ICALL1	CTHE-PRINT
	PRINTI	" murmurs vaguely in response."
	CRLF	
	RETURN	2
?CCL9:	EQUAL?	PRSA,V?EXAMINE \?CCL13
	ICALL1	DIAGNOSE-MONSTER
	FSET?	PRSO,TOUCHED /TRUE
	FSET	PRSO,TOUCHED
	PRINT	TAB
	ICALL1	REFER-TO-PACKAGE
	RTRUE	
?CCL13:	EQUAL?	PRSA,V?WHAT,V?WHO \FALSE
	ICALL1	REFER-TO-PACKAGE
	RETURN	2


	.FUNCT	SPIDER-F,CONTEXT,X
	ZERO?	CONTEXT \FALSE
	ZERO?	NOW-PRSI? /?CCL5
	EQUAL?	PRSA,V?THROW,V?THROW-OVER \FALSE
	ICALL1	MONSTER-THROW
	RTRUE	
?CCL5:	EQUAL?	PRSA,V?EXAMINE \FALSE
	ICALL1	CTHE-PRINT
	PRINTI	" looks alarmingly well-fed. "
	ICALL1	DIAGNOSE-MONSTER
	RTRUE	


	.FUNCT	SLUG-F,CONTEXT,X
	ZERO?	CONTEXT \FALSE
	ZERO?	NOW-PRSI? /?CCL5
	EQUAL?	PRSA,V?THROW,V?THROW-OVER,V?PUT-ON /?CCL7
	EQUAL?	PRSA,V?PUT,V?TOUCH-TO \FALSE
?CCL7:	ICALL2	TOUCH-SLUG-WITH,PRSO
	RTRUE	
?CCL5:	EQUAL?	PRSA,V?EXAMINE,V?LOOK-ON \FALSE
	ICALL1	CTHE-PRINT
	PRINTI	" is about as long as you are tall. "
	ICALL1	DIAGNOSE-MONSTER
	RTRUE	


	.FUNCT	TOUCH-SLUG-WITH,OBJ
	ICALL2	ITALICIZE,STR?664
	PRINTI	"! "
	EQUAL?	OBJ,CUBE /?CND1
	BOR	NEW-DBOX,SHOWING-ALL >NEW-DBOX
	MOVE	OBJ,HERE
	ICALL2	CTHE-PRINT,OBJ
	PRINTI	" slips off "
	ICALL2	THE-PRINT,SLUG
	PRINTR	"'s oozing body with no effect."
?CND1:	REMOVE	CUBE
	ICALL2	VANISH,SLUG
	ICALL2	CTHE-PRINT,SLUG
	PRINTI	" emits a shriek of agony as "
	ICALL2	THE-PRINT,OBJ
	PRINTI	" slides across its body. You leap out of its path of retreat, and listen as its repulsive squeals "
	PRINT	STR?593
	ICALL2	KILL-MONSTER,SLUG
	RTRUE	


	.FUNCT	DESCRIBE-DUST,OBJ
	PRINTI	"dust bunny"
	RTRUE	


	.FUNCT	DUST-F,CONTEXT,X
	EQUAL?	CONTEXT,M-OBJDESC \?CCL3
	LESS?	BUNNIES,5 \?CCL6
	PRINT	XA
	EQUAL?	BUNNIES,1 \?CCL9
	PRINTI	"dust bunny is "
	JUMP	?CND7
?CCL9:	EQUAL?	BUNNIES,2 \?CCL12
	PRINTI	"pair"
	JUMP	?CND10
?CCL12:	PRINTI	"trio"
?CND10:	PRINTI	" of "
	PRINTD	DUST
	PRINTI	" are "
?CND7:	PRINTI	"lurking in "
	ICALL2	THE-PRINT,GCORNER
	PRINTC	PER
	RTRUE	
?CCL6:	EQUAL?	BUNNIES,8 \?CCL14
	PRINTI	"Eight"
	JUMP	?CND4
?CCL14:	EQUAL?	BUNNIES,13 \?CCL16
	PRINTI	"Thirteen"
	JUMP	?CND4
?CCL16:	GRTR?	BUNNIES,BMAX \?CCL18
	PRINTI	"Countless"
	JUMP	?CND4
?CCL18:	GRTR?	BUNNIES,999 \?CCL20
	DIV	BUNNIES,1000
	PRINTN	STACK
	PRINTC	COMMA
	MOD	BUNNIES,1000
	PRINTN	STACK
	JUMP	?CND4
?CCL20:	PRINTN	BUNNIES
?CND4:	PRINTC	SP
	PRINTD	DUST
	PRINTI	" hover in the air."
	RTRUE	
?CCL3:	ZERO?	CONTEXT \FALSE
	FSET?	DUST,TOUCHED /?CND1
	INTBL?	PRSA,TOUCHVERBS,NTOUCHES >X \?CND1
	ICALL1	START-DUST
?CND1:	ZERO?	NOW-PRSI? /?CCL27
	EQUAL?	PRSA,V?THROW,V?THROW-OVER \FALSE
	MOVE	PRSO,HERE
	BOR	NEW-DBOX,SHOWING-ALL >NEW-DBOX
	ICALL1	CTHEI-PRINT
	PRINTI	" easily avoid "
	ICALL1	THE-PRINT
	PRINT	PERIOD
	RTRUE	
?CCL27:	EQUAL?	PRSA,V?HIT,V?MUNG,V?CUT /?CTR30
	EQUAL?	PRSA,V?TOUCH,V?KICK,V?TAKE /?CTR30
	EQUAL?	PRSA,V?SHAKE \?CCL31
?CTR30:	ICALL1	HIT-BUNNIES
	RTRUE	
?CCL31:	EQUAL?	PRSA,V?EXAMINE,V?COUNT \FALSE
	FCLEAR	PRSO,SEEN
	EQUAL?	BUNNIES,1 \?CCL39
	ICALL1	ONLY-ONE
	RTRUE	
?CCL39:	GRTR?	BUNNIES,BMAX \?CND37
	ICALL1	CTHE-PRINT
	PRINTR	" number in the countless thousands."
?CND37:	PRINTI	"A quick count turns up "
	GRTR?	BUNNIES,999 \?CCL43
	DIV	BUNNIES,1000
	PRINTN	STACK
	PRINTC	COMMA
	MOD	BUNNIES,1000
	PRINTN	STACK
	JUMP	?CND41
?CCL43:	PRINTN	BUNNIES
?CND41:	PRINTC	SP
	PRINTD	PRSO
	PRINT	PERIOD
	RTRUE	


	.FUNCT	HIT-BUNNIES
	ICALL1	WHOOSH
	ZERO?	PRSI \?CND1
	SET	'PRSI,HANDS
?CND1:	ICALL1	YOUR-OBJ
	PRINTI	" swipes through "
	ICALL1	THE-PRINT
	PRINT	PTAB
	CALL	SPARK-TO?,PRSI,PRSO
	ZERO?	STACK \TRUE
	ICALL2	I-DUST,FALSE-VALUE
	RFALSE	


	.FUNCT	START-DUST
	FSET	DUST,TOUCHED
	FCLEAR	DUST,SEEN
	ICALL2	QUEUE,I-DUST
	RFALSE	


	.FUNCT	DORN-F,CONTEXT
	EQUAL?	CONTEXT,M-OBJDESC \?CCL3
	ICALL2	PRINTCA,DORN
	PRINT	SIS
	FSET?	DORN,MUNGED \?CCL6
	PRINTI	"thrashing about, bawling helplessly."
	RTRUE	
?CCL6:	FSET?	DORN,SURPRISED \?CND4
	PRINTI	"waiting for you."
	RTRUE	
?CND4:	PRINTI	"sweeping its gaze around the room."
	RTRUE	
?CCL3:	EQUAL?	CONTEXT,M-WINNER \?CCL9
	FSET	DORN,SEEN
	PRINTI	"""Hurumph."""
	CRLF	
	RETURN	2
?CCL9:	ZERO?	CONTEXT \FALSE
	ZERO?	NOW-PRSI? /?CCL15
	EQUAL?	PRSA,V?THROW,V?THROW-OVER \FALSE
	ICALL1	MONSTER-THROW
	RTRUE	
?CCL15:	EQUAL?	PRSA,V?TELL \?CCL19
	ICALL2	SEE-CHARACTER,PRSO
	FSET?	PRSO,MUNGED \?CCL22
	ICALL2	CTHE-PRINT,DORN
	PRINTI	" is too busy bawling to respond."
	CRLF	
	RETURN	2
?CCL22:	ZERO?	P-CONT /?CND20
	SET	'WINNER,PRSO
	RTRUE	
?CND20:	ICALL1	CTHE-PRINT
	PRINTI	" ""Hurumphs"" expectantly."
	CRLF	
	RETURN	2
?CCL19:	EQUAL?	PRSA,V?EXAMINE \?CCL29
	FSET?	PRSO,MUNGED \?CND30
	ICALL1	CTHE-PRINT
	PRINTI	" is bawling like a baby. "
?CND30:	ICALL1	DIAGNOSE-MONSTER
	FSET?	PRSO,TOUCHED /TRUE
	FSET	PRSO,TOUCHED
	PRINT	TAB
	ICALL1	REFER-TO-PACKAGE
	RTRUE	
?CCL29:	EQUAL?	PRSA,V?WHAT,V?WHO \FALSE
	ICALL1	REFER-TO-PACKAGE
	RETURN	2


	.FUNCT	DESCRIBE-WORM,OBJ
	PRINTI	"mossy rock"
	RTRUE	


	.FUNCT	WORM-F,CONTEXT,X
	ZERO?	CONTEXT /?CCL3
	EQUAL?	CONTEXT,M-OBJDESC \FALSE
	FSET?	WORM,MONSTER /?CND6
	PRINTI	"The underbrush almost conceals "
	ICALL2	PRINTA,WORM
	PRINTC	PER
	RTRUE	
?CND6:	ICALL1	VIEW-MONSTER
	RTRUE	
?CCL3:	FSET?	WORM,MONSTER /?CND1
	EQUAL?	PRSA,V?LOOK-UNDER,V?LOOK-BEHIND,V?SEARCH /?CCL9
	INTBL?	PRSA,TOUCHVERBS,NTOUCHES >X \?CND1
?CCL9:	ICALL2	START-WORM,STR?666
	RTRUE	
?CND1:	ZERO?	NOW-PRSI? /?CCL14
	EQUAL?	PRSA,V?THROW,V?THROW-OVER \FALSE
	ICALL1	MONSTER-THROW
	RTRUE	
?CCL14:	EQUAL?	PRSA,V?EXAMINE \FALSE
	ICALL1	CTHE-PRINT
	FSET?	PRSO,MONSTER \?CND19
	PRINTI	" no longer looks like a mossy rock. It's equipped with three-foot fangs, and seems eager to plunge one or both of them into your chest. "
	ICALL1	DIAGNOSE-MONSTER
	RTRUE	
?CND19:	ICALL1	HELMLOOK
	RTRUE	


	.FUNCT	HELMLOOK
	CALL2	WEARING-MAGIC?,HELM
	ZERO?	STACK /?CND1
	PRINTR	" looks vaguely suspicious."
?CND1:	PRINT	STR?667
	RTRUE	


	.FUNCT	START-WORM,STR,X
	FSET	WORM,MONSTER
	FCLEAR	WORM,SLEEPING
	FSET	WORM,NOALL
	FCLEAR	WORM,SURFACE
	ICALL	REPLACE-SYN?,WORM,W?ROCK,W?MONSTER
	ICALL	REPLACE-SYN?,WORM,W?STONE,W?ZZZP
	ICALL	REPLACE-ADJ?,WORM,W?MOSSY,W?ZZZP
	ICALL	REPLACE-ADJ?,WORM,W?MOSS,W?ZZZP
	ICALL2	QUEUE,I-WORM
	BOR	NEW-DBOX,SHOWING-ROOM >NEW-DBOX
	SET	'LAST-MONSTER,WORM
	SET	'LAST-MONSTER-DIR,P-WALK-DIR
	SET	'P-IT-OBJECT,WORM
	PUTP	WORM,P?SDESC,DESCRIBE-MONSTERS
	PRINTI	"As you "
	PRINT	STR
	PRINTI	" the rock, a three-foot set of fangs leaps "
	PRINT	STR?668
	RTRUE	


	.FUNCT	CROC-F,CONTEXT,X
	ZERO?	CONTEXT \FALSE
	ZERO?	NOW-PRSI? /?CCL5
	EQUAL?	PRSA,V?THROW,V?THROW-OVER \FALSE
	ICALL1	MONSTER-THROW
	RTRUE	
?CCL5:	EQUAL?	PRSA,V?EXAMINE \FALSE
	ICALL1	CTHE-PRINT
	PRINTI	" looks hungry. "
	ICALL1	DIAGNOSE-MONSTER
	RTRUE	


	.FUNCT	HOUND-F,CONTEXT,X
	ZERO?	CONTEXT \FALSE
	ZERO?	NOW-PRSI? /?CCL5
	EQUAL?	PRSA,V?THROW,V?THROW-OVER \FALSE
	ICALL1	MONSTER-THROW
	RTRUE	
?CCL5:	EQUAL?	PRSA,V?EXAMINE \FALSE
	ICALL1	CTHE-PRINT
	PRINTI	" is deciding how best to eat you. "
	ICALL1	DIAGNOSE-MONSTER
	RTRUE	


	.FUNCT	PUPP-F,CONTEXT,X
	ZERO?	CONTEXT \FALSE
	ZERO?	NOW-PRSI? /?CCL5
	EQUAL?	PRSA,V?THROW,V?THROW-OVER \FALSE
	ICALL1	MONSTER-THROW
	RTRUE	
?CCL5:	EQUAL?	PRSA,V?EXAMINE \?CCL9
	ICALL1	CTHE-PRINT
	PRINTI	" twists its face to look just like you. Eeek! "
	ICALL1	DIAGNOSE-MONSTER
	RTRUE	
?CCL9:	EQUAL?	PRSA,V?LAUGH \FALSE
	EQUAL?	P-PRSA-WORD,W?INSULT,W?OFFEND \FALSE
	GETP	PRSO,P?EMAX >X
	GETP	PRSO,P?ENDURANCE
	LESS?	STACK,X \?CCL16
	PUTP	PRSO,P?ENDURANCE,X
	JUMP	?CND14
?CCL16:	LESS?	X,32762 \?CND14
	ADD	X,5 >X
	PUTP	PRSO,P?EMAX,X
	PUTP	PRSO,P?ENDURANCE,X
?CND14:	PRINTI	"You instantly regret your words, for "
	ICALL1	THE-PRINT
	PRINTI	" grins with renewed vitality. It apparently "
	ICALL2	ITALICIZE,STR?672
	PRINTR	" off insults like that!"


	.FUNCT	DEAD-F,CONTEXT,X
	ZERO?	CONTEXT \FALSE
	ZERO?	NOW-PRSI? /?CCL5
	EQUAL?	PRSA,V?THROW,V?THROW-OVER,V?TOUCH-TO \FALSE
	ICALL2	TOUCH-DEAD-WITH,PRSO
	RTRUE	
?CCL5:	EQUAL?	PRSA,V?EXAMINE \?CCL9
	ICALL1	CTHE-PRINT
	PRINTI	" shimmers like a wave of heat. "
	ICALL1	DIAGNOSE-MONSTER
	RTRUE	
?CCL9:	EQUAL?	PRSA,V?HIT,V?MUNG,V?CUT /?CTR10
	EQUAL?	PRSA,V?RIP,V?CUT,V?OPEN /?CTR10
	EQUAL?	PRSA,V?OPEN-WITH,V?KICK,V?STOUCH-TO \?CCL11
?CTR10:	ICALL2	TOUCH-DEAD-WITH,PRSI
	RTRUE	
?CCL11:	INTBL?	PRSA,TOUCHVERBS,NTOUCHES >X \FALSE
	ICALL2	TOUCH-DEAD-WITH,HANDS
	RTRUE	


	.FUNCT	TOUCH-DEAD-WITH,OBJ
	EQUAL?	OBJ,VIAL /?CND1
	ICALL	PASSES-THROUGH,OBJ,DEAD
	RTRUE	
?CND1:	ICALL2	VANISH,VIAL
	PRINT	YOU-HEAR
	PRINTI	"a sharp "
	ICALL2	ITALICIZE,STR?674
	PRINTI	" as "
	ICALL2	THE-PRINT,VIAL
	PRINTI	" shatters, splashing your target with a shower of droplets that burst into fire on contact! The blasphemous creature opens its jaws in a silent scream as a purifying flame engulfs its ghostly form.
  Moments later, the last few cinders scatter in the breeze."
	CRLF	
	ICALL2	KILL-MONSTER,DEAD
	RTRUE	


	.FUNCT	GHOUL-F,CONTEXT,X
	ZERO?	CONTEXT /?CCL3
	EQUAL?	CONTEXT,M-CONT \FALSE
	INTBL?	PRSA,TOUCHVERBS,NTOUCHES >X \FALSE
	PRINTI	"Laughing insanely, "
	ICALL2	THE-PRINT,GHOUL
	PRINTR	" dodges out of reach."
?CCL3:	ZERO?	NOW-PRSI? /?CCL9
	EQUAL?	PRSA,V?THROW,V?THROW-OVER \FALSE
	ICALL1	MONSTER-THROW
	RTRUE	
?CCL9:	EQUAL?	PRSA,V?EXAMINE \FALSE
	ICALL1	CTHE-PRINT
	PRINTI	" glares back at you. "
	ICALL1	DIAGNOSE-MONSTER
	RTRUE	


	.FUNCT	CORBIES-F,FEAR,X
	ZERO?	BADKEY /?CND1
	LOC	BADKEY
	EQUAL?	STACK,PLAYER,HERE \?CND1
	INC	'FEAR
?CND1:	ZERO?	NOW-PRSI? /?CCL7
	EQUAL?	PRSA,V?THROW,V?THROW-OVER,V?GIVE /?CTR9
	EQUAL?	PRSA,V?FEED,V?SHOW \?CCL10
?CTR9:	FSET	PRSI,SEEN
	EQUAL?	PRSA,V?SHOW /?CND13
	MOVE	PRSO,HERE
	BOR	NEW-DBOX,SHOWING-ALL >NEW-DBOX
?CND13:	ICALL1	CTHEI-PRINT
	EQUAL?	PRSO,BADKEY \?CND15
	PRINTR	" screech with fear!"
?CND15:	PRINTI	" snatch "
	ICALL1	THE-PRINT
	PRINTI	" out of the air, aim carefully and drop it"
	RANDOM	100
	LESS?	50,STACK /?CND17
	PRINTI	" on your skull. Ouch!"
	CRLF	
	GETP	PRSO,P?SIZE
	SUB	0,STACK
	ICALL2	UPDATE-STAT,STACK
	RTRUE	
?CND17:	PRINTR	", narrowly missing your skull."
?CCL10:	INTBL?	PRSA,TOUCHVERBS,NTOUCHES >X \FALSE
	ICALL1	CORBIES-STAY-AWAY
	RTRUE	
?CCL7:	INTBL?	PRSA,TALKVERBS,NTVERBS >X \?CCL21
	ICALL2	CTHE-PRINT,CORBIES
	PRINTI	" shriek back obscenities."
	CRLF	
	RETURN	2
?CCL21:	EQUAL?	PRSA,V?EXAMINE,V?LOOK-ON \?CCL25
	PRINTI	"The flock of "
	PRINTD	PRSO
	PRINTI	" soars overhead in "
	ZERO?	FEAR /?CCL28
	PRINTI	"high, frightened "
	JUMP	?CND26
?CCL28:	PRINTI	"low, menacing "
?CND26:	PRINTI	"circles."
	CRLF	
	FSET?	PRSO,IDENTIFIED /TRUE
	FSET	PRSO,IDENTIFIED
	PRINT	TAB
	ICALL1	REFER-TO-PACKAGE
	RTRUE	
?CCL25:	EQUAL?	PRSA,V?WHAT,V?WHO \?CCL32
	ICALL1	REFER-TO-PACKAGE
	RETURN	2
?CCL32:	ZERO?	FEAR \?CND5
	EQUAL?	PRSA,V?HIT,V?MUNG,V?CUT /?CCL36
	EQUAL?	PRSA,V?KICK \?CND5
?CCL36:	FCLEAR	CORBIES,SEEN
	ICALL1	CTHE-PRINT
	PRINTR	" flutter out of your reach."
?CND5:	INTBL?	PRSA,TOUCHVERBS,NTOUCHES >X \FALSE
	ICALL1	CORBIES-STAY-AWAY
	RTRUE	


	.FUNCT	CORBIES-STAY-AWAY
	ICALL2	CTHE-PRINT,CORBIES
	ZERO?	BADKEY /?CND1
	LOC	BADKEY
	EQUAL?	STACK,PLAYER,HERE \?CND1
	FSET	CORBIES,SEEN
	PRINT	STR?619
	RTRUE	
?CND1:	FCLEAR	CORBIES,SEEN
	PRINTR	" easily swoop out of reach."


	.FUNCT	GRINDER-F,CONTEXT,X
	EQUAL?	CONTEXT,M-OBJDESC \?CCL3
	SET	'P-HIM-OBJECT,GRINDER
	ICALL2	PRINTCA,GRINDER
	PRINT	SIS
	FSET?	GRINDER,SURPRISED \?CND4
	PRINTI	"loafing nearby."
	RTRUE	
?CND4:	PRINTI	"attacking you with his "
	PRINTD	GURDY
	PRINTC	33
	RTRUE	
?CCL3:	EQUAL?	CONTEXT,M-CONT \?CCL7
	INTBL?	PRSA,TOUCHVERBS,NTOUCHES >X \FALSE
	ICALL2	CTHE-PRINT,GRINDER
	PRINTI	" slaps your hand away."
	RANDOM	100
	LESS?	50,STACK /?CND10
	PRINTR	" ""Touchy, touchy."""
?CND10:	CRLF	
	RTRUE	
?CCL7:	ZERO?	CONTEXT \FALSE
	ZERO?	NOW-PRSI? /?CCL15
	EQUAL?	PRSA,V?GIVE,V?GET-FOR \?CCL18
	ICALL2	GIVE-TO-GRINDER,PRSO
	RTRUE	
?CCL18:	EQUAL?	PRSA,V?SHOW \FALSE
	ICALL2	SHOW-TO-GRINDER,PRSO
	RTRUE	
?CCL15:	EQUAL?	PRSA,V?HELLO,V?WAVE-AT \?CCL21
	FSET	GRINDER,SEEN
	PRINTR	"""Hello, victim."""
?CCL21:	EQUAL?	PRSA,V?GOODBYE \?CCL23
	PRINTR	"""Heh heh heh."""
?CCL23:	INTBL?	PRSA,TALKVERBS,NTVERBS >X \?CCL25
	ICALL2	PERPLEXED,GRINDER
	PRINTI	"You babble of "
	ZERO?	PRSI /?CCL28
	FSET?	PRSI,LIVING /?CTR27
	FSET?	PRSI,MONSTER \?CCL28
?CTR27:	PRINTI	"be"
	JUMP	?CND26
?CCL28:	PRINTI	"th"
?CND26:	PRINTI	"ings of no significance to me!"""
	CRLF	
	RETURN	2
?CCL25:	EQUAL?	PRSA,V?EXAMINE \?CCL36
	ICALL1	DIAGNOSE-MONSTER
	FSET?	PRSO,TOUCHED /TRUE
	FSET	PRSO,TOUCHED
	PRINT	TAB
	ICALL1	REFER-TO-PACKAGE
	RTRUE	
?CCL36:	EQUAL?	PRSA,V?HIT,V?MUNG \?CCL40
	ICALL1	CTHE-PRINT
	PRINTI	" easily avoids "
	EQUAL?	PRSI,FALSE-VALUE,HANDS,FEET /?CCL42
	FSET?	PRSI,NOARTICLE /?CND41
?CCL42:	PRINTI	"your "
?CND41:	EQUAL?	PRSA,V?KICK /?CTR46
	EQUAL?	PRSI,FEET \?CCL47
?CTR46:	PRINTB	W?FOOT
	JUMP	?CND45
?CCL47:	EQUAL?	PRSI,FALSE-VALUE,HANDS \?CCL51
	PRINTB	W?BLOW
	JUMP	?CND45
?CCL51:	ICALL2	DPRINT,PRSI
?CND45:	PRINT	PERIOD
	RTRUE	
?CCL40:	EQUAL?	PRSA,V?WHAT,V?WHO \FALSE
	ICALL1	REFER-TO-PACKAGE
	RETURN	2


	.FUNCT	SOME,OBJ
	FSET?	OBJ,PLURAL \?CND1
	PRINTI	"some"
	RTRUE	
?CND1:	PRINTI	"one"
	RTRUE	


	.FUNCT	GIVE-TO-GRINDER,OBJ
	FSET	GRINDER,SEEN
	CALL	GIVING-LOOT?,OBJ,GRINDER
	ZERO?	STACK \TRUE
	EQUAL?	OBJ,CHEST \?CND1
	ICALL1	GRINDERS-BANE
	RTRUE	
?CND1:	PRINTI	"""If I wanted "
	ICALL2	PRINTA,OBJ
	PRINTI	", I'd steal "
	ICALL2	SOME,OBJ
	PRINT	PERQ
	RTRUE	


	.FUNCT	SHOW-TO-GRINDER,OBJ
	FSET	GRINDER,SEEN
	EQUAL?	OBJ,CHEST \?CND1
	ICALL2	GRINDERS-BANE,TRUE-VALUE
	RTRUE	
?CND1:	ICALL2	CTHE-PRINT,GRINDER
	PRINT	GLANCES-AT
	ICALL2	THE-PRINT,OBJ
	PRINTR	" and yawns conspicuously."


	.FUNCT	EXIT-GRINDER
	MOVE	GURDY,HERE
	SET	'GRTIMER,0
	ICALL2	KILL-MONSTER,GRINDER
	SET	'P-IT-OBJECT,GURDY
	BOR	NEW-DBOX,SHOWING-ALL >NEW-DBOX
	RFALSE	


	.FUNCT	GRINDERS-BANE,TAKIT,L
	LOC	CHEST >L
	MOVE	CHEST,AT-GATE
	PRINTI	"""A treasure chest!"" crows "
	ICALL2	THE-PRINT,GRINDER
	PRINTI	", snatching it "
	EQUAL?	L,PLAYER \?CCL3
	PRINTI	"rudely away from you"
	JUMP	?CND1
?CCL3:	ICALL2	OUT-OF-LOC,L
?CND1:	PRINTI	". ""I just "
	ICALL2	ITALICIZE,STR?676
	PRINTI	" surprises.""
  You wince as he taps on the outside of the chest, shakes it, then turns it upside down. Nothing happens. Then he places it on the ground, stares without comprehension at the brass plate, and cracks his knuckles"
	PRINT	PTAB
	ICALL2	DESCRIBE-GATE,GRINDER
	ICALL1	EXIT-GRINDER
	RTRUE	


	.FUNCT	DESCRIBE-URGRUE,OBJ
	ZERO?	LIT? \?CCL2
	CALL2	WEARING-MAGIC?,HELM
	ZERO?	STACK /?CND1
?CCL2:	PRINTD	OBJ
	RTRUE	
?CND1:	PRINTI	"voice"
	RTRUE	


	.FUNCT	URGRUE-F,CONTEXT,X
	ZERO?	CONTEXT \FALSE
	CALL	NOUN-USED?,W?URGRUE,W?UR-GRUE
	ZERO?	STACK /?CCL5
	ICALL1	PCLEAR
	PRINTI	"It is unwise to speak of such things."
	CRLF	
	ICALL	UPDATE-STAT,-1,LUCK,TRUE-VALUE
	RETURN	2
?CCL5:	ZERO?	NOW-PRSI? /?CCL9
	INTBL?	PRSA,PUTVERBS,NUMPUTS >X \?CCL12
	ICALL1	HOPELESS
	RTRUE	
?CCL12:	EQUAL?	PRSA,V?GIVE,V?SHOW,V?FEED \FALSE
	ICALL1	NO-INTS
	RTRUE	
?CCL9:	INTBL?	PRSA,TALKVERBS,NTVERBS >X \?CCL15
	ICALL1	NO-INTS
	RTRUE	
?CCL15:	EQUAL?	PRSA,V?HIT,V?MUNG,V?CUT \?CCL17
	ICALL1	HOPELESS
	RTRUE	
?CCL17:	EQUAL?	PRSA,V?EXAMINE,V?WHAT,V?WHO \FALSE
	ICALL1	REFER-TO-PACKAGE
	RETURN	2


	.FUNCT	HOPELESS
	PRINTR	"A feeling of utter hopelessness stays your hand."


	.FUNCT	NO-INTS
	ICALL1	PCLEAR
	PRINTI	"""Please don't interrupt my monologue,"" scolds the "
	ZERO?	LIT? \?CCL2
	CALL2	WEARING-MAGIC?,HELM
	ZERO?	STACK /?CND1
?CCL2:	PRINTD	URGRUE
	PRINT	PERIOD
	RTRUE	
?CND1:	PRINTR	"voice in the darkness."


	.FUNCT	XTREES-F,CONTEXT,X
	ZERO?	CONTEXT \FALSE
	ZERO?	NOW-PRSI? /?CCL5
	EQUAL?	PRSA,V?THROW,V?THROW-OVER \?CCL8
	ICALL1	V-THROW
	EQUAL?	PRSO,BFLY \TRUE
	IN?	PRSO,HERE \TRUE
	PRINT	TAB
	ICALL1	SHOW-XTREES-BFLY?
	RTRUE	
?CCL8:	EQUAL?	PRSA,V?SHOW,V?GIVE,V?GET-FOR \?CCL14
	EQUAL?	PRSO,BFLY \?CND15
	ICALL1	SHOW-XTREES-BFLY?
	RTRUE	
?CND15:	ICALL2	CTHE-PRINT,XTREES
	PRINTI	" show no interest in "
	ICALL1	THE-PRINT
	PRINT	PERIOD
	RTRUE	
?CCL14:	INTBL?	PRSA,PUTVERBS,NUMPUTS >X \FALSE
	ICALL1	CTHEI-PRINT
	PRINTR	" edge away from you."
?CCL5:	EQUAL?	PRSA,V?WAVE-AT,V?HELLO /?CTR18
	INTBL?	PRSA,TALKVERBS,NTVERBS >X \?CCL19
?CTR18:	ICALL1	PCLEAR
	ICALL2	CTHE-PRINT,XTREES
	PRINTI	" are too busy singing"
	PRINT	STR?657
	RETURN	2
?CCL19:	EQUAL?	PRSA,V?EXAMINE \?CCL25
	ICALL1	REFER-TO-PACKAGE
	RTRUE	
?CCL25:	EQUAL?	PRSA,V?LISTEN \?CCL27
	PRINTR	"Still singing."
?CCL27:	EQUAL?	PRSA,V?SMELL \?CCL29
	PRINTI	"The scent of pine"
	PRINT	STR?596
	PRINT	PERIOD
	RTRUE	
?CCL29:	EQUAL?	PRSA,V?HIT,V?MUNG,V?KICK \?CCL31
	PRINTR	"Sure. And even if you hit one tree, what about the thousands of others?"
?CCL31:	EQUAL?	PRSA,V?COUNT \?CCL33
	PRINTI	"A quick count reveals 69,105 "
	PRINTD	PRSO
	PRINT	PERIOD
	RTRUE	
?CCL33:	EQUAL?	PRSA,V?WHAT,V?WHO \?CCL35
	ICALL1	REFER-TO-PACKAGE
	RETURN	2
?CCL35:	EQUAL?	PRSA,V?LAMP-OFF \FALSE
	ICALL1	HOW?
	RTRUE	


	.FUNCT	SHOW-XTREES-BFLY?,INDENT
	FSET?	BFLY,MUNGED \?CTR2
	CALL2	VISIBLE?,BFLY
	ZERO?	STACK \?CCL3
?CTR2:	FSET	XTREES,SEEN
	ZERO?	INDENT /?CND6
	PRINT	TAB
?CND6:	ICALL2	CTHE-PRINT,XTREES
	PRINTR	" murmur with vague concern."
?CCL3:	FSET?	BFLY,LIVING /?CND1
	FSET	XTREES,SEEN
	ZERO?	INDENT /?CND9
	PRINT	TAB
?CND9:	ICALL2	CTHE-PRINT,XTREES
	PRINTI	" hesitate for a moment when they spot "
	ICALL2	THE-PRINT,BFLY
	PRINTR	". But as it isn't moving, they soon resume their song."
?CND1:	ZERO?	INDENT /?CND11
	PRINT	TAB
?CND11:	FSET	XTREES,SEEN
	ICALL2	CTHE-PRINT,XTREES
	FSET?	XTREES,NEUTRALIZED \?CND13
	PRINTR	" seem to have gotten over their initial shock. Their carolling proceeds with renewed joy and determination."
?CND13:	FSET	XTREES,NEUTRALIZED
	PRINTI	" stop dead in their tracks when they spot "
	ICALL2	THE-PRINT,BFLY
	PRINTI	". Youngsters take root behind their mothers, and the leaders sing an emergency verse of """
	CALL2	PICK-NEXT,CAROLS
	PRINT	STACK
	PRINT	PERQ
	RTRUE	


	.FUNCT	GRUE-F,CONTEXT,X
	ZERO?	CONTEXT \FALSE
	ZERO?	NOW-PRSI? /?CCL5
	EQUAL?	PRSA,V?THROW,V?THROW-OVER \FALSE
	ICALL1	MONSTER-THROW
	RTRUE	
?CCL5:	EQUAL?	PRSA,V?WHAT,V?WHO \?CCL9
	ICALL1	REFER-TO-PACKAGE
	RETURN	2
?CCL9:	IN?	GRUE,HERE /FALSE
	EQUAL?	PRSA,V?FIND,V?WHERE \?CCL15
	PRINTI	"There's probably one"
	PRINT	STR?677
	RTRUE	
?CCL15:	EQUAL?	PRSA,V?LISTEN \FALSE
	PRINTI	"Grues make no sound, but are always"
	PRINT	STR?677
	RTRUE	


	.FUNCT	ASUCKER-F,CONTEXT
	CALL2	HANDLE-SUCKERS?,ASUCKER
	RSTACK	


	.FUNCT	BSUCKER-F,CONTEXT
	CALL2	HANDLE-SUCKERS?,BSUCKER
	RSTACK	


	.FUNCT	CSUCKER-F,CONTEXT
	CALL2	HANDLE-SUCKERS?,CSUCKER
	RSTACK	


	.FUNCT	DESCRIBE-SUCKERS,OBJ
	GET	SUCKER-NAMES,THIS-SUCKER
	PRINT	STACK
	RTRUE	


	.FUNCT	HANDLE-SUCKERS?,OBJ,X
	CALL2	NOUN-USED?,W?INTNUM
	ZERO?	STACK /?CCL3
	EQUAL?	P-NUMBER,13 /?CCL3
	PRINT	CANT
	PRINTI	"see that number here."
	CRLF	
	RETURN	2
?CCL3:	ZERO?	NOW-PRSI? /?CCL9
	EQUAL?	PRSA,V?SHOW \?CCL12
	ICALL1	CTHEI-PRINT
	PRINTI	" seems "
	EQUAL?	PRSO,RFOOT,CLOVER,SHOE /?CND13
	PRINTI	"indifferent to "
	ICALL2	SAY-YOUR,PRSO
	PRINT	PERIOD
	RTRUE	
?CND13:	PRINTR	"to hesitate for a moment."
?CCL12:	EQUAL?	PRSA,V?THROW,V?THROW-OVER,V?TOUCH-TO \FALSE
	ICALL	TOUCH-SUCKER-WITH,OBJ,PRSO
	RTRUE	
?CCL9:	EQUAL?	PRSA,V?EXAMINE,V?LOOK-ON \?CCL17
	ICALL1	CTHE-PRINT
	PRINTR	" returns your stare."
?CCL17:	EQUAL?	PRSA,V?HIT,V?MUNG,V?CUT /?CTR18
	EQUAL?	PRSA,V?RIP,V?CUT,V?OPEN /?CTR18
	EQUAL?	PRSA,V?OPEN-WITH,V?KICK,V?STOUCH-TO \?CCL19
?CTR18:	ICALL	TOUCH-SUCKER-WITH,OBJ,PRSI
	RTRUE	
?CCL19:	INTBL?	PRSA,TOUCHVERBS,NTOUCHES >X \?CCL24
	ICALL	TOUCH-SUCKER-WITH,OBJ,HANDS
	RTRUE	
?CCL24:	EQUAL?	PRSA,V?WHAT,V?WHO \FALSE
	ICALL1	REFER-TO-PACKAGE
	RETURN	2


	.FUNCT	TOUCH-SUCKER-WITH,SUCKER,OBJ
	EQUAL?	OBJ,RFOOT,CLOVER,SHOE /?CND1
	EQUAL?	PRSA,V?THROW,V?THROW-OVER \?CND3
	MOVE	OBJ,HERE
	BOR	NEW-DBOX,SHOWING-ALL >NEW-DBOX
?CND3:	ICALL	PASSES-THROUGH,OBJ,SUCKER
	RTRUE	
?CND1:	ICALL2	VANISH,OBJ
	ICALL1	KERBLAM
	ICALL2	CTHE-PRINT,OBJ
	ICALL2	BLAST-SUCKER,SUCKER
	RTRUE	


	.FUNCT	BLAST-SUCKER,OBJ
	PUTP	OBJ,P?ENDURANCE,0
	PRINTR	" explodes in a shower of green sparks!"


	.FUNCT	DESCRIBE-WIGHT,OBJ
	PRINTB	W?SNOWDRIFT
	RTRUE	


	.FUNCT	START-WIGHT,X
	FSET	WIGHT,MONSTER
	FSET	WIGHT,LIVING
	FCLEAR	WIGHT,SURFACE
	FCLEAR	WIGHT,CONTAINER
	FCLEAR	WIGHT,OPENED
	ICALL	REPLACE-SYN?,WIGHT,W?DRIFT,W?MONSTER
	ICALL	REPLACE-SYN?,WIGHT,W?SNOWDRIFT,W?WIGHT
	ICALL2	QUEUE,I-WIGHT
	BOR	NEW-DBOX,SHOWING-ROOM >NEW-DBOX
	SET	'LAST-MONSTER,WIGHT
	SET	'LAST-MONSTER-DIR,P?SOUTH
	SET	'P-IT-OBJECT,WIGHT
	ICALL2	AS-YOU-APPROACH,WIGHT
	PUTP	WIGHT,P?SDESC,0
	PRINTI	"a pair of bloodstained claws swipes "
	PRINT	STR?668
	RTRUE	


	.FUNCT	WIGHT-F,CONTEXT,X
	ZERO?	CONTEXT /?CCL3
	EQUAL?	CONTEXT,M-OBJDESC \FALSE
	FSET?	WIGHT,MONSTER /?CND6
	ICALL2	PRINTCA,WIGHT
	PRINTI	" is blocking the uphill trail."
	RTRUE	
?CND6:	ICALL1	VIEW-MONSTER
	RTRUE	
?CCL3:	FSET?	WIGHT,MONSTER /?CND1
	INTBL?	PRSA,TOUCHVERBS,NTOUCHES >X \?CND1
	ICALL1	START-WIGHT
	RTRUE	
?CND1:	ZERO?	NOW-PRSI? /?CCL12
	EQUAL?	PRSA,V?THROW,V?THROW-OVER \FALSE
	ICALL1	MONSTER-THROW
	RTRUE	
?CCL12:	EQUAL?	PRSA,V?EXAMINE \FALSE
	ICALL1	CTHE-PRINT
	FSET?	PRSO,MONSTER \?CND17
	PRINTI	" is equipped with long, sharp teeth and claws, stained with the blood of its last encounter. "
	ICALL1	DIAGNOSE-MONSTER
	RTRUE	
?CND17:	ICALL1	HELMLOOK
	RTRUE	


	.FUNCT	SHAPE-F,CONTEXT,TBL,X
	ZERO?	CONTEXT /?CCL3
	EQUAL?	CONTEXT,M-OBJDESC \FALSE
	SET	'X,P?NW
?PRG6:	GETP	HERE,X >TBL
	ZERO?	TBL /?CND8
	GET	TBL,XDATA
	EQUAL?	STACK,OPLAIN /?REP7
?CND8:	IGRTR?	'X,P?NORTH \?PRG6
	RTRUE	
?REP7:	ICALL2	PRINTCA,SHAPE
	PRINTI	" is stretched across the "
	SUB	X,P?NORTH
	SUB	0,STACK
	GET	DIR-NAMES,STACK
	PRINTB	STACK
	PRINTI	" plane."
	RTRUE	
?CCL3:	ZERO?	NOW-PRSI? /?CCL14
	EQUAL?	PRSA,V?TOUCH-TO \?CCL17
	ICALL2	TOUCH-SHAPE-WITH,PRSO
	RTRUE	
?CCL17:	INTBL?	PRSA,PUTVERBS,NUMPUTS >X \?CCL19
	EQUAL?	PRSO,PHASE \?CND20
	ICALL1	CTHEI-PRINT
	PRINTI	" flexes away from "
	ICALL1	THE-PRINT
	PRINT	PERIOD
	RTRUE	
?CND20:	ICALL1	PRSO-SLIDES-OFF-PRSI
	RTRUE	
?CCL19:	EQUAL?	PRSA,V?LOOK-THRU \FALSE
	ICALL1	DISTORTED
	RTRUE	
?CCL14:	INTBL?	PRSA,E-VERBS,CLIMB-ON-VERBS >X \?CCL24
	ICALL1	CTHE-PRINT
	PRINTR	" flexes backwards and sideways, thwarting your best efforts."
?CCL24:	EQUAL?	PRSA,V?HIT,V?MUNG,V?CUT /?CTR25
	EQUAL?	PRSA,V?RIP,V?CUT,V?OPEN /?CTR25
	EQUAL?	PRSA,V?OPEN-WITH,V?KICK,V?STOUCH-TO \?CCL26
?CTR25:	ICALL2	TOUCH-SHAPE-WITH,PRSI
	RTRUE	
?CCL26:	INTBL?	PRSA,TOUCHVERBS,NTOUCHES >X \?CCL31
	ICALL2	TOUCH-SHAPE-WITH,HANDS
	RTRUE	
?CCL31:	EQUAL?	PRSA,V?EXAMINE,V?LOOK-ON \?CCL33
	PRINTI	"Looking directly at "
	ICALL1	THE-PRINT
	PRINTR	" makes your head ache."
?CCL33:	EQUAL?	PRSA,V?LOOK-UNDER,V?LOOK-BEHIND \FALSE
	ICALL1	DISTORTED
	RTRUE	


	.FUNCT	DISTORTED
	PRINTI	"The space beyond "
	ICALL2	THE-PRINT,SHAPE
	PRINTR	" appears hopelessly distorted."


	.FUNCT	TOUCH-SHAPE-WITH,OBJ
	EQUAL?	OBJ,PHASE /?CCL3
	ICALL	PASSES-THROUGH,OBJ,SHAPE
	RTRUE	
?CCL3:	IN?	OBJ,PLAYER /?CND1
	ICALL	YOUD-HAVE-TO,STR?680,OBJ
	RTRUE	
?CND1:	ICALL2	VANISH,SHAPE
	FCLEAR	SHAPE,LIVING
	SET	'LAST-MONSTER,FALSE-VALUE
	SET	'LAST-MONSTER-DIR,FALSE-VALUE
	ICALL1	HUMS
	PRINTI	"slashes effortlessly through "
	ICALL2	THE-PRINT,SHAPE
	PRINTI	". The torn edges recoil in agony, twist inside out and vanish in a toroid of collapsing geometry, leaving you with a clear path and a headache."
	CRLF	
	GETP	SHAPE,P?VALUE
	ICALL	UPDATE-STAT,STACK,EXPERIENCE
	RTRUE	

	.ENDI