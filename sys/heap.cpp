
#include "heap.hpp"
#include <assert.h>
#include <string.h>

#ifdef __KERNEL__
#include "MMU.h"
#include "ScopedLock.h"
#include "SystemLock.h"
#endif

#include "c/_support.h"

#if __cplusplus > 199711L
#define CONSTEXPR11 constexpr
#else
#define CONSTEXPR11
#endif

namespace heap {
namespace {

struct heap_data;

// when expanding the heap, the amount needed will be rounded up
// to the nearest multiple of this number do help reduce expansions
// in the near future particularly for small allocations
// MUST be a power of 2
// however, the bigger this value is, the more of your maximum brk
// value that can get wasted
#ifdef __KERNEL__
CONSTEXPR11 const unsigned int ExpandSlack = MMU::page_size;
#else
CONSTEXPR11 const unsigned int ExpandSlack = 0x1000;
#endif

// this is the minimum block granularity, it also MUST be a power of 2
// recommended values are 8 and 16
CONSTEXPR11 const unsigned int Granularity = (sizeof(void *) * 2); // 8 on 32-bit, 16 on 64-bit

// MUST be a multiple of granularity, we should avoid making this too
// big as when enough is in the cache that brk fails, the cache is
// searched for blocks to free to main store.
CONSTEXPR11 const unsigned int BiggestToCache = (Granularity * 32); // 256/512 on 32/64 bit

// how many blocks of a given size should we cache
// when possible?
CONSTEXPR11 const unsigned int MaxCacheDepth = 16;

#ifndef NDEBUG
bool initialized = false;
#endif
void *     start      = 0;
void *     end        = 0;
heap_data *last_block = 0;

template <class T>
T *add_pointer(T *p, size_t n) {
	return reinterpret_cast<T *>(reinterpret_cast<char *>(p) + n);
}

template <class T>
T *sub_pointer(T *p, size_t n) {
	return reinterpret_cast<T *>(reinterpret_cast<char *>(p) - n);
}

// NOTE(eteran): N must be a power of 2
template <int N, class T>
T round_up(T value) {
#if defined(__GXX_EXPERIMENTAL_CXX0X__) || (__cplusplus > 199711L)
	static_assert((N & (N - 1)) == 0, "invalid target rounding value");
#else
	assert((N & (N - 1)) == 0);
#endif
	return ((value + N - 1) & ~(N - 1));
}

// TODO(eteran): come up with a more clever way to store this data..
// TODO(eteran): perhaps do like dlmalloc and have the used flag
//       be the LSB of curr_size (since curr_size is never odd)
//       there is no gain in this though unless we can cleverly
//       deal withe cache_next too
struct heap_data {
public:
	size_t     prev_size;
	size_t     curr_size;
	size_t     used;
	heap_data *cache_next;

public:
	heap_data *next() const { return add_pointer(const_cast<heap_data *>(this), curr_size); }
	heap_data *prev() const { return sub_pointer(const_cast<heap_data *>(this), prev_size); }
	size_t     block_size() const { return curr_size - sizeof(heap_data); }

	static heap_data *from_pointer(void *p) { return &static_cast<heap_data *>(p)[-1]; }
	static void *     to_pointer(heap_data *p) { return &p[1]; }
};

struct cache {
	heap_data *  entry;
	size_t depth;
} block_cache[BiggestToCache / Granularity] = {};

void *brk(size_t incsize) {
	return reinterpret_cast<void *>(__elibc_brk(incsize));
}

void split_block(heap_data *p, size_t size) {
	if (p->curr_size - size >= sizeof(heap_data) + Granularity) {
		// split the block up!
		const size_t size1 = size;
		const size_t size2 = p->curr_size - size;

		heap_data *const p2 = add_pointer(p, size1);

		p->curr_size = size1;

		p2->prev_size = size1;
		p2->curr_size = size2;
		p2->used      = 0;

		if (last_block == p) {
			last_block = p2;
		}

		if (p2 != last_block) {
			p2->next()->prev_size = size2;
		}
	}
}

struct first_fit {
	void *operator()(size_t size) const {
		heap_data *p = static_cast<heap_data *>(start);
		while (p != end) {
			if (!p->used && p->curr_size >= size) {
				split_block(p, size);
				p->used       = 1;
				p->cache_next = 0;
				return heap_data::to_pointer(p);
			}

			p = p->next();
		}

		return 0;
	}
};

bool cached_deallocate(void *p) {
	const size_t usable_size = block_size(p) / Granularity;
	if (usable_size < BiggestToCache / Granularity) {

		cache &cacheptr = block_cache[usable_size];

		if (cacheptr.depth < MaxCacheDepth) {
			heap_data *const ptr = heap_data::from_pointer(p);
			ptr->cache_next      = cacheptr.entry;
			cacheptr.entry       = ptr;
			cacheptr.depth++;
			return true;
		}
	}
	return false;
}

template <bool UseCache>
void internal_deallocate(void *p) {
#ifdef __KERNEL__
	SystemLock system_lock;
	auto       lock = make_scoped_lock(&system_lock);
#endif

	if (p) {
		heap_data *curr = heap_data::from_pointer(p);
		assert(curr->used);

		if (!UseCache || !cached_deallocate(p)) {
			if (curr->used) {

				heap_data *next = curr->next();
				heap_data *prev = curr->prev();

				// ok, so if our block is invalid or corrupted
				// then this check should either crash or assert
				// but NEVER continue and potentially corrupt an
				// address of attackers choice
				assert(next == end || next->prev()->prev() == prev);
				assert(prev == curr || prev->next()->next() == next);

				// mark our block as available
				curr->used = 0;

				// combine with block adjacent to us (forward)
				if (next != end && !next->used) {
					curr->curr_size += next->curr_size;
					next->curr_size = 0;
					next->prev_size = 0;

					// we need to recalculate next since did
					// a forward merge
					next = curr->next();
				}

				// combine with block adjacent to us (backwards)
				if (prev != curr && !prev->used) {
					prev->curr_size += curr->curr_size;
					curr->curr_size = 0;
					curr->prev_size = 0;

					// we need to recalculate the current pointer
					// since we merged backwards
					curr = prev;
				}

				// update "last block" pointer
				if (next == end) {
					last_block = curr;
				}

				// update next guys info if neccessary
				if (next != end && next->used) {
					next->prev_size = curr->curr_size;
				}

#ifndef NDEBUG
				// for debugging purposes, freshly freed blocks can be filled
				memset(heap_data::to_pointer(curr), 0x7f, curr->block_size());
#endif
			}
		}
	}
}

bool extend_heap(size_t size) {
	// if we can ask for less because the last block is unused, then do that!
	if (last_block && !last_block->used) {
		size -= last_block->curr_size;
	}

	// round needed size up by <ExpandSlack> so we don't have to do this THAT often
	const size_t size_inc = round_up<ExpandSlack>(size);

	// request the extra space
	void *const new_end = brk(size_inc);

	// did brk work?
	if (new_end && new_end != end) {

		// ok, make the new space look like an allocated block
		heap_data *const new_block = static_cast<heap_data *>(end);
		new_block->curr_size       = size_inc;
		new_block->used            = 1;

		// set previous size to based on the lastblock since we expect to be after it
		new_block->prev_size = last_block ? last_block->curr_size : 0;

		// adjust the end pointer
		end = new_end;

		// "deallocate" our new block so it's available for usage
		// we also want to bypass the cache so the block is more
		// readily available for general allocation
		internal_deallocate<false>(heap_data::to_pointer(new_block));
		return true;
	} else {

		// ok, brk failed, perhaps as a last ditch effort, we can find something in
		// the cache that when coalleced with the main free list will be big enough?
		for (size_t i = (BiggestToCache / Granularity) - 1; i > 0; --i) {

			cache &cacheptr = block_cache[i];

			if (cacheptr.entry) {
				void *const ptr            = heap_data::to_pointer(cacheptr.entry);
				cacheptr.entry->cache_next = 0;
				cacheptr.entry             = cacheptr.entry->cache_next;
				cacheptr.depth--;
				internal_deallocate<false>(ptr);

				return true;
			}
		}
	}

	return false;
}

void *cached_allocate(size_t size) {
	void *ret = 0;
	size /= Granularity;
	if (size < BiggestToCache / Granularity) {

		cache &cacheptr = block_cache[size];

		if (cacheptr.entry) {
			ret                        = heap_data::to_pointer(cacheptr.entry);
			cacheptr.entry->cache_next = 0;
			cacheptr.entry             = cacheptr.entry->cache_next;
			cacheptr.depth--;
		}
	}
	return ret;
}
}

//-----------------------------------------------------------------------------
// Name: init
// Desc: post construction init routine
//-----------------------------------------------------------------------------
void init() {
	start = end = brk(0);

	// the cache depends on this fact..
#if defined(__GXX_EXPERIMENTAL_CXX0X__) || (__cplusplus > 199711L)
	static_assert((sizeof(heap_data) % Granularity) == 0, "invalid heap granularity");
#else
	assert((sizeof(heap_data) % granularity) == 0);
#endif

#ifdef __KERNEL__
	// setup the first level of paging for our heap
	// we do this to avoid needing to tweak each
	// processes page structures whenever we grow
	// the heap

	for (uintptr_t i = MMU::virt_kernel_heap_start; i < MMU::virt_kernel_heap_end; i += MMU::page_size) {
		MMU::map_page_1st_level(i);
	}
#endif

#ifndef NDEBUG
	initialized = true;
#endif
}

//-----------------------------------------------------------------------------
// Name: block_size
// Desc: returns the USABLE size of the block pointed to by p, this pointer
//       must have been allocted with allocate
//-----------------------------------------------------------------------------
size_t block_size(void *p) {
#ifdef __KERNEL__
	SystemLock system_lock;
	auto       lock = make_scoped_lock(&system_lock);
#endif

	if (p) {
		return heap_data::from_pointer(p)->block_size();
	}
	return 0;
}

//-----------------------------------------------------------------------------
// Name: internal_allocate
// Desc: allocates a block of requests size and returns it or NULL on error
// Note: this will also return NULL for blocks of size 0
//-----------------------------------------------------------------------------
template <class F>
void *internal_allocate(size_t size, F find_block) {
#ifdef __KERNEL__
	SystemLock system_lock;
	auto       lock = make_scoped_lock(&system_lock);
#endif

	const size_t orig_size = size;

	assert(initialized);

	if (size == 0) {
		++size;
	}

	// round up to nearest granularity
	size = round_up<Granularity>(size);

	// check for overflow
	if (size < orig_size) {
		return 0;
	}

	// look for it in the cache first
	void *ret = cached_allocate(size);
	if (!ret) {

		// make room for accounting structures
		size += sizeof(heap_data);

		// check for overflow
		if (size < orig_size) {
			return 0;
		}

		do {
			// find a block of sufficient size that is free and return it
			ret = find_block(size);

			// do we need to extend the heap?
			if (!ret && !extend_heap(size)) {
				// ok, we couldn't satify the request, just give up and return NULL
				break;
			}

			// ok, we failed to find a free block, this means just one thing
			// if we got here, that we just tried to extend the heap and succeeded
			// therefore we should try again
			// technically, this loop should run either only 1 or 2 times.
		} while (!ret);
	}

#ifndef NDEBUG
	// for debugging purposes, freshly freed blocks can be filled
	memset(ret, 0x7e, orig_size);
#endif
	return ret;
}

//-----------------------------------------------------------------------------
// Name: allocate
// Desc: allocates a block of requests size and returns it or NULL on error
// Note: this will also return NULL for blocks of size 0
//-----------------------------------------------------------------------------
void *allocate(size_t size) {
	return internal_allocate(size, first_fit());
}

//-----------------------------------------------------------------------------
// Name: deallocate
// Desc: frees a block back to general storage which was allocated with allocate
//-----------------------------------------------------------------------------
void deallocate(void *p) {
	internal_deallocate<true>(p);
}
}
