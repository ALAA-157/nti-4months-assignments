/*
 * counter_7seg.c
 *
 * Created: 3/11/2023 9:49:06 AM
 * Author : DELL
 */ 

#define F_CPU 8000000UL
#include "bit_math.h"
#include "std_types.h"
#include "TIMR0_int.h"
#include "TIMR00_Priv.h"
#include "TIMR0_config.h"
#include "glopal_interrupt.h"
#include "dio.h"
#include <avr/delay.h>
#include "ssd.h"
#include "lcd.h"

int main(void)
{
	//ssd_vidInit();
	dio_vidConfigChannel(DIO_PORTB,0,INPUT);
	lcd_init();
	LCD_clearScreen();
	TIMER0_void_Init();
    /* Replace with your application code */
    while (1) 
    {
		LCD_DisplayNumber((u16)TIMER0_Get_Counts());
		_delay_ms(500);
		LCD_clearScreen();
		//SSD_DisplayNum();
    }
}

