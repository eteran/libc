
#define _ELIBC_SOURCE
#include <assert.h>
#include <string.h>

/*------------------------------------------------------------------------------
// Name: memcmp
//----------------------------------------------------------------------------*/
int memcmp(const void *s1, const void *s2, size_t n) {
	int ret        = 0;
	const char *p1 = s1;
	const char *p2 = s2;

	assert(s1);
	assert(s2);

	while (!ret && n--) {
		ret = (*p1++ - *p2++);
	}

	return ret;
}
