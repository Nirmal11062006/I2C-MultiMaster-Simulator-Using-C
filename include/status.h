#ifndef STATUS_H
#define STATUS_H
typedef enum//integer constants =enum
{
	I2C_OK=0,//operation sucessfull
	I2C_ERROR=1,//error occured
	I2C_BUS_BUSY=2,//currently a different master is using the bus
	I2C_INVALID_ADDRESS=3,//invalid address
	I2C_NACK=4,// not acknowledged
	I2C_FIFO_FULL=5,//queue full
	I2C_FIFO_EMPTY=6,// queue empty
	I2C_LIFO_FULL=7,//stack full
	I2C_LIFO_EMPTY=8,//stack empty
	I2C_ARBITRATION_LOST=9//if a master loses arbitration
}I2C_STATUS;
#endif
