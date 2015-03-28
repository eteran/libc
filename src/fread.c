
#define __ELIBC_SOURCE
#include <stdio.h>
#include <assert.h>

/*------------------------------------------------------------------------------
// Name: __elibc_fread
//----------------------------------------------------------------------------*/
size_t __elibc_fread(void *ptr, size_t size, size_t nmemb, FILE *stream) {

	size_t elem_it;
	size_t size_it;
	char *p = ptr;

	assert(ptr);
	assert(stream);

	for(elem_it = 0; elem_it < nmemb; ++elem_it) {
		for(size_it = 0; size_it < size; ++size_it) {
			const int ch = __elibc_fgetc(stream);
			if(ch != EOF) {
				*p++ = ch;
			} else {
				return elem_it;
			}
		}
	}

	return elem_it;
}

/*------------------------------------------------------------------------------
// Name: fread
//----------------------------------------------------------------------------*/
size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream) {

	size_t r;
	__elibc_lock_stream(stream);
	r = __elibc_fread(ptr, size, nmemb, stream);
	__elibc_unlock_stream(stream);
	return r;
}
