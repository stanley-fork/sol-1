#include <stdio.h>


int main(){

}

/*
During the Command or Result phases, the Main
Status Register must be read by the processor
before each byte of information is written into or
read from the Data Register. After each byte of
data is read from or written into the Data Register,
the CPU waits for 12us before reading the Main
Status Register. BitsD6 and D7 in the Main
Status Register must be in a 0 and 1 state,
respectively, before each byte of the command
word may be written into the WD37C65C. Many of
the commands require multiple bytes. As a result,
the Main Status Register must be read prior to
each byte transfer to the WD37C65C. During the
Result phase, Bits D6 and D7 in the Main Status
Register must both be 1's (D6=1 and D!=1)
before reading each byte from the Data Register.
Note that this reading of the Main Status Register
before each byte transfer to the WD37C65C is
required only in the Command and Result
phases, and not during the Execution phase.

Note that in PC AT usage, non-DMA Host trans-
fers are not the normal procedure. If the user
chooses to do so, the WD37C65C will successfully 
complete commands, but will always give ab-
normal termination error status since TC is
qualified by an inactive DACK.

If the non-DMA mode is
chosen, the DACK signal should be pulled up to
Vcc.

Note that during the Result phase all bytes
shown in the Command Table must be read. The
Read Data Command, for example, has several
bytes of data in the Result phase. All seven bytes
must be read in order to successfully complete
the Read Data command. The WD37C65C will
not accept a new command until all seven bytes
have been read. Other commands may require
fewer bytes to be read during the Result phase.

The WD37C65C contains five Status Registers.
The Main Status Register mentioned may be read
by the processor at any time. The other four
Status Registers (STO, ST1, ST2, and ST3) are
available only during the Result phase and may
be read only afler completing a command. The ~
particular command that has been executed . .
determines how many of the Status Registers will
be read.

The bytes of data which are sent to the
WD37C65C to form the Command phase, and are
read out of the WD37C65C in the Result phase,
must occur in the order shown in the Command
Table. The command code must be sent first and
the other bytes sent in the prescribed sequence.
No foreshortening of the Command or Result
phases is allowed. After the last byte of data in the
Command phase is sent to the WD37C65C, the
Execution phase automatically starts. In a similar
fashion, when the last byte of data is read out in
the Result phase, the command is automatically
ended and the WD37C65C is ready for a new
command.
*/