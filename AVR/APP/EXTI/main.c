#define F_CPU 8000000UL
#include "dio.h"
#include "LED.h"
#include "EXTI2_int.h"
#include "EXTI2_config.h"
#include "EXTI2_private.h"
#include "EXTI0_int.h"
#include "EXTI0_config.h"
#include "EXTI0_private.h"
#include "EXTI1_int.h"
#include "EXTI1_config.h"
#include "EXTI1_private.h"
#include "glopal_interrupt.h"

#include <util/delay.h>

void ISR_0 (void)
{
	led_toggle(LED_RED);
}
void ISR_1 (void)
{
	global_interrupt_Enable();
	while (1)
	{
			led_toggle(LED_GREEN);
			_delay_ms(500);
	}

}
void ISR_2 (void)
{
	led_toggle(LED_YELLOW);
}

int main(void)
{
	led_init();
	EXT1_voidCallBack(ISR_1);
	EXT0_voidCallBack(ISR_0);
	EXT2_voidCallBack(ISR_2);
	EXT0_voidInit();
	EXT1_voidInit();
	EXT2_voidInit();
	EXT0_voidEnable();
	EXT1_voidEnable();
	EXT2_voidEnable();
	global_interrupt_Enable();
	while(1)
	{
		
	}
}

