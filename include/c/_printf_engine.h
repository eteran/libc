
#ifndef _PRINTF_ENGINE_20051228_H_
#define _PRINTF_ENGINE_20051228_H_

#include "arch_va_list.h"
#include "arch_size_t.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*__elibc_write_func_t)(void *, char);
typedef void (*__elibc_done_func_t)(void *);

/* the context structure must be valid when cast to this type, done may be NULL */
struct __elibc_write {
	const __elibc_write_func_t write;
	const __elibc_done_func_t  done;
	size_t                     written;
};

int __elibc_printf_engine(void *ctx, const char *__ELIBC_RESTRICT format, va_list ap);

#ifdef __cplusplus
}
#endif

#endif
