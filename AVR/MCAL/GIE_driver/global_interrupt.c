/*
 * global_interrupt.c
 *
 * Created: 2/25/2023 3:12:27 PM
 *  Author: DELL
 */ 


#include "bit_math.h"
#include "std_types.h"

#include "glopal_interrupt.h"

void global_interrupt_Enable(void)
{
		SET_BIT(SREG,7);
}
void global_interrupt_Desable(void)
{
			CLEAR_BIT(SREG,7);
}