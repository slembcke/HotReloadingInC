#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include <ncurses.h>
#include <dlfcn.h>

#include "better-game.h"


int main(void){
	void* state = NULL;
	
	while(true){
		// Optional: recompile the game's code.
		while(system("make better-game-module.so") != 0){
			fprintf(stderr, "Whoops! Failed to compile!\n");
			fprintf(stderr, "Press return to try again.\n");
			getchar();
		}
		
		// Load the game's library and check for errors.
		void* module = dlopen("./better-game-module.so", RTLD_NOW);
		if(module == NULL){
			fprintf(stderr, "Failed to load library. (%s)\n", dlerror());
			fprintf(stderr, "Press return to try again.\n");
			getchar();
			
			// Jump back to the beginning of the loop to recompile.
			continue;
		}
		
		initscr();
		clear();
		
		module_func* module_main = dlsym(module, "module_main");
		state = module_main(state);
		
		endwin();
		dlclose(module);
		
		if(state == NULL) return EXIT_SUCCESS;
	}
}
