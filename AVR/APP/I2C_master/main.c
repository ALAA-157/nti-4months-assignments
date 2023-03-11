/*
 * I2C_sender.c
 *
 * Created: 3/5/2023 9:23:24 AM
 * Author : DELL
 */ 
#define  F_CPU 8000000
#include "bit_math.h"
#include "std_types.h"
#include "I2C_int.h"
#include "I2C_priv.h"
#include "I2C_config.h"
#include <string.h>


#include "dio.h"
#include "lcd.h"
#include "glopal_interrupt.h"
#include "avr/delay.h"



int main(void)
{
	s8 buffer[10];
	lcd_init();
	I2C_Master_Init();
	
	/*I2C_Master_Write(0x00);
	for (u8 i=0;i<5;i++)
	{
		I2C_Master_Write(arr[i]);
	}
	I2C_Stop();*/
    /* Replace with your application code */
    while (1) 
    {
		I2C_Start(0x20);
		_delay_ms(5);
		for (u8 i=0; i< 10;i++)
		{
			I2C_Master_Write(i);
			_delay_ms(500);
		}
		I2C_Stop();
		
    }
}

