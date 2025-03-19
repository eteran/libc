
#define _ELIBC_SOURCE
#include <stdio.h>
#include <wchar.h>

/**
 * @brief Converts a wide-character to a byte character.
 *
 * @param c The wide-character to convert
 * @return The byte character, or EOF if the wide-character is not a valid byte character.
 * @note This function only supports ASCII.
 * @note For values below 0x80, the function returns the same value as the input.
 */
int wctob(wint_t c) {
	return (unsigned int)c < 128U ? (int)c : EOF;
}
