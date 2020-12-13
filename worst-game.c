#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include <ncurses.h>
#include <dlfcn.h>

typedef enum {
	MODULE_EXIT,
	MODULE_RELOAD,
} ModuleStatus;

ModuleStatus module_loop(void){
	
	return MODULE_EXIT;
}

ModuleStatus module_init(void){
	return module_loop();
}

int NUMBER = 7;

void game_loop(void){
	printw("Welcome to the worst guessing game ever!\n");
	while(true){
		printw("Guess my number (0-9): ");
		refresh();
		
		int c = getch(); printw("\n");
		unsigned n = c - '0';
		
		if(n == NUMBER){
			printw("You guessed the number!\n");
			printw("Please change the hardcoded number in the code and recompile to play again!\n");
			printw("Press almost any key to quit!\n");
			
			getch();
			return;
		} else if(n <= 9){
			const char* hi_lo = (n < NUMBER ? "too low" : "too high");
			printw("You guessed the number %d, which is %s.\n", n, hi_lo);
		} else {
			printw("That was not a number. Please concentrate this time.\n");
		}
	}
}

int main(void){
	initscr();
	
	game_loop();
	
	endwin();
	return EXIT_SUCCESS;
}
