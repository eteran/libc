
#define _ELIBC_SOURCE
#include <stdlib.h>
#include <wchar.h>

/**
 * @brief Converts a wide character to a multibyte character
 *
 * @param s a pointer to the destination multibyte character
 * @param wc the wide character to convert
 * @return int the number of bytes written to the destination multibyte character, or -1 if an error occurs
 * @note s must be at least MB_CUR_MAX bytes long
 */
int wctomb(char *s, wchar_t wc) {

	if (!s) {
		/* does the encoding have a non-trivial shift state?
		 * in UTF-8, conversion from wchar_t to mb can be done all at once since
		 * s is guaranteed to have enough space by the standard
		 */
		return 0;
	}

	return (int)wcrtomb(s, wc, 0);
}
