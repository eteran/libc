
#ifndef HEAP_20080313_H_
#define HEAP_20080313_H_

#include <stddef.h>

namespace heap {
	void init();
	void *allocate(size_t size);
	void deallocate(void *p);
	size_t block_size(void *p);
}

#endif
