#ifndef I2C_BUS_H
#define I2C_BUS_H
#include"memory_slave.h"
#include"fifo_slave.h"
#include"lifo_slave.h"
typedef struct
{
	int sda;
	int scl;
	int busy;
	int current_master;
	MemorySlave *memory_slave;
	FIFOSlave *fifo_slave;
	LIFOSlave *lifo_slave;
}I2CBus;
void bus_start(I2CBus*bus);
void start_memoryslave(I2CBus*bus,MemorySlave*slave);
void start_fifoslave(I2CBus *bus,FIFOSlave *slave);
void start_lifoslave(I2CBus *bus,LIFOSlave *slave);
#endif
