#include <stdio.h>

#include "./vm.h"

int main() {
	printf("Hello!\n");

	object a, b, c;
	VM* vm = new_vm();

	push(vm, &a);
	push(vm, &b);
	push(vm, &c);
	pop(vm);
	pop(vm);
	pop(vm);

	return 0;
}
