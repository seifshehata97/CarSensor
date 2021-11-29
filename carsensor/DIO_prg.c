
#include "types.h"
#include "pinfun.h"
#include "DIO_private.h"
#include "Dio_Interface.h"

/*
  Description: function to set the pin direction 
  parameters: Port which will be ( DIO_PORTA, DIO_PORTB, DIO_PORTC, DIO_PORTD)
              Pin Number 
			  Direction which will be (DIO_PINOUT, DIO_PININ
  return     void 
*/			    
void DIO_SetPinDirection( u8 PORT, u8 PIN, u8 Direction)
{
	switch(PORT)
	{
		case DIO_PORTA:
		switch(Direction)
		{
			case DIO_INPUT:
			Clear_bit(PORTA_DIR_REG, PIN);
			break;
			
			case DIO_OUTPUT:
			Set_bit(PORTA_DIR_REG, PIN);
			break;
			
			default:
			break;
		}
		break;
		
		case DIO_PORTB:
		switch(Direction)
		{
			case DIO_INPUT:
			Clear_bit(PORTB_DIR_REG, PIN);
			break;
			
			case DIO_OUTPUT:
			Set_bit(PORTB_DIR_REG, PIN);
			break;
			
			default:
			break;
		}
		break;
		
		case DIO_PORTC:
		switch(Direction)
		{
			case DIO_INPUT:
			Clear_bit(PORTC_DIR_REG, PIN);
			break;
			
			case DIO_OUTPUT:
			Set_bit(PORTC_DIR_REG, PIN);
			break;
			
			default:
			break;
		}
		break;
		
		case DIO_PORTD:
		switch(Direction)
		{
			case DIO_INPUT:
			Clear_bit(PORTD_DIR_REG, PIN);
			break;
			
			case DIO_OUTPUT:
			Set_bit(PORTD_DIR_REG, PIN);
			break;
			
			default:
			break;
		}
		break;
		
		default:
		break;
	}
}
/**************************************************************/

/*
  Description: function to set the pin value 
  parameters: Port which will be ( DIO_PORTA, DIO_PORTB, DIO_PORTC, DIO_PORTD)
              Pin Number 
			  Value which will be (DIO_PINHIGH, DIO_PINLOW)
  return     void 
*/
void DIO_WritePinValue(u8 PORT, u8 PIN, u8 Value)
{
	switch(PORT)
	{
		case DIO_PORTA:
		switch(Value)
		{
			case DIO_HIGH:
			Set_bit(PORTA_OUT_REG, PIN);
			break;
			
			case DIO_LOW:
			Clear_bit(PORTA_OUT_REG, PIN);
			break;
			
			default:
			break;
		}
		break;
		
		case DIO_PORTB:
		switch(Value)
		{
			case DIO_HIGH:
			Set_bit(PORTB_OUT_REG, PIN);
			break;
			
			case DIO_LOW:
			Clear_bit(PORTB_OUT_REG, PIN);
			break;
			
			default:
			break;
		}
		break;
		
		case DIO_PORTC:
		switch(Value)
		{
			case DIO_HIGH:
			Set_bit(PORTC_OUT_REG, PIN);
			break;
			
			case DIO_LOW:
			Clear_bit(PORTC_OUT_REG, PIN);
			break;
			
			default:
			break;
		}
		break;
		
		case DIO_PORTD:
		switch(Value)
		{
			case DIO_HIGH:
			Set_bit(PORTD_OUT_REG, PIN);
			break;
			
			case DIO_LOW:
			Clear_bit(PORTD_OUT_REG, PIN);
			break;
			
			default:
			break;
		}
		break;
		
		default:
		break;
	}
}
/**************************************************************/


/*
  Description: function to Get the pin value 
  parameters: Port which will be ( DIO_PORTA, DIO_PORTB, DIO_PORTC, DIO_PORTD)
              Pin Number 
  return     u8 for the pin value ( 0, 1) 
*/
u8 DIO_GetPinValue(u8 PORT, u8 PIN)
{
	u8 Reagding=0 ;
	switch(PORT)
	{
		case DIO_PORTA:
		Reagding = Get_bit(PORTA_IN_REG, PIN);
		break;
		
		case DIO_PORTB:
		Reagding = Get_bit(PORTB_IN_REG, PIN);
		break;
		
		case DIO_PORTC:
		Reagding = Get_bit(PORTC_IN_REG, PIN);
		break;
		
		case DIO_PORTD:
		Reagding = Get_bit(PORTD_IN_REG, PIN);
		break;
		default:
		break;
	}
	return Reagding;
}
/***********************************************************************/


/*
  Description: function to set the port direction 
  parameters: Port which will be ( DIO_PORTA, DIO_PORTB, DIO_PORTC, DIO_PORTD)
              Direction which will be (PORT_OUT, PORT_IN) 
  return     void 
*/
void Dio_SetPortDirection(u8 PORT, u8 Direction)
{
	switch(PORT)
	{
		case DIO_PORTA:
		switch(Direction)
		{
			case DIO_OUTPUT:
			PORTA_DIR_REG = PORT_OUT;
			break;
			
			case DIO_INPUT:
			PORTA_DIR_REG = PORT_IN;
			break;
			
			default:
			break;
		}
		break;
		
		case DIO_PORTB:
		switch(Direction)
		{
			case DIO_OUTPUT:
			PORTB_DIR_REG = PORT_OUT;
			break;
			
			case DIO_INPUT:
			PORTC_DIR_REG = PORT_IN;
			break;
			
			default:
			break;
		}
		break;
		
		case DIO_PORTC:
		switch(Direction)
		{
			case DIO_OUTPUT:
			PORTC_DIR_REG = PORT_OUT;
			break;
			
			case DIO_INPUT:
			PORTC_DIR_REG = PORT_IN;
			break;
			
			default:
			break;
		}
		break;
		
		case DIO_PORTD:
		switch(Direction)
		{
			case DIO_OUTPUT:
			PORTD_DIR_REG = PORT_OUT;
			break;
			
			case DIO_INPUT:
			PORTD_DIR_REG = PORT_IN;
			break;
			
			default:
			break;
		}
		break;
		
		
	}
}
/************************************************************************/

/*
  Description: function to set the port value 
  parameters: Port which will be ( DIO_PORTA, DIO_PORTB, DIO_PORTC, DIO_PORTD)
              value which will be (PORT_HIGH, PORT_LOW) 
  return     void 
*/
void Dio_WritePortValue(u8 PORT, u8 value)
{
	switch(PORT)
	{
		case DIO_PORTA:
			PORTA_OUT_REG = value;
			break;
		case DIO_PORTB:
			PORTB_OUT_REG = value;
			break;
		case DIO_PORTC:
		   PORTC_OUT_REG = value;
		   break;
		case DIO_PORTD:
		   PORTD_OUT_REG = value;
		   break;
		default:
		break;
	}
}
/**************************************************/
