#include <stdlib.h>
#include <ncurses.h>

static const int number = 7;

int main(void){
	initscr();
	
	printw("Try and guess the forbidden number if you dare.\n");
	while(1){
		printw("Guess the number (0-9): ");
		refresh();
		
		int c = getch(); printw("\n");
		unsigned n = c - '0';
		
		if(n == number){
			printw("That number is forbidden. Enjoy your doom!\n");
			printw("Please change the hardcoded number in the code and recompile to play again.\n");
			printw("Press nearly any key to quit.\n");
			
			getch();
			return EXIT_SUCCESS;
		} else if(n <= 9){
			const char* hi_lo = (n < number ? "too low" : "too high");
			printw("You guessed the number %d, which is %s.\n", n, hi_lo);
		} else {
			printw("Is that a number? Please concentrate and try again.\n");
		}
	}
	
	return EXIT_SUCCESS;
}
