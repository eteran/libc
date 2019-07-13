
#define __ELIBC_SOURCE
#include <string.h>
#include <assert.h>

/*------------------------------------------------------------------------------
// Name: memcmp
//----------------------------------------------------------------------------*/
int memcmp(const void *s1, const void *s2, size_t n) {
	int ret = 0;
	const char *p1 = s1;
	const char *p2 = s2;

	assert(s1);
	assert(s2);

	while(!ret && n--) {
		ret = (*p2++ - *p1++);
	}

	return ret;
}
