#define F_CPU 8000000
#include "bit_math.h"
#include "std_types.h"
#include "TIMR0_int.h"
#include "TIMR00_Priv.h"
#include "TIMR0_config.h"
#include "TIMR2_int.h"
#include "TIMR2_Priv.h"
#include "TIMR2_config.h"
#include "LED.h"
#include "led_cfg.h"
#include "glopal_interrupt.h"


u8 counter_tick =0;
void timer_delay (void)
{
	if (counter_tick < 5)
	{
		counter_tick++;
	}
	else if (counter_tick==5)
	{
		counter_tick=0;
		led_toggle(LED_RED);
		TIMER2_void_SetTimerReg(66);
	}
	
}
int main(void)
{
	
	dio_vidConfigChannel(DIO_PORTB, 3, OUTPUT);
	TIMER0_void_Init();
    while (1) 
    {
		for(u8 i =0;i<256;i++)
		{
			TIMER0_void_SetCompareVal(i);
			
		}

    }
}
