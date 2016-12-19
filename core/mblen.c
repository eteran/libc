
#define __ELIBC_SOURCE
#include <stdlib.h>
#include <assert.h>

/*------------------------------------------------------------------------------
// Name: mblen
//----------------------------------------------------------------------------*/
int mblen(const char *s, size_t n) {

	assert(s);
	return mbtowc(0, s, n);
}
