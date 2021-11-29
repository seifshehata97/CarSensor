/*
 * AVR_DIO_REG.h
 *
 *  Created on: Aug 23, 2019
 *      Author: hp
 */

#ifndef AVR_REG_H_
#define AVR_REG_H_

/*
 * NULL
 */
#define NULL  ((void*)0)

/*
 * DIO REGISTERS
 */
/*
#define PORTA 	*((volatile u8*) 0x3B)
#define DDRA  	*((volatile u8*) 0x3A)
#define PINA  	*((volatile u8*) 0x39)

#define PORTB 	*((volatile u8*) 0x38)
#define DDRB  	*((volatile u8*) 0x37)
#define PINB  	*((volatile u8*) 0x36)

#define PORTC 	*((volatile u8*) 0x35)
#define DDRC  	*((volatile u8*) 0x34)
#define PINC  	*((volatile u8*) 0x33)

#define PORTD 	*((volatile u8*) 0x32)
#define DDRD  	*((volatile u8*) 0x31)
#define PIND  	*((volatile u8*) 0x30)
*/
/*
 * INTERRUPT REGISTERS
 */

#define MCUCR_reg 	*((volatile u8*) 0x55)
#define MCUCSR_reg	*((volatile u8*) 0x54)
#define GICR_reg	*((volatile u8*) 0x5B)
#define SREG_reg  	*((volatile u8*) 0x5F)
#define GIFR_reg  	*((volatile u8*) 0x5A)

/*
 * TIMER RESIGTERS
 */

/*TIMSK*/
#define TIMSK	*((volatile u8*) 0x59)

/*TIFR*/
#define TIFR	*((volatile u8*) 0x58)

/*TCCR*/
#define TCCR0	*((volatile u8*) 0x53)
#define TCCR1A	*((volatile u8*) 0x4F)
#define TCCR1B	*((volatile u8*) 0x4E)
#define TCCR2	*((volatile u8*) 0x45)

/*TCNT*/
#define TCNT0	*((volatile u8*) 0x52)

#define TCNT1H	*((volatile u8*) 0x4D)
#define TCNT1L	*((volatile u8*) 0x4C)

#define TCNT1	*((volatile u16*) 0x4C)

#define TCNT2	*((volatile u8*) 0x44)

/*OCR*/
#define OCR0	*((volatile u8*) 0x5C)
#define OCR1AH	*((volatile u8*) 0x4B)
#define OCR1AL	*((volatile u8*) 0x4A)

#define OCR1A	*((volatile u16*) 0x4A)

#define OCR1BH	*((volatile u8*) 0x49)
#define OCR1BL	*((volatile u8*) 0x48)

#define OCR1B	*((volatile u16*) 0x48)

#define OCR2	*((volatile u8*) 0x43)

/*
 * ADC REGISTERS
 */
#define ADMUX	*((volatile u8*) 0x27)
#define ADCSRA	*((volatile u8*) 0x26)
#define ADCH	*((volatile u8*) 0x25)
#define ADCL	*((volatile u8*) 0x24)

/*
 * UASRT REGISTERS
 */

#define UDR		*((volatile u8*) 0x2C)
#define UCSRA	*((volatile u8*) 0x2B)
#define UCSRB	*((volatile u8*) 0x2A)
#define UCSRC	*((volatile u8*) 0x40)
#define UBRRL	*((volatile u8*) 0x29)
#define UBRRH	*((volatile u8*) 0x40)

/*
 * SPI REGISTERS
 */

#define SPDR	*((volatile u8*) 0x2f)
#define SPSR	*((volatile u8*) 0x2e)
#define SPCR	*((volatile u8*) 0x2d)

#endif /* AVR_REG_H_ */
