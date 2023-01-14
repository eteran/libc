
#include "heap.hpp"
#include <assert.h>
#include <stdint.h>
#include <string.h>

#ifdef __KERNEL__
#include "Mmu.h"
#include "ScopedLock.h"
#include "Spinlock.h"
#endif

#include "c/_support.h"

namespace heap {
namespace {

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
	static_assert((N & (N - 1)) == 0, "invalid target rounding value");
	return ((value + N - 1) & ~(N - 1));
}

// TODO(eteran): come up with a more clever way to store this data..
//               perhaps do like dlmalloc and have the used flag
//               be the LSb of curr_size (since curr_size is never odd)
//               there is no gain in this though unless we can cleverly
//               deal withe cache_next too
struct heap_data {
public:
	size_t prev_size;
	size_t curr_size;
	size_t used;
	heap_data *cache_next;

public:
	heap_data *next() const { return add_pointer(const_cast<heap_data *>(this), curr_size); }
	heap_data *prev() const { return sub_pointer(const_cast<heap_data *>(this), prev_size); }
	size_t block_size() const { return curr_size - sizeof(heap_data); }

	static heap_data *from_pointer(void *p) { return &static_cast<heap_data *>(p)[-1]; }
	static void *to_pointer(heap_data *p) { return &p[1]; }
};

static_assert(sizeof(heap_data) == 32, "Broken heap data struct");

// when expanding the heap, the amount needed will be rounded up
// to the nearest multiple of this number do help reduce expansions
// in the near future particularly for small allocations
// MUST be a power of 2
// however, the bigger this value is, the more of your maximum brk
// value that can get wasted
#ifdef __KERNEL__
constexpr unsigned int ExpandSlack = Mmu::page_size;
#else
constexpr unsigned int ExpandSlack = 0x1000;
#endif

// this is the minimum block granularity, it also MUST be a power of 2
// recommended values are 8 and 16
constexpr unsigned int Granularity = (sizeof(void *) * 2); // 8 on 32-bit, 16 on 64-bit

// MUST be a multiple of granularity, we should avoid making this too
// big as when enough is in the cache that brk fails, the cache is
// searched for blocks to free to main store.
constexpr unsigned int BiggestToCache = (Granularity * 32); // 256/512 on 32/64 bit

// how many blocks of a given size should we cache
// when possible?
constexpr unsigned int MaxCacheDepth = 16;

#ifdef __KERNEL__
Spinlock heapLock;
#endif

#ifndef NDEBUG
bool initialized = false;
#endif
void *start           = nullptr;
void *end             = nullptr;
heap_data *last_block = nullptr;

struct cache {
	heap_data *entry;
	unsigned int depth;
	uint8_t padding[4];
};

cache blockCache[BiggestToCache / Granularity] = {};

void *brk(size_t incsize) {
	return reinterpret_cast<void *>(__elibc_brk(incsize));
}

void split_block(heap_data *p, size_t size) {

	assert(p);

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
		auto p = static_cast<heap_data *>(start);

		assert(p >= start && p <= end);

		while (p != end) {

			assert(p >= start && p <= end);
			assert(p->used <= 1);

			if (!p->used && p->curr_size >= size) {
				split_block(p, size);
				p->used       = 1;
				p->cache_next = nullptr;
				return heap_data::to_pointer(p);
			}

			p = p->next();
		}

		return nullptr;
	}
};

bool cached_deallocate(void *p) {
	const size_t usable_size = block_size(p) / Granularity;
	if (usable_size < BiggestToCache / Granularity) {

		cache &cache_ptr = blockCache[usable_size];

		if (cache_ptr.depth < MaxCacheDepth) {
			heap_data *const ptr = heap_data::from_pointer(p);
			ptr->cache_next      = cache_ptr.entry;
			cache_ptr.entry      = ptr;
			cache_ptr.depth++;
			return true;
		}
	}
	return false;
}

template <bool use_cache>
void internal_deallocate(void *p) {

	if (p) {
		heap_data *curr = heap_data::from_pointer(p);
		assert(curr->used == 1);

		if (!use_cache || !cached_deallocate(p)) {
			if (curr->used) {

				heap_data *next       = curr->next();
				heap_data *const prev = curr->prev();

				// ok, so if our block is invalid or corrupted
				// then this check should either crash or assert
				// but NEVER continue and potentially corrupt an
				// address of attackers choice
				// assert(next == end || next->prev()->prev() == prev);
				// assert(prev == curr || prev->next()->next() == next);

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

				// update next guys info if necessary
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

	// round needed size up by <expand_slack> so we don't have to do this THAT often
	const size_t size_inc = round_up<ExpandSlack>(size);

	// request the extra space
	void *const new_end = brk(size_inc);

	// did brk work?
	if (new_end && new_end != end) {

		// ok, make the new space look like an allocated block
		const auto new_block = static_cast<heap_data *>(end);
		new_block->curr_size = size_inc;
		new_block->used      = 1;

		// set previous size to based on the last block since we expect to be after it
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
		// the cache that when coalesced with the main free list will be big enough?
		for (size_t i = (BiggestToCache / Granularity) - 1; i > 0; --i) {

			cache &cache_ptr = blockCache[i];

			if (cache_ptr.entry) {
				void *const ptr             = heap_data::to_pointer(cache_ptr.entry);
				cache_ptr.entry->cache_next = nullptr;
				cache_ptr.entry             = cache_ptr.entry->cache_next;
				cache_ptr.depth--;
				internal_deallocate<false>(ptr);

				return true;
			}
		}
	}

	return false;
}

void *cached_allocate(size_t size) {
	void *ret = nullptr;
	size /= Granularity;
	if (size < BiggestToCache / Granularity) {

		cache &cache_ptr = blockCache[size];

		if (cache_ptr.entry) {
			ret                         = heap_data::to_pointer(cache_ptr.entry);
			cache_ptr.entry->cache_next = nullptr;
			cache_ptr.entry             = cache_ptr.entry->cache_next;
			cache_ptr.depth--;
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
	static_assert((sizeof(heap_data) % Granularity) == 0, "invalid heap granularity");

#ifdef __KERNEL__
	// setup the first level of paging for our heap
	// we do this to avoid needing to tweak each
	// processes page structures whenever we grow
	// the heap
	for (uintptr_t i = Mmu::virt_kernel_heap_start; i < Mmu::virt_kernel_heap_end; i += Mmu::first_level_entry_range) {
		Mmu::map_page_1st_level(i);
	}
#endif

#ifndef NDEBUG
	initialized = true;
#endif
}

//-----------------------------------------------------------------------------
// Name: block_size
// Desc: returns the USABLE size of the block pointed to by p, this pointer
//       must have been allocated with allocate
//-----------------------------------------------------------------------------
size_t block_size(void *p) {
	if (p) {
		return heap_data::from_pointer(p)->block_size();
	}
	return 0;
}

//-----------------------------------------------------------------------------
// Name: internal_allocate
// Desc: allocates a block of requests size and returns it or NULL on error
//-----------------------------------------------------------------------------
template <class F>
void *internal_allocate(size_t size, F func) {
	const size_t orig_size = size;

	assert(initialized);

	if (size == 0) {
		++size;
	}

	// round up to nearest granularity
	size = round_up<Granularity>(size);

	// check for overflow
	if (size < orig_size) {
		return nullptr;
	}

	// look for it in the cache first
	void *ret = cached_allocate(size);
	if (!ret) {

		// make room for accounting structures
		size += sizeof(heap_data);

		// check for overflow
		if (size < orig_size) {
			return nullptr;
		}

		do {
			// find a block of sufficient size that is free and return it
			ret = func(size);

			// do we need to extend the heap?
			if (!ret && !extend_heap(size)) {
				// ok, we couldn't satisfy the request, just give up and return NULL
				break;
			}

			// ok, we failed to find a free block, this means just one thing
			// if we got here, that we just tried to extend the heap and succeeded
			// therefore we should try again
			// technically, this loop should run either only 1 or 2 times.
		} while (!ret);
	}

#ifndef NDEBUG
	// for debugging purposes, freshly allocated blocks can be filled
	memset(ret, 0x7e, orig_size);
#endif
	return ret;
}

//-----------------------------------------------------------------------------
// Name: allocate
// Desc: allocates a block of requests size and returns it or NULL on error
//-----------------------------------------------------------------------------
void *allocate(size_t size) {
#ifdef __KERNEL__
	auto lock = make_scoped_lock(&heapLock);
#endif
	void *p = internal_allocate(size, first_fit());
	return p;
}

//-----------------------------------------------------------------------------
// Name: deallocate
// Desc: frees a block back to general storage which was allocated with allocate
//-----------------------------------------------------------------------------
void deallocate(void *p) {
#ifdef __KERNEL__
	auto lock = make_scoped_lock(&heapLock);
#endif
	internal_deallocate<false>(p);
}
}
