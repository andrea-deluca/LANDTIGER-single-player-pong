![GitHub language count](https://img.shields.io/github/languages/count/andrea-deluca/LANDTIGER-single-player-pong)
![GitHub top language](https://img.shields.io/github/languages/top/andrea-deluca/LANDTIGER-single-player-pong)
[![Website polito.it](https://img.shields.io/badge/Associated%20with-Politecnico%20di%20Torino-blue)](https://www.polito.it)
[![GitHub license](https://img.shields.io/github/license/andrea-deluca/LANDTIGER-single-player-pong)](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/blob/main/LICENSE)

# LANDTIGER-single-player-pong
Single-player version of the game called "Pong", implemented by using the LandTiger Emulator available on Keil uVision, that reproduce the behaviour of the classic table tennis-themed arcade game, originally released in 1972 by Atari.

## Table of Contents
1. [Description of requests](https://github.com/andrea-deluca/LANDTIGER-single-player-pong#description-of-requests)
   - [Notes](https://github.com/andrea-deluca/LANDTIGER-single-player-pong#description-of-requests#notes)
2. [Development report](https://github.com/andrea-deluca/LANDTIGER-single-player-pong#development-report)
   - [Documentation](https://github.com/andrea-deluca/LANDTIGER-single-player-pong#development-report#documentation)
     - [Main](https://github.com/andrea-deluca/LANDTIGER-single-player-pong#development-report#documentation#main)
     - [Libraries](https://github.com/andrea-deluca/LANDTIGER-single-player-pong#development-report#documentation#libraries)
3. [Reference](https://github.com/andrea-deluca/LANDTIGER-single-player-pong#reference)

## Description of requests
For this project, start by implementing a single-player version of the game where the player must not let the ball fall below the paddle. The paddle can only move horizontally, and the player operates it through the _potentiometer_ available in the LandTiger board.

The game field should be implemented vertically, i.e., the paddle will be in the bottom portion of the _LCD display_ with red walls (5px thick) on the left, upper and right portion of the _display_ for the ball to bounce on.

When the ball hits a wall, it should bounce with a reflection angle equal to the incident one. For instance, if a ball going downwards hits the left wall with an incident angle of 30°, then it will bounce downwards with the same 30° angle.

When the ball hits the paddle, the reflection angle **must not always be equal** to the incident one, for example, depending on what part of the paddle is hit by the ball. The choice on **how fast** the ball moves is left unconstrained.

The paddle should be **32px high from the bottom part** of the _screen_ and **10px thick**, and the **ball should be a 5x5px square**.

Whenever the ball hits a wall or the paddle, the _buzzer_ should emit a lower pitched note (when bouncing on the wall) and a higher pitched note (when bouncing on the paddle).

Every time the ball hits the paddle, the score is incremented by 5. If the score is greater than 100, whenever the paddle touches the ball, it is incremented by 10 points. The score must be printed on the left side of the _screen_, at mid high (160px from both the bottom and top part of the LCD). The score is saved in between games, and the new record (the maximum score since the board was last reset) is displayed in the top right corner. The initial record to beat is **100 points**. Whenever the board is powered off or the _RESET_ button is pressed, the score is reset as well. If the ball falls below the paddle, a message “You lose” should be displayed.

The user should **start the game** by pressing the button _KEY1_. When the game starts, the ball should be touching the right wall at mid high (160px from both the bottom and top part of the screen) and go downwards with an angle of 45°. To **pause the game and later resume it**, the user should press the button _KEY2_. In case of **game over**, to **prepare a new game** the player should press the _INT0_ button, followed by _KEY1_ to start it.

### Notes
Having to use the emulator and not the physical board, all the non-ideality behaviors must be enabled and considered by your software and the _RIT_ and _Timers_ scaling switches can be enabled for debugging faster the project.

## Development report
A template was used as a starting project, built during the course, ready to manage the interaction with the hardware components on the board. In particular, three new libraries have been created to manage the paddle, ball and GUI functionalities respectively. Furthermore, the handlers of the components' interrupts have been modified to manage the events foreseen by the requests given.

### Documentation

#### Main
Looking at the [```sample.c```](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/sample.c) file, we find the main function, i.e. the starting point of the software, where all the hardware components and the GUI software component are initialazied.

### Libraries
The complete documentation of each library is found within the library itself. Here the linked list of the available documentation:

1. [GLCD - Graphical Liquid Crystal Display](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/GLDC)
2. [GUI - Graphical User Interface](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/GUI)
3. [RIT - Repetitive Interrupt Timer](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/RIT)
4. [ADC - Analog-to-Digital Converter](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/adc)
5. [Ball](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/ball)
6. [Button EXINT - Button External Interrupt](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/button_EXINT)
7. [Paddle](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/paddle)
8. [Timer](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/timer)

## Reference
This project has been developed by Andrea Deluca for the course of "Architetture dei sistemi di elaborazione", attended during the academic year 2021/22 at Politecnico di Torino, Master's Degree in Computer Engineering.
