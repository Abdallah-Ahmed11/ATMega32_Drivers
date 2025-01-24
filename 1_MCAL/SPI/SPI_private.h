/****************************************************/
/*   AUTHOR      : Abdullah Ahmed                   */
/*   Description : SPI_private.h                    */
/*   DATE        : 28 DEC 2023                      */
/*   VERSION     : V01                              */
/****************************************************/


#ifndef INCLUDE_MCAL_SPI_SPI_PRIVATE_H_
#define INCLUDE_MCAL_SPI_SPI_PRIVATE_H_


/**********************************************************************/
// SPI Data Register
#define SPDR		*((volatile u8*)0x2f)


/**********************************************************************/
// SPI Status Register
#define SPSR		*((volatile u8*)0x2e)

#define SPSR_SPI2X    0
#define SPSR_WCOL     6
#define SPSR_SPIF     7



/**********************************************************************/
// SPI Control Register
#define SPCR		*((volatile u8*)0x2d)

#define SPCR_SPR0    0
#define SPCR_SPR1    1
#define SPCR_CPHA    2
#define SPCR_CPOL    3
#define SPCR_MSTR    4
#define SPCR_DORD    5
#define SPCR_SPE     6
#define SPCR_SPIE    7


#endif /* INCLUDE_MCAL_SPI_SPI_PRIVATE_H_ */
