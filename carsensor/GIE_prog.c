/*

 * GIE_prog.c
 *
 *  Created on: Oct 2, 2021
 *      Author: Ahmed El-Gaafrawy
 */
#include "types.h"
#include "AVR_REG.h"
#include "GIE_int.h"


void GIE_vidEnable(void)
{
	SREG_reg |=(1<<7);

}
void GIE_vidDisable(void)
{
	SREG_reg &=~(1<<7);
}
