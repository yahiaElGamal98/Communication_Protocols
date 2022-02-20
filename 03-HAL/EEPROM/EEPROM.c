/*
 * EEPROM.c
 *
 * Created: 2/20/2022 7:18:20 PM
 *  Author: No. 01
 */ 
#include "../../01-LIB/STD_types.h"
#include "../../02-MCAL/I2C/I2C_interface.h"
#include "EEPROM.h"

#define BYTE_SIZE 8

void EEPROM_init(uint8_t SLA)
{
	I2C_init();
}
EN_ErrorStatus_t EEPROM_read(uint8_t SLA, uint16_t addr, uint8_t* retVal)
{
	EN_ErrorStatus_t EN_locStatus;
	EN_locStatus=I2C_masterStartWrite(SLA);
	EN_locStatus=I2C_masterSendData(((uint8_t)(addr>>BYTE_SIZE)));
	EN_locStatus=I2C_masterSendData(((uint8_t)(addr)));
	EN_locStatus=I2C_masterRepeatedStartRead(SLA);
	EN_locStatus=I2C_masterReceiveDataNAck(retVal);
	I2C_stop();
	return EN_locStatus;
}
EN_ErrorStatus_t EEPROM_write(uint8_t SLA, uint16_t addr, uint8_t data)
{
	EN_ErrorStatus_t EN_locStatus;
	EN_locStatus=I2C_masterStartWrite(SLA);
	EN_locStatus=I2C_masterSendData(((uint8_t)(addr>>BYTE_SIZE)));
	EN_locStatus=I2C_masterSendData(((uint8_t)(addr)));
	EN_locStatus=I2C_masterSendData(data);
	I2C_stop();
	return EN_locStatus;
}