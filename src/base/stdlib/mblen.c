
#define _ELIBC_SOURCE
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

/**
 * @brief Get the number of bytes in a multibyte character
 *
 * @param s a pointer to the multibyte character
 * @param n the maximum number of bytes to read from s
 * @return int the number of bytes in the multibyte character, or -1 on error
 */
int mblen(const char *s, size_t n) {
	static _Thread_local mbstate_t state;

	if (!s) {
		memset(&state, 0, sizeof(state));
		return 0;
	}
	return (int)mbrtowc(0, s, n, &state);
}
