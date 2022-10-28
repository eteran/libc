
#define _ELIBC_SOURCE
#include <assert.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: __elibc_modf
//----------------------------------------------------------------------------*/
_ALWAYS_INLINE _INLINE static double __elibc_modf(double arg, double *iptr) {
	int sign = 1;
	double i_portion;
	double f_portion;

	assert(iptr);

	if (arg < 0) {
		arg = -arg;
		sign = -1;
	}

	i_portion = floor(arg);
	f_portion = arg - i_portion;

	*iptr = (i_portion * sign);
	return f_portion * sign;
}

/*------------------------------------------------------------------------------
// Name: modf
//----------------------------------------------------------------------------*/
double modf(double arg, double *iptr) {
	return __elibc_modf(arg, iptr);
}

#endif
