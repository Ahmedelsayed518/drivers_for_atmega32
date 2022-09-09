
#include "Led.h"


void Led_init(Uint8 led_num)
{
    PinMode(led_num, OUTPUT);
}

void Led_on(Uint8 led_num)
{
    PinWrite(led_num, HIGH);
}

void Led_off(Uint8 led_num)
{
    PinWrite(led_num, LOW);
}

void Tog_led(Uint8 led_num)
{
    PinToggle(led_num);
}