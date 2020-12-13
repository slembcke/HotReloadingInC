#include <stdlib.h>
#include <ncurses.h>

static const int number = 7;

int main(void){
	initscr();
	
	printw("Welcome to the worst guessing game ever!\n");
	while(true){
		printw("Guess my number (0-9): ");
		refresh();
		
		int c = getch(); printw("\n");
		unsigned n = c - '0';
		
		if(n == number){
			printw("You guessed the number!\n");
			printw("Please change the hardcoded number in the code and recompile to play again!\n");
			printw("Press almost any key to quit!\n");
			
			getch();
			break;
		} else if(n <= 9){
			const char* hi_lo = (n < number ? "too low" : "too high");
			printw("You guessed the number %d, which is %s.\n", n, hi_lo);
		} else {
			printw("That was not a number. Please concentrate this time.\n");
		}
	}
	
	endwin();
	return EXIT_SUCCESS;
}
