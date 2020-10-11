#include "motor.h" 
/************************************************************************************
* Function Description : Initiliaze Motor
*************************************************************************************/

void InitMotor(void)
{
   /*set motor pins as output pins*/
   MOTOR_PORT_DIR|= ( (1<<DIR_1) | (1<<DIR_2) |  (1<<En)) ;
   /*Initially set motor OFF */
    MOTOR_PORT  &= ~( (1<<DIR_1) | (1<<DIR_2)  ) ;
}