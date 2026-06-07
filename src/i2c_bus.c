#include<stddef.h>
#include "i2c_bus.h"
void bus_start(I2CBus*bus)
{
	bus->sda=1;
	bus->scl=1;
	bus->busy=0;
	bus->current_master=-1;
	bus->memory_slave=NULL;
	bus->fifo_slave=NULL;
	bus->lifo_slave=NULL;
}
void start_memoryslave(I2CBus*bus,MemorySlave*slave)
{
	bus->memory_slave=slave;//store the address of memsave in bus
}
void start_fifoslave(I2CBus*bus,FIFOSlave*slave)
{
	bus->fifo_slave=slave;// store the address of fifo in bus
}

void start_lifoslave(I2CBus*bus,LIFOSlave*slave)
{
	bus->lifo_slave=slave;//store the address of lifo in bus
}
