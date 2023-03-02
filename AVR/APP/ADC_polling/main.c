/*
 * ADC_polling.c
 *
 * Created: 2/25/2023 3:49:26 PM
 * Author : DELL
 */ 

#define F_CPU 8000000
#include "ADC_int.h"
#include "ADC_config.h"
#include "ADC_private.h"
#include "dio.h"
#include "lcd.h"




int main(void)
{
	lcd_init();
	LCD_clearScreen();
	ADC_voidInit ();
	ADC_voidAutoTrigger();
	ADC_voidEnable();
	
	u16 adc_result=0;


	/* Replace with your application code */
	while (1)
	{
		ADC_voidStartConversion();
		adc_result=ADC_u16ReadADCInMV(); //reading the value with polling
		LCD_DisplayNumber(adc_result);
		_delay_ms(500);
		LCD_clearScreen();
	}
}