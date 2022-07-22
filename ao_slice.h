/*

DOCUMENTATION

	Array Slices

		Interface:

			Define the type for a new slice:
			  ao_slice_def(T);

			Declare a new slice of type T:
			  Slice(T) slice = {0};

			Create a slice of array[0:n]:
			  Slice(T) slice = slc_b(array, n);

		Functions

			Slice(T) slc_a(T array[], size_t a);
				Returns a new slice from a to the end of the array (array[a:]).

			Slice(T) slc_b(T array[], size_t b);
				Returns a new slice from the start of the array to b (array[:b]).

			Slice(T) slc_ab(T array[], size_t a, size_t b);
				Returns a new slice from a to b (array[a:b]).

			size_t slclen(Slice(T) s);
				Returns the number of elements in the slice.

			T slcget(Slice(T) s, size_t i);
				Gets an element from the slice at index i.

*/

#ifndef AO_SLICE_H
#define AO_SLICE_H

#ifndef AO_NO_SHORT_NAMES
#define slc_a ao_slice_start
#define slc_b ao_slice_end
#define slc_ab ao_slice_start_end
#define slclen ao_slice_len
#define slcget ao_slice_get
#endif

#define ao_slice_def(T) struct Slice_##T { T *data; int count; }
#define Slice(T) Slice_##T

#define ao_slice_start(array, start) {.data = &(array)[start], .count = (sizeof array / sizeof array[0])}
#define ao_slice_end(array, end) {.data = (array), .count = (end)}
#define ao_slice_start_end(array, start, end) {.data = &(array)[start], .count = (end)-(start)}
#define ao_slice_len(s) ((s).count)
#define ao_slice_get(s, i) ((s).data[i])

#endif // AO_SLICE_H

#ifdef AO_SLICE_IMPLEMENTATION

#endif // AO_SLICE_IMPLEMENTATION
