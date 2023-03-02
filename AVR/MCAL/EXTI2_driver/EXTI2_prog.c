/*
 * EXTI2_prog.c
 *
 * Created: 3/1/2023 5:20:10 PM
 *  Author: DELL
 */ 


/****************************************************************/
/*********************** STD LIB DIRECTIVES *********************/
/****************************************************************/

#include "std_types.h"
#include "bit_math.h"


/****************************************************************/
/*********************** Component DIRECTIVES *******************/
/****************************************************************/

#include "EXTI2_int.h"
#include "EXTI2_Config.h"
#include "EXTI2_private.h"


/***********************************************************/
/**!comment   :  pointer to function for callback	       */
/***********************************************************/
volatile pf p;

/****************************************************************/
/*********************** Function Implementation  ***************/
/****************************************************************/


/****************************************************************/
/* Description    :  This function used to initialize EXT0      */
/*					 Inputs : void 								*/
/*					 return : void		 						*/
/****************************************************************/



void EXT2_voidInit (void)
{
	
	/*  ( if / else if ) condition for Macros */
	
	#if EXTI2_SENSE_MODE == RISING
	SET_BIT(MCUCSR , 6);
	
	#elif EXTI2_SENSE_MODE == FALLING
	CLEAR_BIT(MCUCSR , 6);
	
	#endif
	/* End ( if ) condition for Macros */

	
	/** disable EXT2 in initialization function  **/
	/** like : void EXT2_voidDisable(); 		  */
	CLEAR_BIT( GICR , 5 );
	SET_BIT(GIFR , 5 ) ;	
}

/****************************************************************/
/* Description    : This function used to Enable EXT2			*/
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/

void EXT2_voidEnable()
{
	
	SET_BIT( GICR , 5 );
	
}


/****************************************************************/
/* Description    : This function used to Disable EXT2			*/
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/

void EXT2_voidDisable()
{
	
	CLEAR_BIT( GICR , 5 );
	
}

/****************************************************************/
/* Description    : This function used to communicate with the	*/
/*					function in App Layer(The Callback function)*/
/*						[ Layer Architecture Problem Solved ]	*/
/*																*/
/*					Inputs : Pointer to function that points to	*/
/*							 the first line of the function(ISR)*/
/*					Return : void								*/
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/

void EXT2_voidCallBack(pf addresscpy)
{
	if(addresscpy != NULL)
	{
		p = addresscpy;
	}
}

/****************************************************************/
/* Description    : This function used to Set lach Interrupt	*/
/*									 happens.					*/
/*																*/
/*					Inputs : Sense Mode				  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/
void EXT2_voidSetSignalch(u8 SenseCpy)
{
	if (SenseCpy == RISING)
	{
		SET_BIT(MCUCSR , 6);
	}
	else if (SenseCpy == FALLING)
	{
		CLEAR_BIT(MCUCSR , 6);
	}
}

/** Linker Problem solved */
void __vector_3(void) __attribute__(( signal , used ));


void __vector_3(void)
{
	p();
	
}

/***********************************************************************************************/
/************************************* END OF PROGRAM ******************************************/
/***********************************************************************************************/