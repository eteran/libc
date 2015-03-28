
#ifndef LLDIV_20051228_H_
#define LLDIV_20051228_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
	long long quot;
	long long rem;
} lldiv_t;

lldiv_t lldiv(long long numerator, long long denominator) __ELIBC_NOTHROW;

#ifdef __cplusplus
}
#endif

#endif
