
#define _ELIBC_SOURCE
#include <assert.h>
#include <inttypes.h>
#include <stdlib.h>
#include <wchar.h> /* supposed to be necessary */

/*------------------------------------------------------------------------------
// Name: strtoumax
//----------------------------------------------------------------------------*/
uintmax_t strtoumax(const char *nptr, char **endptr, int base) {
	assert(nptr);
	return (uintmax_t)strtoull(nptr, endptr, base);
}
