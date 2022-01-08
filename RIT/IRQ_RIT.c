/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           IRQ_RIT.c
** Last modified Date:  2022-01-08
** Last Version:        V1.00
** Descriptions:        functions to manage RIT handler and buttons interrupts / bouncing
** Correlated files:    RIT.h
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
#include <stdio.h>
#include "lpc17xx.h"
#include "RIT.h"
#include "../GLCD/GLCD.h"
#include "../button_EXINT/button.h"
#include "../adc/adc.h" 
#include "../timer/timer.h"
#include "../GUI/GUI.h"
#include "../ball/ball.h"


/******************************************************************************
** Function name:		RIT_IRQHandler
**
** Descriptions:		REPETITIVE INTERRUPT TIMER handler
**
** parameters:			None
** Returned value:		None
**
******************************************************************************/

int down_INT0 = 0;
int down_KEY1 = 0;
int down_KEY2 = 0;

extern int check_adc;
extern int GAME_STATUS;

void RIT_IRQHandler (void)
{						
		/* KEY1 */
		if(down_KEY1 != 0){ 
			if((LPC_GPIO2->FIOPIN & (1<<11)) == 0){	/* KEY1 pressed */
				down_KEY1++;				
				switch(down_KEY1){
					case 2:
							// START THE GAME
							if(GAME_STATUS == 0){
								GAME_STATUS = 1;
								build_GUI(GAME_STATUS);
								ADC_init();
								enable_timer(0);
								enable_timer(1);
								NVIC_EnableIRQ(TIMER0_IRQn);
								NVIC_EnableIRQ(TIMER1_IRQn);
							}
						break;
					default:
						break;
				}
			}
			else {	/* button released */
				down_KEY1=0;			
				NVIC_EnableIRQ(EINT1_IRQn);							 /* enable Button interrupts			*/
				LPC_PINCON->PINSEL4    |= (1 << 22);     /* External interrupt 0 pin selection */
			}
		}
	
		/* KEY2 */
		if(down_KEY2 != 0){
			if((LPC_GPIO2->FIOPIN & (1<<12)) == 0){	/* KEY2 pressed */
				down_KEY2++;				
				switch(down_KEY2){
					case 2:
							// PAUSE
							if(GAME_STATUS == 1){
								GAME_STATUS = 2;
								build_GUI(GAME_STATUS);
								NVIC_DisableIRQ(TIMER0_IRQn);
								NVIC_DisableIRQ(TIMER1_IRQn);
							}
							// RESTART THE GAME
							else if(GAME_STATUS == 2){
								GAME_STATUS = 1;
								build_GUI(GAME_STATUS);
								check_adc = 0;
								NVIC_EnableIRQ(TIMER0_IRQn);
								NVIC_EnableIRQ(TIMER1_IRQn);
							}
						break;
					default:
						break;
				}
			}
			else {	/* button released */
				down_KEY2=0;			
				NVIC_EnableIRQ(EINT2_IRQn);							 /* enable Button interrupts			*/
				LPC_PINCON->PINSEL4    |= (1 << 24);     /* External interrupt 0 pin selection */
			}
		}
		
		/* INT0 */
		if(down_INT0 != 0){
			if((LPC_GPIO2->FIOPIN & (1<<10)) == 0){	/* INT0 pressed */
				down_INT0++;				
				switch(down_INT0){
					case 2:
						// RESET THE GAME / GAME OVER
						reset_score();
						if(GAME_STATUS != 3){
							reset_record();
						}
						GAME_STATUS = 0;
						build_GUI(GAME_STATUS);
						check_adc = 0;
						reset_ball();
						NVIC_DisableIRQ(TIMER0_IRQn);
						NVIC_DisableIRQ(TIMER1_IRQn);
						break;
					default:
						break;
				}
			}
			else {	/* button released */
				down_INT0=0;			
				NVIC_EnableIRQ(EINT0_IRQn);							 /* enable Button interrupts			*/
				LPC_PINCON->PINSEL4    |= (1 << 20);     /* External interrupt 0 pin selection */
			}
		}
		
  LPC_RIT->RICTRL |= 0x1;	/* clear interrupt flag */
}

/******************************************************************************
**                            End Of File
******************************************************************************/
