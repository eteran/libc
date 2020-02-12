
#define __ELIBC_SOURCE
#include <assert.h>
#include <string.h>

/*------------------------------------------------------------------------------
// Name: strncmp
//----------------------------------------------------------------------------*/
int strncmp(const char *s1, const char *s2, size_t n) {
	int ret = 0;

	assert(s1);
	assert(s2);

	while (!ret && (*s1 || *s2) && n--) {
		ret = (*s1++ - *s2++);
	}

	return ret;
}
