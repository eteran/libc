
#define __ELIBC_SOURCE
#include <stdarg.h>
#include <stdio.h>
#include "c/_printf_engine.h"

struct __elibc_stream_write {
	const __elibc_write_func_t write;
	const __elibc_done_func_t  done;
	size_t                     written;
	/* end common */
	FILE *stream;
};

static void __elibc_stream_writer(void *context, char ch) {
	struct __elibc_stream_write *const c = context;
	fputc(ch, c->stream);
	++(c->written);
}

/*------------------------------------------------------------------------------
// Name: vfprintf
//----------------------------------------------------------------------------*/
int vfprintf(FILE *_RESTRICT stream, const char *_RESTRICT format, va_list ap) {

	struct __elibc_stream_write ctx = {
		__elibc_stream_writer,
		0,
		0,
		stream};

	return __elibc_printf_engine(&ctx, format, ap);
}
