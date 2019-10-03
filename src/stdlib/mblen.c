
#define __ELIBC_SOURCE
#include <assert.h>
#include <stdlib.h>

/*------------------------------------------------------------------------------
// Name: mblen
//----------------------------------------------------------------------------*/
int mblen(const char *s, size_t n) {
	assert(s);
	return mbtowc(0, s, n);
}
