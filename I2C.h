/*****************************************************************************
 * Module :  I2C 
 * File Name : I2C.h
 * Description : header file for I2C driver 
 * Author : Nada Mohamed 
 * ***************************************************************************/
#ifndef TWI_H
#define TWI_H 

#include "micro_config.h"
#include "std_types.h"
#include "BITS_CONFIGURATION.h"


/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/
/* I2C Status Bits in the TWSR Register */
#define TW_START         0x08 // start has been sent
#define TW_REP_START     0x10 // repeated start 
#define TW_MT_SLA_W_ACK  0x18 // Master transmit ( slave address + Write request ) to slave + Ack received from slave
#define TW_MT_SLA_R_ACK  0x40 // Master transmit ( slave address + Read request ) to slave + Ack received from slave
#define TW_MT_DATA_ACK   0x28 // Master transmit data and ACK has been received from Slave.
#define TW_MR_DATA_ACK   0x50 // Master received data and send ACK to slave
#define TW_MR_DATA_NACK  0x58 // Master received data but doesn't send ACK to slave



/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void I2CInit(void);
void I2CStart(void);
void I2CStop(void);
void I2CWrite(uint8 data);
uint8 I2CReadWithACK(void); 
uint8 I2CReadWithNACK(void); 
uint8 I2CGetStatus(void);

#endif 