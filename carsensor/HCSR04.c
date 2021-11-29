#define F_CPU 8000000UL

#include <avr/io.h>
#include <avr/delay.h>
#include "types.h"
#include "pinfun.h"
#include "DIO_private.h"
#include "DIO_interface.h"
#include "LCD.h"
#include "HC-SR04_Config.h"
#include "HCSR04.h"
#include <avr/interrupt.h>


static int volatile TimerOverflow = 0;
/*
void HCSR04_ISR(void){
	TimerOverflow++;
}
*/
ISR(TIMER1_OVF_vect)
{
	TimerOverflow++;	/* Increment Timer Overflow count */
}

void HCSR04_init () {
	
	//u32 Timer;
	
	
	DIO_SetPinDirection(E_PORT,E_PIN,DIO_INPUT);
	DIO_WritePinValue(E_PORT,E_PIN,DIO_HIGH);
	DIO_SetPinDirection(T_PORT,T_PIN,DIO_OUTPUT);
	
	EXTI_EnableInt0();
	EXTI_Init();
	GIE_vidEnable();
	//EXTI_SetCallback(HCSR04_ISR);
	TIMSK = (1 << TOIE1);	/* Enable Timer1 overflow interrupts */
	TCCR1A = 0;		/* Set all bit to zero Normal operation */
}

	
int HCSR04_Getdist(){
	
	int count;
	int Distance;
	DIO_WritePinValue(T_PORT,T_PIN,DIO_HIGH);
	_delay_us(10);
	DIO_WritePinValue(T_PORT,T_PIN,DIO_LOW);
	
	TCNT1 = 0;	/* Clear Timer counter */
	TCCR1B = 0x41;	/* Capture on rising edge, No prescaler*/
	TIFR = 1<<ICF1;	/* Clear ICP flag (Input Capture flag) */
	TIFR = 1<<TOV1;	/* Clear Timer Overflow flag */
	
	while ((TIFR & (1 << ICF1)) == 0);/* Wait for rising edge */
	TCNT1 = 0;	/* Clear Timer counter */
	TCCR1B = 0x01;	/* Capture on falling edge, No prescaler */
	TIFR = 1<<ICF1;	/* Clear ICP flag (Input Capture flag) */
	TIFR = 1<<TOV1;	/* Clear Timer Overflow flag */
	TimerOverflow = 0;/* Clear Timer overflow count */
	
	
	while ((TIFR & (1 << ICF1)) == 0);/* Wait for falling edge */
	count = (ICR1 + (65535 * TimerOverflow));	/* Take count */
	/* 8MHz Timer freq, sound speed =343 m/s */
	Distance = ((int)count / 466.47)+1;
	_delay_ms(100);

return Distance;

}	
	

