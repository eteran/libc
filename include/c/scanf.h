
#ifndef _C_SCANF_H_20051228_
#define _C_SCANF_H_20051228_

_LIBC_BEGIN

int scanf(const char * format, ...) _NOEXCEPT
	__attribute__((__format__(__scanf__, 1, 2)));

_LIBC_END

#endif
