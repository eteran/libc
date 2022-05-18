
#define _ELIBC_SOURCE
#include <assert.h>
#include <string.h>

/*------------------------------------------------------------------------------
// Name: strcoll
//----------------------------------------------------------------------------*/
int strcoll(const char *s1, const char *s2) {
	/* TODO(eteran): make this locale aware */

	assert(s1);
	assert(s2);

	return strcmp(s1, s2);
}
