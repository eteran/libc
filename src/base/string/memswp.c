
#define _ELIBC_SOURCE
#include <assert.h>
#include <stdint.h>
#include <string.h>

/* quick and dirty macro that tests if a pointer is properly aligned to it's
 * native boundary
 */
#define IS_ALIGNED(x) (((uintptr_t)(x) & (sizeof(*(x)) - 1)) == 0)

#ifdef __OPTIMIZE_SIZE__
#define NAIVE_VERSION
#endif

#define SWAP(T, a, b)        \
	do {                     \
		const T temp = *(a); \
		*(a)         = *(b); \
		*(b)         = temp; \
	} while (0)

/**
 * @brief Swap the bytes of two blocks of memory (1-byte at a time)
 *
 * @param s1 a pointer to the first block of memory
 * @param s2 a pointer to the second block of memory
 * @param n the number of bytes to swap
 */
_ALWAYS_INLINE _INLINE static void *__elibc_memswp8(void *_RESTRICT s1, void *_RESTRICT s2, size_t n) {

	uint8_t *p1 = s1;
	uint8_t *p2 = s2;
	while (n--) {
		SWAP(uint8_t, p1, p2);
		++p1;
		++p2;
	}

	return s1;
}

#ifndef NAIVE_VERSION

#if _MAX_MULTIBYTE >= 2
/**
 * @brief Swap the bytes of two blocks of memory (2-bytes at a time)
 *
 * @param s1 a pointer to the first block of memory
 * @param s2 a pointer to the second block of memory
 * @param n the number of bytes to swap
 */
_ALWAYS_INLINE _INLINE static void *__elibc_memswp16(void *_RESTRICT s1, void *_RESTRICT s2, size_t n) {

	uint16_t *p1 = s1;
	uint16_t *p2 = s2;
	while (n >= 2) {
		SWAP(uint16_t, p1, p2);
		++p1;
		++p2;
		n -= sizeof(uint16_t);
	}

	__elibc_memswp8(p1, p2, n);
	return s1;
}
#endif

#if _MAX_MULTIBYTE >= 4
/**
 * @brief Swap the bytes of two blocks of memory (4-bytes at a time)
 *
 * @param s1 a pointer to the first block of memory
 * @param s2 a pointer to the second block of memory
 * @param n the number of bytes to swap
 */
_ALWAYS_INLINE _INLINE static void *__elibc_memswp32(void *_RESTRICT s1, void *_RESTRICT s2, size_t n) {

	uint32_t *p1 = s1;
	uint32_t *p2 = s2;
	while (n >= 4) {
		SWAP(uint32_t, p1, p2);
		++p1;
		++p2;
		n -= sizeof(uint32_t);
	}

	__elibc_memswp16(p1, p2, n);
	return s1;
}
#endif

#if _MAX_MULTIBYTE >= 8
/**
 * @brief Swap the bytes of two blocks of memory (8-bytes at a time)
 *
 * @param s1 a pointer to the first block of memory
 * @param s2 a pointer to the second block of memory
 * @param n the number of bytes to swap
 */
_ALWAYS_INLINE _INLINE static void *__elibc_memswp64(void *_RESTRICT s1, void *_RESTRICT s2, size_t n) {

	uint64_t *p1 = s1;
	uint64_t *p2 = s2;
	while (n >= 8) {
		SWAP(uint64_t, p1, p2);
		++p1;
		++p2;
		n -= sizeof(uint64_t);
	}

	__elibc_memswp32(p1, p2, n);
	return s1;
}
#endif

#endif

/**
 * @brief Swap the bytes of two blocks of memory
 *
 * @param s1 a pointer to the first block of memory
 * @param s2 a pointer to the second block of memory
 * @param n the number of bytes to swap
 * @return a pointer to the first block of memory
 * @note The function assumes that the two blocks of memory are of the same size.
 * @note The function does not check for overlapping memory regions.
 */
void *memswp(void *_RESTRICT s1, void *_RESTRICT s2, size_t n) {

#ifdef NAIVE_VERSION
	/* traditional version */
	if (n == 0) {
		return s1;
	}

	assert(s1);
	assert(s2);
	return __elibc_memswp8(s1, s2, n);
#else

	union {
		void *ptr;
		uint64_t *ptr64;
		uint32_t *ptr32;
		uint16_t *ptr16;
		uint8_t *ptr8;
	} s1_ptr, s2_ptr;

	if (n == 0) {
		return s1;
	}

	assert(s1);
	assert(s2);

	s1_ptr.ptr = s1;
	s2_ptr.ptr = s2;

#if _MAX_MULTIBYTE >= 8
	if (n >= 8 && IS_ALIGNED(s1_ptr.ptr64) && IS_ALIGNED(s2_ptr.ptr64)) {
		return __elibc_memswp64(s1_ptr.ptr64, s2_ptr.ptr64, n);
	}
#endif

#if _MAX_MULTIBYTE >= 4
	if (n >= 4 && IS_ALIGNED(s1_ptr.ptr32) && IS_ALIGNED(s2_ptr.ptr32)) {
		return __elibc_memswp32(s1_ptr.ptr32, s2_ptr.ptr32, n);
	}
#endif

#if _MAX_MULTIBYTE >= 2
	if (n >= 2 && IS_ALIGNED(s1_ptr.ptr16) && IS_ALIGNED(s2_ptr.ptr16)) {
		return __elibc_memswp16(s1_ptr.ptr16, s2_ptr.ptr16, n);
	}
#endif

	return __elibc_memswp8(s1_ptr.ptr8, s2_ptr.ptr8, n);
#endif
}
