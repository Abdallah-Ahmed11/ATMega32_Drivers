/****************************************************/
/*   AUTHOR      : Abdullah Ahmed                   */
/*   Description : LED_program.c                    */
/*   DATE        : 17 DEC 2023                      */
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
#include "DIO_int.h"
#include "DIO_private.h"
#include "DIO_config.h"


/****************************************************/
/* LED Directives								    */
/****************************************************/
#include "LED_interface.h"
#include "LED_private.h"
#include "LED_configuration.h"


/*********************************************************************/

/* Turn on the LED by setting its pin to HIGH */
void HLED_vTurnOn(u8 copy_u8PortId , u8 copy_u8PinId)
{
    MDIO_voidSetPinVal(copy_u8PortId , copy_u8PinId , LED_ON);
}

/* Turn off the LED by setting its pin to LOW */
void HLED_vTurnOff(u8 copy_u8PortId , u8 copy_u8PinId)
{
    MDIO_voidSetPinVal(copy_u8PortId , copy_u8PinId , LED_OFF);
}

/*
 * Set the LED status based on the provided value (LED_ON or LED_OFF).
 * This function allows flexibility in controlling the LED status.
 */
void HLED_vSetLedStatus(u8 copy_u8PortId , u8 copy_u8PinId , u8 copy_u8LedStatus)
{
    MDIO_voidSetPinVal(copy_u8PortId , copy_u8PinId , copy_u8LedStatus);
}
