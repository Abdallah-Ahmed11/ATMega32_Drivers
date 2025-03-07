/****************************************************/
/*   AUTHOR      : Abdullah Ahmed                   */
/*   Description : TIMERS_Program.c                 */
/*   DATE        : 26 DEC 2023                      */
/*   VERSION     : V01                              */
/****************************************************/


/****************************************************/
/* Library Directives							    */
/****************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"



/****************************************************/
/* TIMERS Directives						        */
/****************************************************/
#include "TIMERS_Interface.h"
#include "TIMERS_Private.h"
#include "TIMERS_Config.h"



/**********************************************************************/
/*********************Timers Definitions*******************************/
/**********************************************************************/
/********************Timer0***************************/
void TIMER0_voidInit(void)
{
	/*Set configurable modes*/
#if TIMER0_WAVEFORM_GENERATION_MODE == TIMER_NORMAL_MODE
	CLR_BIT(TCCR0 ,TCCR0_WGM00);
	CLR_BIT(TCCR0 ,TCCR0_WGM01);

	/*Set the required preload value*/
	TCNT0 = TIMER0_PRELOAD_VAL;

	/*Timer0 overflow interrupt Enable*/
#if TIMER0_OVERFLOW_INTERRUPT == DISABLE
	CLR_BIT(TIMSK ,TOIE0);
#elif TIMER0_OVERFLOW_INTERRUPT == ENABLE
	SET_BIT(TIMSK ,TOIE0);
#else
#error "Wrong TIMER0_OVERFLOW_INTERRUPT config"
#endif

#elif TIMER0_WAVEFORM_GENERATION_MODE == TIMER_PWM_MODE
	SET_BIT(TCCR0 ,TCCR0_WGM00);
	CLR_BIT(TCCR0 ,TCCR0_WGM01);

	/*Set CTC PWM Mode*/
#if TIMER_CTC_PWM_MODE == TIMER_OC_DISCONNECTED
	CLR_BIT(TCCR0 , TCCR0_COM00);
	CLR_BIT(TCCR0 , TCCR0_COM01);

#elif TIMER_CTC_PWM_MODE == TIMER_CLR_ON_CTC_SET_ON_TOP
	CLR_BIT(TCCR0 , TCCR0_COM00);
	SET_BIT(TCCR0 , TCCR0_COM01);

#elif TIMER_CTC_PWM_MODE == TIMER_SET_ON_CTC_CLR_ON_TOP
	SET_BIT(TCCR0 , TCCR0_COM00);
	SET_BIT(TCCR0 , TCCR0_COM01);
#else
#error " Wring Timer0_CTC_PWM_MODE config"
#endif

	/*Set the required CTC Value*/
	OCR0 = TIMER0_CTC_VAL;

#elif TIMER0_WAVEFORM_GENERATION_MODE == TIMER_CTC_MODE
	CLR_BIT(TCCR0 ,TCCR0_WGM00);
	SET_BIT(TCCR0 ,TCCR0_WGM01);

	/*Set the required CTC Value*/
	OCR0 = TIMER0_CTC_VAL;

	/*Timer0 Compare Match interrupt Enable*/
#if TIMER0_CTC_INTERRUPT_INTERRUPT == DISABLE
	CLR_BIT(TIMSK ,OCIE0);
#elif TIMER0_CTC_INTERRUPT_INTERRUPT == ENABLE
	SET_BIT(TIMSK ,OCIE0);
#else
#error "Wrong TIMER0_CTC_INTERRUPT config"
#endif

#elif TIMER0_WAVEFORM_GENERATION_MODE == TIMER_FAST_PWM_MODE
	SET_BIT(TCCR0 ,TCCR0_WGM00);
	SET_BIT(TCCR0 ,TCCR0_WGM01);

	/*Set CTC Fast PWM Mode*/
#if TIMER_CTC_PWM_MODE == TIMER_OC_DISCONNECTED
	CLR_BIT(TCCR0 , TCCR0_COM00);
	SET_BIT(TCCR0 , TCCR0_COM01);

#elif TIMER_CTC_PWM_MODE == TIMER_CLR_ON_CTC_SET_ON_TOP
	CLR_BIT(TCCR0 , TCCR0_COM00);
	SET_BIT(TCCR0 , TCCR0_COM01);

#elif TIMER_CTC_PWM_MODE == TIMER_SET_ON_CTC_CLR_ON_TOP
	SET_BIT(TCCR0 , TCCR0_COM00);
	SET_BIT(TCCR0 , TCCR0_COM01);

#endif

	OCR0 = TIMER0_CTC_VAL;

#else
#error "Wrong TIMER0_CTC_PWM_MODE config"

#endif

	TCCR0 &= TIMER_PRESCALER_MASK;
	TCCR0 |= TIMER0_PRESCALER;
}

void TIMER0_voidSetPreload(u8 Copy_u8Preload)
{
	TCNT0 = Copy_u8Preload;
}

void TIMER0_voidSetCTC(u8 Copy_u8CTC)
{
	OCR0 = Copy_u8CTC;
}

u8 TIMER0_u8GetTimerCounterValue(void)
{
	return TCNT0;
}

/********************Timer1***************************/



/********************Timer2***************************/
void TIMER2_voidInit(void)
{
	/*Set configurable modes*/
#if TIMER2_WAVEFORM_GENERATION_MODE == TIMER_NORMAL_MODE
	CLR_BIT(TCCR2 ,TCCR2_WGM20);
	CLR_BIT(TCCR2 ,TCCR2_WGM21);

	/*Set the required preload value*/
	TCNT2 = TIMER2_PRELOAD_VAL;

	/*Timer2 overflow interrupt Enable*/
#if TIMER2_OVERFLOW_INTERRUPT == DISABLE
	CLR_BIT(TIMSK ,TOIE2);
#elif TIMER0_OVERFLOW_INTERRUPT == ENABLE
	SET_BIT(TIMSK ,TOIE2);
#else
#error "Wrong TIMER2_OVERFLOW_INTERRUPT config"
#endif

#elif TIMER2_WAVEFORM_GENERATION_MODE == TIMER_PWM_MODE
	SET_BIT(TCCR2 ,TCCR2_WGM20);
	CLR_BIT(TCCR2 ,TCCR2_WGM21);

	/*Set CTC PWM Mode*/
#if TIMER_CTC_PWM_MODE == TIMER_OC_DISCONNECTED
	CLR_BIT(TCCR2 , TCCR2_COM20);
	CLR_BIT(TCCR2 , TCCR2_COM21);

#elif TIMER_CTC_PWM_MODE == TIMER_CLR_ON_CTC_SET_ON_TOP
	CLR_BIT(TCCR2 , TCCR2_COM20);
	SET_BIT(TCCR2 , TCCR2_COM21);

#elif TIMER_CTC_PWM_MODE == TIMER_SET_ON_CTC_CLR_ON_TOP
	SET_BIT(TCCR2 , TCCR2_COM20);
	SET_BIT(TCCR2 , TCCR2_COM21);
#else
#error " Wring Timer2_CTC_PWM_MODE config"
#endif

	/*Set the required CTC Value*/
	OCR2 = TIMER2_CTC_VAL;

#elif TIMER2_WAVEFORM_GENERATION_MODE == TIMER_CTC_MODE
	CLR_BIT(TCCR2 ,TCCR2_WGM20);
	SET_BIT(TCCR2 ,TCCR2_WGM21);

	/*Set the required CTC Value*/
	OCR2 = TIMER2_CTC_VAL;

	/*Timer2 Compare Match interrupt Enable*/
#if TIMER2_CTC_INTERRUPT_INTERRUPT == DISABLE
	CLR_BIT(TIMSK ,OCIE2);
#elif TIMER2_CTC_INTERRUPT_INTERRUPT == ENABLE
	SET_BIT(TIMSK ,OCIE2);
#else
#error "Wrong TIMER2_CTC_INTERRUPT config"
#endif

#elif TIMER2_WAVEFORM_GENERATION_MODE == TIMER_FAST_PWM_MODE
	SET_BIT(TCCR2 ,TCCR2_WGM20);
	SET_BIT(TCCR2 ,TCCR2_WGM21);

	/*Set CTC Fast PWM Mode*/
#if TIMER_CTC_PWM_MODE == TIMER_OC_DISCONNECTED
	CLR_BIT(TCCR2 , TCCR2_COM20);
	SET_BIT(TCCR2 , TCCR2_COM21);

#elif TIMER_CTC_PWM_MODE == TIMER_CLR_ON_CTC_SET_ON_TOP
	CLR_BIT(TCCR2 , TCCR2_COM20);
	SET_BIT(TCCR2 , TCCR2_COM21);

#elif TIMER_CTC_PWM_MODE == TIMER_SET_ON_CTC_CLR_ON_TOP
	SET_BIT(TCCR2 , TCCR2_COM20);
	SET_BIT(TCCR2 , TCCR2_COM21);

#endif

	OCR2 = TIMER2_CTC_VAL;

#else
#error "Wrong TIMER0_CTC_PWM_MODE config"

#endif

	TCCR2 &= TIMER_PRESCALER_MASK;
	TCCR2 |= TIMER2_PRESCALER;
}

void TIMER2_voidSetPreload(u8 Copy_u8Preload)
{
	TCNT2 = Copy_u8Preload;
}

void TIMER2_voidSetCTC(u8 Copy_u8CTC)
{
	OCR2 = Copy_u8CTC;
}

u8 TIMER2_u8GetTimerCounterValue(void)
{
	return TCNT2;
}


/**********************************************************************/
/*             END OF FILE : TIMERS_Program.c						  */
/**********************************************************************/

