/*
 * SPI.c
 *
 * Created: 3/4/2023 10:39:36 AM
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
	//led_init();
	button_vidInit();
	//LCD_clearScreen();
	//lcd_displyStr("master mode");
	SPI_Master_Init(MSB_FIRST, IDLE_LOW,ZERO,FREQ_DIV_BY_16);
	//u8 i='a';
    /* Replace with your application code */
    while (1) 
    {
		//SPI_MasterSendByte(i);
		/*x=SPI_MasterReadByte();
		LCD_DisplayNumber(x);*/
		//i++;
		//_delay_ms(500);
		if(Button_GetStatus(BUTTON0)==PRESSED)
		{
			_delay_ms(50);
			if(Button_GetStatus(BUTTON0)==PRESSED)
			{
				SPI_MasterSendByte('r');				
			}
			while(Button_GetStatus(BUTTON0)==PRESSED);
		}
		if(Button_GetStatus(BUTTON1)==PRESSED)
		{
			_delay_ms(50);
			if(Button_GetStatus(BUTTON1)==PRESSED)
			{
				SPI_MasterSendByte('g');
			}
			while(Button_GetStatus(BUTTON1)==PRESSED);
		}
		if(Button_GetStatus(BUTTON2)==PRESSED)
		{
			_delay_ms(50);
			if(Button_GetStatus(BUTTON2)==PRESSED)
			{
				SPI_MasterSendByte('b');
			}
			while(Button_GetStatus(BUTTON2)==PRESSED);
		}
		
    }
}

