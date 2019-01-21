/*
Cephes Math Library Release 2.8:  June, 2000
Copyright 1985, 1995, 2000 by Stephen L. Moshier
*/

#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*							sin.c
 *
 *	Circular sine
 *
 *
 *
 * SYNOPSIS:
 *
 * double x, y, sin();
 *
 * y = sin( x );
 *
 *
 *
 * DESCRIPTION:
 *
 * Range reduction is into intervals of pi/4.  The reduction
 * error is nearly eliminated by contriving an extended precision
 * modular arithmetic.
 *
 * Two polynomial approximating functions are employed.
 * Between 0 and pi/4 the sine is approximated by
 *      x  +  x**3 P(x**2).
 * Between pi/4 and pi/2 the cosine is represented as
 *      1  -  x**2 Q(x**2).
 *
 *
 * ACCURACY:
 *
 *                      Relative error:
 * arithmetic   domain      # trials      peak         rms
 *    DEC       0, 10       150000       3.0e-17     7.8e-18
 *    IEEE -1.07e9,+1.07e9  130000       2.1e-16     5.4e-17
 *
 * ERROR MESSAGES:
 *
 *   message           condition        value returned
 * sin total loss   x > 1.073741824e9      0.0
 *
 * Partial loss of accuracy begins to occur at x = 2**30
 * = 1.074e9.  The loss is not gradual, but jumps suddenly to
 * about 1 part in 10e7.  Results may be meaningless for
 * x > 2**49 = 5.6e14.  The routine as implemented flags a
 * TLOSS error for x > 2**30 and returns 0.0.
 */
/*							cos.c
 *
 *	Circular cosine
 *
 *
 *
 * SYNOPSIS:
 *
 * double x, y, cos();
 *
 * y = cos( x );
 *
 *
 *
 * DESCRIPTION:
 *
 * Range reduction is into intervals of pi/4.  The reduction
 * error is nearly eliminated by contriving an extended precision
 * modular arithmetic.
 *
 * Two polynomial approximating functions are employed.
 * Between 0 and pi/4 the cosine is approximated by
 *      1  -  x**2 Q(x**2).
 * Between pi/4 and pi/2 the sine is represented as
 *      x  +  x**3 P(x**2).
 *
 *
 * ACCURACY:
 *
 *                      Relative error:
 * arithmetic   domain      # trials      peak         rms
 *    IEEE -1.07e9,+1.07e9  130000       2.1e-16     5.4e-17
 *    DEC        0,+1.07e9   17000       3.0e-17     7.2e-18
 */

/*							sin.c	*/

static const double PIO4 = 7.85398163397448309616E-1; /* pi/4 */

double polevl(double x, const double coef[], int N) {
	
	const double *p  = coef;
	double ans = *p++;
	int i      = N;

	do {
		ans = ans * x + *p++;
	} while (--i);

	return ans;
}

/*							p1evl()	*/
/*                                          N
 * Evaluate polynomial when coefficient of x  is 1.0.
 * Otherwise same as polevl.
 */

double p1evl(double x, const double coef[], int N) {

	const double *p = coef;
	double ans      = x + *p++;
	int i           = N - 1;

	do {
		ans = ans * x + *p++;
	} while (--i);

	return ans;
}

static const double sincof[] = {
     1.58962301576546568060E-10, 
	-2.50507477628578072866E-8, 
	 2.75573136213857245213E-6, 
	-1.98412698295895385996E-4, 
	 8.33333333332211858878E-3, 
	-1.66666666666666307295E-1,
};

static const double coscof[6] = {
    -1.13585365213876817300E-11, 
	 2.08757008419747316778E-9, 
	-2.75573141792967388112E-7, 
	 2.48015872888517045348E-5, 
	-1.38888888888730564116E-3, 
	 4.16666666666665929218E-2,
};

static const double DP1 = 7.85398125648498535156E-1;
static const double DP2 = 3.77489470793079817668E-8;
static const double DP3 = 2.69515142907905952645E-15;

static const double lossth = 1.073741824e9;

/*------------------------------------------------------------------------------
// Name: sin
//----------------------------------------------------------------------------*/
double sin(double x) {
	double y;
	double z;
	double zz;
	int j;
	int sign;

#ifndef __FAST_MATH__
	if (x == 0.0) {
		return x;
	}

	if (isnan(x)) {
		return x;
	}
		
	if (isinf(x)) {
		errno = EDOM;
		return NAN;
	}
#endif

	/* make argument positive but save the sign */
	sign = 1;
	if (x < 0) {
		x    = -x;
		sign = -1;
	}

	if (x > lossth) {
		// mtherr( "sin", TLOSS );
		return 0.0;
	}

	y = floor(x / PIO4); /* integer part of x/PIO4 */
	
	/* strip high bits of integer part to prevent integer overflow */
	z = ldexp(y, -4);
	z = floor(z);        /* integer part of y/8 */
	z = y - ldexp(z, 4); /* y - 16 * (y/16) */

	j = (int)z; /* convert to integer for tests on the phase angle */
	
	/* map zeros to origin */
	if (j & 1) {
		j += 1;
		y += 1.0;
	}
	
	j = j & 07; /* octant modulo 360 degrees */
	
	/* reflect in x axis */
	if (j > 3) {
		sign = -sign;
		j -= 4;
	}

	/* Extended precision modular arithmetic */
	z = ((x - y * DP1) - y * DP2) - y * DP3;

	zz = z * z;

	if ((j == 1) || (j == 2)) {
		y = 1.0 - ldexp(zz, -1) + zz * zz * polevl(zz, coscof, 5);
	} else {
		/*	y = z  +  z * (zz * polevl( zz, sincof, 5 ));*/
		y = z + z * z * z * polevl(zz, sincof, 5);
	}

	if (sign < 0) {
		y = -y;
	}

	return (y);
}
