
#define _ELIBC_SOURCE
#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/* quick and dirty macro that tests if a pointer is properly aligned to it's
 * native boundary
 */
#define IS_ALIGNED(x) (((uintptr_t)(x) & (sizeof(*(x)) - 1)) == 0)

#ifdef __OPTIMIZE_SIZE__
#define NAIVE_VERSION
#endif

/**
 * @brief Compare the bytes of two blocks of memory (1-byte at a time)
 *
 * @param s1 the first block of memory to compare
 * @param s2 the second block of memory to compare
 * @param n the number of bytes to compare
 * @return 0 if the blocks are equal, a negative value if s1 is less than s2, or a positive value if s1 is greater than s2
 */
_ALWAYS_INLINE _INLINE static int __elibc_memcmp8(const void *s1, const void *s2, size_t n) {
	const uint8_t *p1 = s1;
	const uint8_t *p2 = s2;

	while (n >= 1) {
		if (*p1 != *p2) {
			return *p1 - *p2;
		}
		++p1;
		++p2;
		n -= sizeof(uint8_t);
	}

	return 0;
}

#ifndef NAIVE_VERSION

#if _MAX_MULTIBYTE >= 2
/**
 * @brief Compare the bytes of two blocks of memory (2-bytes at a time)
 *
 * @param s1 the first block of memory to compare
 * @param s2 the second block of memory to compare
 * @param n the number of bytes to compare
 * @return 0 if the blocks are equal, a negative value if s1 is less than s2, or a positive value if s1 is greater than s2
 */
_ALWAYS_INLINE _INLINE static int __elibc_memcmp16(const void *s1, const void *s2, size_t n) {
	const uint16_t *p1 = s1;
	const uint16_t *p2 = s2;

	while (n >= 2) {
		if (*p1 != *p2) {
			return __elibc_memcmp8(p1, p2, sizeof(uint16_t));
		}
		++p1;
		++p2;
		n -= sizeof(uint16_t);
	}

	return __elibc_memcmp8(p1, p2, n);
}
#endif

#if _MAX_MULTIBYTE >= 4
/**
 * @brief Compare the bytes of two blocks of memory (4-bytes at a time)
 *
 * @param s1 the first block of memory to compare
 * @param s2 the second block of memory to compare
 * @param n the number of bytes to compare
 * @return 0 if the blocks are equal, a negative value if s1 is less than s2, or a positive value if s1 is greater than s2
 */
_ALWAYS_INLINE _INLINE static int __elibc_memcmp32(const void *s1, const void *s2, size_t n) {
	const uint32_t *p1 = s1;
	const uint32_t *p2 = s2;

	while (n >= 4) {
		if (*p1 != *p2) {
			return __elibc_memcmp8(p1, p2, sizeof(uint32_t));
		}
		++p1;
		++p2;
		n -= sizeof(uint32_t);
	}

	return __elibc_memcmp16(p1, p2, n);
}
#endif

#if _MAX_MULTIBYTE >= 8
/**
 * @brief Compare the bytes of two blocks of memory (8-bytes at a time)
 *
 * @param s1 the first block of memory to compare
 * @param s2 the second block of memory to compare
 * @param n the number of bytes to compare
 * @return 0 if the blocks are equal, a negative value if s1 is less than s2, or a positive value if s1 is greater than s2
 */
_ALWAYS_INLINE _INLINE static int __elibc_memcmp64(const void *s1, const void *s2, size_t n) {

	const uint64_t *p1 = s1;
	const uint64_t *p2 = s2;

	while (n >= 8) {
		if (*p1 != *p2) {
			return __elibc_memcmp8(p1, p2, sizeof(uint64_t));
		}
		++p1;
		++p2;
		n -= sizeof(uint64_t);
	}

	return __elibc_memcmp32(p1, p2, n);
}
#endif

#endif

/**
 * @brief Compare the bytes of two blocks of memory
 *
 * @param s1 the first block of memory to compare
 * @param s2 the second block of memory to compare
 * @param n the number of bytes to compare
 * @return 0 if the blocks are equal, a negative value if s1 is less than s2, or a positive value if s1 is greater than s2
 */
int memcmp(const void *s1, const void *s2, size_t n) {
#ifdef NAIVE_VERSION
	if (n == 0) {
		return 0;
	}

	assert(s1);
	assert(s2);
	return __elibc_memcmp8(s1, s2, n);
#else

	union {
		const void *ptr;
		const uint64_t *ptr64;
		const uint32_t *ptr32;
		const uint16_t *ptr16;
		const uint8_t *ptr8;
	} s1_ptr, s2_ptr;

	if (n == 0) {
		return 0;
	}

	assert(s1);
	assert(s2);

	s1_ptr.ptr = s1;
	s2_ptr.ptr = s2;

#if _MAX_MULTIBYTE >= 8
	if (n >= 8 && (IS_ALIGNED(s1_ptr.ptr64) && IS_ALIGNED(s2_ptr.ptr64))) {
		return __elibc_memcmp64(s1, s2, n);
	}
#endif

#if _MAX_MULTIBYTE >= 4
	if (n >= 4 && (IS_ALIGNED(s1_ptr.ptr32) && IS_ALIGNED(s2_ptr.ptr32))) {
		return __elibc_memcmp32(s1, s2, n);
	}
#endif

#if _MAX_MULTIBYTE >= 2
	if (n >= 2 && (IS_ALIGNED(s1_ptr.ptr16) && IS_ALIGNED(s2_ptr.ptr16))) {
		return __elibc_memcmp16(s1, s2, n);
	}
#endif

	return __elibc_memcmp8(s1_ptr.ptr8, s2_ptr.ptr8, n);
#endif
}
