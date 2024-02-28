
#define _ELIBC_SOURCE
#include <stdlib.h>
#include <wchar.h>

/*------------------------------------------------------------------------------
// Name:
//----------------------------------------------------------------------------*/
size_t wcstombs(char *dest, const wchar_t *src, size_t n) {
	static _Thread_local mbstate_t state;

	const wchar_t *first = src;
	const wchar_t *last  = src + n;
	size_t count         = 0;

	if (dest) {
		while (1) {
			if ((size_t)(last - first) < MB_CUR_MAX) {
				break;
			} else {

				const wchar_t ch = *first;
				const size_t rc  = wcrtomb(dest, ch, &state);

				if (rc == (size_t)-1) {
					return (size_t)-1;
				}

				if (ch == L'\0') {
					break;
				}

				dest += rc;
				count += rc;
				++first;
			}
		}
	} else {
		while (1) {
			const wchar_t ch = *first;
			const size_t rc  = wcrtomb(0, ch, &state);
			if (rc == (size_t)-1) {
				return (size_t)-1;
			}

			if (ch == L'\0') {
				break;
			}

			count += rc;
			++first;
		}
	}

	return count;
}
