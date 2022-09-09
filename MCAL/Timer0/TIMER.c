 
#include "avr/interrupt.h"
#include "TIMER_INTERFACE.h"
Uint32 Global_NumOf_OVF = 0;
Uint8 Global_remTicks = 0;
Uint32 Global_No_of_cmpMatch = 0;



void (*callback) (void);

void timer_init(void)
{
    #if MODE == NORMAL
    CLR_BIT(TCCR0, WGM00);
    CLR_BIT(TCCR0, WGM01);
    #elif MODE == CTC
    CLR_BIT(TCCR0, WGM00);
    SET_BIT(TCCR0, WGM01);
    #endif
    #if MODE == CTC && CO_MODE == NORMAL
    CLR_BIT(TCCR0, COM00);
    CLR_BIT(TCCR0, COM01);
    #elif MODE == CTC && CO_MODE == TOGGLE
    SET_BIT(TCCR0, COM00);
    CLR_BIT(TCCR0, COM01);
    #elif MODE == CTC && CO_MODE == T_CLR
    CLR_BIT(TCCR0, COM00);
    SET_BIT(TCCR0, COM01);
    #elif MODE == CTC && CO_MODE == T_SET
    SET_BIT(TCCR0, COM00);
    SET_BIT(TCCR0, COM01);
    #endif
    ///
    #if INT_E == T_TRUE && MODE == CTC
    SET_BIT(TIMSK, OCIE0);
    SET_BIT(SREG, I_BIT);
    #elif INT_E == T_TRUE && MODE == NORMAL && (FAST_PWM0_MODE != NON_INV && FAST_PWM0_MODE != INV)
    SET_BIT(TIMSK, TOIE0);
    SET_BIT(SREG, I_BIT);
    #elif INT_E == T_FALSE
    CLR_BIT(TIMSK, OCIE0);
    CLR_BIT(TIMSK, TOIE0);
    #endif
}


void TIMER0_PWM0_init(void)
{
    // to make pd3 --> output
    SET_BIT(DDRB, 3);
    #if PWM0_MODE == FAST_PWM0
    //to select fast pwm mode 
    SET_BIT(TCCR0, WGM00);
    SET_BIT(TCCR0, WGM01);
    #if FAST_PWM0_MODE == NORMAL
    CLR_BIT(TCCR0, COM00);
    CLR_BIT(TCCR0, COM01);
    #elif FAST_PWM0_MODE == NON_INV
    CLR_BIT(TCCR0, COM00);
    SET_BIT(TCCR0, COM01);
    #elif FAST_PWM0_MODE == INV
    SET_BIT(TCCR0, COM00);
    SET_BIT(TCCR0, COM01);
    #endif
    #elif PWM0_MODE == PHASE_CORRECT
    SET_BIT(TCCR0, WGM00);
    CLR_BIT(TCCR0, WGM01);
    #if PHASE_CORRECT0_MODE == NORMAL
    CLR_BIT(TCCR0, COM00);
    CLR_BIT(TCCR0, COM01);
    #elif PHASE_CORRECT0_MODE == INV
    CLR_BIT(TCCR0, COM00);
    SET_BIT(TCCR0, COM01);
    #elif PHASE_CORRECT0_MODE == NON_INV
    SET_BIT(TCCR0, COM00);
    SET_BIT(TCCR0, COM01);
    #endif
    #endif
}

void TIMER0_PWM0_Start(void)
{
    Timer0_start();
}
awww.l,**
void TIMER0_PWM0_Stop(void)
{
    Timer0_stop();
}

void TIMER0_PWM0_SetDutyCycle(Uint8 DC)
{
    #if PWM0_MODE == FAST_PWM0
    #if FAST_PWM0_MODE == NON_INV
    OCR0 = ((DC * 256)/100) - 1;
    #elif FAST_PWM0_MODE == INV
    OCR0 = 257 - ((DC * 256)/100);
    #endif
    #elif PWM0_MODE == PHASE_CORRECT
    #if PHASE_CORRECT0_MODE == NON_INV
    OCR0 = (DC * 255) / 100;
    #elif PHASE_CORRECT0_MODE == INV
    OCR0 = 255 - ((DC * 255) / 100);
    #endif
    #endif
}

void Timer0_setTime(Uint32 time)
{
    Uint32 TickTime = CLK_SEL/CLK_FRQ; // result in Seconds
    Uint32 TotalTicks = (time*1000)/TickTime;
    #if MODE == NORAML
    Global_NumOf_OVF = TotalTicks/256;
    Global_remTicks = TotalTicks%256;
    if (Global_remTicks != 0)
    {
        TCNT0 = 256 - Global_remTicks;
        Global_NumOf_OVF++;
    }
    #elif MODE == CTC
    Uint8 div_num = 255;
    while(TotalTicks%div_num)
    {
        div_num--;
    }
    Global_No_of_cmpMatch = TotalTicks/div_num;
    OCR0 = div_num - 1;
    #elif MODE == FAST_PWM
     
    #endif
}


void Timer0_start(void)
{
    #if CLK_SEL == NO_PRESCALING
    SET_BIT(TCCR0, CS00);
    CLR_BIT(TCCR0, CS01);
    CLR_BIT(TCCR0, CS02);
    #elif CLK_SEL == PRE_8
    CLR_BIT(TCCR0, CS00);
    SET_BIT(TCCR0, CS01);
    CLR_BIT(TCCR0, CS02);
    #elif CLK_SEL == PRE_64
    SET_BIT(TCCR0, CS00);
    SET_BIT(TCCR0, CS01);
    CLR_BIT(TCCR0, CS02);
    #elif CLK_SEL == PRE_256
    CLR_BIT(TCCR0, CS00);
    CLR_BIT(TCCR0, CS01);
    SET_BIT(TCCR0, CS02);
    #elif CLK_SEL == PRE_1024
    SET_BIT(TCCR0, CS00);
    CLR_BIT(TCCR0, CS01);
    SET_BIT(TCCR0, CS02);
    #elif CLK_SEL == EXT_CLK_FALLING
    CLR_BIT(TCCR0, CS00);
    SET_BIT(TCCR0, CS01);
    SET_BIT(TCCR0, CS02);
    #elif CLK_SEL == EXT_CLK_RISING
    SET_BIT(TCCR0, CS00);
    SET_BIT(TCCR0, CS01);
    SET_BIT(TCCR0, CS02);
    #endif
}


void Timer0_stop(void)
{
    // to disable the timer
    CLR_BIT(TCCR0, CS01);
    CLR_BIT(TCCR0, CS00);
    CLR_BIT(TCCR0, CS02);
}

void Timer0_SetCallback(void(*ptr)(void))
{
    callback = ptr;
}

#if MODE == NORMAL
ISR(TIMER0_OVF_vect)
{
    
    static Uint32 counter = 0;
    counter++;
    if (counter == Global_NumOf_OVF)
    {
        callback();
        counter = 0;
        TCNT0 = 256 - Global_remTicks; 
        
    }
}
#elif MODE == CTC
ISR(TIMER0_COMP_vect)
{
    static Uint32 counter = 0;
    counter++;
    if (counter == Global_No_of_cmpMatch)
    {
        callback();
        counter = 0;
    }
}
#endif