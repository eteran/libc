
#define _ELIBC_SOURCE
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief This function is called when an assertion fails. It prints the
 * expression that failed, the file and line number where the failure
 * occurred, and the function name (if available). After printing this
 * information, it calls abort() to terminate the program.
 *
 * @param expr The expression that failed.
 * @param file The name of the file where the failure occurred.
 * @param line The line number where the failure occurred.
 * @param func The name of the function where the failure occurred (if available).
 */
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
