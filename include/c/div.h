
#ifndef _C_DIV_H_20051228_
#define _C_DIV_H_20051228_

_LIBC_BEGIN

typedef struct {
	int quot;
	int rem;
} div_t;

div_t div(int numerator, int denominator) _NOEXCEPT;

_LIBC_END

#endif
