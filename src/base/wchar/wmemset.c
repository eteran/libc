
#define _ELIBC_SOURCE
#include <assert.h>
#include <wchar.h>

/**
 * @brief Sets the wide-characters of a block of memory to a specified value.
 *
 * @param s The pointer to the block of memory to be set.
 * @param c The wide-character to set.
 * @param n The number of wide-characters to set.
 * @return a pointer to the block of memory that was set.
 */
wchar_t *wmemset(wchar_t *s, wchar_t c, size_t n) {

	/* traditional memset */
	wchar_t *s_ptr   = s;
	const wchar_t ch = c;

	assert(s);

	while (n--) {
		*s_ptr++ = ch;
	}

	return s;
}
