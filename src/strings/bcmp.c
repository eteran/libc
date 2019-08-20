
#define __ELIBC_SOURCE
#include <strings.h>
#include <string.h>
#include <assert.h>

/*------------------------------------------------------------------------------
// Name: bcmp
//----------------------------------------------------------------------------*/
int bcmp(const void *s1, const void *s2, size_t n) {
	assert(s1);
	assert(s2);
	return memcmp(s1, s2, n);
}
