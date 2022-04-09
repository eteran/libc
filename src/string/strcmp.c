
#define _ELIBC_SOURCE
#include <assert.h>
#include <string.h>

/*------------------------------------------------------------------------------
// Name: strcmp
//----------------------------------------------------------------------------*/
int strcmp(const char *s1, const char *s2) {
	int ret = 0;

	assert(s1);
	assert(s2);

	while (!ret && (*s1 || *s2)) {
		ret = (*s1++ - *s2++);
	}

	return ret;
}
