
#define _ELIBC_SOURCE
#include <assert.h>
#include <string.h>

/*------------------------------------------------------------------------------
// Name: memchr
//----------------------------------------------------------------------------*/
void *memchr(const void *s, int c, size_t n) {

	const unsigned char *s_ptr = s;
	const unsigned char cmp    = (const unsigned char)(c & 0xff);

	assert(s);

	while (n--) {
		if (*s_ptr == cmp) {
			return (void *)s_ptr;
		}
		++s_ptr;
	}

	return 0;
}
