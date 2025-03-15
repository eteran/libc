
#define _ELIBC_SOURCE
#define _ELIBC_SAFE_STRING
#include <stdlib.h>
#include <string.h>

/**
 * @brief Duplicate a string
 *
 * @param s the string to be duplicated
 * @return pointer to the newly allocated string, or NULL if the allocation fails
 * @note This function is not a standard C function. It is included for compatibility with other systems.
 */
char *strdup(const char *s) {
	const size_t len = strlen(s) + 1;
	char *const ptr  = malloc(len);

	if (ptr) {
		memcpy(ptr, s, len);
	}

	return ptr;
}
