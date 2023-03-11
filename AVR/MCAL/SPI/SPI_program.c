/*
 * SPI_program.c
 *
 * Created: 3/4/2023 1:25:29 PM
 *  Author: DELL
 */ 
#include "bit_math.h"
#include "std_types.h"
#include "dio.h"

#include "SPI_int.h"
#include "SPI_priv.h"
#include "SPI_config.h"

void (*SPI_callback)(void);

void SPI_SetCallBack( void (*Ptr) (void) )
{
	SPI_callback = Ptr ;
}

void __vector_12(void) __attribute__((signal , used));
void __vector_12(void)
{
	SPI_callback();
}


void_SPI_INTEnable(void)
{
	SET_BIT(SPCR_REG,7);
}
void_SPI_INTDesable(void)
{
	CLEAR_BIT(SPCR_REG,7);
}

void SPI_Master_Init(u8 Data_Order, u8 Clock_Polarity,u8 Clock_Phase,u8 Clock_Rate)
{
	dio_vidConfigChannel(DIO_PORTB, 6, INPUT);
	dio_vidConfigChannel(DIO_PORTB,5, OUTPUT);
	dio_vidConfigChannel(DIO_PORTB, 4, OUTPUT);
	dio_vidConfigChannel(DIO_PORTB, 7, OUTPUT);
	
	
	SET_BIT(SPCR_REG,4);
	if (Data_Order == MSB_FIRST)
	{
		CLEAR_BIT(SPCR_REG,5);
	}
	else if (Data_Order == LSB_FIRST)
	{
		SET_BIT(SPCR_REG,5);
	}
	if (Clock_Polarity == IDLE_LOW)
	{
		CLEAR_BIT(SPCR_REG,3);
	}
	else if (Clock_Polarity == IDLE_HIGH)
	{
		SET_BIT(SPCR_REG,3);
	}
	if (Clock_Phase == ZERO)
	{
		CLEAR_BIT(SPCR_REG,2);
	}
	else if (Clock_Phase == ONE)
	{
		SET_BIT(SPCR_REG,2);
	}
	if(Clock_Rate == FREQ_DIV_BY_4) 
	{
		CLEAR_BIT(SPCR_REG , 0);
		CLEAR_BIT(SPCR_REG , 1);
		CLEAR_BIT(SPSR_REG , 0);
	}
	else if(Clock_Rate == FREQ_DIV_BY_16)
	{
		SET_BIT(SPCR_REG , 0);
		CLEAR_BIT(SPCR_REG , 1);
		CLEAR_BIT(SPSR_REG , 0);
	}
	else if(Clock_Rate == FREQ_DIV_BY_64)
	{
		CLEAR_BIT(SPCR_REG , 0);
		SET_BIT(SPCR_REG , 1);
		CLEAR_BIT(SPSR_REG , 0);
	}
	else if(Clock_Rate == FREQ_DIV_BY_128)
	{
		SET_BIT(SPCR_REG , 0);
		SET_BIT(SPCR_REG , 1);
		CLEAR_BIT(SPSR_REG , 0);
	}
	else if(Clock_Rate == FREQ_DIV_BY_2)
	{
		CLEAR_BIT(SPCR_REG , 0);
		CLEAR_BIT(SPCR_REG , 1);
		SET_BIT(SPSR_REG , 0);
	}
	else if(Clock_Rate == FREQ_DIV_BY_8)
	{
		SET_BIT(SPCR_REG , 0);
		CLEAR_BIT(SPCR_REG , 1);
		SET_BIT(SPSR_REG , 0);
	}
	else if(Clock_Rate == FREQ_DIV_BY_32)
	{
		CLEAR_BIT(SPCR_REG , 0);
		SET_BIT(SPCR_REG , 1);
		SET_BIT(SPSR_REG , 0);
	}
	SET_BIT(SPCR_REG,6);
	
}
void SPI_Slave_Init(u8 Data_Order, u8 Clock_Polarity,u8 Clock_Phase,u8 Clock_Rate)
{
	dio_vidConfigChannel(DIO_PORTB, 6, OUTPUT);
	dio_vidConfigChannel(DIO_PORTB,5, INPUT);
	dio_vidConfigChannel(DIO_PORTB, 4, INPUT);
	dio_vidConfigChannel(DIO_PORTB, 7, INPUT);
	
	
	CLEAR_BIT(SPCR_REG,4);
	if (Data_Order == MSB_FIRST)
	{
		CLEAR_BIT(SPCR_REG,5);
	}
	else if (Data_Order == LSB_FIRST)
	{
		SET_BIT(SPCR_REG,5);
	}
	if (Clock_Polarity == IDLE_LOW)
	{
		CLEAR_BIT(SPCR_REG,3);
	}
	else if (Clock_Polarity == IDLE_HIGH)
	{
		SET_BIT(SPCR_REG,3);
	}
	if (Clock_Phase == ZERO)
	{
		CLEAR_BIT(SPCR_REG,2);
	}
	else if (Clock_Phase == ONE)
	{
		SET_BIT(SPCR_REG,2);
	}
	if(Clock_Rate == FREQ_DIV_BY_4)
	{
		CLEAR_BIT(SPCR_REG , 0);
		CLEAR_BIT(SPCR_REG , 1);
		CLEAR_BIT(SPSR_REG , 0);
	}
	else if(Clock_Rate == FREQ_DIV_BY_16)
	{
		SET_BIT(SPCR_REG , 0);
		CLEAR_BIT(SPCR_REG , 1);
		CLEAR_BIT(SPSR_REG , 0);
	}
	else if(Clock_Rate == FREQ_DIV_BY_64)
	{
		CLEAR_BIT(SPCR_REG , 0);
		SET_BIT(SPCR_REG , 1);
		CLEAR_BIT(SPSR_REG , 0);
	}
	else if(Clock_Rate == FREQ_DIV_BY_128)
	{
		SET_BIT(SPCR_REG , 0);
		SET_BIT(SPCR_REG , 1);
		CLEAR_BIT(SPSR_REG , 0);
	}
	else if(Clock_Rate == FREQ_DIV_BY_2)
	{
		CLEAR_BIT(SPCR_REG , 0);
		CLEAR_BIT(SPCR_REG , 1);
		SET_BIT(SPSR_REG , 0);
	}
	else if(Clock_Rate == FREQ_DIV_BY_8)
	{
		SET_BIT(SPCR_REG , 0);
		CLEAR_BIT(SPCR_REG , 1);
		SET_BIT(SPSR_REG , 0);
	}
	else if(Clock_Rate == FREQ_DIV_BY_32)
	{
		CLEAR_BIT(SPCR_REG , 0);
		SET_BIT(SPCR_REG , 1);
		SET_BIT(SPSR_REG , 0);
	}
	SET_BIT(SPCR_REG,6);
	
}
void SPI_MasterSendByte(u8 byte)
{
	dio_vidWriteChannel(DIO_PORTB, 4, STD_LOW);
	u8 flushed;
	SPDR_REG = byte ;
	while(CHECK_BIT(SPSR_REG , 7) == 0);
	flushed=SPDR_REG ;
}
u8 SPI_MasterReadByte(void)
{
	SPDR_REG = 0xFF ;
	while(CHECK_BIT(SPSR_REG , 7) == 0);
	return (SPDR_REG) ;
}
u8 SPI_SlaveReceive(void)
{
	while(CHECK_BIT(SPSR_REG , 7) == 0);
	return (SPDR_REG) ;
}
void SPI_SlaveSend(u8 byte)
{
	SPDR_REG = byte ;
	while(CHECK_BIT(SPSR_REG , 7) == 0);
}
