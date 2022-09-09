#include "Lcd.h"
#include "util/delay.h"


void Enable(void)
{
    PinWrite(E_PIN, HIGH);
    _delay_ms(ENABLE_DELAY);
    PinWrite(E_PIN, LOW);
    _delay_ms(5);
}



void Lcd_init(void)
{
    #if LCD_MODE == LCD_4_BIT
    PinMode(DATA4_PIN, OUTPUT);
    PinMode(DATA5_PIN, OUTPUT);
    PinMode(DATA6_PIN, OUTPUT);
    PinMode(DATA7_PIN, OUTPUT);
    PinMode(RS_PIN, OUTPUT);
    PinMode(RW_PIN, OUTPUT);
    PinMode(E_PIN, OUTPUT);
    PinWrite(RW_PIN, LOW);
    _delay_ms(START_DELAY);
    Lcd_writeCmd(TWO_LINES_4_BIT_MODE);
    Lcd_writeCmd(LCD_4_BIT_MODE_1);
    Lcd_writeCmd(LCD_4_BIT_MODE_2);
    Lcd_writeCmd(DISPLAY_ON_CURSOR_OFF);
    Lcd_writeCmd(CLEAR_DISPLAY);
    Lcd_writeCmd(RETURN_HOME);
    #elif LCD_MODE == LCD_8_BIT
    PinMode(DATA0_PIN, OUTPUT);
    PinMode(DATA1_PIN, OUTPUT); 
    PinMode(DATA2_PIN, OUTPUT);
    PinMode(DATA3_PIN, OUTPUT);
    PinMode(DATA4_PIN, OUTPUT);
    PinMode(DATA5_PIN, OUTPUT);
    PinMode(DATA6_PIN, OUTPUT);
    PinMode(DATA7_PIN, OUTPUT);
    PinMode(RS_PIN, OUTPUT);
    PinMode(RW_PIN, OUTPUT);
    PinMode(E_PIN, OUTPUT);
    PinWrite(RW_PIN, LOW);
    _delay_ms(START_DELAY);
    Lcd_writeCmd(TWO_LINES_8_BIT_MODE);
    Lcd_writeCmd(DISPLAY_ON_CURSOR_OFF);
    Lcd_writeCmd(CLEAR_DISPLAY);
    Lcd_writeCmd(RETURN_HOME);
    #endif
}


void Lcd_writeChar(Uint8 character)
{
    #if LCD_MODE == LCD_8_BIT
    PinWrite(RS_PIN, HIGH);
    LCD_DATA_PORT = character;
    Enable();
    #elif LCD_MODE == LCD_4_BIT
    PinWrite(RS_PIN, HIGH);
    SetNibble(LCD_DATA_PORT, LEFT, character);
    Enable();
    SetNibble(LCD_DATA_PORT, LEFT, (character<<4));
    Enable();
    #endif
    _delay_ms(WAIT_DELAY);
}

void Lcd_writeCmd(Uint8 cmd)
{
    #if LCD_MODE == LCD_8_BIT
    PinWrite(RS_PIN, LOW);
    LCD_DATA_PORT = cmd;
    Enable();
    #elif LCD_MODE == LCD_4_BIT
    PinWrite(RS_PIN, LOW);
    SetNibble(LCD_DATA_PORT, LEFT, cmd);
    
    Enable();
    SetNibble(LCD_DATA_PORT, LEFT, (cmd<<4));
    
    Enable();
    #endif
    _delay_ms(WAIT_DELAY);
}



void Lcd_Clr(void)
{
    Lcd_writeCmd(CLEAR_DISPLAY);
    _delay_ms(2);
}


void Lcd_writeString(Uint8 * str)
{ 
    Uint32 counter = 0;
    while(str[counter] != '\0')
    {
        Lcd_writeChar(str[counter]);
        counter++;
    }
}

void Lcd_goto(Uint8 row, Uint8 col)
{
    Uint8 coords_arr[2] = {0x80, 0xC0};
    Lcd_writeCmd(coords_arr[row] + col);
}

void Lcd_shiftRight(void)
{
    Lcd_writeCmd(LCD_RIGHT_SHIFT);
}

void Lcd_shiftLeft(void)
{
    Lcd_writeCmd(LCD_LEFT_SHIFT);
}

void Lcd_writeNum(f32 num)  //124
{
    #if numtype == INTEGER
    Sint32 new_num = (Sint32)num;
    Sint8 counter = 0;
    Uint8 arr[10 ] = {0};
    Uint8 digit =0;
    if (new_num == 0)
    {
        Lcd_writeChar('0');
    }
    else if (new_num > 0)
    {
        while(new_num != 0)
        {
            digit = new_num % 10;
            arr[counter] = digit;
            new_num = new_num/10;
            counter++;
        }
        counter--;
        for(Sint8 i = counter; i>=0; i--)
        {
            Lcd_writeChar(arr[i] + 48);
        }
    }
    else if (new_num < 0)
    {
        //Lcd_writeChar('p');
        new_num = new_num * (-1);
        while(new_num != 0)
        {
            digit = new_num % 10;
            arr[counter] = digit;
            new_num = new_num/10;
            counter++;
        }
        counter--;
        Lcd_writeChar('-');
        for(Sint8 i = counter; i>=0; i--)
        {
            Lcd_writeChar(arr[i] + 48);
        }
    }
    #elif numtype == FLOAT
    Sint8 intcounter = 0;
    Sint8 floatCounter = 0;
    Uint8 arr_int[10] = {0};
    Uint8 arr_float[10] = {0};
    Uint8 intdigit =0;
    Uint8 floatdigit = 0;
    if (num > 0)
    {
        Uint32 intnum = (Uint32)num;
        Uint32 decnum = (Uint32)((num-intnum)*100);
        while(intnum != 0)
        {
            intdigit = intnum % 10;
            arr_int[intcounter] = intdigit;
            intnum = intnum/10;
            intcounter++;
        }
        intcounter--;
        while(decnum != 0)
        {
            //Lcd_writeChar('p');
            floatdigit = decnum % 10;
            arr_float[floatCounter] = floatdigit;
            decnum = decnum/10;
            floatCounter++;
        }
        floatCounter--;
        for(Sint8 i = intcounter; i>=0; i--)
        {
            Lcd_writeChar(arr_int[i] + 48);
        }
        Lcd_writeChar('.');
        for(Sint8 j = floatCounter; j>=0; j--)
        {
            Lcd_writeChar(arr_float[j] + 48);
        }

    }
    else if ((Sint32)num < 0)
    {
        num = num *(-1);
        Uint32 intnum = (Uint32)num;
        Uint32 decnum = (Uint32)((num-intnum)*100);
        //Lcd_writeChar('d');
        while(intnum != 0)
        {
            intdigit = intnum % 10;
            arr_int[intcounter] = intdigit;
            intnum = intnum/10;
            intcounter++;
        }
        intcounter--;
        while(decnum != 0)
        {
            //Lcd_writeChar('p');
            floatdigit = decnum % 10;
            arr_float[floatCounter] = floatdigit;
            decnum = decnum/10;
            floatCounter++;
        }
        floatCounter--;
        Lcd_writeChar('-');
        for(Sint8 i = intcounter; i>=0; i--)
        {
            Lcd_writeChar(arr_int[i] + 48);
        }
        Lcd_writeChar('.');
        for(Sint8 j = floatCounter; j>=0; j--)
        {
            Lcd_writeChar(arr_float[j] + 48);
        }
    }
    
    #endif
}

