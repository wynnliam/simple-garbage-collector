// Liam Wynn, 9/16/2019, Simple Garbage Collector

/*
	In this language, we use a stack based virtual machine.

	VM's are either stack based or register based, typically.
	JVM and CLR would be the former, whereas Lua's vm is the latter.

	We use this stack to store variables in scope that are used in
	the middle of an expression.
*/

#include "./obj_type.h"

#define MAX_STACK_SIZE	256
#define INITIAL_GC_THRESHOLD 4

typedef struct {
	// Tells us how many objects are allocated.
	int num_objects;
	// The number of objects required to trigger a garbage collection step.
	int max_objects;

	// A list of ALL objects allocated (used or unused).
	// We use this to find unused variables so that we can free them.
	object* first_object;

	object* stack[MAX_STACK_SIZE];
	int stack_size;
} VM;

VM* new_vm();

void push(VM* vm, object* val);
object* pop(VM* vm);

object* new_object(VM* vm, object_type type);
void push_int(VM* vm, int val);
object* push_pair(VM* vm);

void do_garbage_collection(VM* vm);

void mark_all(VM* vm);
void mark(object* obj);

void sweep(VM* vm);

void free_vm(VM* vm);
