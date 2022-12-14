https://powcoder.com
代写代考加微信 powcoder
Assignment Project Exam Help
Add WeChat powcoder
https://powcoder.com
代写代考加微信 powcoder
Assignment Project Exam Help
Add WeChat powcoder
/*
 * display.h
 *
 * Authors: Luke Kamols, Jarrod Bennett
 */ 


#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <stdint.h>

// Offset for the terminal display to cater for any game border offset to the
// edge of the terminal display.
#define TERMINAL_BOARD_X 45
#define TERMINAL_BOARD_Y 5

// Terminal colour definitions
#define TERMINAL_COLOUR_EMPTY		BG_BLACK
#define TERMINAL_COLOUR_START_END	BG_YELLOW
#define TERMINAL_COLOUR_P1			BG_CYAN
#define TERMINAL_COLOUR_SNAKE		BG_RED
#define TERMINAL_COLOUR_LADDER		BG_GREEN

// Initialise the display for the board, this creates the display
// for an empty board.
void initialise_display(void);

// Shows a starting display.
void start_display(void);

// Updates the colour at square (x, y) to be the colour
// of the object 'object'.
void update_square_colour(uint8_t x, uint8_t y, uint8_t object);


#endif /* DISPLAY_H_ */