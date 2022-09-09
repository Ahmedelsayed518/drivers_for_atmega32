#ifndef LCD_H_
#define LCD_H_

#include "../../MCAL/DIO/Dio.h"
#include "LcdCfg.h"

#define ENABLE_DELAY 1
#define WAIT_DELAY 5
#define START_DELAY 1000

#define TWO_LINES_4_BIT_MODE 0x33
#define LCD_4_BIT_MODE_1 0x32
#define LCD_4_BIT_MODE_2 0x28
#define TWO_LINES_8_BIT_MODE 0x38
#define DISPLAY_ON_CURSOR_OFF 0x0C
#define CLEAR_DISPLAY 0x01
#define RETURN_HOME 0x02

#define LCD_4_BIT 0
#define LCD_8_BIT 1

#define LCD_RIGHT_SHIFT 0x05
#define LCD_LEFT_SHIFT 0x07

#define INT 0
#define FLOAT 1

//void Enable(void);
void Lcd_writeChar(Uint8 character);
void Lcd_writeCmd(Uint8 cmd);
void Lcd_init(void);
void Lcd_writeString(Uint8 * str);
void Lcd_writeNum(f32 num);
void Lcd_Clr(void);
void Lcd_goto(Uint8 row, Uint8 col);
void Lcd_shiftRight(void);
void Lcd_shiftLeft(void);

#endif