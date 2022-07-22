#include <stdio.h>
#include "../ao_slice.h"

// Defines a new structure called Slice_int
ao_slice_def(int);

int main() {
	int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	// Creates a slice array[1:7]
	struct Slice(int) slice = slc_ab(array, 1, 7);

	for (int i = 0; i < slclen(slice); ++i) {
		printf("%d\n", slcget(slice, i));
	}

	return 0;
}
