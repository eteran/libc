
#define __ELIBC_SOURCE
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define ELEMENT_PTR(base, index, size) (void *)(((char *)(base)) + ((index) * (size)))

#define SWAP_PTR_BYTE(p1, p2)         \
do {                                  \
	const unsigned char temp = *(p1); \
	*(p1) = *(p2);                    \
	*(p2) = temp;                     \
} while(0)

#define ELEMENT_SWP(base, i, j, size)                                \
do {                                                                 \
	if(i != j) {                                                     \
		size_t it;                                                   \
		unsigned char *const base_ptr1 = ELEMENT_PTR(base, i, size); \
		unsigned char *const base_ptr2 = ELEMENT_PTR(base, j, size); \
		for(it = 0; it < size; ++it) {                               \
			SWAP_PTR_BYTE(base_ptr1 + it, base_ptr2 + it);           \
		}                                                            \
	}                                                                \
} while(0)

/*------------------------------------------------------------------------------
// Name: __elibc_partition
//----------------------------------------------------------------------------*/
static size_t __elibc_partition(void *base, size_t left, size_t right, size_t size, _compar_t compar) {

	const void *const x = ELEMENT_PTR(base, right, size);
	size_t index = left - 1;
	size_t i;

	assert(base);
	assert(compar);

	for(i = left; i < right; ++i) {
		if(compar(ELEMENT_PTR(base, i, size), x) <= 0) {
			++index;
			ELEMENT_SWP(base, index, i, size);
		}
	}

	ELEMENT_SWP(base, index + 1, right, size);
	return index + 1;
}

/*------------------------------------------------------------------------------
// Name: __elibc_quick_sort
//----------------------------------------------------------------------------*/
static void __elibc_quick_sort(void *base, int l, int r, size_t size, _compar_t compar) {
	assert(base);
	assert(compar);

	if(l < r) {
		const size_t q = __elibc_partition(base, l, r, size, compar);
		__elibc_quick_sort(base, l, q - 1, size, compar);
		__elibc_quick_sort(base, q + 1, r, size, compar);
	}
}

/*------------------------------------------------------------------------------
// Name: qsort
//----------------------------------------------------------------------------*/
void qsort(void *base, size_t nmemb, size_t size, _compar_t compar) {
	assert(base);
	assert(compar);

	if(size != 0) {
		__elibc_quick_sort(base, 0, nmemb - 1, size, compar);
	}

}
