# Timer
This library has been created to manage timer hardware components. Only interrupt request handlers have been changed to support A/D conversion, the movement of the ball and sound emission from the _buzzer_, through a digital-to-analog converter (DAC), at any given interval.

## Table of Contents
1. [Functions](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/timer#functions)
   - [`lib_timer.c`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/timer#lib_timerc)
   - [`IRQ_timer.c`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/timer#IRQ_timerc)

## Functions
This section is divided according to the distribution of functions within `lib_timer.c` and `IRQ_timer.c` files. In particular, whitin the first file there are functions capable of managing hardware components, unlike the second one, where only the interrupt request handlers are present.

### `lib_timer.c`
Here a summary of the available functions in `lib_timer.c` file to manage timers and a short description for each of them.

| Function name | Input params | Return value | Description | Scope |
|:--------------|:-------------|:-------------|:------------|:------|
| [`init_timer`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/timer#init_timer-) | `uint8_t timer_num, uint32_t TimerInterval` | `uint32_t` | Initialize timer passed to the function to count as much as passed as `TimerInterval`. | Public |
| [`enable_timer`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/timer#enable_timer-) | `uint8_t timer_num` | `void` | Enable timer passed to the function to count. | Public |
| [`disable_timer`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/timer#disable_timer-) | `uint8_t timer_num` | `void` | Disable timer passed to the function to count. It doesn't reset the current timer count. | Public |
| [`reset_timer`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/timer#reset_timer-) | `uint8_t timer_num` | `void` | Reset the current count of the timer passed to the function. | Public |

</br>

#### `init_timer` ![Function scope](https://img.shields.io/badge/Scope-Public-brightgreen)
```c
uint32_t init_timer(uint8_t timer_num, uint32_t TimerInterval)
```
##### Input parameters
- `uint8_t timer_num`: number of the timer. It can be a value from 0 to 3 and it can represent Timer0, Timer1, Timer2 or Timer3.
- `uint32_t TimerInterval`: interval value that the timer has to count.
##### Return value
It returns the value `0`.
##### Description
It Initializes timer `timer_num` passed to the function to count as much as passed as `TimerInterval`. To calculate the value of the interval it is necessary to keep in mind that there is a clock cycle of 25MHz by default for timers, therefore the value of the interval K is given by:

_K = time_in_seconds * (25 * 10^6)Hz_

It's also important to keep in mind that the value of `MCR` register of the related timer sets the mode of operation of the timer itself. In particular, this register has three bit available, where they indicate, from MSB to LSB, Stop, Reset and Interrupt functionality of the timer. So, e.g. to allow timer to count and to throw interrupts cyclically, you have to set `MCR` register to `3`.

</br>

#### `enable_timer` ![Function scope](https://img.shields.io/badge/Scope-Public-brightgreen)
```c
void enable_timer(uint8_t timer_num)
```
##### Input parameters
- `uint8_t timer_num`: number of the timer. It can be a value from 0 to 3 and it can represent Timer0, Timer1, Timer2 or Timer3.
##### Description
It enables timer `timer_num` passed to the function to count.

</br>

#### `disable_timer` ![Function scope](https://img.shields.io/badge/Scope-Public-brightgreen)
```c
void disable_timer(uint8_t timer_num)
```
##### Input parameters
- `uint8_t timer_num`: number of the timer. It can be a value from 0 to 3 and it can represent Timer0, Timer1, Timer2 or Timer3.
##### Description
It disables timer `timer_num` passed to the function to count. It doesn't reset the current timer count.

</br>

#### `reset_timer` ![Function scope](https://img.shields.io/badge/Scope-Public-brightgreen)
```c
void reset_timer(uint8_t timer_num)
```
##### Input parameters
- `uint8_t timer_num`: number of the timer. It can be a value from 0 to 3 and it can represent Timer0, Timer1, Timer2 or Timer3.
##### Description
It resets the current count of the timer `timer_num` passed to the function.

</br>

### `IRQ_timer.c`
Three timers out of four are actually used for the purpose, while the last one is unused.

| Function name | Input params | Return value | Description | Scope |
|:--------------|:-------------|:-------------|:------------|:------|
| [`TIMER0_IRQHandler`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/timer#TIMER0_IRQHandler-) | `void` | `void` | Used to start A/D conversion. | Public |
| [`TIMER1_IRQHandler`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/timer#TIMER1_IRQHandler-) | `void` | `void` | Used to move the ball. | Public |
| [`TIMER2_IRQHandler`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/timer#TIMER2_IRQHandler-) | `void` | `void` | Used to manage sound emission and D/A converter. | Public |
| [`TIMER3_IRQHandler`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/timer#TIMER3_IRQHandler-) | `void` | `void` | Unused. | Public |

</br>

#### `TIMER0_IRQHandler` ![Function scope](https://img.shields.io/badge/Scope-Public-brightgreen)
```c
void TIMER0_IRQHandler(void)
```
##### Description
It's used to start A/D conversion to manage movement of the paddle related to the _potentiometer_ component. _Timer0_ is set to 2ms and it works cyclically.

</br>

#### `TIMER1_IRQHandler` ![Function scope](https://img.shields.io/badge/Scope-Public-brightgreen)
```c
void TIMER1_IRQHandler(void)
```
##### Description
It's used to manage the movement of the ball. _Timer1_ is set to 0.5ms and it works cyclically.

</br>

#### `TIMER2_IRQHandler` ![Function scope](https://img.shields.io/badge/Scope-Public-brightgreen)
```c
void TIMER2_IRQHandler(void)
```
##### Description
It's used to manage D/A conversion and emission of sound through the _buzzer_ when the ball hits the paddle or a wall. The value of interval for _Timer2_ varies according to the frequency of the note to play. This value is higher for a lower pitched note and lower for a higher pitched note. 

</br>

#### `TIMER3_IRQHandler` ![Function scope](https://img.shields.io/badge/Scope-Public-brightgreen)
```c
void TIMER3_IRQHandler(void)
```
##### Description
This is unused in this case.
