#include "types.h"
#include "pinfun.h"
#include "DIO_private.h"
#include "DIO_interface.h"
#include "LCD.h"
#include <avr/delay.h>

static u8 InitStepFinished=0;
void LCD_Init()
{
	
	DIO_SetPinDirection(DIO_PORTA, D1, DIO_OUTPUT);
	DIO_SetPinDirection(DIO_PORTA, D2, DIO_OUTPUT);
	DIO_SetPinDirection(DIO_PORTA, D3, DIO_OUTPUT);
	DIO_SetPinDirection(DIO_PORTA, D4, DIO_OUTPUT);
	DIO_SetPinDirection(DIO_PORTB, RS, DIO_OUTPUT);
	DIO_SetPinDirection(DIO_PORTB, RW, DIO_OUTPUT);
	DIO_SetPinDirection(DIO_PORTB,  E, DIO_OUTPUT);
	
	_delay_ms(30);

    LCD_Cmd(0x20);
	LCD_Cmd(0x20);
	LCD_Cmd(0x80);
	_delay_ms(1);
	
	LCD_Cmd(0x00);
	LCD_Cmd(0xF0);
	_delay_ms(1);
	
	LCD_Cmd(0x00);
	LCD_Cmd(0x00);
	_delay_ms(2);
	
	
	
	InitStepFinished=1;
}

void LCD_Cmd(u8 cmd){
	
	DIO_WritePinValue(DIO_PORTB,RS,DIO_LOW);
	DIO_WritePinValue(DIO_PORTB,RW,DIO_LOW);
	
	
	DIO_WritePinValue(DIO_PORTA,D1,Get_bit(cmd,4));
	DIO_WritePinValue(DIO_PORTA,D2,Get_bit(cmd,5));
	DIO_WritePinValue(DIO_PORTA,D3,Get_bit(cmd,6));
	DIO_WritePinValue(DIO_PORTA,D4,Get_bit(cmd,7));
	
	DIO_WritePinValue(DIO_PORTB,E,DIO_HIGH);
	_delay_ms(1);
	DIO_WritePinValue(DIO_PORTB,E,DIO_LOW);
	
	if(InitStepFinished)
	{
		
	DIO_WritePinValue(DIO_PORTA,D1,Get_bit(cmd,0));
	DIO_WritePinValue(DIO_PORTA,D2,Get_bit(cmd,1));
	DIO_WritePinValue(DIO_PORTA,D3,Get_bit(cmd,2));
	DIO_WritePinValue(DIO_PORTA,D4,Get_bit(cmd,3));
	
	DIO_WritePinValue(DIO_PORTB,E,DIO_HIGH);
	_delay_ms(1);
	DIO_WritePinValue(DIO_PORTB,E,DIO_LOW);
	}
	_delay_ms(2);
	
}

void LCD_WriteDATA(u8 Data){
	
	DIO_WritePinValue(DIO_PORTB,RS,DIO_HIGH);
	DIO_WritePinValue(DIO_PORTB,RW,DIO_LOW);
	
	
	DIO_WritePinValue(DIO_PORTA,D1,Get_bit(Data,4));
	DIO_WritePinValue(DIO_PORTA,D2,Get_bit(Data,5));
	DIO_WritePinValue(DIO_PORTA,D3,Get_bit(Data,6));
	DIO_WritePinValue(DIO_PORTA,D4,Get_bit(Data,7));
	
	DIO_WritePinValue(DIO_PORTB,E,DIO_HIGH);
	_delay_ms(1);
	DIO_WritePinValue(DIO_PORTB,E,DIO_LOW);
	
	
		
	DIO_WritePinValue(DIO_PORTA,D1,Get_bit(Data,0));
	DIO_WritePinValue(DIO_PORTA,D2,Get_bit(Data,1));
	DIO_WritePinValue(DIO_PORTA,D3,Get_bit(Data,2));
	DIO_WritePinValue(DIO_PORTA,D4,Get_bit(Data,3));
		
	DIO_WritePinValue(DIO_PORTB,E,DIO_HIGH);
	_delay_ms(1);
	DIO_WritePinValue(DIO_PORTB,E,DIO_LOW);
	
	_delay_ms(2);
	
	
	
}
void LCD_WriteString(u8 *Str,u8 row,u8 col){
	LCD_GoToPos(row,col);
	u8 index=0;
	u8 line=0;
	
	while(Str[index]!='\0' && ((row*16)+(index + col)) <32)
	{
		if(((row*16)+(index + col))<16)
		{ LCD_WriteDATA(Str[index]);
		 index++;
		}
		else if (((row*16)+(index + col))==16 && line ==0)
		{
			LCD_GoToPos(1,0);
			line++;
		}
		else if (((row*16)+(index + col))<32 && line==1)
		{
			 LCD_WriteDATA(Str[index]);
			 index++;
		}
		 
	}
	
}
void LCD_GoToPos(u8 row,u8 col){
	u8 address;
	if(row<2 && col<16)
	{
		address=(row * 0x40)+col;
		address=Set_bit(address,7);
		LCD_Cmd(address);
	}
	
}
void LCD_StoreCustomChr(u8*pattern,u8 CGRAM_index){
	u8 ad;
	u8 index;
	if(CGRAM_index < 8)
	{
		ad = CGRAM_index *8;
		ad=Set_bit(ad,6);
		LCD_Cmd(ad);
		for (index=0;index<8;index++)
		{
			LCD_WriteDATA(pattern[index]);
		}
	}
	LCD_Cmd(0x02);
}
void LCD_DisplayCustomChr(u8 CGRAM_index,u8 Row,u8 Col){
	LCD_GoToPos(Row,Col);
	LCD_WriteDATA(CGRAM_index);
}