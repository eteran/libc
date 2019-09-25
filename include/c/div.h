
#ifndef DIV_20051228_H_
#define DIV_20051228_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
	int quot;
	int rem;
} div_t;

div_t div(int numerator, int denominator) _NOEXCEPT;

#ifdef __cplusplus
}
#endif

#endif
