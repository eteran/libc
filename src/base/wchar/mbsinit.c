
#define _ELIBC_SOURCE
#include <wchar.h>

/**
 * @brief Check if a multibyte conversion state is in the initial state.
 *
 * @param ps pointer to the multibyte conversion state
 * @return int non-zero if the state is in the initial state or NULL, zero otherwise
 */
int mbsinit(const mbstate_t *ps) {

	if (ps) {
		return ps->expected == 0 && ps->seen == 0;
	}

	return 1;
}
