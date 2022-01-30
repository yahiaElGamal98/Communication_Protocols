/*
 * SPI_interface.h
 *
 * Created: 1/25/2022 9:21:41 PM
 *  Author: No. 01
 */ 


#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

/*SPI DIO PORTS AND PINS*/
#define SPI_PORT PORTB_DATA
#define SPI_DDR PORTB_DIR
#define SCK 7
#define MISO 6
#define MOSI 5
#define SS 4

/*SPICR (CONTROL REGISTER) BITS*/
#define SPIE 7
#define SPE 6
#define DORD 5
#define MSTR 4
#define CPOL 3
#define CPHA 2
#define SPR1 1
#define SPR0 0

/*SPSR (STATUS REGISTER) BITS*/
#define SPIF 7
#define WCOL 6
#define SP2X 0

#define HIGH 1
#define LOW 0



void SPI_masterInit(void);
void SPI_slaveInit(void);
void SPI_masterTransmit(uint8_t u8_data);
void SPI_slaveReceive(uint8_t * pu8_data);





#endif /* SPI_INTERFACE_H_ */