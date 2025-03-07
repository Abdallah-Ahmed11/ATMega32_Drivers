/****************************************************/
/*   AUTHOR      : Abdullah Ahmed                   */
/*   Description : TIMERS_Config.h                  */
/*   DATE        : 26 DEC 2023                      */
/*   VERSION     : V01                              */
/****************************************************/


#ifndef TIMERS_CONFIG_H_
#define TIMERS_CONFIG_H_

/********************Timer0***************************/
/*set Timer0 waveform Generation mode
 * choose between:
 * 1.TIMER_NORMAL_MODE
 * 2.TIMER_PWM_MODE
 * 3.TIMER_CTC_MODE
 * 4.TIMER_FAST_PWM_MODE
 */
#define TIMER0_WAVEFORM_GENERATION_MODE  TIMER_NORMAL_MODE


/* Set the required prescaler
 * choose between
 * -TIMER_NO_CLOCK_SOURCE
 * -TIMER_NO_PRESCALER_FACTOR
 * -TIMER_DIVITION_FACTOR_8
 * -TIMER_DIVITION_FACTOR_64
 * -TIMER_DIVITION_FACTOR_256
 * -TIMER_DIVITION_FACTOR_1024
 * -TIMER_T0_EXTERNAL_CLOCK_SOURCE_FALLING
 * -TIMER_T0_EXTERNAL_CLOCK_SOURCE_RISING
 */
#define TIMER0_PRESCALER	TIMER_DIVITION_FACTOR_256


#if TIMER0_WAVEFORM_GENERATION_MODE == TIMER_NORMAL_MODE
/*Set the required pre-load value*/
#define TIMER0_PRELOAD_VAL      200

/*Set Timer0 overflow Interrupt
 *choose between
 *1. DISABLE
 *2. ENABLE
 */
#define TIMER0_OVERFLOW_INTERRUPT  ENABLE


#elif TIMER0_WAVEFORM_GENERATION_MODE == TIMER_PWM_MODE
/*Set PWM Mode
 * choose between
 * 1.TIMER_OC_DISCONNECTED
 * 2.TIMER_CLR_ON_CTC_SET_ON_TOP
 * 3.TIMER_SET_ON_CTC_CLR_ON_TOP
 */
#define TIMER_CTC_PWM_MODE   TIMER_SET_ON_CTC_CLR_ON_TOP

/*Set the required CTC value*/
#define TIMER0_CTC_VAL      250

#elif TIMER0_WAVEFORM_GENERATION_MODE == TIMER_CTC_MODE
/*Set the required CTC value*/
#define TIMER0_CTC_VAL      250

/*set compare match output mode
 * choose between
 * 1. TIMER_OC_DISCONNECTED
 * 2. TIMER_OC_TOGGLE
 * 3. TIMER_OC_LOW
 * 4. TIMER_OC_HIGH
 */
#define TIMER0_OC0_MODE		TIMER_OC_DISCONNECTED


/*Set Timer0 CTC Interrupt
 *choose between
 *1. DISABLE
 *2. ENABLE
 */
#define TIMER0_CTC_INTERRUPT  ENABLE


#elif TIMER0_WAVEFORM_GENERATION_MODE == TIMER_FAST_PWM_MODE
#define TIMER0_CTC_VAL      0

/*Set PWM Mode
 * choose between
 * 1.TIMER_OC_DISCONNECTED
 * 2.TIMER_CLR_ON_CTC_SET_ON_TOP
 * 3.TIMER_SET_ON_CTC_CLR_ON_TOP
 */

#define TIMER_CTC_PWM_MODE   TIMER_CLR_ON_CTC_SET_ON_TOP

#else
#error "Wrong TIMER0_Waveform generation mode configuration"
#endif

/********************Timer1***************************/


/********************Timer2***************************/
/*set Timer2 waveform Generation mode
 * choose between:
 * 1.TIMER_NORMAL_MODE
 * 2.TIMER_PWM_MODE
 * 3.TIMER_CTC_MODE
 * 4.TIMER_FAST_PWM_MODE
 */
#define TIMER2_WAVEFORM_GENERATION_MODE  TIMER_NORMAL_MODE


/* Set the required prescaler
 * choose between
 * -TIMER_NO_CLOCK_SOURCE
 * -TIMER_NO_PRESCALER_FACTOR
 * -TIMER_DIVITION_FACTOR_8
 * -TIMER_DIVITION_FACTOR_64
 * -TIMER_DIVITION_FACTOR_256
 * -TIMER_DIVITION_FACTOR_1024
 * -TIMER_T0_EXTERNAL_CLOCK_SOURCE_FALLING
 * -TIMER_T0_EXTERNAL_CLOCK_SOURCE_RISING
 */
#define TIMER2_PRESCALER	TIMER_DIVITION_FACTOR_256


#if TIMER2_WAVEFORM_GENERATION_MODE == TIMER_NORMAL_MODE
/*Set the required pre-load value*/
#define TIMER2_PRELOAD_VAL      200

/*Set Timer2 overflow Interrupt
 *choose between
 *1. DISABLE
 *2. ENABLE
 */
#define TIMER2_OVERFLOW_INTERRUPT  ENABLE


#elif TIMER2_WAVEFORM_GENERATION_MODE == TIMER_PWM_MODE
/*Set PWM Mode
 * choose between
 * 1.TIMER_OC_DISCONNECTED
 * 2.TIMER_CLR_ON_CTC_SET_ON_TOP
 * 3.TIMER_SET_ON_CTC_CLR_ON_TOP
 */
#define TIMER_CTC_PWM_MODE   TIMER_SET_ON_CTC_CLR_ON_TOP

/*Set the required CTC value*/
#define TIMER2_CTC_VAL      250

#elif TIMER2_WAVEFORM_GENERATION_MODE == TIMER_CTC_MODE
/*Set the required CTC value*/
#define TIMER2_CTC_VAL      250

/*set compare match output mode
 * choose between
 * 1. TIMER_OC_DISCONNECTED
 * 2. TIMER_OC_TOGGLE
 * 3. TIMER_OC_LOW
 * 4. TIMER_OC_HIGH
 */
#define TIMER2_OC0_MODE		TIMER_OC_DISCONNECTED


/*Set Timer0 CTC Interrupt
 *choose between
 *1. DISABLE
 *2. ENABLE
 */
#define TIMER2_CTC_INTERRUPT  ENABLE


#elif TIMER2_WAVEFORM_GENERATION_MODE == TIMER_FAST_PWM_MODE
#define TIMER2_CTC_VAL      0

/*Set PWM Mode
 * choose between
 * 1.TIMER_OC_DISCONNECTED
 * 2.TIMER_CLR_ON_CTC_SET_ON_TOP
 * 3.TIMER_SET_ON_CTC_CLR_ON_TOP
 */

#define TIMER_CTC_PWM_MODE   TIMER_CLR_ON_CTC_SET_ON_TOP

#else
#error "Wrong TIMER2_Waveform generation mode configuration"
#endif




#endif /* TIMERS_CONFIG_H_ */



