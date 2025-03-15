
#include <stdlib.h>

#ifdef _HAS_FPU

/**
 * @brief Convert a string to a long double
 *
 * @param nptr the string to be converted
 * @param endptr a pointer to a pointer to the first invalid character in the string
 * @return the converted value
 */
long double strtold(const char *_RESTRICT nptr, char **_RESTRICT endptr) {
	_UNUSED(nptr);
	_UNUSED(endptr);

	/* TODO(eteran): implement this */
	return 0;
}

#endif
