
#define __ELIBC_SOURCE
#include <stdlib.h>
#include <string.h>
#include "c/_support.h"

/*------------------------------------------------------------------------------
// Name: getenv
//----------------------------------------------------------------------------*/
char *getenv(const char *name) {

	if(__elibc_environment) {
		char **ep = __elibc_environment;
		const size_t len = strlen(name);
		while(*ep) {
			char *const s = *ep;

			if(memcmp(name, s, len) == 0 && s[len] == '=') {
				return s + (len + 1);
			}
			++ep;
		}
	}

	return 0;
}
