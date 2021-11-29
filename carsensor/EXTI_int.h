/*
 * EXTI_int.h
 */

#ifndef EXTI_INT_H_
#define EXTI_INT_H_

// initialize external interrupt
void EXTI_Init(void);
// function to enable EXTI0 ISR
void EXTI_EnableInt0(void);
// function to disable EXTI0 ISR
void EXTI_DisableInt0(void);

//void EXTI_SetSenceLevel(u8 intNum, u8 senseLevel);

//void EXTI_vidCallBack(u8 intNum,void(*ptr)(void));
void EXTI_SetCallback(void(*CopyFuncPtr)(void));

#endif /* EXTI_INT_H_ */
