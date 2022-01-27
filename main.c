/*
 * Sprint6_COMM.c
 *
 * Created: 1/24/2022 8:04:48 PM
 * Author : No. 01
 */ 

#include "./01-LIB/STD_types.h"
#include "./01-LIB/Registers.h"
#include "./02-MCAL/UART/UART_interface.h"
#include <string.h>

int main(void)
{
	uint8_t u8_val[255];
	UART_init();
	PORTB_DIR=(1<<4)|(1<<5)|(1<<6);
    /* Replace with your application code */
    while (1) 
    {
		UART_sendString("ENTER A STRING : ");
		UART_receiveString(u8_val);
		UART_sendString(u8_val);
		if(strcmp(u8_val,"START")==0)
		{
			PORTB_DATA=1<<4;
		}
		else if(strcmp(u8_val,"WAIT")==0)
		{
			PORTB_DATA=1<<5;
		}
		else if(strcmp(u8_val,"STOP")==0)
		{
			PORTB_DATA=1<<6;
		}
		else if(strcmp(u8_val,"AT")==0)
		{
			UART_sendChar('\n');
			UART_sendChar('\r');
			UART_sendString("OK");
		}
		else
		{
			PORTB_DATA=0;
		}
		UART_sendChar('\n');
		UART_sendChar('\r');
    }
}

