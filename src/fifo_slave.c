#include "fifo_slave.h"
void fifo_start(FIFOSlave*fifo,int address)
{
	fifo->address=address;//slave address in I2C real life implementation
	fifo->front=0;
	fifo->rear=-1;
	fifo->count=0;//initial values
}
I2C_STATUS enqueue(FIFOSlave*fifo,int data)
{
	if(fifo->count==SIZE)
	{
		return I2C_FIFO_FULL;//queue full
	}
	fifo->rear=(fifo->rear+1)%SIZE;//adding a rear node//eg(0+1)%5=1
	fifo->buffer[fifo->rear]=data;//storing data at the last node
	fifo->count++;//counting it
	return I2C_OK;
}

int dequeue(FIFOSlave*fifo)
{
	int data;
	if(fifo->count==0)
	{
		return -1;
	}
	data=fifo->buffer[fifo->front];//geting the data first
	fifo->front=(fifo->front+1)%SIZE;// removing the first naode
	fifo->count--;//removing count by 1
	return data;
}
