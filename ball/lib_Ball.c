/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           lib_Ball.c
** Last modified Date:  2022-01-08
** Last Version:        V1.00
** Descriptions:        functions to manage the Ball
** Correlated files:    ball.h
**--------------------------------------------------------------------------------------------------------       
*********************************************************************************************************/
#include "ball.h"

extern int GAME_STATUS;

int firstTouch = 1;
static double tan = -1;
static int falling_ball = 1;
static int fromLeftToRight = 0;

extern uint16_t PADDLE_X0;
extern uint16_t PADDLE_X1;
extern uint16_t PADDLE_Y;

uint16_t BALL_X0 = DEFAULT_BALL_X0;
uint16_t BALL_X1 = DEFAULT_BALL_X1;
uint16_t BALL_Y = DEFAULT_BALL_Y;

extern int currentScore;


/******************************************************************************
** Function name:		reset_ball
**
** Descriptions:		function to reset ball position and motion settings
**
** parameters:			none
** Returned value:	None
**
******************************************************************************/
void reset_ball(void){
	firstTouch = 1;
	falling_ball = 1;
	fromLeftToRight = 0;
	tan = -TAN_45;
	BALL_X0 = DEFAULT_BALL_X0;
	BALL_X1 = DEFAULT_BALL_X1;
	BALL_Y = DEFAULT_BALL_Y;
}


/******************************************************************************
** Function name:		play_sound
**
** Descriptions:		function to play a sound when ball hits the paddle 
**									or the wall
**
** parameters:			sound: id for the sound to play
** Returned value:	None
**
******************************************************************************/
void play_sound(const int sound){
		init_timer(2, sound);
		enable_timer(2);
}


/******************************************************************************
** Function name:		chang_direction
**
** Descriptions:		function to change the direction of the motion of the ball
**
** parameters:			x_direction: 0 or 1 to specify if the ball goes from left to
**									to right or not
**									y_direction: 0 or 1 to specify if the ball goes down or up
**									bounceAngle: angular coefficient of the direction of the motion
**
** Returned value:	None
**
******************************************************************************/
void change_direction(const int x_direction, const int y_direction, const double bouceAngle){
	fromLeftToRight = x_direction;
	falling_ball = y_direction;
	tan = bouceAngle;
}


/******************************************************************************
** Function name:		checkForCollision
**
** Descriptions:		function to check is the ball is going to hit the padlle
**									or some wall for change direction and update the score
**
** parameters:			none
** Returned value:	None
**
******************************************************************************/
void checkForCollision(void){
	double bounceAngle = tan;
	
	// Ball hits the paddle
	if(falling_ball && (BALL_Y + 5) == (PADDLE_Y - 10) && BALL_X0 >= PADDLE_X0 && BALL_X1 <= PADDLE_X1){
		// the direction, so the sign of the bounce angle, is given by the side
		// where the ball hits the paddle
		double relativeIntersect = (PADDLE_X0 + ((PADDLE_X1 - PADDLE_X0) / 2)) - BALL_X0;
		double normalizeRelativeIntersection = (relativeIntersect / ((PADDLE_X1 - PADDLE_X0) / 2));
		// the bounce angle goes from -45 to 45 degrees
		bounceAngle = normalizeRelativeIntersection * TAN_45;
		if(bounceAngle < 0){
			fromLeftToRight = 1;
		} else fromLeftToRight = 0;
		// if the bounce angle tends to 0, the direction tends to be horizontal
		// so if the bounce angle is so close to 0, it is set to 15 degrees
		if(bounceAngle > -0.25 && bounceAngle <= 0){
			change_direction(fromLeftToRight, !falling_ball, -TAN_15);
		} else if(bounceAngle < 0.25 && bounceAngle >= 0){
			change_direction(fromLeftToRight, !falling_ball, TAN_15);
		} else change_direction(fromLeftToRight, !falling_ball, bounceAngle);
		update_score();
		play_sound(HIGHER_PITCHED_NOTE_FREQ);
	}
	// Ball hits left wall while it falls
	else if(falling_ball && BALL_X0 <= BORDER_LEFT){
		if(tan < 0) bounceAngle = -tan;
		change_direction(1, falling_ball, bounceAngle);
		play_sound(LOWER_PITCHED_NOTE_FREQ);
	} 
	// Ball hits right wall while it falls
	else if(falling_ball && BALL_X1 >= BORDER_RIGHT){
		if(tan > 0) bounceAngle = -tan;
		change_direction(0, falling_ball, bounceAngle);
		play_sound(LOWER_PITCHED_NOTE_FREQ);
	} 
	// Ball hits upper wall while it goes up and it goes from left to right
	else if(!falling_ball && fromLeftToRight && BALL_Y <= BORDER_TOP){
		if(tan < 0) bounceAngle = -tan;
		change_direction(fromLeftToRight, !falling_ball, bounceAngle);
		play_sound(LOWER_PITCHED_NOTE_FREQ);
	}
	// Ball hits upper wall while it goes up and it goes from right to left
	else if(!falling_ball && !fromLeftToRight && BALL_Y <= BORDER_TOP){
		if(tan > 0) bounceAngle = -tan;
		change_direction(fromLeftToRight, !falling_ball, bounceAngle);
		play_sound(LOWER_PITCHED_NOTE_FREQ);
	} 
	// Ball hits right wall while it goes up 
	else if(!falling_ball && BALL_X1 >= BORDER_RIGHT){
		if(tan < 0) bounceAngle = -tan;
		change_direction(0, falling_ball, bounceAngle);
		play_sound(LOWER_PITCHED_NOTE_FREQ);
	}
	// Ball hits left wall while it goes up
	else if(!falling_ball && BALL_X0 <= BORDER_LEFT){
		if(tan > 0) bounceAngle = -tan;
		change_direction(1, falling_ball, bounceAngle);
		play_sound(LOWER_PITCHED_NOTE_FREQ);
	}
	// Ball falls, so game over
	else if(BALL_Y + 5 >= BORDER_BOTTOM){
		GAME_STATUS = 3;
		build_GUI(GAME_STATUS);
		NVIC_DisableIRQ(TIMER0_IRQn);
		NVIC_DisableIRQ(TIMER1_IRQn);
	}	 
}


/******************************************************************************
** Function name:		draw_ball
**
** Descriptions:		function to draw the ball in the new current position
**
** parameters:			new_ballX0: new start position of the ball on x direction
**									new_ballX1: new end position of the ball on x direction
**									new_ballY: position of the new upper side of the ball on the
**									y direction

** Returned value:	None
**
******************************************************************************/
void draw_ball(const uint16_t new_ballX0, const uint16_t new_ballX1, const uint16_t new_ballY){
	int i = 0;
	int dx = 0;
	
	// variance between last and new positions on x direction
	dx = BALL_X0 - new_ballX0;
	if(dx < 0){
		dx = -dx;
	}
	
	if(firstTouch){
		// First complete drawing of the ball
		for(i = 0; i < BALL_DIMENSION; i++){
			LCD_DrawLine(BALL_X0, BALL_Y + i, BALL_X1, BALL_Y + i, Green);
		}
	} 
	
	// update the ball depending on its current motion
	
	// the ball goes from left to right and it falls
	if(fromLeftToRight && falling_ball){
		LCD_DrawLine(BALL_X0, BALL_Y, BALL_X1, BALL_Y, Black);
		LCD_DrawLine(new_ballX0, new_ballY + 5, new_ballX1, new_ballY + 5, Green);
		for(i = 0; i <= dx; i++){
			LCD_DrawLine(BALL_X0 + i, BALL_Y, BALL_X0 + i, BALL_Y + 5, Black);
			LCD_DrawLine(new_ballX1 - i, new_ballY, new_ballX1 - i, new_ballY + 5, Green);
		}
	}
	// the ball goes from left to right and it goes up
	else if(fromLeftToRight && !falling_ball){
		LCD_DrawLine(BALL_X0, BALL_Y + 5, BALL_X1, BALL_Y + 5, Black);
		LCD_DrawLine(new_ballX0, new_ballY, new_ballX1, new_ballY, Green);
		for(i = 0; i <= dx; i++){
			LCD_DrawLine(BALL_X0 + i, BALL_Y, BALL_X0 + i, BALL_Y + 5, Black);
			LCD_DrawLine(new_ballX1 - i, new_ballY, new_ballX1 - i, new_ballY + 5, Green);
		}
	}
	// the ball goes from right to left and it falls
	else if(!fromLeftToRight && falling_ball){
		LCD_DrawLine(BALL_X0, BALL_Y, BALL_X1, BALL_Y, Black);
		LCD_DrawLine(new_ballX0, new_ballY + 5, new_ballX1, new_ballY + 5, Green);
		for(i = 0; i <= dx; i++){
			LCD_DrawLine(BALL_X1 - i, BALL_Y, BALL_X1 - i, BALL_Y + 5, Black);
			LCD_DrawLine(new_ballX0 + i, new_ballY, new_ballX0 + i, new_ballY + 5, Green);
		}
	}
	// the ball goes from right to left and it goes up
	else if(!fromLeftToRight && !falling_ball){
		LCD_DrawLine(BALL_X0, BALL_Y + 5, BALL_X1, BALL_Y + 5, Black);
		LCD_DrawLine(new_ballX0, new_ballY, new_ballX1, new_ballY, Green);
		for(i = 0; i <= dx; i++){
			LCD_DrawLine(BALL_X1 - i, BALL_Y, BALL_X1 - i, BALL_Y + 5, Black);		
			LCD_DrawLine(new_ballX0 + i, new_ballY, new_ballX0 + i, new_ballY + 5, Green);
		}
	}
}


/******************************************************************************
** Function name:		move_ball
**
** Descriptions:		function to move the ball
**
** parameters:			none
** Returned value:	None
**
******************************************************************************/
void move_ball(void){
	
	uint16_t new_ballX0;
	uint16_t new_ballX1;
	uint16_t new_ballY;
	
	if(!firstTouch) checkForCollision();
	if (GAME_STATUS == 3) return;
	
	// the ball only moves one position on the y direction at each update
	if(falling_ball){
		new_ballY = BALL_Y + 1;
	} else new_ballY = BALL_Y - 1;
	
	// from the equation of the bundle of straight lines passing through a point
	// select the only one that has direction given by the tangent, that represents
	// the angular coefficient
	new_ballX0 = (new_ballY + (tan * BALL_X0) - BALL_Y) / tan;
	new_ballX1 = new_ballX0 + 5;
	
	if(new_ballY < RECORD_Y1 || (new_ballY > SCORE_Y0 || new_ballY < SCORE_Y1)){
		checkForGUI(new_ballX0, new_ballX1, new_ballY);
	}
	
	draw_ball(new_ballX0, new_ballX1, new_ballY);
	
	// update position
	BALL_X0 = new_ballX0;
	BALL_X1 = new_ballX1;
	BALL_Y = new_ballY;
	
	if(firstTouch) firstTouch = 0;
	
}

/******************************************************************************
**                            End Of File
******************************************************************************/
