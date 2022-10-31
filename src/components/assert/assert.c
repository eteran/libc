
#define _ELIBC_SOURCE
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/*------------------------------------------------------------------------------
// Name: __assert_fail
//----------------------------------------------------------------------------*/
void __assert_fail(const char *expr, const char *file, const char *line, const char *func) {

	if (func) {
		fputs(file, stderr);
		fputs(":", stderr);
		fputs(line, stderr);
		fputs(": ", stderr);
		fputs(func, stderr);
		fputs(": Assertion '", stderr);
		fputs(expr, stderr);
		fputs("' failed.\n", stderr);
	} else {
		fputs(file, stderr);
		fputs(":", stderr);
		fputs(line, stderr);
		fputs(": Assertion '", stderr);
		fputs(expr, stderr);
		fputs("' failed.\n", stderr);
	}

	abort();
}
