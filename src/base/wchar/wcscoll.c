
#define _ELIBC_SOURCE
#include <assert.h>
#include <wchar.h>

/**
 * @brief Compare two wide-character strings using collating information
 *
 * @param ws1 The first wide-character string to be compared
 * @param ws2 The second wide-character string to be compared
 * @return less than, equal to, or greater than zero if ws1 is
 * lexicographically less than, equal to, or greater than ws2.
 */
int wcscoll(const wchar_t *ws1, const wchar_t *ws2) {
	/* TODO(eteran): make this locale aware */

	assert(ws1);
	assert(ws2);

	return wcscmp(ws1, ws2);
}
