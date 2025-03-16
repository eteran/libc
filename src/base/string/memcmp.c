
#define _ELIBC_SOURCE
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

/**
 * @brief Compare the bytes of two blocks of memory (1-byte at a time)
 *
 * @param s1 the first block of memory to compare
 * @param s2 the second block of memory to compare
 * @param n the number of bytes to compare
 * @return 0 if the blocks are equal, a negative value if s1 is less than s2, or a positive value if s1 is greater than s2
 */
_ALWAYS_INLINE _INLINE static int __elibc_memcmp8(const void *s1, const void *s2, size_t n) {
	int ret        = 0;
	const char *p1 = s1;
	const char *p2 = s2;

	while (!ret && n--) {
		ret = (*p1++ - *p2++);
	}

	return ret;
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
	const uint8_t *p1 = s1;
	const uint8_t *p2 = s2;

	while (n >= 4) {
		uint16_t u1 = *(const uint16_t *)p1;
		uint16_t u2 = *(const uint16_t *)p2;
		if (u1 != u2) {
			// If the 2-byte chunks are not equal, compare byte by byte
			for (size_t i = 0; i < 2; ++i) {
				if (p1[i] != p2[i]) {
					return p1[i] - p2[i];
				}
			}
		}
		p1 += 2;
		p2 += 2;
		n -= 2;
	}

	if (n >= 1) {
		return __elibc_memcmp8(p1, p2, n);
	}

	return 0;
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
	const uint8_t *p1 = s1;
	const uint8_t *p2 = s2;

	while (n >= 4) {
		uint32_t u1 = *(const uint32_t *)p1;
		uint32_t u2 = *(const uint32_t *)p2;
		if (u1 != u2) {
			// If the 4-byte chunks are not equal, compare byte by byte
			for (size_t i = 0; i < 4; ++i) {
				if (p1[i] != p2[i]) {
					return p1[i] - p2[i];
				}
			}
		}
		p1 += 4;
		p2 += 4;
		n -= 4;
	}

	if (n >= 2) {
		return __elibc_memcmp16(p1, p2, n);
	}

	if (n >= 1) {
		return __elibc_memcmp8(p1, p2, n);
	}

	return 0;
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
	const uint8_t *p1 = s1;
	const uint8_t *p2 = s2;

	while (n >= 8) {
		uint64_t u1 = *(const uint64_t *)p1;
		uint64_t u2 = *(const uint64_t *)p2;
		if (u1 != u2) {
			// If the 8-byte chunks are not equal, compare byte by byte
			for (size_t i = 0; i < 8; ++i) {
				if (p1[i] != p2[i]) {
					return p1[i] - p2[i];
				}
			}
		}
		p1 += 8;
		p2 += 8;
		n -= 8;
	}

	if (n >= 4) {
		return __elibc_memcmp32(p1, p2, n);
	}

	if (n >= 2) {
		return __elibc_memcmp16(p1, p2, n);
	}

	if (n >= 1) {
		return __elibc_memcmp8(p1, p2, n);
	}

	return 0;
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
	assert(s1);
	assert(s2);
	return __elibc_memcmp8(s1, s2, n);
#else

	/* this one is optimized for dword and word aligned copies */
	union {
		const void *ptr;
		const uint64_t *ptr64;
		const uint32_t *ptr32;
		const uint16_t *ptr16;
		const uint8_t *ptr8;
	} s1_ptr, s2_ptr;

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

	/* compare the remaining bytes */
	return __elibc_memcmp8(s1_ptr.ptr8, s2_ptr.ptr8, n);
#endif
}
