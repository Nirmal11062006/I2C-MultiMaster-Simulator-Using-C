#include<stddef.h>
#include "master.h"
void master_start(Master*master,int id,I2CBus*bus)
{
	master->id=id;
	master->bus=bus;
}
I2C_STATUS master_request(Master*master)
{
	if(master->bus->busy)
	{
		if(master->id > master->bus->current_master)//if master id is differnt from current master the approaching master will lose arbitation
		{
			return I2C_ARBITRATION_LOST;
		}

		return I2C_BUS_BUSY;//bus busy already another bus using
	}

	master->bus->busy=1;//now the master takes the bus and gives signal busy
	master->bus->current_master=master->id;//current master id
	return I2C_OK;
}
void master_release_bus(Master*master)
{
	master->bus->busy=0;//releasing and making bus free , so new master can use it
	master->bus->current_master=-1;// master id 
}
I2C_STATUS master_memory_write(Master*master,int location,int data)
{
	if(master->bus->memory_slave==NULL)//checks if slave is connected
	{
		return I2C_ERROR;//ch
	}
	return m_write(master->bus->memory_slave,location,data);// this function in mem_slave.c
}
int master_memory_read(Master*master,int location)
{
	if(master->bus->memory_slave==NULL)
	{
		return -1;//check if slave is connected
	}
	return m_read(master->bus->memory_slave,location);//this function in mem_slave.c
}
I2C_STATUS master_fifo_enqueue(Master*master,int data)
{
	if(master->bus->fifo_slave==NULL)
	{
		return I2C_ERROR;//check is slave is connected
	}
	return enqueue(master->bus->fifo_slave,data);//this function is in fifoslave.c
}

int master_fifo_dequeue(Master*master)
{
	if(master->bus->fifo_slave == NULL)
	{
		return -1;//check if  slave is connected
	}
	return dequeue(master->bus->fifo_slave);//this function is in fifoslave.c
}
I2C_STATUS master_lifo_push(Master*master,int data)
{
	if(master->bus->lifo_slave == NULL)
	{
		return I2C_ERROR;//check if slave is connected
	}
	return push(master->bus->lifo_slave,data);//this function is in lifoslave.c
}

int master_lifo_pop(Master*master)
{
	if(master->bus->lifo_slave == NULL)
	{
		return -1;//check if slave is connected
	}
	return pop(master->bus->lifo_slave);//this function is in lifoslave.c
}
