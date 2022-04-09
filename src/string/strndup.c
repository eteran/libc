
#define _ELIBC_SOURCE
#define _ELIBC_SAFE_STRING
#include <stdlib.h>
#include <string.h>

/*------------------------------------------------------------------------------
// Name: strndup
//----------------------------------------------------------------------------*/
char *strndup(const char *s, size_t n) {
	const size_t len = (n + 1);
	char *const ret = malloc(len);

	if (ret) {
		strncpy(ret, s, n);
		ret[len - 1] = '\0';
	}

	return ret;
}
