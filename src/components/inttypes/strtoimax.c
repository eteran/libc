
#define _ELIBC_SOURCE
#include <inttypes.h>
#include <stdlib.h>
#include <wchar.h> /* supposed to be necessary */

/*------------------------------------------------------------------------------
// Name: strtoimax
//----------------------------------------------------------------------------*/
intmax_t strtoimax(const char *nptr, char **endptr, int base) {
	return (intmax_t)strtoll(nptr, endptr, base);
}
