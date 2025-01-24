/****************************************************/
/*   AUTHOR      : Abdullah Ahmed                   */
/*   Description : SSD_program.c                    */
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
/* SSD Directives								    */
/****************************************************/
#include "SSD_interface.h"
#include "SSD_private.h"
#include "SSD_configuration.h"



/*********************************************************************/

void HSSD_vDisplay(u8 copy_u8Number )
{
	switch(copy_u8Number)
	{
	case ZERO :
		MDIO_voidSetPortVal(SSD_PORT , ZERO);
		break ;
	case ONE :
		MDIO_voidSetPortVal(SSD_PORT , ONE);
		break ;
	case TWO :
		MDIO_voidSetPortVal(SSD_PORT , TWO);
		break ;
	case THREE :
		MDIO_voidSetPortVal(SSD_PORT , THREE);
		break ;
	case FOUR :
		MDIO_voidSetPortVal(SSD_PORT , FOUR);
		break ;
	case FIVE :
		MDIO_voidSetPortVal(SSD_PORT , FIVE);
		break ;
	case SIX :
		MDIO_voidSetPortVal(SSD_PORT , SIX);
		break ;
	case SEVEN :
		MDIO_voidSetPortVal(SSD_PORT , SEVEN);
		break ;
	case EIGHT :
		MDIO_voidSetPortVal(SSD_PORT , EIGHT);
		break ;
	case NINE :
		MDIO_voidSetPortVal(SSD_PORT , NINE);
		break ;
	default:
		break;
	}
}


void HSSD_vDisplayByPort(u8 copy_u8PortId ,u8 copy_u8Number )
{
	switch(copy_u8Number)
	{
	case ZERO :
		MDIO_voidSetPortVal(copy_u8PortId , ZERO);
		break ;
	case ONE :
		MDIO_voidSetPortVal(copy_u8PortId , ONE);
		break ;
	case TWO :
		MDIO_voidSetPortVal(copy_u8PortId , TWO);
		break ;
	case THREE :
		MDIO_voidSetPortVal(copy_u8PortId , THREE);
		break ;
	case FOUR :
		MDIO_voidSetPortVal(copy_u8PortId , FOUR);
		break ;
	case FIVE :
		MDIO_voidSetPortVal(copy_u8PortId , FIVE);
		break ;
	case SIX :
		MDIO_voidSetPortVal(copy_u8PortId , SIX);
		break ;
	case SEVEN :
		MDIO_voidSetPortVal(copy_u8PortId , SEVEN);
		break ;
	case EIGHT :
		MDIO_voidSetPortVal(copy_u8PortId , EIGHT);
		break ;
	case NINE :
		MDIO_voidSetPortVal(copy_u8PortId , NINE);
		break ;
	default:
		break;
	}
}

void HSSD_vDisplayAscending(void)
{
	u8 Local_u8ArrOfNumbers[10] = {ZERO , ONE , TWO , THREE , FOUR , FIVE , SIX , SEVEN , EIGHT , NINE };

	for(u8 i = 0 ; i<10 ; i++)
		{
			HSSD_vDisplay(Local_u8ArrOfNumbers[i]);
			_delay_ms(SSD_DELAY_TIME);
		}
}

void HSSD_vDisplayDescending(void)
{
	u8 Local_u8ArrOfNumbers[10] = {ZERO , ONE , TWO , THREE , FOUR , FIVE , SIX , SEVEN , EIGHT , NINE };

	for(u8 i = 9 ; i >= 0 ; i--)
		{
			HSSD_vDisplay(Local_u8ArrOfNumbers[i]);
			_delay_ms(SSD_DELAY_TIME);
		}
}