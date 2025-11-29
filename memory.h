#ifndef MEMORY
#define MEMORY

#include<stdint.h>
#define MEMSIZE 65535

uint16_t memory[MEMSIZE];

void setmemory(uint16_t src[MEMSIZE]){
	for (int i = 0; i < MEMSIZE; i++){
		memory[i] = src[i];
	}
}

#endif
