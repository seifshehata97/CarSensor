#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_
/******************************************/
/*********** public definitions ***********/
/******************************************/
#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

#define DIO_PIN_0 0
#define DIO_PIN_1 1
#define DIO_PIN_2 2
#define DIO_PIN_3 3
#define DIO_PIN_4 4
#define DIO_PIN_5 5
#define DIO_PIN_6 6
#define DIO_PIN_7 7


#define DIO_INPUT  0
#define DIO_OUTPUT 1

#define DIO_LOW    0
#define DIO_HIGH   1

#define PORT_OUT    0xFF
#define PORT_IN     0x00

#define PORT_HIGH     0xFF
#define PORT_LOW    0x00




/******************************************/
/*********** public functions *************/
/******************************************/

/* IO pins functions */
void DIO_SetPinDirection( u8 PORT, u8 PIN, u8 Direction);
void DIO_WritePinValue(u8 PORT, u8 PIN, u8 Value);
u8 DIO_GetPinValue(u8 PORT, u8 PIN);

/* IO ports functions */
void Dio_SetPortDirection(u8 PORT, u8 Direction);
void Dio_WritePortValue(u8 PORT, u8 Direction);


#endif