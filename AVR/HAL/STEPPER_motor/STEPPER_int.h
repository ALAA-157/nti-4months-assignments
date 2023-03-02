/*
 * STEPPER_int.h
 *
 * Created: 3/2/2023 1:58:31 AM
 *  Author: DELL
 */ 


#ifndef STEPPER_INT_H_
#define STEPPER_INT_H_

#define DELAY  1000

void StepperMotor_Init( void );

void StepperMotor_FullStep_Move( u8 Motor_Num , u8 Direction ,u16 Steps_Num );

void StepperMotor_HalfStep_Move( u8 Motor_Num , u8 Direction ,u16 Steps_Num );



#endif /* STEPPER_INT_H_ */