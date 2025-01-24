/****************************************************/
/*   AUTHOR      : Abdullah Ahmed                   */
/*   Description : LED_interface.h                  */
/*   DATE        : 17 DEC 2023                      */
/*   VERSION     : V01                              */
/****************************************************/

#ifndef INCLUDE_HAL_LED_LED_INTERFACE_H_
#define INCLUDE_HAL_LED_LED_INTERFACE_H_

#define LED_ON   1
#define LED_OFF  0


void HLED_vTurnOn(u8 A_u8PortId , u8 A_u8PinId);
void HLED_vTurnOff(u8 A_u8PortId , u8 A_u8PinId);
void HLED_vSetLedStatus(u8 A_u8PortId , u8 A_u8PinId , u8 A_u8LedStatus) ; 

#endif /* INCLUDE_HAL_LED_LED_INTERFACE_H_ */
