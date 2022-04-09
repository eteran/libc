
#define __ELIBC_SOURCE
#include <assert.h>
#include <stdio.h>
#include <time.h>

#define DO_H()                                                                                     \
	do {                                                                                           \
		int chunk = snprintf(s, space, "%.2i", tm->tm_hour);                                       \
		if (chunk >= space) {                                                                      \
			return 0;                                                                              \
		}                                                                                          \
		s += chunk;                                                                                \
	} while (0)

#define DO_M()                                                                                     \
	do {                                                                                           \
		int chunk = snprintf(s, space, "%.2i", tm->tm_min);                                        \
		if (chunk >= space) {                                                                      \
			return 0;                                                                              \
		}                                                                                          \
		s += chunk;                                                                                \
	} while (0)

#define DO_S()                                                                                     \
	do {                                                                                           \
		int chunk = snprintf(s, space, "%.2d", tm->tm_sec);                                        \
		if (chunk >= space) {                                                                      \
			return 0;                                                                              \
		}                                                                                          \
		s += chunk;                                                                                \
	} while (0)

#define DO_Y()                                                                                     \
	do {                                                                                           \
		int chunk = snprintf(s, space, "%d", 1900 + tm->tm_year);                                  \
		if (chunk >= space) {                                                                      \
			return 0;                                                                              \
		}                                                                                          \
		s += chunk;                                                                                \
	} while (0)

#define DO_m()                                                                                     \
	do {                                                                                           \
		int chunk = snprintf(s, space, "%.2d", tm->tm_mon + 1);                                    \
		if (chunk >= space) {                                                                      \
			return 0;                                                                              \
		}                                                                                          \
		s += chunk;                                                                                \
	} while (0)

#define DO_d()                                                                                     \
	do {                                                                                           \
		int chunk = snprintf(s, space, "%.2d", tm->tm_mday);                                       \
		if (chunk >= space) {                                                                      \
			return 0;                                                                              \
		}                                                                                          \
		s += chunk;                                                                                \
	} while (0)

#define DO_e()                                                                                     \
	do {                                                                                           \
		int chunk = snprintf(s, space, "%2d", tm->tm_mday);                                        \
		if (chunk >= space) {                                                                      \
			return 0;                                                                              \
		}                                                                                          \
		s += chunk;                                                                                \
	} while (0)

#define DO_y()                                                                                     \
	do {                                                                                           \
		int chunk = snprintf(s, space, "%.2i", tm->tm_year % 100);                                 \
		if (chunk >= space) {                                                                      \
			return 0;                                                                              \
		}                                                                                          \
		s += chunk;                                                                                \
	} while (0)

#define DO_I()                                                                                     \
	do {                                                                                           \
		int chunk;                                                                                 \
		int hour = tm->tm_hour;                                                                    \
		if (hour > 12)                                                                             \
			hour -= 12;                                                                            \
		chunk = snprintf(s, space, "%.2i", hour);                                                  \
		if (chunk >= space) {                                                                      \
			return 0;                                                                              \
		}                                                                                          \
		s += chunk;                                                                                \
	} while (0)

#define DO_p()                                                                                     \
	do {                                                                                           \
		int chunk = snprintf(s, space, "%s", (tm->tm_hour < 12) ? "AM" : "PM");                    \
		if (chunk >= space)                                                                        \
			return 0;                                                                              \
		s += chunk;                                                                                \
	} while (0)

#define DO_char(ch)                                                                                \
	do {                                                                                           \
		int chunk = snprintf(s, space, "%c", ch);                                                  \
		if (chunk >= space)                                                                        \
			return 0;                                                                              \
		s += chunk;                                                                                \
	} while (0)

/* TODO(eteran): implement this */

/*------------------------------------------------------------------------------
// Name: strftime
//----------------------------------------------------------------------------*/
size_t strftime(char *s, size_t max, const char *format, const struct tm *tm) {

	char *const dest = s;

	int space = (s + max) - s;

	assert(tm);
	assert(format);

	while (*format != '\0') {
		if (*format == '%') {
			++format;
			switch (*format) {
			case 'a':
			case 'A':
			case 'h': /* NOTE(eteran): Equivalent to %b. */
			case 'b':
			case 'B':
			case 'c':
			case 'C':
				break;

			case 'e':
				DO_e();
				break;

			case 'E':
			case 'G':
			case 'g':
			case 'j':
			case 'k':
			case 'l':
			case 'O':
			case 'P':
			case 's':
			case 'u':
			case 'U':
			case 'V':
			case 'w':
			case 'W':
			case 'x':
			case 'X':
			case 'z':
			case 'Z':
			case '+':
				break;

			case 'y':
				DO_y();
				break;

			case 'p':
				DO_p();
				break;

			case 'I':
				DO_I();
				break;

			case 'r':
				DO_I();
				DO_char('/');
				DO_M();
				DO_char('/');
				DO_S();
				DO_char(' ');
				DO_p();
				break;

			case 'D':
				DO_m();
				DO_char('/');
				DO_d();
				DO_char('/');
				DO_y();
				break;

			case 'd':
				DO_d();
				break;

			case 'F':
				DO_Y();
				DO_char('-');
				DO_M();
				DO_char('-');
				DO_d();
				break;

			case 'H':
				DO_H();
				break;

			case 'm':
				DO_m();
				break;

			case 'M':
				DO_M();
				break;

			case 'n':
				DO_char('\n');
				break;

			case 'R':
				DO_H();
				DO_char(':');
				DO_M();
				break;

			case 'S':
				DO_S();
				break;

			case 't':
				DO_char('\t');
				break;

			case 'T':
				DO_H();
				DO_char(':');
				DO_M();
				DO_char(':');
				DO_S();
				break;

			case 'Y':
				DO_Y();
				break;

			case '%':
				DO_char('%');
				break;

			default:
				assert(0);
			}
		} else {
			DO_char(*format);
		}
		++format;
	}

	return s - dest;
}
