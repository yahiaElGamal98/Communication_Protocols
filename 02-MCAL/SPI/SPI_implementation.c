/*
 * SPI_implementation.c
 *
 * Created: 1/25/2022 9:22:42 PM
 *  Author: No. 01
 */ 
#include "../../01-LIB/STD_types.h"
#include "../../01-LIB/Registers.h"
#include "SPI_config.h"
#include "SPI_interface.h"

void SPI_masterInit()
{
	SPI_DDR|= (HIGH<<MOSI) | (HIGH<<SCK) |(HIGH<<SS);
	SPI_DDR&= ~(HIGH<<MISO);
	SPI_PORT|=(HIGH<<SS);
	SPCR = (HIGH<<SPE) | (HIGH<<MSTR) | (SPI_MODE<<CPHA) | (SPI_CR<<SPR0);
}
void SPI_slaveInit()
{
	SPI_DDR |= (HIGH<<MISO);
	SPI_DDR &=~((HIGH<<MOSI)|(HIGH<<SCK)|(HIGH<<SS));
	SPCR = HIGH<<SPE;
}
void SPI_masterTransmit(uint8_t u8_data)
{
	SPI_PORT&=~(HIGH<<SS);
	uint8_t u8_flushHelper;
	SPDR=u8_data;
	while(LOW==((SPSR&(HIGH<<SPIF))>>SPIF));
	u8_flushHelper=SPDR;
	SPI_PORT|=(HIGH<<SS);
}
void SPI_slaveReceive(uint8_t * pu8_data)
{
	SPDR=0xFF;
	while(LOW==((SPSR&(HIGH<<SPIF))>>SPIF));
	*pu8_data=SPDR;
}