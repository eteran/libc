
#ifndef DIV_20051228_H_
#define DIV_20051228_H_

_LIBC_BEGIN

typedef struct {
	int quot;
	int rem;
} div_t;

div_t div(int numerator, int denominator) _NOEXCEPT;

_LIBC_END

#endif
