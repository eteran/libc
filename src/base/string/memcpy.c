
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

/**
 * @brief Copy the bytes of a block of memory to another block of memory (1-byte at a time)
 *
 * @param dest a pointer to the destination block of memory
 * @param src a pointer to the source block of memory
 * @param n the number of bytes to copy
 * @return a pointer to the destination block of memory
 */
_ALWAYS_INLINE _INLINE static void *__elibc_memcpy8(void *_RESTRICT dest, const void *_RESTRICT src, size_t n) {

	uint8_t *p1       = dest;
	const uint8_t *p2 = src;
	while (n >= 1) {
		*p1++ = *p2++;
		n -= sizeof(uint8_t);
	}

	return dest;
}

#ifndef NAIVE_VERSION

#if _MAX_MULTIBYTE >= 2
/**
 * @brief Copy the bytes of a block of memory to another block of memory (2-bytes at a time)
 *
 * @param dest a pointer to the destination block of memory
 * @param src a pointer to the source block of memory
 * @param n the number of bytes to copy
 * @return a pointer to the destination block of memory
 */
_ALWAYS_INLINE _INLINE static void *__elibc_memcpy16(void *_RESTRICT dest, const void *_RESTRICT src, size_t n) {

	uint16_t *p1       = dest;
	const uint16_t *p2 = src;
	while (n >= 2) {
		*p1++ = *p2++;
		n -= sizeof(uint16_t);
	}

	__elibc_memcpy8(p1, p2, n);
	return dest;
}
#endif

#if _MAX_MULTIBYTE >= 4
/**
 * @brief Copy the bytes of a block of memory to another block of memory (4-bytes at a time)
 *
 * @param dest a pointer to the destination block of memory
 * @param src a pointer to the source block of memory
 * @param n the number of bytes to copy
 * @return a pointer to the destination block of memory
 */
_ALWAYS_INLINE _INLINE static void *__elibc_memcpy32(void *_RESTRICT dest, const void *_RESTRICT src, size_t n) {

	uint32_t *p1       = dest;
	const uint32_t *p2 = src;
	while (n >= 4) {
		*p1++ = *p2++;
		n -= sizeof(uint32_t);
	}

	__elibc_memcpy16(p1, p2, n);
	return dest;
}
#endif

#if _MAX_MULTIBYTE >= 8
/**
 * @brief Copy the bytes of a block of memory to another block of memory (8-bytes at a time)
 *
 * @param dest a pointer to the destination block of memory
 * @param src a pointer to the source block of memory
 * @param n the number of bytes to copy
 * @return a pointer to the destination block of memory
 */
_ALWAYS_INLINE _INLINE static void *__elibc_memcpy64(void *_RESTRICT dest, const void *_RESTRICT src, size_t n) {

	uint64_t *p1       = dest;
	const uint64_t *p2 = src;
	while (n >= 8) {
		*p1++ = *p2++;
		n -= sizeof(uint64_t);
	}

	__elibc_memcpy32(p1, p2, n);
	return dest;
}
#endif

#endif

/**
 * @brief Copy the bytes of a block of memory to another block of memory
 *
 * @param dest a pointer to the destination block of memory
 * @param src a pointer to the source block of memory
 * @param n the number of bytes to copy
 * @return a pointer to the destination block of memory
 */
void *memcpy(void *_RESTRICT dest, const void *_RESTRICT src, size_t n) {

#ifdef NAIVE_VERSION
	/* traditional memory copy */
	if (n == 0) {
		return dest;
	}

	assert(dest);
	assert(src);
	return __elibc_memcpy8(dest, src, n);
#else

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

	if (n == 0) {
		return dest;
	}

	assert(dest);
	assert(src);

	d_ptr.ptr = dest;
	s_ptr.ptr = src;

#if _MAX_MULTIBYTE >= 8
	if (n >= 8 && IS_ALIGNED(d_ptr.ptr64) && IS_ALIGNED(s_ptr.ptr64)) {
		return __elibc_memcpy64(d_ptr.ptr64, s_ptr.ptr64, n);
	}
#endif

#if _MAX_MULTIBYTE >= 4
	if (n >= 4 && IS_ALIGNED(d_ptr.ptr32) && IS_ALIGNED(s_ptr.ptr32)) {
		return __elibc_memcpy32(d_ptr.ptr32, s_ptr.ptr32, n);
	}
#endif

#if _MAX_MULTIBYTE >= 2
	if (n >= 2 && IS_ALIGNED(d_ptr.ptr16) && IS_ALIGNED(s_ptr.ptr16)) {
		return __elibc_memcpy16(d_ptr.ptr16, s_ptr.ptr16, n);
	}
#endif

	return __elibc_memcpy8(d_ptr.ptr8, s_ptr.ptr8, n);
#endif
}
