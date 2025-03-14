
#define _ELIBC_SOURCE
#include <string.h>
#include <strings.h>

/**
 * @brief Find the last occurrence of a character in a string
 *
 * @param s the string to search in
 * @param c the character to search for
 * @return char* pointer to the last occurrence of the character in the string, or NULL if not found
 * @note This function is similar to strrchr, but it is not a standard C function.
 *       It is included for compatibility with other systems.
 */
char *rindex(const char *s, int c) {
	return strrchr(s, c);
}
