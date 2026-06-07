#include"lifo_slave.h"
void lifo_start(LIFOSlave*lifo,int address)
{
	lifo->address=address;//slave address used in real life I2C
	lifo->top=-1;//initial value
}

I2C_STATUS push(LIFOSlave*lifo,int data)
{
	if(lifo->top==LIFO_SIZE-1)
	{
		return I2C_LIFO_FULL;//check if stack full
	}
	lifo->top++;
	lifo->stack[lifo->top]=data;//pushing the data
	return I2C_OK;
}
int pop(LIFOSlave*lifo)
{
	int data;
	if(lifo->top==-1)
	{
	return -1;//if empty
	}
	data=lifo->stack[lifo->top];//retrive the data
	lifo->top--;//remove the top layer
	return data;
}
