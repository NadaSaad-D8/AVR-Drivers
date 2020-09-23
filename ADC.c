#include "ADC.h"

/*******************************************************************************
 *                          Global Variables                                   *
 *******************************************************************************/

volatile uint16 g_adcResult = 0;
/*******************************************************************************
 *                          ISR's Definitions                                  *
 *******************************************************************************/

ISR(ADC_vect)
{
	/* Read ADC Data after conversion complete */
	g_adcResult = ADC;
}
/*****************************************************************************
 * 
 * Description : Function to Initiliaze The ADC 
 * ***************************************************************************/

void ADCInit(const ADCConfigType* config_ptr)
{
  /*choose voltage */
  ADMUX = ((ADMUX & 0xCF) | ((config_ptr -> RefrenceVoltage) <<6) );
  /*choose the ADCResult Left or Right Adjusted */
  ADMUX =((config_ptr -> ResultAdjust ) << 5) ;
  /*Enable ADC */
   ADCSRA |= (1<<7);
  /*choose Clock Note : ADC must operate in range 50-200Khz */
   ADCSRA = (( ADCSRA & 0xF8) |  (config_ptr -> Prescaler )  ) ;
   #ifdef INTERRUPT 
   ADCSRA |= (1<<ADIE);
   #endif
  
   }
  
}
/*****************************************************************************
 * 
 * Description : Read the channel of the ADC and Start Conversion 
 * ***************************************************************************/
void ADCReadChannel (const ADCConfigType* config_ptr)
{
    /*choose ADC channel */
     ADMUX = ( (ADMUX & 0xE0) | (config_ptr ->   channel )) ; 
   /* start conversion write '1' to ADSC */
     SET_BIT(ADCSRA,ADSC);  
 
      #ifdef POLLING
   {
       /* start conversion write '1' to ADSC */
    SET_BIT(ADCSRA,ADSC);
       /* wait for conversion to complete ADIF becomes '1' */ 
	while(BIT_IS_CLEAR(ADCSRA,ADIF));
    /* clear ADIF by write '1' to it :) */
	SET_BIT(ADCSRA,ADIF); 
	 /* store the data register of ADC in the g_variable  */
     g_adcResult =ADC ;
    } 
    #endif
}
