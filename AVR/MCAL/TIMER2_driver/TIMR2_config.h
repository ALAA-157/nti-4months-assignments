/*
 * TIMR2_config.h
 *
 * Created: 3/1/2023 9:04:51 PM
 *  Author: DELL
 */ 


#ifndef TIMR2_CONFIG_H_
#define TIMR2_CONFIG_H_
/*Range
#define TIMER2_NORMAL
#define TIMER2_CTC
#define TIMER2_FAST_PWM
#define TIMER2_PHASE_PWM
*/

#define TIMER2_MODE 		TIMER2_NORMAL
/*Range
//#define		NO_PRESCALLER			0
#define TIMER2_DIV_BY_1
#define TIMER2_DIV_BY_8
#define TIMER2_DIV_BY_32
#define TIMER2_DIV_BY_64
#define TIMER2_DIV_BY_128
#define TIMER2_DIV_BY_256
#define TIMER2_DIV_BY_1024
*/
#define TIMER2_PRESCALER  	TIMER2_DIV_BY_64

/*Range
#define TIMER2_NO_ACTION
#define TIMER2_TOGGLE
#define TIMER2_SET
#define TIMER2_CLEAR
#define TIMER2_NIN_INVERTING	
#define TIMER2_INVERTING		
*/

#define TIMER2_COM_EVENT   TIMER2_NO_ACTION




#endif /* TIMR2_CONFIG_H_ */