#include "register.h"
#include "opcode.h"
#include "memory.h"
#include<stdint.h>
#include<stdio.h>
#include "exec.h"

uint16_t getinstr(){
    	return memory[pc];
}
void next(){++pc;}

uint16_t execinstr(){ // 0: success, 1: exit, 2: error
	uint16_t instr = getinstr();
	uint16_t operator, operand;
	operator = (0xff00 & instr) >> 8;
	operand = instr & 0x00ff;
	switch (operator){
                case VOID: 
			break;
		case ADDR:
			e_addr((0xf0 & operand) >> 4, (0x0f) & operand);
			break;
		case ADDL:
			e_addl((0xf0 & operand) >> 4, (0x0f) & operand);
			break;
		case SUBR:
			e_subr((0xf0 & operand) >> 4, (0x0f) & operand);
			break;
		case SUBL:
			e_subl((0xf0 & operand) >> 4, (0x0f) & operand);
			break;
		case MOVR:
			e_movr((0xf0 & operand) >> 4, (0x0f) & operand);
			break;
		case MOVL:
			e_movl((0xf0 & operand) >> 4, (0x0f) & operand);
			break;
		case ENDX:
			return 1;
		case ADDH:
			e_addh((0xf0 & operand) >> 4, (0x0f) & operand);
			break;
		case SUBH:
			e_subh((0xf0 & operand) >> 4, (0x0f) & operand);
			break;
		case MOVH:
			e_movh((0xf0 & operand) >> 4, (0x0f) & operand);
			break;
		default:
			printf("INVALID OPERATOR: %x\n", operator);
			return 2;
	}
	return 0;
}

void exec(){
	uint16_t res;
	while(pc < MEMSIZE){
		res = execinstr();
		if (res == 1) 
			break;
		if (res == 2)
			printf("Execution stopped due to an error.\n");
		next();
	}
	printf("AX:%x\n", ax);
	printf("BX:%x\n", bx);
	printf("CX:%x\n", cx);
	printf("DX:%x\n", dx);
	printf("PC:%x\n", pc);
	printf("FLAGSA:%x\n", flagsa);
	printf("FLAGSB:%x\n", flagsb);
	printf("STACK:%x\n", stack);
}
