
#define _ELIBC_SOURCE
#include <inttypes.h>
#include <wchar.h>

/*------------------------------------------------------------------------------
// Name: wcstoumax
//----------------------------------------------------------------------------*/
uintmax_t wcstoumax(const wchar_t *nptr, wchar_t **endptr, int base) {
	return (uintmax_t)wcstoull(nptr, endptr, base);
}
