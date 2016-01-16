
#define __ELIBC_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

/*------------------------------------------------------------------------------
// Name: __assert_fail
//----------------------------------------------------------------------------*/
void __assert_fail(const char *expr, const char *file, unsigned int line, const char *func) {

	if(func) {
		fprintf(
			stderr,
			"%s:%u: %s: Assertion '%s' failed.\n",
			file,
			line,
			func,
			expr
			);
	} else {
		fprintf(
			stderr,
			"%s:%u: Assertion '%s' failed.\n",
			file,
			line,
			expr
			);
	}

	abort();
}
