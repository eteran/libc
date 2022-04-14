
#define _ELIBC_SAFE_STRING
#define _ELIBC_SOURCE
#include <ctype.h>
#include <math.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "c/_printf_engine.h"

/* we use this because the our assert uses fprintf to print its message,
 * resulting in an infinite recursion if some assertions fail
 */
#if defined NDEBUG
#define PRINTF_ASSERT(ignore) ((void)0)
#else
#include <stdio.h>
#define PRINTF_ASSERT(test)                                                                        \
	do {                                                                                           \
		if (!(test)) {                                                                             \
			puts(#test);                                                                           \
			abort();                                                                               \
		}                                                                                          \
	} while (0)
#endif

enum __flags {
	PRINTF_ALL = -1,
	PRINTF_JUSTIFY = 0x01,
	PRINTF_SIGN = 0x02,
	PRINTF_SPACE = 0x04,
	PRINTF_PREFIX = 0x08,
	PRINTF_PADDING = 0x10
};

enum __modifiers {
	MOD_NONE,
	MOD_CHAR,
	MOD_SHORT,
	MOD_LONG,
	MOD_LONG_LONG,
	MOD_LONG_DOUBLE,
	MOD_INTMAX_T,
	MOD_SIZE_T,
	MOD_PTRDIFF_T
};

struct __write_context {
	char *ptr;
	size_t size;
};

_ALWAYS_INLINE struct __write_context _create_context(char *ptr, size_t size) {
	struct __write_context ctx;
	ctx.ptr = ptr;
	ctx.size = size;
	return ctx;
}

_ALWAYS_INLINE static void _write_char(struct __write_context *ctx, char ch) {
	if (ctx->size != 1) {
		*ctx->ptr++ = ch;
		--ctx->size;
	}
}

_ALWAYS_INLINE static void _reverse_buffer(char *p1, char *p2) {
	while (p1 < p2) {
		const char t_ = *p2;
		*p2 = *p1;
		*p1 = t_;
		p1++;
		p2--;
	}
}

static int _digit_count(intmax_t n) {
	/* clang-format off */
	if (n < 0) n = (n == INTMAX_MIN) ? INTMAX_MAX : -n;
	if (n < 10) return 1;
	if (n < 100) return 2;
	if (n < 1000) return 3;
	if (n < 10000) return 4;
	if (n < 100000) return 5;
	if (n < 1000000) return 6;
	if (n < 10000000) return 7;
	if (n < 100000000) return 8;
	if (n < 1000000000) return 9;
	if (n < 10000000000) return 10;
	if (n < 100000000000) return 11;
	if (n < 1000000000000) return 12;
	if (n < 10000000000000) return 13;
	if (n < 100000000000000) return 14;
	if (n < 1000000000000000) return 15;
	if (n < 10000000000000000) return 16;
	if (n < 100000000000000000) return 17;
	if (n < 1000000000000000000) return 18;
	/* clang-format on */

	/* 9223372036854775807 is 2^63-1 - add more ifs as needed
	   and adjust this final return as well. */
	return 19;
}

#define SET_FLAGS(x, flag)                                                                         \
	do {                                                                                           \
		(x) |= (flag);                                                                             \
	} while (0)

#define CLEAR_FLAGS(x, flag)                                                                       \
	do {                                                                                           \
		(x) &= ~(flag);                                                                            \
	} while (0)

#define GET_FLAG(x, flag) (((x) & (flag)) != 0)

static const char *_get_flags(const char *format, uint8_t *flags);
static const char *_get_width(const char *format, long int *width, va_list *ap);
static const char *_get_precision(const char *format, long int *precision, va_list *ap);
static const char *_get_modifier(const char *format, int *modifier);

static const char *_signed_itoa(char *buf, size_t size, char base, int precision, intmax_t d,
                                int width, uint8_t flags);
static const char *_unsigned_itoa(char *buf, size_t size, char base, int precision, uintmax_t d,
                                  int width, uint8_t flags);
#ifdef _HAS_FPU
static double _round_double(double value, int precision);
static char *_format_float_decimal(char *buf, size_t size, double value, int precision, int width,
                                   uint8_t flags);
static char *_format_float_exponent(char *buf, size_t size, double value, int precision,
                                    char format, int width, uint8_t flags);
static char *_format_float(char *buf, size_t size, double value, int precision, char format,
                           int width, uint8_t flags);
static int _float_length(double value, int precision, uint8_t flags);
#endif

#ifdef _HAS_FPU
/*------------------------------------------------------------------------------
// Name:
//----------------------------------------------------------------------------*/
double _round_double(double value, int precision) {
	const double x = 0.5 / pow(10, precision);
	if (value < 0) {
		value -= x;
	} else {
		value += x;
	}
	return value;
}

/*------------------------------------------------------------------------------
// Name:
//----------------------------------------------------------------------------*/
int _float_length(double value, int precision, uint8_t flags) {
	int n = 0;

	if (signbit(value)) {
		++n;
		value = -value;
	} else if (GET_FLAG(flags, PRINTF_SPACE)) {
		++n;
	} else if (GET_FLAG(flags, PRINTF_SIGN)) {
		++n;
	}

	n += _digit_count(trunc(_round_double(value, precision)));

	if (precision > 0) {
		n += (precision + 1);
	}

	return n;
}

/*------------------------------------------------------------------------------
// Name:
//----------------------------------------------------------------------------*/
char *_format_float_decimal(char *buf, size_t size, double value, int precision, int width,
                            uint8_t flags) {

	double x = value;
	double int_part;
	double frac_part;
	char *p1;
	char *p2;

	const int flen = _float_length(value, precision, flags);
	struct __write_context ctx = _create_context(buf, size);

	if (signbit(x)) {
		_write_char(&ctx, '-');
		x = -x;
	} else if (GET_FLAG(flags, PRINTF_SPACE)) {
		_write_char(&ctx, ' ');
	} else if (GET_FLAG(flags, PRINTF_SIGN)) {
		_write_char(&ctx, '+');
	}

	if (GET_FLAG(flags, PRINTF_PADDING)) {
		while (width > flen) {
			_write_char(&ctx, '0');
			--width;
		}
	}

	x = _round_double(x, precision);
	int_part = trunc(x);
	frac_part = x - int_part;
	p1 = ctx.ptr;

	do {
		const int digit = (int)fmod(int_part, 10);
		_write_char(&ctx, (digit + '0'));
		int_part /= 10;
	} while (int_part >= 1.0);

	/* reverse buffer */
	p2 = ctx.ptr - 1;
	_reverse_buffer(p1, p2);

	if (precision > 0) {
		int i;

		_write_char(&ctx, '.');
		if (frac_part == 0.0) {
			for (i = 1; i <= precision; ++i) {
				_write_char(&ctx, '0');
			}
		} else {
			for (i = 1; i <= precision; ++i) {
				x *= 10;
				do {
					const double digit_d = fmod(x, 10);
					const int digit = trunc(digit_d);
					_write_char(&ctx, (digit + '0'));
				} while (0);
			}
		}
	}

	/* terminate buffer */
	if (ctx.size != 0) {
		*ctx.ptr = '\0';
	}
	return buf;
}

/*------------------------------------------------------------------------------
// Name:
//----------------------------------------------------------------------------*/
char *_format_float_exponent(char *buf, size_t size, double value, int precision, char format,
                             int width, uint8_t flags) {

	double x = value;
	int exponent = 0;
	double int_part;
	double frac_part;
	char *p1;
	char *p2;

	struct __write_context ctx = _create_context(buf, size);

	(void)width;

	if (x != 0.0) {
		while (x < 1.0) {
			x *= 10;
			exponent -= 1;
		}

		while (x > 10.0) {
			x /= 10;
			exponent += 1;
		}
	}

	if (signbit(x)) {
		_write_char(&ctx, '-');
		x = -x;
	} else if (GET_FLAG(flags, PRINTF_SPACE)) {
		_write_char(&ctx, ' ');
	} else if (GET_FLAG(flags, PRINTF_SIGN)) {
		_write_char(&ctx, '+');
	}

	x = _round_double(x, precision);
	int_part = trunc(x);
	frac_part = x - int_part;
	p1 = ctx.ptr;

	do {
		const int digit = (int)fmod(int_part, 10);
		_write_char(&ctx, (digit + '0'));

		int_part /= 10;
	} while (int_part >= 1.0);

	/* reverse buffer */
	p2 = ctx.ptr - 1;
	_reverse_buffer(p1, p2);

	if (precision > 0) {
		int i;
		_write_char(&ctx, '.');
		if (frac_part == 0.0) {
			for (i = 1; i <= precision; ++i) {
				_write_char(&ctx, '0');
			}
		} else {
			for (i = 1; i <= precision; ++i) {
				x *= 10;
				do {
					const double digit_d = fmod(x, 10);
					const int digit = trunc(digit_d);
					_write_char(&ctx, digit + '0');
				} while (0);
			}
		}
	}

	_write_char(&ctx, format);
	_signed_itoa(ctx.ptr, ctx.size, 'd', 2, exponent, 3, PRINTF_SIGN | PRINTF_PADDING);

	/* NOTE(eteran): no need to manually terminate, _signed_itoa, null terminates */
	return buf;
}

/*------------------------------------------------------------------------------
// Name:
//----------------------------------------------------------------------------*/
char *_format_float(char *buf, size_t size, double value, int precision, char format, int width,
                    uint8_t flags) {

	/* negative means no precision given, default to 6 */
	if (precision < 0) {
		precision = 6;
	}

	if (isnan(value)) {
		if (format == 'e' || format == 'f' || format == 'g') {
			strlcpy(buf, "nan", size);
		}

		if (format == 'E' || format == 'F' || format == 'G') {
			strlcpy(buf, "NAN", size);
		}
		return buf;
	}

	if (isinf(value)) {
		if (signbit(value)) {
			if (format == 'e' || format == 'f' || format == 'g') {
				strlcpy(buf, "-inf", size);
			}

			if (format == 'E' || format == 'F' || format == 'G') {
				strlcpy(buf, "-INF", size);
			}
		} else {
			if (format == 'e' || format == 'f' || format == 'g') {
				strlcpy(buf, "inf", size);
			}

			if (format == 'E' || format == 'F' || format == 'G') {
				strlcpy(buf, "INF", size);
			}
		}
		return buf;
	}

	switch (format) {
	case 'e':
	case 'E':
		return _format_float_exponent(buf, size, value, precision, format, width, flags);
	case 'f':
	case 'F':
		return _format_float_decimal(buf, size, value, precision, width, flags);
	case 'g':
	case 'G':
	case 'A':
	case 'a':
	default:
		return buf;
	}
}
#endif

/*------------------------------------------------------------------------------
// Name: _signed_itoa
//----------------------------------------------------------------------------*/
static const char *_signed_itoa(char *buf, size_t size, char base, int precision, intmax_t d,
                                int width, uint8_t flags) {

	const char *const buf_ptr = buf;
	const int pad_zero = GET_FLAG(flags, PRINTF_PADDING);
	const int prefix = GET_FLAG(flags, PRINTF_PREFIX);
	uintmax_t ud = d;
	struct __write_context ctx = _create_context(buf, size);

	/* NOTE: do not change this to const char *'s, it breaks an assert
	 * which makes sure the sizeof(alphabet_u) > divisor!
	 */
	static const char alphabet_l[] = "0123456789abcdef";
	static const char alphabet_u[] = "0123456789ABCDEF";
	const char *alphabet = alphabet_l;

	if (d == 0 && precision == 0 && size > 0) {
		buf[0] = '\0';
		return buf;
	}

	if (size > 0) {

		unsigned int divisor = 10;

		/* If %d is specified and D is negative, put `-' in the head. */
		switch (base) {
		case 'd':
		case 'i':
			if (d < 0) {
				_write_char(&ctx, '-');
				ud = -d;
			} else if (GET_FLAG(flags, PRINTF_SPACE)) {
				_write_char(&ctx, ' ');
			} else if (GET_FLAG(flags, PRINTF_SIGN)) {
				_write_char(&ctx, '+');
			}
			/* FALL THROUGH */
		case 'u':
			divisor = 10;
			break;

		case 'b':
			divisor = 2;
			break;

		case 'X':
			alphabet = alphabet_u;
			/* FALL THROUGH */
		case 'x':
			divisor = 16;
			if (prefix) {
				_write_char(&ctx, '0');
				_write_char(&ctx, base);
			}
			break;

		case 'o':
			divisor = 8;
			if (prefix) {
				_write_char(&ctx, '0');
			}
			break;

		default:
			divisor = 10;
		}

		/* adjust the width to account for the chars we may have just written */
		width -= (ctx.ptr - buf);

		/* this is the point we will start reversing the string at after
		 * conversion*/
		buf = ctx.ptr;

		PRINTF_ASSERT(divisor < sizeof(alphabet_u));

		/* Divide UD by DIVISOR until UD == 0. */
		do {
			const int remainder = (ud % divisor);
			_write_char(&ctx, alphabet[remainder]);
			if (width > 0)
				--width;
		} while (ud /= divisor);

		while (pad_zero && width > 0) {
			_write_char(&ctx, '0');
			--width;
		}

		if (precision > (ctx.ptr - buf)) {
			precision -= (ctx.ptr - buf);
			while (precision--) {
				_write_char(&ctx, '0');
			}
		}
	}

	/* terminate buffer */
	if (ctx.size != 0) {
		*ctx.ptr = '\0';
	}

	/* reverse buffer */
	_reverse_buffer(buf, ctx.ptr - 1);

	return buf_ptr;
}

/*------------------------------------------------------------------------------
// Name: _unsigned_itoa
//----------------------------------------------------------------------------*/
static const char *_unsigned_itoa(char *buf, size_t size, char base, int precision, uintmax_t ud,
                                  int width, uint8_t flags) {

	const char *const buf_ptr = buf;
	const int pad_zero = GET_FLAG(flags, PRINTF_PADDING);
	const int prefix = GET_FLAG(flags, PRINTF_PREFIX);
	struct __write_context ctx = _create_context(buf, size);

	/* NOTE: do not change this to const char *'s, it breaks an assert
	 * which makes sure the sizeof(alphabet_u) > divisor!
	 */
	static const char alphabet_l[] = "0123456789abcdef";
	static const char alphabet_u[] = "0123456789ABCDEF";
	const char *alphabet = alphabet_l;

	if (ud == 0 && precision == 0 && size > 0) {
		buf[0] = '\0';
		return buf;
	}

	if (size > 0) {
		unsigned int divisor = 10;

		/* If %d is specified and D is negative, put `-' in the head. */
		switch (base) {
		case 'd':
			if (GET_FLAG(flags, PRINTF_SPACE)) {
				_write_char(&ctx, ' ');
			} else if (GET_FLAG(flags, PRINTF_SIGN)) {
				_write_char(&ctx, '+');
			}
			/* FALL THROUGH */
		case 'u':
			divisor = 10;
			break;

		case 'b':
			divisor = 2;
			break;

		case 'X':
			alphabet = alphabet_u;
			/* FALL THROUGH */
		case 'x':
			divisor = 16;
			if (prefix) {
				_write_char(&ctx, '0');
				_write_char(&ctx, base);
			}
			break;

		case 'o':
			divisor = 8;
			if (prefix) {
				_write_char(&ctx, '0');
			}
			break;

		default:
			divisor = 10;
		}

		/* adjust the width to account for the chars we may have just written */
		width -= (ctx.ptr - buf);

		/* this is the point we will start reversing the string at after
		 * conversion*/
		buf = ctx.ptr;

		PRINTF_ASSERT(divisor < sizeof(alphabet_u));

		/* Divide UD by DIVISOR until UD == 0. */
		do {
			const int remainder = (ud % divisor);
			_write_char(&ctx, alphabet[remainder]);
			if (width > 0)
				--width;
		} while (ud /= divisor);

		while (pad_zero && width > 0) {
			_write_char(&ctx, '0');
			--width;
		}

		if (precision > (ctx.ptr - buf)) {
			precision -= (ctx.ptr - buf);
			while (precision--) {
				_write_char(&ctx, '0');
			}
		}
	}

	/* terminate buffer */
	if (ctx.size != 0) {
		*ctx.ptr = '\0';
	}

	/* reverse buffer */
	_reverse_buffer(buf, ctx.ptr - 1);

	return buf_ptr;
}

/*------------------------------------------------------------------------------
// Name: _get_flags
//----------------------------------------------------------------------------*/
static const char *_get_flags(const char *format, uint8_t *flags) {
	uint8_t f = 0;
	uint8_t done = 0;

	PRINTF_ASSERT(format);
	PRINTF_ASSERT(flags);

	/* skip past the % char */
	++format;

	while (!done) {

		char ch = *format++;

		switch (ch) {
		case '-':
			/* justify, overrides padding */
			SET_FLAGS(f, PRINTF_JUSTIFY);
			CLEAR_FLAGS(f, PRINTF_PADDING);
			break;
		case '+':
			/* sign, overrides space */
			SET_FLAGS(f, PRINTF_SIGN);
			CLEAR_FLAGS(f, PRINTF_SPACE);
			break;
		case ' ':
			if (!GET_FLAG(f, PRINTF_SIGN)) {
				SET_FLAGS(f, PRINTF_SPACE);
			}
			break;
		case '#':
			SET_FLAGS(f, PRINTF_PREFIX);
			break;
		case '0':
			if (!GET_FLAG(f, PRINTF_JUSTIFY)) {
				SET_FLAGS(f, PRINTF_PADDING);
			}
			break;
		default:
			done = 1;
			--format;
		}
	}

	*flags = f;

	return format;
}

/*------------------------------------------------------------------------------
// Name: _get_width
//----------------------------------------------------------------------------*/
static const char *_get_width(const char *format, long int *width, va_list *ap) {

	PRINTF_ASSERT(format);
	PRINTF_ASSERT(width);
	PRINTF_ASSERT(ap);

	if (*format == '*') {
		++format;
		/* pull an int off the stack for processing */
		*width = va_arg(*ap, long int);
	} else {
		*width = strtol(format, 0, 10);
		while (isdigit(*format)) {
			++format;
		}
	}

	return format;
}

/*------------------------------------------------------------------------------
// Name: _get_precision
//----------------------------------------------------------------------------*/
static const char *_get_precision(const char *format, long int *precision, va_list *ap) {

	/* default to non-existant */
	long int p = -1;

	PRINTF_ASSERT(format);
	PRINTF_ASSERT(precision);
	PRINTF_ASSERT(ap);

	if (*format == '.') {

		++format;
		if (*format == '*') {
			++format;

			/* pull an int off the stack for processing */
			p = va_arg(*ap, long int);

		} else {
			p = strtol(format, 0, 10);
			PRINTF_ASSERT(p >= 0);
			while (isdigit(*format)) {
				++format;
			}
		}
	}

	*precision = p;

	return format;
}

/*------------------------------------------------------------------------------
// Name: _get_modifier
//----------------------------------------------------------------------------*/
static const char *_get_modifier(const char *format, int *modifier) {

	PRINTF_ASSERT(format);
	PRINTF_ASSERT(modifier);

	*modifier = MOD_NONE;

	switch (*format) {
	case 'h':
		*modifier = MOD_SHORT;
		++format;
		if (*format == 'h') {
			*modifier = MOD_CHAR;
			++format;
		}
		break;
	case 'l':
		*modifier = MOD_LONG;
		++format;
		if (*format == 'l') {
			*modifier = MOD_LONG_LONG;
			++format;
		}
		break;
	case 'L':
		*modifier = MOD_LONG_DOUBLE;
		++format;
		break;
	case 'j':
		*modifier = MOD_INTMAX_T;
		++format;
		break;
	case 'z':
		*modifier = MOD_SIZE_T;
		++format;
		break;
	case 't':
		*modifier = MOD_PTRDIFF_T;
		++format;
		break;
	default:
		break;
	}

	return format;
}

/* NOTE(eteran): ch is the current format specifier */
static void _output_string(char ch, const char *s_ptr, int precision, long int *width,
                           uint8_t flags, struct __elibc_write *const ctx) {
	int len;
	PRINTF_ASSERT(s_ptr);

	/* on release builds, we are somewhat forgiving ... */
	if (!s_ptr) {
		s_ptr = "(null)";
	}

	/* TODO(eteran): is this correct? */
	len = strlen(s_ptr);
	len = (ch == 's' && precision >= 0 && precision < len) ? precision : len;

	/* if not left justified padding goes first.. */
	if (!GET_FLAG(flags, PRINTF_JUSTIFY)) {
		/* spaces go before the prefix...*/
		while (*width > len) {
			ctx->write(ctx, ' ');
			--*width;
		}
	}

	/* output the string */
	while (*s_ptr != '\0' && len--) {
		ctx->write(ctx, *s_ptr++);
		--*width;
	}

	/* if left justified padding goes last.. */
	if (GET_FLAG(flags, PRINTF_JUSTIFY)) {
		while (*width > 0) {
			ctx->write(ctx, ' ');
			--*width;
		}
	}
}

#define FLT_BUF_SIZE 64

/*------------------------------------------------------------------------------
// Name: __elibc_printf_engine
//----------------------------------------------------------------------------*/
int __elibc_printf_engine(void *c, const char *_RESTRICT format, va_list ap) {

	va_list aq;

	struct __elibc_write *const ctx = c;

	/* enough to contain a 64-bit number in bin notation */
	char num_buf[65];

	/* TODO(eteran): big enough?, we need the _format_float_* stuff to actually
	 * enforce maximum length */
#ifdef _HAS_FPU
	char flt_buf[FLT_BUF_SIZE];
#endif

	__elibc_va_copy(aq, ap);

	PRINTF_ASSERT(format);

	while (*format != '\0') {
		if (*format == '%') {
			/* %[flag][width][.precision][length]char */

			const char *s_ptr = 0;
			long int width = 0;
			long int precision = 0;
			int modifier = 0;
			char ch;
			uint8_t flags;

			format = _get_flags(format, &flags);
			format = _get_width(format, &width, &aq);
			format = _get_precision(format, &precision, &aq);
			format = _get_modifier(format, &modifier);

			if (width < 0) {
				/* negative width means positive width and left justified */
				width = -width;

				/* justify, overrides padding */
				SET_FLAGS(flags, PRINTF_JUSTIFY);
				CLEAR_FLAGS(flags, PRINTF_PADDING);
			}

			ch = *format;

			switch (ch) {
			/* double format of sorts */
			case 'e':
			case 'E':
			case 'f':
			case 'F':
			case 'a':
			case 'A':

				if (precision < 0) {
					precision = 6;
				}

				/* limit it to something sane */
				if (precision > 32) {
					precision = 32;
				}
				goto do_float;

			case 'g':
			case 'G':
				if (precision < 0) {
					precision = 6;
				}

				/* limit it to something sane */
				if (precision > 32) {
					precision = 32;
				}

			do_float:
#ifdef _HAS_FPU
				if (modifier == MOD_LONG_DOUBLE) {
					/* unsupported (as of yet), but we still need to pluck an argument off
					 * the stack so any following arguments work correctly!
					 */
					(void)va_arg(aq, long double);
					s_ptr = 0;
				} else {
					s_ptr = _format_float(flt_buf, sizeof(flt_buf), va_arg(aq, double), precision,
					                      ch, width, flags);
				}
#else
				s_ptr = "0.0";
#endif
				_output_string(ch, s_ptr, precision, &width, flags, ctx);
				break;

			/* integer format of sorts */
			case 'p':
				precision = 1;
				ch = 'x';
				SET_FLAGS(flags, PRINTF_PREFIX);
				s_ptr = _unsigned_itoa(num_buf, sizeof(num_buf), ch, precision,
				                       (uintptr_t)va_arg(aq, void *), width, flags);
				_output_string(ch, s_ptr, precision, &width, flags, ctx);
				break;
			case 'x':
			case 'X':
			case 'u':
			case 'o':
			case 'b': /* extension, BINARY mode */
				if (precision < 0) {
					precision = 1;
				}

				switch (modifier) {
				case MOD_CHAR:
					s_ptr = _unsigned_itoa(num_buf, sizeof(num_buf), ch, precision,
					                       (unsigned char)va_arg(aq, unsigned int), width, flags);
					break;
				case MOD_SHORT:
					s_ptr =
						_unsigned_itoa(num_buf, sizeof(num_buf), ch, precision,
					                   (unsigned short int)va_arg(aq, unsigned int), width, flags);
					break;
				case MOD_LONG:
					s_ptr = _unsigned_itoa(num_buf, sizeof(num_buf), ch, precision,
					                       va_arg(aq, unsigned long int), width, flags);
					break;
				case MOD_LONG_LONG:
					s_ptr = _unsigned_itoa(num_buf, sizeof(num_buf), ch, precision,
					                       va_arg(aq, unsigned long long int), width, flags);
					break;
				case MOD_INTMAX_T:
					s_ptr = _unsigned_itoa(num_buf, sizeof(num_buf), ch, precision,
					                       va_arg(aq, uintmax_t), width, flags);
					break;
				case MOD_SIZE_T:
					s_ptr = _unsigned_itoa(num_buf, sizeof(num_buf), ch, precision,
					                       va_arg(aq, size_t), width, flags);
					break;
				case MOD_PTRDIFF_T:
					/* NOTE: we really want uptrdiff_t or something to that effect, but
					 * unsigned long will have to do */
					s_ptr = _unsigned_itoa(num_buf, sizeof(num_buf), ch, precision,
					                       (unsigned long)va_arg(aq, ptrdiff_t), width, flags);
					break;
				default:
					s_ptr = _unsigned_itoa(num_buf, sizeof(num_buf), ch, precision,
					                       va_arg(aq, unsigned int), width, flags);
					break;
				}
				_output_string(ch, s_ptr, precision, &width, flags, ctx);
				break;

			case 'i':
			case 'd':
				if (precision < 0) {
					precision = 1;
				}

				switch (modifier) {
				case MOD_CHAR:
					s_ptr = _signed_itoa(num_buf, sizeof(num_buf), ch, precision,
					                     (signed char)va_arg(aq, int), width, flags);
					break;
				case MOD_SHORT:
					s_ptr = _signed_itoa(num_buf, sizeof(num_buf), ch, precision,
					                     (short int)va_arg(aq, int), width, flags);
					break;
				case MOD_LONG:
					s_ptr = _signed_itoa(num_buf, sizeof(num_buf), ch, precision,
					                     va_arg(aq, long int), width, flags);
					break;
				case MOD_LONG_LONG:
					s_ptr = _signed_itoa(num_buf, sizeof(num_buf), ch, precision,
					                     va_arg(aq, long long int), width, flags);
					break;
				case MOD_INTMAX_T:
					s_ptr = _signed_itoa(num_buf, sizeof(num_buf), ch, precision,
					                     va_arg(aq, intmax_t), width, flags);
					break;
				case MOD_SIZE_T:
					s_ptr = _signed_itoa(num_buf, sizeof(num_buf), ch, precision,
					                     va_arg(aq, ssize_t), width, flags);
					break;
				case MOD_PTRDIFF_T:
					s_ptr = _signed_itoa(num_buf, sizeof(num_buf), ch, precision,
					                     va_arg(aq, ptrdiff_t), width, flags);
					break;
				default:
					s_ptr = _signed_itoa(num_buf, sizeof(num_buf), ch, precision, va_arg(aq, int),
					                     width, flags);
					break;
				}
				_output_string(ch, s_ptr, precision, &width, flags, ctx);
				break;

			case 'c':
				/* char is promoted to an int when pushed on the stack */
				num_buf[0] = va_arg(aq, long int);
				num_buf[1] = '\0';
				s_ptr = num_buf;
				_output_string(ch, s_ptr, precision, &width, flags, ctx);
				break;

			case 's':
				s_ptr = va_arg(aq, char *);
				_output_string(ch, s_ptr, precision, &width, flags, ctx);
				break;

			case 'n':
				do {
					union {
						void *p;
						char *p_char;
						short int *p_short;
						int *p_int;
						long int *p_long;
						long long int *p_longlong;
					} p;

					p.p = va_arg(aq, void *);

					if (p.p) {
						switch (modifier) {
						case MOD_CHAR:
							*(p.p_char) = ctx->written;
							break;
						case MOD_SHORT:
							*(p.p_short) = ctx->written;
							break;
						case MOD_LONG:
							*(p.p_long) = ctx->written;
							break;
						case MOD_LONG_LONG:
							*(p.p_longlong) = ctx->written;
							break;
						default:
							*(p.p_int) = ctx->written;
							break;
						}
					}
				} while (0);
				break;

			default:
				ctx->write(ctx, '%');
				/* FALL THROUGH */
			case '\0':
			case '%':
				ctx->write(ctx, ch);
				break;
			}
		} else {
			ctx->write(ctx, *format);
		}

		++format;
	}

	va_end(aq);

	/* this will usually null terminate the string */
	if (ctx->done) {
		ctx->done(ctx);
	}

	/* return the amount of bytes that should have been written if there was
	 * sufficient space*/
	return ctx->written;
}
