#include <stdio.h>

#include "./vm.h"

int main() {
	printf("Hello!\n");

	VM* vm = new_vm();
	object* pair_a = new_object(vm, OBJ_PAIR);
	object* pair_b = new_object(vm, OBJ_PAIR);

	pair_a->head = pair_b;
	pair_a->tail = pair_b;
	pair_b->tail = pair_a;
	pair_b->head = pair_a;

	mark(pair_a);

	/*push_int(vm, 3);
	push_int(vm, 4);

	object* obj = push_pair(vm);*/

	return 0;
}
