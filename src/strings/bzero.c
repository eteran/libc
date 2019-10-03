
#define __ELIBC_SOURCE
#include <assert.h>
#include <string.h>
#include <strings.h>

/*------------------------------------------------------------------------------
// Name: bzero
//----------------------------------------------------------------------------*/
void bzero(void *s, size_t n) {
	assert(s);
	memset(s, 0, n);
}
