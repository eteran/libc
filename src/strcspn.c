
#define __ELIBC_SOURCE
#include <string.h>
#include <assert.h>

/*------------------------------------------------------------------------------
// Name: strcspn
//----------------------------------------------------------------------------*/
size_t strcspn(const char *s, const char *reject) {
	const char *s_ptr = s;

	assert(s);
	assert(reject);

	while(*s_ptr != '\0') {
		if(strchr(reject, *s_ptr) != 0) {
			break;
		}

		++s_ptr;
	}

	return s_ptr - s;
}
