/*
 * UART.c
 *
 * Created: 3/3/2023 9:38:44 AM
 * Author : DELL
 */ 

#define  F_CPU 8000000
#include "bit_math.h"
#include "std_types.h"
#include "uart_reg.h"
#include "uart.h"


#include "dio.h"
#include "lcd.h"
#include "glopal_interrupt.h"
#include "avr/delay.h"

u8 Uart_Data='0';
u8 UART_Send_Data='a';

u8 send_UART (void)
{
	return UART_Send_Data;
}

void get_uart_receive(u8 value)
{
	Uart_Data=value;
}
int main(void)
{
	lcd_init();
	UART_Init(UART_BAUDRATE_9600);
	//UART_void_SetRXCallBack(get_uart_receive);
	//UART_void_SetEmptyCallBack(send_UART);
	global_interrupt_Enable();
	//UART_RxInterruptEnable();	
	UART_RxInterruptEnable();
	//UART_Tx_String("alaa");

    /* Replace with your application code */
	//u8 str[10];
	u8 str[200];
    while (1) 
    {
		/*LCD_clearScreen();
		lcd_displyChar(Uart_Data);
		_delay_ms(500);*/
	//	UART_Send_Data++;
		//_delay_ms(500);
		if(UART_Check_Recieve_STR() == 1)
		{
			UART_GetString(str);
			LCD_clearScreen();
			lcd_displyStr(str);
			_delay_ms(500);
		}
		else
		{
			LCD_clearScreen();
			lcd_displyChar('*');
			lcd_displyChar('*');
			lcd_displyChar('*');
			_delay_ms(1000);
		}
    }
}

