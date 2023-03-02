/*
 * WATCHDOG_prog.c
 *
 * Created: 3/1/2023 11:10:05 PM
 *  Author: DELL
 */ 
#include "bit_math.h"
#include "std_types.h"
#include "WATCHDOG_int.h"
#include "WATCHDOG_priv.h"


void WDT_Enable(void)
{
	SET_BIT(WDTCR,3);
	SET_BIT(WDTCR,2);
	SET_BIT(WDTCR,1);
	SET_BIT(WDTCR,0);
}
void WDT_Disable(void)
{
	WDTCR |= ((1<<4)|(1<<3));
	WDTCR =0x00;
}