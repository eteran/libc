
#define _ELIBC_SOURCE
#include "c/_printf_engine.h"
#include <assert.h>
#include <stdarg.h>
#include <stdio.h>

struct __elibc_stream_write {
	__elibc_write_func_t write;
	__elibc_done_func_t done;
	size_t written;
	/* end common */
	FILE *stream;
};

/**
 * @brief Called when the printf engine needs to write a character
 *
 * @param context a pointer to the context structure
 * @param ch the character to write
 */
static void __elibc_stream_writer(void *context, char ch) {
	struct __elibc_stream_write *const c = context;
	assert(context);
	fputc(ch, c->stream);
	++(c->written);
}

/**
 * @brief Write formatted output to a stream
 *
 * @param stream the stream to write to
 * @param format a pointer to the format string
 * @param ap a pointer to the variable argument list
 * @return int the number of characters written to the stream, or a negative value on error
 */
int vfprintf(FILE *_RESTRICT stream, const char *_RESTRICT format, va_list ap) {

	struct __elibc_stream_write ctx;
	ctx.write   = __elibc_stream_writer;
	ctx.done    = 0;
	ctx.written = 0;
	ctx.stream  = stream;

	return __elibc_printf_engine(&ctx, format, ap);
}
