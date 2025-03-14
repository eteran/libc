
#define _ELIBC_SOURCE
#include <assert.h>
#include <inttypes.h>
#include <stdlib.h>
#include <wchar.h> /* supposed to be necessary */

/**
 * @brief Converts a string to an integer of type uintmax_t.
 *
 * @param nptr The string to be converted.
 * @param endptr A pointer to a pointer to the character after the last character used in the conversion.
 * @param base The base to use for the conversion (between 2 and 36 inclusive, or 0)
 * @return uintmax_t Returns the converted integer value.
 * @note If the base is 0, the function automatically detects the base from the string format.
 */
uintmax_t strtoumax(const char *nptr, char **endptr, int base) {
	assert(nptr);
	return (uintmax_t)strtoull(nptr, endptr, base);
}
