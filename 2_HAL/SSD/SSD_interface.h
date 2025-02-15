/****************************************************/
/*   AUTHOR      : Abdullah Ahmed                   */
/*   Description : SSD_interface.h                  */
/*   DATE        : 17 DEC 2023                      */
/*   VERSION     : V01                              */
/****************************************************/


#ifndef INCLUDE_HAL_SSD_SSD_INTERFACE_H_
#define INCLUDE_HAL_SSD_SSD_INTERFACE_H_

#define ZERO    0b00111111
#define ONE     0b00000110
#define TWO     0b01011011
#define THREE   0b01001111
#define FOUR    0b01100110
#define FIVE    0b01101101
#define SIX     0b01111101
#define SEVEN   0b00000111
#define EIGHT   0b01111111
#define NINE    0b01101111


void HSSD_vDisplay(u8 copy_u8Number);
void HSSD_vDisplayByPort(u8 copy_u8PortId ,u8 copy_u8Number );
void HSSD_vDisplayAscending(void);
void HSSD_vDisplayDescending(void);


#endif /* INCLUDE_HAL_SSD_SSD_INTERFACE_H_ */
