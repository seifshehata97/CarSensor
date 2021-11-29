#define F_CPU 8000000UL

#include <avr/io.h>
#include <avr/delay.h>
#include "types.h"
#include "pinfun.h"
#include "DIO_private.h"
#include "DIO_interface.h"
#include "SERVO.h"
#include "SERVO_Config.h"

void SERVO_INIT(){
	
	DIO_SetPinDirection(SERVO_PORT,SERVO_PIN,DIO_OUTPUT);
	DIO_WritePinValue(SERVO_PORT,SERVO_PIN,DIO_LOW);
	
}

void SERVO_ROT_RIGHT(){
	DIO_WritePinValue(SERVO_PORT,SERVO_PIN,DIO_HIGH);
	_delay_us(1250);
	DIO_WritePinValue(SERVO_PORT,SERVO_PIN,DIO_LOW);
	_delay_ms(5000);
}

void SERVO_ROT_LEFT(){
	DIO_WritePinValue(SERVO_PORT,SERVO_PIN,DIO_HIGH);
	_delay_us(1750);
	DIO_WritePinValue(SERVO_PORT,SERVO_PIN,DIO_LOW);
	_delay_ms(5000);	
}
void SERVO_ROT_FORWARD(){
	DIO_WritePinValue(SERVO_PORT,SERVO_PIN,DIO_HIGH);
	_delay_us(990);
	DIO_WritePinValue(SERVO_PORT,SERVO_PIN,DIO_LOW);
	_delay_ms(2000);
	
}


