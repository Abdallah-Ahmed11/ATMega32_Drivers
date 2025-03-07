/****************************************************/
/*   AUTHOR      : Abdullah Ahmed                   */
/*   Description : SPI_configuration.h              */
/*   DATE        : 28 DEC 2023                      */
/*   VERSION     : V01                              */
/****************************************************/

#ifndef INCLUDE_MCAL_SPI_SPI_CONFIGURATION_H_
#define INCLUDE_MCAL_SPI_SPI_CONFIGURATION_H_


/**********************************************
  SELECT FROM :-
        1- SPI_DATA_ORDER_LSB   
        2- SPI_DATA_ORDER_MSB    
*/
# define SPI_DATA_ORDER  SPI_DATA_ORDER_LSB           




/**********************************************
 SELECT FROM :-
        1- SPI_MASTER_SELECT
        2- SPI_SLAVE_SELECT  
*/
# define SPI_MASTER_SLAVE_SELECT




/********************************************** 
 SELECT FROM :-
        1-SPI_CLK_IDLE_HIGH   
        2-SPI_CLK_IDLE_LOW    
*/
# define SPI_COLCK_POLARITY





/**********************************************
  SELECT FROM :-
        1-SPI_SAMPLE_ON_LEADING
        2-SPI_SETUP_ON_LEADING 
*/
# define SPI_CLOCK_PHASE






/**********************************************
   SELECT FROM :-
        1-SPI_PRESCALLER_4    
        2-SPI_PRESCALLER_16   
        3-SPI_PRESCALLER_64   
        4-SPI_PRESCALLER_128  
        5-SPI_PRESCALLER_X2_2 
        6-SPI_PRESCALLER_X2_8 
        7-SPI_PRESCALLER_X2_32
        8-SPI_PRESCALLER_X2_64
*/
# define SPI_CLOCK_RATE





/**********************************************
   SELECT FROM :-
        1-SPI_INTERRUPT_ENABLE
        2-SPI_INTERRUPT_DIABLE
*/
# define SPI_INTERRUPT_ENABLE_MODE      SPI_INTERRUPT_ENABLE





/**********************************************
   SELECT FROM :-
        1-SPI_ENABLE 
        2-SPI_DIABLE 
*/
# define SPI_ENABLE_MODE      SPI_ENABLE

#endif /* INCLUDE_MCAL_SPI_SPI_CONFIGURATION_H_ */
