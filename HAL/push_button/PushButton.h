#ifndef PUSHBUTTON_H_
#define PUSHBUTTON_H_

#include "../../MCAL/DIO/Dio.h"
#include "PushButtonCfg.h"


#define PUSH_BUTTON0 0
#define PUSH_BUTTON1 1
#define PUSH_BUTTON2 2

#define ACTIVE_HIGH 1
#define ACTIVE_LOW 0

#if BUTTON_ARCH == ACTIVE_HIGH
#define PRESSED 1
#define RELEASED 0

#elif BUTTON_ARCH == ACTIVE_LOW
#define PRESSED 0
#define RELEASED 1
#endif

#define PUSHBUTTON_DELAY 100


void PushButton_init(Uint8);
Uint8 PushButtonRead(Uint8);


#endif