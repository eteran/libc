
#define __ELIBC_SOURCE
#include <assert.h>
#include <stdint.h>
#include <string.h>

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
// Name: __elibc_memcpy64
//----------------------------------------------------------------------------*/
static void __elibc_memcpy64(uint64_t *_RESTRICT dest, const uint64_t *_RESTRICT src, size_t n) {
	n /= 8;
	while (n--) {
		*dest++ = *src++;
	}
}
#endif

/*------------------------------------------------------------------------------
// Name: __elibc_memcpy32
//----------------------------------------------------------------------------*/
static void __elibc_memcpy32(uint32_t *_RESTRICT dest, const uint32_t *_RESTRICT src, size_t n) {
	n /= 4;
	while (n--) {
		*dest++ = *src++;
	}
}

/*------------------------------------------------------------------------------
// Name: __elibc_memcpy16
//----------------------------------------------------------------------------*/
static void __elibc_memcpy16(uint16_t *_RESTRICT dest, const uint16_t *_RESTRICT src, size_t n) {
	n /= 2;
	while (n--) {
		*dest++ = *src++;
	}
}

/*------------------------------------------------------------------------------
// Name: __elibc_memcpy8
//----------------------------------------------------------------------------*/
static void __elibc_memcpy8(uint8_t *_RESTRICT dest, const uint8_t *_RESTRICT src, size_t n) {
	while (n--) {
		*dest++ = *src++;
	}
}
#endif

/*------------------------------------------------------------------------------
// Name: memcpy
//----------------------------------------------------------------------------*/
void *memcpy(void *_RESTRICT dest, const void *_RESTRICT src, size_t n) {

#ifdef NAIVE_VERSION
	/* traditional memory copy */
	char *d_ptr       = dest;
	const char *s_ptr = src;

	assert(dest);
	assert(src);

	while (n--) {
		*d_ptr++ = *s_ptr++;
	}
#else

	/* this one is optimized for dword and word aligned copies */
	union {
		void *ptr;
		uint64_t *ptr64;
		uint32_t *ptr32;
		uint16_t *ptr16;
		uint8_t *ptr8;
	} d_ptr;

	union {
		const void *ptr;
		const uint64_t *ptr64;
		const uint32_t *ptr32;
		const uint16_t *ptr16;
		const uint8_t *ptr8;
	} s_ptr;

	assert(dest);
	assert(src);

	d_ptr.ptr = dest;
	s_ptr.ptr = src;

	switch (n & (MAX_MULTIBYTE - 1)) {
	case 0:
#if MAX_MULTIBYTE >= 2
#if MAX_MULTIBYTE >= 4
#if MAX_MULTIBYTE >= 8
		if (!IS_ALIGNED(d_ptr.ptr64) || !IS_ALIGNED(s_ptr.ptr64)) {
			goto unaligned;
		}

		/* multiple of 8 */
		__elibc_memcpy64(d_ptr.ptr64, s_ptr.ptr64, n);
		break;
	case 4:
#endif
		if (!IS_ALIGNED(d_ptr.ptr32) || !IS_ALIGNED(s_ptr.ptr32)) {
			goto unaligned;
		}

		/* multiple of 4 */
		__elibc_memcpy32(d_ptr.ptr32, s_ptr.ptr32, n);
		break;
	case 6:
	case 2:
#endif
		if (!IS_ALIGNED(d_ptr.ptr16) || !IS_ALIGNED(s_ptr.ptr16)) {
			goto unaligned;
		}

		/* multiple of 2 */
		__elibc_memcpy16(d_ptr.ptr16, s_ptr.ptr16, n);
		break;
	unaligned:
	default:
#endif
		/* multiple of 1 */
		__elibc_memcpy8(d_ptr.ptr8, s_ptr.ptr8, n);
	}
#endif
	return dest;
}
