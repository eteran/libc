
#include "heap.h"
#include <assert.h>
#include <string.h>

#ifdef __KERNEL__
#include "SystemLock.h"
#include "AutoLock.h"
#include "mmu.h"
#endif

#include "c/_support.h"


namespace heap {
	namespace detail {

		template <class T>
		inline T *add_pointer(T *p, size_t n) {
			return reinterpret_cast<T *>(reinterpret_cast<char *>(p) + n);
		}

		template <class T>
		inline T *sub_pointer(T *p, size_t n) {
			return reinterpret_cast<T *>(reinterpret_cast<char *>(p) - n);
		}

		// NOTE: N must be a power of 2
		template <int N, class T>
		inline T round_up(T value) {

        #if defined(__GXX_EXPERIMENTAL_CXX0X__) || (__cplusplus > 199711L)
			static_assert((N & (N - 1)) == 0, "invalid target rounding value");
		#else
			assert((N & (N - 1)) == 0);
        #endif
			return ((value + N - 1) & ~(N - 1));
		}

		// TODO: come up with a more clever way to store this data..
		// TODO: perhaps do like dlmalloc and have the used flag
		//       be the LSB of curr_size (since curr_size is never odd)
		//       there is no gain in this though unless we can cleverly
		//       deal withe cache_next too
		struct heap_data {
		public:
			size_t		prev_size;
			size_t		curr_size;
			size_t		used;
			heap_data	*cache_next;

		public:
			heap_data *next() const		{ return add_pointer(const_cast<heap_data *>(this), curr_size); }
			heap_data *prev() const		{ return sub_pointer(const_cast<heap_data *>(this), prev_size); }
			size_t block_size() const	{ return curr_size - sizeof(heap_data); }

			static heap_data *from_pointer(void *p)	{ return &static_cast<heap_data *>(p)[-1]; }
			static void *to_pointer(heap_data *p)	{ return &p[1]; }
		};

		// when expanding the heap, the amount needed will be rounded up
		// to the nearest multiple of this number do help reduce expansions
		// in the near future particularly for small allocations
		// MUST be a power of 2
		// however, the bigger this value is, the more of your maximum brk
		// value that can get wasted
#ifdef __KERNEL__
		static const unsigned int expand_slack = mmu::page_size;
#else
		static const unsigned int expand_slack = 0x1000;
#endif

		// this is the minimum block granularity, it also MUST be a power of 2
		// recommended values are 8 and 16
		static const unsigned int granularity = (sizeof(void *) * 2); // 8 on 32-bit, 16 on 64-bit

		// MUST be a multiple of granularity, we should avoid making this too
		// big as when enough is in the cache that brk fails, the cache is
		// searched for blocks to free to main store.
		static const unsigned int biggest_to_cache = (granularity * 32); // 256/512 on 32/64 bit

		// how many blocks of a given size should we cache
		// when possible?
		static const unsigned int max_cache_depth = 16;

		#ifndef NDEBUG
		bool		initialized		= false;
		#endif
		void		*start			= 0;
		void		*end			= 0;
		heap_data	*last_block		= 0;

		struct cache {
			heap_data		*entry;
			unsigned int	depth;
		} block_cache[biggest_to_cache / granularity] = {};
	}

	namespace {

		void *brk(size_t incsize) {
			return reinterpret_cast<void *>(__elibc_brk(incsize));
		}

		void split_block(detail::heap_data *p, size_t size) {
			if(p->curr_size - size >= sizeof(detail::heap_data) + detail::granularity) {
				// split the block up!
				const size_t size1 = size;
				const size_t size2 = p->curr_size - size;

				detail::heap_data *const p2 = add_pointer(p, size1);

				p->curr_size = size1;

				p2->prev_size = size1;
				p2->curr_size = size2;
				p2->used = 0;

				if(detail::last_block == p) {
					detail::last_block = p2;
				}

				if(p2 != detail::last_block) {
					p2->next()->prev_size = size2;
				}
			}
		}

		void *first_fit(size_t size) {
			detail::heap_data *p = static_cast<detail::heap_data *>(detail::start);
			while(p != detail::end) {
				if(!p->used && p->curr_size >= size) {
					split_block(p, size);
					p->used			= 1;
					p->cache_next	= 0;
					return detail::heap_data::to_pointer(p);
				}

				p = p->next();
			}

			return 0;
		}

#if 0
		void *best_fit(size_t size) {
			detail::heap_data *p = static_cast<detail::heap_data *>(detail::start);
			detail::heap_data *best = 0;
			while(p != detail::end) {
				if(!p->used && p->curr_size >= size) {
					if(!best || p->curr_size < best->curr_size) {
						best = p;
					}
				}
				p = p->next();
			}

			p = best;

			if(p != detail::end) {
				split_block(p, size);
				p->used			= 1;
				p->cache_next	= 0;
				return detail::heap_data::to_pointer(p);
			}
			return 0;
		}
#endif

		bool cached_deallocate(void *p) {
			const size_t usable_size = block_size(p) / detail::granularity;
			if(usable_size < detail::biggest_to_cache / detail::granularity) {

				detail::cache &cacheptr = detail::block_cache[usable_size];

				if(cacheptr.depth < detail::max_cache_depth) {
					detail::heap_data *const ptr = detail::heap_data::from_pointer(p);
					ptr->cache_next = cacheptr.entry;
					cacheptr.entry = ptr;
					cacheptr.depth++;
					return true;
				}
			}
			return false;
		}

		template <bool use_cache>
		void internal_deallocate(void *p) {
		#ifdef __KERNEL__
			SystemLock system_lock;
			Autolock<SystemLock> lock(&system_lock);
		#endif

			if(p) {
				detail::heap_data *curr = detail::heap_data::from_pointer(p);
				assert(curr->used);

				if(!use_cache || !cached_deallocate(p)) {
					if(curr->used) {

						detail::heap_data *next = curr->next();
						detail::heap_data *prev = curr->prev();

						// ok, so if our block is invalid or corrupted
						// then this check should either crash or assert
						// but NEVER continue and potentially corrupt an
						// address of attackers choice
						assert(next == detail::end || next->prev()->prev() == prev);
						assert(prev == curr || prev->next()->next() == next);

						// mark our block as available
						curr->used = 0;

						// combine with block adjacent to us (forward)
						if(next != detail::end && !next->used) {
							curr->curr_size += next->curr_size;
							next->curr_size = 0;
							next->prev_size = 0;

							// we need to recalculate next since did
							// a forward merge
							next = curr->next();
						}

						// combine with block adjacent to us (backwards)
						if(prev != curr && !prev->used) {
							prev->curr_size += curr->curr_size;
							curr->curr_size = 0;
							curr->prev_size = 0;

							// we need to recalculate the current pointer
							// since we merged backwards
							curr = prev;
						}

						// update "last block" pointer
						if(next == detail::end) {
							detail::last_block = curr;
						}

						// update next guys info if neccessary
						if(next != detail::end && next->used) {
							next->prev_size = curr->curr_size;
						}

					#ifndef NDEBUG
						// for debugging purposes, freshly freed blocks can be filled
						memset(detail::heap_data::to_pointer(curr), 0x7f, curr->block_size());
					#endif
					}
				}
			}
		}

		bool extend_heap(size_t size) {
			// if we can ask for less because the last block is unused, then do that!
			if(detail::last_block && !detail::last_block->used) {
				size -= detail::last_block->curr_size;
			}

			// round needed size up by <detail::expand_slack> so we don't have to do this THAT often
			const size_t size_inc = detail::round_up<detail::expand_slack>(size);

			// request the extra space
			void *const new_end = brk(size_inc);

			// did brk work?
			if(new_end && new_end != detail::end) {

				// ok, make the new space look like an allocated block
				detail::heap_data *const new_block = static_cast<detail::heap_data *>(detail::end);
				new_block->curr_size	= size_inc;
				new_block->used			= 1;

				// set previous size to based on the lastblock since we expect to be after it
				new_block->prev_size = detail::last_block ? detail::last_block->curr_size : 0;

				// adjust the end pointer
				detail::end = new_end;

				// "deallocate" our new block so it's available for usage
				// we also want to bypass the cache so the block is more
				// readily available for general allocation
				internal_deallocate<false>(detail::heap_data::to_pointer(new_block));
				return true;
			} else {

				// ok, brk failed, perhaps as a last ditch effort, we can find something in
				// the cache that when coalleced with the main free list will be big enough?
				for(size_t i = (detail::biggest_to_cache / detail::granularity) - 1; i > 0; --i) {

					detail::cache &cacheptr = detail::block_cache[i];

					if(cacheptr.entry) {
						void *const ptr = detail::heap_data::to_pointer(cacheptr.entry);
						cacheptr.entry->cache_next = 0;
						cacheptr.entry = cacheptr.entry->cache_next;
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
			size /= detail::granularity;
			if(size < detail::biggest_to_cache / detail::granularity) {

				detail::cache &cacheptr = detail::block_cache[size];

				if(cacheptr.entry) {
					ret = detail::heap_data::to_pointer(cacheptr.entry);
					cacheptr.entry->cache_next = 0;
					cacheptr.entry = cacheptr.entry->cache_next;
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
		detail::start = detail::end = brk(0);

		// the cache depends on this fact..
	#if defined(__GXX_EXPERIMENTAL_CXX0X__) || (__cplusplus > 199711L)
		static_assert((sizeof(detail::heap_data) % detail::granularity) == 0, "invalid heap granularity");
	#else
		assert((sizeof(detail::heap_data) % detail::granularity) == 0);
	#endif

	#ifdef __KERNEL__
		// setup the first level of paging for our heap
		// we do this to avoid needing to tweak each
		// processes page structures whenever we grow
		// the heap

		for(uintptr_t i = mmu::virt_kernel_heap_start; i < mmu::virt_kernel_heap_end; i += mmu::page_size) {
			mmu::map_page_1st_level(i);
		}
	#endif

	#ifndef NDEBUG
		detail::initialized = true;
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
		Autolock<SystemLock> lock(&system_lock);
	#endif

		if(p) {
			return detail::heap_data::from_pointer(p)->block_size();
		}
		return 0;
	}

	//-----------------------------------------------------------------------------
	// Name: internal_allocate
	// Desc: allocates a block of requests size and returns it or NULL on error
	// Note: this will also return NULL for blocks of size 0
	//-----------------------------------------------------------------------------

	template <void *(*F)(size_t size)>
	void *internal_allocate(size_t size) {
	#ifdef __KERNEL__
		SystemLock system_lock;
		Autolock<SystemLock> lock(&system_lock);
	#endif

		const size_t orig_size = size;

		assert(detail::initialized);

		if(size == 0) {
			++size;
		}

		// round up to nearest granularity
		size = detail::round_up<detail::granularity>(size);

		// check for overflow
		if(size < orig_size) {
			return 0;
		}


		// look for it in the cache first
		void *ret = cached_allocate(size);
		if(!ret) {

			// make room for accounting structures
			size += sizeof(detail::heap_data);

			// check for overflow
			if(size < orig_size) {
				return 0;
			}

			do {
				// find a block of sufficient size that is free and return it
				ret = F(size);

				// do we need to extend the heap?
				if(ret == 0 && !extend_heap(size)) {
					// ok, we couldn't satify the request, just give up and return NULL
					break;
				}

				// ok, we failed to find a free block, this means just one thing
				// if we got here, that we just tried to extend the heap and succeeded
				// therefore we should try again
				// technically, this loop should run either only 1 or 2 times.
			} while(!ret);
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
		return internal_allocate<first_fit>(size);
	}

	//-----------------------------------------------------------------------------
	// Name: deallocate
	// Desc: frees a block back to general storage which was allocated with allocate
	//-----------------------------------------------------------------------------
	void deallocate(void *p) {
		internal_deallocate<true>(p);
	}
}
