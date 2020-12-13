#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include <ncurses.h>
// #include <dlfcn.h>

#include "module.h"

int main(void){
	initscr();
	
	extern module_func module_init;
	module_init();
	
	endwin();
	return EXIT_SUCCESS;
}
