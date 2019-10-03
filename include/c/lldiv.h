
#ifndef LLDIV_20051228_H_
#define LLDIV_20051228_H_

_LIBC_BEGIN

typedef struct {
	long long quot;
	long long rem;
} lldiv_t;

lldiv_t lldiv(long long numerator, long long denominator) _NOEXCEPT;

_LIBC_END

#endif
