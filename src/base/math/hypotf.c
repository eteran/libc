
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
 */
_ALWAYS_INLINE _INLINE static float __elibc_hypotf(float x, float y) {
	/* TODO(eteran): check for overflow */
	const float x2 = x * x;
	const float y2 = y * y;
	return sqrtf(x2 + y2);
}

/**
 * @brief Compute the hypotenuse of a right triangle given the lengths of its two sides
 *
 * @param x the length of one side of the triangle
 * @param y the length of the other side of the triangle
 * @return the length of the hypotenuse of the triangle
 */
float hypotf(float x, float y) {
	return __elibc_hypotf(x, y);
}

#endif
