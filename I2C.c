#include "I2C.h"

/************************************************************************************
* Function Description : Initiliaze I2C protocol
*************************************************************************************/

void I2CInit(void) 
{
    /*set Baud Rate , Here is the Equation, SCL=((F_CPU)/16+2*TWBR*4^TWBS) 
         to get SCL speed 400 KB/s , choose TWBR=0x02 and TWBS=0x00 */ 
    TWBR = 0x02;
	TWSR = 0x00;
   /*  used in case this MC is a slave device General Call Recognition: Off */
    TWAR = 0b00000010; 
    /* enable TWI */
    TWCR = (1<<TWEN); 
	    
} 
/************************************************************************************
* Function Description : Send Start bit of the frame 
*************************************************************************************/


void I2CStart()
{
  /* 
	 * Clear the TWINT flag before sending the start bit to start TWI,
	 * send the start bit by TWSTA=1
	 * Enable TWI Module TWEN=1 */
        TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
    
    /* Wait for TWINT flag set in TWCR Register (start bit is send successfully) */
      while(BIT_IS_CLEAR(TWCR,TWINT));  
}
 
/************************************************************************************
* Function Description : Send Stop Bit 
*************************************************************************************/
void I2CStop(){

 /* 
	 * Clear the TWINT flag before sending the stop bit TWINT=1
	 * send the stop bit by TWSTO=1
	 * Enable TWI Module TWEN=1 
	 */
    TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);

}

/************************************************************************************
* Function Description : write Byte 
*************************************************************************************/
void I2CWrite(uint8 data){

     /* Put data On TWI data Register */
        TWDR = data;
    /* 
	 * Clear the TWINT flag before sending the data TWINT=1
	 * Enable TWI Module TWEN=1 
	 */ 
    TWCR = (1 << TWINT) | (1 << TWEN);
    /* Wait for TWINT flag set in TWCR Register(data is send successfully) */
    while(BIT_IS_CLEAR(TWCR,TWINT));
}
/************************************************************************************
* Function Description : Read and send Acknoldgment 
*************************************************************************************/
uint8 I2CReadWithACK()
{
    /* 
	 * Clear the TWINT flag before reading the data TWINT=1
	 * Enable sending ACK after reading or receiving data TWEA=1
	 * Enable TWI Module TWEN=1 
	 */ 
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);
    /* Wait for TWINT flag set in TWCR Register (data received successfully) */
    while(BIT_IS_CLEAR(TWCR,TWINT));
    /* Read Data */
    return TWDR;

}
/************************************************************************************
* Function Description : Read and don't senk Acknoldgment
*************************************************************************************/

uint8 I2CReadWithNACK()
{

    /* 
	 * Clear the TWINT flag before reading the data TWINT=1
	 * Enable TWI Module TWEN=1 
	 */
    TWCR = (1 << TWINT) | (1 << TWEN);
    /* Wait for TWINT flag set in TWCR Register (data received successfully) */
    while(BIT_IS_CLEAR(TWCR,TWINT));
    /* Read Data */
    return TWDR;

}
/************************************************************************************
* Function Description : tell the status of the current frame
*************************************************************************************/

uint8 I2CGetStatus()
{
 
    uint8 status;
    /* masking to eliminate first 3 bits and get the last 5 bits (status bits) */
    status = TWSR & 0xF8;
    return status;
}