#include <stdio.h>
#include <stdlib.h>

#include "./vm.h"

int main() {
	printf("Hello!\n");

	VM* vm = new_vm();

	// This loop triggers the garbage collector two times. However,
	// since all objects are in use, none get removed.

	int i;
	for(i = 0; i < 10; i++) {
		push_int(vm, i);

		if(i > 0 && i % 5 == 0)
			push_pair(vm);
	}

	// Now two objects are no longer in use so we make them unreachable.
	pop(vm);
	pop(vm);

	// This will clean up the two objects.
	do_garbage_collection(vm);

	// This will free all objects left.
	free_vm(vm);

	return 0;
}
