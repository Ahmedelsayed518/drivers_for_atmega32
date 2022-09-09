/* HI, it's AHMED driver*/

#ifndef REG_H_
#define REG_H_
#include "STD.h"
/* defining DDR registers and their addresses */
#define DDRA *((volatile Uint8*)0x3A)
#define DDRB *((volatile Uint8*)0x37)
#define DDRC *((volatile Uint8*)0x34)
#define DDRD *((volatile Uint8*)0x31)

/* defining PIN registers and thier addresses */ 
#define PINA *((volatile Uint8*)0x39)
#define PINB *((volatile Uint8*)0x36)
#define PINC *((volatile Uint8*)0x33)
#define PIND *((volatile Uint8*)0x30)

/* defining PORT registers and thier addresses */
#define PORTA *((volatile Uint8*)0x3B)
#define PORTB *((volatile Uint8*)0x38)
#define PORTC *((volatile Uint8*)0x35)
#define PORTD *((volatile Uint8*)0x32)

#endif
