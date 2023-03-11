/*
 * SPI_priv.h
 *
 * Created: 3/4/2023 1:06:53 PM
 *  Author: DELL
 */ 


#ifndef SPI_PRIV_H_
#define SPI_PRIV_H_


#define SPCR_REG (*((volatile u8 *)0x2D ))
#define SPSR_REG (*((volatile u8 *)0x2E ))
#define SPDR_REG (*((volatile u8 *)0x2F ))




#define LSB_FIRST    0
#define MSB_FIRST    1

#define MASTER  0
#define SLAVE   1

#define IDLE_LOW   0
#define IDLE_HIGH  1


#define ZERO   0
#define ONE    1


#define FREQ_DIV_BY_4    0
#define FREQ_DIV_BY_16   1
#define FREQ_DIV_BY_64   2
#define FREQ_DIV_BY_128  3
#define FREQ_DIV_BY_2    4
#define FREQ_DIV_BY_8    5
#define FREQ_DIV_BY_32   6











#endif /* SPI_PRIV_H_ */