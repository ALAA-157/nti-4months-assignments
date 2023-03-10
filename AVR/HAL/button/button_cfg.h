/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  button_cfg.h
 *       Module:  button
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef BUTTON_CFG_H
#define BUTTON_CFG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define BUTTON0_PORT   	DIO_PORTD
#define BUTTON0_PIN		DIO_PIN7

#define BUTTON1_PORT	DIO_PORTD
#define BUTTON1_PIN		DIO_PIN6

#define BUTTON2_PORT	DIO_PORTD
#define BUTTON2_PIN		DIO_PIN5

#define PULL_UP			1
#define PULL_DOWN		0

/*	options		*/
/*	PULL_DOWN	*/
/*	PULL_UP		*/
#define BUTTON0_CONNECTION   PULL_UP
#define BUTTON1_CONNECTION   PULL_UP
#define BUTTON2_CONNECTION   PULL_UP


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

 
#endif  /* BUTTON_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: button_cfg.h
 *********************************************************************************************************************/
