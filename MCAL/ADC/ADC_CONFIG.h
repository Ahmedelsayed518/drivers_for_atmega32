#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

#define ADC_CHANNEL 0  // choose any pin in portA



/*
choose from CHANNEL_0 to CHANNEL_7
*/
#define CHANNEL CHANNEL_1


/*
choose division factor:
* DIV_FAC_2
* DIV_FAC_4
* DIV_FAC_8
* DIV_FAC_16
* DIV_FAC_32
* DIV_FAC_64
* DIV_FAC_128
*/
#define DIV_FAC DIV_FAC_128

/*
chosse one from:
* AREF_Internal_Vref_turned_off
* AVCC_with_external_capacitor_at_AREF_pin
* Reserved
* Internal_2_56V_Voltage_Reference_with_external_capacitor_at_AREF_pin
*/
#define V_REF AVCC_with_external_capacitor_at_AREF_pin
//

/*
if you want to use auto trigger choose TRUE.
if not choose FALSE.
*/
#define AUTO_TRIGGER TRUE

/*
if you choose TRUE in auto trigger
choose one of these trigger sources
* FREE_RUNNING
* ANALOG_CMOPARATOR
* EXT_INT_REQ_0
* TIMER_COUNTER0_COMPARE_MATCH
* TIMER_COUNTER0_OVF
* TIMER_COUNTER1_COMPARE_MATCH_B
* TIMER_COUNTER1_OVF
* TIMER_COUNTER1_CAPTURE_EVENT
*/
#define TRIGGER_SRC FREE_RUNNING

/*
choose adjust ADC_RIGHT or ADC_LEFT
*/
#define ADJUST ADC_RIGHT 


#endif