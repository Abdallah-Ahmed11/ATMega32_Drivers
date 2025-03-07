/****************************************************/
/*   AUTHOR      : Abdullah Ahmed                   */
/*   Description : KeyPad_program.c                 */
/*   DATE        : 12 DEC 2023                      */
/*   VERSION     : V01                              */
/****************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "DIO_interface.h"

#include "KeyPad_interface.h"
#include "KeyPad_private.h"
#include "KeyPad_config.h"

void HKeyPad_vInit(void)
{
	/* Set keypad pins configurations */
	/* SET keypad cols. as OUTPUT */
	DIO_voidsetPinDirection(KEY_PAD_PORT , COL_PIN0 , OUTPUT);
	DIO_voidsetPinDirection(KEY_PAD_PORT , COL_PIN1 , OUTPUT);
	DIO_voidsetPinDirection(KEY_PAD_PORT , COL_PIN2 , OUTPUT);
	DIO_voidsetPinDirection(KEY_PAD_PORT , COL_PIN3 , OUTPUT);

	/* SET Keypad ROWS as INPUT */

	DIO_voidsetPinDirection(KEY_PAD_PORT , ROW_PIN0 , INPUT);
	DIO_voidsetPinDirection(KEY_PAD_PORT , ROW_PIN1 , INPUT);
	DIO_voidsetPinDirection(KEY_PAD_PORT , ROW_PIN2 , INPUT);
	DIO_voidsetPinDirection(KEY_PAD_PORT , ROW_PIN3 , INPUT);

	/*Activate the PUllup Resistor for all ROWS */
	DIO_voidsetPinValue(KEY_PAD_PORT , ROW_PIN0 , HIGH);
	DIO_voidsetPinValue(KEY_PAD_PORT , ROW_PIN1 , HIGH);
	DIO_voidsetPinValue(KEY_PAD_PORT , ROW_PIN2 , HIGH);
	DIO_voidsetPinValue(KEY_PAD_PORT , ROW_PIN3 , HIGH);

	/* Deactivate for all Cols. */
	DIO_voidsetPinValue(KEY_PAD_PORT , COL_PIN0 , HIGH);
	DIO_voidsetPinValue(KEY_PAD_PORT , COL_PIN1 , HIGH);
	DIO_voidsetPinValue(KEY_PAD_PORT , COL_PIN2 , HIGH);
	DIO_voidsetPinValue(KEY_PAD_PORT , COL_PIN3 , HIGH);



}
u8 HKeyPad_u8ReadPressedKey(void)
{
	u8 Local_u8PressedKey = NOT_PRESSED;
	u8 Col_iterator , Row_iterator;
	u16 flag = 0;
	u8 Local_u8Pressed;
	u8 KeyPad_Arr[ROW_IDX][COL_IDX] = 	{{'7' , '8' , '9', '/'},
										 {'4' , '5' , '6','*'},
										 {'1' , '2' , '3' , '-'},
										 {'#' , '0' , '=' , '+'}};

	u8 Col_arr[COL_IDX] = {COL_PIN0 , COL_PIN1 , COL_PIN2 , COL_PIN3};
	u8 Row_arr[COL_IDX] = {ROW_PIN0 , ROW_PIN1 , ROW_PIN2 , ROW_PIN3};

	for(Col_iterator = 0; Col_iterator < COL_IDX; Col_iterator++)
	{
		/* Activate current Col. */
		DIO_voidsetPinValue(KEY_PAD_PORT , Col_arr[Col_iterator] , LOW);

		for(Row_iterator = 0; Row_iterator < ROW_IDX ; Row_iterator++)
		{
			/* CHECK ALL ROWS */
			Local_u8Pressed = DIO_u8GetPinValue(KEY_PAD_PORT , Row_arr[Row_iterator]);
			if(LOW == Local_u8Pressed)
			{
				Local_u8PressedKey = KeyPad_Arr[Row_iterator][Col_iterator];
				/* Busy wait */
				while(LOW == Local_u8Pressed)
				{
					Local_u8Pressed = DIO_u8GetPinValue(KEY_PAD_PORT , Row_arr[Row_iterator]);
				}
				flag = 1;
				break;
			}
			else
			{
				/* no code */
			}
		}
		if(1 == flag)
		{
			break;
		}
		else
		{
			/* no code */
		}
		/* Deactivate for current col */
		DIO_voidsetPinValue(KEY_PAD_PORT , Col_arr[Col_iterator] , HIGH);

	}


	return Local_u8PressedKey;
}
