
#define __ELIBC_SOURCE
#include <time.h>
#include <wchar.h>

#define DO_H(s) (void)0
#define DO_M(s) (void)0
#define DO_S(s) (void)0
#define DO_Y(s) (void)0
#define DO_m(s) (void)0
#define DO_d(s) (void)0
#define DO_y(s) (void)0
#define DO_I(s) (void)0
#define DO_p(s) (void)0

/* TODO(eteran): implement this */

#define DO_WRITE_CHAR(s, n, ch) \
	if (n != 0) {               \
	}

/*------------------------------------------------------------------------------
// Name: wcsftime
//----------------------------------------------------------------------------*/
size_t wcsftime(wchar_t *s, size_t max, const wchar_t *format, const struct tm *tm) {

	(void)max;
	(void)tm;

	while (*format != L'\0') {
		if (*format == L'%') {
			++format;
			switch (*format) {
			case L'a':
			case L'A':
			case L'b':
			case L'B':
			case L'c':
			case L'C':
			case L'e':
			case L'E':
			case L'G':
			case L'g':
			case L'h':
			case L'I':
			case L'j':
			case L'k':
			case L'l':
			case L'O':
			case L'p':
			case L'P':
			case L's':
			case L'u':
			case L'U':
			case L'V':
			case L'w':
			case L'W':
			case L'x':
			case L'X':
			case L'y':
			case L'z':
			case L'Z':
			case L'+':
				break;

			case L'r':
				DO_I(s);
				*s++ = '/';
				DO_M(s);
				*s++ = '/';
				DO_S(s);
				*s++ = ' ';
				DO_p(s);
				break;

			case L'D':
				DO_m(s);
				*s++ = '/';
				DO_d(s);
				*s++ = '/';
				DO_y(s);
				break;

			case L'd':
				DO_d(s);
				break;

			case L'F':
				DO_Y(s);
				*s++ = '-';
				DO_M(s);
				*s++ = '-';
				DO_d(s);
				break;

			case L'H':
				DO_H(s);
				break;

			case L'm':
				DO_m(s);
				break;

			case 'M':
				DO_M(s);
				break;

			case L'n':
				*s++ = '\n';
				break;
			case L'R':
				DO_H(s);
				*s++ = ':';
				DO_M(s);
				break;

			case L'S':
				DO_S(s);
				break;

			case L't':
				*s++ = '\t';
				break;

			case L'T':
				DO_H(s);
				*s++ = ':';
				DO_M(s);
				*s++ = ':';
				DO_S(s);
				break;

			case L'Y':
				DO_Y(s);
				break;

			case L'%':
				*s++ = '%';
				break;
			}
		}
		++format;
	}

	return 0;
}
