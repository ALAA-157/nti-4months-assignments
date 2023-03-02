/*
 * buzzer.h
 *
 * Created: 2/23/2023 1:09:06 AM
 *  Author: DELL
 */ 


#ifndef BUZZER_H_
#define BUZZER_H_
#include "dio_types.h"
#include "bit_math.h"
#include "dio_reg.h"
#include "std_types.h"
#include "dio.h"

#define BUZZER_POTR DIO_PORTC
#define BUZZER_PIN  DIO_PIN6

void buzzer_init(void);
void buzzer_on(void);
void buzzer_off (void);



#endif /* BUZZER_H_ */