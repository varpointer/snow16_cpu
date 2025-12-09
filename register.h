#ifndef REGISTER
#define REGISTER

#include<stdint.h>

enum register_: uint16_t{
    	AX = 0x00, // 0x0
    	AH, // 0x1
    	AL, // 0x2
		BX, // 0x3
    	BH, // 0x4
    	BL, // 0x5
    	CX, // 0x6
    	CH, // 0x7
    	CL, // 0x8
    	DX, // 0x9
    	DH, // 0xA
		DL, // 0xB
		PC, // 0xC
    	FLAGSA, // 0xD
		FLAGSB, // 0xE
    	STACK, // 0xF
};

uint16_t ax = 0;
uint16_t bx = 0;
uint16_t cx = 0;
uint16_t dx = 0; 
uint16_t pc = 0; // Address of the current instruction
uint16_t flagsa = 0;
uint16_t flagsb = 0;
uint16_t stack = 0;  // Points to the next free spot on the stack

void setreg(enum register_ reg, uint16_t val){
	switch (reg){
		case AX:
			ax = val;
			break;
		case BX:
			bx = val;
			break;
		case CX:
			cx = val;
			break;
		case DX:
			dx = val;
			break;
		case STACK:
			stack = val;
			break;
		case FLAGSA:
			flagsa =  val;
			break;
		case FLAGSB:
			flagsb = val;
			break;
		case PC:
			pc = val;
			break;
		case AL:
			ax = (ax & 0xff00) | (val & 0x00ff);
			break;
		case BL:
			bx = (bx & 0xff00) | (val & 0x00ff);
			break;
		case CL:
			cx = (cx & 0xff00) | (val & 0x00ff);
			break;
		case DL:
			dx = (dx & 0xff00) | (val & 0x00ff);
			break;
		case AH:
			ax = ((val & 0x00ff) << 8) | (ax & 0x00ff);
			break;
		case BH:
			bx = ((val & 0x00ff) << 8) | (bx & 0x00ff);
			break;
		case CH:
			cx = ((val & 0x00ff) << 8) | (cx & 0x00ff);
			break;
		case DH:
			dx = ((val & 0x00ff) << 8) | (dx & 0x00ff);
			break;
	}
}

uint16_t getreg(enum register_ reg){
	switch (reg){
		case AX:
			return ax;
		case BX:
			return bx;
		case CX:
			return cx;
		case DX:
			return dx;
		case STACK:
			return stack;
		case FLAGSA:
			return flagsa;
		case FLAGSB:
			return flagsb;
		case PC:
			return pc;
		case AL:
			return ax & 0x00ff;
		case BL:
			return bx & 0x00ff;
		case CL:
			return cx & 0x00ff;
		case DL:
			return dx & 0x00ff;
		case AH:
			return (ax & 0xff00) >> 8;
		case BH:
			return (bx & 0xff00) >> 8;
		case CH:
			return (cx & 0xff00) >> 8;
		case DH:
			return (dx & 0xff00) >> 8;
	}
}

#endif
