#undef NDEBUG
#include <assert.h>
#include <math.h>
#include <stdio.h>

int main() {
#if _HAVE_FPU
	double x = sin(2.0);
	printf("%f\n", x);
#endif
	return 0;
}
