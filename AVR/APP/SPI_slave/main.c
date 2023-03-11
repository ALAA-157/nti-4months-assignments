/*
 * spi_slave.c
 *
 * Created: 3/4/2023 2:50:05 PM
 * Author : DELL
 */ 

#define  F_CPU 8000000
#include "bit_math.h"
#include "std_types.h"
#include "SPI_int.h"
#include "SPI_priv.h"
#include "SPI_config.h"
#include "LED.h"
#include "Button.h"

#include "dio.h"
#include "lcd.h"
#include "glopal_interrupt.h"
#include "avr/delay.h"


int main(void)
{
	//lcd_init();
	//LCD_clearScreen();
	led_init();
	SPI_Slave_Init(MSB_FIRST, IDLE_LOW,ZERO,FREQ_DIV_BY_16);
	u8 x;
    /* Replace with your application code */
    while (1) 
    {
		x=SPI_SlaveReceive();
		/*lcd_displyChar(x);
		_delay_ms(500);*/
		if(x == 'r')
		{
			led_toggle(LED_RED);
		}
		else if(x == 'g')
		{
			led_toggle(LED_GREEN);
		}
		else if(x == 'b')
		{
			led_toggle(LED_BLUE);
		}
    }
}

