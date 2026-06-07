#include "memory_slave.h"
void m_start(MemorySlave*slave,int address)
{
	int i;
	slave->address=address;//size =256 , its like an array of 256 size when initialiing it will have random value to make it 0 we are using it
	for(i=0;i<MEM_SIZE;i++)
	{
		slave->memory[i] = 0;//initialize to 0 
	}
}
I2C_STATUS m_write(MemorySlave*slave,int location,int data)
{
	if(location<0||location>=MEM_SIZE)
	{
		return I2C_ERROR;//gives error if memory location is invalid  or size not defined to 256
	}
	slave->memory[location] = data;
	return I2C_OK;//if sucessfull
}

int m_read(MemorySlave*slave,int location)
{
	if(location<0||location>=MEM_SIZE)
	{
	return -1;//if no location found
	}
	return slave->memory[location];//if found
}
