#include <ncurses.h>

#include "better-game.h"

static const int NUMBER = 7;

ModuleStatus game_loop(void){
	printw("Welcome to a better guessing game.\n");
	while(1){
		printw("Guess my number (0-9): ");
		refresh();
		
		int c = getch(); printw("\n");
		unsigned n = c - '0';
		
		if(n == NUMBER){
			printw("You guessed the number!\n");
			printw("Please change the hardcoded number in the code and recompile to play again!\n");
			printw("Press almost any key to hot-reload!\n");
			
			getch();
			return MODULE_RELOAD;
		} else if(n <= 9){
			const char* hi_lo = (n < NUMBER ? "too low" : "too high");
			printw("You guessed the number %d, which is %s.\n", n, hi_lo);
		} else {
			printw("That was not a number. Please concentrate this time.\n");
		}
	}
	
	return MODULE_EXIT;
}

ModuleStatus module_init(void){
	return game_loop();
}
