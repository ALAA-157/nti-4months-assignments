/*
 * TIMR1_int.h
 *
 * Created: 3/2/2023 10:50:30 PM
 *  Author: DELL
 */ 


#ifndef TIMR1_INT_H_
#define TIMR1_INT_H_

void TIMER1_void_Init(void);

void TIMER1_void_SetTimerReg(u16 Copy_uint16Val);

void TIMER1A_void_SetCompareVal(u16 Copy_uint16Val);
void TIMER1B_void_SetCompareVal(u16 Copy_uint16Val);


void TIMER1_void_EnableOVInt(void);

void TIMER1_void_DisableOVInt(void);

void TIMER1_void_EnableCTCAInt(void);

void TIMER1_void_DisableCTCAInt(void);

void TIMER1_void_EnableCTCBInt(void);

void TIMER1_void_DisableCTCBInt(void);

void TIMER1_void_EnableCAPTInt(void);

void TIMER1_void_DisableCAPTInt(void);

void TIMER1_void_SetOVCallBack(void (*Copy_ptr) (void) ) ;

void TIMER1_void_SetCTCACallBack(void (*Copy_ptr) (void) ) ;

void TIMER1_void_SetCTCBCallBack(void (*Copy_ptr) (void) ) ;

void TIMER1_void_SetCAPTCallBack(void (*Copy_ptr) (void) ) ;




#endif /* TIMR1_INT_H_ */