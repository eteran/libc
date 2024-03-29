
#define _ELIBC_SOURCE
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/*------------------------------------------------------------------------------
// Name: __assert_fail
//----------------------------------------------------------------------------*/
void __assert_fail(const char *expr, const char *file, const char *line, const char *func) {
	/* NOTE(eteran): we use a series of fputs instead of the easier printf because we
	 * want to be able to call this from printf itself
	 */
	fputs(file, stderr);
	fputs(":", stderr);
	fputs(line, stderr);

	if (func) {
		fputs(": ", stderr);
		fputs(func, stderr);
	}

	fputs(": Assertion '", stderr);
	fputs(expr, stderr);
	fputs("' failed.\n", stderr);

	abort();
}
