/*
 * Sprint6_COMM.c
 *
 * Created: 1/24/2022 8:04:48 PM
 * Author : No. 01
 */ 

#include "./01-LIB/STD_types.h"
#include "./02-MCAL/UART/UART_interface.h"

int main(void)
{
	uint8_t u8_send;
	uint8_t u8_receive;
	UART_init();
    /* Replace with your application code */
    while (1) 
    {
		UART_receiveChar(&u8_send);
		UART_sendChar(u8_send);
    }
}

