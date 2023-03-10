
#ifndef _TIMER0_CONFIG_H
#define _TIMER0_CONFIG_H

/*Range
#define TIMER0_NORMAL 		
#define TIMER0_CTC 			
#define TIMER0_FAST_PWM 	
#define TIMER0_PHASE_PWM 	
*/

#define TIMER0_MODE 		TIMER0_NORMAL
/*Range
//#define		NO_PRESCALLER			0
#define TIMER0_DIV_BY_1			
#define TIMER0_DIV_BY_8			
#define TIMER0_DIV_BY_64		
#define TIMER0_DIV_BY_256		
#define TIMER0_DIV_BY_1024	
#define EXTERNAL_CLOCK_FALLING	
#define EXTERNAL_CLOCK_RISING	
*/
#define TIMER0_PRESCALER  	EXTERNAL_CLOCK_RISING

/*Range
#define TIMER0_NO_ACTION	
#define TIMER0_TOGGLE		
#define TIMER0_SET			
#define TIMER0_CLEAR	
#define TIMER0_NIN_INVERTING	
#define TIMER0_INVERTING			
*/

#define TIMER0_COM_EVENT   TIMER0_NO_ACTION


#endif
