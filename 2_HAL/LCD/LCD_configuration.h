/****************************************************/
/*   AUTHOR      : Abdullah Ahmed                   */
/*   Description : LCD_configuration.h              */
/*   DATE        : 18 DEC 2023                      */
/*   VERSION     : V01                              */
/****************************************************/

#ifndef INCLUDE_HAL_LCD_LCD_CONFIGURATION_H_
#define INCLUDE_HAL_LCD_LCD_CONFIGURATION_H_

// This code defines the configuration for the LCD module in an ATMega32 microcontroller.
// It sets the data and control ports, as well as the pins for RS, RW, and EN.
// Additionally, it defines the LCD commands for function set, display control, clear screen, and entry mode set.

#define LCD_DATA_PORT     DIO_PORTA
#define LCD_CONTROL_PORT  DIO_PORTB

#define RS_PIN  DIO_PIN0
#define RW_PIN  DIO_PIN1
#define EN_PIN  DIO_PIN2

#define LCD_FUNCTION_SET     0b00111000
#define LCD_DISPLAY          0b00001111
#define LCD_CLR_SCREEN       0b00000001
#define ENTRY_MODE_SET       0b00000110



#endif /* INCLUDE_HAL_LCD_LCD_CONFIGURATION_H_ */
