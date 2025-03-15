
#define _ELIBC_SOURCE
#include <assert.h>
#include <stdint.h>
#include <string.h>

#define IS_ALIGNED(x) (((uintptr_t)(x) & (sizeof(*(x)) - 1)) == 0)

#ifdef __OPTIMIZE_SIZE__
#define NAIVE_VERSION
#endif

#ifndef NAIVE_VERSION
#if _MAX_MULTIBYTE >= 8

/**
 * @brief Compare the bytes of two blocks of memory (8-bytes at a time)
 *
 * @param s1 the first block of memory to compare
 * @param s2 the second block of memory to compare
 * @param n the number of bytes to compare
 * @return 0 if the blocks are equal, a negative value if s1 is less than s2, or a positive value if s1 is greater than s2
 */
_ALWAYS_INLINE _INLINE static int __elibc_memcmp64(const uint64_t *s1, const uint64_t *s2, size_t n) {
	int ret = 0;

	n /= 8;

	assert(s1);
	assert(s2);

	while (!ret && n--) {
		ret = (*s1++ - *s2++);
	}

	return ret;
}

#endif
#endif

/**
 * @brief Compare the bytes of two blocks of memory (4-bytes at a time)
 *
 * @param s1 the first block of memory to compare
 * @param s2 the second block of memory to compare
 * @param n the number of bytes to compare
 * @return 0 if the blocks are equal, a negative value if s1 is less than s2, or a positive value if s1 is greater than s2
 */
_ALWAYS_INLINE _INLINE static int __elibc_memcmp32(const uint32_t *s1, const uint32_t *s2, size_t n) {
	int ret = 0;

	n /= 4;

	assert(s1);
	assert(s2);

	while (!ret && n--) {
		ret = (*s1++ - *s2++);
	}

	return ret;
}

/**
 * @brief Compare the bytes of two blocks of memory (2-bytes at a time)
 *
 * @param s1 the first block of memory to compare
 * @param s2 the second block of memory to compare
 * @param n the number of bytes to compare
 * @return 0 if the blocks are equal, a negative value if s1 is less than s2, or a positive value if s1 is greater than s2
 */
_ALWAYS_INLINE _INLINE static int __elibc_memcmp16(const uint16_t *s1, const uint16_t *s2, size_t n) {
	int ret = 0;

	n /= 2;

	assert(s1);
	assert(s2);

	while (!ret && n--) {
		ret = (*s1++ - *s2++);
	}

	return ret;
}

/**
 * @brief Compare the bytes of two blocks of memory (1-byte at a time)
 *
 * @param s1 the first block of memory to compare
 * @param s2 the second block of memory to compare
 * @param n the number of bytes to compare
 * @return 0 if the blocks are equal, a negative value if s1 is less than s2, or a positive value if s1 is greater than s2
 */
_ALWAYS_INLINE _INLINE static int __elibc_memcmp8(const uint8_t *s1, const uint8_t *s2, size_t n) {
	int ret = 0;

	assert(s1);
	assert(s2);

	while (!ret && n--) {
		ret = (*s1++ - *s2++);
	}

	return ret;
}

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
	int ret        = 0;
	const char *p1 = s1;
	const char *p2 = s2;

	assert(s1);
	assert(s2);

	while (!ret && n--) {
		ret = (*p1++ - *p2++);
	}

	return ret;
#else
	/* this one is optimized for dword and word aligned copies */
	union {
		const void *ptr;
		const uint64_t *ptr64;
		const uint32_t *ptr32;
		const uint16_t *ptr16;
		const uint8_t *ptr8;
	} d_ptr;

	union {
		const void *ptr;
		const uint64_t *ptr64;
		const uint32_t *ptr32;
		const uint16_t *ptr16;
		const uint8_t *ptr8;
	} s_ptr;

	assert(s1);
	assert(s2);

	d_ptr.ptr = s1;
	s_ptr.ptr = s2;

	switch (n & (_MAX_MULTIBYTE - 1)) {
	case 0:
#if _MAX_MULTIBYTE >= 2
#if _MAX_MULTIBYTE >= 4
#if _MAX_MULTIBYTE >= 8
		if (!IS_ALIGNED(d_ptr.ptr64) || !IS_ALIGNED(s_ptr.ptr64)) {
			goto unaligned;
		}

		/* multiple of 8 */
		return __elibc_memcmp64(d_ptr.ptr64, s_ptr.ptr64, n);
	case 4:
#endif
		if (!IS_ALIGNED(d_ptr.ptr32) || !IS_ALIGNED(s_ptr.ptr32)) {
			goto unaligned;
		}

		/* multiple of 4 */
		return __elibc_memcmp32(d_ptr.ptr32, s_ptr.ptr32, n);
	case 6:
	case 2:
#endif
		if (!IS_ALIGNED(d_ptr.ptr16) || !IS_ALIGNED(s_ptr.ptr16)) {
			goto unaligned;
		}

		/* multiple of 2 */
		return __elibc_memcmp16(d_ptr.ptr16, s_ptr.ptr16, n);
	unaligned:
	default:
#endif
		/* multiple of 1 */
		return __elibc_memcmp8(d_ptr.ptr8, s_ptr.ptr8, n);
	}
#endif
}
