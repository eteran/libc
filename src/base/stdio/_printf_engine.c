
#define _ELIBC_SAFE_STRING
#define _ELIBC_SOURCE
#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <math.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "c/_printf_engine.h"

typedef struct {
	unsigned int justify : 1;
	unsigned int sign : 1;
	unsigned int space : 1;
	unsigned int prefix : 1;
	unsigned int padding : 1;
} flags_t;

typedef enum {
	MOD_NONE,
	MOD_CHAR,
	MOD_SHORT,
	MOD_LONG,
	MOD_LONG_LONG,
	MOD_LONG_DOUBLE,
	MOD_INTMAX_T,
	MOD_SIZE_T,
	MOD_PTRDIFF_T
} modifiers_t;

typedef struct {
	char *base;
	char *ptr;
	size_t size;
	int width;
	int precision;
} write_context_t;

/**
 * @brief Create a write context
 *
 * @param buffer the buffer to write to
 * @param size the size of the buffer
 * @param width the width to use
 * @param precision the precision to use
 * @return the write context
 */
_ALWAYS_INLINE _INLINE static write_context_t _create_context(char *buffer, size_t size, int width,
															  int precision) {
	write_context_t ctx;
	ctx.base      = buffer;
	ctx.ptr       = buffer;
	ctx.size      = size;
	ctx.width     = width;
	ctx.precision = precision;
	return ctx;
}

/**
 * @brief Write a single character to the write context
 *
 * @param ctx the write context
 * @param ch the character to write
 */
_ALWAYS_INLINE _INLINE static void _write_char(write_context_t *ctx, char ch) {
	if (ctx->size != 1) {
		*ctx->ptr++ = ch;
		--ctx->size;
		if (ctx->width != 0) {
			--ctx->width;
		}
	}
}

/**
 * @brief Reverse a buffer
 *
 * @param p1 the start of the buffer
 * @param p2 the end of the buffer
 */
_ALWAYS_INLINE _INLINE static void _reverse_buffer(char *p1, char *p2) {
	while (p1 < p2) {
		const char t_ = *p2;
		*p2           = *p1;
		*p1           = t_;
		p1++;
		p2--;
	}
}

/**
 * @brief Get the padding width for a given write context
 *
 * @param ctx the write context
 * @param flags the flags to use for the conversion
 * @return the padding width
 */
static int _pad_width(write_context_t *ctx, const flags_t *flags) {
	const int pad_zero  = flags->padding;
	const int width     = ctx->width;
	const int precision = ctx->precision;

	if (pad_zero) {
		return width > precision ? width : precision;
	} else {
		return precision;
	}
}

/**
 * @brief Common integer conversion function
 *
 * @param ctx the write context
 * @param ud the unsigned integer to convert
 * @param divisor the divisor to use for the conversion
 * @param alphabet the alphabet to use for the conversion
 * @param flags the flags to use for the conversion
 */
static void _itoa_common(write_context_t *ctx, uintmax_t ud, unsigned int divisor,
						 const char *alphabet, const flags_t *flags) {

	int min_length = _pad_width(ctx, flags);

	/* this is the point we will start reversing the string at after
	 * conversion*/
	char *buf = ctx->ptr;

	assert(divisor != 0);

	/* Divide UD by DIVISOR until UD == 0. */
	do {
		_write_char(ctx, alphabet[ud % divisor]);
		--min_length;
	} while (ud /= divisor);

	while (min_length-- > 0) {
		_write_char(ctx, '0');
	}

	/* reverse buffer */
	_reverse_buffer(buf, ctx->ptr - 1);

	/* terminate buffer */
	if (ctx->size != 0) {
		*ctx->ptr = '\0';
	}
}

/**
 * @brief Convert a unsigned integer to a string
 *
 * @param buffer the buffer to write the string to
 * @param size the size of the buffer
 * @param precision the precision to use
 * @param d the unsigned integer to convert
 * @param width the width to use
 * @param flags the flags to use
 * @return a pointer to the string
 */
static const char *_unsigned_itoa(char *buffer, size_t size, char base, int precision, uintmax_t ud,
								  int width, const flags_t *flags) {

	const int prefix    = flags->prefix;
	write_context_t ctx = _create_context(buffer, size, width, precision);

	static const char *alphabet_l = "0123456789abcdef";
	static const char *alphabet_u = "0123456789ABCDEF";
	const char *alphabet          = alphabet_l;

	if (ud == 0 && ctx.precision == 0 && ctx.size > 0) {
		buffer[0] = '\0';
		return buffer;
	}

	if (ctx.size > 0) {
		unsigned int divisor = 10;

		/* If %d is specified and D is negative, put `-' in the head. */
		switch (base) {
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
			assert(0 && "Invalid Base");
		}

		_itoa_common(&ctx, ud, divisor, alphabet, flags);
	}

	return ctx.base;
}

/**
 * @brief Convert a signed integer to a string
 *
 * @param buffer the buffer to write the string to
 * @param size the size of the buffer
 * @param precision the precision to use
 * @param d the signed integer to convert
 * @param width the width to use
 * @param flags the flags to use
 * @return a pointer to the string
 */
static const char *_signed_itoa(char *buffer, size_t size, int precision, intmax_t d, int width,
								const flags_t *flags) {

	uintmax_t ud        = (uintmax_t)d;
	write_context_t ctx = _create_context(buffer, size, width, precision);

	const char *alphabet = "0123456789";

	if (d == 0 && precision == 0 && size > 0) {
		buffer[0] = '\0';
		return buffer;
	}

	if (size > 0) {
		unsigned int divisor = 10;

		if (d < 0) {
			_write_char(&ctx, '-');
			ud = (~ud + 1);
		} else if (flags->space) {
			_write_char(&ctx, ' ');
		} else if (flags->sign) {
			_write_char(&ctx, '+');
		}

		_itoa_common(&ctx, ud, divisor, alphabet, flags);
	}

	return buffer;
}

#ifdef _HAS_FPU

/**
 * @brief Get the number of digits in a double in base 10
 *
 * @param n the number to get the length of
 * @return the number of digits in the number
 * @note this function assumes that the number is positive
 */
static int base10_len(double n) {
	/* clang-format off */
	if (n < 10.0) return 1;
	if (n < 100.0) return 2;
	if (n < 1000.0) return 3;
	if (n < 10000.0) return 4;
	if (n < 100000.0) return 5;
	if (n < 1000000.0) return 6;
	if (n < 10000000.0) return 7;
	if (n < 100000000.0) return 8;
	if (n < 1000000000.0) return 9;
	if (n < 10000000000.0) return 10;
	if (n < 100000000000.0) return 11;
	if (n < 1000000000000.0) return 12;
	if (n < 10000000000000.0) return 13;
	if (n < 100000000000000.0) return 14;
	if (n < 1000000000000000.0) return 15;
	if (n < 10000000000000000.0) return 16;
	if (n < 100000000000000000.0) return 17;
	if (n < 1000000000000000000.0) return 18;
	if (n < 10000000000000000000.0) return 19;
	/* clang-format on */

	return 20;
}

/**
 * @brief Get the number of digits in a double in base 10
 *
 * @param n the number to get the length of
 * @return the number of digits in the number
 */
static int _digit10_count(double n) {

	if (n < 0) {
		return base10_len(-n);
	}

	return base10_len(n);
}

/**
 * @brief Round a double to the given precision
 *
 * @param value the value to round
 * @param precision the precision to round to
 * @return the rounded value
 */
static double _round_double(double value, int precision) {
	const double x = 0.5 / pow(10, precision);
	if (value < 0) {
		value -= x;
	} else {
		value += x;
	}
	return value;
}

/**
 * @brief Get the length of a floating point number in decimal notation
 *
 * @param value the value to format
 * @param precision the precision to use
 * @param flags the flags to use
 * @return the length of the formatted string
 */
static int _float_length(double value, int precision, const flags_t *flags) {
	int n = 0;

	if (signbit(value) || flags->space || flags->sign) {
		++n;
	}

	n += _digit10_count(_round_double(value, precision));

	if (precision > 0) {
		n += (precision + 1);
	}

	return n;
}

/**
 * @brief Format a floating point number in decimal notation
 *
 * @param buf the buffer to write to
 * @param size the size of the buffer
 * @param value the value to format
 * @param precision the precision to use
 * @param width the width to use
 * @param flags the flags to use
 * @return a pointer to the formatted string
 */
static char *_format_float_decimal(char *buf, size_t size, double value, int precision, int width,
								   const flags_t *flags) {
	double x = value;
	double int_part;
	double frac_part;
	char *p1;
	char *p2;

	const int flen      = _float_length(value, precision, flags);
	write_context_t ctx = _create_context(buf, size, width, precision);

	if (signbit(x)) {
		_write_char(&ctx, '-');
		x = -x;
	} else if (flags->space) {
		_write_char(&ctx, ' ');
	} else if (flags->sign) {
		_write_char(&ctx, '+');
	}

	if (flags->padding) {
		while (ctx.width > flen) {
			_write_char(&ctx, '0');
		}
	}

	x         = _round_double(x, ctx.precision);
	int_part  = trunc(x);
	frac_part = x - int_part;
	p1        = ctx.ptr;

	do {
		const int digit = (int)fmod(int_part, 10);
		_write_char(&ctx, (char)(digit + '0'));
		int_part /= 10;
	} while (int_part >= 1.0);

	/* reverse buffer */
	p2 = ctx.ptr - 1;
	_reverse_buffer(p1, p2);

	if (ctx.precision > 0) {
		int i;

		_write_char(&ctx, '.');
		if (frac_part == 0.0) {
			for (i = 0; i < ctx.precision; ++i) {
				_write_char(&ctx, '0');
			}
		} else {
			for (i = 0; i < ctx.precision; ++i) {
				x *= 10;
				do {
					const int digit = (int)fmod(x, 10);
					_write_char(&ctx, (char)(digit + '0'));
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

/**
 * @brief Format a floating point number in scientific notation
 *
 * @param buf the buffer to write to
 * @param size the size of the buffer
 * @param value the value to format
 * @param precision the precision to use
 * @param format the format to use ('e' or 'E')
 * @param width the width to use
 * @param flags the flags to use
 * @return a pointer to the formatted string
 */
static char *_format_float_exponent(char *buf, size_t size, double value, int precision,
									char format, int width, const flags_t *flags) {
	double x     = value;
	int exponent = 0;
	double int_part;
	double frac_part;
	write_context_t ctx = _create_context(buf, size, width, precision);

	/* normalize to a single digit integer */
	if (x != 0.0) {
		while (x < 1.0) {
			x *= 10;
			--exponent;
		}

		while (x > 10.0) {
			x /= 10;
			++exponent;
		}
	}

	if (signbit(x)) {
		_write_char(&ctx, '-');
		x = -x;
	} else if (flags->space) {
		_write_char(&ctx, ' ');
	} else if (flags->sign) {
		_write_char(&ctx, '+');
	}

	x         = _round_double(x, precision);
	int_part  = trunc(x);
	frac_part = x - int_part;

	/* write the integer portion, it'll be exactly one digit */
	_write_char(&ctx, (char)((int)int_part + '0'));

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
					const int digit = (int)fmod(x, 10);
					_write_char(&ctx, (char)(digit + '0'));
				} while (0);
			}
		}
	}

	_write_char(&ctx, format);
	{
		flags_t f = {0, 0, 0, 0, 0};
		f.sign    = 1;
		f.padding = 1;
		_signed_itoa(ctx.ptr, ctx.size, 2, exponent, 3, &f);
	}

	/* NOTE(eteran): no need to manually terminate, _signed_itoa, null terminates */
	return buf;
}

/**
 * @brief Format a floating point number
 *
 * @param buf the buffer to write to
 * @param size the size of the buffer
 * @param value the value to format
 * @param precision the precision to use
 * @param format the format to use
 * @param width the width to use
 * @param flags the flags to use
 * @return a pointer to the formatted string
 * @note this function supports the following formats:
 * - %e: scientific notation (lowercase)
 * - %E: scientific notation (uppercase)
 * - %f: fixed point notation (lowercase)
 * - %F: fixed point notation (uppercase)
 * - %g: scientific or fixed point notation, depending on the value and precision (lowercase)
 * - %G: scientific or fixed point notation, depending on the value and precision (uppercase)
 * - %a: hexadecimal floating point notation (lowercase)
 * - %A: hexadecimal floating point notation (uppercase)
 */
static char *_format_float(char *buf, size_t size, double value, int precision, char format,
						   int width, const flags_t *flags) {

	buf[0] = '\0';

	/* negative means no precision given, default to 6 */
	if (precision < 0) {
		precision = 6;
	}

	if (isnan(value)) {
		switch (format) {
		case 'e':
		case 'f':
		case 'g':
			strlcpy(buf, "nan", size);
			break;
		case 'E':
		case 'F':
		case 'G':
			strlcpy(buf, "NAN", size);
			break;
		}
		return buf;
	}

	if (isinf(value)) {
		if (signbit(value)) {
			switch (format) {
			case 'e':
			case 'f':
			case 'g':
				strlcpy(buf, "-inf", size);
				break;
			case 'E':
			case 'F':
			case 'G':
				strlcpy(buf, "-INF", size);
				break;
			}
		} else {
			switch (format) {
			case 'e':
			case 'f':
			case 'g':
				strlcpy(buf, "inf", size);
				break;
			case 'E':
			case 'F':
			case 'G':
				strlcpy(buf, "INF", size);
				break;
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
		/* auto-detect */
	case 'A':
	case 'a':
		/* hex-floats */
	default:
		return buf;
	}
}
#endif

/**
 * @brief Get the flags for a format specifier
 *
 * @param format the format string
 * @param flags the flags to set
 * @return the next character in the format string
 */
static const char *_get_flags(const char *format, flags_t *flags) {
	flags_t f    = {0, 0, 0, 0, 0};
	uint8_t done = 0;

	assert(format);
	assert(flags);

	/* skip past the % char */
	++format;

	while (!done) {

		char ch = *format++;

		switch (ch) {
		case '-':
			/* justify, overrides padding */
			f.justify = 1;
			f.padding = 0;
			break;
		case '+':
			/* sign, overrides space */
			f.sign  = 1;
			f.space = 0;
			break;
		case ' ':
			if (!f.sign) {
				f.space = 1;
			}
			break;
		case '#':
			f.prefix = 1;
			break;
		case '0':
			if (!f.justify) {
				f.padding = 1;
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

/**
 * @brief Get the width for a format specifier
 *
 * @param format the format string
 * @param width the width to set
 * @param ap the variable argument list
 * @return the next character in the format string
 */
static const char *_get_width(const char *format, int *width, va_list *ap) {

	assert(format);
	assert(width);
	assert(ap);

	if (*format == '*') {
		++format;
		/* pull an int off the stack for processing */
		*width = (int)va_arg(*ap, long int);
	} else {
		char *endptr = 0;
		errno        = 0;
		*width       = (int)strtol(format, &endptr, 10);
		assert(errno == 0);
		format = endptr;
	}

	return format;
}

/**
 * @brief Get the precision for a format specifier
 *
 * @param format the format string
 * @param precision the precision to set
 * @param ap the variable argument list
 * @return the next character in the format string
 */
static const char *_get_precision(const char *format, int *precision, va_list *ap) {

	/* default to non-existant */
	long int p = -1;

	assert(format);
	assert(precision);
	assert(ap);

	if (*format == '.') {
		++format;
		if (*format == '*') {
			++format;

			/* pull an int off the stack for processing */
			p = va_arg(*ap, long int);

		} else {
			char *endptr = 0;
			errno        = 0;
			p            = strtol(format, &endptr, 10);
			assert(errno == 0);
			assert(p >= 0);
			format = endptr;
		}
	}

	*precision = (int)p;
	return format;
}

/**
 * @brief Get the modifier for a format specifier
 *
 * @param format the format string
 * @param modifier the modifier to set
 * @return the next character in the format string
 */
static const char *_get_modifier(const char *format, int *modifier) {

	assert(format);
	assert(modifier);

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
static void _output_string(char ch, const char *s_ptr, int precision, int *width,
						   const flags_t *flags, struct __elibc_write *const ctx) {
	int len;

	/* on release builds, we are somewhat forgiving ... */
	if (!s_ptr) {
		s_ptr = "(null)";
	}

	/* TODO(eteran): is this correct? */
	len = (int)strlen(s_ptr);
	len = (ch == 's' && precision >= 0 && precision < len) ? precision : len;

	/* if not left justified padding goes first.. */
	if (!flags->justify) {
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
	if (flags->justify) {
		while (*width > 0) {
			ctx->write(ctx, ' ');
			--*width;
		}
	}
}

#define FLT_BUF_SIZE 64

/**
 * @brief The printf engine, writes formatted output to a context
 *
 * @param c the context to write to
 * @param format the format string
 * @param ap the variable argument list
 * @return the number of characters written
 */
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

	assert(format);

	while (*format != '\0') {
		if (*format == '%') {
			/* %[flag][width][.precision][length]char */

			const char *s_ptr = 0;
			int width         = 0;
			int precision     = 0;
			int modifier      = 0;
			char ch;
			flags_t flags;

			format = _get_flags(format, &flags);
			format = _get_width(format, &width, &aq);
			format = _get_precision(format, &precision, &aq);
			format = _get_modifier(format, &modifier);

			if (width < 0) {
				/* negative width means positive width and left justified */
				width = -width;

				/* justify, overrides padding */
				flags.justify = 1;
				flags.padding = 0;
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
										  ch, width, &flags);
				}
#else
				s_ptr = "0.0";
#endif
				_output_string(ch, s_ptr, precision, &width, &flags, ctx);
				break;

			/* integer format of sorts */
			case 'p':
				precision    = 1;
				ch           = 'x';
				flags.prefix = 1;
				s_ptr        = _unsigned_itoa(num_buf, sizeof(num_buf), ch, precision,
											  (uintptr_t)va_arg(aq, void *), width, &flags);
				_output_string(ch, s_ptr, precision, &width, &flags, ctx);
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
										   (unsigned char)va_arg(aq, unsigned int), width, &flags);
					break;
				case MOD_SHORT:
					s_ptr =
						_unsigned_itoa(num_buf, sizeof(num_buf), ch, precision,
									   (unsigned short int)va_arg(aq, unsigned int), width, &flags);
					break;
				case MOD_LONG:
					s_ptr = _unsigned_itoa(num_buf, sizeof(num_buf), ch, precision,
										   va_arg(aq, unsigned long int), width, &flags);
					break;
				case MOD_LONG_LONG:
					s_ptr = _unsigned_itoa(num_buf, sizeof(num_buf), ch, precision,
										   va_arg(aq, unsigned long long int), width, &flags);
					break;
				case MOD_INTMAX_T:
					s_ptr = _unsigned_itoa(num_buf, sizeof(num_buf), ch, precision,
										   va_arg(aq, uintmax_t), width, &flags);
					break;
				case MOD_SIZE_T:
					s_ptr = _unsigned_itoa(num_buf, sizeof(num_buf), ch, precision,
										   va_arg(aq, size_t), width, &flags);
					break;
				case MOD_PTRDIFF_T:
					/* NOTE: we really want uptrdiff_t or something to that effect, but
					 * unsigned long will have to do */
					s_ptr = _unsigned_itoa(num_buf, sizeof(num_buf), ch, precision,
										   (unsigned long)va_arg(aq, ptrdiff_t), width, &flags);
					break;
				default:
					s_ptr = _unsigned_itoa(num_buf, sizeof(num_buf), ch, precision,
										   va_arg(aq, unsigned int), width, &flags);
					break;
				}
				_output_string(ch, s_ptr, precision, &width, &flags, ctx);
				break;

			case 'i':
			case 'd':
				if (precision < 0) {
					precision = 1;
				}

				switch (modifier) {
				case MOD_CHAR:
					s_ptr = _signed_itoa(num_buf, sizeof(num_buf), precision,
										 (signed char)va_arg(aq, int), width, &flags);
					break;
				case MOD_SHORT:
					s_ptr = _signed_itoa(num_buf, sizeof(num_buf), precision,
										 (short int)va_arg(aq, int), width, &flags);
					break;
				case MOD_LONG:
					s_ptr = _signed_itoa(num_buf, sizeof(num_buf), precision, va_arg(aq, long int),
										 width, &flags);
					break;
				case MOD_LONG_LONG:
					s_ptr = _signed_itoa(num_buf, sizeof(num_buf), precision,
										 va_arg(aq, long long int), width, &flags);
					break;
				case MOD_INTMAX_T:
					s_ptr = _signed_itoa(num_buf, sizeof(num_buf), precision, va_arg(aq, intmax_t),
										 width, &flags);
					break;
				case MOD_SIZE_T:
					s_ptr = _signed_itoa(num_buf, sizeof(num_buf), precision, va_arg(aq, ssize_t),
										 width, &flags);
					break;
				case MOD_PTRDIFF_T:
					s_ptr = _signed_itoa(num_buf, sizeof(num_buf), precision, va_arg(aq, ptrdiff_t),
										 width, &flags);
					break;
				default:
					s_ptr = _signed_itoa(num_buf, sizeof(num_buf), precision, va_arg(aq, int),
										 width, &flags);
					break;
				}
				_output_string(ch, s_ptr, precision, &width, &flags, ctx);
				break;

			case 'c':
				/* char is promoted to an int when pushed on the stack */
				num_buf[0] = (char)va_arg(aq, long int);
				num_buf[1] = '\0';
				s_ptr      = num_buf;
				_output_string(ch, s_ptr, precision, &width, &flags, ctx);
				break;

			case 's':
				s_ptr = va_arg(aq, char *);
				_output_string(ch, s_ptr, precision, &width, &flags, ctx);
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
							*(p.p_char) = (char)ctx->written;
							break;
						case MOD_SHORT:
							*(p.p_short) = (short)ctx->written;
							break;
						case MOD_LONG:
							*(p.p_long) = (long)ctx->written;
							break;
						case MOD_LONG_LONG:
							*(p.p_longlong) = (long long)ctx->written;
							break;
						default:
							*(p.p_int) = (int)ctx->written;
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
	return (int)ctx->written;
}
