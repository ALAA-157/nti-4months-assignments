/*
 * buzzer.c
 *
 * Created: 2/23/2023 1:14:08 AM
 *  Author: DELL
 */ 
#include "buzzer.h"


void buzzer_init(void)
{
	dio_vidConfigChannel(BUZZER_POTR, BUZZER_PIN, OUTPUT);
	dio_vidWriteChannel(BUZZER_POTR, BUZZER_PIN,STD_HIGH ); 
}
void buzzer_on(void)
{
	dio_vidWriteChannel(BUZZER_POTR, BUZZER_PIN,STD_LOW);
}
void buzzer_off (void)
{
	dio_vidWriteChannel(BUZZER_POTR, BUZZER_PIN,STD_HIGH );
}