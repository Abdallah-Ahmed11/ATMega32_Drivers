/****************************************************/
/*   AUTHOR      : Abdullah Ahmed                   */
/*   Description : UART_private.h                   */
/*   DATE        : 31 DEC 2023                      */
/*   VERSION     : V01                              */
/****************************************************/

#ifndef INCLUDE_MCAL_UART_UART_PRIVATE_H_
#define INCLUDE_MCAL_UART_UART_PRIVATE_H_

/*address of UART Control and status register A*/
#define UCSRA               *((volatile u8*)0x2B)
/*************************** REGISTER UCSRA BITS ************************/
#define UCSRA_U2X_BIT	        1
#define UCSRA_UDRE_BIT	        5
#define UCSRA_TXC_BIT	        6
#define UCSRA_RXC_BIT	        7



/*address of UART Control and status register B*/
#define UCSRB              *((volatile u8*)0x2A)
/*************************** REGISTER UCSRB BITS ************************/
#define UCSRB_TXB8_BIT	        0
#define UCSRB_RXB8_BIT	        1
#define UCSRB_UCSZ2_BIT	        2
#define UCSRB_TXEN_BIT	        3
#define UCSRB_RXEN_BIT	        4
#define UCSRB_UDRIE_BIT	        5
#define UCSRB_TXCIE_BIT	        6
#define UCSRB_RXCIE_BIT	        7



/*address of UART Control and status register C*/
#define UCSRC            *((volatile u8*)0x40)
/*************************** REGISTER UCSRB BITS ************************/
#define UCSRC_UCPOL_BIT	        0
#define UCSRC_UCSZ0_BIT	        1
#define UCSRC_UCSZ1_BIT	        2
#define UCSRC_USBS_BIT	        3
#define UCSRC_UPM0_BIT	        4
#define UCSRC_UPM1_BIT	        5
#define UCSRC_UMSEL_BIT	        6
#define UCSRC_URSEL_BIT	        7


/*address of USART I/O register*/
#define UDR               *((volatile u8*)0x2C)
#define UBRRL             *((volatile u8*)0x29)
#define UBRRH             *((volatile u8*)0x40)


/**************************************************************************/
/*************************** DEFINITIONS **********************************/
/**************************************************************************/

#define DOUBLE_SPEED_ON		1
#define DOUBLE_SPEED_OFF	0

# define INTERRUPT_ENABLE   1
# define INTERRUPT_DISABLE  0

# define ENABLE             1
# define DISABLE            0

#define ASYNCHRONOUS		                    0
#define SYNCHRONOUS 		                    1

#define EVEN_PARITY			                    2
#define ODD_PARITY 			                    3

#define STOP_BIT_1			                    0
#define STOP_BIT_2			                    1

#define DATA_SIZE_5_BIT		                    0
#define DATA_SIZE_6_BIT		                    1
#define DATA_SIZE_7_BIT		                    2
#define DATA_SIZE_8_BIT		                    3
#define DATA_SIZE_9_BIT		                    4


#define FLAG_DOWN          0
#define FLAG_UP            1


#endif /* INCLUDE_MCAL_UART_UART_PRIVATE_H_ */
