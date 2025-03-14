
#define _ELIBC_SOURCE
#include "c/_support.h"
#include <stdlib.h>

/**
 * @brief Free the memory allocated for an object
 *
 * @param ptr a pointer to the memory to free
 * @note this function frees the memory allocated for an object, performs no operation
 * if ptr is NULL.
 *
 */
void free(void *ptr) {
	__elibc_free(ptr);
}
