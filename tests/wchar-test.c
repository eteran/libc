#undef NDEBUG
#define _ELIBC_SOURCE
#include <assert.h>
#include <errno.h>
#include <limits.h>
#include <locale.h>
#include <stdio.h>
#include <string.h>
#include <wchar.h>

/* Test for NUL byte processing via empty string.  */
static void test_utf8_empty(void) {
	wchar_t wc;
	mbstate_t s;

	wc = 42;                               /* arbitrary number */
	memset(&s, 0, sizeof(s));              /* get s into initial state */
	assert(mbrtowc(NULL, "", 1, &s) == 0); /* valid terminator */
	assert(mbsinit(&s));

	wc = 42;                                           /* arbitrary number */
	memset(&s, 0, sizeof(s));                          /* get s into initial state */
	assert(mbrtowc(&wc, "\xE2", 1, &s) == (size_t)-2); /* 1st byte processed */
	assert(mbrtowc(NULL, "", 1, &s) == (size_t)-1);    /* invalid terminator */

	wc = 42;                                           /* arbitrary number */
	memset(&s, 0, sizeof(s));                          /* get s into initial state */
	assert(mbrtowc(&wc, "\xE2", 1, &s) == (size_t)-2); /* 1st byte processed */
	assert(mbrtowc(&wc, "\x89", 1, &s) == (size_t)-2); /* 2nd byte processed */
	assert(mbrtowc(NULL, "", 1, &s) == (size_t)-1);    /* invalid terminator */

	wc = 42;                                           /* arbitrary number */
	memset(&s, 0, sizeof(s));                          /* get s into initial state */
	assert(mbrtowc(&wc, "\xE2", 1, &s) == (size_t)-2); /* 1st byte processed */
	assert(mbrtowc(&wc, "\x89", 1, &s) == (size_t)-2); /* 2nd byte processed */
	assert(mbrtowc(&wc, "\xA0", 1, &s) == 1);          /* 3nd byte processed */
	assert(mbrtowc(NULL, "", 1, &s) == 0);             /* valid terminator */
	assert(mbsinit(&s));
}

/* Test for NUL byte processing via NULL string.  */
static void test_utf8_null(void) {
	wchar_t wc;
	mbstate_t s;

	wc = 42;                                 /* arbitrary number */
	memset(&s, 0, sizeof(s));                /* get s into initial state */
	assert(mbrtowc(NULL, NULL, 0, &s) == 0); /* valid terminator */
	assert(mbsinit(&s));

	wc = 42;                                           /* arbitrary number */
	memset(&s, 0, sizeof(s));                          /* get s into initial state */
	assert(mbrtowc(&wc, "\xE2", 1, &s) == (size_t)-2); /* 1st byte processed */
	assert(mbrtowc(NULL, NULL, 0, &s) == (size_t)-1);  /* invalid terminator */

	wc = 42;                                           /* arbitrary number */
	memset(&s, 0, sizeof(s));                          /* get s into initial state */
	assert(mbrtowc(&wc, "\xE2", 1, &s) == (size_t)-2); /* 1st byte processed */
	assert(mbrtowc(&wc, "\x89", 1, &s) == (size_t)-2); /* 2nd byte processed */
	assert(mbrtowc(NULL, NULL, 0, &s) == (size_t)-1);  /* invalid terminator */

	wc = 42;                                           /* arbitrary number */
	memset(&s, 0, sizeof(s));                          /* get s into initial state */
	assert(mbrtowc(&wc, "\xE2", 1, &s) == (size_t)-2); /* 1st byte processed */
	assert(mbrtowc(&wc, "\x89", 1, &s) == (size_t)-2); /* 2nd byte processed */
	assert(mbrtowc(&wc, "\xA0", 1, &s) == 1);          /* 3nd byte processed */
	assert(mbrtowc(NULL, NULL, 0, &s) == 0);           /* valid terminator */
	assert(mbsinit(&s));
}

static void test_utf8_codepoints(void) {
	wchar_t wc;
	mbstate_t s;
	const char str[] = "\xe0\xa0\x80";

	wc = 42;                  /* arbitrary number */
	memset(&s, 0, sizeof(s)); /* get s into initial state */
	assert(mbrtowc(&wc, str, 1, &s) == (size_t)-2);
	assert(mbrtowc(&wc, str + 1, 2, &s) == 2);
	assert(wc == 0x800);

	wc = 42;                  /* arbitrary number */
	memset(&s, 0, sizeof(s)); /* get s into initial state */
	assert(mbrtowc(&wc, str, 3, &s) == 3);
	assert(wc == 0x800);
}

static void test_utf8_bytewise(void) {
	wchar_t wc;
	mbstate_t s;

	wc = 42;                                           /* arbitrary number */
	memset(&s, 0, sizeof(s));                          /* get s into initial state */
	assert(mbrtowc(&wc, "\xE2", 1, &s) == (size_t)-2); /* 1st byte processed */
	assert(mbrtowc(&wc, "\x89", 1, &s) == (size_t)-2); /* 2nd byte processed */
	assert(wc == 42);                                  /* no value has not been stored into &wc yet */
	assert(mbrtowc(&wc, "\xA0", 1, &s) == 1);          /* 3nd byte processed */
	assert(wc == 0x2260);                              /* E2 89 A0 = U+2260 (not equal) decoded correctly */
	assert(mbrtowc(&wc, "", 1, &s) == 0);              /* test final byte processing */
	assert(wc == 0);                                   /* test final byte decoding */
}

static void test_mbrtowc(void) {

	mbstate_t state = {0, 0, 0};

	/*    u8"z\u00df\u6c34\U0001F34C" */
	/* or u8"zß水🍌" */
	const char input[]            = "\x7a\xc3\x9f\xe6\xb0\xb4\xf0\x9f\x8d\x8c";
	wchar_t output[sizeof(input)] = L"";
	const size_t in_sz            = sizeof(input);
	const char *first             = input;
	const char *last              = input + in_sz;
	wchar_t *out_ptr              = output;
	size_t rc;

	while ((rc = mbrtowc(out_ptr, first, (size_t)(last - first), &state)) > 0) {
		first += rc;
		++out_ptr;
	}

	assert((out_ptr - output + 1) == 5);
	assert(output[0] == 0x7a);
	assert(output[1] == 0xdf);
	assert(output[2] == 0x6c34);
	assert(output[3] == 0x1f34c);
	assert(output[4] == L'\0');
}

void test_wcstol(void) {

	const wchar_t *p = L"10 200000000000000000000000000000 30 -40";
	wchar_t *end;
	long i;

	errno = 0;
	i     = wcstol(p, &end, 10);
	assert(errno == 0);
	assert(i == 10);
	p = end;

	errno = 0;
	i     = wcstol(p, &end, 10);
	assert(errno == ERANGE);
	assert(i == LONG_MAX);
	p = end;

	errno = 0;
	i     = wcstol(p, &end, 10);
	assert(errno == 0);
	assert(i == 30);
	p = end;

	errno = 0;
	i     = wcstol(p, &end, 10);
	assert(errno == 0);
	assert(i == -40);
	p = end;
}

void test_wcstoll(void) {

	const wchar_t *p = L"10 200000000000000000000000000000 30 -40";
	wchar_t *end;
	long long i;

	errno = 0;
	i     = wcstoll(p, &end, 10);
	assert(errno == 0);
	assert(i == 10);
	p = end;

	errno = 0;
	i     = wcstoll(p, &end, 10);
	assert(errno == ERANGE);
	assert(i == LLONG_MAX);
	p = end;

	errno = 0;
	i     = wcstoll(p, &end, 10);
	assert(errno == 0);
	assert(i == 30);
	p = end;

	errno = 0;
	i     = wcstoll(p, &end, 10);
	assert(errno == 0);
	assert(i == -40);
	p = end;
}

void test_wcstoul(void) {
	const wchar_t *p = L"10 200000000000000000000000000000 30 40";
	wchar_t *end;
	unsigned long i;

	errno = 0;
	i     = wcstoul(p, &end, 10);
	assert(errno == 0);
	assert(i == 10);
	p = end;

	errno = 0;
	i     = wcstoul(p, &end, 10);
	assert(errno == ERANGE);
	assert(i == ULONG_MAX);
	p = end;

	errno = 0;
	i     = wcstoul(p, &end, 10);
	assert(errno == 0);
	assert(i == 30);
	p = end;

	errno = 0;
	i     = wcstoul(p, &end, 10);
	assert(errno == 0);
	assert(i == 40);
	p = end;
}

void test_wcstoull(void) {
	const wchar_t *p = L"10 200000000000000000000000000000 30 40";
	wchar_t *end;
	unsigned long i;

	errno = 0;
	i     = wcstoull(p, &end, 10);
	assert(errno == 0);
	assert(i == 10);
	p = end;

	errno = 0;
	i     = wcstoull(p, &end, 10);
	assert(errno == ERANGE);
	assert(i == ULLONG_MAX);
	p = end;

	errno = 0;
	i     = wcstoull(p, &end, 10);
	assert(errno == 0);
	assert(i == 30);
	p = end;

	errno = 0;
	i     = wcstoull(p, &end, 10);
	assert(errno == 0);
	assert(i == 40);
	p = end;
}

int main(void) {

	/* TODO(eteran): support close enough locales, such as "en_US.utf8" */
	setlocale(LC_ALL, "en_US.UTF-8");

	test_mbrtowc();
	test_utf8_bytewise();
	test_utf8_codepoints();
	test_utf8_empty();
	test_utf8_null();
	test_wcstol();
	test_wcstoll();
	test_wcstoul();
	test_wcstoull();

	return 0;
}
