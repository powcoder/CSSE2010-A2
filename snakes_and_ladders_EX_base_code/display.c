https://powcoder.com
代写代考加微信 powcoder
Assignment Project Exam Help
Add WeChat powcoder
https://powcoder.com
代写代考加微信 powcoder
Assignment Project Exam Help
Add WeChat powcoder
/*
 * display.c
 *
 * Authors: Luke Kamols, Jarrod Bennett
 */ 

#include "display.h"
#include <stdio.h>
#include <avr/pgmspace.h>
#include "terminalio.h"
#include "game.h"

void initialise_display(void) {
	// first turn off the cursor
	hide_cursor();

	// next build an empty board
	set_display_attribute(FG_YELLOW);
	for (uint8_t row = 0; row < HEIGHT; row++) {
		move_terminal_cursor(TERMINAL_BOARD_X, TERMINAL_BOARD_Y+2*row);
		printf_P(PSTR("+--+--+--+--+--+--+--+--+"));
		move_terminal_cursor(TERMINAL_BOARD_X, TERMINAL_BOARD_Y+2*row+1);
		printf_P(PSTR("|  |  |  |  |  |  |  |  |"));
	}
	move_terminal_cursor(TERMINAL_BOARD_X, TERMINAL_BOARD_Y+2*HEIGHT);
	printf_P(PSTR("+--+--+--+--+--+--+--+--+"));

	// clear the colour settings so we don't print other things in yellow
	normal_display_mode();
}

void start_display(void) {
	move_terminal_cursor(TERMINAL_BOARD_X, TERMINAL_BOARD_Y);
	set_display_attribute(FG_GREEN);
	printf_P(PSTR("SNAKES AND LADDERS"));
}

// Update the square colour to the display. The object passed can be the object
// type or an object instance (which additionally has an ID number if
// applicable -see get_object_type in game.c/h)
void update_square_colour(uint8_t x, uint8_t y, uint8_t object) {
	// determine which colour corresponds to this object
	DisplayParameter backgroundColour;
	object = get_object_type(object);

	switch (object) {
		case EMPTY_SQUARE:
			backgroundColour = TERMINAL_COLOUR_EMPTY;
			break;
		case START_POINT:	/* FALLTHROUGH */
		case FINISH_LINE:
			backgroundColour = TERMINAL_COLOUR_START_END;
			break;
		case PLAYER_1:
			backgroundColour = TERMINAL_COLOUR_P1;
			break;
	
		// All snakes should be the same colour
		case SNAKE_START:	/* FALLTHROUGH */
		case SNAKE_END:		/* FALLTHROUGH */
		case SNAKE_MIDDLE:
			backgroundColour = TERMINAL_COLOUR_SNAKE;
			break;
	
		// All ladders should be the same colour
		case LADDER_START:	/* FALLTHROUGH */
		case LADDER_END:	/* FALLTHROUGH */
		case LADDER_MIDDLE:
			backgroundColour = TERMINAL_COLOUR_LADDER;
			break;
	
		// An invalid object
		default:
			backgroundColour = TERMINAL_COLOUR_EMPTY;
			break;
	}

	// set the background colour to be the determined colour
	// when we enter a space this will appear as a solid block
	set_display_attribute(backgroundColour);

	// update the square at the given location
	// note that two spaces form roughly a square so that is used instead of one space
	// also note that the terminal y values count from the top
	// but our referencing counts from the bottom, so the y position is inverted
	move_terminal_cursor(TERMINAL_BOARD_X + 1 + 3 * x,
	TERMINAL_BOARD_Y + 1 + 2 * (HEIGHT - y - 1));
	printf_P(PSTR("  ")); // print two spaces, since we set the background colour

	normal_display_mode(); // remove the display attribute
}