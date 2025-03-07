/****************************************************/
/*   AUTHOR      : Abdullah Ahmed                   */
/*   Description : DIO DRIVER                       */
/*   DATE        : 16 DEC 2023                      */
/*   VERSION     : V01                              */
/****************************************************/

/****************************************************/
/* Library Directives							    */
/****************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"


/****************************************************/
/* DIO Directives								    */
/****************************************************/
#include "DIO_int.h"
#include "DIO_private.h"
#include "DIO_config.h"

/*********************************************************************/

/* Function to initialize DIO ports */
void MDIO_voidInit(void)
{
    /* Set direction for PORTA */
    DDRA = CONC_BIT(PORTA_PIN7_DIRECTION, PORTA_PIN6_DIRECTION, PORTA_PIN5_DIRECTION, PORTA_PIN4_DIRECTION,
                    PORTA_PIN3_DIRECTION, PORTA_PIN2_DIRECTION, PORTA_PIN1_DIRECTION, PORTA_PIN0_DIRECTION);

    /* Set direction for PORTB */
    DDRB = CONC_BIT(PORTB_PIN7_DIRECTION, PORTB_PIN6_DIRECTION, PORTB_PIN5_DIRECTION, PORTB_PIN4_DIRECTION,
                    PORTB_PIN3_DIRECTION, PORTB_PIN2_DIRECTION, PORTB_PIN1_DIRECTION, PORTB_PIN0_DIRECTION);

    /* Set direction for PORTC */
    DDRC = CONC_BIT(PORTC_PIN7_DIRECTION, PORTC_PIN6_DIRECTION, PORTC_PIN5_DIRECTION, PORTC_PIN4_DIRECTION,
                    PORTC_PIN3_DIRECTION, PORTC_PIN2_DIRECTION, PORTC_PIN1_DIRECTION, PORTC_PIN0_DIRECTION);

    /* Set direction for PORTD */
    DDRD = CONC_BIT(PORTD_PIN7_DIRECTION, PORTD_PIN6_DIRECTION, PORTD_PIN5_DIRECTION, PORTD_PIN4_DIRECTION,
                    PORTD_PIN3_DIRECTION, PORTD_PIN2_DIRECTION, PORTD_PIN1_DIRECTION, PORTD_PIN0_DIRECTION);

    /* Set initial values for PORTA */
    PORTA = CONC_BIT(PORTA_PIN7_VALUE, PORTA_PIN6_VALUE, PORTA_PIN5_VALUE, PORTA_PIN4_VALUE,
                     PORTA_PIN3_VALUE, PORTA_PIN2_VALUE, PORTA_PIN1_VALUE, PORTA_PIN0_VALUE);

    /* Set initial values for PORTB */
    PORTB = CONC_BIT(PORTB_PIN7_VALUE, PORTB_PIN6_VALUE, PORTB_PIN5_VALUE, PORTB_PIN4_VALUE,
                     PORTB_PIN3_VALUE, PORTB_PIN2_VALUE, PORTB_PIN1_VALUE, PORTB_PIN0_VALUE);

    /* Set initial values for PORTC */
    PORTC = CONC_BIT(PORTC_PIN7_VALUE, PORTC_PIN6_VALUE, PORTC_PIN5_VALUE, PORTC_PIN4_VALUE,
                     PORTC_PIN3_VALUE, PORTC_PIN2_VALUE, PORTC_PIN1_VALUE, PORTC_PIN0_VALUE);

    /* Set initial values for PORTD */
    PORTD = CONC_BIT(PORTD_PIN7_VALUE, PORTD_PIN6_VALUE, PORTD_PIN5_VALUE, PORTD_PIN4_VALUE,
                     PORTD_PIN3_VALUE, PORTD_PIN2_VALUE, PORTD_PIN1_VALUE, PORTD_PIN0_VALUE);
}

/* Function to set the direction of a pin */
void MDIO_voidSetPinDir(u8 copy_u8PortId, u8 copy_u8PinId, u8 copy_u8Direction)
{
    switch (copy_u8PortId)
    {
    case DIO_PORTA:
        if (copy_u8Direction == PIN_INPUT)
        {
            CLR_BIT(DDRA, copy_u8PinId);
        }
        else if (copy_u8Direction == PIN_OUTPUT)
        {
            SET_BIT(DDRA, copy_u8PinId);
        }
        break;
    case DIO_PORTB:
        if (copy_u8Direction == PIN_INPUT)
        {
            CLR_BIT(DDRB, copy_u8PinId);
        }
        else if (copy_u8Direction == PIN_OUTPUT)
        {
            SET_BIT(DDRB, copy_u8PinId);
        }
        break;
    case DIO_PORTC:
        if (copy_u8Direction == PIN_INPUT)
        {
            CLR_BIT(DDRC, copy_u8PinId);
        }
        else if (copy_u8Direction == PIN_OUTPUT)
        {
            SET_BIT(DDRC, copy_u8PinId);
        }
        break;
    case DIO_PORTD:
        if (copy_u8Direction == PIN_INPUT)
        {
            CLR_BIT(DDRD, copy_u8PinId);
        }
        else if (copy_u8Direction == PIN_OUTPUT)
        {
            SET_BIT(DDRD, copy_u8PinId);
        }
        break;
    default:
        break;
    }
}

/* Function to set the value of a pin */
void MDIO_voidSetPinVal(u8 copy_u8PortId, u8 copy_u8PinId, u8 copy_u8Value)
{
    switch (copy_u8PortId)
    {
    case DIO_PORTA:
        if (copy_u8Value == PIN_LOW)
        {
            CLR_BIT(PORTA, copy_u8PinId);
        }
        else if (copy_u8Value == PIN_HIGH)
        {
            SET_BIT(PORTA, copy_u8PinId);
        }
        break;
    case DIO_PORTB:
        if (copy_u8Value == PIN_LOW)
        {
            CLR_BIT(PORTB, copy_u8PinId);
        }
        else if (copy_u8Value == PIN_HIGH)
        {
            SET_BIT(PORTB, copy_u8PinId);
        }
        break;
    case DIO_PORTC:
        if (copy_u8Value == PIN_LOW)
        {
            CLR_BIT(PORTC, copy_u8PinId);
        }
        else if (copy_u8Value == PIN_HIGH)
        {
            SET_BIT(PORTC, copy_u8PinId);
        }
        break;
    case DIO_PORTD:
        if (copy_u8Value == PIN_LOW)
        {
            CLR_BIT(PORTD, copy_u8PinId);
        }
        else if (copy_u8Value == PIN_HIGH)
        {
            SET_BIT(PORTD, copy_u8PinId);
        }
        break;
    default:
        break;
    }
}

/* Function to get the value of a pin */
u8 MDIO_u8GetPinVal(u8 copy_u8PortId, u8 copy_u8PinId)
{
    u8 local_u8PinValue = 0;
    switch (copy_u8PortId)
    {
    case DIO_PORTA:
        local_u8PinValue = GET_BIT(PINA, copy_u8PinId);
        break;
    case DIO_PORTB:
        local_u8PinValue = GET_BIT(PINB, copy_u8PinId);
        break;
    case DIO_PORTC:
        local_u8PinValue = GET_BIT(PINC, copy_u8PinId);
        break;
    case DIO_PORTD:
        local_u8PinValue = GET_BIT(PIND, copy_u8PinId);
        break;
    default:
        break;
    }
    return local_u8PinValue;
}

/* Function to set the direction of a port */
void MDIO_voidSetPortDir(u8 copy_u8PortId, u8 copy_u8Direction)
{
    switch (copy_u8PortId)
    {
    case DIO_PORTA:
        DDRA = copy_u8Direction;
        break;
    case DIO_PORTB:
        DDRB = copy_u8Direction;
        break;
    case DIO_PORTC:
        DDRC = copy_u8Direction;
        break;
    case DIO_PORTD:
        DDRD = copy_u8Direction;
        break;
    default:
        break;
    }
}

/* Function to set the value of a port */
void MDIO_voidSetPortVal(u8 copy_u8PortId, u8 copy_u8Value)
{
    switch (copy_u8PortId)
    {
    case DIO_PORTA:
        PORTA = copy_u8Value;
        break;
    case DIO_PORTB:
        PORTB = copy_u8Value;
        break;
    case DIO_PORTC:
        PORTC = copy_u8Value;
        break;
    case DIO_PORTD:
        PORTD = copy_u8Value;
        break;
    default:
        break;
    }
}
