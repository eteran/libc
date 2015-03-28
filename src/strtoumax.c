
#define __ELIBC_SOURCE
#include <wchar.h> /* supposed to be necessary */
#include <inttypes.h>
#include <stdlib.h>

uintmax_t strtoumax(const char *nptr, char **endptr, int base) {
	return (uintmax_t)strtoull(nptr, endptr, base);
}
