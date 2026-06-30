
#define _ELIBC_SOURCE
#include <string.h>

/**
 * @brief Compare two strings according to the current locale
 *
 * @param s1 the first string to be compared
 * @param s2 the second string to be compared
 * @return a negative value if s1 is less than s2, a positive value if s1 is greater than s2, and 0 if they are equal
 */
int strcoll(const char *s1, const char *s2) {
	/* TODO(eteran): make this locale aware */

	_LIBC_PRECOND(s1);
	_LIBC_PRECOND(s2);

	return strcmp(s1, s2);
}
