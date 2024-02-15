
#define _ELIBC_SOURCE
#include "c/_support.h"
#include <assert.h>
#include <stdio.h>

/*------------------------------------------------------------------------------
// Name: __elibc_fwrite
//----------------------------------------------------------------------------*/
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

/*------------------------------------------------------------------------------
// Name: fwrite
//----------------------------------------------------------------------------*/
size_t fwrite(const void *ptr, size_t size, size_t nelem, FILE *stream) {
	size_t r;
	__ELIBC_WITH_LOCK(__elibc_fwrite(ptr, size, nelem, stream), &r);
	return r;
}
