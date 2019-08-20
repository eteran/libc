
#define __ELIBC_SOURCE
#include <math.h>
#include <assert.h>

/*------------------------------------------------------------------------------
// Name: modf
//----------------------------------------------------------------------------*/
double modf(double x, double *iptr) {

	int sign = 1;
	double i_portion;
	double f_portion;

	assert(iptr);

	if(x < 0) {
		x = -x;
		sign = -1;
	}

	i_portion = floor(x);
	f_portion = x - i_portion;

	*iptr = (i_portion * sign);
	return f_portion * sign;;
}
