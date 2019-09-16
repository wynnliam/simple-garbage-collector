// Liam Wynn, 9/16/2019, Simple Garbage Collector

#include "./vm.h"
#include <stdlib.h>
#include <stdio.h>

VM* new_vm() {
	VM* result = (VM*)malloc(sizeof(VM));
	result->stack_size = 0;

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
