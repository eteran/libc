
#define _ELIBC_SOURCE
#include <assert.h>
#include <wchar.h>

/**
 * @brief Calculate the length of a wide-character string
 *
 * @param s the wide-character string to be checked
 * @return number of wide-characters in the string pointed to by s
 */
size_t wcslen(const wchar_t *s) {
	const wchar_t *s_ptr = s;

	assert(s);

	while (*s != L'\0') {
		++s;
	}

	return (size_t)(s - s_ptr);
}
