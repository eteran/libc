
#define _ELIBC_SOURCE
#include <wchar.h>

#ifdef _HAS_FPU

/**
 * @brief Converts a wide string to a float
 *
 * @param nptr The wide string to convert
 * @param endptr A pointer to a wide-character pointer that will be set to the first invalid character in the string
 * @return The converted float
 */
float wcstof(const wchar_t *_RESTRICT nptr, wchar_t **_RESTRICT endptr) {
	_UNUSED(nptr);
	_UNUSED(endptr);

	/* TODO(eteran): implement this */
	return 0;
}

#endif
