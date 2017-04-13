
#define __ELIBC_SOURCE
#include <time.h>
#include <assert.h>

#define DO_H(s) (void)0
#define DO_M(s) (void)0
#define DO_S(s) (void)0
#define DO_Y(s) (void)0
#define DO_m(s) (void)0
#define DO_d(s) (void)0
#define DO_y(s) (void)0
#define DO_I(s) (void)0
#define DO_p(s) (void)0

/* TODO: implement this */

#define DO_WRITE_CHAR(s, n, ch) \
if(n != 0) {                    \
}

/*------------------------------------------------------------------------------
// Name: strftime
//----------------------------------------------------------------------------*/
size_t strftime(char *s, size_t max, const char *format, const struct tm *tm) {

	(void)max;
	(void)tm;

	assert(tm);
	assert(format);

	while(*format != '\0') {
		if(*format == '%') {
			++format;
			switch(*format) {
			case 'a':
			case 'A':
			case 'b':
			case 'B':
			case 'c':
			case 'C':
			case 'e':
			case 'E':
			case 'G':
			case 'g':
			case 'h':
			case 'I':
			case 'j':
			case 'k':
			case 'l':
			case 'O':
			case 'p':
			case 'P':
			case 's':
			case 'u':
			case 'U':
			case 'V':
			case 'w':
			case 'W':
			case 'x':
			case 'X':
			case 'y':
			case 'z':
			case 'Z':
			case '+':
				break;

			case 'r':
				DO_I(s);
				*s++ = '/';
				DO_M(s);
				*s++ = '/';
				DO_S(s);
				*s++ = ' ';
				DO_p(s);

			case 'D':
				DO_m(s);
				*s++ = '/';
				DO_d(s);
				*s++ = '/';
				DO_y(s);
				break;

			case 'd':
				DO_d(s);
				break;

			case 'F':
				DO_Y(s);
				*s++ = '-';
				DO_M(s);
				*s++ = '-';
				DO_d(s);
				break;

			case 'H':
				DO_H(s);
				break;

			case 'm':
				DO_m(s);
				break;

			case 'M':
				DO_M(s);
				break;

			case 'n':
				*s++ = '\n';
				break;
			case 'R':
				DO_H(s);
				*s++ = ':';
				DO_M(s);
				break;

			case 'S':
				DO_S(s);
				break;

			case 't':
				*s++ = '\t';
				break;

			case 'T':
				DO_H(s);
				*s++ = ':';
				DO_M(s);
				*s++ = ':';
				DO_S(s);
				break;

			case 'Y':
				DO_Y(s);
				break;

			case '%':
				*s++ = '%';
				break;
			}
		}
		++format;
	}

	return 0;
}
