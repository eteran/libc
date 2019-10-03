
#define __ELIBC_SOURCE
#include <stdlib.h>
#include <string.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: __elibc_calloc
//----------------------------------------------------------------------------*/
static void *__elibc_calloc(size_t nmemb, size_t size) {
	
	void *ret = 0;
	const size_t len = nmemb * size;

	/* do some overflow checking.. */
	if (size != (len / nmemb)) {
		errno = ENOMEM;
	} else if((ret = malloc(len))) {
		/* allocate it and zero it */
		memset(ret, 0, len);
	}

	return ret;
}

/*------------------------------------------------------------------------------
// Name: calloc
//----------------------------------------------------------------------------*/
void *calloc(size_t nmemb, size_t size) {

	/* we need to ensure this because we divide by this later */
	if(nmemb == 0) {
		nmemb = 1;
	}
	
	return __elibc_calloc(nmemb, size);
}
