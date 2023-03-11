/*
 * I2C_program.h
 *
 * Created: 3/5/2023 9:33:46 AM
 *  Author: DELL
 */ 


#define  F_CPU 8000000
#include "bit_math.h"
#include "std_types.h"
#include "I2C_int.h"
#include "I2C_priv.h"
#include "I2C_config.h"
#include "dio.h"
#include "avr/delay.h"


extern double pow(double _x, double __y) __attribute((__const_));
#define powf	pow

#define BIT_RATE(TWSR)	((F_CPU/TWBR)-16)/(2*pow(4,(TWSR&((1<<0)|(1<<1)))))



void I2C_Master_Init(void)
{
	TWBR = BIT_RATE(TWSR=0x00);
}


u8 I2C_Start(u8 write_address)
{
	u8 status;
	SET_BIT(TWCR,5);
	SET_BIT(TWCR,2);
	SET_BIT(TWCR,7);
	while(CHECK_BIT(TWCR,7)==0);
	status=TWSR&0xF8;
	if(status != START_ACK)
	{
		return 0;
	}
	TWDR=write_address;
	SET_BIT(TWCR,2);
	SET_BIT(TWCR,7);
	while(CHECK_BIT(TWCR,7)==0);
	status=TWSR&0xF8;
	if(status == SLAVE_ADD_AND_WR_ACK)
	{
		return 1;
	}
	if(status == SLAVE_ADD_AND_WR_NACK)
	{
		return 2;	
	}
	else
	{
		return 3;
	}
}
u8 I2C_Reapeated_Start(u8 read_address)
{
	u8 status;
	SET_BIT(TWCR,5);
	SET_BIT(TWCR,2);
	SET_BIT(TWCR,7);
	while(CHECK_BIT(TWCR,7)==0);
	status=TWSR&0xF8;
	if(status != REP_START)
	{
		return 0;
	}
	TWDR=read_address;
	SET_BIT(TWCR,2);
	SET_BIT(TWCR,7);
	while(CHECK_BIT(TWCR,7)==0);
	status=TWSR&0xF8;
	if(status == SLAVE_ADD_AND_RD_ACK)
	{
		return 1;
	}
	if(status == SLAVE_ADD_AND_RD_NACK)
	{
		return 2;
	}
	else
	{
		return 3;
	}
}

u8 I2C_Master_Write(u8 data)
{
	u8 status;
	TWDR=data;
	SET_BIT(TWCR,2);
	SET_BIT(TWCR,7);
	while(CHECK_BIT(TWCR,7)==0);
	status=TWSR&0xF8;
	if(status == WR_BYTE_ACK)
	{
		return 0;
	}
	if(status == WR_BYTE_NACK)
	{
		return 1;
	}
	else
	{
		return 2;
	}
	
}

u8 I2C_Read_Ack(void)
{
	SET_BIT(TWCR,2);
	SET_BIT(TWCR,7);
	SET_BIT(TWCR,6);
	while(CHECK_BIT(TWCR,7)==0);
	return (TWDR);	
}
u8 I2C_Read_Nack(void)
{
	SET_BIT(TWCR,2);
	SET_BIT(TWCR,7);
	while(CHECK_BIT(TWCR,7)==0);
	return (TWDR);
}
void I2C_Stop(void)
{
	SET_BIT(TWCR,2);
	SET_BIT(TWCR,7);
	SET_BIT(TWCR,4);
	while(CHECK_BIT(TWCR,4)==1);
}

void I2C_Slave_Init(u8 slave_address)
{
	TWDR=slave_address;
	SET_BIT(TWCR,2);
	SET_BIT(TWCR,7);
	SET_BIT(TWCR,6);
}
u8 I2C_Slave_Listen(void)
{
	while(1)
	{
		u8 status;
		while(CHECK_BIT(TWCR,7)==0);
		status=TWSR&0xF8;
		if((status == SLAVE_ADD_RCVD_WR_REQ)||(status == SLAVE_ADD_RCVD_WR_ACK_SENT))
		{
			return 0;
		}
		if((status == SLAVE_ADD_RCVD_RD_REQ)||(status == SLAVE_ADD_RCVD_RD_ACK_SENT))
		{
			return 1;
		}
		if((status == SLAVE_ADD_RCVD_GEN_REQ)||(status == SLAVE_ADD_RCVD_GEN_ACK_SENT))
		{
			return 2;
		}
		else
		{
			continue;
		}
	}
}
s8 I2C_Slave_Transmit(u8 data)
{
	u8 status;
	TWDR=data;
	SET_BIT(TWCR,2);
	SET_BIT(TWCR,7);
	SET_BIT(TWCR,6);
	while(CHECK_BIT(TWCR,7)==0);
	status=TWSR&0xF8;
	if(status == SLAVE_STOP_OR_REP_START_RCVD)
	{
		SET_BIT(TWCR,7);
		return (-1);
	}
	if(status == SLAVE_DATA_TRANS_ACK)
	{
		return 0;
	}
	if(status == SLAVE_DATA_TRANS_NACK)
	{
		SET_BIT(TWCR,7);
		return (-2);
	}
	if(status == SLAVE_LAST_BYTE_TRANS_ACK)
	{
		return (-3);
	}
	else
	{
		return (-4);
	}
}

s8 I2C_Slave_Receive(void)
{
	u8 status;
	SET_BIT(TWCR,2);
	SET_BIT(TWCR,7);
	SET_BIT(TWCR,6);
	while(CHECK_BIT(TWCR,7)==0);
	status=TWSR&0xF8;
	if((status == SLAVE_DATA_RECEIVED)||(status == SLAVE_DATA_RECEIVED_ACK))
	{
		return (TWDR);
	}
	if((status == SLAVE_DATA_RECEIVED_N)||(status == SLAVE_DATA_RECEIVED_NACK))
	{
		return (TWDR);
	}
	if (status == SLAVE_STOP_OR_REP_START_RCVD)
	{
		SET_BIT(TWCR,7);
		return (-1);
	}
	else
	{
		return (-2);
	}
}

