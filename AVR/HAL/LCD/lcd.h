/*
 * lcd.h
 *
 * Created: 2/18/2023 1:18:43 PM
 *  Author: DELL
 */ 


#ifndef LCD_H_
#define LCD_H_

#define F_CPU 8000000UL
#include "avr/delay.h"
#include "dio_types.h"
#include "bit_math.h"
#include "dio.h"
#include "dio_reg.h"
#include "std_types.h"


#define RS DIO_PIN3
#define E  DIO_PIN2
#define LCD_CTRL_PORT DIO_PORTA
#define LCD_DATA_PORT DIO_PORTB

#define CLEAR_COMMAND 0x01
#define FOUR_BITS_DATA_MODE 0x02
#define TWO_LINE_LCD_Four_BIT_MODE 0x28
#define TWO_LINE_LCD_Eight_BIT_MODE 0x38
#define CURSOR_OFF 0x0C
#define CURSOR_ON 0x0E
#define SET_CURSOR_LOCATION 0x80
#define display_on_off 0b00001100
#define entrymode_set 0b00000110


void lcd_sendCmd(u8 cmd);
void lcd_gotoRowColumn(u8 row, u8 column);
void lcd_displyChar(u8 chr);
void lcd_displyStr(u8* str);
void lcd_init(void);
void LCD_clearScreen(void);
void LCD_DisplayNumber(u16 number);



#endif /* LCD_H_ */