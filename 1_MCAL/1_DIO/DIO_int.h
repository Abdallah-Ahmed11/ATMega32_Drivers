/****************************************************/
/*   AUTHOR      : Abdullah Ahmed                   */
/*   Description : DIO_int.h                        */
/*   DATE        : 16 DEC 2023                      */
/*   VERSION     : V01                              */
/****************************************************/
#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/*******************************/

#define PIN_HIGH    1
#define PIN_LOW     0

#define PIN_PULLUP     1
#define PIN_FLOATING   0


#define PIN_OUTPUT  1
#define PIN_INPUT   0


#define REG_HIGH    255
#define REG_LOW     0


#define DIO_PORTA   0
#define DIO_PORTB   1
#define DIO_PORTC   2
#define DIO_PORTD   3

#define DIO_PIN0    0
#define DIO_PIN1    1
#define DIO_PIN2    2
#define DIO_PIN3    3
#define DIO_PIN4    4
#define DIO_PIN5    5
#define DIO_PIN6    6
#define DIO_PIN7    7


void MDIO_voidInit(void);
void MDIO_voidSetPinDir(u8 copy_u8PortId , u8 copy_u8PinId , u8 copy_u8Direction);
void MDIO_voidSetPinVal(u8 copy_u8PortId , u8 copy_u8PinId , u8 copy_u8Value);
u8 MDIO_u8GetPinVal(u8 copy_u8PortId , u8 copy_u8Pin);

void MDIO_voidSetPortDir(u8 copy_u8PortId  , u8 copy_u8Direction);
void MDIO_voidSetPortVal(u8 copy_u8PortId , u8 copy_u8Value);
u8 MDIO_u8GetPortVal(u8 copy_u8PortId );





#endif
