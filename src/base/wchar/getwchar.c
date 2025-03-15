
#define _ELIBC_SOURCE
#include <stdio.h>
#include <wchar.h>

/**
 * @brief Read a wide-character from stdin
 *
 * @return the read character, or WEOF if an error occurred
 */
wint_t getwchar(void) {
	return fgetwc(stdin);
}
