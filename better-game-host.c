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
		while(system("make better-game-module.so") != 0){
			fprintf(stderr, "Whoops! Failed to compile!\n");
			fprintf(stderr, "Press return to try again.\n");
			getchar();
		}
		
		void* module;
		if((module = dlopen("./better-game-module.so", RTLD_NOW)) == NULL){
			fprintf(stderr, "Failed to load module. (%s)\n", dlerror());
			fprintf(stderr, "Press return to try again.\n");
			getchar();
			continue;
		}
		
		module_func* module_main = dlsym(module, "module_main");
		
		initscr();
		clear();
		state = module_main(state);
		endwin();
		
		dlclose(module);
		
		if(state == NULL) return EXIT_SUCCESS;
	}
}
