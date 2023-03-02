/*
 * ssd.c
 *
 * Created: 2/23/2023 2:43:47 PM
 *  Author: DELL
 */ 
#define F_CPU 8000000
#include <avr/delay.h>
#include "ssd.h"

void ssd_vidInit(void)
{
	dio_vidConfigChannel(ssd_dataA_port,ssd_dataA_pin,OUTPUT);
	dio_vidConfigChannel(ssd_dataB_port,ssd_dataB_pin,OUTPUT);
	dio_vidConfigChannel(ssd_dataC_port,ssd_dataC_pin,OUTPUT);
	dio_vidConfigChannel(ssd_dataD_port,ssd_dataD_pin,OUTPUT);
	
	dio_vidConfigChannel(ssd_E1_port,ssd_E1_pin,OUTPUT);
	dio_vidConfigChannel(ssd_E2_port,ssd_E2_pin,OUTPUT);
	dio_vidConfigChannel(ssd_E3_port,ssd_E3_pin,OUTPUT);
	dio_vidConfigChannel(ssd_E4_port,ssd_E4_pin,OUTPUT);
	
	dio_vidWriteChannel(ssd_E1_port, ssd_E1_pin, STD_LOW);
	dio_vidWriteChannel(ssd_E2_port, ssd_E2_pin, STD_LOW);
	dio_vidWriteChannel(ssd_E3_port, ssd_E3_pin, STD_LOW);
	dio_vidWriteChannel(ssd_E4_port, ssd_E4_pin, STD_LOW);
}
void SSD_DisplayNum(u16 num)
{
	/************get every digit of the number alone*************/
	
	u8 first_digit,second_digit,third_digit,fourth_digit;
	first_digit=num%10;
	num=num/10;
	second_digit=num%10;
	num=num/10;
	third_digit=num%10;
	num=num/10;
	fourth_digit=num%10;
	
	/***********display first digit***********/
	
	dio_vidWriteChannel(ssd_dataA_port,ssd_dataA_pin, CHECK_BIT(first_digit,0));
	dio_vidWriteChannel(ssd_dataB_port,ssd_dataB_pin, CHECK_BIT(first_digit,1));
	dio_vidWriteChannel(ssd_dataC_port,ssd_dataC_pin, CHECK_BIT(first_digit,2));
	dio_vidWriteChannel(ssd_dataD_port,ssd_dataD_pin, CHECK_BIT(first_digit,3));

	dio_vidWriteChannel(ssd_E1_port, ssd_E1_pin, STD_LOW);
	dio_vidWriteChannel(ssd_E2_port, ssd_E2_pin, STD_HIGH);
	dio_vidWriteChannel(ssd_E3_port, ssd_E3_pin, STD_HIGH);
	dio_vidWriteChannel(ssd_E4_port, ssd_E4_pin, STD_HIGH);
	
	_delay_ms(5);
	
	/***********display second digit***********/
	
	dio_vidWriteChannel(ssd_dataA_port,ssd_dataA_pin, CHECK_BIT(second_digit,0));
	dio_vidWriteChannel(ssd_dataB_port,ssd_dataB_pin, CHECK_BIT(second_digit,1));
	dio_vidWriteChannel(ssd_dataC_port,ssd_dataC_pin, CHECK_BIT(second_digit,2));
	dio_vidWriteChannel(ssd_dataD_port,ssd_dataD_pin, CHECK_BIT(second_digit,3));

	dio_vidWriteChannel(ssd_E1_port, ssd_E1_pin, STD_HIGH);
	dio_vidWriteChannel(ssd_E2_port, ssd_E2_pin, STD_LOW);
	dio_vidWriteChannel(ssd_E3_port, ssd_E3_pin, STD_HIGH);
	dio_vidWriteChannel(ssd_E4_port, ssd_E4_pin, STD_HIGH);
	
	_delay_ms(5);
	
	/***********display third digit***********/
	
	dio_vidWriteChannel(ssd_dataA_port,ssd_dataA_pin, CHECK_BIT(third_digit,0));
	dio_vidWriteChannel(ssd_dataB_port,ssd_dataB_pin, CHECK_BIT(third_digit,1));
	dio_vidWriteChannel(ssd_dataC_port,ssd_dataC_pin, CHECK_BIT(third_digit,2));
	dio_vidWriteChannel(ssd_dataD_port,ssd_dataD_pin, CHECK_BIT(third_digit,3));

	dio_vidWriteChannel(ssd_E1_port, ssd_E1_pin, STD_HIGH);
	dio_vidWriteChannel(ssd_E2_port, ssd_E2_pin, STD_HIGH);
	dio_vidWriteChannel(ssd_E3_port, ssd_E3_pin, STD_LOW);
	dio_vidWriteChannel(ssd_E4_port, ssd_E4_pin, STD_HIGH);
	
	_delay_ms(5);

	/***********display fourth digit***********/
	
	dio_vidWriteChannel(ssd_dataA_port,ssd_dataA_pin, CHECK_BIT(fourth_digit,0));
	dio_vidWriteChannel(ssd_dataB_port,ssd_dataB_pin, CHECK_BIT(fourth_digit,1));
	dio_vidWriteChannel(ssd_dataC_port,ssd_dataC_pin, CHECK_BIT(fourth_digit,2));
	dio_vidWriteChannel(ssd_dataD_port,ssd_dataD_pin, CHECK_BIT(fourth_digit,3));

	dio_vidWriteChannel(ssd_E1_port, ssd_E1_pin, STD_HIGH);
	dio_vidWriteChannel(ssd_E2_port, ssd_E2_pin, STD_HIGH);
	dio_vidWriteChannel(ssd_E3_port, ssd_E3_pin, STD_HIGH);
	dio_vidWriteChannel(ssd_E4_port, ssd_E4_pin, STD_LOW);
	
	_delay_ms(5);
}
