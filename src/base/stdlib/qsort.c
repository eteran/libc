
#define _ELIBC_SOURCE
#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/* This is the threshold at which we switch from quicksort to insertion sort.
 * It is defined in terms of the number of bytes in the array, not the number of
 * elements.
 */
#define INSERTION_SORT_THRESHOLD 16

#define ELEMENT_PTR(base, index, size) (void *)(((char *)(base)) + ((index) * (size)))

#define ELEMENT_SWP(base, i, j, size)                                          \
	do {                                                                       \
		if ((i) != (j)) {                                                      \
			unsigned char *const base_ptr1 = ELEMENT_PTR((base), (i), (size)); \
			unsigned char *const base_ptr2 = ELEMENT_PTR((base), (j), (size)); \
			memswp(base_ptr1, base_ptr2, (size));                              \
		}                                                                      \
	} while (0)

/**
 * @brief Partition an array of elements using the quicksort algorithm
 *
 * @param base a pointer to the first element of the array to be sorted
 * @param left the left index of the array to be sorted
 * @param right the right index of the array to be sorted
 * @param size the size of each element in the array
 * @param compar a pointer to a comparison function that determines the order of the elements
 * @return the index of the pivot element after partitioning
 */
static size_t __elibc_partition(void *base, size_t left, size_t right, size_t size,
								__compar_fn_t compar) {

	const void *const x = ELEMENT_PTR(base, right, size);
	size_t index        = left - 1;
	size_t i;

	assert(base);
	assert(compar);

	for (i = left; i < right; ++i) {
		if (compar(ELEMENT_PTR(base, i, size), x) <= 0) {
			++index;
			ELEMENT_SWP(base, index, i, size);
		}
	}

	ELEMENT_SWP(base, index + 1, right, size);
	return index + 1;
}

static void __elibc_insertion_sort(void *base, size_t n, size_t size, __compar_fn_t compar) {
	for (size_t i = 1; i < n; ++i) {
		for (size_t j = i; j > 0 && compar(ELEMENT_PTR(base, j - 1, size), ELEMENT_PTR(base, j, size)) > 0; --j) {
			ELEMENT_SWP(base, j - 1, j, size);
		}
	}
}

#include <stdio.h>

/**
 * @brief Sort an array of elements using the quicksort algorithm
 *
 * @param base a pointer to the first element of the array to be sorted
 * @param l the left index of the array to be sorted
 * @param r the right index of the array to be sorted
 * @param size the size of each element in the array
 * @param compar a pointer to a comparison function that determines the order of the elements
 */
static void __elibc_quick_sort(void *base, size_t l, size_t r, size_t size, __compar_fn_t compar) {
	assert(base);
	assert(compar);

	if ((r - l) < INSERTION_SORT_THRESHOLD) {
		__elibc_insertion_sort(ELEMENT_PTR(base, l, size), r - l + 1, size, compar);
		return;
	}

	if (l < r) {
		const size_t q = __elibc_partition(base, l, r, size, compar);
		if (q > 0) {
			__elibc_quick_sort(base, l, q - 1, size, compar);
		}
		__elibc_quick_sort(base, q + 1, r, size, compar);
	}
}

/**
 * @brief Sort an array of elements using the quicksort algorithm
 *
 * @param base a pointer to the first element of the array to be sorted
 * @param nmemb the number of elements in the array
 * @param size the size of each element in the array
 * @param compar a pointer to a comparison function that determines the order of the elements
 */
void qsort(void *base, size_t nmemb, size_t size, __compar_fn_t compar) {
	assert(base);
	assert(compar);

	if (size != 0) {
		__elibc_quick_sort(base, 0, nmemb - 1, size, compar);
	}
}
