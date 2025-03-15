
#define _ELIBC_SOURCE

#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Return a NaN value
 *
 * @param tagp a pointer to a string that specifies the type of NaN to return
 * @return a NaN value
 */
double nan(const char *tagp) {
	return __builtin_nan(tagp);
}

#endif
