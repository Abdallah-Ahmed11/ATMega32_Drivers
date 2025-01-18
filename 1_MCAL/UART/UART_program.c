/****************************************************/
/*   AUTHOR      : Abdullah Ahmed                   */
/*   Description : UART DRIVER                      */
/*   DATE        : 31 DEC 2023                      */
/*   VERSION     : V01                              */
/****************************************************/

/****************************************************/
/* Library Directives							    */
/****************************************************/
#include"STD_TYPES.h"
#include"BIT_MATH.h"

/****************************************************/
/* UART Directives								    */
/****************************************************/
#include"UART_Interface.h"
#include"UART_Private.h"
#include"UART_Configuration.h"




static void (*FuncPtr[3])(void)={NULL,NULL,NULL};


void UART_voidInit(void)
{
    /* We will adjust this value according to the configrations then store it in UCSRC in one operation */
	u8 Local_u8UCSRC = 0 ;

	/*Calculate The Baud Rate From The Equation */
	u16 Local_u16UBRR = (u16)((F_CPU / (16 * UART_BAUD_RATE)) - 1) ;

    /*
		$ Set Baud Rate
		Hint : UBRRH then UBRRL to avoid problems
	*/
	UBRRH = (u8)(Local_u16UBRR >> 8) ; /* MSBs at Local_u16UBRR */
	UBRRL = (u8)Local_u16UBRR ;	

    /***** Check 3 Modes   *****/
	#if (USART_MODE == ASYNCHRONOUS) && (USART_SYSTEM_SPEED == DOUBLE_SPEED_OFF)

		CLR_BIT(UCSRA , UCSRA_U2X_BIT) ;

	#elif (USART_MODE == ASYNCHRONOUS) && (USART_SYSTEM_SPEED == DOUBLE_SPEED_ON)

		Local_u16UBRR /= 2 ;
		SET_BIT(UCSRA , UCSRA_U2X_BIT) ;

	#elif (USART_MODE == SYNCHRONOUS)

		Local_u16UBRR /= 8 ;

	#else
		#error "Wrong USART_MODE or USART_SYSTEM_SPEED config"
	#endif

    /************************************************************************************/
    /****************************  UCSRC Register Config  *******************************/
    /************************************************************************************/

    /*Set UCSRC Mode*/
	SET_BIT(Local_u8UCSRC , UCSRC_URSEL_BIT) ;

	/*USART Mode*/
	#if USART_MODE == ASYNCHRONOUS
		CLR_BIT(Local_u8UCSRC , UCSRC_UMSEL_BIT) ;
	#elif USART_MODE == SYNCHRONOUS
		SET_BIT(Local_u8UCSRC , UCSRC_UMSEL_BIT) ;
	#else
		#error "Wrong USART_MODE config"
	#endif


    /*Parity Mode */
    #if UART_PARITY_MODE == DISABLE  
        CLR_BIT(Local_u8UCSRC,UCSRC_UPM0_BIT);
        CLR_BIT(Local_u8UCSRC,UCSRC_UPM1_BIT);
    #elif UART_PARITY_MODE == EVEN_PARITY
        CLR_BIT(Local_u8UCSRC,UCSRC_UPM0_BIT);
        SET_BIT(Local_u8UCSRC,UCSRC_UPM1_BIT);
    #elif UART_PARITY_MODE == PARITY_ODD
        SET_BIT(Local_u8UCSRC,UCSRC_UPM0_BIT);
        SET_BIT(Local_u8UCSRC,UCSRC_UPM1_BIT);
	#else
		#error "Wrong UART_PARITY_MODE config"
    #endif

	/*Stop Bit select*/
	#if UART_STOP_BIT == STOP_BIT_1
		CLR_BIT(Local_u8UCSRC , UCSRC_USBS_BIT) ;
	#elif UART_STOP_BIT == STOP_BIT_2
		SET_BIT(Local_u8UCSRC , UCSRC_USBS_BIT) ;
	#else
		#error "Wrong UART_STOP_BIT config"
	#endif

	/* Data Size */
	#if UART_DATA_SIZE == DATA_SIZE_5_BIT
		CLR_BIT(UCSRB , UCSRB_UCSZ2_BIT) ;
		CLR_BIT(Local_u8UCSRC , UCSRC_UCSZ1_BIT) ;
		CLR_BIT(Local_u8UCSRC , UCSRC_UCSZ0_BIT) ;
	#elif UART_DATA_SIZE == DATA_SIZE_6_BIT
		CLR_BIT(UCSRB , UCSRB_UCSZ2_BIT) ;
		CLR_BIT(Local_u8UCSRC , UCSRC_UCSZ1_BIT) ;
		SET_BIT(Local_u8UCSRC , UCSRC_UCSZ0_BIT) ;
	#elif UART_DATA_SIZE == DATA_SIZE_7_BIT
		CLR_BIT(UCSRB , UCSRB_UCSZ2_BIT) ;
		SET_BIT(Local_u8UCSRC , UCSRC_UCSZ1_BIT) ;
		CLR_BIT(Local_u8UCSRC , UCSRC_UCSZ0_BIT) ;
	#elif UART_DATA_SIZE == DATA_SIZE_8_BIT
		CLR_BIT(UCSRB , UCSRB_UCSZ2_BIT) ;
		SET_BIT(Local_u8UCSRC , UCSRC_UCSZ1_BIT) ;
		SET_BIT(Local_u8UCSRC , UCSRC_UCSZ0_BIT) ;
	#elif UART_DATA_SIZE == DATA_SIZE_9_BIT
		SET_BIT(UCSRB , UCSRB_UCSZ2_BIT) ;
		SET_BIT(Local_u8UCSRC , UCSRC_UCSZ1_BIT) ;
		SET_BIT(Local_u8UCSRC , UCSRC_UCSZ0_BIT) ;
	#else
		#error "Wrong UART_DATA_SIZE config"
	#endif

    /*Store the value in UCSRC Register (one operation) */
	UCSRC = Local_u8UCSRC ;

    /************************************************************************************/
    /***********************************  ENABLES  **************************************/
    /************************************************************************************/
    
    /* Set RX Complete Interrupt Enable */
	#if UART_RX_COMPLETE_INTERRUPT == INTERRUPT_ENABLE
		SET_BIT(UCSRB , UCSRB_RXCIE_BIT) ;
	#elif UART_RX_COMPLETE_INTERRUPT == INTERRUPT_DISABLE
		CLR_BIT(UCSRB , UCSRB_RXCIE_BIT) ;
	#else
		#error "Wrong UART_RX_COMPLETE_INTERRUPT config"
	#endif
   
    /* Set TX Complete Interrupt Enable */
	#if UART_TX_COMPLETE_INTERRUPT == INTERRUPT_ENABLE
		SET_BIT(UCSRB , UCSRB_TXCIE_BIT) ;
	#elif UART_TX_COMPLETE_INTERRUPT == INTERRUPT_DISABLE
		CLR_BIT(UCSRB , UCSRB_TXCIE_BIT) ;
	#else
		#error "Wrong UART_TX_COMPLETE_INTERRUPT config"
	#endif
    
    /* Set USART Data Register Empty Interrupt Enable */
	#if UART_UDR_EMPTY_INTERRUPT == INTERRUPT_ENABLE
		SET_BIT(UCSRB , UCSRB_UDRIE_BIT) ;
	#elif UART_UDR_EMPTY_INTERRUPT == INTERRUPT_DISABLE
		CLR_BIT(UCSRB , UCSRB_UDRIE_BIT) ;
	#else
		#error "Wrong UART_UDR_EMPTY_INTERRUPT config"
	#endif
    
    /* Receiver Enable */
	#if UART_RECEIVER_ENABLE == ENABLE
		SET_BIT(UCSRB , UCSRB_RXEN_BIT) ;
	#elif UART_RECEIVER_ENABLE == DISABLE
		CLR_BIT(UCSRB , UCSRB_RXEN_BIT) ;
	#else
		#error "Wrong UART_RECEIVER_ENABLE config"
	#endif
    
    /* Transmitter Enable */
	#if UART_TRANSMITTER_ENABLE == ENABLE
		SET_BIT(UCSRB , UCSRB_TXEN_BIT) ;
	#elif UART_TRANSMITTER_ENABLE == DISABLE
		CLR_BIT(UCSRB , UCSRB_TXEN_BIT) ;
	#else
		#error "Wrong UART_TRANSMITTER_ENABLE config"
	#endif



}


void UART_voidSendByteSynchNonBlocking (u8 copy_u8Byte)
{
	u32 Local_u32TimeOut =0 ;
	while (GET_BIT( UCSRA , UCSRA_UDRE_BIT) == FLAG_DOWN )
	{
		Local_u32TimeOut++;
		if (Local_u32TimeOut==TIME_OUT)
		{
			break;
		}
	}

	if (Local_u32TimeOut!=TIME_OUT)
	{
		Local_u32TimeOut=0;
		/* Set byte to be transmitted */
		UDR = copy_u8Byte;
		/* check the bit5 (UDRE) is a flag bit to figure that if the UDR register empty or not */
		while(GET_BIT(UCSRA , UCSRA_UDRE_BIT )==FLAG_DOWN)
		{
			Local_u32TimeOut++;
			if (Local_u32TimeOut==TIME_OUT)
			{
				break;
			}
		}
		//clear the transmit interrupt flag
		SET_BIT(UCSRA , UCSRA_TXC_BIT );
	}
}

void UART_voidSendByteSynchBlocking (u8 copy_u8Byte)
{
	/* check the bit5 (UDRE) is a flag bit to figure that if the UDR register empty or not */
	while (GET_BIT( UCSRA , UCSRA_UDRE_BIT) == FLAG_DOWN );
	
    /* Set byte to be transmitted */
	UDR = copy_u8Byte;
	
    /* check the bit5 (UDRE) is a flag bit to figure that if the UDR register empty or not */
	while (GET_BIT( UCSRA , UCSRA_UDRE_BIT) == FLAG_DOWN );
	
    //clear the transmit interrupt flag
	SET_BIT(UCSRA , UCSRA_TXC_BIT );

}

void UART_voidSendByteAsynch(u8 copy_u8Byte)
{
	/* Set byte to be transmitted */
	UDR = copy_u8Byte;
}

u8 UART_u8READByteSynchBlocking (void)
{
    /* Check the bit7 (RXC) >> IF = 1 >> Receive Complete */
	while(GET_BIT(UCSRA , UCSRA_RXC_BIT) == FLAG_DOWN);
	
    return UDR;
}


u8 UART_u8READByteSynchNonBlocking (void)
{
    /*Local Variable For Time Out*/
	u32 Local_u32TimeOut = 0 ;
    /* Check the bit7 (RXC) >> IF = 1 >> Receive Complete */
	u8  Loval_u8Value = VALUE_RETURN_NO_RECIEVED_DATA;
	
    while (GET_BIT(UCSRA,UCSRA_RXC_BIT) == FLAG_DOWN)
	{
		Local_u32TimeOut++;
		if (Local_u32TimeOut==TIME_OUT)
		{
			break;
		}
	}
	if (Local_u32TimeOut!=TIME_OUT)
	{
		Loval_u8Value = UDR ;
	}
	
    return Loval_u8Value;
}

u8 UART_u8READByteAsynch (void)
{
	return UDR ;
}

void UART_voidSetCallBack(u8 copy_u8InterruptType, void (*copy_PtrFunc)(void))
{
	if ((copy_u8InterruptType <= USART_UDRE_INTERRUPT)&&(copy_PtrFunc !=NULL))
	{
		FuncPtr[copy_u8InterruptType]=copy_PtrFunc;
	}
}


void __vector_13(void)    __attribute__((signal));
void __vector_13(void)
{
	if (FuncPtr[USART_RX_INTERRUPT] != NULL)
		{
		FuncPtr[USART_RX_INTERRUPT]();
		}
}

void __vector_14(void)    __attribute__((signal));
void __vector_14(void)
{
	if (FuncPtr[USART_UDRE_INTERRUPT] != NULL)
		{
			FuncPtr[USART_UDRE_INTERRUPT]();
		}
}

void __vector_15(void)    __attribute__((signal));
void __vector_15(void)
{
	if (FuncPtr[USART_TX_INTERRUPT] != NULL)
		{
			FuncPtr[USART_TX_INTERRUPT]();
		}
}



