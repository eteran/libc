
#define _ELIBC_SOURCE
#include <stdio.h>
#include <wchar.h>

/**
 * @brief Convert a byte to a wide-character
 *
 * @param c the byte to be converted
 * @return the wide-character corresponding to the byte c, or WEOF if c is
 * not a valid wide-character
 * @note This function only supports ASCII and UTF-8, so in both cases, a value less than 0x80 maps directly.
 */
wint_t btowc(int c) {
	return (wint_t)c < 128u ? (wint_t)c : WEOF;
}
