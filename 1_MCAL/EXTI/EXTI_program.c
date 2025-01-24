/*
 ****************************************************
 *   AUTHOR      : Abdullah Ahmed                   *
 *   Description : EXTI_program.c                   *
 *   DATE        : 20 DEC 2023                      *
 *   VERSION     : V01                              *
 ****************************************************
*/

/****************************************************/
/* Library Directives                               */
/****************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/****************************************************/
/* EXTI Directives                                  */
/****************************************************/
#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_configuration.h"

/* Function pointers for callback functions */
void (*EXTI0_CallBack)(void) = NULL;
void (*EXTI1_CallBack)(void) = NULL;
void (*EXTI2_CallBack)(void) = NULL;

/* Function to set callback function for EXTI0 */
void EXTI0_vSetCallBack(void (*pf)(void))
{
    EXTI0_CallBack = pf;
}

/* Function to set callback function for EXTI1 */
void EXTI1_vSetCallBack(void (*pf)(void))
{
    EXTI1_CallBack = pf;
}

/* Function to set callback function for EXTI2 */
void EXTI2_vSetCallBack(void (*pf)(void))
{
    EXTI2_CallBack = pf;
}

/* Function to configure the external interrupt based on the channel */
void MEXTI_voidSetINT(EXTI_channel_t Copy_enuChannelNum)
{
    switch(Copy_enuChannelNum)
    {
        case EXT_INT0:
            #if EXTI0_SENSE == LOW_LEVEL
                CLR_BIT(MCUCR , MCUCR_ISC00);
                CLR_BIT(MCUCR , MCUCR_ISC01);
            #elif EXTI0_SENSE == ANY_CHANGE
                SET_BIT(MCUCR , MCUCR_ISC00);
                CLR_BIT(MCUCR , MCUCR_ISC01);
            #elif EXTI0_SENSE == RISING_EDGE
                SET_BIT(MCUCR , MCUCR_ISC00);
                SET_BIT(MCUCR , MCUCR_ISC01);
            #elif EXTI0_SENSE == FALLING_EDGE
                CLR_BIT(MCUCR, MCUCR_ISC00);
                SET_BIT(MCUCR, MCUCR_ISC01);
            #endif
            SET_BIT(GICR , GICR_INT0); /* Enable EXTI0 interrupt */
            break;

        case EXT_INT1:
            #if EXTI1_SENSE == LOW_LEVEL
                CLR_BIT(MCUCR , MCUCR_ISC10);
                CLR_BIT(MCUCR , MCUCR_ISC11);
            #elif EXTI1_SENSE == ANY_CHANGE
                SET_BIT(MCUCR , MCUCR_ISC10);
                CLR_BIT(MCUCR , MCUCR_ISC11);
            #elif EXTI1_SENSE == RISING_EDGE
                SET_BIT(MCUCR , MCUCR_ISC10);
                SET_BIT(MCUCR , MCUCR_ISC11);
            #elif EXTI1_SENSE == FALLING_EDGE
                CLR_BIT(MCUCR, MCUCR_ISC10);
                SET_BIT(MCUCR, MCUCR_ISC11);
            #endif
            SET_BIT(GICR , GICR_INT1); /* Enable EXTI1 interrupt */
            break;

        case EXT_INT2:
            #if EXTI2_SENSE == RISING_EDGE
                SET_BIT(MCUCSR , MCUCSR_ISC2);
            #elif EXTI2_SENSE == FALLING_EDGE
                CLR_BIT(MCUCSR , MCUCSR_ISC2);
            #endif
            SET_BIT(GICR , GICR_INT2); /* Enable EXTI2 interrupt */
            break;

        default:
            /* Invalid channel number */
            break;
    }
}

/* ISR for EXTI0 */
void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
    if(EXTI0_CallBack != NULL)
    {
        EXTI0_CallBack();
    }
}

/* ISR for EXTI1 */
void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
    if(EXTI1_CallBack != NULL)
    {
        EXTI1_CallBack();
    }
}

/* ISR for EXTI2 */
void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
    if(EXTI2_CallBack != NULL)
    {
        EXTI2_CallBack();
    }
}
