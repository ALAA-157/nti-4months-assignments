/*
 * ADC_polling.c
 *
 * Created: 2/25/2023 3:25:40 PM
 * Author : DELL
 */ 

#define F_CPU 8000000
#include "ADC_int.h"
#include "ADC_config.h"
#include "ADC_private.h"
#include "dio.h"
#include "lcd.h"
#include "glopal_interrupt.h"






u16 adc_result;


void ADC_interrupt_result(u16 value)
{
	adc_result=value;
}

int main(void)
{
	lcd_init();
	LCD_clearScreen();
	ADC_voidInit ();
	ADC_voidCallBack(ADC_interrupt_result);
	ADC_voidAutoTrigger();
	ADC_voidEnable();
	ADC_voidInterrputEnable();
	global_interrupt_Enable();

	/* Replace with your application code */
	while (1)
	{
		ADC_voidStartConversion();
		LCD_DisplayNumber(adc_result);
		_delay_ms(500);
		LCD_clearScreen();
	}
}

