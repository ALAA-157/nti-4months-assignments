/*
 * stepper_motor.c
 *
 * Created: 3/2/2023 1:00:43 AM
 * Author : DELL
 */ 


#define F_CPU 8000000

#include "std_types.h"
#include "bit_math.h"

#include "util/delay.h"

#include "dio.h"

#include "STEPPER_int.h"
#include "STEPPER_config.h"
#include "STEPPER_priv.h"




int main(void)
{
	StepperMotor_Init( );
    /* Replace with your application code */
    while (1) 
    {
		StepperMotor_HalfStep_Move( 0 , CLKWISE ,2);
		StepperMotor_HalfStep_Move( 0 , ANTI_CLKWISE ,2);
		StepperMotor_HalfStep_Move( 0 , STOP ,2);
		StepperMotor_FullStep_Move( 0 , CLKWISE ,2 );
		StepperMotor_FullStep_Move( 0 , ANTI_CLKWISE ,2 );
		StepperMotor_FullStep_Move( 0 , STOP ,2 );
		_delay_ms(DELAY);

    }
}

