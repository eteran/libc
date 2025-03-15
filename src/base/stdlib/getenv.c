
#define _ELIBC_SOURCE
#include "c/_support.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Get the value of an environment variable
 *
 * @param name the name of the environment variable to get
 * @return a pointer to the value of the environment variable, or NULL if the variable is not found
 */
char *getenv(const char *name) {

	assert(name);

	if (__elibc_environment) {
		char **ep        = __elibc_environment;
		const size_t len = strlen(name);
		while (*ep) {
			char *const s = *ep;

			if (memcmp(name, s, len) == 0 && s[len] == '=') {
				return s + (len + 1);
			}
			++ep;
		}
	}

	return 0;
}
