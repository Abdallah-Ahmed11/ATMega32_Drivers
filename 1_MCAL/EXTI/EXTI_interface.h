/****************************************************/
/*   AUTHOR      : Abdullah Ahmed                   */
/*   Description : EXTI_interface.h       	        */
/*   DATE        : 20 DEC 2023                      */
/*   VERSION     : V01                              */
/****************************************************/


#ifndef INCLUDE_MCAL_EXTI_EXTI_INTERFACE_H_
#define INCLUDE_MCAL_EXTI_EXTI_INTERFACE_H_

typedef enum{
    EXT_INT0,
    EXT_INT1,
    EXT_INT2,
}EXTI_channel_t;


/*
  * Function: MEXTI_voidSetINT
  * Description: This function sets the interrupt for the specified EXTI channel.
  * Parameters: Copy_enuChannelNum - The EXTI channel number (EXT_INT0, EXT_INT1, EXT_INT2).
  * Return: None
  */
 void MEXTI_voidSetINT(EXTI_channel_t Copy_enuChannelNum);

 /*
  * Function: EXTI0_vSetCallBack
  * Description: This function sets the callback function for EXTI0 interrupt.
  * Parameters: pf - Pointer to the callback function.
  * Return: None
  */
 void EXTI0_vSetCallBack(void (*pf)(void));

 /*
  * Function: EXTI1_vSetCallBack
  * Description: This function sets the callback function for EXTI1 interrupt.
  * Parameters: pf - Pointer to the callback function.
  * Return: None
  */
 void EXTI1_vSetCallBack(void (*pf)(void));

 /*
  * Function: EXTI2_vSetCallBack
  * Description: This function sets the callback function for EXTI2 interrupt.
  * Parameters: pf - Pointer to the callback function.
  * Return: None
  */
 void EXTI2_vSetCallBack(void (*pf)(void));




#endif /* INCLUDE_MCAL_EXTI_EXTI_INTERFACE_H_ */
