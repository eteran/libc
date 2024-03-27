
#define _ELIBC_SOURCE
#define _ELIBC_SAFE_STRING
#include <stdlib.h>
#include <string.h>

/*------------------------------------------------------------------------------
// Name: strdup
//----------------------------------------------------------------------------*/
char *strdup(const char *s) {
	const size_t len = strlen(s) + 1;
	char *const ptr  = malloc(len);

	if (ptr) {
		memcpy(ptr, s, len);
	}

	return ptr;
}
