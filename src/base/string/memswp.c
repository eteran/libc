
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

#ifndef NAIVE_VERSION
#if _MAX_MULTIBYTE >= 8
/**
 * @brief Swap the bytes of two blocks of memory (8-bytes at a time)
 *
 * @param s1 a pointer to the first block of memory
 * @param s2 a pointer to the second block of memory
 * @param n the number of bytes to swap
 */
_ALWAYS_INLINE _INLINE static void __elibc_memswp64(uint64_t *_RESTRICT s1, uint64_t *_RESTRICT s2, size_t n) {
	while (n--) {
		const uint64_t temp = *s1;
		*s1                 = *s2;
		*s2                 = temp;

		++s1;
		++s2;
	}
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
_ALWAYS_INLINE _INLINE static void __elibc_memswp32(uint32_t *_RESTRICT s1, uint32_t *_RESTRICT s2, size_t n) {
	while (n--) {
		const uint32_t temp = *s1;
		*s1                 = *s2;
		*s2                 = temp;

		++s1;
		++s2;
	}
}
#endif

#if _MAX_MULTIBYTE >= 2
/**
 * @brief Swap the bytes of two blocks of memory (2-bytes at a time)
 *
 * @param s1 a pointer to the first block of memory
 * @param s2 a pointer to the second block of memory
 * @param n the number of bytes to swap
 */
_ALWAYS_INLINE _INLINE static void __elibc_memswp16(uint16_t *_RESTRICT s1, uint16_t *_RESTRICT s2, size_t n) {
	while (n--) {
		const uint16_t temp = *s1;
		*s1                 = *s2;
		*s2                 = temp;

		++s1;
		++s2;
	}
}
#endif

/**
 * @brief Swap the bytes of two blocks of memory (1-byte at a time)
 *
 * @param s1 a pointer to the first block of memory
 * @param s2 a pointer to the second block of memory
 * @param n the number of bytes to swap
 */
_ALWAYS_INLINE _INLINE static void __elibc_memswp8(uint8_t *_RESTRICT s1, uint8_t *_RESTRICT s2, size_t n) {

	while (n--) {
		const uint8_t temp = *s1;
		*s1                = *s2;
		*s2                = temp;

		++s1;
		++s2;
	}
}
#endif

/**
 * @brief Swap the bytes of two blocks of memory
 *
 * @param s1 a pointer to the first block of memory
 * @param s2 a pointer to the second block of memory
 * @param n the number of bytes to swap
 * @return a pointer to the first block of memory
 * @note this function swaps the bytes of two blocks of memory, it does not
 * copy the bytes from one block to another, it swaps them in place.
 * @note The function assumes that the two blocks of memory are of the same size.
 * @note The function does not check for overlapping memory regions.
 */
void *memswp(void *_RESTRICT s1, void *_RESTRICT s2, size_t n) {

#ifdef NAIVE_VERSION
	/* traditional version */
	char *s1_ptr = s1;
	char *s2_ptr = s2;

	assert(s1);
	assert(s2);

	while (n--) {
		const char temp = *s1_ptr;
		*s1_ptr         = *s2_ptr;
		*s2_ptr         = temp;

		++s1_ptr;
		++s2_ptr;
	}
#else

	/* this one is optimized for dword and word aligned copies */
	union {
		void *ptr;
		uint64_t *ptr64;
		uint32_t *ptr32;
		uint16_t *ptr16;
		uint8_t *ptr8;
	} s1_ptr, s2_ptr;

	assert(s1);
	assert(s2);

	s1_ptr.ptr = s1;
	s2_ptr.ptr = s2;

#if _MAX_MULTIBYTE >= 8
	// Handle 8-byte swaps if possible
	if (n >= 8 && IS_ALIGNED(s1_ptr.ptr64) && IS_ALIGNED(s2_ptr.ptr64)) {
		const size_t count = n / 8;
		__elibc_memswp64(s1_ptr.ptr64, s2_ptr.ptr64, count);
		n -= count * 8;
		s1_ptr.ptr64 += count;
		s2_ptr.ptr64 += count;
	}
#endif

#if _MAX_MULTIBYTE >= 4
	// Handle 4-byte swaps if possible
	if (n >= 4 && IS_ALIGNED(s1_ptr.ptr32) && IS_ALIGNED(s2_ptr.ptr32)) {
		const size_t count = n / 4;
		__elibc_memswp32(s1_ptr.ptr32, s2_ptr.ptr32, count);
		n -= count * 4;
		s1_ptr.ptr32 += count;
		s2_ptr.ptr32 += count;
	}
#endif

#if _MAX_MULTIBYTE >= 2
	// Handle 2-byte swaps if possible
	if (n >= 2 && IS_ALIGNED(s1_ptr.ptr16) && IS_ALIGNED(s2_ptr.ptr16)) {
		const size_t count = n / 2;
		__elibc_memswp16(s1_ptr.ptr16, s2_ptr.ptr16, count);
		n -= count * 2;
		s1_ptr.ptr16 += count;
		s2_ptr.ptr16 += count;
	}
#endif

	// Handle remaining 1-byte swaps
	if (n > 0) {
		__elibc_memswp8(s1_ptr.ptr8, s2_ptr.ptr8, n);
	}
#endif
	return s1;
}
