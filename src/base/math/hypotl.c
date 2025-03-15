
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Compute the hypotenuse of a right triangle given the lengths of its two sides
 *
 * @param x the length of one side of the triangle
 * @param y the length of the other side of the triangle
 * @return the length of the hypotenuse of the triangle
 * @note This function does not handle special cases such as NaN or infinity
 *       gracefully.
 */
_ALWAYS_INLINE _INLINE static long double __elibc_hypotl(long double x, long double y) {
	/* TODO(eteran): check for overflow */
	const long double x2 = x * x;
	const long double y2 = y * y;
	return sqrtl(x2 + y2);
}

/**
 * @brief Compute the hypotenuse of a right triangle given the lengths of its two sides
 *
 * @param x the length of one side of the triangle
 * @param y the length of the other side of the triangle
 * @return the length of the hypotenuse of the triangle
 */
long double hypotl(long double x, long double y) {
	return __elibc_hypotl(x, y);
}

#endif
