/*****************************************************************************
 * Module :  LCD 
 * File Name : ICU.h
 * Description : header file for ICU driver 
 * Author : Nada Mohamed 
 * ***************************************************************************/
 #ifndef ICU_H_
 #define ICU_H_
 #include "std_types.h"
 #include "micro_config.h"
/******************************************************************************
                    Common Macros
 *****************************************************************************/
 #define Interrupt 
 #define NULL ((char *)0)
 
 /****************************************************************************
                    Types Declerations 
 *****************************************************************************/
typedef enum { 
    NO_CLK, CLK_SRC, CLK_8, CLK_64, CLK_256, CLK_1024
}IcuClock;

typedef enum {
FALLING_EDGE , RISING_EDGE
}IcuEdgeType ;

typedef struct {
   IcuClock     clock ;
   IcuEdgeType  edge ;
}IcuConfigType ; 

 /****************************************************************************
                       Functions Prototypes
 *****************************************************************************/
 void ICU_Init( const IcuConfigType* config_ptr ) ;  
 void IcuSetCallBack(void (*g_SetCallBack)(void)) ;
 void SETEdge ( const IcuEdgeType  EdgeType  ) ; 
 uint16 GETInputCaptureValue (void) ; 
 void CLEARTimerValue (void) ; 
 #endif /*ICU_H*/