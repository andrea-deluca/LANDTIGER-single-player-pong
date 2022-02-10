[![GitHub license](https://img.shields.io/github/license/andrea-deluca/LANDTIGER-single-player-pong)](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/blob/main/LICENSE)

# LANDTIGER-single-player-pong
Single-player version of the game called "Pong", implemented by using the LandTiger Emulator available on Keil uVision, that reproduce the behaviour of the classic table tennis-themed arcade game, originally released in 1972 by Atari.


## Description of requests
For this project, start by implementing a single-player version of the game where the player must not let the ball fall below the paddle. The paddle can only move horizontally, and the player operates it through the _potentiometer_ available in the LandTiger board.

The game field should be implemented vertically, i.e., the paddle will be in the bottom portion of the _LCD display_ with red walls (5px thick) on the left, upper and right portion of the _display_ for the ball to bounce on.

When the ball hits a wall, it should bounce with a reflection angle equal to the incident one. For instance, if a ball going downwards hits the left wall with an incident angle of 30°, then it will bounce downwards with the same 30° angle.

When the ball hits the paddle, the reflection angle **must not always be equal** to the incident one, for example, depending on what part of the paddle is hit by the ball. The choice on **how fast** the ball moves is left unconstrained.

The paddle should be **32px high from the bottom part** of the _screen_ and **10px thick**, and the **ball should be a 5x5px square**.

Whenever the ball hits a wall or the paddle, the _buzzer_ should emit a lower pitched note (when bouncing on the wall) and a higher pitched note (when bouncing on the paddle).

Every time the ball hits the paddle, the score is incremented by 5. If the score is greater than 100, whenever the paddle touches the ball, it is incremented by 10 points. The score must be printed on the left side of the _screen_, at mid high (160px from both the bottom and top part of the LCD). The score is saved in between games, and the new record (the maximum score since the board was last reset) is displayed in the top right corner. The initial record to beat is **100 points**. Whenever the board is powered off or the _RESET_ button is pressed, the score is reset as well. If the ball falls below the paddle, a message “You lose” should be displayed.

The user should **start the game** by pressing the button _KEY1_. When the game starts, the ball should be touching the right wall at mid high (160px from both the bottom and top part of the screen) and go downwards with an angle of 45°. To **pause the game and later resume it**, the user should press the button _KEY2_. In case of **game over**, to **prepare a new game** the player should press the _INT0_ button, followed by _KEY1_ to start it.

### Note
Having to use the emulator and not the physical board, all the non-ideality behaviors must be enabled and considered by your software and the _RIT_ and _Timers_ scaling switches can be enabled for debugging faster the project.


## Reference
This project has been developed by Andrea Deluca for the course of "Architetture dei sistemi di elaborazione", attended during the academic year 2021/22 at Politecnico di Torino, Master's Degree in Computer Engineering.
