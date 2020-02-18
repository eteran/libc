
#ifndef _C_LDIV_H_20051228_
#define _C_LDIV_H_20051228_

_LIBC_BEGIN

typedef struct {
	long quot;
	long rem;
} ldiv_t;

ldiv_t ldiv(long numerator, long denominator) _NOEXCEPT;

_LIBC_END

#endif
