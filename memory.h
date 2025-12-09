#ifndef MEMORY
#define MEMORY

#include<stdint.h>
#define MEMSIZE 65535

uint8_t memory[MEMSIZE];

void setword(uint16_t, uint16_t);

void setmemory16(uint16_t src[MEMSIZE/2]){
	for (int i = 0; i < MEMSIZE/2; i++){
		setword(i*2, src[i]);
	}
}

void setword(uint16_t addr, uint16_t value){
	int lower = value & 0x00ff;
	int upper = (value & 0xff00) >> 8;
	memory[addr] = upper;
	memory[addr+1] = lower;
}

uint16_t getword(uint16_t addr){
	return (memory[addr] << 8) | memory[addr+1];
}

#endif
