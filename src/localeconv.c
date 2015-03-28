
#define __ELIBC_SOURCE
#include <locale.h>

/*------------------------------------------------------------------------------
// Name: localeconv
//----------------------------------------------------------------------------*/
struct lconv *localeconv(void) {
	_Thread_local static struct lconv __current_lconv;
	return &__current_lconv;
}
