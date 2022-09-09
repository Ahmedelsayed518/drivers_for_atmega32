#include "Dio.h"

void PinMode(Uint8 Dio_pin, Uint8 Dio_Mode)
{
    /*
    params:
    - Dio_pin => used to select the pin
    - Dio_Mode => used to store the value of the mode (INPUT/OUTPUT).
    usage:
    * used to change the direction of the pin.
    */
    Uint8 pin = Dio_pin%10;
    Uint8 port = Dio_pin/10;

    if (Dio_Mode == OUTPUT)
    {
        switch(port)
        {
            case Dio_portA: SET_BIT(DDRA, pin); break;
            case Dio_portB: SET_BIT(DDRB, pin); break;
            case Dio_portC: SET_BIT(DDRC, pin); break;
            case Dio_portD: SET_BIT(DDRD, pin); break;
            default:                            break;
        }
    }

    else if (Dio_Mode == INPUT)
    {
        switch(port)
        {
            case Dio_portA: CLR_BIT(DDRA, pin); break;
            case Dio_portB: CLR_BIT(DDRB, pin); break;
            case Dio_portC: CLR_BIT(DDRC, pin); break;
            case Dio_portD: CLR_BIT(DDRD, pin); break;
            default:                            break;
        }
    }
}

void PinWrite(Uint8 Dio_pin, Uint8 Dio_logic)
{
    /*
    params:
    - Dio_pin => used to select the pin
    - Dio_logic => used to store the value wanted to be loaded to the pin (HIGH/LOW)
    usage:
    * used to write HIGH or LOW to a certain pin.
    */
    Uint8 pin = Dio_pin%10;
    Uint8 port = Dio_pin/10;

    if (Dio_logic == HIGH)
    {
        switch(port)
        {
            case Dio_portA: SET_BIT(PORTA, pin); break;
            case Dio_portB: SET_BIT(PORTB, pin); break;
            case Dio_portC: SET_BIT(PORTC, pin); break;
            case Dio_portD: SET_BIT(PORTD, pin); break;
            default:                             break;
        }
    }

    else if (Dio_logic == LOW)
    {
        switch(port)
        {
            case Dio_portA: CLR_BIT(PORTA, pin); break;
            case Dio_portB: CLR_BIT(PORTB, pin); break;
            case Dio_portC: CLR_BIT(PORTC, pin); break;
            case Dio_portD: CLR_BIT(PORTD, pin); break;
            default:                             break;
        }
    }
}

Uint8 PinRead(Uint8 Dio_pin)
{
    /*
    params:
    - Dio_pin => used to select the pin
    Usage:
    * used to read the state of the pin choosen.
    */
    Uint8 pin = Dio_pin%10;
    Uint8 port = Dio_pin/10;
    Uint8 Pin_val = 0;
    switch(port)
        {
            case Dio_portA: Pin_val = GET_BIT(PINA, pin); break;
            case Dio_portB: Pin_val = GET_BIT(PINB, pin); break;
            case Dio_portC: Pin_val = GET_BIT(PINC, pin); break;
            case Dio_portD: Pin_val = GET_BIT(PIND, pin); break;
            default:                                      break;
        }
    return Pin_val;
}


void PortMode(Uint8 Dio_port, Uint8 Dio_mode)
{
    /*
    params:
    - Dio_port => used to select the port
    - Dio_mode => used to store the mode choosen (Input/output)
    Usage:
    * used to change the port mode as desired.
    */
    switch(Dio_mode)
    {
        case OUTPUT:
        switch(Dio_port)
        {
            case Dio_portA: DDRA = 255; break;
            case Dio_portB: DDRB = 255; break;
            case Dio_portC: DDRC = 255; break;
            case Dio_portD: DDRD = 255; break;
            default:                    break;
        }
        break;
        case INPUT:
        switch(Dio_port)
        {
            case Dio_portA: DDRA = 0; break;
            case Dio_portB: DDRB = 0; break;
            case Dio_portC: DDRC = 0; break;
            case Dio_portD: DDRD = 0; break;
            default:                  break;
        }
        break;
        default:                      break;
    }
}



void PortWrite(Uint8 Dio_port, Uint8 Port_val)
{
    /*
    params:
    - Dio_port => used to select the port
    - port_val => used to store the value wanted to laod into the port
    usage:
    * used to load a value into a selected port.
    */
    switch(Dio_port)
        {
            case Dio_portA: PORTA = Port_val; break;
            case Dio_portB: PORTB = Port_val; break;
            case Dio_portC: PORTC = Port_val; break;
            case Dio_portD: PORTD = Port_val; break;
            default:                          break;
        }
}


void PinPullUpRes(Uint8 Dio_pin, Uint8 Dio_mode)
{
    /*
    params:
    - Dio_pin => used to select the pin
    - port_val => used to store the mode of the internal pull up (Enable/Disable)
    usage:
    * used to Enable or disable the internal pull up resistor.
    */
    Uint8 pin = Dio_pin%10;
    Uint8 port = Dio_pin/10;
    
    switch(Dio_mode)
    {
        case ENABLE:
        switch(port)
        {
            case Dio_portA: CLR_BIT(DDRA, pin); SET_BIT(PORTA, pin); break;
            case Dio_portB: CLR_BIT(DDRB, pin); SET_BIT(PORTB, pin); break;
            case Dio_portC: CLR_BIT(DDRC, pin); SET_BIT(PORTC, pin); break;
            case Dio_portD: CLR_BIT(DDRD, pin); SET_BIT(PORTD, pin); break;
            default:                             break;
        }
        break;
        case DISABLE:
        switch(port)
        {
            case Dio_portA: CLR_BIT(DDRA, pin); CLR_BIT(PORTA, pin); break;
            case Dio_portB: CLR_BIT(DDRB, pin); CLR_BIT(PORTB, pin); break;
            case Dio_portC: CLR_BIT(DDRC, pin); CLR_BIT(PORTC, pin); break;
            case Dio_portD: CLR_BIT(DDRD, pin); CLR_BIT(PORTD, pin); break;
            default:                             break;
        }
        break;
        default: break;
    }
    
}


void PinToggle(Uint8 Dio_pin)
{
    /*
    params:
    - Dio_pin => used to select the pin
    usage:
    * used to toggle the pin selected.
    */
    Uint8 pin = Dio_pin%10;
    Uint8 port = Dio_pin/10;

    switch(port)
    {
        case Dio_portA: TOG_BIT(PORTA, pin); break;
        case Dio_portB: TOG_BIT(PORTB, pin); break;
        case Dio_portC: TOG_BIT(PORTC, pin); break;
        case Dio_portD: TOG_BIT(PORTD, pin); break;
        default:                             break;
    }
}


void SetNibble(Uint8 port, Uint8 section, Uint8 data)
{
    switch(section)
    {
        case RIGHT:

        switch(port)
        {
            case Dio_portA: PORTA = (PORTA & 0xF0) | (data & 0x0F); break;
            case Dio_portB: PORTB = (PORTB & 0xF0) | (data & 0x0F); break;
            case Dio_portC: PORTC = (PORTC & 0xF0) | (data & 0x0F); break;
            case Dio_portD: PORTD = (PORTD & 0xF0) | (data & 0x0F); break;
            default:                                                break;
        }
        case LEFT:
        switch(port)
        {
            case Dio_portA: PORTA = (PORTA & 0x0F) | (data & 0xF0); break;
            case Dio_portB: PORTB = (PORTB & 0x0F) | (data & 0xF0); break;
            case Dio_portC: PORTC = (PORTC & 0x0F) | (data & 0xF0); break;
            case Dio_portD: PORTD = (PORTD & 0x0F) | (data & 0xF0); break;
            default:                                                break;
        }
        break;
        default:
        break;
    }
}