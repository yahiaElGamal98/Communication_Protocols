/*
 * Sprint6_COMM.c
 *
 * Created: 1/24/2022 8:04:48 PM
 * Author : No. 01
 */ 

#include "./01-LIB/STD_types.h"
#include "./01-LIB/Registers.h"
#include "./03-HAL/LED/LED.h"
#include "./02-MCAL/UART/UART_interface.h"
#include <string.h>

int main(void)
{
	uint8_t u8_val[255];
	UART_init();
	LED_init(LED0);
	LED_init(LED1);
	LED_init(LED2);
    /* Replace with your application code */
    while (1) 
    {
		UART_sendString("ENTER A COMMAND : ");
		UART_receiveString(u8_val);
		UART_sendString(u8_val);
		if(strcmp(u8_val,"START")==0)
		{
			LED_ON(LED0);
			LED_OFF(LED1);
			LED_OFF(LED2);
			UART_sendChar('\n');
			UART_sendChar('\r');
			UART_sendString("LED 0 IS ON");
			
		}
		else if(strcmp(u8_val,"WAIT")==0)
		{
			LED_ON(LED1);
			LED_OFF(LED0);
			LED_OFF(LED2);
			UART_sendChar('\n');
			UART_sendChar('\r');
			UART_sendString("LED 1 IS ON");
		}
		else if(strcmp(u8_val,"STOP")==0)
		{
			LED_ON(LED2);
			LED_OFF(LED1);
			LED_OFF(LED0);
			UART_sendChar('\n');
			UART_sendChar('\r');
			UART_sendString("LED 2 IS ON");
		}
		else if(strcmp(u8_val,"AT")==0)
		{
			UART_sendChar('\n');
			UART_sendChar('\r');
			UART_sendString("OK");
		}
		else
		{
			LED_OFF(LED2);
			LED_OFF(LED1);
			LED_OFF(LED0);
		}
		UART_sendChar('\n');
		UART_sendChar('\r');
    }
}

