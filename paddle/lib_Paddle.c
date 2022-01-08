/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           lib_Paddle.c
** Last modified Date:  2022-01-08
** Last Version:        V1.00
** Descriptions:        functions to manage the Paddle
** Correlated files:    paddle.h
**--------------------------------------------------------------------------------------------------------       
*********************************************************************************************************/
#include "paddle.h"

uint16_t PADDLE_X0 = 0;
uint16_t PADDLE_X1 = 0;
uint16_t PADDLE_Y = MAX_Y - MARGIN_BOTTOM;


/******************************************************************************
** Function name:		draw_paddle
**
** Descriptions:		function to draw the paddle, given start and end position 
**									on x direction (positions on y direction are fixed)
**
** parameters:			paddleX0: start position of the paddle on x direction
**									paddleX1: end position of the paddle on x direction
**
** Returned value:	None
**
******************************************************************************/
void draw_paddle(const uint16_t paddleX0, const uint16_t paddleX1){
	int i = 0;
	for(i = 0; i < PADDLE_THICK; i++){
			LCD_DrawLine(paddleX0, PADDLE_Y - i, paddleX1, PADDLE_Y - i, Green);
		}
	// update position
	PADDLE_X0 = paddleX0;
	PADDLE_X1 = paddleX1;
}


/******************************************************************************
** Function name:		move_paddle
**
** Descriptions:		function to move the paddle from the last position
**									to the given new position
**
** parameters:			new_paddleX0: new start position of the paddle on x direction
**									new_paddleX1: new end position of the paddle on x direction
**
** Returned value:	None
**
******************************************************************************/
void move_paddle(const uint16_t new_paddleX0, const uint16_t new_PaddleX1){
	int i = 0;
	for(i = 0; i < 10; i++){
		if(new_paddleX0 > PADDLE_X0){
			LCD_DrawLine(PADDLE_X0, PADDLE_Y - i, new_paddleX0, PADDLE_Y - i, Black);
			LCD_DrawLine(PADDLE_X1, PADDLE_Y - i, new_paddleX0 + 40, PADDLE_Y - i, Green);
		} else {
			LCD_DrawLine(new_paddleX0 + 40, PADDLE_Y - i, PADDLE_X1, PADDLE_Y - i, Black);
			LCD_DrawLine(new_paddleX0, PADDLE_Y - i, PADDLE_X0, PADDLE_Y - i, Green);
		}
	}
	// update position
	PADDLE_X0 = new_paddleX0;
	PADDLE_X1 = new_PaddleX1;
}

/******************************************************************************
**                            End Of File
******************************************************************************/
