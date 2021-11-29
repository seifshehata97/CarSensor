#define F_CPU 8000000UL

#include <avr/io.h>
#include <avr/delay.h>
#include "types.h"
#include "pinfun.h"
#include "DIO_private.h"
#include "DIO_interface.h"
#include "Motor.h"
#include "Motor_Config.h"

void MOTOR_Left_init(){
	
	DIO_SetPinDirection(Motor_Port,Motor_pin0,DIO_OUTPUT);
	DIO_SetPinDirection(Motor_Port,Motor_pin1,DIO_OUTPUT);
	
}
void MOTOR_Left_Forward(){
	DIO_SetPinDirection(Motor_Port,Motor_pin0,DIO_LOW);
	DIO_SetPinDirection(Motor_Port,Motor_pin1,DIO_HIGH);
}

void MOTOR_Left_Stop(){
	DIO_SetPinDirection(Motor_Port,Motor_pin0,DIO_LOW);
	DIO_SetPinDirection(Motor_Port,Motor_pin1,DIO_LOW);
}

void MOTOR_Left_Backward(){
	DIO_SetPinDirection(Motor_Port,Motor_pin1,DIO_LOW);
	DIO_SetPinDirection(Motor_Port,Motor_pin0,DIO_HIGH);
}