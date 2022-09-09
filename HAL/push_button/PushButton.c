
#include "PushButton.h"
#include "util/delay.h"

void PushButton_init(Uint8 pushButton_num)
{
    switch(pushButton_num)
    {
        case PUSH_BUTTON0: PinMode(PUSH_BUTTON0_PIN, INPUT); break;
        case PUSH_BUTTON1: PinMode(PUSH_BUTTON1_PIN, INPUT); break;
        case PUSH_BUTTON2: PinMode(PUSH_BUTTON2_PIN, INPUT); break;
        default:                                              break;
    }
}


Uint8 PushButtonRead(Uint8 Push_Button)
{
    Uint8 Ret_val = 0;
    switch(Push_Button)
    {
        case PUSH_BUTTON0: 
        if (PinRead(PUSH_BUTTON0_PIN) == PRESSED)
        {
            _delay_ms(PUSHBUTTON_DELAY);
            if (PinRead(PUSH_BUTTON0_PIN) == RELEASED)
            {
                Ret_val = PRESSED;
            }
        }
        break;
        case PUSH_BUTTON1:
        if (PinRead(PUSH_BUTTON1_PIN) == PRESSED)
        {
            _delay_ms(PUSHBUTTON_DELAY);
            if (PinRead(PUSH_BUTTON1_PIN) == RELEASED)
            {
                Ret_val = PRESSED;
            }
        }
        break;
        case PUSH_BUTTON2: 
        if (PinRead(PUSH_BUTTON2_PIN) == PRESSED)
        {
            _delay_ms(PUSHBUTTON_DELAY);
            if (PinRead(PUSH_BUTTON2_PIN) == RELEASED)
            {
                Ret_val = PRESSED;
            }
        }
        break;
        default:
        break;
    }   
    return Ret_val;
}
