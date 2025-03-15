
#define _ELIBC_SOURCE
#include "c/_support.h"
#include <assert.h>
#include <stdio.h>

/**
 * @brief Write a block of data to a stream (thread-unsafe)
 *
 * @param ptr a pointer to the block of data to write
 * @param size the size of each element to write
 * @param nelem the number of elements to write
 * @param stream the stream to write to
 * @return the number of elements written, or 0 if an error occurred
 */
static size_t __elibc_fwrite(const void *ptr, size_t size, size_t nelem, FILE *stream) {
	size_t elem_it;
	size_t size_it;
	const char *p = ptr;

	assert(ptr);
	assert(stream);

	for (elem_it = 0; elem_it < nelem; ++elem_it) {
		for (size_it = 0; size_it < size; ++size_it) {
			if (__elibc_fputc(*p++, stream, _ELIBC_FILE_NARROW) == EOF) {
				return elem_it;
			}
		}
	}

	return elem_it;
}

/**
 * @brief Write a block of data to a stream
 *
 * @param ptr a pointer to the block of data to write
 * @param size the size of each element to write
 * @param nelem the number of elements to write
 * @param stream the stream to write to
 * @return the number of elements written, or 0 if an error occurred
 */
size_t fwrite(const void *ptr, size_t size, size_t nelem, FILE *stream) {
	size_t r;
	__ELIBC_WITH_LOCK(__elibc_fwrite(ptr, size, nelem, stream), &r);
	return r;
}
