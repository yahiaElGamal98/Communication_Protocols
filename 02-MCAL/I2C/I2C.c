/*
 * UART.c
 *
 * Created: 1/24/2022 8:21:18 PM
 *  Author: No. 01
 */ 

#include "../../01-LIB/STD_types.h"
#include "../../01-LIB/Registers.h"

#include "I2C_interface.h"
#include "I2C_config.h"

#define HIGH 1
#define LOW 0

void I2C_init(void)
{
	TWBR= 0x02;
	TWSR&=~((HIGH<<TWPS1)|(HIGH<<TWPS0));
}
void I2C_masterStartRead(uint8_t u8_SLA)
{
	/*clear interrupt flag, enable TWI, send start condition*/
	TWCR = (HIGH<<TWINT) | (HIGH<<TWSTA) | (HIGH <<TWEN);
	/*wait for TWINT to be set*/
	while (LOW==((TWCR&(HIGH<<TWINT))>>TWINT));
	/*wait for condition to be met*/
	while(M_START_CONDITION!=(TWSR&TWSR_MASK));
	/*load address and command which is read from address*/
	TWDR= u8_SLA+READ;
	/*clear flag and enable TWI*/
	TWCR= (HIGH<<TWINT) | (HIGH << TWEN);
	/*wait for TWINT to be set*/
	while (LOW==((TWCR&(HIGH<<TWINT))>>TWINT));
	/*wait for condition to be met*/
	while(M_SLA_R_ACK!=(TWSR&TWSR_MASK));
}

void I2C_masterStartWrite(uint8_t u8_SLA)
{
	/*clear interrupt flag, enable TWI, send start condition*/
	TWCR = (HIGH<<TWINT) | (HIGH<<TWSTA) | (HIGH <<TWEN);
	/*wait for TWINT to be set*/
	while (LOW==((TWCR&(HIGH<<TWINT))>>TWINT));
	/*wait for condition to be met*/
	while(M_START_CONDITION!=(TWSR&TWSR_MASK));
	/*load address and command which is write to address*/
	TWDR= u8_SLA+WRITE;
	/*clear interrupt flag and enable TWI*/
	TWCR= (HIGH<<TWINT) | (HIGH << TWEN);
	/*wait for TWINT to be set*/
	while (LOW==((TWCR&(HIGH<<TWINT))>>TWINT));
	/*wait for condition to be met*/
	while(M_SLA_W_ACK!=(TWSR&TWSR_MASK));
}

void I2C_masterSendData(uint8_t u8_data)
{
	TWDR=u8_data;
	TWCR = (HIGH<<TWINT) | (HIGH <<TWEN);
	while (LOW==((TWCR&(HIGH<<TWINT))>>TWINT));
	while(M_DATA_T_ACK!=(TWSR&TWSR_MASK));
}
void I2C_masterReceiveDataAck(uint8_t * u8_data)
{
	TWCR = (HIGH<<TWINT) | (HIGH<<TWEA) | (HIGH <<TWEN);
	while(LOW==((TWCR&(HIGH<<TWINT))>>TWINT))
	while(M_DATA_R_ACK!=(TWSR&TWSR_MASK));
	*u8_data=TWDR;
}
void I2C_masterReceiveDataNAck(uint8_t * u8_data)
{
	TWCR = (HIGH<<TWINT) | (HIGH <<TWEN);
	while(LOW==((TWCR&(HIGH<<TWINT))>>TWINT))
	while(M_DATA_R_NACK!=(TWSR&TWSR_MASK));
	*u8_data=TWDR;
}
void I2C_stop()
{
	TWCR=(HIGH<<TWINT) | (HIGH<<TWSTO) |(HIGH<<TWEN);
	while(LOW==((TWCR&(HIGH<<TWINT))>>TWINT));
}
void I2C_masterRepeatedStartRead(uint8_t u8_SLA)
{
	TWCR = (HIGH<<TWINT) | (HIGH<<TWSTA) | (HIGH <<TWEN);
	while(LOW==((TWCR&(HIGH<<TWINT))>>TWINT));
	while(M_REPEATED_START!=(TWSR&TWSR_MASK));
	TWDR=u8_SLA+READ;
	TWCR= (HIGH<<TWINT)|(HIGH<<TWEN);
	while (LOW==((TWCR&(HIGH<<TWINT))>>TWINT));
	while((M_SLA_R_ACK!=(TWSR&TWSR_MASK)) || (M_SLA_R_NACK!=(TWSR&TWSR_MASK)));
}

void I2C_slaveListen(void)
{
	while(1)
	{
		while(LOW==((TWCR&(HIGH<<TWINT))>>TWINT));
		if(S_SLA_W_ACK==(TWSR&TWSR_MASK)||S_SLA_R_ACK==(TWSR&TWSR_MASK)||S_GENERAL_CALL_ACK==(TWSR&TWSR_MASK))
		{
			break;
		}
		else
		{
			continue;
		}
	}
	
}
void I2C_slaveReceiveDataAck(uint8_t * u8_data)
{
	TWCR = (HIGH<<TWINT) | (HIGH <<TWEN);
	while(LOW==((TWCR&(HIGH<<TWINT))>>TWINT))
	if(S_DATA_R_ACK==(TWSR&TWSR_MASK)||S_LAST_DATA_R_NACK==(TWSR&TWSR_MASK))
	{
		*u8_data=TWDR;
	}
	else
	{
		
	}
}
void I2C_slaveInit(uint8_t SLA)
{
	TWAR=SLA;
}
//void I2C_slaveReceiveDataAck()

