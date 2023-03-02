/*
 * STEPPER_config.c
 *
 * Created: 3/2/2023 1:03:04 AM
 *  Author: DELL
 */ 
#include "std_types.h"
#include "dio.h"
#include "STEPPER_config.h"
#include "STEPPER_priv.h"

stepper_motor motors_array[MOTORS_NUMBER] =
{
	{DIO_PIN0,DIO_PIN1,DIO_PIN2,DIO_PIN3,DIO_PORTA}
};