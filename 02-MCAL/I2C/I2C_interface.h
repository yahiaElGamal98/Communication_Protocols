/*
 * UART_interface.h
 *
 * Created: 1/24/2022 8:20:49 PM
 *  Author: No. 01
 */ 


#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

/*MASTER TRANSMITTER MODE STATUS CODES*/
#define M_SLA_W_ACK 0x18
#define M_SLA_W_NACK 0x20
#define M_DATA_T_ACK 0x28
#define M_DATA_T_NACK 0x30
/*MASTER TRANSMITTER AND RECIEVER MODES STATUS CODES*/
#define M_START_CONDITION 0x08
#define M_REPEATED_START 0x10
#define M_ARBIT_LOST_SLA_DATA 0x38
/*MASTER RECEIVER MODE STATUS CODES*/
#define M_SLA_R_ACK 0x40
#define M_SLA_R_NACK 0x48
#define M_DATA_R_ACK 0x50
#define M_DATA_R_NACK 0x58
/*SLAVE TRANSMITTER MODE STATUS CODES*/
#define S_SLA_R_ACK 0xA8
#define S_DATA_T_ACK 0xB8
#define S_DATA_T_NACK 0xC0
#define S_LAST_DATA_T_ACK 0xC8
/*SLAVE RECIEVER MODE STATUS CODES*/
#define S_SLA_W_ACK 0x60
#define S_ARBIT_LOST 0x68
#define S_GENERAL_CALL_ACK 0x70
#define S_DATA_R_ACK 0x80
#define S_STOP_CONDITION 0xA0
#define S_LAST_DATA_R_NACK 0x88
/*MISC STATE STATUS CODES*/
#define NO_STATE 0xF8
#define ILLEGAL_ERROR 0x00

/*TWCR BITS*/
#define TWINT 7
#define TWEA 6
#define TWSTA 5
#define TWSTO 4
#define TWWC 3
#define TWEN 2
#define TWIE 0
/*TWSR BIT*/
#define TWPS1 1
#define TWPS0 0
#define TWSR_MASK 0xF8

#define WRITE 0
#define READ 1

#define HIGH 1
#define LOW 0

void I2C_init(void);
void I2C_masterStartRead(uint8_t SLA);
void I2C_masterStartWrite(uint8_t SLA);
void I2C_masterSendData(uint8_t u8_data);
void I2C_masterReceiveDataAck(uint8_t * u8_data);
void I2C_masterReceiveDataNAck(uint8_t * u8_data);
void I2C_masterRepeatedStart(uint8_t SLA);
void I2C_stop();
void I2C_slaveListen(void);
void I2C_slaveReceiveDataAck(uint8_t * u8_data);
void I2C_slaveInit(uint8_t SLA);


#endif /* UART_INTERFACE_H_ */