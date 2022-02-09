/*
 * Sprint6_COMM.c
 *
 * Created: 1/24/2022 8:04:48 PM
 * Author : No. 01
 */ 

#include "./01-LIB/STD_types.h"
#include "./02-MCAL/I2C/I2C_interface.h"

#define SLAVE_ADD 0x10
void msdelay(uint16_t u16_time);
int main(void)
{
	uint8_t u8_send;
	I2C_init();
	
    /* Replace with your application code */
    while (1) 
    {
		I2C_masterStartWrite(SLAVE_ADD);
		I2C_masterSendData(u8_send);
		I2C_stop();
		msdelay(1000);
    }
}
void msdelay(uint16_t u16_time)
{
	volatile uint16_t u16_index;
	volatile uint8_t u8_index;
	for(u16_index=0;u16_index<u16_time;u16_index++)
	{
		for(u8_index=0;u8_index<450;u8_index++);
	}
	
}
