/*
 * carsensor.c
 *
 * Created: 11/15/2021 11:00:52 AM
 * Author : Shehata
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include "types.h"
#include "pinfun.h"
#include "DIO_private.h"
#include "DIO_interface.h"
#include "LCD.h"
#include "HCSR04.h"
#include "SERVO.h"
#include "Motor.h"
#include "Motor_Right.h"
#include <avr/delay.h>



int main(void)
{  
	LCD_Init();
	SERVO_INIT();
	MOTOR_Left_init();
	MOTOR_Right_init();
	LCD_WriteString("Distance in cm =",0,0);
	HCSR04_init();
	u16 Distancee;
	u16 distright;
	u16 distleft;
	u8 string[10];
	
	
	 
    while (1) 
    {  
	
		Distancee=HCSR04_Getdist();
		itoa(Distancee,string,10);
		LCD_WriteString(string,1,0);
		_delay_ms(200);
		MOTOR_Left_Forward();
		MOTOR_Right_Forward();
		if(Distancee<20 && Distancee>0)
		{
			MOTOR_Left_Stop();
			MOTOR_Right_Stop();
			SERVO_ROT_RIGHT();
			distright=HCSR04_Getdist();
			itoa(distright,string,10);
			LCD_WriteString(string,1,0);
			SERVO_ROT_LEFT();
			distleft=HCSR04_Getdist();
			itoa(distleft,string,10);
			LCD_WriteString(string,1,0);
			SERVO_ROT_FORWARD();
			_delay_ms(2000);
			Distancee=HCSR04_Getdist();
			itoa(Distancee,string,10);
			LCD_WriteString(string,1,0);
			
			if (distright>=distleft && distright>=20)
			{
			  MOTOR_Left_Forward();
			  u16 rdist;
			  rdist=HCSR04_Getdist();
			  while(rdist<distright)
			  {
				  rdist=HCSR04_Getdist();
				  itoa(rdist,string,10);
				  LCD_WriteString(string,1,0);
				  
			  }
			  MOTOR_Right_Forward();
			  	 
			}
			 else if (distleft>distright && distleft>=20)  
			 {
				
				MOTOR_Right_Forward();
				u16 ldist;
				ldist=HCSR04_Getdist();
				 while(ldist<distleft)
				 {
					 ldist=HCSR04_Getdist();
					 itoa(ldist,string,10);
					 LCD_WriteString(string,1,0);
					 
				 }
				 MOTOR_Left_Forward();
				
			}
			else break;
			
		
		}
		
	}
		

	
}

