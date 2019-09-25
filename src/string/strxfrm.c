
#define __ELIBC_SOURCE
#include <string.h>
#include <assert.h>

/*------------------------------------------------------------------------------
// Name: strxfrm
//----------------------------------------------------------------------------*/
size_t strxfrm(char *_RESTRICT dest, const char *_RESTRICT src, size_t n) {

	assert(dest);
	assert(src);

	/* in the "POSIX" or "C" locales strxfrm() is equivalent
	 * to copying the string  with strncpy().
	 */

	/* NOTE: I've seen at least one source that says strncpy isn't correct here
	 * because the zero filling nature of strncpy isn't in the strxfrm spec
	 */

	/* TODO(eteran): be locale aware */

	strncpy(dest, src, n);
	dest[n - 1] = '\0';
	return strlen(dest);
}
