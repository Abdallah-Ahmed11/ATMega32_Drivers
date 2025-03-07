/****************************************************/
/*   AUTHOR      : Abdullah Ahmed                   */
/*   Description : KeyPad_interface.h               */
/*   DATE        : 12 DEC 2023                      */
/*   VERSION     : V01                              */
/****************************************************/


#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_

#define NOT_PRESSED		0xff


void HKeyPad_vInit(void);
u8 HKeyPad_u8ReadPressedKey(void);


#endif /* HKEYPAD_INTERFACE_H_ */
