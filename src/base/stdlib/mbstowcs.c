
#define _ELIBC_SOURCE
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

/**
 * @brief Convert a multibyte string to a wide character string
 *
 * @param dest a pointer to the destination wide-character buffer
 * @param src a pointer to the multibyte string to be converted
 * @param n the maximum number of bytes to write to the destination buffer
 * @return the number of wide characters written to dest, or (size_t)-1 on error
 */
size_t mbstowcs(wchar_t *dest, const char *src, size_t n) {

	static _Thread_local mbstate_t state;

	const char *first = src;
	size_t count      = 0;

	memset(&state, 0, sizeof(state));

	if (!dest) {
		while (1) {
			const size_t rc = mbrtowc(0, first, MB_CUR_MAX, &state);
			if (rc == (size_t)-1 || rc == (size_t)-2) {
				return (size_t)-1;
			}

			if (rc == 0) {
				break;
			}

			first += rc;
			++count;
		}
		return count;
	}

	if (n == 0) {
		return 0;
	}

	while (count < n) {
		const size_t rc = mbrtowc(dest, first, MB_CUR_MAX, &state);
		if (rc == (size_t)-1 || rc == (size_t)-2) {
			return (size_t)-1;
		}

		if (rc == 0) {
			break;
		}

		first += rc;
		++dest;
		++count;
	}

	return count;
}
