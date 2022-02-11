# RIT - Repetitive Interrupt Timer
This library has been created to manage the RIT hardware component. Only the interrupt request handler has been changed to support button bouncing and the functionality performed by buttons.

## Table of Contents
1. [Functions](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/RIT#fucntions)
   - [`lib_RIT.c`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/RIT#lib_RITc)
   - [`IRQ_RIT.c`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/RIT#IRQ_RITc)

## Functions
This section is divided according to the distribution of functions within `lib_RIT.c` and `IRQ_RIT.c` files. In particular, whitin the first file there are functions capable of managing the hardware component itself, unlike the second one, where only the interrupt request handler is present.

### `lib_RIT.c`
Here a summary of the available functions in `lib_RIT.c` file to manage the hardware component and a short description for each of them.

| Function name | Input params | Return value | Description | Scope |
|:--------------|:-------------|:-------------|:------------|:------|
| [`init_RIT`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/RIT#init_RIT-) | `uint32_t RITInterval` | `uint32_t` | Inizialize the RIT component to count as much as specified. | Public |
| [`enable_RIT`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/RIT#enable_RIT-) | `void` | `void` | Allow the RIT component to count and to throw interrupts at each interval. | Public |
| [`disable_RIT`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/RIT#disable_RIT-) | `void` | `void` | Stop the RIT component from counting and throwing interrupts. It doesn't reset the current RIT count. | Public |
| [`reset_RIT`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/RIT#reset_RIT-) | `void` | `void` | Reset the current RIT count. | Public |

</br>

#### `init_RIT` ![Function scope](https://img.shields.io/badge/Scope-Public-brightgreen)
```c
uint32_t init_RIT (uint32_t RITInterval)
```
##### Input parameters
- `uint32_t RITInterval`: interval value that the RIT has to count to throw interrupts.
##### Return value
It returns the value `0`.
##### Description
It Inizializes the RIT component to count as much as specified by `RITInterval` variable. To calculate the value of the interval it is necessary to keep in mind that there is a clock cycle of 100MHz for the RIT, therefore the value of the interval K is given by:

_K = time_in_seconds * (25 * 10^6)Hz_

</br>

#### `enable_RIT` ![Function scope](https://img.shields.io/badge/Scope-Public-brightgreen)

```c
void enable_RIT(void)
```
##### Description
It allows the RIT component to count and to throw interrupts at each interval.

</br>

#### `disable_RIT` ![Function scope](https://img.shields.io/badge/Scope-Public-brightgreen)

```c
void disable_RIT(void)
```
##### Description
It stops the RIT component from counting and throwing interrupts. It doesn't reset the current RIT count.

</br>

#### `reset_RIT` ![Function scope](https://img.shields.io/badge/Scope-Public-brightgreen)

```c
void reset_RIT(void)
```
##### Description
It resets the current RIT count.

</br>

### `IRQ_RIT.c`
In `IRQ_RIT.c` file there is the RIT interrupt request handler (IRQ). It's used to implement buttons debouncing and their functionality.

#### RIT_IRQHandler ![Function scope](https://img.shields.io/badge/Scope-Public-brightgreen)
```c
void RIT_IRQHandler(void)
```

In particular, there are some extern variables, i.e. `extern int check_adc` and `extern int GAME_STATUS`. The second one is used to check current game status (Home, Game, Pause and Game Over) and to control effects of interactions with buttons. In addition, `int down_INT0`, `int down_KEY1` and `int down_KEY2` variables are used to check if buttons are pressed or released and to avoid buttons bouncing effects.

When _KEY1_ button is pressed, if the game has not been started yet and the software shows home screen to the user, then the software builds game screen to start playing and it enables all the needed components, such as _timers_, their interrupts and the _analog-to-digital converter_. The game status changes to store this event and to know that user is playing.

When _KEY2_ button is pressed during the game, it is paused. When the game is paused, if _KEY2_ is pressed, the game is resumed. These events are stored by the game status variable.

When the game is over, pressing _INT0_ button the game is resetted and return to home screen, ready to start a new game. In this case the record value is maintained. If _INT0_ is pressed when the game is not over, e.g. when the game is paused, then it causes the reset of the game, including record value.
