#ifndef EXTINTCFG_H_
#define EXTINTCFG_H_

#include "ExtIntREG.h"
/********************SELECT_SENSE_CONTROL********************/
/*
options for sense control:
*   RISING_EDGE
*   FALLING_EDGE
*   LOGICAL_CHANGE
*   LOW_LEVEL
*/
#define SENSE_CONTROL RISING_EDGE

/****************SELECT_INTERRUPT_NUMBER****************/
/*
options for selecting the interrupt number:
*   INT0
*   INT1
*   INT2
*/
#define INT_NUM INT0


/***************************** MACROS ********************/
#define RISING_EDGE 0
#define FALLING_EDGE 1
#define LOGICAL_CHANGE 2
#define LOW_LEVEL 3

#endif