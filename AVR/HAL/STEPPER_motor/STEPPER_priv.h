/*
 * STEPPER_priv.h
 *
 * Created: 3/2/2023 1:47:48 AM
 *  Author: DELL
 */ 


#ifndef STEPPER_PRIV_H_
#define STEPPER_PRIV_H_

typedef struct stepper_motor
{
	u8 Blue_Wire;
	u8 Pink_Wire;
	u8 Yellow_Wire;
	u8 Orange_Wire;
	u8 Motor_Port;
}stepper_motor;


#define  STOP          1
#define  CLKWISE       2
#define  ANTI_CLKWISE   3



extern stepper_motor motors_array[MOTORS_NUMBER];

#endif /* STEPPER_PRIV_H_ */