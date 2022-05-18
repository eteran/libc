
#define _ELIBC_SOURCE
#include <inttypes.h>
#include <wchar.h>

/*------------------------------------------------------------------------------
// Name: wcstoimax
//----------------------------------------------------------------------------*/
intmax_t wcstoimax(const wchar_t *nptr, wchar_t **endptr, int base) {
	return (intmax_t)wcstoll(nptr, endptr, base);
}
