
#define _ELIBC_SOURCE
#include <assert.h>
#include <string.h>

/*------------------------------------------------------------------------------
// Name: strlen
//----------------------------------------------------------------------------*/
size_t strlen(const char *s) {
	const char *s_ptr = s;

	assert(s);

	while (*s != '\0') {
		++s;
	}

	return (size_t)(s - s_ptr);
}
