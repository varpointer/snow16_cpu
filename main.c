#include<stdio.h>
#include"cpu.h"

int main(){
	uint16_t code[MEMSIZE] = {0x0a26, 0x0251, 0x0552, 0x0700};
	setmemory(code);
	exec();
	return 0;
}
