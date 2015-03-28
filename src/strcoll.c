
#define __ELIBC_SOURCE
#include <string.h>
#include <assert.h>

/*------------------------------------------------------------------------------
// Name: strcoll
//----------------------------------------------------------------------------*/
int strcoll(const char *s1, const char *s2) {
	/* TODO: make this locale aware */

	assert(s1);
	assert(s2);

	return strcmp(s1, s2);
}
