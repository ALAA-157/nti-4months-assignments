/*
 * EEPROM_Program.c
 *
 *  Created on: Sep 15, 2021
 *      Author: dell
 */


/****************************************************/
/* Library Directives							    */
/****************************************************/
#define  F_CPU 8000000
#include "bit_math.h"
#include "std_types.h"
#include "util/delay.h"

#include "EEPROM_Interface.h"
#include "EEPROM_Private.h"




void EEPROM_write(u16 uiAddress, u8 ucData)
{
/* Wait for completion of previous write */


while( EEPROM_u8_EECR_REG & (1<<1));
/* Set up address and data registers */
EEPROM_u16_EEAR_REG = uiAddress;
EEPROM_u8_EEDR_REG = ucData;
/* Write logical one to EEMWE */
EEPROM_u8_EECR_REG = 4;
/* Start eeprom write by setting EEWE */
EEPROM_u8_EECR_REG = 0x06;
_delay_ms(9);
EEPROM_u8_EECR_REG =0;

}

u8 EEPROM_read(u16 uiAddress)
{
/* Wait for completion of previous write */
while( EEPROM_u8_EECR_REG & (1<<1));

/* Set up address register */
EEPROM_u16_EEAR_REG = uiAddress;
/* Start eeprom read by writing EERE */
EEPROM_u8_EECR_REG |= (1<<0);
/* Return data from data register */
return EEPROM_u8_EEDR_REG;
}

