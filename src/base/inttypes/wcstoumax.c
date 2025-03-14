
#define _ELIBC_SOURCE
#include <assert.h>
#include <inttypes.h>
#include <wchar.h>

/**
 * @brief Converts a wide string to an integer of type uintmax_t.
 *
 * @param nptr The wide string to be converted.
 * @param endptr A pointer to a pointer to the wide-character after the last character used in the conversion.
 * @param base The base of the number in the wide string. It can be 0, 2, 8, 10, or 16.
 * @return uintmax_t Returns the converted integer value.
 * @note If the base is 0, the function automatically detects the base from the wide string format.
 */
uintmax_t wcstoumax(const wchar_t *nptr, wchar_t **endptr, int base) {
	assert(nptr);
	return (uintmax_t)wcstoull(nptr, endptr, base);
}
