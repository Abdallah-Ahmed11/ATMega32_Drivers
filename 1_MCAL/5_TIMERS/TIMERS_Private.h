/****************************************************/
/*   AUTHOR      : Abdullah Ahmed                   */
/*   Description : TIMERS_Private.h                 */
/*   DATE        : 26 DEC 2023                      */
/*   VERSION     : V01                              */
/****************************************************/


#ifndef TIMERS_PRIVATE_H_
#define TIMERS_PRIVATE_H_


/**********************************************************************/
/*********************Timers Registers*********************************/
/**********************************************************************/
#define SREG		*((volatile u8 *)0x5F)
#define TIMSK		*((volatile u8 *)0x59)
#define TIFR		*((volatile u8 *)0x58)


/********************Timer0***************************/
#define TCCR0		*((volatile u8 *)0x53)
#define TCNT0		*((volatile u8 *)0x52)
#define OCR0		*((volatile u8 *)0x5C)


/********************Timer1***************************/


/********************Timer2***************************/
#define TCCR2		*((volatile u8 *)0x45)
#define TCNT2		*((volatile u8 *)0x44)
#define OCR2		*((volatile u8 *)0x43)




/**********************************************************************/
/*********************Timers Registers Bits****************************/
/**********************************************************************/
/***TIMSK Register bits***/
#define TOIE0		0
#define OCIE0		1
#define TOIE1		2
#define OCIE1B		3
#define OCIE1A		4
#define TICIE1		5
#define TOIE2		6
#define OCIE2		7


/***TIFR Register bits***/
#define TOV0		0
#define OCF0		1
#define TOV1		2
#define OCF1B		3
#define OCF1A		4
#define ICF1		5
#define TOV2		6
#define OCF2		7

/***SREG Register bits***/
#define I		7


/********************Timer0***************************/
/***TCCR0 Register bits***/
#define TCCR0_CS00		0
#define TCCR0_CS01		1
#define TCCR0_CS02		2
#define TCCR0_WGM01		3
#define TCCR0_COM00		4
#define TCCR0_COM01		5
#define TCCR0_WGM00		6
#define TCCR0_FOC0		7




/********************Timer1***************************/


/********************Timer2***************************/
/***TCCR2 Register bits***/
#define TCCR2_CS20		0
#define TCCR2_CS21		1
#define TCCR2_CS22		2
#define TCCR2_WGM21		3
#define TCCR2_COM20		4
#define TCCR2_COM21		5
#define TCCR2_WGM20		6
#define TCCR2_FOC2		7


#endif /* TIMERS_PRIVATE_H_ */
