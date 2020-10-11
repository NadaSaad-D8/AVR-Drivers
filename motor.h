/*****************************************************************************
 * Module :  LCD 
 * File Name : Keypad.h
 * Description : header file for Motor  
 * Author : Nada Mohamed 
 * ***************************************************************************/
#include "BITS_CONFIGURATION.h"
#include "std_types.h"
#include "micro_config.h"

/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/
#define En     PB3
#define DIR_1  PB0
#define DIR_2  PB1
#define MOTOR_PORT PORTB
#define MOTOR_PORT_DIR DDRB 
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

void InitMotor(void);