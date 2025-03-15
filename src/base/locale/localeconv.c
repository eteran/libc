
#define _ELIBC_SOURCE
#include <locale.h>

/**
 * @brief Returns a pointer to the current locale's numeric and monetary formatting information.
 *
 * @return A pointer to a structure containing the current locale's numeric and monetary formatting information.
 */
struct lconv *localeconv(void) {
	static _Thread_local struct lconv __current_lconv;
	return &__current_lconv;
}
