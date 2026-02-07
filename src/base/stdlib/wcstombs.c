
#define _ELIBC_SOURCE
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

/**
 * @brief Convert a wide character string to a multibyte character string
 *
 * @param dest the destination multibyte character string
 * @param src the source wide character string
 * @param n the maximum number of wide characters to convert
 * @return the number of bytes written to the destination multibyte character string, or (size_t)-1 if an error occurs
 */
size_t wcstombs(char *dest, const wchar_t *src, size_t n) {
	static _Thread_local mbstate_t state;

	const wchar_t *first = src;
	size_t count         = 0;

	memset(&state, 0, sizeof(state));

	if (!dest) {
		while (1) {
			const wchar_t ch = *first;
			char buffer[MB_CUR_MAX];
			const size_t rc = wcrtomb(buffer, ch, &state);
			if (rc == (size_t)-1) {
				return (size_t)-1;
			}

			if (ch == L'\0') {
				break;
			}

			count += rc;
			++first;
		}
		return count;
	}

	if (n == 0) {
		return 0;
	}

	while (1) {
		const wchar_t ch = *first;
		char buffer[MB_CUR_MAX];
		const size_t rc = wcrtomb(buffer, ch, &state);
		if (rc == (size_t)-1) {
			return (size_t)-1;
		}

		if (rc > n) {
			break;
		}

		memcpy(dest, buffer, rc);
		if (ch == L'\0') {
			return count;
		}

		dest += rc;
		n -= rc;
		count += rc;
		++first;
	}

	return count;
}
