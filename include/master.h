#ifndef MASTER_H
#define MASTER_H
#include"i2c_bus.h"
#include"status.h"
typedef struct
{
	int id;
	I2CBus *bus;
}Master;
void master_start(Master *master,int id,I2CBus *bus);
I2C_STATUS master_request(Master *master);
void master_release_bus(Master *master);
I2C_STATUS master_memory_write(Master *master,int location,int data);
int master_memory_read(Master *master,int location);
I2C_STATUS master_fifo_enqueue(Master *master,int data);
int master_fifo_dequeue(Master *master);
I2C_STATUS master_lifo_push(Master *master,int data);
int master_lifo_pop(Master *master);
#endif
