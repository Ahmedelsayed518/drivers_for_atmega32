#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

#include "../../BIT_MATH.h"
#include "TIMER_REG.h"
#include "../../REG.h"
#include "TimerCfg.h"
//#include <avr/interrupt.h>

#define NA 15

#define NORMAL 0
#define PWM 1
#define CTC 2
#define FAST_PWM 3

#define TOGGLE 4
#define NON_INV 5
#define INV 6
#define T_CLR 50
#define T_SET 60

#define NO_PRESCALING 0
#define PRE_8 8
#define PRE_64 64
#define PRE_256 256
#define PRE_1024 1024
#define EXT_CLK_FALLING 13
#define EXT_CLK_RISING 14

#define T_TRUE 1
#define T_FALSE 0
#define RESERVED 2

#define FAST_PWM 600
#define PHASE_CORRECT 601

void timer_init(void);
void Timer0_setTime(Uint32);
void Timer0_start(void);
void Timer0_stop(void);
void Timer0_SetCallback(void(*)(void));

void TIMER0_PWM0_init(void);
void TIMER0_PWM0_SetDutyCycle(Uint8 DC);
void TIMER0_PWM0_Start(void);
void TIMER0_PWM0_Stop(void);
#endif