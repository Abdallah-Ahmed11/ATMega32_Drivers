/****************************************************/
/*   AUTHOR      : Abdullah Ahmed                   */
/*   Description : UART_configuration.h             */
/*   DATE        : 31 DEC 2023                      */
/*   VERSION     : V01                              */
/****************************************************/


#ifndef INCLUDE_MCAL_UART_UART_CONFIGURATION_H_
#define INCLUDE_MCAL_UART_UART_CONFIGURATION_H_

/*Set System Frequency*/
#define F_CPU		                	8000000UL

/*Set Timeout for Your functions*/
#define TIME_OUT        	         	10000UL

/* Return Value If Receive is Not Complete */
#define VALUE_RETURN_NO_RECIEVED_DATA  255

/*Set Baud Rate*/
#define UART_BAUD_RATE					9600UL

/*Set System Speed
 * choose between
 * 1.  DOUBLE_SPEED_ON		
 * 2.  DOUBLE_SPEED_OFF	
 */
#define UART_SYSTEM_SPEED				DOUBLE_SPEED_OFF

/* Set RX Complete Interrupt Enable
 *  Choose between 
 *  1. INTERRUPT_ENABLE 
 *  2. INTERRUPT_DISABLE
*/
#define UART_RX_COMPLETE_INTERRUPT		INTERRUPT_DISABLE

/* Set TX Complete Interrupt Enable
 *  Choose between 
 *  1. INTERRUPT_ENABLE 
 *  2. INTERRUPT_DISABLE
*/
#define UART_TX_COMPLETE_INTERRUPT		INTERRUPT_DISABLE

/* Set UDR Empty Interrupt Enable
 *  Choose between 
 *  1. INTERRUPT_ENABLE 
 *  2. INTERRUPT_DISABLE
*/
#define UART_UDR_EMPTY_INTERRUPT		INTERRUPT_DISABLE

/*Set Receiver Enable
 * choose between
 * 1. DISABLE
 * 2. ENABLE
 */
#define UART_RECEIVER_ENABLE		ENABLE

/*Set Transmitter Enable
 * choose between
 * 1. DISABLE
 * 2. ENABLE
 */
#define UART_TRANSMITTER_ENABLE		ENABLE

/*Set Data Size
 * choose between
 * 1. DATA_SIZE_5_BIT
 * 2. DATA_SIZE_6_BIT
 * 3. DATA_SIZE_7_BIT
 * 4. DATA_SIZE_8_BIT
 * 5. DATA_SIZE_9_BIT
 */
#define UART_DATA_SIZE				DATA_SIZE_8_BIT

/*Set UART Mode select
 * choose between
 * 1. ASYNCHRONOUS
 * 2. SYNCHRONOUS
 */
#define UART_MODE              	ASYNCHRONOUS

/*Set UART Parity mode  select
 * choose between
 * 1. DISABLE
 * 2. EVEN_PARITY
 * 3. ODD_PARITY
 */
#define UART_PARITY_MODE              	DISABLE

/*Set UART Stop Bit select
 * choose between
 * 1. STOP_BIT_1
 * 2. STOP_BIT_2
 */
#define UART_STOP_BIT              	STOP_BIT_1







#endif /* INCLUDE_MCAL_UART_UART_CONFIGURATION_H_ */
