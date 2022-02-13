# Ball
This library has been created by Andrea Deluca to manage the movement and the settings of the ball and its interaction with other objects in game, such as the hit of the ball on the paddle or on a wall. All files have been written from scratch for the purpose.

## Table of Contents
1. [Constants](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/ball#constants)
2. [Functions](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/ball#functions)

## Constants
In `ball.h` file you can find all the private defines of the library. Here a summary of the defined constants and a short description for each of them.

| Name | Value | Description |
|:-----|:------|:------------|
| `BALL_DIMENSION` | `5` | Dimension in pixel of the sides of the ball in game. |
| `DEFAULT_BALL_X0, DEFAULT_BALL_X1, DEFAULT_BALL_Y` | `229, 234, 158` | Default position of the ball on the display when game starts. In particular, the ball is drawn from the 229th pixel to the 234th pixel of the display horizontally and from the 158th pixel vertically. |
| `TAN_15` | `0.2679` | Tangent value of 15 degrees. |
| `TAN_45` | `1` | Tangent value of 45 degrees. |
| `BORDER_LEFT, BORDER_RIGHT, BORDER_TOP, BORDER_BOTTOM` | `8, 232, 6, 300` | Pixels of the display where the game defines the start of borders (red walls) in game. They are used to check if the ball has to bounce. |
| `LOWER_PITCHED_NOTE_FREQ` | `265` | Value of the interval of the _Timer2_ related to the D/A conversion when the _buzzer_ has to play a lower pithced note because the ball hits a wall. |
| `HIGHER_PITCHED_NOTE_FREQ` | `133` | Value of the interval of the _Timer2_ related to the D/A conversion when the _buzzer_ has to play an higher pithced note because the ball hits the paddle. |

## Functions
Functions make use of some variables to control specific functionality. In particular, `int firstTouch` variable stores information about the first touch of the ball on the wall when game starts. On the other hand, `static double tan`, `static int falling_ball` and `static int fromLeftToRight` variables control particular aspects of the motion of the ball, i.e. the bounce angle when the ball hits the paddle or a wall, vertical direction of the ball, so if it's falling or it's going up, and horizontal direction of the ball.

There are also extern variables to store information about the current position of the paddle, bacause in this way a function can control if the ball hits the paddle itself, and an extern variable that store the current score value, to be updatable.

Here a summary of the available functions and a short description for each of them.

| Function name | Input params | Return value | Description | Scope |
|:--------------|:-------------|:-------------|:------------|:------|
| [`reset_ball`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/ball#reset_ball-) | `void` | `void` | Reset ball settings and position to be ready for a new game. | Public |
| [`play_sound`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/ball#play_sound-) | `const int sound` | `void` | Initialize and enable timer to play sound when ball hits the paddle or a wall. | Private |
| [`change_direction`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/ball#change_direction-) | `const int x_direction, const int y_direction, const double bouceAngle` | `void` | Chenge the direction of the motion of the ball. | Private |
| [`checkForCollision`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/ball#checkForCollision-) | `void` | `void` | Check if the ball is hitting the paddle or a wall. It checks also for game over condition.  | Public |
| [`draw_ball`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/ball#draw_ball-) | `const uint16_t new_ballX0, const uint16_t new_ballX1, const uint16_t new_ballY` | `void` | Draw the ball in the new position computed. | Public |
| [`move_ball`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/ball#move_ball) | `void` | `void` | Compute the new position of the ball. | Public |

</br>

### `reset_ball` ![Function scope](https://img.shields.io/badge/Scope-Public-brightgreen)
```c
void reset_ball(void)
```
#### Description
It resets ball settings and position to be ready for a new game.

</br>

### `play_sound` ![Function scope](https://img.shields.io/badge/Scope-Private-orange)
```c
void play_sound(const int sound)
```
#### Input parameters
- `const int sound`: value of the frequency of the note that has to be played.
#### Description
It initializes and enables timer to play sound when ball hits the paddle or a wall. According to project requestes, when the ball hits the paddle, an higher pithced note has to be played, instead, when the ball hits a wall, a lower pithced note has to be played.

</br>

### `change_direction` ![Function scope](https://img.shields.io/badge/Scope-Private-orange)
```c
void change_direction(const int x_direction, const int y_direction, const double bouceAngle)
```
#### Input parameters
- `const int x_direction`: `0` or `1` value to specify if the ball goes from left to right, or viceversa.
- `const int y_direction`: `0` or `1` value to specify if the ball is falling or if it's going up.
- `const double bouceAngle`: angular coefficient of the direction of the motion of the ball.
#### Description
It's changes settings that control the movement of the ball, i.e. `static int fromLeftToRight`, `static int falling_ball` and `static double tan` variables.

</br>

### `checkForCollision` ![Function scope](https://img.shields.io/badge/Scope-Public-brightgreen)
```c
void checkForCollision(void)
```
#### Description
It checks if the ball is hitting the paddle or a wall and It also checks for game over condition. If the ball hits the paddle or a wall, new direction is computed and `change_direction` function is called. Furthermore, in both cases `play_sound` function is also called.

When the ball hits the paddle, the direction sign, i.e. the sign of the bounce angle, is given by means the side where the ball hits the paddle itself and the value of the bounce angle is mapped in a range from -45 degrees to 45 degrees. Because, if the bounce angle tends to 0, the direction tends to be horizontal, so, if the bounce angle is so close to 0, then it is set to 15 degrees. At the end of this case, current score value is also updated.

This function checks also game over condition and in this case the game status is modified, game over screen is displayed and interrupts produced by timers are disabled.

</br>

### `draw_ball` ![Function scope](https://img.shields.io/badge/Scope-Public-brightgreen)
```c
void draw_ball(const uint16_t new_ballX0, const uint16_t new_ballX1, const uint16_t new_ballY)
```
#### Input parameters
- `const uint16_t new_ballX0`: new start position of the ball on horizontal direction.
- `const uint16_t new_ballX1`: new end position of the ball on horizontal direction.
- `const uint16_t new_ballY`: position of the new upper side of the ball on the vertical direction.
#### Description
It draws the ball in the new position computed. This action is optimized by means coloring only the new parts of the ball and deleting only the parts needed, accordding to new position computed and current direction of the ball, instead of deleting ball fully and then drawing again the complete ball in the new position.

</br>

### `move_ball` ![Function scope](https://img.shields.io/badge/Scope-Public-brightgreen)
```c
void move_ball(void)
```
#### Description
It computes the new position of the ball and it's called every time the related timer throws an interrupt. After checking if the ball hits a paddle or a wall, according to current direction of the ball, its new position is computed, a chekc for collision with GUI elements is performed and position variables are updated.

In particular, the ball only moves one pixel on the vertical direction at each update. On the other hand, the new position on horizontal direction is computed by means the equation of the bundle of straight lines passing through a point, selecting the only one that has direction given by the current tangent value, that represents the angular coefficient.


