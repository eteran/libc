/* 100% Coverage */

#undef NDEBUG
#define _ELIBC_SOURCE
#include <assert.h>
#include <stdnoreturn.h>

int main(void) {

#ifndef noreturn
#error noreturn is not defined
#endif

	return 0;
}
