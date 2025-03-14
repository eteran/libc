
#ifndef _C_SPRINTF_H_20051228_
#define _C_SPRINTF_H_20051228_

_LIBC_BEGIN

int sprintf(char * str, const char * format, ...) _NOEXCEPT
	__attribute__((__format__(printf, 2, 3)));

_LIBC_END

#endif
