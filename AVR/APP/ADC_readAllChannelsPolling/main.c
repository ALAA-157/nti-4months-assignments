/*
 * ADC_readingAllChannels.c
 *
 * Created: 2/25/2023 8:25:50 PM
 * Author : Dell
 */ 
#define F_CPU 8000000
#include "ADC_int.h"
#include "ADC_config.h"
#include "ADC_private.h"
#include "dio.h"
#include "lcd.h"

u16 adc_result=0;

void ADC_ReadAllChannel (void)
{
	for(u8 i=0;i<=7;i++)
	{
		ADC_voidSelectChannel(i);
		ADC_voidStartConversion();
		adc_result=ADC_u16ReadADCInMV();
		LCD_DisplayNumber(adc_result);
		_delay_ms(500);
		LCD_clearScreen();
	}
}

int main(void)
{
	lcd_init();
	LCD_clearScreen();
	ADC_voidInit ();
	ADC_voidAutoTrigger();
	ADC_voidEnable();

	/* Replace with your application code */
	while (1)
	{
		ADC_ReadAllChannel ();
	}
}