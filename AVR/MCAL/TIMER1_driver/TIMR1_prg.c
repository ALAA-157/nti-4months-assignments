/*
 * TIMR1_prg.c
 *
 * Created: 3/2/2023 10:51:24 PM
 *  Author: DELL
 */ 
#include "std_types.h"
#include "bit_math.h"
#include "TIMR1_int.h"
#include "TIMR1_priv.h"
#include "TIMR1_config.h"


void (*TIMER1_CTCB_CallBack) (void) ;
void (*TIMER1_CTCA_CallBack) (void) ;
void (*TIMER1_OV_CallBack) (void) ;
void (*TIMER1_CAPT_CallBack) (void) ;

void TIMER1_void_Init(void)
{
#if(TIMER1_MODE == TIMER1_NORMAL)
	CLEAR_BIT(TCCR1A , 0);
	CLEAR_BIT(TCCR1A , 1);
	CLEAR_BIT(TCCR1B , 3);
	CLEAR_BIT(TCCR1B , 4);
	
	#elif(TIMER1_MODE == TIMER1_PWM_8)
	SET_BIT(TCCR1A , 0);
	CLEAR_BIT(TCCR1A , 1);
	CLEAR_BIT(TCCR1B , 3);
	CLEAR_BIT(TCCR1B , 4);
	
	#elif(TIMER1_MODE == TIMER1_PWM_9 )
	CLEAR_BIT(TCCR1A , 0);
	SET_BIT(TCCR1A , 1);
	CLEAR_BIT(TCCR1B , 3);
	CLEAR_BIT(TCCR1B , 4);
	
	#elif(TIMER1_MODE == TIMER1_PWM_10 )
	SET_BIT(TCCR1A , 0);
	SET_BIT(TCCR1A , 1);
	CLEAR_BIT(TCCR1B , 3);
	CLEAR_BIT(TCCR1B , 4);
	
	#elif(TIMER1_MODE == TIMER1_CTC )
	CLEAR_BIT(TCCR1A , 0);
	CLEAR_BIT(TCCR1A , 1);
	SET_BIT(TCCR1B , 3);
	CLEAR_BIT(TCCR1B , 4);
	
	#elif(TIMER1_MODE == TIMER1_FPWM_8 )
	SET_BIT(TCCR1A , 0);
	CLEAR_BIT(TCCR1A , 1);
	SET_BIT(TCCR1B , 3);
	CLEAR_BIT(TCCR1B , 4);
	
	#elif(TIMER1_MODE == TIMER1_FPWM_9 )
	CLEAR_BIT(TCCR1A , 0);
	SET_BIT(TCCR1A , 1);
	SET_BIT(TCCR1B , 3);
	CLEAR_BIT(TCCR1B , 4);
	
	#elif(TIMER1_MODE == TIMER1_FPWM_10 )
	SET_BIT(TCCR1A , 0);
	SET_BIT(TCCR1A , 1);
	SET_BIT(TCCR1B , 3);
	CLEAR_BIT(TCCR1B , 4);
	
	#elif(TIMER1_MODE == TIMER1_PWM_PF_ICR )
	CLEAR_BIT(TCCR1A , 0);
	CLEAR_BIT(TCCR1A , 1);
	CLEAR_BIT(TCCR1B , 3);
	SET_BIT(TCCR1B , 4);
	
	#elif(TIMER1_MODE == TIMER1_PWM_PF_OCR )
	SET_BIT(TCCR1A , 0);
	CLEAR_BIT(TCCR1A , 1);
	CLEAR_BIT(TCCR1B , 3);
	SET_BIT(TCCR1B , 4);
	
	#elif(TIMER1_MODE == TIMER1_PWM_P_ICR )
	CLEAR_BIT(TCCR1A , 0);
	SET_BIT(TCCR1A , 1);
	CLEAR_BIT(TCCR1B , 3);
	SET_BIT(TCCR1B , 4);
	
	#elif(TIMER1_MODE == TIMER1_PWM_P_OCR )
	SET_BIT(TCCR1A , 0);
	SET_BIT(TCCR1A , 1);
	CLEAR_BIT(TCCR1B , 3);
	SET_BIT(TCCR1B , 4);
	
	#elif(TIMER1_MODE == TIMER1_CTC_ICR )
	CLEAR_BIT(TCCR1A , 0);
	CLEAR_BIT(TCCR1A , 1);
	SET_BIT(TCCR1B , 3);
	SET_BIT(TCCR1B , 4);
	
	#elif(TIMER1_MODE == TIMER1_FPWM_ICR )
	CLEAR_BIT(TCCR1A , 0);
	SET_BIT(TCCR1A , 1);
	SET_BIT(TCCR1B , 3);
	SET_BIT(TCCR1B , 4);
	
	#elif(TIMER1_MODE == TIMER1_FPWM_OCR )
	SET_BIT(TCCR1A , 0);
	SET_BIT(TCCR1A , 1);
	SET_BIT(TCCR1B , 3);
	SET_BIT(TCCR1B , 4);
	
	#endif
	
	#if(TIMER1_PRESCALER == TIMER1_DIV_BY_1)
	SET_BIT(TCCR1B , 0);
	CLEAR_BIT(TCCR1B , 1);
	CLEAR_BIT(TCCR1B , 2);
	
	#elif(TIMER1_PRESCALER == TIMER1_DIV_BY_8)
	CLEAR_BIT(TCCR1B , 0);
	SET_BIT(TCCR1B , 1);
	CLEAR_BIT(TCCR1B , 2);
	#elif(TIMER1_PRESCALER == TIMER1_DIV_BY_64 )
	SET_BIT(TCCR1B , 0);
	SET_BIT(TCCR1B , 1);
	CLEAR_BIT(TCCR1B , 2);
	#elif(TIMER1_PRESCALER == TIMER1_DIV_BY_256 )
	CLEAR_BIT(TCCR1B , 0);
	CLEAR_BIT(TCCR1B , 1);
	SET_BIT(TCCR1B , 2);
	#elif(TIMER1_PRESCALER == TIMER1_DIV_BY_1024 )
	SET_BIT(TCCR1B , 0);
	CLEAR_BIT(TCCR1B , 1);
	SET_BIT(TCCR1B , 2);
	#elif(TIMER1_PRESCALER ==EXT_T1_FALLING_EDGE)
	CLEAR_BIT(TCCR1B , 0);
	SET_BIT(TCCR1B , 1);
	SET_BIT(TCCR1B , 2);
	#elif(TIMER1_PRESCALER ==EXT_T1_RISING_EDGE)
	SET_BIT(TCCR1B , 0);
	SET_BIT(TCCR1B , 1);
	SET_BIT(TCCR1B , 2);
	#endif
	
	#if(TIMER1_COM_EVENT == TIMER1_NO_ACTION_COMA)
	CLEAR_BIT(TCCR1A , 4);
	CLEAR_BIT(TCCR1A , 5);
	CLEAR_BIT(TCCR1A , 6);
	CLEAR_BIT(TCCR1A , 7);
	
	#elif(TIMER1_COM_EVENT == TIMER1_TOGGLE_COMA)
	CLEAR_BIT(TCCR1A , 4)
	CLEAR_BIT(TCCR1A , 5);
	SET_BIT(TCCR1A , 6);
	CLEAR_BIT(TCCR1A , 7);
	
	#elif(TIMER1_COM_EVENT == TIMER1_CLEAR_COMA )
	CLEAR_BIT(TCCR1A , 4);
	CLEAR_BIT(TCCR1A , 5);
	CLEAR_BIT(TCCR1A , 6);
	SET_BIT(TCCR1A , 7);
	
	#elif(TIMER1_COM_EVENT == TIMER1_SET_COMA )
	CLEAR_BIT(TCCR1A , 4);
	CLEAR_BIT(TCCR1A , 5);
    SET_BIT(TCCR1A , 6);
    SET_BIT(TCCR1A , 7);
	
	#elif(TIMER1_COM_EVENT == TIMER1_NO_ACTION_COMB)
	CLEAR_BIT(TCCR1A , 4);
	CLEAR_BIT(TCCR1A , 5);
	CLEAR_BIT(TCCR1A , 6);
	CLEAR_BIT(TCCR1A , 7);
	
	#elif(TIMER1_COM_EVENT == TIMER1_TOGGLE_COMB)
	SET_BIT(TCCR1A , 4)
	CLEAR_BIT(TCCR1A , 5);
	CLEAR_BIT(TCCR1A , 6);
	CLEAR_BIT(TCCR1A , 7);
	
	#elif(TIMER1_COM_EVENT == TIMER1_CLEAR_COMB )
	CLEAR_BIT(TCCR1A , 4);
	SET_BIT(TCCR1A , 5);
	CLEAR_BIT(TCCR1A , 6);
	CLEAR_BIT(TCCR1A , 7);
	
	#elif(TIMER1_COM_EVENT == TIMER1_SET_COMB )
	SET_BIT(TCCR1A , 4);
	SET_BIT(TCCR1A , 5);
	CLEAR_BIT(TCCR1A , 6);
	CLEAR_BIT(TCCR1A , 7);
	
	#endif
	/***********Disable Interrupts**********/
	CLEAR_BIT(TIMSK , 2);
	CLEAR_BIT(TIMSK , 3);
	CLEAR_BIT(TIMSK , 4);
	CLEAR_BIT(TIMSK , 5);
	
	/*******SET FLAGS TO CLEAR***********/
	SET_BIT(TIFR , 2);
	SET_BIT(TIFR , 3);
	SET_BIT(TIFR , 4);
	SET_BIT(TIFR , 5);
	
	/**********Clear all the registers*****/
	TCNT1L = 0 ;
	TCNT1H = 0 ;
	OCR1AH = 0 ;
	OCR1AL = 0 ;
	OCR1BH = 0 ;
	OCR1BL = 0 ;
}

void TIMER1_void_SetTimerReg(u16 Copy_uint16Val)
{
	TCNT1L = Copy_uint16Val ;	
}

void TIMER1A_void_SetCompareVal(u16 Copy_uint16Val)
{
	OCR1AL = Copy_uint16Val ;
}

void TIMER1B_void_SetCompareVal(u16 Copy_uint16Val)
{
	OCR1BL = Copy_uint16Val;
}


void TIMER1_void_EnableCTCAInt(void)
{
	SET_BIT(TIMSK , 4);
}

void TIMER1_void_DisableCTCAInt(void)
{
	CLEAR_BIT(TIMSK , 4);
}

void TIMER1_void_EnableCTCBInt(void)
{
	SET_BIT(TIMSK , 3);
}

void TIMER1_void_DisableCTCBInt(void)
{
	CLEAR_BIT(TIMSK , 3);
}
void TIMER1_void_EnableOVInt(void)
{
	SET_BIT(TIMSK , 2);
}

void TIMER1_void_DisableOVInt(void)
{
	CLEAR_BIT(TIMSK , 2);
}

void TIMER1_void_EnableCAPTInt(void)
{
	SET_BIT(TIMSK , 5);
}

void TIMER1_void_DisableCAPTInt(void)
{
	CLEAR_BIT(TIMSK , 5);
}

void TIMER1_void_SetCAPTCallBack(void (*Copy_ptr) (void) ) 
{
	TIMER1_CAPT_CallBack = Copy_ptr ;
}
void TIMER1_void_SetOVCallBack(void (*Copy_ptr) (void) ) 
{
	TIMER1_OV_CallBack = Copy_ptr ;
}

void TIMER1_void_SetCTCACallBack(void (*Copy_ptr) (void) ) 
{
	TIMER1_CTCA_CallBack = Copy_ptr ;
}

void TIMER1_void_SetCTCBCallBack(void (*Copy_ptr) (void) ) 
{
	TIMER1_CTCB_CallBack = Copy_ptr ;
}

void __vector_6(void) __attribute__((signal , used));
void __vector_6(void)
{
	
	TIMER1_CAPT_CallBack();
}

void __vector_7(void) __attribute__((signal , used));
void __vector_7(void)
{
	
	TIMER1_CTCA_CallBack();
}

void __vector_8(void) __attribute__((signal , used));
void __vector_8(void)
{
	
	TIMER1_CTCB_CallBack();
}

void __vector_9(void) __attribute__((signal , used));
void __vector_9(void)
{
	
	TIMER1_OV_CallBack();
}
