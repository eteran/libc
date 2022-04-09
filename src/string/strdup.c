
#define _ELIBC_SOURCE
#define _ELIBC_SAFE_STRING
#include <stdlib.h>
#include <string.h>

/*------------------------------------------------------------------------------
// Name: strdup
//----------------------------------------------------------------------------*/
char *strdup(const char *s) {
	const size_t len = strlen(s) + 1;
	char *const ret = malloc(len);

	if (ret) {
		strcpy(ret, s);
	}

	return ret;
}
