
#define __ELIBC_SOURCE
#include <locale.h>

/*------------------------------------------------------------------------------
// Name: localeconv
//----------------------------------------------------------------------------*/
struct lconv *localeconv(void) {
	static _Thread_local struct lconv __current_lconv;
	return &__current_lconv;
}
