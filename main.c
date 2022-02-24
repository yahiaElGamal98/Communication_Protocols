/*
 * Sprint6_COMM.c
 *
 * Created: 1/24/2022 8:04:48 PM
 * Author : No. 01
 */ 

#include "./01-LIB/STD_types.h"
#include "./03-HAL/LED/LED.h"
#include "./02-MCAL/UART/UART_interface.h"
#include <string.h>

int main(void)
{
	uint8_t u8_val[255];
	void *ptr =NULL_PTR;
	ptr=u8_val;
	UART_init();
	LED_init(LED0);
	LED_init(LED1);
	LED_init(LED2);
    /* Replace with your application code */
    while (1) 
    {
		UART_sendString((void*)("ENTER A COMMAND : "));
		UART_receiveString(ptr);
		UART_sendString(ptr);
		if(strcmp((const char*)ptr,(const char*)("START"))==0)
		{
			LED_ON(LED0);
			LED_OFF(LED1);
			LED_OFF(LED2);
			UART_sendChar('\n');
			UART_sendChar('\r');
			UART_sendString((void*)("LED 0 IS ON"));	
		}
		else if(strcmp((const char *)ptr,"WAIT")==0)
		{
			LED_ON(LED1);
			LED_OFF(LED0);
			LED_OFF(LED2);
			UART_sendChar('\n');
			UART_sendChar('\r');
			UART_sendString((void*)"LED 1 IS ON");
		}
		else if(strcmp((const char *)ptr,"STOP")==0)
		{
			LED_ON(LED2);
			LED_OFF(LED1);
			LED_OFF(LED0);
			UART_sendChar('\n');
			UART_sendChar('\r');
			UART_sendString((void*)"LED 2 IS ON");
		}
		else if(strcmp((const char *)u8_val,"AT")==0)
		{
			UART_sendChar('\n');
			UART_sendChar('\r');
			UART_sendString((void*)"OK");
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

