/*
 * ADC_readingAllChannels_Interrupt.c
 *
 * Created: 3/2/2023 2:20:46 PM
 * Author : DELL
 */ 

#define F_CPU 8000000
#include "ADC_int.h"
#include "ADC_config.h"
#include "ADC_private.h"
#include "dio.h"
#include "lcd.h"
#include "glopal_interrupt.h"

u16 adc_result=0;
u8 channel_number=0;

void ADC_interrupt_result(u16 value)
{
	adc_result=value;
	LCD_clearScreen();
	LCD_DisplayNumber(adc_result);
	_delay_ms(500);
	ADC_voidDisable();
	for (u8 i =1 ; i<=7;i++)
	{
		ADC_voidInit ();
		ADC_voidAutoTrigger();
		ADC_voidEnable();
		ADC_voidSelectChannel(i);
		ADC_voidStartConversion();
		adc_result=ADC_u16ReadADCInMV();
		LCD_clearScreen();
		LCD_DisplayNumber(adc_result);
		_delay_ms(500);
	}

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
	//ADC_voidSelectChannel(0);
	//ADC_voidStartConversion();
	/* Replace with your application code */
	while (1)
	{
		
		ADC_voidSelectChannel(0);
		ADC_voidStartConversion();

	}
}

