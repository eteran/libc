
#define _ELIBC_SOURCE
#include <assert.h>
#include <ctype.h>
#include <strings.h>

/*------------------------------------------------------------------------------
// Name: strcasecmp
//----------------------------------------------------------------------------*/
int strcasecmp(const char *s1, const char *s2) {
	int ret = 0;

	assert(s1);
	assert(s2);

	while (!ret && (*s1 || *s2)) {
		const char cs1 = (char)tolower(*s1++);
		const char cs2 = (char)tolower(*s2++);
		ret            = (cs1 - cs2);
	}

	return ret;
}
