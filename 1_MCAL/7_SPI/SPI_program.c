/****************************************************/
/*   AUTHOR      : Abdullah Ahmed                   */
/*   Description : SPI_program.c                    */
/*   DATE        : 28 DEC 2023                      */
/*   VERSION     : V01                              */
/****************************************************/


/****************************************************/
/* Library Directives							    */
/****************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"


/****************************************************/
/* DIO & GIE Directives	         				    */
/****************************************************/
#include "DIO_int.h"
#include "GIE_interface.h"
/****************************************************/
/* SPI Directives								    */
/****************************************************/
#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_configuration.h"

/****************************************************/
/* GLOBAL VARIABLES								    */
/****************************************************/
volatile static u8* gl_pu8TxBuffer = NULL;
volatile static u8* gl_pu8RxBuffer = NULL;
volatile static u8 gl_u8BufferSize = 0;
volatile static u8 gl_u8Counter = 0;
volatile static void (*gl_pvNotificationFunc)(void) = NULL;


void SPI_vInit(void) {
    // If in Master mode, initialize SS pin (PB4) as output and set it HIGH
    #if SPI_MASTER_SLAVE_SELECT == SPI_MASTER_SELECT
        MDIO_voidSetPinDir(DIO_PORTB, DIO_PIN4, PIN_OUTPUT);
        MDIO_voidSetPinVal(DIO_PORTB, DIO_PIN4, PIN_HIGH);
    #endif

    // Initialize SPCR register
    u8 spcr = 0;

    // Configure data order (LSB first or MSB first)
    #if SPI_DATA_ORDER == SPI_DATA_ORDER_LSB
        SET_BIT(spcr, SPCR_DORD);
    #else
        CLR_BIT(spcr, SPCR_DORD);
    #endif

    // Configure Master/Slave mode
    #if SPI_MASTER_SLAVE_SELECT == SPI_MASTER_SELECT
        SET_BIT(spcr, SPCR_MSTR);
    #else
        CLR_BIT(spcr, SPCR_MSTR);
    #endif

    // Configure clock polarity (idle state)
    #if SPI_CLOCK_POLARITY == SPI_CLK_IDLE_HIGH
        SET_BIT(spcr, SPCR_CPOL);
    #else
        CLR_BIT(spcr, SPCR_CPOL);
    #endif

    // Configure clock phase (sampling edge)
    #if SPI_CLOCK_PHASE == SPI_SAMPLE_ON_LEADING
        CLR_BIT(spcr, SPCR_CPHA);
    #else
        SET_BIT(spcr, SPCR_CPHA);
    #endif

    // Configure clock rate (prescaler)
    switch(SPI_CLOCK_RATE) 
    {
        case SPI_PRESCALLER_4:
            CLR_BIT(spcr, SPCR_SPR0);
            CLR_BIT(spcr, SPCR_SPR1);
            CLR_BIT(SPSR, SPSR_SPI2X);
            break;
        case SPI_PRESCALLER_16:
            SET_BIT(spcr, SPCR_SPR0);
            CLR_BIT(spcr, SPCR_SPR1);
            CLR_BIT(SPSR, SPSR_SPI2X);
            break;
        case SPI_PRESCALLER_64:
            CLR_BIT(spcr, SPCR_SPR0);
            SET_BIT(spcr, SPCR_SPR1);
            CLR_BIT(SPSR, SPSR_SPI2X);
            break;
        case SPI_PRESCALLER_128:
            SET_BIT(spcr, SPCR_SPR0);
            SET_BIT(spcr, SPCR_SPR1);
            CLR_BIT(SPSR, SPSR_SPI2X);
            break;
        case SPI_PRESCALLER_X2_2:
            CLR_BIT(spcr, SPCR_SPR0);
            CLR_BIT(spcr, SPCR_SPR1);
            SET_BIT(SPSR, SPSR_SPI2X);
            break;
        default: // Fallback to default prescaler (4)
            CLR_BIT(spcr, SPCR_SPR0);
            CLR_BIT(spcr, SPCR_SPR1);
            CLR_BIT(SPSR, SPSR_SPI2X);
            break;
    }

    // Enable SPI
    #if SPI_ENABLE_MODE == SPI_ENABLE
        SET_BIT(spcr, SPCR_SPE);
    #endif

    // Enable interrupts if required
    #if SPI_INTERRUPT_ENABLE_MODE == SPI_INTERRUPT_ENABLE
        SET_BIT(spcr, SPCR_SPIE);
        GIE_vEnable(); // Enable global interrupts
    #endif

    // Apply configurations to the SPCR register
    SPCR = spcr;
}


/**
 * @brief Transmits and receives a single byte synchronously
 * @param copy_u8Data: Data to transmit
 * @return Received data
 */
u8 SPI_u8Transceive(u8 copy_u8Data) 
{
    SPDR = copy_u8Data;                     // Load data into SPI Data Register
    while(!GET_BIT(SPSR, SPSR_SPIF));       // Wait for transmission complete
    return SPDR;                            // Return received data
}


/**
 * @brief Transmits and receives a buffer synchronously
 * @param copy_pu8TxBuffer: Pointer to transmit buffer
 * @param copy_pu8RxBuffer: Pointer to receive buffer
 * @param copy_u8Size: Buffer size
 * @return Error status:
 *         - 0: Success
 *         - 1: Null pointer error
 */
u8 SPI_u8BufferTransceiverSynch(u8* copy_pu8TxBuffer, u8* copy_pu8RxBuffer, u8 copy_u8Size)
 {
    if (copy_pu8TxBuffer == NULL || copy_pu8RxBuffer == NULL) return 1; // Null check
    
    for(u8 i = 0; i < copy_u8Size; i++) 
    {
        SPDR = copy_pu8TxBuffer[i];         // Load data
        while(!GET_BIT(SPSR, SPSR_SPIF));   // Wait for completion
        copy_pu8RxBuffer[i] = SPDR;         // Store received data
    }
    return 0; // Success
}



/**
 * @brief Transmits and receives a buffer asynchronously using interrupts
 * @param copy_pu8TxBuffer: Pointer to transmit buffer
 * @param copy_pu8RxBuffer: Pointer to receive buffer
 * @param copy_u8Size: Buffer size
 * @param copy_pvNotificationFunc: Callback function pointer
 * @return Error status:
 *         - 0: Success
 *         - 1: Null pointer error
 *         - 2: SPI not in interrupt mode
 */

u8 SPI_u8BufferTransceiverAsynch(u8* copy_pu8TxBuffer, u8* copy_pu8RxBuffer, u8 copy_u8Size, void (*copy_pvNotificationFunc)(void)) {
    if (copy_pu8TxBuffer == NULL || copy_pu8RxBuffer == NULL) return 1; // Null check
    #if SPI_INTERRUPT_ENABLE_MODE != SPI_INTERRUPT_ENABLE
        return 2; // Interrupt mode not enabled
    #endif

    // Initialize global variables
    gl_pu8TxBuffer = copy_pu8TxBuffer;
    gl_pu8RxBuffer = copy_pu8RxBuffer;
    gl_u8BufferSize = copy_u8Size;
    gl_u8Counter = 0;
    gl_pvNotificationFunc = copy_pvNotificationFunc;

    // Start transmission by sending first byte
    SPDR = gl_pu8TxBuffer[gl_u8Counter++];
    return 0; // Success
}


/* SPI Interrupt Service Routine */
void __vector_12(void) __attribute__((signal)); // SPI STC Vector
void __vector_12(void) {
    // Store received data
    gl_pu8RxBuffer[gl_u8Counter - 1] = SPDR;
    
    // Check if more data to send
    if (gl_u8Counter < gl_u8BufferSize) {
        SPDR = gl_pu8TxBuffer[gl_u8Counter++];
    } 
    else {
        // Transmission complete - execute callback
        if (gl_pvNotificationFunc != NULL) {
            gl_pvNotificationFunc();
        }
    }
}
