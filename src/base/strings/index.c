
#define _ELIBC_SOURCE
#include <string.h>
#include <strings.h>

/**
 * @brief Find the first occurrence of a character in a string
 *
 * @param s the string to search in
 * @param c the character to search for
 * @return char* pointer to the first occurrence of the character in the string, or NULL if not found
 * @note This function is similar to strchr, but it is not a standard C function.
 *       It is included for compatibility with other systems.
 */
char *index(const char *s, int c) {
	return strchr(s, c);
}
