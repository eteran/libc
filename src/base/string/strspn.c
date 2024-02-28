
#define _ELIBC_SOURCE
#include <assert.h>
#include <string.h>

/*------------------------------------------------------------------------------
// Name: strspn
//----------------------------------------------------------------------------*/
size_t strspn(const char *s, const char *accept) {
	const char *s_ptr = s;

	assert(s);
	assert(accept);

	while (*s_ptr != '\0') {
		if (strchr(accept, *s_ptr) == 0) {
			break;
		}

		++s_ptr;
	}

	return (size_t)(s_ptr - s);
}
