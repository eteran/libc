
#define __ELIBC_SOURCE
#include <stdlib.h>
#include <errno.h>
#include "c/_support.h"

/*------------------------------------------------------------------------------
// Name: malloc
//----------------------------------------------------------------------------*/
void *malloc(size_t size) {
	void *const p = __elibc_malloc(size);
	if(!p && size != 0) {
		errno = ENOMEM;
	}
	return p;
}
