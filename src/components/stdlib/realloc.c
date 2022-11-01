
#define _ELIBC_SOURCE
#include "c/_support.h"
#include <stdlib.h>
#include <string.h>

/*------------------------------------------------------------------------------
// Name: realloc
//----------------------------------------------------------------------------*/
void *realloc(void *ptr, size_t size) {
	if (size == 0) {
		/* a call with size == 0 and ptr != NULL is same as free */
		free(ptr);
		return 0;
	}

	if (!ptr) {
		/* if ptr is NULL, the call is equivalent to malloc(size) */
		return malloc(size);
	}

	{
		void *ret = ptr;
		const size_t orig_size = __elibc_size(ptr);

		/* if we are making the block bigger, time to grow */
		if (size > orig_size) {

			void *const new_ptr = malloc(size);
			if (new_ptr) {
				memcpy(new_ptr, ptr, orig_size);
				ret = new_ptr;
				free(ptr);
			}
		}

		return ret;
	}
}
