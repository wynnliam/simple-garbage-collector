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
