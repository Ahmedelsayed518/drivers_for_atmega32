#ifndef ADC_INTERFACE_H_INCLUDED
#define ADC_INTERFACE_H_INCLUDED
#include "../../BIT_MATH.h"
#include "../../STD.h"
#include "ADC_REG.h"
#include "ADC_CONFIG.h"

#define CHANNEL_0 0
#define CHANNEL_1 1
#define CHANNEL_2 2
#define CHANNEL_3 3
#define CHANNEL_4 4
#define CHANNEL_5 5
#define CHANNEL_6 6
#define CHANNEL_7 7

#define DIV_FAC_2 2
#define DIV_FAC_4 4
#define DIV_FAC_8 8
#define DIV_FAC_16 16
#define DIV_FAC_32 32
#define DIV_FAC_64 64
#define DIV_FAC_128 128

#define AREF_Internal_Vref_turned_off 1
#define AVCC_with_external_capacitor_at_AREF_pin 2
#define Reserved 3
#define Internal_2_56V_Voltage_Reference_with_external_capacitor_at_AREF_pin 4

#define ADC_LEFT 0
#define ADC_RIGHT 1

#define TRUE 1
#define FALSE 0

#define FREE_RUNNING 0
#define ANALOG_CMOPARATOR 1
#define EXT_INT_REQ_0 2
#define TIMER_COUNTER0_COMPARE_MATCH 3
#define TIMER_COUNTER0_OVF 4
#define TIMER_COUNTER1_COMPARE_MATCH_B 5
#define TIMER_COUNTER1_OVF 6
#define TIMER_COUNTER1_CAPTURE_EVENT 7

void ADC_INIT(void);
Uint16 ADC_READ(void);
#endif