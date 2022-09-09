#ifndef ADC_REG_H_
#define ADC_REG_H_


#define ADMUX_REG *((volatile Uint8*)0x27)

#define ADLAR 5   // zero if right adjustment, 1 if left adjusted

/*
    to select the voltage reference for ADC
    REFS1 | REFS0 | Voltage Reference Selection
    ------|-------|--------------------------------
    0     |   0   | AREF, Internal Vref turned off 
    0     |   1   | AVCC with external capacitor at AREF pin
    1     |   0   | Reserved
    1     |   1   | Internal 2.56V Voltage Reference with external capacitor at AREF pin
*/
#define REFS0 6   
#define REFS1 7

/*
To select the ADC input channel

MUX4..0 | Single Ended Input
00000   | ADC0
00001   | ADC1
00010   | ADC2
00011   | ADC3
00100   | ADC4
00101   | ADC5
00110   | ADC6
00111   | ADC7

*/
#define MUX0 0
#define MUX1 1
#define MUX2 2
#define MUX3 3
#define MUX4 4

/***********************************************************************************/


#define ADCSRA *((volatile Uint8*)0x26)

#define ADEN 7
#define ADSC 6
#define ADATE 5
#define ADIE 3
#define ADIF 4

/* 

ADPS2 | ADPS1 | ADPS0 | Division Factor
0     |   0   |   0   |      2
0     |   0   |   1   |      2
0     |   1   |   0   |      4
0     |   1   |   1   |      8
1     |   0   |   0   |      16
1     |   0   |   1   |      32
1     |   1   |   0   |      64
1     |   1   |   1   |      128

*/

#define ADPS2 2
#define ADPS1 1
#define ADPS0 0
/******************************************************************/
 
#define SFIOR *((volatile Uint8*)0x50)

#define ADTS0 5
#define ADTS1 6
#define ADTS2 7
/*
ADTS2 | ADTS1 | ADTS0 | Trigger Source
  0   |   0   |   0   | Free Running mode
  0   |   0   |   1   | Analog Comparator
  0   |   1   |   0   | External Interrupt Request 0
  0   |   1   |   1   | Timer/Counter0 Compare Match
  1   |   0   |   0   | Timer/Counter0 Overflow
  1   |   0   |   1   | Timer/Counter1 Compare Match B
  1   |   1   |   0   | Timer/Counter1 Overflow
  1   |   1   |   1   | Timer/Counter1 Capture Event
*/

/******************************************************************************/
#define ADCH_REG *((volatile Uint8*)0x25)
#define ADCL_REG *((volatile Uint8*)0x24)

#define ADC_ADJUST *((volatile Uint16*)0x24)

#endif

