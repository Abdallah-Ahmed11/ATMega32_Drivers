/****************************************************/
/*   AUTHOR      : Abdullah Ahmed                   */
/*   Description : EXTI_private.h                   */
/*   DATE        : 20 DEC 2023                      */
/*   VERSION     : V01                              */
/****************************************************/


#ifndef INCLUDE_MCAL_EXTI_EXTI_PRIVATE_H_
#define INCLUDE_MCAL_EXTI_EXTI_PRIVATE_H_


#define MCUCR			*((volatile u8*)0x55)
#define	MCUCR_ISC10		2
#define	MCUCR_ISC11		3
#define	MCUCR_ISC00		0
#define	MCUCR_ISC01		1

#define MCUCSR			*((volatile u8*)0x54)
#define MCUCSR_ISC2		6

#define GICR			*((volatile u8*)0x5B)
#define GICR_INT0		6
#define GICR_INT1		7
#define GICR_INT2		5

#define GIFR			*((volatile u8*)0x5A)

#define LOW_LEVEL		1
#define ANY_CHANGE		2
#define RISING_EDGE		3
#define FALLING_EDGE	4


#endif /* INCLUDE_MCAL_EXTI_EXTI_PRIVATE_H_ */
