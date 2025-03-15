
#define _ELIBC_SOURCE
#include <assert.h>
#include <wchar.h>

/**
 * @brief Searches for the first occurrence of the wide-character c in the first n wide-characters of the string pointed to by s.
 *
 * @param s The string to be searched.
 * @param c The wide-character to be located.
 * @param n The maximum number of wide-characters to be searched.
 * @return A pointer to the first occurrence of the wide-character c in the first n wide-characters of the string pointed to by s, or NULL if the character is not found.
 */
wchar_t *wmemchr(const wchar_t *s, wchar_t c, size_t n) {

	const wchar_t *s_ptr = s;
	const wchar_t cmp    = c;

	assert(s);

	while (n--) {
		if (*s_ptr == cmp) {
			return (wchar_t *)s_ptr;
		}
		++s_ptr;
	}

	return 0;
}
