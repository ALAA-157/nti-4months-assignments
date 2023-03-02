/*
 * ADC.c
 *
 * Created: 2/24/2023 3:23:06 PM
 * Author : DELL
 */ 
#define F_CPU 8000000
#include "ADC_int.h"
#include "ADC_config.h"
#include "ADC_private.h"
#include "dio.h"
#include "lcd.h"
#include "EXTI0_int.h"
#include "EXTI0_config.h"
#include "EXTI0_private.h"
#include "glopal_interrupt.h"


u16 adc_result;

void ISR_0 (void)
{
	
}
void ADC_interrupt_result(u16 value)
{
	adc_result=value;
}

int main(void)
{
	lcd_init();
	LCD_clearScreen();
	EXT0_voidCallBack(ISR_0);
	EXT0_voidInit();
	ADC_voidInit ();
	ADC_voidCallBack(ADC_interrupt_result);
	ADC_voidAutoTrigger();
	ADC_voidEnable();
	ADC_voidInterrputEnable();
	EXT0_voidEnable();
	global_interrupt_Enable();

    /* Replace with your application code */
    while (1) 
    {
		
		LCD_DisplayNumber(adc_result);
		_delay_ms(500);
		LCD_clearScreen();
    }
}

