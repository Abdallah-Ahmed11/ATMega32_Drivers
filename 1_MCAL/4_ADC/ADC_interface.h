/****************************************************/
/*   AUTHOR      : Abdullah Ahmed                   */
/*   Description : ADC_interface.h  	            */
/*   DATE        : 24 DEC 2023                      */
/*   VERSION     : V01                              */
/****************************************************/

#ifndef INCLUDE_MCAL_ADC_ADC_INTERFACE_H_
#define INCLUDE_MCAL_ADC_ADC_INTERFACE_H_

// This code defines an enumeration for ADC channels and prototypes two functions: MADC_vAdcInit and MADC_u16ReadADC.

 typedef enum CH_ADC
 {
     ADC_CH0=0,
     ADC_CH1,
     ADC_CH2,
     ADC_CH3,
     ADC_CH4,
     ADC_CH5,
     ADC_CH6,
     ADC_CH7
 }ADC_channel_t;

 void MADC_vAdcInit(void);

 u16 MADC_u16ReadADC(ADC_channel_t copy_enuChannelADC);

#endif /* INCLUDE_MCAL_ADC_ADC_INTERFACE_H_ */
