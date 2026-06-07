#ifndef FIFO_SLAVE_H
#define FIFO_SLAVE_H
#define SIZE 64
#include"status.h"
typedef struct
{
	int address;
	int front;
	int rear;
	int count;
	int buffer[SIZE];
}FIFOSlave;
void fifo_start(FIFOSlave*fifo,int address);
I2C_STATUS enqueue(FIFOSlave*fifo,int data);
int dequeue(FIFOSlave*fifo);
#endif
