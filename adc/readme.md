# ADC - Analog-to-Digital Converter
This library has been created to manage the ADC hardware component. Only the interrupt request handler has been changed to support the creation of the paddle in the right initial position and the movement of the paddle itself.

## Table of Contents
1. [Functions](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/adc#functions)
   - [`lib_adc.c`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/adc#lib_adcc)
   - [`IRQ_adc.c`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/adc#IRQ_adcc)

## Functions
This section is divided according to the distribution of functions within `lib_adc.c` and `IRQ_adc.c` files. In particular, whitin the first file there are functions capable of managing the hardware component itself, unlike the second one, where only the interrupt request handler is present.

### `lib_adc.c`
Here a summary of the available functions in `lib_adc.c` file to manage the hardware component and a short description for each of them.

| Function name | Input params | Return value | Description | Scope |
|:--------------|:-------------|:-------------|:------------|:------|
| [`ADC_init`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/adc#ADC_init-) | `void` | `void` | Initialize the ADC hardware component. | Public |
| [`ADC_start_conversion`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/adc#ADC_start_conversion-) | `void` | `void` | Start A/D conversion. | Public |

</br>

#### `ADC_init` ![Function scope](https://img.shields.io/badge/Scope-Public-brightgreen)
```c
void ADC_init(void)
```
##### Description
It Initializes the ADC hardware component and it enables ADC interrupt.

</br>

#### `ADC_start_conversion` ![Function scope](https://img.shields.io/badge/Scope-Public-brightgreen)
```c
void ADC_start_conversion(void)
```
##### Description
It starts A/D convertion and it throws an ADC interrupt request.

</br>

### `IRQ_adc.c`
In `IRQ_adc.c` file there is the ADC interrupt request handler (IRQ). It's used to implement the creation of the paddle, the first time, and the movement of the paddle then.

There are two extern variables, i.e. `extern uint16_t PADDLE_X0` and `extern uint16_t PADDLE_X1`, that represent start and end positions of the paddle along horizontal direction. In addition, `unsigned short AD_current` variable is the current value read by the ADC component. Furthermore, `int check_adc` variable gives information on whether the conversion is the first one or not.

#### `ADC_IRQHandler` ![Function scope](https://img.shields.io/badge/Scope-Public-brightgreen)
```c
void ADC_IRQHandler(void)
```
##### Description
The new start position of the paddle along the horizontal direction is computed according to the current value read by the A/D conversion. If the current conversion is the first one, then the `check_adc` variable is incremented by `1`, adding some delay. It's needed because, when the game starts, the ADC component read always `0` during the first conversion, so it's not ready yet.

When `check_adc` variable assumes value `1`, ADC component is ready to draw paddle for the first time. The paddle is drawn in the corrent position, according to the _potentiometer_ position. Now, `check_adc` is incrementd by `1`. 

Then, when `check_adc` is equal to `2`, the ADC interrupt manages the movement of the paddle on the horizontal direction, based on the new position taken by the _potentiometer_. To avoid _potentiometer_ bouncing effect and its not-ideality behavior, some constraints are added to motion conditions.
