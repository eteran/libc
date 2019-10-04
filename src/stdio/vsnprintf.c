
#define __ELIBC_SOURCE
#include "c/_printf_engine.h"
#include <stdarg.h>

struct __elibc_buffer_write {
	__elibc_write_func_t write;
	__elibc_done_func_t  done;
	size_t               written;
	/* end common */
	char * p;
	size_t size;
};

static void __elibc_buffer_writer(void *context, char ch) {
	struct __elibc_buffer_write *const c = context;

	if (c->p && (c->size) > 1) {
		*(c->p)++ = ch;
		--(c->size);
	}
	++(c->written);
}

static void __elibc_buffer_writer_done(void *context) {
	struct __elibc_buffer_write *const c = context;

	if (c->p && (c->size) != 0) {
		*(c->p)++ = '\0';
		--(c->size);
	}
}

/*------------------------------------------------------------------------------
// Name: vsnprintf
//----------------------------------------------------------------------------*/
int vsnprintf(char *_RESTRICT str, size_t size, const char *_RESTRICT format, va_list ap) {

	struct __elibc_buffer_write ctx;
	ctx.write   = __elibc_buffer_writer;
	ctx.done    = __elibc_buffer_writer_done;
	ctx.written = 0;
	ctx.p       = str;
	ctx.size    = size;

	return __elibc_printf_engine(&ctx, format, ap);
}
