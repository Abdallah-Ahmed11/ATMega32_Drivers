/****************************************************/
/*   AUTHOR      : Abdullah Ahmed                   */
/*   Description : GIE_program.c                    */
/*   DATE        : 22 DEC 2023                      */
/*   VERSION     : V01                              */
/****************************************************/


/****************************************************/
/* Library Directives							    */
/****************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"


/****************************************************/
/* DIO Directives								    */
/****************************************************/
#include "GIE_interface.h"
#include "GIE_private.h"
#include "GIE_configuration.h"

 // This code enables and disables Global Interrupt Enable (GIE) in the ATmega32 microcontroller.

 void GIE_vEnable(void)
 {
     SET_BIT(SREG, SREG_GIE);  // Set the Global Interrupt Enable bit in the Status Register (SREG)
 }

 void GIE_vDisable(void)
 {
     CLR_BIT(SREG, SREG_GIE);  // Clear the Global Interrupt Enable bit in the Status Register (SREG)
 }
