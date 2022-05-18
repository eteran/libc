
#define _ELIBC_SOURCE
#include "c/_support.h"
#include <errno.h>
#include <stdlib.h>

/*------------------------------------------------------------------------------
// Name: malloc
//----------------------------------------------------------------------------*/
void *malloc(size_t size) {
	void *const p = __elibc_malloc(size);
	if (!p && size != 0) {
		errno = ENOMEM;
	}
	return p;
}
