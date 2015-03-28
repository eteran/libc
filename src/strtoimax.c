
#define __ELIBC_SOURCE
#include <wchar.h> /* supposed to be necessary */
#include <inttypes.h>
#include <stdlib.h>

intmax_t strtoimax(const char *nptr, char **endptr, int base) {
	return (intmax_t)strtoll(nptr, endptr, base);
}
