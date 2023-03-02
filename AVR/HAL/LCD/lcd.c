#include "lcd.h"
void lcd_sendCmd(u8 cmd)
{
	dio_vidWriteChannel(LCD_CTRL_PORT, RS, STD_LOW);
	_delay_ms(1);
	dio_vidWriteChannel(LCD_DATA_PORT, DIO_PIN0, CHECK_BIT(cmd,4));
	dio_vidWriteChannel(LCD_DATA_PORT, DIO_PIN1, CHECK_BIT(cmd,5));
	dio_vidWriteChannel(LCD_DATA_PORT, DIO_PIN2, CHECK_BIT(cmd,6));
	dio_vidWriteChannel(LCD_DATA_PORT, DIO_PIN4, CHECK_BIT(cmd,7));
	dio_vidWriteChannel(LCD_CTRL_PORT, E, STD_HIGH);
	_delay_ms(5);
	dio_vidWriteChannel(LCD_CTRL_PORT, E, STD_LOW);
	_delay_ms(5);
	dio_vidWriteChannel(LCD_DATA_PORT, DIO_PIN0, CHECK_BIT(cmd,0));
	dio_vidWriteChannel(LCD_DATA_PORT, DIO_PIN1, CHECK_BIT(cmd,1));
	dio_vidWriteChannel(LCD_DATA_PORT, DIO_PIN2, CHECK_BIT(cmd,2));
	dio_vidWriteChannel(LCD_DATA_PORT, DIO_PIN4, CHECK_BIT(cmd,3));
	_delay_ms(1);
	dio_vidWriteChannel(LCD_CTRL_PORT, E, STD_HIGH);
	_delay_ms(5);
	dio_vidWriteChannel(LCD_CTRL_PORT, E, STD_LOW);
	_delay_ms(5);	
}
void lcd_displyChar(u8 chr)
{
	dio_vidWriteChannel(LCD_CTRL_PORT, RS, STD_HIGH);
	_delay_ms(1);
	dio_vidWriteChannel(LCD_DATA_PORT, DIO_PIN0, CHECK_BIT(chr,4));
	dio_vidWriteChannel(LCD_DATA_PORT, DIO_PIN1, CHECK_BIT(chr,5));
	dio_vidWriteChannel(LCD_DATA_PORT, DIO_PIN2, CHECK_BIT(chr,6));
	dio_vidWriteChannel(LCD_DATA_PORT, DIO_PIN4, CHECK_BIT(chr,7));
	dio_vidWriteChannel(LCD_CTRL_PORT, E, STD_HIGH);
	_delay_ms(5);
	dio_vidWriteChannel(LCD_CTRL_PORT, E, STD_LOW);
	_delay_ms(5);
	dio_vidWriteChannel(LCD_DATA_PORT, DIO_PIN0, CHECK_BIT(chr,0));
	dio_vidWriteChannel(LCD_DATA_PORT, DIO_PIN1, CHECK_BIT(chr,1));
	dio_vidWriteChannel(LCD_DATA_PORT, DIO_PIN2, CHECK_BIT(chr,2));
	dio_vidWriteChannel(LCD_DATA_PORT, DIO_PIN4, CHECK_BIT(chr,3));

	_delay_ms(1);
	dio_vidWriteChannel(LCD_CTRL_PORT, E, STD_HIGH);
	_delay_ms(5);
	dio_vidWriteChannel(LCD_CTRL_PORT, E, STD_LOW);
	_delay_ms(5);
}
void lcd_displyStr(u8* str)
{
	u8 i=0;
	while(str[i]!='\0')
	{
		lcd_displyChar(str[i]);
		i++;
	}
}
void lcd_gotoRowColumn(u8 row, u8 column)
{
	u8 address;
		switch(row)
		{
			case 0:
			address=column;
			break;
			case 1:
			address=column+0x40;
			break;
		}
		lcd_sendCmd(address | SET_CURSOR_LOCATION);
}

void lcd_init(void)
{
	dio_vidConfigChannel(LCD_CTRL_PORT, RS, OUTPUT);
	dio_vidConfigChannel(LCD_CTRL_PORT, E, OUTPUT);
	dio_vidConfigChannel(LCD_DATA_PORT, 0, OUTPUT);
	dio_vidConfigChannel(LCD_DATA_PORT, 1, OUTPUT);
	dio_vidConfigChannel(LCD_DATA_PORT, 2, OUTPUT);
	dio_vidConfigChannel(LCD_DATA_PORT, 4, OUTPUT);
	_delay_ms(40);
	dio_vidWriteChannel(LCD_CTRL_PORT, RS, STD_LOW);
	dio_vidWriteChannel(LCD_DATA_PORT, 0, STD_LOW);
	dio_vidWriteChannel(LCD_DATA_PORT, 1, STD_HIGH);
	dio_vidWriteChannel(LCD_DATA_PORT, 2, STD_LOW);
	dio_vidWriteChannel(LCD_DATA_PORT, 4, STD_LOW);
	
	dio_vidWriteChannel(LCD_CTRL_PORT, E, STD_HIGH);
	_delay_ms(5);
	dio_vidWriteChannel(LCD_CTRL_PORT, E, STD_LOW);
	_delay_ms(5);
	
	 lcd_sendCmd(0b00000010);
	 lcd_sendCmd(0b00101000);  
	_delay_ms(40);
	 lcd_sendCmd(display_on_off);
	 _delay_ms(40);
	 lcd_sendCmd(CLEAR_COMMAND);
	 _delay_ms(40);
	 lcd_sendCmd(entrymode_set);
}
void LCD_clearScreen(void)
{
	lcd_sendCmd(CLEAR_COMMAND);

}
void LCD_DisplayNumber(u16 number)
{
	static u16 converted_number[16];
	u8* ptr =&converted_number[15];
	*ptr='\n';
	if(number == 0)
	{
		ptr--;
		*ptr='0';
	}
	while(number != 0)
	{
		ptr--;
		*ptr = (number%10)+'0';
		number/=10;
	}
	lcd_displyStr(ptr);
}
