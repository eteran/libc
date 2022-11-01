
#define _ELIBC_SOURCE
#include <assert.h>
#include <stdio.h>
#include <time.h>

#define WRITE_FORMATTED(fmt, value)                                                                \
	do {                                                                                           \
		const int chunk = snprintf(ctx->ptr, ctx->size, (fmt), (value));                           \
		if (chunk < 0) {                                                                           \
			return 0;                                                                              \
		}                                                                                          \
		ctx->ptr += chunk;                                                                         \
		ctx->size -= (size_t)chunk;                                                                \
		ctx->written += (size_t)chunk;                                                             \
	} while (0)

#define DO_H()      WRITE_FORMATTED("%.2i", tm->tm_hour)
#define DO_M()      WRITE_FORMATTED("%.2i", tm->tm_min)
#define DO_S()      WRITE_FORMATTED("%.2d", tm->tm_sec)
#define DO_Y()      WRITE_FORMATTED("%d", 1900 + tm->tm_year)
#define DO_m()      WRITE_FORMATTED("%.2d", tm->tm_mon + 1)
#define DO_d()      WRITE_FORMATTED("%.2d", tm->tm_mday)
#define DO_e()      WRITE_FORMATTED("%2d", tm->tm_mday)
#define DO_y()      WRITE_FORMATTED("%.2i", tm->tm_year % 100)
#define DO_p()      WRITE_FORMATTED("%s", (tm->tm_hour < 12) ? "AM" : "PM")
#define DO_char(ch) WRITE_FORMATTED("%c", ch)
#define DO_I()      WRITE_FORMATTED("%.2i", (tm->tm_hour > 12) ? tm->tm_hour - 12 : tm->tm_hour)
#define DO_a()      WRITE_FORMATTED("%s", wday_name[tm->tm_wday])
#define DO_b()      WRITE_FORMATTED("%s", mon_name[tm->tm_mon])
#define DO_A()      WRITE_FORMATTED("%s", wday_name_full[tm->tm_wday])
#define DO_B()      WRITE_FORMATTED("%s", mon_name_full[tm->tm_mon])
#define DO_C()      WRITE_FORMATTED("%.2d", (1900 + tm->tm_year) / 100)
#define DO_j()      WRITE_FORMATTED("%d", tm->tm_yday)

/* TODO(eteran): implement this */

struct __elibc_strftime_context {
	char *ptr;
	size_t size;
	size_t capacity;
	size_t written;
};

size_t __elibc_strftime(const char *format, struct __elibc_strftime_context *ctx,
                        const struct tm *tm) {

	static const char wday_name[][4] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

	static const char mon_name[][4] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
	                                   "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

	static const char wday_name_full[][10] = {"Sunday",   "Monday", "Tuesday", "Wednesday",
	                                          "Thursday", "Friday", "Saturday"};

	static const char mon_name_full[][10] = {"January",   "February", "March",    "April",
	                                         "May",       "June",     "July",     "August",
	                                         "September", "October",  "November", "December"};
	assert(ctx);
	assert(tm);
	assert(format);

	while (*format != '\0') {
		if (*format == '%') {
			++format;
			switch (*format) {
			case 'a':
				assert(tm->tm_wday < 7);
				DO_a();
				break;

			case 'h': /* NOTE(eteran): Equivalent to %b. */
			case 'b':
				assert(tm->tm_mon < 12);
				DO_b();
				break;

			case 'A':
				assert(tm->tm_wday < 7);
				DO_A();
				break;

			case 'B':
				assert(tm->tm_mon < 12);
				DO_B();
				break;

			case 'c':
				/* %a %b %e %H:%M:%S %Y */
				DO_a();
				DO_char(' ');
				DO_b();
				DO_char(' ');
				DO_e();
				DO_char(' ');
				DO_H();
				DO_char(':');
				DO_M();
				DO_char(':');
				DO_S();
				DO_char(' ');
				DO_Y();
				break;

			case 'C':
				DO_C();
				break;

			case 'e':
				DO_e();
				break;

			case 'j':
				DO_j();
				break;

			case 'E':
			case 'G':
			case 'g':
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

	return ctx->written < ctx->capacity ? ctx->written - 1 : 0;
}

/*------------------------------------------------------------------------------
// Name: strftime
//----------------------------------------------------------------------------*/
size_t strftime(char *s, size_t max, const char *format, const struct tm *tm) {

	struct __elibc_strftime_context ctx;
	ctx.ptr = s;
	ctx.size = max;
	ctx.capacity = max;
	ctx.written = 0;

	return __elibc_strftime(format, &ctx, tm);
}
