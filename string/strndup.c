
#define __ELIBC_SOURCE
#define __ELIBC_SAFE_STRING
#include <string.h>
#include <stdlib.h>

/*------------------------------------------------------------------------------
// Name: strndup
//----------------------------------------------------------------------------*/
char *strndup(const char *s, size_t n) {
	const size_t len = (n + 1);
	char *const ret  = malloc(len);

	if(ret) {
		strncpy(ret, s, n);
		ret[len - 1] = '\0';
	}

	return ret;
}
