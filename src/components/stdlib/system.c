
#define _ELIBC_SOURCE
#include "c/_support.h"

/*------------------------------------------------------------------------------
// Name: system
//----------------------------------------------------------------------------*/
int system(const char *command) {
	return __elibc_system(command);
}
