// Liam Wynn, 9/16/2019, Simple Garbage Collector

/*
	In this language, we use a stack based virtual machine.

	VM's are either stack based or register based, typically.
	JVM and CLR would be the former, whereas Lua's vm is the latter.

	We use this stack to store variables in scope that are used in
	the middle of an expression.
*/

#include "./obj_type.h"

#define MAX_STACK_SIZE	2

typedef struct {
	object* stack[MAX_STACK_SIZE];
	int stack_size;
} VM;

VM* new_vm();
void push(VM* vm, object* val);
object* pop(VM* vm);
