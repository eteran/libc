
#define _ELIBC_SOURCE
#define __STDC_CONSTANT_MACROS
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
 * @brief Set the bytes of a block of memory to a specified value (1-byte at a time)
 *
 * @param p a pointer to the block of memory to be set
 * @param ch the value to set the memory to
 * @param n the number of bytes to set
 * @return a pointer to the block of memory that was set
 */
_ALWAYS_INLINE _INLINE static void *__elibc_memset8(void *p, char ch, size_t n) {

	const uint8_t value = (uint8_t)ch;
	uint8_t *dest       = p;
	while (n--) {
		*dest++ = value;
	}

	return p;
}

#ifndef NAIVE_VERSION

#if _MAX_MULTIBYTE >= 2
/**
 * @brief Set the bytes of a block of memory to a specified value (2-bytes at a time)
 *
 * @param p a pointer to the block of memory to be set
 * @param ch the value to set the memory to
 * @param n the number of bytes to set
 * @return a pointer to the block of memory that was set
 */
_ALWAYS_INLINE _INLINE static void *__elibc_memset16(void *p, char ch, size_t n) {

	const uint16_t value = (uint16_t)((uint8_t)ch * UINT16_C(0x0101));
	uint16_t *dest       = p;
	while (n >= 2) {
		*dest++ = value;
		n -= sizeof(uint16_t);
	}

	__elibc_memset8(dest, ch, n);
	return p;
}
#endif

#if _MAX_MULTIBYTE >= 4
/**
 * @brief Set the bytes of a block of memory to a specified value (4-bytes at a time)
 *
 * @param p a pointer to the block of memory to be set
 * @param ch the value to set the memory to
 * @param n the number of bytes to set
 * @return a pointer to the block of memory that was set
 */
_ALWAYS_INLINE _INLINE static void *__elibc_memset32(void *p, char ch, size_t n) {

	const uint32_t value = (uint32_t)((uint8_t)ch * UINT32_C(0x01010101));
	uint32_t *dest       = p;
	while (n >= 4) {
		*dest++ = value;
		n -= sizeof(uint32_t);
	}

	__elibc_memset16(dest, ch, n);
	return p;
}
#endif

#if _MAX_MULTIBYTE >= 8
/**
 * @brief Set the bytes of a block of memory to a specified value (8-bytes at a time)
 *
 * @param p a pointer to the block of memory to be set
 * @param ch the value to set the memory to
 * @param n the number of bytes to set
 * @return a pointer to the block of memory that was set
 */
_ALWAYS_INLINE _INLINE static void *__elibc_memset64(void *p, char ch, size_t n) {

	const uint64_t value = (uint64_t)((uint8_t)ch * UINT64_C(0x0101010101010101));
	uint64_t *dest       = p;
	while (n >= 8) {
		*dest++ = value;
		n -= sizeof(uint64_t);
	}

	__elibc_memset32(dest, ch, n);
	return p;
}
#endif
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
	assert(s);
	return __elibc_memset8(s, c, n);
#else

	union {
		void *ptr;
		uint64_t *ptr64;
		uint32_t *ptr32;
		uint16_t *ptr16;
		uint8_t *ptr8;
	} d_ptr;

	assert(s);

	d_ptr.ptr = s;

#if _MAX_MULTIBYTE >= 8
	if (n >= 8 && (IS_ALIGNED(d_ptr.ptr64))) {
		return __elibc_memset64(d_ptr.ptr64, c, n);
	}
#endif

#if _MAX_MULTIBYTE >= 4
	if (n >= 4 && (IS_ALIGNED(d_ptr.ptr32))) {
		return __elibc_memset32(d_ptr.ptr32, c, n);
	}
#endif

#if _MAX_MULTIBYTE >= 2
	if (n >= 2 && (IS_ALIGNED(d_ptr.ptr16))) {
		return __elibc_memset16(d_ptr.ptr16, c, n);
	}
#endif
	return __elibc_memset8(d_ptr.ptr8, c, n);
#endif
}
