
#define _ELIBC_SOURCE
#include <stdio.h>
#include <wchar.h>

/**
 * @brief Write a wide-character to stdout
 *
 * @param wc the wide-character to be written
 * @return wint_t the written character, or WEOF if an error occurred
 */
wint_t putwchar(wchar_t wc) {
	return fputwc(wc, stdout);
}
