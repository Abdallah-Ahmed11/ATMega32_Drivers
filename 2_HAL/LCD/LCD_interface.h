/****************************************************/
/*   AUTHOR      : Abdullah Ahmed                   */
/*   Description : LCD_interface.h                  */
/*   DATE        : 18 DEC 2023                      */
/*   VERSION     : V01                              */
/****************************************************/

#ifndef INCLUDE_HAL_LCD_LCD_INTERFACE_H_
#define INCLUDE_HAL_LCD_LCD_INTERFACE_H_

void HLCD_vSendCommand(u8 copy_u8Command);
void HLCD_vSendData(u8 copy_u8Data ) ;
void HLCD_vLCDInit(void);
void HLCD_vClearDisplay(void);
void HLCD_vSendString( u8 *p_u8String);
void HLCD_vDisplayNumber(u16 copy_u16Number);

// X --> (0 to 15 )  , Y -->( 0  to 1 )  
void HLCD_vGotoXY(u8 Copy_u8PositionX , u8 Copy_u8PositionY);

#endif /* INCLUDE_HAL_LCD_LCD_INTERFACE_H_ */
