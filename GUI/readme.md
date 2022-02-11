# GUI - Graphical User Interface
This library has been created by Andrea Deluca to manage the visualization of graphical content to be shown in game and to show all game screens. All files have been written from scratch for the purpose.

## Table of Contents
1. [Costants](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/GUI#costants)
2. [Functions](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/GUI#functions)

## Costants
In `GUI.h` file you can find all the private defines of the library. In addition to all the texts to be shown in game, you can find following constants.

| Name | Value | Description |
|:-----|:------|:------------|
| `BORDER_DIMENSION` | `5` | Dimension in pixel of the border (wall) in game. |
| `PADDING_BOTTOM` | `42` | Value in pixel of the margin from the bottom of the border (wall) in game, necessary to not overlap the paddle area. |
| `SCORE_X0, SCORE_X1, SCORE_Y0, SCORE_Y1` | `5, 10, 150, 170` | They define protection area for the score value shown in game. In particular, the area covers from the 5th pixel to the 10th pixel of the display horizontally and from the 150th pixel to the 170th vertically. |
| `RECORD_X0, RECORD_X1, RECORD_Y0, RECORD_Y1` | `190, 200, 5, 50` | They define protection area for the record value shown in game. In particular, the area covers from the 190th pixel to the 200th pixel of the display horizontally and from the 5th pixel to the 50th vertically. |
| `RECORD_STR_X0, RECORD_STR_X1, RECORD_STR_Y0, RECORD_STR_Y1` | `120, 190, 5, 50` | They define protection area for the `" Record: "` text shown in game. In particular, the area covers from the 120th pixel to the 190th pixel of the display horizontally and from the 5th pixel to the 50th vertically. |
| `DEFAULT_RECORD` | `100` | Default record value, useful for resetting its value. |

## Functions
Here a summary of the available functions and a short description for each of them.

| Function name | Input params | Return value | Description | Scope |
|:--------------|:-------------|:-------------|:------------|:------|
| [`init_GUI`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/GUI#init_GUI-) | `void` | `void` | Initialize the GUI, setting `GAME_STATUS` variable to `0`. | Public |
| [`home_GUI`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/GUI#home_GUI-) | `void` | `void` | Show home screen. Used in [`build_GUI`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/GUI#build_GUI-) function. | Private |
| [`game_GUI`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/GUI#game_GUI-) | `void` | `void` | Show game screen. Used in [`build_GUI`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/GUI#build_GUI-) function. | Private |
| [`pause_GUI`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/GUI#pause_GUI-) | `void` | `void` | Show pause screen. Used in [`build_GUI`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/GUI#build_GUI-) function. | Private |
| [`game_over_GUI`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/GUI#game_over_GUI-) | `void` | `void` | Show game over screen. Used in [`build_GUI`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/GUI#build_GUI-) function. | Private |
| [`build_GUI`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/GUI#build_GUI-) | `const int status` | `void` | In according to the status variable passed to the function, show specific screen. | Public |
| [`update_record`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/GUI#update_record-) | `void` | `void` | Update record value with the current score value. | Private |
| [`update_score`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/GUI#update_score-) | `void` | `void` | Update score value, in according to requests provoided by the assignment. | Public |
| [`reset_score`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/GUI#reset_score-) | `void` | `void` | Reset score value, setting it to `0`. | Public |
| [`reset_record`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/GUI#reset_record-) | `void` | `void` | Reset record value, setting it to `DEFAULT_RECORD` value. | Public |
| [`hideGUI`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/GUI#hideGUI-) | `const int GUI_element` | `void` | In according to `GUI_element` variable passed to the function, hide a GUI element from game screen. Used in [`checkForGUI`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/GUI#checkForGUI-) function. | Private |
| [`showGUI`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/GUI#showGUI-) | `const int GUI_element` | `void` | In according to `GUI_element` variable passed to the function, show a GUI element on game screen. Used in [`checkForGUI`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/GUI#checkForGUI-) function. | Private |
| [`checkForGUI`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/GUI#checkForGUI-) | `const uint16_t ballX0, const uint16_t ballX1, const uint16_t ballY` | `void` | In according to the ball position on the screen, check if a GUI element has to be hidden from game screen. | Public |

</br>

#### `init_GUI` ![Function scope](https://img.shields.io/badge/Scope-Public-brightgreen)
```c
void init_GUI(void)
```
##### Description
It initializes the GUI, setting `GAME_STATUS` variable to `0`.

</br>

#### `home_GUI` ![Function scope](https://img.shields.io/badge/Scope-Private-orange)
```c
void home_GUI(void)
```
##### Description
It shows home screen. Used in [`build_GUI`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/GUI#build_GUI-) function. It shows some information and how to start playing.

</br>

#### `game_GUI` ![Function scope](https://img.shields.io/badge/Scope-Private-orange)
```c
void game_GUI(void)
```
##### Description
It shows game screen. Used in [`build_GUI`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/GUI#build_GUI-) function. It draws borders (red walls) and it shows record score value and current score value.

</br>

#### `pause_GUI` ![Function scope](https://img.shields.io/badge/Scope-Private-orange)
```c
void pause_GUI(void)
```
##### Description
It shows pause screen. Used in [`build_GUI`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/GUI#build_GUI-) function. It shows record score value, current score value and how to restart or reset the game.

</br>

#### `game_over_GUI` ![Function scope](https://img.shields.io/badge/Scope-Private-orange)
```c
void game_over_GUI(void)
```
##### Description
It shows game over screen. Used in [`build_GUI`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/GUI#build_GUI-) function. It shows record score value, score achieved and how to reset the game.

</br>

#### `build_GUI` ![Function scope](https://img.shields.io/badge/Scope-Public-brightgreen)
```c
void build_GUI(const int status)
```
##### Input parameters
- `const int status`: status of the game. It takes values from `0` to `3` and they represent Home, Game, Pause, Game Over screens respectively.
##### Description
In according to the status variable passed to the function, it shows a specific screen.

</br>

#### `update_record` ![Function scope](https://img.shields.io/badge/Scope-Private-orange)
```c
void update_record(void)
```
##### Description
It updates record value with the current score value and then it shows it.

</br>

#### `update_score` ![Function scope](https://img.shields.io/badge/Scope-Public-brightgreen)
```c
void update_score(void)
```
##### Description
It updates score value, in according to requests provoided by the assignment, and then it shows it. In particular, if the current score value is less than `100`, then it is incremented by `5` points, else if it is equal or greater than `100`, the current score value is incremented by `10` points. 

</br>

#### `reset_score` ![Function scope](https://img.shields.io/badge/Scope-Public-brightgreen)
```c
void reset_score(void)
```
##### Description
It resets score value, setting it to `0`.

</br>

#### `reset_record` ![Function scope](https://img.shields.io/badge/Scope-Public-brightgreen)
```c
void reset_record(void)
```
##### Description
It resets record value, setting it to `DEFAULT_RECORD` value.

</br>

#### `hideGUI` ![Function scope](https://img.shields.io/badge/Scope-Private-orange)
```c
void hideGUI(const int GUI_element)
```
##### Input parameters
- `const int GUI_element`: code that represents the GUI element that needs to be hidden. It takes values from 1 to 3 and they represent current score value, record value and `" Record: "` text respectively.
##### Description
In according to `GUI_element` variable passed to the function, it hides a GUI element from game screen. Used in [`checkForGUI`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/GUI#checkForGUI-) function.

</br>

#### `showGUI` ![Function scope](https://img.shields.io/badge/Scope-Private-orange)
```c
void showGUI(const int GUI_element)
```
##### Input parameters
- `const int GUI_element`: code that represents the GUI element that needs to be hidden. It takes values from 1 to 3 and they represent current score value, record value and `" Record: "` text respectively.
##### Description
In according to `GUI_element` variable passed to the function, it shows a GUI element on game screen. Used in [`checkForGUI`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/GUI#checkForGUI-) function.

</br>

#### `checkForGUI` ![Function scope](https://img.shields.io/badge/Scope-Public-brightgreen)
```c
void checkForGUI(const uint16_t ballX0, const uint16_t ballX1, const uint16_t ballY)
```
##### Input parameters
- `const uint16_t ballX0`: start position of the ball on x direction
- `const uint16_t ballX1`: end position of the ball on x direction
- `const uint16_t ballY`: position of the upper side of the ball on y direction
##### Description
In according to the ball position on the screen, check if a GUI element has to be hidden from game screen. It is needed to avoid overlapping between visualization of GUI elements and the ball.
