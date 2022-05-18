
#define _ELIBC_SOURCE
#include <ctype.h>
#include <limits.h>
#include <stdarg.h>
#include <stdlib.h>

/* TODO(eteran): finish this! */

#define CONVERT_NUMBER(temp_name, type, base)                                                      \
	do {                                                                                           \
		conversion_pointers.temp_name = va_arg(ap, type *);                                        \
		*(conversion_pointers.temp_name) = strtol(str, &endptr, (base));                           \
		++assign_count;                                                                            \
		str = endptr;                                                                              \
	} while (0)

#define BITSET(name, N) unsigned char name[N / CHAR_BIT]
#define SET_BIT(name, I)                                                                           \
	do {                                                                                           \
		name[I / CHAR_BIT] |= (1 << (I % CHAR_BIT));                                               \
	} while (0)
#define TEST_BIT(name, I) (int)(name[I / CHAR_BIT] & (1 << (I % CHAR_BIT)))
#define FLIP_BITS(name, N)                                                                         \
	do {                                                                                           \
		int i;                                                                                     \
		for (i = 0; i < (N / CHAR_BIT); ++i) {                                                     \
			name[i] = ~name[i];                                                                    \
		}                                                                                          \
	} while (0)

/*------------------------------------------------------------------------------
// Name: vsscanf
//----------------------------------------------------------------------------*/
int vsscanf(const char *_RESTRICT str, const char *_RESTRICT format, va_list ap) {
	int assign_count = 0;
	int done = 0;
	char *endptr = 0;
	const char *str_ptr = str;

	union {
		char *char_ptr;
		unsigned int *uint_ptr;
		int *int_ptr;
		float *float_ptr;
		void *void_ptr;
	} conversion_pointers = {0};

	while (*format != '\0' && !done) {
		switch (*format) {
		case '%':
			switch (format[1]) {
			case 'D':
			case 'd':
				CONVERT_NUMBER(int_ptr, int, 10);
				break;

			case 'i':
				CONVERT_NUMBER(int_ptr, int, 0);
				break;

			case 'o':
				CONVERT_NUMBER(uint_ptr, unsigned int, 8);
				break;

			case 'u':
				CONVERT_NUMBER(uint_ptr, unsigned int, 10);
				break;

			case 'x':
			case 'X':
				CONVERT_NUMBER(uint_ptr, unsigned int, 16);
				break;

			case 'f':
			case 'e':
			case 'g':
			case 'E':
#ifdef _HAS_FPU
				conversion_pointers.float_ptr = va_arg(ap, float *);
				*(conversion_pointers.float_ptr) = strtof(str, &endptr);
				++assign_count;
				str = endptr;
#endif
				break;

			case 's':
				conversion_pointers.char_ptr = va_arg(ap, char *);
				while (isspace(*str)) {
					++str;
				}

				while (!isspace(*str)) {
					*(conversion_pointers.char_ptr)++ = *str++;
				}
				*(conversion_pointers.char_ptr) = '\0';
				++assign_count;
				break;

			case 'c':
				conversion_pointers.char_ptr = va_arg(ap, char *);
				*(conversion_pointers.char_ptr) = *str++;
				++assign_count;
				break;

			case '[':
				do {
					/* I am assuming 8-bit characters,
					 * is it possible that this is not the case?
					 */
					BITSET(charset, 256) = {0};
					const char *p = &format[2];
					const int invert = (*p == '^');
					char ch = '\0';

					if (invert) {
						++p;
					}

					if (*p == ']') {
						SET_BIT(charset, (int)']');
						++p;
					}

					while (*p != '\0' && *p != ']') {
						char range_start = ch;
						ch = *p++;
						if (ch == '-') {
							if (*p == '\0' || *p == ']') {
								SET_BIT(charset, (int)'-');
							} else {
								if (range_start <= *p) {
									char range_ch;
									for (range_ch = range_start; range_ch != *p; ++range_ch) {
										SET_BIT(charset, (int)range_ch);
									}
								}
							}
						} else {
							SET_BIT(charset, (int)ch);
						}
					}

					if (invert) {
						FLIP_BITS(charset, 256);
					}

					do {
						conversion_pointers.char_ptr = va_arg(ap, char *);
						while (TEST_BIT(charset, *str)) {
							*(conversion_pointers.char_ptr)++ = *str++;
						}
						*(conversion_pointers.char_ptr) = '\0';
						++assign_count;
					} while (0);
				} while (0);
				break;

			case 'p':
				conversion_pointers.void_ptr = va_arg(ap, void *);
				*(conversion_pointers.uint_ptr) = strtoul(str, &endptr, 16);
				++assign_count;
				str = endptr;
				break;

			case 'n':
				conversion_pointers.uint_ptr = va_arg(ap, unsigned int *);
				*(conversion_pointers.uint_ptr) = (str - str_ptr);
				++assign_count;
				break;

			case '%':
				if (*str != '%') {
					return assign_count;
				}
				++str;
				++format;
				break;
			default:
				if (*str != format[1]) {
					return assign_count;
				}
				++str;
				break;
			}
			break;
		default:
			done = (*str != *format);
			++str;
			break;
		}
		++format;
	}

	return assign_count;
}

#undef CONVERT_NUMBER
