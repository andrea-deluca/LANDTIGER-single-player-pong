/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           lib_GUI.c
** Last modified Date:  2022-01-08
** Last Version:        V1.00
** Descriptions:        functions to manage the GUI
** Correlated files:    GUI.h
**--------------------------------------------------------------------------------------------------------       
*********************************************************************************************************/
#include "GUI.h"

volatile int GAME_STATUS = 0;

int currentScore = 0;
int recordScore = DEFAULT_RECORD;
char score[sizeof(currentScore)];
char record[sizeof(recordScore)];


/******************************************************************************
** Function name:		init_GUI
**
** Descriptions:		function to clear GAME_STATUS
**
** parameters:			none
** Returned value:	None
**
******************************************************************************/
void init_GUI(void){
	GAME_STATUS = 0;
}


/******************************************************************************
** Function name:		home_GUI
**
** Descriptions:		function to build the first view of the game
**
** parameters:			none
** Returned value:	None
**
******************************************************************************/
void home_GUI(void){
	GUI_Text(24, 20, (uint8_t *) INSTITUTE, White, Black);
	GUI_Text(24, 40, (uint8_t *) AUTHOR, White, Black);
	GUI_Text(94, 160, (uint8_t *) GAME_NAME, White, Black);
	GUI_Text(0, 280, (uint8_t *) START_GAME, Black, White);
}


/******************************************************************************
** Function name:		game_GUI
**
** Descriptions:		function to build the view of the game
**
** parameters:			none
** Returned value:	None
**
******************************************************************************/
void game_GUI(void){
	int i = 0;
	// DRAW BORDERS
	for(i = 0; i < BORDER_DIMENSION; i++){
		LCD_DrawLine(i, MAX_Y - PADDING_BOTTOM, i, 0, Red);
		LCD_DrawLine(0, i, MAX_X, i, Red);
		LCD_DrawLine((MAX_X - 1) - i, 0, (MAX_X - 1) - i, MAX_Y - PADDING_BOTTOM, Red);
	}
	// SHOW TEXT
	GUI_Text(120, 10, (uint8_t *) RECORD_STR, White, Black);
	GUI_Text(190, 10, (uint8_t *) record , White, Black);
	GUI_Text(10, 160, (uint8_t *) score, White, Black);
}


/******************************************************************************
** Function name:		pause_GUI
**
** Descriptions:		function to build the GUI when the game is paused
**
** parameters:			none
** Returned value:	None
**
******************************************************************************/
void pause_GUI(void){
	GUI_Text(10, 10, (uint8_t *) RECORD_STR, White, Black);
	GUI_Text(100, 10, (uint8_t *) record , White, Black);
	GUI_Text(10, 30, (uint8_t *) SCORE_STR, White, Black);
	GUI_Text(100, 30, (uint8_t *) score, White, Black);
	GUI_Text(95, 160, (uint8_t *) PAUSE_STR, White, Black);
	GUI_Text(0, 250, (uint8_t *) RESTART_GAME, Black, White);
	GUI_Text(0, 280, (uint8_t *) RESET_GAME, White, Red);
}


/******************************************************************************
** Function name:		game_over_GUI
**
** Descriptions:		function to build the GUI when player loses
**
** parameters:			none
** Returned value:	None
**
******************************************************************************/
void game_over_GUI(void){
	GUI_Text(80, 160, (uint8_t *) GAME_OVER_STR, Red, Black);
	GUI_Text(10, 10, (uint8_t *) RECORD_STR, White, Black);
	GUI_Text(100, 10, (uint8_t *) record , White, Black);
	GUI_Text(10, 30, (uint8_t *) SCORE_STR, White, Black);
	GUI_Text(100, 30, (uint8_t *) score, White, Black);
	GUI_Text(0, 280, (uint8_t *) RESET_GAME, White, Red);
}


/******************************************************************************
** Function name:		build_GUI
**
** Descriptions:		function to manage the construction of the GUI
**									depending on the GAME_STATUS value
**
** parameters:			staus: status of the game
** Returned value:	None
**
******************************************************************************/
void build_GUI(const int status){
	LCD_Clear(Black);
	sprintf(record, "%d", recordScore);
	sprintf(score, "%d", currentScore);
	switch(status){
		case 0:
			home_GUI();
			break;
		case 1:
			game_GUI();
			break;
		case 2:
			pause_GUI();
			break;
		case 3:
			game_over_GUI();
			break;
		default:
			break;
	}
}


/******************************************************************************
** Function name:		update_record
**
** Descriptions:		function to update the record value and show it
**
** parameters:			none
** Returned value:	None
**
******************************************************************************/
void update_record(void){
	recordScore = currentScore;
	sprintf(record, "%d", recordScore);
	GUI_Text(180, 10, (uint8_t *) record , White, Black);
}


/******************************************************************************
** Function name:		update_score
**
** Descriptions:		function to update the score value and show it
**
** parameters:			none
** Returned value:	None
**
******************************************************************************/
void update_score(void){
	if(currentScore < 100){
		currentScore += 5;
	} else currentScore += 10;
	sprintf(score, "%d", currentScore);
	GUI_Text(10, 160, (uint8_t *) score, White, Black);
	if(currentScore > recordScore) update_record();
}


/******************************************************************************
** Function name:		reset_score
**
** Descriptions:		function to reset the score value
**
** parameters:			none
** Returned value:	None
**
******************************************************************************/
void reset_score(void){
	currentScore = 0;
	sprintf(score, "%d", currentScore);
}


/******************************************************************************
** Function name:		reset_record
**
** Descriptions:		function to reset the record value
**
** parameters:			none
** Returned value:	None
**
******************************************************************************/
void reset_record(void){
	recordScore = DEFAULT_RECORD;
	sprintf(record, "%d", recordScore);
}


/******************************************************************************
** Function name:		hideGUI
**
** Descriptions:		function to hide an element from the GUI during the game
**
** parameters:			GUI_element: id of the element to hide
** Returned value:	None
**
******************************************************************************/
void hideGUI(const int GUI_element){
	switch(GUI_element){
		// Score value
		case 1:
			GUI_Text(10, 160, (uint8_t *) score, Black, Black);
			break;
		// Record value
		case 2:
			GUI_Text(190, 10, (uint8_t *) record , Black, Black);
			break;
		// Record text
		case 3:
			GUI_Text(120, 10, (uint8_t *) RECORD_STR, Black, Black);
			break;
		default:
			break;
	}
}


/******************************************************************************
** Function name:		showGUI
**
** Descriptions:		function to show an element in the GUI during the game
**
** parameters:			GUI_element: id of the element to show
** Returned value:	None
**
******************************************************************************/
void showGUI(const int GUI_element){
	switch(GUI_element){
		// Score value
		case 1:
			GUI_Text(10, 160, (uint8_t *) score, White, Black);
			break;
		// Record value
		case 2:
			GUI_Text(190, 10, (uint8_t *) record , White, Black);
			break;
		// Record text
		case 3:
			GUI_Text(120, 10, (uint8_t *) RECORD_STR, White, Black);
			break;
		default:
			break;
	}
}


/******************************************************************************
** Function name:		checkForGUI
**
** Descriptions:		function to check if the ball is going to conflict with
**									some GUI element
**
** parameters:			ball_X0: start position of the ball on x direction
**									ball_X1: end position of the ball on x direction
**									ball_Y: position of the upper side of the ball on the
										y direction
**
** Returned value:	None
**
******************************************************************************/
void checkForGUI(const uint16_t ballX0, const uint16_t ballX1, const uint16_t ballY){
	static int flag = 0;
	static int hide_element = 0;
	
	if(!flag && ballX0 >= SCORE_X0 && ballX1 <= SCORE_X1 && ballY >= SCORE_Y0 && ballY + 5 <= SCORE_Y1){
		hide_element = 1;
		flag = 1;
	} else if(hide_element == 1 && flag == 2 && ((ballX1 > SCORE_X1) || (ballY < SCORE_Y0 || ballY + 5 > SCORE_Y1))){
		flag = 3;
	}
	
	if(!flag && ballX0 >= RECORD_X0 && ballX1 <= RECORD_X1 && ballY >= RECORD_Y0 && ballY + 5 <= RECORD_Y1){
		hide_element = 2;
		flag = 1;
	} else if(hide_element == 2 && flag == 2 && ((ballX0 < RECORD_X0) || ( ballY + 5 > RECORD_Y1))){
		flag = 3;
	}
	
	if(!flag && ballX0 >= RECORD_STR_X0 && ballX1 <= RECORD_STR_X1 && ballY >= RECORD_STR_Y0 && ballY + 5 <= RECORD_STR_Y1){
		hide_element = 3;
		flag = 1;
	} else if(hide_element == 3 && flag == 2 && ((ballX0 < RECORD_STR_X0 || ballX1 > RECORD_STR_X1) || ( ballY + 5 > RECORD_STR_Y1))){
		flag = 3;
	}
	
	if(flag == 1){
		hideGUI(hide_element);
		flag = 2;
	} else if(flag == 3){
		showGUI(hide_element);
		flag = 0;
	} 
}

/******************************************************************************
**                            End Of File
******************************************************************************/
