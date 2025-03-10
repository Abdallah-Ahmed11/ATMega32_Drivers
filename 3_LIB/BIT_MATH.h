
#ifndef _BIT_MATH_H_
#define _BIT_MATH_H_

#define SET_BIT(Reg, bitnum)    (Reg|= ( 1 << bitnum))
#define CLR_BIT(Reg, bitnum)    (Reg&= ~(1 << bitnum))
#define TOGGLE_BIT(Reg, bitnum)    (Reg^=(1<<bitnum))
#define GET_BIT(Reg, bitnum)    ((Reg>> bitnum ) & 1 )

#define SET_BYTE(Reg,value)      (Reg =value)


#define CONC_BIT(b7,b6,b5,b4,b3,b2,b1,b0)     CONC_help(b7,b6,b5,b4,b3,b2,b1,b0)
#define CONC_help(b7,b6,b5,b4,b3,b2,b1,b0)   0b##b7##b6##b5##b4##b3##b2##b1##b0
 
#endif