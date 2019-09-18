// Liam Wynn, 9/16/2019, Simple Garbage Collector

#include "./vm.h"
#include <stdlib.h>
#include <stdio.h>

VM* new_vm() {
	VM* result = (VM*)malloc(sizeof(VM));

	result->stack_size = 0;
	result->first_object = NULL;

	result->num_objects = 0;
	result->max_objects = INITIAL_GC_THRESHOLD;

	return result;
}

void push(VM* vm, object* val) {
	if(!vm) {
		printf("push: ERROR! virtual machine is NULL\n");
		return;
	} else if(vm->stack_size >= MAX_STACK_SIZE) {
		printf("push: ERROR! Stack overflow!\n");
		return;
	}

	vm->stack[vm->stack_size++] = val;
}

object* pop(VM* vm) {
	if(!vm) {
		printf("pop: ERROR! virtual machine is NULL\n");
		return NULL;
	} else if(vm->stack_size <= 0) {
		printf("pop: ERROR! Stack underflow!\n");
		return NULL;
	}

	return vm->stack[--vm->stack_size];
}

object* new_object(VM* vm, object_type type) {
	if(vm->num_objects == vm->max_objects)
		do_garbage_collection(vm);

	object* result = (object*)malloc(sizeof(object));

	result->type = type;
	result->marked = 0;

	// Push this object on the stack of all allocated variables
	result->next = vm->first_object;
	vm->first_object = result;

	vm->num_objects++;

	return result;
}

void push_int(VM* vm, int val) {
	object* object = new_object(vm, OBJ_INT);
	object->value = val;

	push(vm, object);
}

object* push_pair(VM* vm) {
	object* object = new_object(vm, OBJ_PAIR);
	object->tail = pop(vm);
	object->head = pop(vm);

	push(vm, object);

	return object;
}

void mark_all(VM* vm) {
	int i;
	for(i = 0; i < vm->stack_size; i++)
		mark(vm->stack[i]);
}

void mark(object* obj) {
	// This is important so that we don't get caught in a cycle where pair a points to pair b
	// which points back to pair a.
	if(obj->marked)
		return;

	obj->marked = 1;

	if(obj->type == OBJ_PAIR) {
		mark(obj->head);
		mark(obj->tail);
	}
}

void sweep(VM* vm) {
	object** curr = &vm->first_object;

	while(*curr) {
		if(!(*curr)->marked) {
			// This object wasn't reached, so remove it
			object* temp = *curr;
			*curr = temp->next;
			free(temp);

			vm->num_objects--;

		} else {
			// This object was reached, so go to the next one.
			// So unmark this one (for the next garbage collection call)
			// and move to the next one.
			(*curr)->marked = 0;
			curr = &(*curr)->next;
		}
	}
}

void do_garbage_collection(VM* vm) {
	int num_objects = vm->num_objects;

	mark_all(vm);
	sweep(vm);

	vm->max_objects = vm->num_objects * 2;

	printf("Objects removed: %d\n", num_objects - vm->num_objects);
}

void free_vm(VM* vm) {
	// Pops all items off the stack
	vm->stack_size = 0;

	do_garbage_collection(vm);
	free(vm);
}
