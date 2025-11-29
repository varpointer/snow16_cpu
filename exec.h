#ifndef EXEC
#define EXEC

#include"register.h"
#include"opcode.h"
#include"memory.h"
#include<stdint.h>

enum execres{
    	EXEC_SUCCESS,
	EXEC_FAILURE
};


enum execres e_movl(uint16_t reg, uint16_t num){
	setreg((enum register_) reg, (getreg(reg) & 0xf0) | (num));
	return EXEC_SUCCESS;
} 

enum execres e_addl(uint16_t reg, uint16_t num){
	setreg((enum register_) reg, getreg(reg)+num);
	return EXEC_SUCCESS;
}

enum execres e_subl(uint16_t reg, uint16_t num){
	setreg((enum register_) reg, getreg(reg)-num);
	return EXEC_SUCCESS;
}


enum execres e_movh(uint16_t reg, uint16_t num){
	setreg((enum register_) reg, (getreg(reg) & 0x0f) | (num << 4));
	return EXEC_SUCCESS;
} 

enum execres e_addh(uint16_t reg, uint16_t num){
	setreg((enum register_) reg, getreg(reg)+(num << 4));
	return EXEC_SUCCESS;
}

enum execres e_subh(uint16_t reg, uint16_t num){
	setreg((enum register_) reg, getreg(reg)-(num << 4));
	return EXEC_SUCCESS;
}

enum execres e_addr(uint16_t reg1, uint16_t reg2){
	setreg((enum register_) reg1, getreg(reg1) + getreg(reg2));
	return EXEC_SUCCESS;
}

enum execres e_subr(uint16_t reg1, uint16_t reg2) {
	setreg((enum register_) reg1, getreg(reg1) - getreg(reg2));
	return EXEC_SUCCESS;
}

enum execres e_movr(uint16_t reg1, uint16_t reg2) {
	setreg((enum register_) reg1, getreg(reg2));
	return EXEC_SUCCESS;
}

#endif
