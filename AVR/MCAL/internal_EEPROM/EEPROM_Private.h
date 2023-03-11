/*
 * EEPROM_Private.h
 *
 *  Created on: Sep 15, 2021
 *      Author: dell
 */

#ifndef EEPROM_EEPROM_PRIVATE_H_
#define EEPROM_EEPROM_PRIVATE_H_

#define EEPROM_u8_EEARH_REG       *((volatile u8 *)0x3F)
#define EEPROM_u8_EEARL_REG       *((volatile u8 *)0x3E)
#define EEPROM_u16_EEAR_REG       *((volatile u16 *)0x3E)
#define EEPROM_u8_EEDR_REG        *((volatile u8 *)0x3D)
#define EEPROM_u8_EECR_REG        *((volatile u8 *)0x3C)


#endif /* INCLUDE_MCAL_EEPROM_EEPROM_PRIVATE_H_ */
