/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           ball.h
** Last modified Date:  2022-01-08
** Last Version:        V1.00
** Descriptions:        Prototypes of functions included in the lib_Ball.c file
** Correlated files:    lib_Ball.c
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "LPC17xx.h"
#include "../GLCD/GLCD.h"
#include "../GUI/GUI.h"
#include "../timer/timer.h"

/* Private define ------------------------------------------------------------*/

/* Ball settings */
#define BALL_DIMENSION 5
#define DEFAULT_BALL_X0 229
#define DEFAULT_BALL_X1 234
#define DEFAULT_BALL_Y 158

/* Angular constants */
#define TAN_15 0.2679
#define TAN_45 1

/* Border LCD positions */
#define BORDER_LEFT 8
#define BORDER_RIGHT 232
#define BORDER_TOP 6
#define BORDER_BOTTOM 300

/* Sounds */ 																		/* k=1/f'*f/n  k=f/(f'*n) k=25MHz/(f'*45) */
#define LOWER_PITCHED_NOTE_FREQ 265 						/* C7 (Bouncing on wall) */
#define HIGHER_PITCHED_NOTE_FREQ	133						/* C8 (bouncing on paddle) */

/* Private function prototypes -----------------------------------------------*/
void reset_ball(void);
void checkForCollision(void);
void draw_ball(const uint16_t new_ballX0, const uint16_t new_ballX1, const uint16_t new_ballY);
void move_ball(void);

/*****************************************************************************
**                            End Of File
******************************************************************************/
