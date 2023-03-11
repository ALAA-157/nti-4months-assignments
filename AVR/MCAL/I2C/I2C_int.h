/*
 * I2C_int.h
 *
 * Created: 3/5/2023 9:30:40 AM
 *  Author: DELL
 */ 


#ifndef I2C_INT_H_
#define I2C_INT_H_

void I2C_Master_Init(void);
u8 I2C_Start(u8 write_address);
u8 I2C_Reapeated_Start(u8 read_address);
u8 I2C_Master_Write(u8 data);
u8 I2C_Read_Ack(void);
u8 I2C_Read_Nack(void);
void I2C_Stop(void);
void I2C_Slave_Init(u8 slave_address);
u8 I2C_Slave_Listen(void);
s8 I2C_Slave_Transmit(u8 data);
s8 I2C_Slave_Receive(void);









#endif /* I2C_INT_H_ */