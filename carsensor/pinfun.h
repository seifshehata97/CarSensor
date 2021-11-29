#ifndef Bit_access
#define Bit_access

/* Macro for Getting specific Bit value */
#define Get_bit(Reg,bit)            (Reg&(1<<bit))>>bit
/* Macro for setting specific Bit */
#define Set_bit(Reg,bit)            (Reg |=(1<<bit))
/* Macro for toggling specific Bit */
#define Toggle_bit(Reg,bit)         (Reg ^=(1<<bit))
/* Macro for Clearing specific Bit */
#define Clear_bit(Reg,bit)          (Reg &= ~(1<<bit))

#endif // Bit_access


