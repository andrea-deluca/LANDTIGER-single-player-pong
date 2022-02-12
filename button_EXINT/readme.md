# Button EXINT - Button External Interrupt
This library has been created to manage external interrupts produced by the interaction with buttons. All files have not been modified, but here you can find a brief description for implemented functionality.

## Table of Contents
1. [Functions](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/button_EXINT#functions)
   - [`lib_button.c`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/button_EXINT#lib_buttonc)
   - [`IRQ_button.c`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/button_EXINT#IRQ_buttonc)

## Functions
This section is divided according to the distribution of functions within `lib_button.c` and `IRQ_button.c` files. In particular, whitin the first file there is a function capable of managing the hardware component itself, unlike the second one, where only the interrupt request handlers are present.

### `lib_button.c`
Here a brief description of the only one function present in this file.

#### `BUTTON_init`
```c
void BUTTON_init(void)
```
##### Description
It initializes buttons hardware components so that they are able to throw interrupts when they are pressed by the user.

### `IRQ_button.c`
There are three external variables, i.e. `extern int down_INT0`, `extern int down_KEY1` and `extern int down_KEY2`, that represent when a button is pressed and they are used inside the related functions.

Here a summary of available functions in `IRQ_button.c` file to manage external interrupt requestes and a short description for each of them.

| Function name | Input params | Return value | Decsription | Scope |
|:--------------|:-------------|:-------------|:------------|:------|
| [`EINT0_IRQHandler`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/button_EXINT#EINT0_IRQHandler) | `void` | `void` | Manage external interrupt procuded when _INT0_ button is pressed. | Public |
| [`EINT1_IRQHandler`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/button_EXINT#EINT1_IRQHandler) | `void` | `void` | Manage external interrupt procuded when _KEY1_ button is pressed. | Public |
| [`EINT2_IRQHandler`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/button_EXINT#EINT2_IRQHandler) | `void` | `void` | Manage external interrupt procuded when _KEY2_ button is pressed. | Public |

</br>

#### `EINT0_IRQHandler`
```c
void EINT0_IRQHandler(void)
```
##### Description
It manages external interrupt procuded when _INT0_ button is pressed. Here button interrupts are disabled and `extern int down_INT0` is incremented by `1` to store information about pressing the button. The button interrupts are enabled again and the variable return to `0` when button is released, inside `RIT_IRQHandler` function.

</br>

#### `EINT1_IRQHandler`
```c
void EINT1_IRQHandler(void)
```
##### Description
It manages external interrupt procuded when _KEY1_ button is pressed. Here button interrupts are disabled and `extern int down_KEY1` is incremented by `1` to store information about pressing the button. The button interrupts are enabled again and the variable return to `0` when button is released, inside `RIT_IRQHandler` function.

</br>

#### `EINT2_IRQHandler`
```c
void EINT2_IRQHandler(void)
```
##### Description
It manages external interrupt procuded when _KEY2_ button is pressed. Here button interrupts are disabled and `extern int down_KEY2` is incremented by `1` to store information about pressing the button. The button interrupts are enabled again and the variable return to `0` when button is released, inside `RIT_IRQHandler` function.
