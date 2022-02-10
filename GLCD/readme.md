# GLCD - Graphical Liquid Crystal Display
This library has been created by AVRman, how is reported whitin the files, and it provides functions to manage LCD hardware component. All files have not been modified, but here you can find a brief description for implemented functionalities.

## Table of Contents

## AsciiLib and HzLib
They implement the conversion of characters into ASCII and GBK (for Simplified Chinese characters) code.

## GLCD
This is the effective library that manage LCD and content visualization on it.

### Costants
Private defines in [```GLCD.h```](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/blob/main/GLCD/GLCD.h) set up all values for PINs, display orientation, width and height in pixels and colors.
In [```GLCD.c```](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/blob/main/GLCD/GLCD.c) file there are also constants defines of supported display models.

### Functions
Here a summary of the available functions and a short description for each of them.

| Function name | Input params | Return value | Description |
|:--------------|:-------------|:--------|:-------------|
| [```LCD_Configuration```](https://github.com/andrea-deluca/LANDTIGER-single-player-pong/tree/main/GLCD#LCD_Configuration) | ```void``` | ```void``` | It configures the LCD Control pins. |

#### ```LCD_Configuration```
```c
static void LCD_Configuration(void)
```
##### Description
It configures the LCD Control pins.
