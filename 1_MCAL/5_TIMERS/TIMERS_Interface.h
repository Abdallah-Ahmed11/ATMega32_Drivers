/****************************************************/
/*   AUTHOR      : Abdullah Ahmed                   */
/*   Description : TIMERS_Interface.h               */
/*   DATE        : 26 DEC 2023                      */
/*   VERSION     : V01                              */
/****************************************************/



#ifndef TIMERS_INTERFACE_H_
#define TIMERS_INTERFACE_H_


/**********************************************************************/
/*********************Timers configurations****************************/
/**********************************************************************/
#define DISABLE					0
#define ENABLE					1


#define TIMER_NORMAL_MODE		0
#define TIMER_PWM_MODE			1
#define TIMER_CTC_MODE			2
#define TIMER_FAST_PWM_MODE		3


#define TIMER_NO_CLOCK_SOURCE					0
#define TIMER_NO_PRESCALER_FACTOR				1
#define TIMER_DIVITION_FACTOR_8					2
#define TIMER_DIVITION_FACTOR_64				3
#define TIMER_DIVITION_FACTOR_256				4
#define TIMER_DIVITION_FACTOR_1024				5
#define TIMER_T0_EXTERNAL_CLOCK_SOURCE_FALLING  6
#define TIMER_T0_EXTERNAL_CLOCK_SOURCE_RISING   7


#define TIMER_OC_DISCONNECTED					0
#define TIMER_CLR_ON_CTC_SET_ON_TOP				2
#define TIMER_SET_ON_CTC_CLR_ON_TOP				3


#define TIMER_OC_DISCONNECTED					0
#define TIMER_OC_TOGGLE							1
#define TIMER_OC_LOW							2
#define TIMER_OC_HIGH							3




#define TIMER_PRESCALER_MASK    0b11111000

/**********************************************************************/
/*********************Timers Prototypes********************************/
/**********************************************************************/
/********************Timer0***************************/
void TIMER0_voidInit(void);
void TIMER0_voidSetPreload(u8 Copy_u8Preload);
void TIMER0_voidSetCTC(u8 Copy_u8CTC);
u8 TIMER0_u8GetTimerCounterValue(void);

/********************Timer1***************************/


/********************Timer2***************************/
void TIMER2_voidInit(void);
void TIMER2_voidSetPreload(u8 Copy_u8Preload);
void TIMER2_voidSetCTC(u8 Copy_u8CTC);
u8 TIMER2_u8GetTimerCounterValue(void);


#endif /* TIMERS_INTERFACE_H_ */
