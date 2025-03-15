
#define _ELIBC_SOURCE
#include "c/_support.h"
#include <errno.h>
#include <stdlib.h>

/**
 * @brief Allocate memory for an object of size size
 *
 * @param size the size of the object to allocate
 * @return a pointer to the allocated memory, or NULL if the allocation fails
 */
void *malloc(size_t size) {
	void *const p = __elibc_malloc(size);
	if (!p && size != 0) {
		errno = ENOMEM;
	}
	return p;
}
