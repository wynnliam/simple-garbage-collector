// Liam Wynn, 9/16/2019, Simple Garbage Collector

/*
	For this garbage collector, we are assuming our language
	has two object types: ints and pairs.
*/

typedef enum {
	OBJ_INT,
	OBJ_PAIR
} object_type;

typedef struct s_object {
	// Problem: unmarked objects, by definition, are unreachable. Our VM implements
	// the language semantics for object references. That is, we store only the pairs
	// and ints that variables use. If a variable is not in scope, the objects are unreachable.
	// To rectify this, we keep a list of ALL variables that are allocated.
	struct s_object* next;

	// If 0, it means the object is not referenced so we want to clean it.
	// Otherwise, it is referenced directly or indirectly. We say it is directly
	// referenced if it is used by a variable in scope. If it is indirectly, then
	// another object that is in scope uses this object.
	unsigned char marked;

	object_type type;

	union {
		// If type is OBJ_INT, use value.
		int value;

		// If type is OBJ_PAIR, use this struct.
		struct {
			struct s_object* head;
			struct s_object* tail;
		};
	};
} object;
