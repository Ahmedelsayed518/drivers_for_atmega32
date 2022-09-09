#ifndef TIMERCFG_H_
#define TIMERCFG_H_


/*
select the mode:
*   NORMAL
*   CTC
*/
#define MODE NORMAL

/*
select Fast pwm optoins:
*   NON_INV
*   INV
*   NORMAL
*/
#define FAST_PWM0_MODE NON_INV


/*
select PWM options:
*   FAST_PWM0
*   PHASE_CORRECT
*/
#define PWM0_MODE PHASE_CORRECT


/*
select pwm optoins for phase correct:
*   NON_INV
*   INV
*   NORMAL
*/
#define PHASE_CORRECT0_MODE NON_INV

/*
select the co mode 
*   NORMAL
*   TOGGLE
*   T_SET
*   T_CLR
*/
#define CO_MODE NORMAL


/*
select the prescalling:
*   NO_PRESCALING
*   PRE_8
*   PRE_64
*   PRE_256
*   PRE_1024
*   EXT_CLK_FALLING
*   EXT_CLK_RISING
*/
#define CLK_SEL PRE_1024


/*
select whether you want to Enable the inturrupt or not:
*   T_TRUE
*   T_FALSE
*/
#define INT_E T_TRUE

/*
type the clock frequancy of your micro-controller (with MHZ)
*/
#define CLK_FRQ 16

#endif