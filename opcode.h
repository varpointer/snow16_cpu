#ifndef OPCODE
#define OPCODE

enum opcode{
    	VOID, // 0x00
    	ADDR, // 0x01
    	ADDL, // 0x02
    	SUBR, // 0x03
    	SUBL, // 0x04
    	MOVR, // 0x05
    	MOVL, // 0x06
	ENDX, // 0x07
	ADDH, // 0x08
	SUBH, // 0x09
	MOVH, // 0x0A
	ADDN, // 0x0B
	SUBN, // 0x0C
	MOVN, // 0x0D
};

#endif
