#include <stdio.h>
#include <stdlib.h>

#include "./vm.h"

int main() {
	printf("Hello!\n");

	VM* vm = new_vm();

	push_int(vm, 1);
	push_int(vm, 2);

	do_garbage_collection(vm);

	free(vm);

	return 0;
}
