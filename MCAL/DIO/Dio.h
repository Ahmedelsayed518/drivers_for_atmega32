#ifndef DIO_H_
#define DIO_H_



/****************includes**************/
#include "../../BIT_MATH.h"
#include "../../REG.h"


/**********DIO_PINS*********************/
#define PA0 10
#define PA1 11
#define PA2 12
#define PA3 13
#define PA4 14
#define PA5 15
#define PA6 16
#define PA7 17

#define PB0 20
#define PB1 21
#define PB2 22
#define PB3 23
#define PB4 24
#define PB5 25
#define PB6 26
#define PB7 27

#define PC0 30
#define PC1 31
#define PC2 32
#define PC3 33
#define PC4 34
#define PC5 35
#define PC6 36
#define PC7 37

#define PD0 40
#define PD1 41
#define PD2 42
#define PD3 43
#define PD4 44
#define PD5 45
#define PD6 46
#define PD7 47


/********HELPER_MACROS*****************/
#define INPUT 0
#define OUTPUT 1

#define HIGH 1
#define LOW 0


/***********DIO_PORTS*****************/
#define Dio_portA 1
#define Dio_portB 2
#define Dio_portC 3
#define Dio_portD 4


#define ENABLE 1
#define DISABLE 0


#define RIGHT 0
#define LEFT 1
/*
#define Dio_pin0 0
#define Dio_pin1 1
#define Dio_pin2 2
#define Dio_pin3 3
#define Dio_pin4 4
#define Dio_pin5 5
#define Dio_pin6 6
#define Dio_pin7 7
*/


/***********FUNCTIONS_PROTOTYPES*************/
void PinMode(Uint8 Dio_pin, Uint8 Dio_Mode);
void PinWrite(Uint8 Dio_pin, Uint8 Dio_logic);
Uint8 PinRead(Uint8 Dio_pin);
void PortMode(Uint8 Dio_port, Uint8 Dio_mode);
void PortWrite(Uint8 Dio_port, Uint8 Port_val);
void PinPullUpRes(Uint8 Dio_pin, Uint8 Dio_mode);
void PinToggle(Uint8 Dio_pin);
void SetNibble(Uint8 port, Uint8 section, Uint8 data);
#endif
