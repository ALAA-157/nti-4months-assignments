/*
 * glopal_interrupt.h
 *
 * Created: 2/25/2023 3:11:57 PM
 *  Author: DELL
 */ 


#ifndef GLOPAL_INTERRUPT_H_
#define GLOPAL_INTERRUPT_H_


#define SREG		*((volatile u8 * ) (0X5F))

void global_interrupt_Enable(void);
void global_interrupt_Desable(void);




#endif /* GLOPAL_INTERRUPT_H_ */