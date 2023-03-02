/*
 * STEPPER_Prog.c
 *
 * Created: 3/2/2023 2:11:59 AM
 *  Author: DELL
 */ 

#define F_CPU 8000000

#include "std_types.h"
#include "bit_math.h"

#include "util/delay.h"

#include "dio.h"

#include "STEPPER_int.h"
#include "STEPPER_config.h"
#include "STEPPER_priv.h"



void StepperMotor_Init( void )
{
	for(u8 i = 0 ; i < MOTORS_NUMBER ; i++)
	{
		/*************configure all wires pins as an output pins**********************/
		
		dio_vidConfigChannel(motors_array[i].Motor_Port, motors_array[i].Blue_Wire, OUTPUT);
		dio_vidConfigChannel(motors_array[i].Motor_Port, motors_array[i].Pink_Wire, OUTPUT);
		dio_vidConfigChannel(motors_array[i].Motor_Port, motors_array[i].Yellow_Wire, OUTPUT);
		dio_vidConfigChannel(motors_array[i].Motor_Port, motors_array[i].Orange_Wire, OUTPUT);
		
		/*****************turn off all wires**********************************/
		
		dio_vidWriteChannel(motors_array[i].Motor_Port, motors_array[i].Blue_Wire, STD_LOW);
		dio_vidWriteChannel(motors_array[i].Motor_Port, motors_array[i].Pink_Wire, STD_LOW);
		dio_vidWriteChannel(motors_array[i].Motor_Port, motors_array[i].Yellow_Wire, STD_LOW);
		dio_vidWriteChannel(motors_array[i].Motor_Port, motors_array[i].Orange_Wire, STD_LOW);
		_delay_ms(5);
	}
}
void StepperMotor_FullStep_Move( u8 Motor_Num , u8 Direction ,u16 Steps_Num )
{
	switch(Direction)
	{
		case CLKWISE:
			for(u8 i = 0 ; i < Steps_Num ; i++)
				{
					dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Blue_Wire, STD_HIGH);
					dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Pink_Wire, STD_LOW);
					dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Yellow_Wire, STD_HIGH);
					dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Orange_Wire, STD_LOW);
					_delay_ms(DELAY);
					dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Blue_Wire, STD_LOW);
					dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Pink_Wire, STD_LOW);
					dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Yellow_Wire, STD_HIGH);
					dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Orange_Wire, STD_HIGH);
					_delay_ms(DELAY);
					dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Blue_Wire, STD_LOW);
					dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Pink_Wire, STD_HIGH);
					dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Yellow_Wire, STD_LOW);
					dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Orange_Wire, STD_HIGH);
					_delay_ms(DELAY);
					dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Blue_Wire, STD_HIGH);
					dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Pink_Wire, STD_HIGH);
					dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Yellow_Wire, STD_LOW);
					dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Orange_Wire, STD_LOW);
					_delay_ms(DELAY);
				}
					dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Blue_Wire, STD_HIGH);
					dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Pink_Wire, STD_LOW);
					dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Yellow_Wire, STD_HIGH);
					dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Orange_Wire, STD_LOW);
					_delay_ms(DELAY);
			break;
		
		case ANTI_CLKWISE:
		
				for(u8 i = 0 ; i < Steps_Num ; i++)
				{
					dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Blue_Wire, STD_HIGH);
					dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Pink_Wire, STD_LOW);
					dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Yellow_Wire, STD_HIGH);
					dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Orange_Wire, STD_LOW);
					_delay_ms(DELAY);
					dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Blue_Wire, STD_HIGH);
					dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Pink_Wire, STD_HIGH);
					dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Yellow_Wire, STD_LOW);
					dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Orange_Wire, STD_LOW);
					_delay_ms(DELAY);
					dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Blue_Wire, STD_LOW);
					dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Pink_Wire, STD_HIGH);
					dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Yellow_Wire, STD_LOW);
					dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Orange_Wire, STD_HIGH);
					_delay_ms(DELAY);
					dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Blue_Wire, STD_LOW);
					dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Pink_Wire, STD_LOW);
					dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Yellow_Wire, STD_HIGH);
					dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Orange_Wire, STD_HIGH);
					_delay_ms(DELAY);
				}
					dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Blue_Wire, STD_HIGH);
					dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Pink_Wire, STD_LOW);
					dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Yellow_Wire, STD_HIGH);
					dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Orange_Wire, STD_LOW);
					_delay_ms(DELAY);
				break;
		case STOP:
		default:
				/*****************turn off all wires**********************************/
				
				dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Blue_Wire, STD_LOW);
				dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Pink_Wire, STD_LOW);
				dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Yellow_Wire, STD_LOW);
				dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Orange_Wire, STD_LOW);
				_delay_ms(DELAY);
				break;
	}
	
}
void StepperMotor_HalfStep_Move( u8 Motor_Num , u8 Direction ,u16 Steps_Num )
{
	switch(Direction)
	{
		case CLKWISE:
		for(u8 i = 0 ; i < Steps_Num ; i++)
		{
			dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Blue_Wire, STD_HIGH);
			dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Pink_Wire, STD_LOW);
			dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Yellow_Wire, STD_HIGH);
			dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Orange_Wire, STD_LOW);
			_delay_ms(DELAY);
			dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Blue_Wire, STD_LOW);
			dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Pink_Wire, STD_LOW);
			dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Yellow_Wire, STD_HIGH);
			dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Orange_Wire, STD_LOW);
			_delay_ms(DELAY);
			dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Blue_Wire, STD_LOW);
			dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Pink_Wire, STD_LOW);
			dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Yellow_Wire, STD_HIGH);
			dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Orange_Wire, STD_HIGH);
			_delay_ms(DELAY);
			dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Blue_Wire, STD_LOW);
			dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Pink_Wire, STD_LOW);
			dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Yellow_Wire, STD_LOW);
			dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Orange_Wire, STD_HIGH);
			_delay_ms(DELAY);
			dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Blue_Wire, STD_LOW);
			dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Pink_Wire, STD_HIGH);
			dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Yellow_Wire, STD_LOW);
			dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Orange_Wire, STD_HIGH);
			_delay_ms(DELAY);
			dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Blue_Wire, STD_LOW);
			dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Pink_Wire, STD_HIGH);
			dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Yellow_Wire, STD_LOW);
			dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Orange_Wire, STD_LOW);
			_delay_ms(DELAY);
			dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Blue_Wire, STD_HIGH);
			dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Pink_Wire, STD_HIGH);
			dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Yellow_Wire, STD_LOW);
			dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Orange_Wire, STD_LOW);
			_delay_ms(DELAY);
			dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Blue_Wire, STD_HIGH);
			dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Pink_Wire, STD_LOW);
			dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Yellow_Wire, STD_LOW);
			dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Orange_Wire, STD_LOW);
			_delay_ms(DELAY);
		}
		dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Blue_Wire, STD_HIGH);
		dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Pink_Wire, STD_LOW);
		dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Yellow_Wire, STD_HIGH);
		dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Orange_Wire, STD_LOW);
		_delay_ms(DELAY);
		break;
		
		case ANTI_CLKWISE:
		
		for(u8 i = 0 ; i < Steps_Num ; i++)
		{
			dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Blue_Wire, STD_HIGH);
			dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Pink_Wire, STD_LOW);
			dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Yellow_Wire, STD_HIGH);
			dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Orange_Wire, STD_LOW);
			_delay_ms(DELAY);
			dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Blue_Wire, STD_HIGH);
			dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Pink_Wire, STD_LOW);
			dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Yellow_Wire, STD_LOW);
			dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Orange_Wire, STD_LOW);
			_delay_ms(DELAY);
			dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Blue_Wire, STD_HIGH);
			dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Pink_Wire, STD_HIGH);
			dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Yellow_Wire, STD_LOW);
			dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Orange_Wire, STD_LOW);
			_delay_ms(DELAY);
			dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Blue_Wire, STD_LOW);
			dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Pink_Wire, STD_HIGH);
			dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Yellow_Wire, STD_LOW);
			dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Orange_Wire, STD_LOW);
			_delay_ms(DELAY);
			dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Blue_Wire, STD_LOW);
			dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Pink_Wire, STD_HIGH);
			dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Yellow_Wire, STD_LOW);
			dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Orange_Wire, STD_HIGH);
			_delay_ms(DELAY);
			dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Blue_Wire, STD_LOW);
			dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Pink_Wire, STD_LOW);
			dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Yellow_Wire, STD_LOW);
			dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Orange_Wire, STD_HIGH);
			_delay_ms(DELAY);
			dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Blue_Wire, STD_LOW);
			dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Pink_Wire, STD_LOW);
			dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Yellow_Wire, STD_HIGH);
			dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Orange_Wire, STD_HIGH);
			_delay_ms(DELAY);
			dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Blue_Wire, STD_LOW);
			dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Pink_Wire, STD_LOW);
			dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Yellow_Wire, STD_HIGH);
			dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Orange_Wire, STD_LOW);
			_delay_ms(DELAY);
		}
		dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Blue_Wire, STD_HIGH);
		dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Pink_Wire, STD_LOW);
		dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Yellow_Wire, STD_HIGH);
		dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Orange_Wire, STD_LOW);
		_delay_ms(DELAY);
		break;
		case STOP:
		default:
		/*****************turn off all wires**********************************/
		
		dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Blue_Wire, STD_LOW);
		dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Pink_Wire, STD_LOW);
		dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Yellow_Wire, STD_LOW);
		dio_vidWriteChannel(motors_array[Motor_Num].Motor_Port, motors_array[Motor_Num].Orange_Wire, STD_LOW);
		_delay_ms(DELAY);
		break;
	}
	
}