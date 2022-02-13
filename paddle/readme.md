# Paddle
This library has been created by Andrea Deluca to manage the movement of the paddle. All files have been written from scratch for the purpose.

## Table of Contents
1. [Constants](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/paddle#constants)
2. [Functions](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/paddle#functions)

## Constants
In `paddle.h` file you can find all the private defines of the library. Here a summary of the defined constants and a short description for each of them.

| Name | Value | Description |
|:-----|:------|:------------|
| `PADDLE_THICK` | `10` | Thickness in pixel of the paddle. |
| `MARGIN_BOTTOM` | `32` | Margin from the bottom of the paddle in pixel. |

## Functions
Here a summary of the available functions and a short description for each of them.

| Function name | Input params | Return value | Description | Scope | 
|:--------------|:-------------|:-------------|:------------|:------|
| [`draw_paddle`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/paddle#draw_paddle-) | `const uint16_t paddleX0, const uint16_t paddleX1` | `void` | Draw the paddle fully. | Public |
| [`move_paddle`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/paddle#move_paddle-) | `const uint16_t new_paddleX0, const uint16_t new_PaddleX1` | `void` | Move the paddle to the new position. | Public |

</br>

### `draw_paddle` ![Function scope](https://img.shields.io/badge/Scope-Public-brightgreen)
```c
void draw_paddle(const uint16_t paddleX0, const uint16_t paddleX1)
```
#### Input parameters
- `const uint16_t paddleX0`: start position of the paddle on horizontal direction.
- `const uint16_t paddleX1`: end position of the paddle on horizontal direction.
#### Description
It draws the paddle fully. It's used during the first real reading of the value given by the _potentiometer_ to be able to draw it in the right position, according to the hardware component. Then, the position of the paddle is updated.

</br>

### `draw_paddle` ![Function scope](https://img.shields.io/badge/Scope-Public-brightgreen)
```c
void move_paddle(const uint16_t new_paddleX0, const uint16_t new_PaddleX1)
```
#### Input parameters
- `const uint16_t new_paddleX0`: new start position of the paddle on horizontal direction.
- `const uint16_t new_paddleX1`: new end position of the paddle on horizontal direction.
#### Description
It moves the paddle to the new position. It computes the new position of the paddle and it's called every time the related timer throw an interrupt, so a A/D conversion, and the _potentiometer_ has been moved enough.

This action is optimized by means coloring only the new parts of the paddle and deleting only the parts needed, accordding to the new position computed and the direction of the movement of the paddle, instead of deleting the paddle fully and then drawing again the complete paddle in the new position.
