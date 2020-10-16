/*****************************************************************************
 * Module :  ADC
 * File Name : ADC.h
 * Description : header file for ADC driver 
 * Author : Nada Mohamed 
 * ***************************************************************************/
 #include "micro_config.h"
 #include "std_types.h"
 #include "BITS_CONFIGURATION.h"
 #ifndef ADC_H 
 #define ADC_H
 /****************************************************************************
                    Types Declerations 
 *****************************************************************************/

typedef enum {AREF,AVCC_CAP,RESERVED,INTERNAL_REFRENCEVOLT }ADCRefVolt;
typedef enum {ADC0,ADC1,ADC2,ADC3,ADC4,ADC5,ADC6,ADC7}ADCChannel;
typedef enum {RIGHT,LEFT}ADCResultAdjust;
typedef enum {CLK_2=1,CLK_4,CLK_8,CLK_16,CLK_32,CLK_64_CLK_128}ADCPrescaler;
typedef struct {
ADCRefVolt         RefrenceVoltage ;
ADCChannel         channel         ;
ADCResultAdjust    ResultAdjust    ;
ADCPrescaler       Prescaler       ;
}ADCConfigType ;

#define INTERRUPT 
#define POLLING
 /*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void ADCInit(const ADCConfigType* config_ptr);
void ADCReadChannel (const ADCConfigType* config_ptr);

 #endif