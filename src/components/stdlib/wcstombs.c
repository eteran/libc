
#define _ELIBC_SOURCE
#include <stdlib.h>
#include <wchar.h>

/*------------------------------------------------------------------------------
// Name:
//----------------------------------------------------------------------------*/
size_t wcstombs(char *dest, const wchar_t *src, size_t n) {
	static _Thread_local mbstate_t state = {0, 0, 0};

	const wchar_t *first = src;
	const wchar_t *last = src + n;
	size_t count = 0;

	if (dest) {
		while (1) {
			if ((size_t)(last - first) < MB_CUR_MAX) {
				break;
			} else {
				const size_t rc = wcrtomb(dest, *first, &state);
				if (rc == (size_t)-1) {
					return (size_t)-1;
				}

				if (rc == 0) {
					break;
				}

				dest += rc;
				++first;
				++count;
			}
		}
	} else {
		while (1) {
			const size_t rc = wcrtomb(0, *first, &state);
			if (rc == (size_t)-1) {
				return (size_t)-1;
			}

			if (rc == 0) {
				break;
			}

			++first;
			++count;
		}
	}

	return count;
}
