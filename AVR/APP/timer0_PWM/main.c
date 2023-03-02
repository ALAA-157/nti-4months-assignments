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
//u8 ticks_num=0,timer0_init_value=0;
/*void delay_ms_timer0(u16 msec)
{
	f32 T = (u8)((TIMER0_PRESCALER*256)/F_CPU);
	if(((msec*0.001) % T)==0)
	{
		ticks_num= (u8)((msec*0.001) / T);
	}
	else
	{
		ticks_num= (u8)((msec*0.001) / T)+1;
	}
	timer0_init_value=(u8)(((msec*0.001) % T)*256);
}*/
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
		//TIMER0_void_SetTimerReg(66);
	}
	
}
int main(void)
{
	/*led_init ();
	TIMER2_void_Init();
	TIMER2_void_SetTimerReg(66);
	TIMER2_void_SetOVCallBack(timer_delay);
	global_interrupt_Enable();
	TIMER2_void_EnableOVInt();*/
	dio_vidConfigChannel(DIO_PORTB, 3, OUTPUT);
	//led_init ();
	TIMER0_void_Init();
	
	//TIMER0_void_SetCTCCallBack(timer_delay);
	
	//TIMER0_void_EnableCTCInt();
	//global_interrupt_Enable();
	
    /* Replace with your application code */
    while (1) 
    {
		for(u8 i =0;i<256;i++)
		{
			TIMER0_void_SetCompareVal(i);
			
		}

    }
}
