typedef enum {
	MODULE_EXIT,
	MODULE_RELOAD,
} ModuleStatus;

typedef ModuleStatus module_func(void);
