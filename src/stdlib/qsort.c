
#define __ELIBC_SOURCE
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdint.h>

#define ELEMENT_PTR(base, index, size) (void *)(((char *)(base)) + ((index) * (size)))

#define ELEMENT_SWP(base, i, j, size)                                \
do {                                                                 \
	if(i != j) {                                                     \
		unsigned char *const base_ptr1 = ELEMENT_PTR(base, i, size); \
		unsigned char *const base_ptr2 = ELEMENT_PTR(base, j, size); \
		memswp(base_ptr1, base_ptr2, size);                          \
	}                                                                \
} while(0)

/* quick and dirty macro that tests if a pointer is properly aligned to it's
 * native boundary, we need this because some arches (x86) don't like multibyte
 * accesses to cross a page boundary
 */
#define IS_ALIGNED(x) (((uintptr_t)(x) & (sizeof(*(x)) - 1)) == 0)

/* valid options here are, 1, 2, 4 and 8 */
#ifdef __x86_64__
#define MAX_MULTIBYTE 8
#else
#define MAX_MULTIBYTE 4
#endif

#ifdef __OPTIMIZE_SIZE__
#define NAIVE_VERSION
#endif

#ifndef NAIVE_VERSION
#if MAX_MULTIBYTE >= 8
/*------------------------------------------------------------------------------
// Name: __elibc_memswp64
//----------------------------------------------------------------------------*/
static void __elibc_memswp64(uint64_t *_RESTRICT dest, uint64_t *_RESTRICT src, size_t n) {
	n /= 8;
	while(n--) {
		const uint64_t temp = *dest; 
		*dest = *src;
		*src = temp;                     
	
		++dest;
		++src;
	}
}
#endif

/*------------------------------------------------------------------------------
// Name: __elibc_memswp32
//----------------------------------------------------------------------------*/
static void __elibc_memswp32(uint32_t *_RESTRICT dest, uint32_t *_RESTRICT src, size_t n) {
	n /= 4;
	while(n--) {
		const uint32_t temp = *dest; 
		*dest = *src;
		*src = temp;                     
	
		++dest;
		++src;
	}
}

/*------------------------------------------------------------------------------
// Name: __elibc_memswp16
//----------------------------------------------------------------------------*/
static void __elibc_memswp16(uint16_t *_RESTRICT dest, uint16_t *_RESTRICT src, size_t n) {
	n /= 2;
	while(n--) {
		const uint16_t temp = *dest; 
		*dest = *src;
		*src = temp;                     
	
		++dest;
		++src;
	}
}

/*------------------------------------------------------------------------------
// Name: __elibc_memswp8
//----------------------------------------------------------------------------*/
static void __elibc_memswp8(uint8_t *_RESTRICT dest, uint8_t *_RESTRICT src, size_t n) {
	while(n--) {
		const uint8_t temp = *dest; 
		*dest = *src;
		*src = temp;                     
	
		++dest;
		++src;
	}
}
#endif

/*------------------------------------------------------------------------------
// Name: memswp
//----------------------------------------------------------------------------*/
static void *memswp(void *_RESTRICT dest, void *_RESTRICT src, size_t n) {

#ifdef NAIVE_VERSION
    /* traditional version */
	char *d_ptr = dest;
	char *s_ptr = src;

	assert(dest);
	assert(src);

	while(n--) {
        const char temp = *d_ptr;
        *d_ptr = *s_ptr;
        *s_ptr = temp;
	
        ++d_ptr;
        ++s_ptr;
	}
#else

	/* this one is optimized for dword and word aligned copies */
	union {
		void     *ptr;
		uint64_t *ptr64;
		uint32_t *ptr32;
		uint16_t *ptr16;
		uint8_t  *ptr8;
	} d_ptr;

	union {
		void     *ptr;
		uint64_t *ptr64;
		uint32_t *ptr32;
		uint16_t *ptr16;
		uint8_t  *ptr8;
	} s_ptr;

	assert(dest);
	assert(src);

	d_ptr.ptr = dest;
	s_ptr.ptr = src;

	switch(n & (MAX_MULTIBYTE - 1)) {
	case 0:
#if MAX_MULTIBYTE >= 2
#if MAX_MULTIBYTE >= 4
#if MAX_MULTIBYTE >= 8
		if(!IS_ALIGNED(d_ptr.ptr64) || !IS_ALIGNED(s_ptr.ptr64)) {
			goto unaligned;
		}

		/* multiple of 8 */
		__elibc_memswp64(d_ptr.ptr64, s_ptr.ptr64, n);
		break;
	case 4:
#endif
		if(!IS_ALIGNED(d_ptr.ptr32) || !IS_ALIGNED(s_ptr.ptr32)) {
			goto unaligned;
		}

		/* multiple of 4 */
		__elibc_memswp32(d_ptr.ptr32, s_ptr.ptr32, n);
		break;
	case 6:
	case 2:
#endif
		if(!IS_ALIGNED(d_ptr.ptr16) || !IS_ALIGNED(s_ptr.ptr16)) {
			goto unaligned;
		}

		/* multiple of 2 */
		__elibc_memswp16(d_ptr.ptr16, s_ptr.ptr16, n);
		break;
	unaligned:
	default:
#endif
		/* multiple of 1 */
		__elibc_memswp8(d_ptr.ptr8, s_ptr.ptr8, n);
	}
#endif
	return dest;
}

/*------------------------------------------------------------------------------
// Name: __elibc_partition
//----------------------------------------------------------------------------*/
static size_t __elibc_partition(void *base, size_t left, size_t right, size_t size, __compar_fn_t compar) {

	const void *const x = ELEMENT_PTR(base, right, size);
	size_t index = left - 1;
	size_t i;

	assert(base);
	assert(compar);

	for(i = left; i < right; ++i) {
		if(compar(ELEMENT_PTR(base, i, size), x) <= 0) {
			++index;
			ELEMENT_SWP(base, index, i, size);
		}
	}

	ELEMENT_SWP(base, index + 1, right, size);
	return index + 1;
}

/*------------------------------------------------------------------------------
// Name: __elibc_quick_sort
//----------------------------------------------------------------------------*/
static void __elibc_quick_sort(void *base, int l, int r, size_t size, __compar_fn_t compar) {
	assert(base);
	assert(compar);

	if(l < r) {
		const size_t q = __elibc_partition(base, l, r, size, compar);
		__elibc_quick_sort(base, l, q - 1, size, compar);
		__elibc_quick_sort(base, q + 1, r, size, compar);
	}
}

/*------------------------------------------------------------------------------
// Name: qsort
//----------------------------------------------------------------------------*/
void qsort(void *base, size_t nmemb, size_t size, __compar_fn_t compar) {
	assert(base);
	assert(compar);

	if(size != 0) {
		__elibc_quick_sort(base, 0, nmemb - 1, size, compar);
	}
}
