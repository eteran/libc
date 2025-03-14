
#define _ELIBC_SOURCE
#include <assert.h>
#include <inttypes.h>
#include <wchar.h>

/**
 * @brief Converts a wide string to an integer of type uintmax_t.
 *
 * @param nptr The wide string to be converted.
 * @param endptr A pointer to a pointer to the wide-character after the last character used in the conversion.
 * @param base The base to use for the conversion (between 2 and 36 inclusive, or 0)
 * @return uintmax_t Returns the converted integer value.
 * @note If the base is 0, the function automatically detects the base from the wide string format.
 */
uintmax_t wcstoumax(const wchar_t *nptr, wchar_t **endptr, int base) {
	assert(nptr);
	return (uintmax_t)wcstoull(nptr, endptr, base);
}
