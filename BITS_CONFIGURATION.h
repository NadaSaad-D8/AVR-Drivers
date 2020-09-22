 /******************************************************************************
 
 * Module: BITS CONFIGURATIONS
 *
 * File Name: BITS_CONFIGURATION .h
 *
 * Description: Commonly used Macros
 *
 * Author: Nada Mohamed
 *
 *******************************************************************************/
#ifndef BITS_CONFIGURATION 
#define BITS_CONFIGURATION 


// set  bit in the register 
#define SET_BIT(REG,bit) ( REG|=(1<<bit) )

//reset bit in register 
#define CLEAR_BIT(REG,bit) ( REG &= ~(1<<bit) )

// toggle bit in register 
#define TOGGLE(REG,bit) (REG^= (1<<bit))

//ROTATE RIGHT WITH CERTAIN NUMBER OF ROTATES 
#define ROTATE_RIGHT(REG,bit) (REG=(REG>>bit) | (REG<<8-bit))

//ROTATE LEFT WITH CERTAIN NUMBER OF ROTATES 
#define ROTATE_LEFT(REG,bit)  (REG = (REG<<bit)|(REG>>8-bit))

//Check if a specific bit is set in any register and return true if yes 
#define BIT_IS_SET(REG,BIT)   (REG & (1<<BIT))

// Check if a specific bit is cleared in any register and return true if yes 
#define BIT_IS_CLEAR(REG,BIT) (!(REG & (1<<BIT)))

#endif