# snow16
A 16-bit CPU emulator running its own architecture, known as `snow16`.

Loads 2 bytes / 1 word at a time, with each instruction fitting in 1 word (but some may use 2 words instead.).\
Operators use up the first byte (8 bits) of an instruction.

INCOMPLETE

## instruction set
Syntax: `0xOPCODE` `NAME argument.type .type`\
if the argument is an integer, the type will be its bitsize. Any arguments that are ignored are left unnamed
### `0x00` `VOID .8`
Does literally nothing.
### `0x01` `ADDR reg1.reg reg2.reg`
Adds `reg2` to `reg1` and stores the result in `reg1`
### `0x02` `ADDL reg.reg val.4`
Adds `val` to `reg`
### `0x03` `SUBR reg1.reg reg2.reg`
Subtracts `reg2` from `reg`
### `0x04` `SUBL reg.reg val.4`
Subtracts `val` from `reg`
### `0x05` `MOVR reg1.reg reg2.reg`
Places the value of `reg2` in `reg`
### `0x06` `MOVL reg.reg val.4`
Assigns `val` to the first 4 bits of `reg`
### `0x07` `ENDX .8`
Ends execution
### `0x08` `ADDH reg.reg val.4`
Adds `val` leftshifted by 4 bits to `reg`
### `0x09` `SUBH reg.reg val.4`
Subtracts `val` leftshifted by 4 bits from `reg`
### `0x0A` `MOVH reg.reg val.4`
Assigns `val` to the 5-8th bits from the bottom of `reg`
