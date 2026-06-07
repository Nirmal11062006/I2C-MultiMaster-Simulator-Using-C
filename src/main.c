#include<stdio.h>
#include"i2c_bus.h"
#include"memory_slave.h"
#include"fifo_slave.h"
#include"lifo_slave.h"
#include"master.h"
#include"status.h"

int main()
{
	I2CBus bus;//it is in i2cbus.h
	MemorySlave mem;//it is in memslave.h
	FIFOSlave fifo;//it is in fifoslave.h
	LIFOSlave lifo;//it is in lifoslave.h
	Master master1;//it is in master.h
	Master master2;//it is in master.h
	Master *current_master;//pointer
	int choice;
	int master_choice;
	int location;
	int data;
	bus_start(&bus);//address of bus
	m_start(&mem,0x50);//address of memslave ,in real life the slave has physical adress so i am emulating it
	fifo_start(&fifo,0x60);//address of fifoslave ,in real life the slave has physical adress so i am emulating it
	lifo_start(&lifo,0x70);//address of lifoslave ,in real life the slave has physical adress so i am emulating it
	start_memoryslave(&bus,&mem);//connecting memslave to the bus
	start_fifoslave(&bus,&fifo);//connectng fifo slave to bus
	start_lifoslave(&bus,&lifo);//connecting lifoslave to bus
	master_start(&master1,1,&bus);//initialing master1
	master_start(&master2,2,&bus);//initializing master2
	while(1)
	{
		printf("\n----I2C SIMULATOR----\n");
		printf("1. Acquire Bus\n");
		printf("2. Release Bus\n");
		printf("3. Memory Write\n");
		printf("4. Memory Read\n");
		printf("5. FIFO Enqueue\n");
		printf("6. FIFO Dequeue\n");
		printf("7. LIFO Push\n");
		printf("8. LIFO Pop\n");
		printf("9. Bus Status\n");
		printf("10. Exit\n");
		printf("Enter Choice : ");
		scanf("%d",&choice);
		if(choice == 10)
		{
			printf("Exiting\n");
			return 0;
		}
		if(choice == 9)
		{
			printf("\nBus Busy:%d\n",bus.busy);
			printf("Current Master:%d\n",bus.current_master);
			continue;//goes to start of loop
		}
		printf("Select Master (1/2) : ");
		scanf("%d",&master_choice);
		if(master_choice == 1)
		{
			current_master = &master1;
		}
		else if(master_choice == 2)
		{
			current_master = &master2;
		}
		else
		{
			printf("Invalid Master\n");
			continue;//goes to the start of loop
		}
		I2C_STATUS status;
		switch(choice)
		{
			case 1:
				status = master_request(current_master);
				switch(status)
				{
					case I2C_OK:

						printf("Bus Acquired\n");
						break;
					case I2C_BUS_BUSY:
						printf("Bus Busy\n");
						break;
					case I2C_ARBITRATION_LOST:
						printf("Arbitration Lost\n");
						break;
					default:
						printf("Unknown Error\n");
				}
				break;
			case 2:
				if(bus.current_master==current_master->id)
				{
					master_release_bus(current_master);//releasing and making bus free
					printf("Bus Released\n");
				}
				else
				{
					printf("You do not own the bus\n");
				}
				break;
			case 3:
				if(bus.current_master!=current_master->id)
				{
					printf("Acquire Bus First\n");
					break;
				}
				printf("Location : ");
				scanf("%d",&location);
				printf("Data : ");
				scanf("%d",&data);
				if(master_memory_write(current_master,location,data)==I2C_OK)
				{
					printf("Write Successful\n");
				}
				else
				{
					printf("Write Failed\n");
				}
				break;
			case 4:
				if(bus.current_master!=current_master->id)
				{
					printf("Acquire Bus First\n");
					break;
				}
				printf("Location : ");
				scanf("%d",&location);
				data=master_memory_read(current_master,location);
				printf("Data = %d\n",data);
				break;
			case 5:
				if(bus.current_master != current_master->id)
				{
					printf("Acquire Bus First\n");
					break;
				}
				printf("Data : ");
				scanf("%d",&data);
				if(master_fifo_enqueue(current_master,data)==I2C_OK)
				{
					printf("Enqueue Successful\n");
				}
				else
				{
					printf("FIFO Full\n");
				}
				break;
			case 6:
				if(bus.current_master != current_master->id)
				{
					printf("Acquire Bus First\n");
					break;
				}
				data=master_fifo_dequeue(current_master);
				if(data==-1)
				{
					printf("FIFO Empty\n");
				}
				else
				{
					printf("Dequeued = %d\n",data);
				}
				break;
			case 7:
				if(bus.current_master != current_master->id)
				{
					printf("Acquire Bus First\n");
					break;
				}
				printf("Data : ");
				scanf("%d",&data);
				if(master_lifo_push(current_master,data) == I2C_OK)
				{
					printf("Push Successful\n");
				}
				else
				{
					printf("Stack Full\n");
				}
				break;
			case 8:
				if(bus.current_master != current_master->id)
				{
					printf("Acquire Bus First\n");
					break;
				}
				data = master_lifo_pop(current_master);
				if(data == -1)
				{
					printf("Stack Empty\n");
				}
				else
				{
					printf("Popped = %d\n",data);
				}
				break;
			default:
				printf("Invalid Choice\n");
				continue;
		}
	}
	return 0;
}
