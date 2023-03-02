/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  LED.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "LED.h"
#include "dio.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void led_init (void)
        
* \Description     : this service for initialize the leds channels                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : none
* \Return value:   : None                            
*******************************************************************************/
  
void led_init (void)
{
	/***********initialize pins as output****************/
		dio_vidConfigChannel(LED_RED_PORT, LED_RED_PIN, OUTPUT);
		dio_vidConfigChannel(LED_GREEN_PORT, LED_GREEN_PIN, OUTPUT);
		dio_vidConfigChannel(LED_BLUE_PORT, LED_BLUE_PIN, OUTPUT);
		dio_vidConfigChannel(LED_YELLOW_PORT, LED_YELLOW_PIN, OUTPUT);

	/************initial state************/
	
		/******red led*********/
		#if (LED_RED_DIRECT==LED_SOURCE_DIRECT)
		{
			dio_vidWriteChannel(LED_RED_PORT, LED_RED_PIN,STD_LOW );  //source mode
		}
		#else
		{
			dio_vidWriteChannel(LED_RED_PORT, LED_RED_PIN,STD_HIGH );  //sink mode
		}
		#endif 
		
		/*********green led***********/
		#if (LED_GREEN_DIRECT==LED_SOURCE_DIRECT)
		{
			dio_vidWriteChannel(LED_GREEN_PORT, LED_GREEN_PIN,STD_LOW );
		}
		#else
		{
			dio_vidWriteChannel(LED_GREEN_PORT, LED_GREEN_PIN,STD_HIGH );
		}
		#endif
		
		/***********blue led***********/
		#if (LED_BLUE_DIRECT==LED_SOURCE_DIRECT)
		{
			dio_vidWriteChannel(LED_BLUE_PORT, LED_BLUE_PIN,STD_LOW );
		}
		#else
		{
			dio_vidWriteChannel(LED_BLUE_PORT, LED_BLUE_PIN,STD_HIGH );
		}
		#endif
		
		/*******yellow led**********/
		#if (LED_YELLOW_DIRECT==LED_SOURCE_DIRECT)
		{
			dio_vidWriteChannel(LED_YELLOW_PORT, LED_YELLOW_PIN,STD_LOW );
		}
		#else
		{
			dio_vidWriteChannel(LED_YELLOW_PORT, LED_YELLOW_PIN,STD_HIGH );
		}
		#endif	
}
/******************************************************************************
* \Syntax          : void led_on (u8 led_id)        
* \Description     : this service for make a led on                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : led_id 	   -> led ID (1,2,3,4)
* \Return value:   : None                            
*******************************************************************************/

void led_on (u8 led_id)
{
			switch(led_id) //detect which led on
			{
				
				/**********red led********/
				case LED_RED:
				#if (LED_RED_DIRECT==LED_SOURCE_DIRECT)
				{
					dio_vidWriteChannel(LED_RED_PORT, LED_RED_PIN,STD_HIGH );  //source mode
				}
				#else
				{
					dio_vidWriteChannel(LED_RED_PORT, LED_RED_PIN,STD_LOW ); //sink mode
				}
				#endif
				break;
				
				/*********green led***********/
				case LED_GREEN:
				#if (LED_GREEN_DIRECT==LED_SOURCE_DIRECT)
				{
					dio_vidWriteChannel(LED_GREEN_PORT, LED_GREEN_PIN,STD_HIGH );
				}
				#else
				{
					dio_vidWriteChannel(LED_GREEN_PORT, LED_GREEN_PIN,STD_LOW );
				}
				#endif
				break;
				
				/**********blue led**********/
				case LED_BLUE:
				#if (LED_BLUE_DIRECT==LED_SOURCE_DIRECT)
				{
					dio_vidWriteChannel(LED_BLUE_PORT, LED_BLUE_PIN,STD_HIGH );
				}
				#else
				{
					dio_vidWriteChannel(LED_BLUE_PORT, LED_BLUE_PIN,STD_LOW );
				}
				#endif
				break;
				
				/**********yellow led********/
				case LED_YELLOW:
				#if (LED_YELLOW_DIRECT==LED_SOURCE_DIRECT)
				{
					dio_vidWriteChannel(LED_YELLOW_PORT, LED_YELLOW_PIN,STD_HIGH );
				}
				#else
				{
					dio_vidWriteChannel(LED_YELLOW_PORT, LED_YELLOW_PIN,STD_LOW );
				}
				#endif
				break;
			}	
}
/******************************************************************************
* \Syntax          : void led_off (u8 led_id)
* \Description     : this service for make a led off
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : led_id 	   -> led ID (1,2,3,4)
* \Return value:   : None
*******************************************************************************/
void led_off (u8 led_id)
{
	switch(led_id) //detect which led off
	{
		/********red led**********/
		case LED_RED:
		#if (LED_RED_DIRECT==LED_SOURCE_DIRECT)
		{
			dio_vidWriteChannel(LED_RED_PORT, LED_RED_PIN,STD_LOW );     //source mode
		}
		#else
		{
			dio_vidWriteChannel(LED_RED_PORT, LED_RED_PIN,STD_HIGH );  //sink mode
		}
		#endif
		break;
		
		/***********green led*******/
		case LED_GREEN:
		#if (LED_GREEN_DIRECT==LED_SOURCE_DIRECT)
		{
			dio_vidWriteChannel(LED_GREEN_PORT, LED_GREEN_PIN,STD_LOW );
		}
		#else
		{
			dio_vidWriteChannel(LED_GREEN_PORT, LED_GREEN_PIN,STD_HIGH );
		}
		#endif
		break;
		
		/***********blue**********/
		case LED_BLUE:
		#if (LED_BLUE_DIRECT==LED_SOURCE_DIRECT)
		{
			dio_vidWriteChannel(LED_BLUE_PORT, LED_BLUE_PIN,STD_LOW );
		}
		#else
		{
			dio_vidWriteChannel(LED_BLUE_PORT, LED_BLUE_PIN,STD_HIGH );
		}
		#endif
		break;
		
		/*************yellow********/
		case LED_YELLOW:
		#if (LED_YELLOW_DIRECT==LED_SOURCE_DIRECT)
		{
			dio_vidWriteChannel(LED_YELLOW_PORT, LED_YELLOW_PIN,STD_LOW );
		}
		#else
		{
			dio_vidWriteChannel(LED_YELLOW_PORT, LED_YELLOW_PIN,STD_HIGH );
		}
		#endif
		break;
	}
}
/******************************************************************************
* \Syntax          : void led_toggle (u8 led_id)
* \Description     : this service for make a led toggle its state
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : led_id 	   -> led ID (1,2,3,4)
* \Return value:   : None
*******************************************************************************/
void led_toggle (u8 led_id)
{
	switch(led_id)
	{
		
		/*********red**********/
		case LED_RED:
        dio_vidFlipChannel(LED_RED_PORT, LED_RED_PIN);
		break;
		
		/********green**********/
		case LED_GREEN:
        dio_vidFlipChannel(LED_GREEN_PORT, LED_GREEN_PIN);
		break;
		
		/*******blue********/
		case LED_BLUE:
        dio_vidFlipChannel(LED_BLUE_PORT, LED_BLUE_PIN);
		break;
		
		/*********yellow**********/
		case LED_YELLOW:
        dio_vidFlipChannel(LED_YELLOW_PORT, LED_YELLOW_PIN);
		break;
	}	
}
