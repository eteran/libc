
#define __ELIBC_SOURCE
#include <strings.h>
#include <ctype.h>
#include <assert.h>

/*------------------------------------------------------------------------------
// Name: strncasecmp
//----------------------------------------------------------------------------*/
int strncasecmp(const char *s1, const char *s2, size_t n) {
	int ret = 0;

	assert(s1);
	assert(s2);

	while(!ret && (*s1 || *s2) && n--) {
		const char cs1 = (const char)tolower(*s1++);
		const char cs2 = (const char)tolower(*s2++);
		ret = (cs1 - cs2);
	}

	return ret;
}
