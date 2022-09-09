#ifndef TiMER_REG_H_
#define TIMER_REG_H_

#include "../../STD.h"

#define TCCR0 *((volatile Uint8*)0x53)
#define WGM00 6  //clr
#define WGM01 3  //clr 

#define COM00 4
#define COM01 5

#define CS02 2   //set
#define CS01 1   //clr
#define CS00 0   //clr

#define TCNT0 *((volatile Uint8*)0x52)

//#define OCR0 *((volatile Uint8*)0x5C)
#define TIFR *((volatile Uint8*)0x58)

#define OVR 0

#define TIMSK *((volatile Uint8*)0x59)
#define TOIE0 0  //set
#define OCIE0 1

#define SREG *((volatile Uint8*)0x5F)
#define I_BIT 7 //set

#define OCR0 *((volatile Uint8*)0x5C)

#endif