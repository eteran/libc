
#define __ELIBC_SOURCE
#include <strings.h>
#include <string.h>
#include <assert.h>

/*------------------------------------------------------------------------------
// Name: bzero
//----------------------------------------------------------------------------*/
void bzero(void *s, size_t n) {
	assert(s);
	memset(s, 0, n);
}
