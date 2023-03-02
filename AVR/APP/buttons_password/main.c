/*
 * assignment7.c
 *
 * Created: 2/22/2023 11:58:12 PM
 * Author : DELL
 */ 

#define F_CPU 8000000UL
#include "dio.h"
#include "LED.h"
#include <avr/delay.h>
#include "Button.h"
#include "buzzer.h"

int main(void)
{
	u8 true_pass[6]={BUTTON0,BUTTON0,BUTTON1,BUTTON2,BUTTON2,BUTTON2};
	u8 input_pass[6];
	u8 i,flag;
 	led_init();
 	button_vidInit();
	 buzzer_init();
 	while (1)
 	{
		 for(i=0;i<6;i++)
		 {
			 input_pass[i]=3;
		 }
		 i=0;flag=1;
		 while(i < 6)
		 {
			 if(Button_GetStatus(BUTTON0)==PRESSED)
			 {
				 input_pass[i]=BUTTON0;
				 i++;
				 while(Button_GetStatus(BUTTON0)==PRESSED);
			 }
			 if(Button_GetStatus(BUTTON1)==PRESSED)
			 {
				 input_pass[i]=BUTTON1;
				 i++;
				 while(Button_GetStatus(BUTTON1)==PRESSED);
			 }
			 if(Button_GetStatus(BUTTON2)==PRESSED)
			 {
				 input_pass[i]=BUTTON2;
				 i++;
				 while(Button_GetStatus(BUTTON2)==PRESSED);
			 } 
		 }
		 for(i=0;i<6;i++)
		 {
			 if(input_pass[i] !=true_pass[i])
			 {
				 flag=0;
				 break;
			 } 
		 }
		 if (flag == 1)
		 {
			 led_on(LED_GREEN);
	 		_delay_ms(500);
			led_off(LED_GREEN);
		 }
		 else
		 {
			 buzzer_on();
			 _delay_ms(500);
			 buzzer_off();		 
		 }
 	}
}

