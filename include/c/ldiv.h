
#ifndef LDIV_20051228_H_
#define LDIV_20051228_H_

_LIBC_BEGIN

typedef struct {
	long quot;
	long rem;
} ldiv_t;

ldiv_t ldiv(long numerator, long denominator) _NOEXCEPT;

_LIBC_END

#endif
