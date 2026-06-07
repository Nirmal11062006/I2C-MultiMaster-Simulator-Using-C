#ifndef MEMORY_SLAVE_H
#define MEMORY_SLAVE_H
#define MEM_SIZE 256
#include"status.h"
typedef struct
{
	int address;
	int memory[MEM_SIZE];
}MemorySlave;
void m_start(MemorySlave*slave,int address);
I2C_STATUS m_write(MemorySlave*slave,int location,int data);// we use the return type in the in the enum specified
int m_read(MemorySlave*slave,int location);
#endif
