/*
 * EXTI_Config.h
 *
 */

#ifndef EXTI_CONFIG_H_
#define EXTI_CONFIG_H_

/*
CONFIGURE EXTERNAL INTERUPPT 0 MODE

EXTI_Low_Level                  
EXTI_Any_Logical_change       
EXTI_Falling_Edge               
EXTI_Rising_Edge                
*/


#define EXTI0_MODE               EXTI_Any_Logical_change

/*
CONFIGURE EXTERNAL INTERUPPT 1 MODE

EXTI_Low_Level                  
EXTI_Any_Logical_change       
EXTI_Falling_Edge               
EXTI_Rising_Edge                
*/

#define EXTI1_MODE               EXTI_Any_Logical_change

/*
CONFIGURE EXTERNAL INTERUPPT 2 MODE
      
EXTI2_Falling_Edge               
EXTI2_Rising_Edge                
*/

#define EXTI2_MODE               EXTI_INT2_Falling_Edge

#define EXTI_INT0_INIT_STATE     EXTI_Enable_State
#define EXTI_INT1_INIT_STATE     EXTI_Disable_State
#define EXTI_INT2_INIT_STATE     EXTI_Disable_State

#endif /* EXTI_CONFIG_H_ */
