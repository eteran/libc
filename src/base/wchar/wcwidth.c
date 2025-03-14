
#define _ELIBC_SOURCE
#include <wchar.h>

/**
 * @brief Returns the number of columns required to represent a wide-character
 *
 * @param wc The wide-character to measure
 * @return int The number of columns required to represent the wide-character
 */
int wcwidth(wchar_t wc) {

	if (wc == L'\0') {
		return 0;
	}

	/* TODO(eteran): implement this */
	return 1;
}
