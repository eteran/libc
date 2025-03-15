
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
static void *__elibc_calloc(size_t nmemb, size_t size) {

	void *ret        = 0;
	const size_t len = nmemb * size;

	assert(nmemb != 0);
	assert(size != 0);

	/* do some overflow checking.. */
	if (size != (len / nmemb)) {
		errno = ENOMEM;
	} else if ((ret = malloc(len))) {
		/* allocate it and zero it */
		memset(ret, 0, len);
	}

	return ret;
}

/**
 * @brief Allocate memory for an array of nmemb elements, each of size size
 *
 * @param nmemb the number of elements to allocate
 * @param size the size of each element
 * @return a pointer to the allocated memory, or NULL if the allocation fails
 * @note this function sets all bytes in the allocated memory to zero
 */
void *calloc(size_t nmemb, size_t size) {

	if (nmemb == 0 || size == 0) {
		return 0;
	}

	return __elibc_calloc(nmemb, size);
}
