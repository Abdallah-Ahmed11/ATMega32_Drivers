/****************************************************/
/*   AUTHOR      : Abdullah Ahmed                   */
/*   Description : ADC_progarm.c 	                */
/*   DATE        : 24 DEC 2023                      */
/*   VERSION     : V01                              */
/****************************************************/


/****************************************************/
/* Library Directives							    */
/****************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"


/****************************************************/
/* ADC Directives								    */
/****************************************************/
#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_configuration.h"

void MADC_vAdcInit()
{
	/*select volt ref. AVCC REF.*/
	SET_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);
	/*select the adjust Right adjust*/
	CLR_BIT(ADMUX,ADMUX_ADLAR);

	/*enable ADC it regard the circute itself */
	SET_BIT(ADCSRA,ADCSRA_ADEN);
	/*enable adc interrupt */

	/*set the pre-scaller --64*/
	CLR_BIT(ADCSRA,ADCSRA_ADPS0);
	SET_BIT(ADCSRA,ADCSRA_ADPS1);
	SET_BIT(ADCSRA,ADCSRA_ADPS2);
}

//adc Synchronans function
u16 MADC_u16ReadADC(ADC_channel_t copy_enuChannelADC)
{
	/*mask the bits for channel before overwrite*/
	ADMUX &=0xE0; //or binary 0b11100000
	/*select channel */
	ADMUX |=copy_enuChannelADC;
	/*start conversion*/
	SET_BIT(ADCSRA,ADCSRA_ADSC);
	/*busy wait for ADC flag*/
	while(!GET_BIT(ADCSRA,ADCSRA_ADIF)){}
	/*clr flag*/
	SET_BIT(ADCSRA,ADCSRA_ADIF);
	return ADC_DATA_REG;
}
