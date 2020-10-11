#include "micro_config.h"
#include "BITS_CONFIGURATION.h"
#include "std_types.h"
#include "LCD.h"
#include "ADC.h"
#include "motor.h"

uint8 Timer0_CTC_Square_Wave_Init(void)
{
	TCNT0 = 0; // initial value 0 
	DDRB = DDRB | (1<<PB3); // OC0 Pin as output pin
	/* Configure timer control register 
	 * 1. Non PWM mode FOC0=1
	 * 2. CTC Mode WGM01=1 & WGM00=0
	 * 3. Toggle OC0 on compare match COM00=1 & COM01=0 
	 * 4. clock = CPU clock CS00=1 CS01=0 CS02=0
	 */ 
	TCCR0 = (1<<FOC0) | (1<<WGM01) | (1<<COM00) | (1<<CS00);
}
int main(void)
{   
    static ADCConfigType ConfigADC = {AREF,ADC0,RIGHT,CLK_4} ;
	uint16 res_value;
    Timer0_CTC_Square_Wave_Init();
    InitMotor(); /*Initialize Motor */
	LCD_init(); /* initialize LCD driver */
	ADCInit(&ConfigADC); /* initialize ADC driver */
	LCD_clearScreen(); /* clear LCD at the beginning */
	/* display this string "ADC Value = " only once at LCD */
	LCD_displayString("ADC Value = ") ;
    while(1)
    {
	   LCD_goToRowColumn(0,12);        /* display the number every time at this position */
	   ADCReadChannel(&ConfigADC); /* read channel zero where the potentiometer is connect */
	   LCD_intgerToString( g_adcResult );  /* display the ADC value on LCD screen */
       OCR0 = (g_adcResult)/4 ;  /* Read ADC and map it into 0-255 to write in OCR0 register */
    }
}

