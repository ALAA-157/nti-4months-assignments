/*
 * counter_7seg.c
 *
 * Created: 3/11/2023 9:49:06 AM
 * Author : DELL
 */ 

#define F_CPU 8000000UL
#include "bit_math.h"
#include "std_types.h"
#include "TIMR0_int.h"
#include "TIMR00_Priv.h"
#include "TIMR0_config.h"
#include "glopal_interrupt.h"
#include "dio.h"
#include <avr/delay.h>
#include "ssd.h"


int main(void)
{
	ssd_vidInit();
	TIMER0_void_Init();
    /* Replace with your application code */
    while (1) 
    {
		SSD_DisplayNum((u16)TIMER0_Get_Counts());
    }
}

