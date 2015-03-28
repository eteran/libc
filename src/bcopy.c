
#define __ELIBC_SOURCE
#include <strings.h>
#include <string.h>
#include <assert.h>

/*------------------------------------------------------------------------------
// Name: bcopy
//----------------------------------------------------------------------------*/
void bcopy(const void *src, void *dest, size_t n) {
	assert(src);
	assert(dest);

	/* we use memmove because spec for bcopy says it is correct
	   even for overlapping regions */
	memmove(dest, src, n);

}
