
#define _ELIBC_SOURCE
#include <assert.h>
#include <inttypes.h>
#include <stdlib.h>
#include <wchar.h> /* supposed to be necessary */

/*------------------------------------------------------------------------------
// Name: strtoimax
//----------------------------------------------------------------------------*/
intmax_t strtoimax(const char *nptr, char **endptr, int base) {
	assert(nptr);
	return (intmax_t)strtoll(nptr, endptr, base);
}
