
#define _ELIBC_SOURCE
#include <wchar.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name:
//----------------------------------------------------------------------------*/
double wcstod(const wchar_t *_RESTRICT nptr, wchar_t **_RESTRICT endptr) {
	_UNUSED(nptr);
	_UNUSED(endptr);

	/* TODO(eteran): implement this */
	return 0;
}

#endif
