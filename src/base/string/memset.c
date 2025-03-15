
#define _ELIBC_SOURCE
#define __STDC_CONSTANT_MACROS
#include <assert.h>
#include <stdint.h>
#include <string.h>

/* quick and dirty macro that tests if a pointer is properly aligned to it's
 * native boundary, we need this because some arches (x86) don't like multibyte
 * accesses to cross a page boundary
 */
#define IS_ALIGNED(x) (((uintptr_t)(x) & (sizeof(*(x)) - 1)) == 0)

#ifdef __OPTIMIZE_SIZE__
#define NAIVE_VERSION
#endif

#ifndef NAIVE_VERSION
#if _MAX_MULTIBYTE >= 8

/**
 * @brief Set the bytes of a block of memory to a specified value (8-bytes at a time)
 *
 * @param p a pointer to the block of memory to be set
 * @param ch the value to set the memory to
 * @param n the number of bytes to set
 */
_ALWAYS_INLINE _INLINE static void __elibc_memset64(uint64_t *p, char ch, size_t n) {
	const uint64_t source = (uint8_t)ch * UINT64_C(0x0101010101010101);
	n /= 8;
	while (n--) {
		*p++ = source;
	}
}
#endif

/**
 * @brief Set the bytes of a block of memory to a specified value (4-bytes at a time)
 *
 * @param p a pointer to the block of memory to be set
 * @param ch the value to set the memory to
 * @param n the number of bytes to set
 */
_ALWAYS_INLINE _INLINE static void __elibc_memset32(uint32_t *p, char ch, size_t n) {
	const uint32_t source = ((uint8_t)ch * UINT32_C(0x01010101));
	n /= 4;
	while (n--) {
		*p++ = source;
	}
}

/**
 * @brief Set the bytes of a block of memory to a specified value (2-bytes at a time)
 *
 * @param p a pointer to the block of memory to be set
 * @param ch the value to set the memory to
 * @param n the number of bytes to set
 */
_ALWAYS_INLINE _INLINE static void __elibc_memset16(uint16_t *p, char ch, size_t n) {
	const uint16_t source = (uint16_t)((uint8_t)ch * UINT16_C(0x0101));
	n /= 2;
	while (n--) {
		*p++ = source;
	}
}

/**
 * @brief Set the bytes of a block of memory to a specified value (1-byte at a time)
 *
 * @param p a pointer to the block of memory to be set
 * @param ch the value to set the memory to
 * @param n the number of bytes to set
 */
_ALWAYS_INLINE _INLINE static void __elibc_memset8(uint8_t *p, char ch, size_t n) {
	while (n--) {
		*p++ = (uint8_t)ch;
	}
}
#endif

/**
 * @brief Set the bytes of a block of memory to a specified value
 *
 * @param s a pointer to the block of memory to be set
 * @param c the value to set the memory to
 * @param n the number of bytes to set
 * @return a pointer to the block of memory that was set
 */
void *memset(void *s, int c, size_t n) {

#ifdef NAIVE_VERSION
	/* traditional memset */
	char *s_ptr   = s;
	const char ch = (char)(c & 0xff);

	assert(s);

	while (n--) {
		*s_ptr++ = ch;
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

	const char ch = (char)(c & 0xff);

	assert(s);

	d_ptr.ptr = s;

	switch (n & (_MAX_MULTIBYTE - 1)) {
	case 0:
#if _MAX_MULTIBYTE >= 2
#if _MAX_MULTIBYTE >= 4
#if _MAX_MULTIBYTE >= 8
		if (!IS_ALIGNED(d_ptr.ptr64)) {
			goto unaligned;
		}

		/* multiple of 8 */
		__elibc_memset64(d_ptr.ptr64, ch, n);
		break;
	case 4:
#endif
		if (!IS_ALIGNED(d_ptr.ptr32)) {
			goto unaligned;
		}

		/* multiple of 4 */
		__elibc_memset32(d_ptr.ptr32, ch, n);
		break;
	case 6:
	case 2:
#endif
		if (!IS_ALIGNED(d_ptr.ptr16)) {
			goto unaligned;
		}

		/* multiple of 2 */
		__elibc_memset16(d_ptr.ptr16, ch, n);
		break;
	unaligned:
	default:
#endif
		/* multiple of 1 */
		__elibc_memset8(d_ptr.ptr8, ch, n);
	}
#endif
	return s;
}
