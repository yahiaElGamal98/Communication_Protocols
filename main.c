/*
 * Sprint6_COMM.c
 *
 * Created: 1/24/2022 8:04:48 PM
 * Author : No. 01
 */ 

#include "./01-LIB/STD_types.h"
#include "./01-LIB/Registers.h"
#include "./02-MCAL/SPI/SPI_config.h"
#include "./02-MCAL/SPI/SPI_interface.h"

int main(void)
{
	uint8_t u8_val=0xf8;
	SPI_masterInit();
	//SPI_slaveInit();
	//PORTA_DIR=0xFF;
    /* Replace with your application code */
    while (1) 
    {
		//SPI_slaveReceive(&u8_val);
		//PORTA_DATA=u8_val;
		SPI_masterTransmit(u8_val);
		//UART_receiveChar(&u8_val);
		//UART_sendChar(u8_val);
    }
}

