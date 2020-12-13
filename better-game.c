#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include <ncurses.h>
#include <dlfcn.h>

#include "better-game.h"


int main(void){
	const char* module_name = "./better-game-module.so";
	
	while(1){
		while(system("make better-game-module.so") != 0){
			fprintf(stderr, "Whoops! Failed to compile!\n");
			gets();
		}
		
		void* module = dlopen(module_name, RTLD_NOW);
		if(module == NULL){
			fprintf(stderr, "Failed to load module. (%s)\n", dlerror());
			abort();
		}
		
		typedef ModuleStatus module_func(void);
		module_func* func = dlsym(module, "module_init");
		if(func == NULL){
			fprintf(stderr, "Failed to find module_init(). (%s)\n", dlerror());
			abort();
		}
		
		initscr();
		clear();
		if(func() == MODULE_EXIT) break;
		endwin();
		
		if(dlclose(module) != 0){
			fprintf(stderr, "Failed to close module. (%s)\n", dlerror());
			abort();
		}
	}
	
	return EXIT_SUCCESS;
}
