#ifndef LIFO_SLAVE_H
#define LIFO_SLAVE_H
#include"status.h"
#define LIFO_SIZE 64
typedef struct
{
	int address;
	int top;
	int stack[LIFO_SIZE];
}LIFOSlave;
void lifo_start(LIFOSlave*lifo,int address);
I2C_STATUS push(LIFOSlave*lifo,int data);
int pop(LIFOSlave*lifo);
#endif
