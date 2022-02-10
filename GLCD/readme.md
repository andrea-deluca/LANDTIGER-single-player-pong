# GLCD - Graphical Liquid Crystal Display
This library has been created by AVRman, how is reported whitin the files, and it provides functions to manage LCD hardware component. All files have not been modified, but here you can find a brief description for implemented functionalities.

## Table of Contents
1. [AsciiLib and HzLib](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/GLCD#AsciiLib-and-HzLib)
2. [GLCD](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/GLCD#GLCD)
   - [Costants](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/GLCD#costants)
   - [Functions](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/GLCD#functions)

## AsciiLib and HzLib
They implement the conversion of characters into ASCII and GBK (for Simplified Chinese characters) code.

## GLCD
This is the effective library that manage LCD and content visualization on it.

### Costants
Private defines in [`GLCD.h`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/blob/main/GLCD/GLCD.h) set up all values for PINs, display orientation, width and height in pixels and colors.
In [`GLCD.c`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/blob/main/GLCD/GLCD.c) file there are also constants defines of supported display models.

### Functions
Here a summary of the available functions and a short description for each of them.

| Function name | Input params | Return value | Description | Scope |
|:--------------|:-------------|:--------|:-----------------|:------|
| [`LCD_Configuration`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/GLCD#LCD_Configuration-) | `void` | `void` | Configure the LCD Control pins. | Private
| [`LCD_Send`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/GLCD#LCD_Send-) | `uint16_t byte` | `void` | LCD write data. | Private
| [`wait_delay`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/GLCD#wait_delay-) | `int count` | `void` | Delay time. | Private
| [`LCD_Read`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/GLCD#LCD_Read-) | `void` | `uint16_t` | LCD read data. | Private
| [`LCD_WriteIndex`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/GLCD#LCD_WriteIndex-) | `uint16_t index` | `void` | LCD write register address. | Private
| [`LCD_WriteData`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/GLCD#LCD_WriteData-) | `uint16_t data` | `void` | LCD write register data. | Private
| [`LCD_ReadData`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/GLCD#LCD_ReadData-) | `void` | `uint16_t` | Read controller data. | Private
| [`LCD_WriteReg`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/GLCD#LCD_WriteReg-) | `uint16_t LCD_Reg, uint16_t LCD_RegValue` | `void` | Writes to the selected LCD register. | Private
| [`LCD_ReadReg`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/GLCD#LCD_ReadReg-) | `uint16_t LCD_Reg` | `uint16_t` | Reads to the selected LCD register. | Private
| [`LCD_SetCursor`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/GLCD#LCD_SetCursor-) | `uint16_t Xpos, uint16_t Ypos` | `void` | Set the cursor position. | Private
| [`LCD_Delay`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/GLCD#LCD_Delay-) | `uint16_t ms` | `void` | Delay time. | Private
| [`LCD_Initialization`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/GLCD#LCD_Initialization-) | `void` | `void` | Initialize TFT Controller. | Public
| [`LCD_Clear`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/GLCD#LCD_Clear-) | `uint16_t color` | `void` | Fill the screen with the specified color. | Public
| [`LCD_BGR2RGB`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/GLCD#LCD_BGR2RGB-) | `uint16_t color` | `uint16_t` | Convert color code format. | Private
| [`LCD_GetPoint`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/GLCD#LCD_GetPoint-) | `uint16_t Xpos, uint16_t Ypos` | `uint16_t` | Get the color value of the specified coordinates. | Public
| [`LCD_SetPoint`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/GLCD#LCD_SetPoint-) | `uint16_t Xpos, uint16_t Ypos, uint16_t point` | `void` | Draw a point at the specified coordinates. | Public
| [`LCD_DrawLine`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/GLCD#LCD_DrawLine-) | `uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t color` | `void` | Bresenham's line algorithm. | Public
| [`LCD_PutChar`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/GLCD#LCD_PutChar-) | `uint16_t Xpos, uint16_t Ypos, uint8_t ASCII, uint16_t charColor, uint16_t bkColor` | `void` | Display a character anywhere on the LCD screen. | Public
| [`GUI_Text`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/GLCD#GUI_Text-) | `uint16_t Xpos, uint16_t Ypos, uint8_t *str, uint16_t color, uint16_t bkColor` | `void` | Display the string at the specified coordinates. | Public

</br>

#### `LCD_Configuration` ![Function scope](https://img.shields.io/badge/Scope-Private-orange)
```c
static void LCD_Configuration(void)
```
##### Description
It configures the LCD Control pins.

</br>

#### `LCD_Send` ![Function scope](https://img.shields.io/badge/Scope-Private-orange)
```c
static __attribute__((always_inline)) void LCD_Send (uint16_t byte)
```
##### Input parameters
- `uint16_t byte`: byte to be sent
##### Description
LCD write data.

</br>

#### `wait_delay` ![Function scope](https://img.shields.io/badge/Scope-Private-orange)
```c
static void wait_delay(int count)
```
##### Input parameters
- `int count`: delay time
##### Description
It adds delay time.

</br>

#### `LCD_Read` ![Function scope](https://img.shields.io/badge/Scope-Private-orange)
```c
static __attribute__((always_inline)) uint16_t LCD_Read (void) 
```
##### Return value
Return the read data.
##### Description
LCD read data.

</br>

#### `LCD_WriteIndex` ![Function scope](https://img.shields.io/badge/Scope-Private-orange)
```c
static __attribute__((always_inline)) void LCD_WriteIndex(uint16_t index)
```
##### Input parameters
- `uint16_t index`: register address
##### Description
LCD write register address.

</br>

#### `LCD_WriteData` ![Function scope](https://img.shields.io/badge/Scope-Private-orange)
```c
static __attribute__((always_inline)) void LCD_WriteData(uint16_t data)
```
##### Input parameters
- `uint16_t data`: register data
##### Description
LCD write register data.

</br>

#### `LCD_ReadData` ![Function scope](https://img.shields.io/badge/Scope-Private-orange)
```c
static __attribute__((always_inline)) uint16_t LCD_ReadData(void)
```
##### Return value
Return the read data.
##### Description
It reads controller data.

</br>

#### `LCD_WriteReg` ![Function scope](https://img.shields.io/badge/Scope-Private-orange)
```c
static __attribute__((always_inline)) void LCD_WriteReg(uint16_t LCD_Reg, uint16_t LCD_RegValue)
```
##### Input parameters
- `uint16_t LCD_Reg`: address of the selected register
- `uint16_t LCD_RegValue`: value to write to the selected register
##### Description
It writes to the selected LCD register.

</br>

#### `LCD_ReadReg` ![Function scope](https://img.shields.io/badge/Scope-Private-orange)
```c
static __attribute__((always_inline)) uint16_t LCD_ReadReg(uint16_t LCD_Reg)
```
##### Input parameters
- `uint16_t LCD_Reg`: address of the selected register
##### Return value
Return the LCD register value.
##### Description
It reads from the selected LCD register.

</br>

#### `LCD_SetCursor` ![Function scope](https://img.shields.io/badge/Scope-Private-orange)
```c
static void LCD_SetCursor(uint16_t Xpos, uint16_t Ypos)
```
##### Input parameters
- `uint16_t Xpos`: specifies the X position
- `uint16_t Ypos`: specifies the Y position
##### Description
It sets the cursor position.

</br>

#### `LCD_Delay` ![Function scope](https://img.shields.io/badge/Scope-Private-orange)
```c
static void delay_ms(uint16_t ms)
```
##### Input parameters
- `uint16_t ms`: delay time
##### Description
It adds delay time.

</br>

#### `LCD_Initialization` ![Function scope](https://img.shields.io/badge/Scope-Public-brightgreen)
```c
void LCD_Initialization(void)
```
##### Description
This function initializes TFT (Thin Film Transistor) Controller.

</br>

#### `LCD_Clear` ![Function scope](https://img.shields.io/badge/Scope-Public-brightgreen)
```c
void LCD_Clear(uint16_t Color)
```
##### Input parameters
- `uint16_t color`: screen color
##### Description
This function provides to fill the screen with the specified color.

</br>

#### `LCD_BGR2RGB` ![Function scope](https://img.shields.io/badge/Scope-Private-orange)
```c
static uint16_t LCD_BGR2RGB(uint16_t color)
```
##### Input parameters
- `uint16_t color`: BRG color value
##### Return value
Return the RGB color value.
##### Description
It converts color code format from BRG to RGB.

</br>

#### `LCD_GetPoint` ![Function scope](https://img.shields.io/badge/Scope-Public-brightgreen)
```c
uint16_t LCD_GetPoint(uint16_t Xpos, uint16_t Ypos)
```
##### Input parameters
- `uint16_t Xpos`: row coordinate
- `uint16_t Ypos`: line coordinate
##### Return value
Return the screen color.
##### Description
It get the color value of the specified coordinates.

</br>

#### `LCD_SetPoint` ![Function scope](https://img.shields.io/badge/Scope-Public-brightgreen)
```c
void LCD_SetPoint(uint16_t Xpos, uint16_t Ypos, uint16_t point)
```
##### Input parameters
- `uint16_t Xpos`: row coordinate
- `uint16_t Ypos`: line coordinate
- `uint16_t point`: value to write to the 0x0022 register
##### Description
It draws a point at the specified coordinates.

</br>

#### `LCD_DrawLine` ![Function scope](https://img.shields.io/badge/Scope-Public-brightgreen)
```c
void LCD_DrawLine(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1 , uint16_t color)
```
##### Input parameters
- `uint16_t x0`: row coordinate of point A
- `uint16_t y0`: column coordinate of point A
- `uint16_t x1`: row coordinate of point B
- `uint16_t y1`: column coordinate of point B
- `uint16_t color`: line color
##### Description
This function implements Bresenham's line algorithm to draw a line.

</br>

#### `LCD_PutChar` ![Function scope](https://img.shields.io/badge/Scope-Public-brightgreen)
```c
void PutChar(uint16_t Xpos, uint16_t Ypos, uint8_t ASCI, uint16_t charColor, uint16_t bkColor)
```
##### Input parameters
- `uint16_t Xpos`: horizontal coordinate
- `uint16_t Ypos`: vertical coordinate
- `uint16_t ASCII`: character to display
- `uint16_t charColor`: character color
- `uint16_t bkColor`: background color
##### Description
It displays a character anywhere on the LCD screen.

</br>

#### `GUI_Text` ![Function scope](https://img.shields.io/badge/Scope-Public-brightgreen)
```c
void GUI_Text(uint16_t Xpos, uint16_t Ypos, uint8_t *str,uint16_t Color, uint16_t bkColor)
```
##### Input parameters
- `uint16_t Xpos`: horizontal coordinate
- `uint16_t Ypos`: vertical coordinate
- `uint16_t str`: string to display
- `uint16_t color`: string color
- `uint16_t bkColor`: background color
##### Description
It displays the string at the specified coordinates.
