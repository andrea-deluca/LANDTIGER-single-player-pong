/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           GUI.h
** Last modified Date:  2022-01-08
** Last Version:        V1.00
** Descriptions:        Prototypes of functions included in the lib_GUI.c file
** Correlated files:    lib_GUI.c
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include "LPC17xx.h"
#include "../GLCD/GLCD.h"

/* Private define ------------------------------------------------------------*/

/* GUI Text */
#define INSTITUTE " Politecnico di Torino "
#define AUTHOR " Andrea Deluca S303906"
#define GAME_NAME " Pong "
#define START_GAME " Press KEY1 to start the game "
#define RESTART_GAME "Press KEY2 to restart the game"
#define RESET_GAME " Press INT0 to reset the game "
#define RECORD_STR " Record: "
#define SCORE_STR " Score: "
#define PAUSE_STR " Pause "
#define GAME_OVER_STR " You lose "

/* GUI Borders Settings */
#define BORDER_DIMENSION 5
#define PADDING_BOTTOM 42

/* GUI Score value protected area */
#define SCORE_X0 5
#define SCORE_X1 10
#define SCORE_Y0 150
#define SCORE_Y1 170

/* GUI Record value protected area */
#define RECORD_X0 190
#define RECORD_X1 200
#define RECORD_Y0 5
#define RECORD_Y1 50

/* GUI Record string protected area */
#define RECORD_STR_X0 120
#define RECORD_STR_X1 190
#define RECORD_STR_Y0 5
#define RECORD_STR_Y1 50

/* Game default values */
#define DEFAULT_RECORD 100

/* Private function prototypes -----------------------------------------------*/
void init_GUI(void);
void build_GUI(const int status);
void update_score(void);
void reset_score(void);
void reset_record(void);
void checkForGUI(const uint16_t ballX0, const uint16_t ballX1, const uint16_t ballY);

/*****************************************************************************
**                            End Of File
******************************************************************************/
