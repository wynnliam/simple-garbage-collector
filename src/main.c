#include <stdio.h>

#include "./vm.h"

int main() {
	printf("Hello!\n");

	VM* vm = new_vm();

	push_int(vm, 3);
	push_int(vm, 4);

	object* obj = push_pair(vm);

	return 0;
}
