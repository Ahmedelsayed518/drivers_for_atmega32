#include "../DIO/Dio.h"

#define MCUCR *((volatile Uint8 *)0x55)
#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3

#define MCUCSR *((volatile Uint8 *)0x54)
#define ISC2 6   // --> INT2

#define GICR *((volatile Uint8 *) 0x5B)
#define INT0 6
#define INT1 7
#define INT2 5

#define SREG *((volatile Uint8 *) 0x5F)
#define I 7
