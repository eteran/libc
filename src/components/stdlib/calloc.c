
#define _ELIBC_SOURCE
#include <assert.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

/*------------------------------------------------------------------------------
// Name: __elibc_calloc
//----------------------------------------------------------------------------*/
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

/*------------------------------------------------------------------------------
// Name: calloc
//----------------------------------------------------------------------------*/
void *calloc(size_t nmemb, size_t size) {

	if (nmemb == 0 || size == 0) {
		return 0;
	}

	return __elibc_calloc(nmemb, size);
}
