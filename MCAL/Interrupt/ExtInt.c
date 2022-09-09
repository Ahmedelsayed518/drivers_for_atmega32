
#include "ExtInt.h"
//#include "avr/interrupt.h"
//Uint8 INT_NUM, Uint8 SENSE_CONTROL

///void (*CallBack) (void);
void ExtInt_init(void)
{
    /*
    #if INT_NUM == INT1
    SET_BIT(GICR, INT1); //local interrupt enable
    #if SENSE_CONTROL == RISING_EDGE
    SET_BIT(MCUCR, ISC10);
    SET_BIT(MCUCR, ISC11);
    #elif SENSE_CONTROL == FALLING_EDGE
    CLR_BIT(MCUCR, ISC10);
    SET_BIT(MCUCR, ISC11);
    #elif SENSE_CONTROl == LOGICAL_CHANGE
    SET_BIT(MCUCR, ISC10);
    CLR_BIT(MCUCR, ISC11);
    #elif SENSE_CONTROL == LOW_LEVEL
    CLR_BIT(MCUCR, ISC10);
    CLR_BIT(MCUCR, ISC11);
    #endif
    #elif INT_NUM == INT0
    */
    
    //#if SENSE_CONTROL == RISING_EDGE
    SET_BIT(MCUCR, ISC00);
    SET_BIT(MCUCR, ISC01);
    SET_BIT(GICR, INT0); 
    /*
    #elif SENSE_CONTROL == FALLING_EDGE
    CLR_BIT(MCUCR, ISC00);
    SET_BIT(MCUCR, ISC01);
    #elif SENSE_CONTROl == LOGICAL_CHANGE
    SET_BIT(MCUCR, ISC00);
    CLR_BIT(MCUCR, ISC01);
    #elif SENSE_CONTROL == LOW_LEVEL
    CLR_BIT(MCUCR, ISC00);
    CLR_BIT(MCUCR, ISC01);
    #endif
    #elif INT_NUM == INT2
    SET_BIT(GICR, INT2);
    #if SENSE_CONTROL == FALLING_EDGE
    CLR_BIT(MCUCSR, ISC2);
    #elif SENSE_CONTROL == RISING_EDGE
    SET_BIT(MCUCSR, ISC2);
    #endif
    #endif*/
    SET_BIT(SREG, I);
}
/*
void ExtInt_SetCallback(void (*ptr)(void))
{
    CallBack = ptr;
}

ISR(INT0_vect)
{
    CallBack();
}*/