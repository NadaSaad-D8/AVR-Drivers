#include "ICU.h"
 
 /***********************************************************************************
                   Global Variables and pointers
 ************************************************************************************/
  static volatile void (*g_IcuCallBack_Ptr)(void) = NULL ;
 
 /***********************************************************************************
    Interrupt Service Routine of Timer 1, in case an interrupt occurs 
 ************************************************************************************/
  ISR(TIMER1_CAPT_vect)
  {
           if (g_IcuCallBack_Ptr!=NULL)
       {
              g_IcuCallBack_Ptr();
       }

  }
/************************************************************************************
* Function Description : ICU Set Call Back Function 
*************************************************************************************/
 void IcuSetCallBack(void (*g_SetCallBack)(void)) 
 {
        g_IcuCallBack_Ptr=g_SetCallBack ;
 }
/************************************************************************************
* Function Description : Initiliaze ICU module 
*************************************************************************************/
  void ICU_Init( const IcuConfigType* config_ptr ) 
{   
    /* Set input capture pin as input */
    DDRD &= ~ (1<<PD6) ;
    /* set Timer1 in Normal mode */
    TCCR1A = (1<<FOC1A) |(1<<FOC1B);
    /*select edge type*/
    TCCR1B = (TCCR1B & 0xBF) | ((config_ptr-> edge) <<6 ) ;
    /*set clock source*/
    TCCR1B = (TCCR1B & 0xF8) | (config_ptr -> clock)      ;
    /* Initial Value for Timer1 */
	TCNT1 = 0;
	/* Initial Value for the input capture register */
	ICR1 = 0;
    /*enable Input Capture interrupt */
    #ifdef Interrupt
    TIMSK |= (1<<TICIE1);
    #endif  
}

/****************************************************************************************
* Function Description : clear Timer register to start count from 0 
*****************************************************************************************/
 void CLEARTimerValue (void) 
 {
      TCNT1 = 0;
 } 
/****************************************************************************************
* Function Description : Get Input capture register value to store value of the register 
*****************************************************************************************/
 uint16 GETInputCaptureValue (void) 
  {
           return ICR1 ;
  }
/****************************************************************************************
* Function Description : Function to set the required edge detection.
*****************************************************************************************/
void SETEdge ( const IcuEdgeType  EdgeType  ) 
   {
         TCCR1B = (TCCR1B & 0xBF) | ( EdgeType <<6 ) ;
   }