/*
 * SPI_int.h
 *
 * Created: 3/4/2023 1:03:49 PM
 *  Author: DELL
 */ 


#ifndef SPI_INT_H_
#define SPI_INT_H_

void SPI_Master_Init(u8 Data_Order, u8 Clock_Polarity,u8 Clock_Phase,u8 Clock_Rate);
void void_SPI_INTEnable(void);
void void_SPI_INTDesable(void);
void SPI_Slave_Init(u8 Data_Order, u8 Clock_Polarity,u8 Clock_Phase,u8 Clock_Rate);
void SPI_SetCallBack( void (*Ptr) (void) );
void SPI_MasterSendByte(u8 byte);
u8 SPI_MasterReadByte(void);
u8 SPI_SlaveReceive(void);
void SPI_SlaveSend(u8 byte);




#endif /* SPI_INT_H_ */