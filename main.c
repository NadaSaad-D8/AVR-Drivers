#include "micro_config.h"
#include "BITS_CONFIGURATION.h"
#include "std_types.h"
#include "LCD.h"
#include "ADC.h"
#include "motor.h"
 extern uint16 g_adcResult ;
void Timer0_PWM_Init(unsigned char set_duty_cycle)
{

	TCNT0 = 0; /* Timer initial value */

	OCR0  = set_duty_cycle; /* compare value */

	/* Configure timer control register
	 * 1. Fast PWM mode FOC0=0
	 * 2. Fast PWM Mode WGM01=1 & WGM00=1
	 * 3. Clear OC0 when match occurs (non inverted mode) COM00=0 & COM01=1
	 * 4. clock = F_CPU/8 CS00=0 CS01=1 CS02=0
	 */
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);
}
int main(void)
{   
    static ADCConfigType ConfigADC = {AREF,ADC0,RIGHT,CLK_4} ;
   
	/*Initialize Motor */
    InitMotor(); 
	 /* initialize LCD driver */
	LCD_init();
	/* initialize ADC driver */
	ADCInit(&ConfigADC); 
	/* clear LCD at the beginning */
	LCD_clearScreen(); 
	/*set motor to rotate right initially*/
	RotateRight(); 
	/* display this string "ADC Value = " only once at LCD */
	LCD_displayString("ADC Value = ") ;
    while(1)
    {
		 /* display the number every time at this position */
	   LCD_goToRowColumn(0,12); 
	    /* read channel zero where the potentiometer is connect */      
	   ADCReadChannel(&ConfigADC);
       /* display the ADC value on LCD screen */
	   LCD_intgerToString( g_adcResult ); 
	   /* Read ADC and map it into 0-255 to write in OCR0 register */ 
	   Timer0_PWM_Init(g_adcResult/4);
    }
}

