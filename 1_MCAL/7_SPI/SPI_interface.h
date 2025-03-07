/*
 * SPI_interface.h
 *
 *  Created on: Dec 28, 2023
 *      Author: Eng Abdallah Ahmed
 */

#ifndef INCLUDE_MCAL_SPI_SPI_INTERFACE_H_
#define INCLUDE_MCAL_SPI_SPI_INTERFACE_H_

void SPI_vInit();

//SPI DATA ORDER OPTION
#define SPI_DATA_ORDER_LSB        1
#define SPI_DATA_ORDER_MSB        0


// SPI MASTER/SALVE SELECT
#define SPI_MASTER_SELECT      1
#define SPI_SLAVE_SELECT       0


// SPI Clock Polarity
#define SPI_CLK_IDLE_HIGH       1
#define SPI_CLK_IDLE_LOW        0


// SPI Clock Phase
#define SPI_SAMPLE_ON_LEADING        0
#define SPI_SETUP_ON_LEADING         1


// SPI Clock Rate Select
#define SPI_PRESCALLER_4             0
#define SPI_PRESCALLER_16            1
#define SPI_PRESCALLER_64            2
#define SPI_PRESCALLER_128           3
#define SPI_PRESCALLER_X2_2          4
#define SPI_PRESCALLER_X2_8          5
#define SPI_PRESCALLER_X2_32         6
#define SPI_PRESCALLER_X2_64         7


// SPI Interrupt Enable OPTIONS
#define SPI_INTERRUPT_ENABLE       1
#define SPI_INTERRUPT_DIABLE       0


// SPI  Enable OPTIONS
#define SPI_ENABLE       1
#define SPI_DIABLE       0


#endif /* INCLUDE_MCAL_SPI_SPI_INTERFACE_H_ */
