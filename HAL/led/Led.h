#ifndef LED_H_
#define LED_H_


#include "../../MCAL/DIO/Dio.h"


#define LED0  PC2
#define LED1  PC7
#define LED2  PD3

void Led_init(Uint8 led_num);
void Led_on(Uint8 led_num);
void Led_off(Uint8 led_num);
void Tog_led(Uint8 led_num);

#endif
