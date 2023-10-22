
#define _ELIBC_SOURCE
#include <assert.h>
#include <string.h>

/*------------------------------------------------------------------------------
// Name: strcpy
//----------------------------------------------------------------------------*/
char *strcpy(char *_RESTRICT dest, const char *_RESTRICT src) {
	char *dest_ptr = dest;

	assert(dest);
	assert(src);

	while (*src != '\0') {
		*dest_ptr++ = *src++;
	}

	*dest_ptr = '\0';
	return dest;
}
