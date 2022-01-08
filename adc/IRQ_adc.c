/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           IRQ_adc.c
** Last modified Date:  2022-01-08
** Last Version:        V1.00
** Descriptions:        functions to manage A/D interrupts
** Correlated files:    adc.h
**--------------------------------------------------------------------------------------------------------       
*********************************************************************************************************/

#include "lpc17xx.h"
#include "adc.h"
#include "../paddle/paddle.h"

/*----------------------------------------------------------------------------
  A/D IRQ: Executed when A/D Conversion is ready (signal from ADC peripheral)
 *----------------------------------------------------------------------------*/

unsigned short AD_current;   
unsigned short AD_last = 0xFF;     /* Last converted value               */

extern uint16_t PADDLE_X0;
extern uint16_t PADDLE_X1;

int check_adc = 0;

void ADC_IRQHandler(void) {
  uint16_t new_paddleX0;
	AD_current = ((LPC_ADC->ADGDR>>4) & 0xFFF); /* Read Conversion Result	*/
	new_paddleX0 = AD_current*200/0xFFF;
	if(check_adc == 0){
		check_adc++;
	}else if(check_adc == 1){
		draw_paddle(new_paddleX0, new_paddleX0 + 40);
		check_adc++;
	}else if(check_adc == 2 && AD_current != AD_last){
		if((new_paddleX0 - PADDLE_X0 >= 8 && new_paddleX0 - PADDLE_X0 <= 15) || (new_paddleX0 - PADDLE_X0 <= -8 && new_paddleX0 - PADDLE_X0 >= -15)){
			move_paddle(new_paddleX0, new_paddleX0 + 40);
		}
	}
	AD_last = AD_current;
}

/******************************************************************************
**                            End Of File
******************************************************************************/
