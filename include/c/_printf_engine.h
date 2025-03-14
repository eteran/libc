
#ifndef _C_PRINTF_ENGINE_H_20051228_
#define _C_PRINTF_ENGINE_H_20051228_

#include "c/c-config.h"

#include "arch_size_t.h"
#include "arch_va_list.h"

_LIBC_BEGIN

typedef void (*__elibc_write_func_t)(void *, char);
typedef void (*__elibc_done_func_t)(void *);

/* the context structure must be valid when cast to this type, done may be NULL
 */
struct __elibc_write {
	__elibc_write_func_t write;
	__elibc_done_func_t done;
	size_t written;
};

int __elibc_printf_engine(void *ctx, const char *format, va_list ap);

_LIBC_END

#endif
