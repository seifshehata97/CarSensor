#define F_CPU 8000000UL

#include <avr/io.h>
#include <avr/delay.h>
#include "types.h"
#include "pinfun.h"
#include "DIO_private.h"
#include "DIO_interface.h"
#include "Motor_Right.h"
#include "Motor_Right_Config.h"

void MOTOR_Right_init(){
	
	DIO_SetPinDirection(Motor_Right_Port,Motor_Right_pin0,DIO_OUTPUT);
	DIO_SetPinDirection(Motor_Right_Port,Motor_Right_pin1,DIO_OUTPUT);
	
}
void MOTOR_Right_Forward(){
	DIO_SetPinDirection(Motor_Right_Port,Motor_Right_pin0,DIO_LOW);
	DIO_SetPinDirection(Motor_Right_Port,Motor_Right_pin1,DIO_HIGH);
}

void MOTOR_Right_Stop(){
	DIO_SetPinDirection(Motor_Right_Port,Motor_Right_pin0,DIO_LOW);
	DIO_SetPinDirection(Motor_Right_Port,Motor_Right_pin1,DIO_LOW);
}

void MOTOR_Right_Backward(){
	DIO_SetPinDirection(Motor_Right_Port,Motor_Right_pin1,DIO_LOW);
	DIO_SetPinDirection(Motor_Right_Port,Motor_Right_pin0,DIO_HIGH);
}