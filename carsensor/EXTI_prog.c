/*
 * EXTI_prog.c
 *
 *  Created on: Oct 2, 2021
 *      Author: Ahmed El-Gaafrawy
 */
#include "types.h"
#include "EXTI_types.h"
#include "EXTI_int.h"
#include "AVR_REG.h"
#include "pinfun.h"
#include "EXTI_Config.h"

void(*CallBackPtr)(void)=NULL;

void EXTI_Init(void){
	Clear_bit(MCUCR_reg,0);
	Clear_bit(MCUCR_reg,1);
	Clear_bit(MCUCR_reg,2);
	Clear_bit(MCUCR_reg,3);
	
	
	
	#if   EXTI0_MODE  ==    EXTI_Low_Level
	     MCUCR_reg |= EXTI_Low_Level;
    #elif EXTI0_MODE  ==    EXTI_Any_Logical_change
	     MCUCR_reg |= EXTI_Any_Logical_change;
    #elif EXTI0_MODE  ==    EXTI_Falling_Edge
	     MCUCR_reg |= EXTI_Falling_Edge;
    #elif EXTI0_MODE  ==    EXTI_Rising_Edge
	     MCUCR_reg |= EXTI_Rising_Edge;
    #endif
	
	#if   EXTI1_MODE  ==    EXTI_Low_Level
	MCUCR_reg |= (EXTI_Low_Level <<2);
	#elif EXTI1_MODE  ==    EXTI_Any_Logical_change
	MCUCR_reg |= (EXTI_Any_Logical_change<<2);
	#elif EXTI1_MODE  ==    EXTI_Falling_Edge
	MCUCR_reg |= (EXTI_Falling_Edge<<2);
	#elif EXTI1_MODE  ==    EXTI_Rising_Edge
	MCUCR_reg |= (EXTI_Rising_Edge<<2);
	#endif
	
	#if   EXTI2_MODE  ==    EXTI_INT2_Falling_Edge
	Clear_bit(MCUCSR_reg,6);
	#elif EXTI2_MODE  ==    EXTI_INT2_Rising_Edge
	Set_bit(MCUCSR_reg,6);
	#endif
	
	#if   EXTI_INT0_INIT_STATE  ==    EXTI_Enable_State
	Set_bit(GICR_reg,6);
	#elif EXTI_INT0_INIT_STATE  ==    EXTI_Disable_State
	Clear_bit(GICR_reg,6);
	#endif
	
	#if   EXTI_INT1_INIT_STATE  ==    EXTI_Enable_State
	Set_bit(GICR_reg,7);
	#elif EXTI_INT1_INIT_STATE  ==    EXTI_Disable_State
	Clear_bit(GICR_reg,7);
	#endif
	
	#if   EXTI_INT2_INIT_STATE  ==    EXTI_Enable_State
	Set_bit(GICR_reg,5);
	#elif EXTI_INT2_INIT_STATE  ==    EXTI_Disable_State
	Clear_bit(GICR_reg,5);
	#endif
	
	Set_bit(GIFR_reg,5);
	Set_bit(GIFR_reg,6);
	Set_bit(GIFR_reg,7);
	
}

void EXTI_EnableInt0(void){
	Set_bit(GICR_reg,6);
}

void EXTI_DisableInt0(void){
	Clear_bit(GICR_reg,6);
}

void EXTI_SetCallback(void(*CopyFuncPtr)(void)){
	
	CallBackPtr=CopyFuncPtr;
	
}


void __vector_1(void)__attribute__((signal,used));
void __vector_1(void){
	if(CallBackPtr!= NULL)
	CallBackPtr();
	
}