/*
 * internal_eeprom.c
 *
 * Created: 3/11/2023 10:31:56 AM
 * Author : DELL
 */ 

#define  F_CPU 8000000
#include "bit_math.h"
#include "std_types.h"
#include "dio.h"
#include "lcd.h"
#include "EEPROM_Interface.h"
#include "EEPROM_Private.h"

int main(void)
{
	lcd_init();
	for (u8 i =1;i<6;i++)
	{
		EEPROM_write(i,5*i);
	}
    /* Replace with your application code */
    while (1) 
    {
		u8 data;
		for (u8 i =1;i<6;i++)
		{
			data=EEPROM_read(i);
			LCD_clearScreen();
			LCD_DisplayNumber(data);
			_delay_ms(1000);
		}
    }
}

