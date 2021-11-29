#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

/* PORT A Registers addresses ( Direction, Input, OUTPUT) */
#define PORTA_DIR_REG  *((volatile u8*) 0x3a)
#define PORTA_IN_REG   *((volatile u8*) 0x39)
#define PORTA_OUT_REG  *((volatile u8*) 0x3b)

/* PORT B Registers addresses ( Direction, Input, OUTPUT) */
#define PORTB_DIR_REG  *((volatile u8*) 0x37)
#define PORTB_IN_REG   *((volatile u8*) 0x36)
#define PORTB_OUT_REG  *((volatile u8*) 0x38)

/* PORT C Registers addresses ( Direction, Input, OUTPUT) */
#define PORTC_DIR_REG  *((volatile u8*) 0x34)
#define PORTC_IN_REG   *((volatile u8*) 0x33)
#define PORTC_OUT_REG  *((volatile u8*) 0x35)

/* PORT D Registers addresses ( Direction, Input, OUTPUT) */
#define PORTD_DIR_REG  *((volatile u8*) 0x31)
#define PORTD_IN_REG   *((volatile u8*) 0x30)
#define PORTD_OUT_REG  *((volatile u8*) 0x32)

#endif
