/*
 * EEPROM.h
 *
 * Created: 2/20/2022 7:18:06 PM
 *  Author: No. 01
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

void EEPROM_init();
EN_ErrorStatus_t EEPROM_read(uint8_t SLA, uint16_t addr, uint8_t* retVal);
EN_ErrorStatus_t EEPROM_write(uint8_t SLA, uint16_t addr, uint8_t data);




#endif /* EEPROM_H_ */