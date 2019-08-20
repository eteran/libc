
#define __ELIBC_SOURCE
#include <stdlib.h>
#include "c/_support.h"

/*------------------------------------------------------------------------------
// Name: free
//----------------------------------------------------------------------------*/
void free(void *ptr) {
	__elibc_free(ptr);
}
