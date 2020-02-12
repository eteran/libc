
#define __ELIBC_SOURCE
#include "c/_support.h"
#include <stdlib.h>

/*------------------------------------------------------------------------------
// Name: free
//----------------------------------------------------------------------------*/
void free(void *ptr) {
	__elibc_free(ptr);
}
