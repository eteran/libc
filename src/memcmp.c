
#define __ELIBC_SOURCE
#include <string.h>
#include <assert.h>

/*------------------------------------------------------------------------------
// Name: memcmp
//----------------------------------------------------------------------------*/
int memcmp(const void *s1, const void *s2, size_t n) {
	int ret = 0;
	const char *s1_ptr = s1;
	const char *s2_ptr = s2;

	assert(s1);
	assert(s2);

	while(!ret && n--) {
		ret = (*s2_ptr++ - *s1_ptr++);
	}

	return ret;
}
