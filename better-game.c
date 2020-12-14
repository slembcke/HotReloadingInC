#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include <ncurses.h>
#include <dlfcn.h>

#include "better-game.h"


int main(void){
	while(1){
		while(system("make better-game-module.so") != 0){
			fprintf(stderr, "Whoops! Failed to compile!\n");
			fprintf(stderr, "Press return to try again.\n");
			getchar();
		}
		
		void* module;
		while((module = dlopen("./better-game-module.so", RTLD_NOW)) == NULL){
			fprintf(stderr, "Failed to load module. (%s)\n", dlerror());
			fprintf(stderr, "Press return to try again.\n");
			getchar();
		}
		
		module_func* module_main = dlsym(module, "module_main");
		if(module_main == NULL){
			fprintf(stderr, "Failed to find module_main(). (%s)\n", dlerror());
			abort();
		}
		
		initscr();
		clear();
		if(module_main() == MODULE_EXIT) break;
		endwin();
		
		if(dlclose(module) != 0){
			fprintf(stderr, "Failed to close module. (%s)\n", dlerror());
			abort();
		}
	}
	
	return EXIT_SUCCESS;
}
