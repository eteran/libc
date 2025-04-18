
#define _ELIBC_SOURCE
#include <assert.h>
#include <stdio.h>

/**
 * @brief Read a block of data from a stream (thread-unsafe)
 *
 * @param ptr a pointer to the block of data to read
 * @param size the size of each element to read
 * @param nmemb the number of elements to read
 * @param stream the stream to read from
 * @return the number of elements read, or 0 if an error occurred
 */
static size_t __elibc_fread(void *ptr, size_t size, size_t nmemb, FILE *stream) {

	size_t elem_it;
	size_t size_it;
	char *p = ptr;

	assert(ptr);
	assert(stream);

	for (elem_it = 0; elem_it < nmemb; ++elem_it) {
		for (size_it = 0; size_it < size; ++size_it) {
			const int ch = __elibc_fgetc(stream);
			if (ch != EOF) {
				*p++ = (char)ch;
			} else {
				return elem_it;
			}
		}
	}

	return elem_it;
}

/**
 * @brief Read a block of data from a stream
 *
 * @param ptr a pointer to the block of data to read
 * @param size the size of each element to read
 * @param nmemb the number of elements to read
 * @param stream the stream to read from
 * @return the number of elements read, or 0 if an error occurred
 */
size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream) {
	size_t r;
	__ELIBC_WITH_LOCK(__elibc_fread(ptr, size, nmemb, stream), &r);
	return r;
}
