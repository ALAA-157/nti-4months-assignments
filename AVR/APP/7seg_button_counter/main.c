/*
 * assignment8.c
 *
 * Created: 2/23/2023 2:39:09 PM
 * Author : DELL
 */ 
#define F_CPU 8000000UL
#include "dio.h"
#include <avr/delay.h>
#include "ssd.h"
#include "Button.h"

int main(void)
{
    /* Replace with your application code */
	ssd_vidInit();
   	button_vidInit();
	u16 counter=0;

    while (1) 
    {
	 	if(Button_GetStatus(BUTTON0)==PRESSED)
		 {
			 _delay_ms(250);
			 if(Button_GetStatus(BUTTON0)==PRESSED)
			 {
				if (counter < 99)
				{
					counter++;
				} 
			 }
			 while (Button_GetStatus(BUTTON0)==PRESSED);
		 }
		if(Button_GetStatus(BUTTON2)==PRESSED)
		{
			 _delay_ms(250);
			 if(Button_GetStatus(BUTTON2)==PRESSED)
			 {
				if (counter > 0)
				{
					counter--;
				} 
			 }
			 while (Button_GetStatus(BUTTON2)==PRESSED);

		}
		if((counter<=99)&&(counter>=0))
		{
					SSD_DisplayNum(counter);
			
		}

    }
}

