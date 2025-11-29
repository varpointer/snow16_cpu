# snow16
A 16-bit CPU emulator running its own architecture, known as `snow16`.

Loads 2 bytes / 1 word at a time, with each instruction fitting in 1 word (but some may use 2 words instead.).\
Operators use up the first byte (8 bits) of an instruction.

INCOMPLETE

## instruction set
Syntax: `0xOPCODE` `NAME argument.type 0xCONSTANT`\
if the argument is an integer, the type will be its bitsize.
### `0x00` `VOID 0x00`
Does literally nothing.
### `0x01` `ADDR reg1.reg reg2.reg`
Adds `reg2` to `reg1` and stores the result in `reg1`
### `0x02` `ADDL reg.reg val.4`
Adds `val` to the first 4 bits of `reg`
