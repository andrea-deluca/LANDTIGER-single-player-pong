/*----------------------------------------------------------------------------
 * Name:    sample.c
 * Purpose: Single-player Pong game
 * Note(s):
 *----------------------------------------------------------------------------
 *
 * This software is supplied "AS IS" without warranties of any kind.
 *
 * Copyright (c) 2022 Politecnico di Torino - Andrea Deluca S303906. 
 * All rights reserved.
 
 *----------------------------------------------------------------------------*/
                  
#include <stdio.h>
#include "LPC17xx.H"
#include "led/led.h"
#include "button_EXINT/button.h"
#include "timer/timer.h"
#include "RIT/RIT.h"
#include "adc/adc.h"
#include "GLCD/GLCD.h"
#include "GUI/GUI.h"

#ifdef SIMULATOR
extern uint8_t ScaleFlag; // <- ScaleFlag needs to visible in order for the emulator to find the symbol (can be placed also inside system_LPC17xx.h but since it is RO, it needs more work)
#endif

/*----------------------------------------------------------------------------
  Main Program
 *----------------------------------------------------------------------------*/

extern int GAME_STATUS; 

int main (void) {
  	
	SystemInit();  												/* System Initialization (i.e., PLL)  */
	
	BUTTON_init();
	init_RIT(0x004C4B40);									/* RIT Initialization 50 msec       	*/
	enable_RIT();													/* RIT enabled												*/
	
	init_timer(0, 0x0000C350);						/* T0 init 2ms												*/
	init_timer(1, 0x000030D4);						/* T1 init 1ms												*/
	
	LCD_Initialization();									/* LCD Initialization									*/
	init_GUI();														/* Game status initialization				 	*/
	build_GUI(GAME_STATUS);								/* Build GUI 													*/
	
	LPC_SC->PCON |= 0x1;									/* power-down	mode										*/
	LPC_SC->PCON &= ~(0x2);						
	
	LPC_PINCON->PINSEL1 |= (1<<21);
	LPC_PINCON->PINSEL1 &= ~(1<<20);
	LPC_GPIO0->FIODIR |= (1<<26);
	
  while (1) {                           /* Loop forever                       */	
		__ASM("wfi");
  }
}

/*----------------------------------------------------------------------------
  End of file
 *----------------------------------------------------------------------------*/
