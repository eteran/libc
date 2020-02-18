
#ifndef _C_LLDIV_H_20051228_
#define _C_LLDIV_H_20051228_

_LIBC_BEGIN

typedef struct {
	long long quot;
	long long rem;
} lldiv_t;

lldiv_t lldiv(long long numerator, long long denominator) _NOEXCEPT;

_LIBC_END

#endif
