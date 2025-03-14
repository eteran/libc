
#define _ELIBC_SOURCE
#include "c/_printf_engine.h"
#include <assert.h>
#include <stdarg.h>
#include <stdio.h>

struct __elibc_buffer_write {
	__elibc_write_func_t write;
	__elibc_done_func_t done;
	size_t written;
	/* end common */
	char *p;
	size_t size;
};

/**
 * @brief Called when the printf engine needs to write a character
 *
 * @param context a pointer to the context structure
 * @param ch the character to write
 */
static void __elibc_buffer_writer(void *context, char ch) {
	struct __elibc_buffer_write *const c = context;

	assert(context);

	if (c->p && (c->size) > 1) {
		*(c->p)++ = ch;
		--(c->size);
	}
	++(c->written);
}

/**
 * @brief Called when the printf engine is done writing
 *
 * @param context a pointer to the context structure
 */
static void __elibc_buffer_writer_done(void *context) {
	struct __elibc_buffer_write *const c = context;

	assert(context);

	if (c->p && (c->size) != 0) {
		*(c->p)++ = '\0';
		--(c->size);
	}
}

/**
 * @brief Write formatted output to a string
 *
 * @param str a pointer to the destination string
 * @param size the maximum number of characters to write to the string
 * @param format a pointer to the format string
 * @param ap a pointer to the variable argument list
 * @return int the number of characters written to the string, or a negative value on error
 */
int vsnprintf(char *_RESTRICT str, size_t size, const char *_RESTRICT format, va_list ap) {

	struct __elibc_buffer_write ctx;
	ctx.write   = __elibc_buffer_writer;
	ctx.done    = __elibc_buffer_writer_done;
	ctx.written = 0;
	ctx.p       = str;
	ctx.size    = size;

	return __elibc_printf_engine(&ctx, format, ap);
}
