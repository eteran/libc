
#define _ELIBC_SOURCE
#include <assert.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Allocate memory for an array of nmemb elements, each of size size
 *
 * @param nmemb the number of elements to allocate
 * @param size the size of each element
 * @return a pointer to the allocated memory, or NULL if the allocation fails
 * @note this function sets all bytes in the allocated memory to zero
 */
void *calloc(size_t nmemb, size_t size) {

	void *ret  = 0;
	size_t len = 0;

	/* multiply nmemb and size while checking for overflow */
	if (__builtin_mul_overflow(nmemb, size, &len)) {
		errno = ENOMEM;
		return 0;
	}

	if ((ret = malloc(len))) {
		/* allocate it and zero it */
		memset(ret, 0, len);
	}

	return ret;
}
