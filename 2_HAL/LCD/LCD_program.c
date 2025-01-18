/****************************************************/
/*   AUTHOR      : Abdullah Ahmed                   */
/*   Description : LCD_program.h                    */
/*   DATE        : 18 DEC 2023                      */
/*   VERSION     : V01                              */
/****************************************************/

/****************************************************/
/* Library Directives							    */
/****************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#define F_CPU 8000000UL 


/****************************************************/
/* DIO Directives								    */
/****************************************************/
#include "DIO_int.h"
#include "DIO_private.h"
#include "DIO_config.h"


/****************************************************/
/* LCD Directives								    */
/****************************************************/
#include "LCD_interface.h"
#include "LCD_private.h"
#include "LCD_configuration.h"



void HLCD_vSendCommand(u8 copy_u8Command ) 
{
    /* RS --> 0 , RW --> 0 */
    MDIO_voidSetPinVal(LCD_CONTROL_PORT , RS_PIN , PIN_LOW) ; 
    MDIO_voidSetPinVal(LCD_CONTROL_PORT , RW_PIN , PIN_LOW) ;
    /* Send Command to LCD  */
    MDIO_voidSetPortVal(LCD_DATA_PORT , copy_u8Command) ; 
    /* Set LCD Enable */
    MDIO_voidSetPinVal(LCD_CONTROL_PORT , EN_PIN , PIN_HIGH) ; 
    /* wait for 1 mSec */
	_delay_ms(1);
    /* CLR LCD Enable */
    MDIO_voidSetPinVal(LCD_CONTROL_PORT , EN_PIN , PIN_LOW) ; 
}


void HLCD_vSendData(u8 copy_u8Data ) 
{
    /* RS --> 1 , RW --> 0 */
    MDIO_voidSetPinVal(LCD_CONTROL_PORT , RS_PIN , PIN_HIGH) ; 
    MDIO_voidSetPinVal(LCD_CONTROL_PORT , RW_PIN , PIN_LOW) ;
    /* Send data to LCD  */
    MDIO_voidSetPortVal(LCD_DATA_PORT , copy_u8Data) ;
    /* Set LCD Enable */
    MDIO_voidSetPinVal(LCD_CONTROL_PORT , EN_PIN , PIN_HIGH) ; 
    /* wait for 1 mSec */
	_delay_ms(1);
    /* CLR LCD Enable */
    MDIO_voidSetPinVal(LCD_CONTROL_PORT , EN_PIN , PIN_LOW) ; 
} 


void HLCD_vLCDInit(void)
{
    /* Set LCD pins configuration */
    MDIO_voidSetPortDir(LCD_DATA_PORT , REG_HIGH);
    MDIO_voidSetPinDir(LCD_CONTROL_PORT,RS_PIN, PIN_OUTPUT);
    MDIO_voidSetPinDir(LCD_CONTROL_PORT,RW_PIN, PIN_OUTPUT);
    MDIO_voidSetPinDir(LCD_CONTROL_PORT,EN_PIN, PIN_OUTPUT);

    /* Wait for 30 msec*/
	_delay_ms(30);
	/* Send function set command */
    HLCD_vSendCommand(LCD_FUNCTION_SET);
    /* wait for 1 msec */
	_delay_ms(1);
    /* Send command "Display ON/OFF control " */
    HLCD_vSendCommand(LCD_DISPLAY);
    /* wait for 1 msec */
	_delay_ms(1);
    /* send command " Clear LCD screen " */
	HLCD_vSendCommand(LCD_CLR_SCREEN);
    /* Delay for 2 */
	_delay_ms(2);
    /* Send command "Entry Mode Set " */
	HLCD_vSendCommand(ENTRY_MODE_SET);
    /* End  of Initialization */
}


void HLCD_vClearDisplay(void)
{
    /* send command " Clear LCD screen " */
	HLCD_vSendCommand(LCD_CLR_SCREEN);
    /* Delay for 2 */
	_delay_ms(2);
}

void HLCD_vSendString( u8 *p_u8String)
{
    u8 i = 0 ;
    while(p_u8String[i])
	{
		HLCD_vSendData(p_u8String[i]);
		i++;
	}
     
}

void HLCD_vGotoXY(u8 Copy_u8PositionX , u8 Copy_u8PositionY)
{
   if(Copy_u8PositionY == LCD_ROW_ONE)
	{
		HLCD_vSendCommand(LCD_ROW1_ADDRESS + Copy_u8PositionX);
	}
	else if(Copy_u8PositionY == LCD_ROW_TWO)
	{
		HLCD_vSendCommand(LCD_ROW2_ADDRESS + Copy_u8PositionX);
	}
	else
	{
		/* no code */
	}
    _delay_ms(1); 
}

void HLCD_vDisplayNumber(u16 copy_u16Number)
{
     //late
}
