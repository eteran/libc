
#define __ELIBC_SOURCE
#include <string.h>
#include <assert.h>

/*------------------------------------------------------------------------------
// Name: strlen
//----------------------------------------------------------------------------*/
size_t strlen(const char *s) {
	const char *s_ptr = s;

	assert(s);

	while(*s != '\0') {
		++s;
	}

	return s - s_ptr;
}
