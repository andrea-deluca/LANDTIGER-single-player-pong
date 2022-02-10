# GLCD - Graphical Liquid Crystal Display
This library has been created by AVRman, how is reported whitin the files, and it provides functions to manage LCD hardware component. All files have not been modified, but here you can find a brief description for implemented functionalities.

## Table of Contents

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
| [`LCD_Configuration`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/GLCD#LCD_Configuration) | `void` | `void` | Configure the LCD Control pins. | Private
| [`LCD_Send`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/GLCD#LCD_Configuration) | `uint16_t byte` | `void` | LCD write data. | Private
| [`wait_delay`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/GLCD#LCD_Configuration) | `int count` | `void` | Delay time. | Private
| [`LCD_Read`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/GLCD#LCD_Configuration) | `void` | `uint16_t` | LCD read data. | Private
| [`LCD_WriteIndex`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/GLCD#LCD_Configuration) | `uint16_t index` | `void` | LCD write register address. | Private
| [`LCD_WriteData`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/GLCD#LCD_Configuration) | `uint16_t data` | `void` | LCD write register data. | Private
| [`LCD_ReadData`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/GLCD#LCD_Configuration) | `void` | `uint16_t` | Read controller data. | Private
| [`LCD_WriteReg`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/GLCD#LCD_Configuration) | `uint16_t LCD_Reg, uint16_t LCD_RegValue` | `void` | Writes to the selected LCD register. | Private
| [`LCD_ReadReg`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/GLCD#LCD_Configuration) | `uint16_t LCD_Reg` | `uint16_t` | Reads to the selected LCD register. | Private
| [`LCD_SetCursor`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/GLCD#LCD_Configuration) | `uint16_t Xpos, uint16_t Ypos` | `void` | Set the cursor position. | Private
| [`LCD_Delay`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/GLCD#LCD_Configuration) | `uint16_t ms` | `void` | Delay time. | Private
| [`LCD_Initialization`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/GLCD#LCD_Configuration) | `void` | `void` | Initialize TFT Controller. | Public
| [`LCD_Clear`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/GLCD#LCD_Configuration) | `uint16_t color` | `void` | Fill the screen with the specified color. | Public
| [`LCD_BGR2RGB`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/GLCD#LCD_Configuration) | `uint16_t color` | `uint16_t` | Convert color code format. | Private
| [`LCD_GetPoint`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/GLCD#LCD_Configuration) | `uint16_t Xpos, uint16_t Ypos` | `uint16_t` | Get the color value of the specified coordinates. | Public
| [`LCD_SetPoint`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/GLCD#LCD_Configuration) | `uint16_t Xpos, uint16_t Ypos, uint16_t point` | `void` | Draw a point at the specified coordinates. | Public
| [`LCD_DrawLine`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/GLCD#LCD_Configuration) | `uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t color` | `void` | Bresenham's line algorithm. | Public
| [`LCD_PutChar`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/GLCD#LCD_Configuration) | `uint16_t Xpos, uint16_t Ypos, uint8_t ASCII, uint16_t charColor, uint16_t bkColor` | `void` | Display a character anywhere on the LCD screen. | Public
| [`GUI_Text`](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/GLCD#LCD_Configuration) | `uint16_t Xpos, uint16_t Ypos, uint8_t *str, uint16_t color, uint16_t bkColor` | `void` | Display the string at the specified coordinates. | Public

#### `LCD_Configuration`
```c
static void LCD_Configuration(void)
```
##### Description
It configures the LCD Control pins.
