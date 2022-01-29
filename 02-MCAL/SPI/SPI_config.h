/*
 * SPI_config.h
 *
 * Created: 1/25/2022 9:21:22 PM
 *  Author: No. 01
 */ 


#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_

/*
SPI MASTER CLOCK RATE OPTIONS:
f/4 -> 0
f/16 -> 1
f/64 -> 2
f/128 -> 3
*/
#define SPI_CR 3  // f/16 as default
/*
SPI MODE OPTIONS
mode 1 -> 0 (ACTIVE HIGH) Data sampled on rising edge and shifted out on the falling edge
mode 2 -> 1 (ACTIVE HIGH) Data sampled on the falling edge and shifted out on the rising edge
mode 3 -> 2 (ACTIVE LOW) Data sampled on the falling edge and shifted out on the rising edge
mode 4 -> 3 (ACTIVE LOW) Data sampled on rising edge and shifted out on the falling edge
*/
#define SPI_MODE 1




#endif /* SPI_CONFIG_H_ */