#ifndef LCD
#define LCD
#define RS DIO_PIN_1
#define RW DIO_PIN_2
#define E  DIO_PIN_3
#define D1 DIO_PIN_4
#define D2 DIO_PIN_5
#define D3 DIO_PIN_6
#define D4 DIO_PIN_7

void LCD_Cmd(u8 cmd);
void LCD_WriteDATA(u8 Data);
void LCD_Init();
//void LCD_custom(u8 location , u8 *Data);
//void Set_Location(u8 location);
void LCD_WriteString(u8 *Str,u8 row,u8 col);
void LCD_GoToPos(u8 row,u8 col);
void LCD_StoreCustomChr(u8*pattern,u8 CGRAM_index);
void LCD_DisplayCustomChr(u8 CGRAM_index,u8 Row,u8 Col);
#endif 
