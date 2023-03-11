/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  uart.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "bit_math.h"
#include "std_types.h"
#include "uart_reg.h"
#include "uart.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

void (*UART_RX_CallBack) (u8) ;
u8 (*UART_Empty_CallBack) (void) ;
/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
u8 Uart_Tx_Buffer[200];
u8 Uart_Rx_Buffer[200];
u8 index_Rx=0;
u8 current_index=0;
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
u8 UART_Check_Recieve_STR (void)
{
	/*if (index_Rx == 0)
	{
		return 0;
	}
	else if (Uart_Rx_Buffer[index_Rx-1] == '!')
	{
		return 1;
	}
	else
	{
		return 0;
	}*/
	u8 flag=0;
	for(u8 i = 0;i<index_Rx;i++)
	{
		if (Uart_Rx_Buffer[i] == '!')
		{
			flag=1;
			break;
		}
	}
	return flag;
}
void UART_GetString(u8 *str)
{
	u8 i;
	for(i=0;Uart_Rx_Buffer[i] != '!';i++)
	{
		str[i]=Uart_Rx_Buffer[i];
	}
	str[i]='\0';
	index_Rx=0;
}
void UART_Tx_String(u8 *str)
{
	if(current_index==0)
	{u8 i;
		for (i=0; str[i]!= '\0';i++)
		{
			Uart_Tx_Buffer[i]=str[i];
		}
		str[i]='\0';
		UART_UDR_REG=str[0];
	}
}
/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void UART_Init(u16 baudRate)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : baudRate   UART baudrate                                                                     
* \Return value:   : None                                   
*******************************************************************************/
void UART_Init(u16 baudRate)
{
	/* Set baud rate */
	UART_UBRRL_REG = (u8)baudRate;
	UART_UBRRH_REG = (u8)(baudRate>>8);

	/* Enable receiver and transmitter */
	SET_BIT(UART_UCSRB_REG,RXEN_BIT_NO);  /* Enable Receiver*/
	SET_BIT(UART_UCSRB_REG,TXEN_BIT_NO);  /* Enable Transmitter */
	/* Set frame format: 8data, 1stop bit, Even Parity */
	UART_UCSRC_REG |= (1 << URSEL_BIT_NO) | UART_8_BIT_DATA | UART_EVEN_PARITY;

	SET_BIT(UART_UCSRB_REG,7); /*	Enable Rx Complete Interrupt	*/
	SET_BIT(UART_UCSRB_REG,6); /*	Enable Tx Complete Interrupt	*/
}

/******************************************************************************
* \Syntax          : void UART_TransmitChr(u8 data)      
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : data   data byte                                                                    
* \Return value:   : None                                   
*******************************************************************************/
void UART_TransmitChr(u8 data)
{
	while(!(UART_UCSRA_REG &(1<<UDRE_BIT_NO)));
	/* Put data into buffer*/
	UART_UDR_REG = data;
}

/******************************************************************************
* \Syntax          : u8 UART_ReceiveChr(void)       
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                                                                    
* \Return value:   : u8     received data byte                                   
*******************************************************************************/
u8 UART_ReceiveChr(void)
{
	while((UART_UCSRA_REG &(1<<RXC_BIT_NO)) == 0);
	return UART_UDR_REG;
}
/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
void UART_TransmitStr(u8 *str)
{
	u8 i=0;
	while(str[i] != '\0')
	{
		UART_TransmitChr(str[i]);
		i++;
	}
	UART_TransmitChr(str[i]);
}
void UART_receiveString(u8 *str)
{
	u8 i = 0;
	str[i] = UART_ReceiveChr();
	while(str[i] != '#')
	{
		i++;
		str[i] = UART_ReceiveChr();
	}
	str[i] = '\0';
}
void UART_RxInterruptEnable(void)
{
	SET_BIT(UART_UCSRB_REG,7);
}
void UART_TxInterruptEnable(void)
{
	SET_BIT(UART_UCSRB_REG,6);
}
void UART_DataEmptyInterruptEnable(void)
{
	SET_BIT(UART_UCSRB_REG,5);
}
void UART_RxInterruptDesable(void)
{
	CLEAR_BIT(UART_UCSRB_REG,7);
}
void UART_TxInterruptDesable(void)
{
	CLEAR_BIT(UART_UCSRB_REG,6);
}
void UART_DataEmptyInterruptDesable(void)
{
	CLEAR_BIT(UART_UCSRB_REG,5);
}


void UART_void_SetRXCallBack(void (*Copy_ptr) (u8) ) 
{
	UART_RX_CallBack = Copy_ptr ;
}
void UART_void_SetEmptyCallBack(u8 (*Copy_ptr) (void) )
{
	UART_Empty_CallBack = Copy_ptr ;
}
void __vector_13(void) __attribute__((signal , used));
/*void __vector_13(void)
{	
	UART_RX_CallBack(UART_UDR_REG);
}*/
void __vector_13(void)
{
	if (index_Rx <200)
	{
			Uart_Rx_Buffer[index_Rx]=UART_UDR_REG;
			index_Rx++;
	}

}
void __vector_15(void) __attribute__((signal , used));
void __vector_15(void)
{
	current_index++;
	if(Uart_Tx_Buffer[current_index]!='\0')
	{
		UART_UDR_REG=Uart_Tx_Buffer[current_index];
	}
	else
	{
		current_index=0;
	}
}
void __vector_14(void) __attribute__((signal , used));
void __vector_14(void)
{
	UART_UDR_REG=UART_Empty_CallBack();
}
