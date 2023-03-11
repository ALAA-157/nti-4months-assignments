/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  uart.h
 *       Module:  uart
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef UART_H_
#define UART_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#include "Std_Types.h"
#include "Bit_Math.h"
#include "uart_reg.h"

#define RX_BUFFER_SIZE				(25)

#define UART_BAUDRATE_1200			(0x340)
#define UART_BAUDRATE_2400			(0x1A0)
#define UART_BAUDRATE_4800			(0xCF)
#define UART_BAUDRATE_9600			(0x33)
#define UART_BAUDRATE_19200			(0x51)
#define UART_BAUDRATE_115200		(0x8)


#define UART_5_BIT_DATA				(0<<UCSZ0_BIT_NO)
#define UART_6_BIT_DATA				(1<<UCSZ0_BIT_NO)
#define UART_7_BIT_DATA				(2<<UCSZ0_BIT_NO)
#define UART_8_BIT_DATA				(3<<UCSZ0_BIT_NO)

#define UART_1_STOP_BIT				(0<<USBS_BIT_NO)
#define UART_2_STOP_BIT				(1<<USBS_BIT_NO)

#define UART_EVEN_PARITY			(2<<UPM0_BIT_NO)
#define UART_ODD_PARITY				(3<<UPM0_BIT_NO)

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void UART_Init(u16 baudRate);
void UART_TransmitChr(u8 data);
void UART_TransmitStr(u8 *str);
u8 UART_ReceiveChr(void);
void UART_receiveString(u8 *Str);
void UART_void_SetRXCallBack(void (*Copy_ptr) (u8) );
void UART_RxInterruptEnable(void);
void UART_TxInterruptEnable(void);
void UART_DataEmptyInterruptEnable(void);
void UART_RxInterruptDesable(void);
void UART_TxInterruptDesable(void);
void UART_DataEmptyInterruptDesable(void);
void UART_void_SetEmptyCallBack(u8 (*Copy_ptr) (void) );
void UART_Tx_String(u8 *str);
void UART_GetString(u8 *str);
u8 UART_Check_Recieve_STR (void);


 
#endif  /* UART_H_ */

/**********************************************************************************************************************
 *  END OF FILE: uart.h
 *********************************************************************************************************************/
