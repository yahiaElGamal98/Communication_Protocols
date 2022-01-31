/*
 * Sprint6_COMM.c
 *
 * Created: 1/24/2022 8:04:48 PM
 * Author : No. 01
 */ 

#include "./01-LIB/STD_types.h"
#include "./02-MCAL/SPI/SPI_interface.h"
#include "./02-MCAL/UART/UART_interface.h"

//void msdelay(uint8_t u8_time);

int main(void)
{
	uint8_t u8_val[255];
	SPI_masterInit();
	UART_init();
    /* Replace with your application code */
    while (1) 
    {
		UART_receiveString(u8_val);
		UART_sendString(u8_val);
		SPI_masterTransmitString(u8_val);
	}
	return 0;
}

