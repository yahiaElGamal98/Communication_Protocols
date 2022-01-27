/*
 * SPI_implementation.c
 *
 * Created: 1/25/2022 9:22:42 PM
 *  Author: No. 01
 */ 

void SPI_masterInit()
{
	SPI_DDR= (HIGH<<MOSI) | (HIGH<<SCK) |(HIGH<<SS);
	SPCR = (HIGH<<SPE) | (HIGH<<MSTR) | (SPI_MODE<<CPHA) | (SPI_CR<<SPR0);
}
void SPI_slaveInit()
{
	SPI_DDR = (HIGH<<MISO);
	SPCR = HIGH<<SPE;
}
void SPI_masterTransmit(uint8_t u8_data)
{
	SPDR=u8_data;
	while(LOW==(SPCR&(HIGH<<SPIF)>>SPIF));
}
void SPI_slaveReceive(uint8_t * pu8_data)
{
	while(LOW==(SPCR&(HIGH<<SPIF)>>SPIF));
	*pu8_data=SPDR;
}