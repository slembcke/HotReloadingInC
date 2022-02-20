#include <stdlib.h>
#include <ncurses.h>

#include "better-game.h"

static const int NUMBER = 7;

typedef struct {
	int last_number;
} GameState;

void* module_main(void* saved_state){
	GameState* game_state = saved_state;
	if(game_state == NULL){
		game_state = calloc(1, sizeof(*game_state));
		printw("Welcome to the better number guessing game.\n");
	} else {
		printw("Welcome back!\nLast time the number was %d\n", game_state->last_number);
	}
	
	while(true){
		printw("Guess my number (0-9): ");
		refresh();
		
		int c = getch(); printw("\n");
		unsigned n = c - '0';
		
		if(n == NUMBER){
			printw("You guessed the number!\n");
			printw("Please change the hardcoded number in the code\n");
			printw("... then press almost any key to hot-load!\n");
			
			getch();
			game_state->last_number = NUMBER;
			return game_state;
		} else if(n <= 9){
			const char* hi_lo = (n < NUMBER ? "too low" : "too high");
			printw("You guessed the number %d, which is %s.\n", n, hi_lo);
		} else {
			printw("That was not a number. Please concentrate this time.\n");
		}
	}
	
	return NULL;
}
