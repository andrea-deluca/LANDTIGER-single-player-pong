/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           paddle.h
** Last modified Date:  2022-01-08
** Last Version:        V1.00
** Descriptions:        Prototypes of functions included in the lib_Paddle.c file
** Correlated files:    lib_Paddle.c
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "LPC17xx.h"
#include "../GLCD/GLCD.h"

/* Private define ------------------------------------------------------------*/

/* Paddle settings */
#define PADDLE_THICK 10
#define MARGIN_BOTTOM 32

/* Private function prototypes -----------------------------------------------*/
void draw_paddle(const uint16_t paddleX0, const uint16_t paddleX1);
void move_paddle(const uint16_t new_paddleX0, const uint16_t new_paddleX1);

/*****************************************************************************
**                            End Of File
******************************************************************************/
