/*
 * EEPROM_Interface.h
 *
 *  Created on: Sep 15, 2021
 *      Author: dell
 */

#ifndef EEPROM_EEPROM_INTERFACE_H_
#define EEPROM_EEPROM_INTERFACE_H_

void EEPROM_write(u16 uiAddress, u8 ucData);
u8 EEPROM_read(u16 uiAddress);


#endif /* EEPROM_EEPROM_INTERFACE_H_ */
