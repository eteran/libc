
#define _ELIBC_SOURCE
#include <assert.h>
#include <stdlib.h>

#define ELEMENT_PTR(base, index, size) (((char *)(base)) + ((index) * (size)))

/**
 * @brief Search for a key in a sorted array using binary search
 *
 * @param key the key to search for
 * @param base a pointer to the first element of the array to search
 * @param nmemb the number of elements in the array
 * @param size the size of each element in the array
 * @param compar a pointer to a comparison function that determines the order of the elements
 * @return a pointer to the found element, or NULL if the key is not found
 */
void *bsearch(const void *key, const void *base, size_t nmemb, size_t size, __compar_fn_t compar) {

	size_t low  = 0;
	size_t high = nmemb;

	assert(key);
	assert(base);
	assert(compar);

	if (size == 0 || nmemb == 0) {
		return 0;
	}

	while (high > low) {

		/* split search in to halves */
		const size_t i = low + ((high - low) / 2);

		/* get item at center of this half */
		void *const item = ELEMENT_PTR(base, i, size);
		const int cmp    = compar(key, item);

		/* check results, go high or low or we found it ... */
		if (cmp < 0) {
			high = i;
		} else if (cmp > 0) {
			low = i + 1;
		} else {
			return item;
		}
	}

	return 0;
}
