#include<stdio.h>
#include"cpu.h"
#include"version.h"

int main(){
	printf("Arch: snow16, CPU v%d.%d.%d\n", VERSION_MAJOR, VERSION_MINOR, VERSION_PATCH);
	uint16_t code[MEMSIZE/2] = {0x0d00, 0x4a12, 0x0700};
	setmemory16(code);
	exec();
	printf("AX:%x\n", ax);
	printf("BX:%x\n", bx);
	printf("CX:%x\n", cx);
	printf("DX:%x\n", dx);
	printf("PC:%x\n", pc);
	printf("FLAGSA:%x\n", flagsa);
	printf("FLAGSB:%x\n", flagsb);
	printf("STACK:%x\n", stack);
	return 0;
}
