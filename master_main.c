/*
 * Sprint6_COMM.c
 *
 * Created: 1/24/2022 8:04:48 PM
 * Author : No. 01
 */ 

#include "./01-LIB/STD_types.h"
#include "./03-HAL/EEPROM/EEPROM.h"
#include "./03-HAL/Terminal/Terminal.h"
#include <string.h>
#include <stdlib.h>

#define EEPROM_ADDR (0xA0)

#define DATA_ADDR (0x1000)
#define FOUND 0


int main(void)
{
	uint8_t u8_send;
	uint8_t u8_retData;
	uint8_t au8_address[6];
	uint16_t u16_address;
	uint8_t au8_command[10];
	TERMINAL_init();
	EEPROM_init(EEPROM_ADDR);
    /* Replace with your application code */
	while (1) 
    {
		TERMINAL_write("Enter a command (READ) OR (WRITE)");
		TERMINAL_newLine();
		TERMINAL_read(au8_command);
		if(FOUND==strcmp(au8_command,"READ"))
		{
			TERMINAL_write("OK");
			TERMINAL_newLine();
			TERMINAL_write("Enter read address : ");
			TERMINAL_read(au8_address);
			TERMINAL_newLine();
			u16_address=atoi(au8_address);
			TERMINAL_write("OK");
			TERMINAL_newLine();
			EEPROM_read(EEPROM_ADDR,u16_address,&u8_retData);
			TERMINAL_write("DATA Returned is : ");
			TERMINAL_writeChar(u8_retData);
			TERMINAL_newLine();
		}
		else if (FOUND==strcmp(au8_command,"WRITE"))
		{
			TERMINAL_write("OK");
			TERMINAL_newLine();
			TERMINAL_write("Enter write address : ");
			TERMINAL_read(au8_address);
			TERMINAL_newLine();
			u16_address=atoi(au8_address);
			TERMINAL_write("OK");
			TERMINAL_newLine();
			TERMINAL_write("Enter Data : ");
			TERMINAL_readChar(&u8_send);
			TERMINAL_newLine();
			EEPROM_write(EEPROM_ADDR,u16_address,u8_send);
			TERMINAL_write("OK,Done");
			TERMINAL_newLine();
		}
    }
}
