#undef NDEBUG
#include <assert.h>
#include <ctype.h>
#include <string.h>

static void test_isalnum(void) {
	int ch;
	for (ch = 0; ch < 256; ++ch) {
		if (strchr("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789", ch)) {
			assert(isalnum(ch));
		} else {
			assert(!isalnum(ch));
		}
	}
}

static void test_isalpha(void) {
	int ch;
	for (ch = 0; ch < 256; ++ch) {
		if (strchr("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz", ch)) {
			assert(isalpha(ch));
		} else {
			assert(!isalpha(ch));
		}
	}
}

static void test_islower(void) {
	int ch;
	for (ch = 0; ch < 256; ++ch) {
		if (strchr("abcdefghijklmnopqrstuvwxyz", ch)) {
			assert(islower(ch));
		} else {
			assert(!islower(ch));
		}
	}
}

static void test_isupper(void) {
	int ch;
	for (ch = 0; ch < 256; ++ch) {
		if (strchr("ABCDEFGHIJKLMNOPQRSTUVWXYZ", ch)) {
			assert(isupper(ch));
		} else {
			assert(!isupper(ch));
		}
	}
}

static void test_isdigit(void) {
	int ch;
	for (ch = 0; ch < 256; ++ch) {
		if (strchr("0123456789", ch)) {
			assert(isdigit(ch));
		} else {
			assert(!isdigit(ch));
		}
	}
}

static void test_isxdigit(void) {
	int ch;
	for (ch = 0; ch < 256; ++ch) {
		if (strchr("0123456789ABCDEFabcdef", ch)) {
			assert(isxdigit(ch));
		} else {
			assert(!isxdigit(ch));
		}
	}
}

static void test_isspace(void) {
	int ch;
	for (ch = 0; ch < 256; ++ch) {
		if (strchr(" \t\f\n\r\v", ch)) {
			assert(isspace(ch));
		} else {
			assert(!isspace(ch));
		}
	}
}

static void test_isblank(void) {
#ifdef _HAS_C99
	int ch;
	for (ch = 0; ch < 256; ++ch) {
		if (strchr(" \t", ch)) {
			assert(isblank(ch));
		} else {
			assert(!isblank(ch));
		}
	}
#endif
}

static void test_iscntrl(void) {
	int ch;
	for (ch = 0; ch < 256; ++ch) {
		if (ch < 0x20 || ch == 0x7f) {
			assert(iscntrl(ch));
		} else {
			assert(!iscntrl(ch));
		}
	}
}

static void test_tolower(void) {
	int ch;
	for (ch = 0; ch < 256; ++ch) {
		if (isupper(ch)) {
			assert(islower(tolower(ch)));
		}
	}
}

static void test_toupper(void) {
	int ch;
	for (ch = 0; ch < 256; ++ch) {
		if (islower(ch)) {
			assert(isupper(toupper(ch)));
		}
	}
}

static void test_ispunct(void) {
	int ch;
	for (ch = 0; ch < 256; ++ch) {
		if (strchr("!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~", ch)) {
			assert(ispunct(ch));
		} else {
			assert(!ispunct(ch));
		}
	}
}

static void test_isprint(void) {
	int ch;
	for (ch = 0; ch < 256; ++ch) {
		if (strchr("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!\"#$%&'()*+,-./"
		           ":;<=>?@[\\]^_`{|}~ ",
		           ch)) {
			assert(isprint(ch));
		} else {
			assert(!isprint(ch));
		}
	}
}

static void test_isgraph(void) {
	int ch;
	for (ch = 0; ch < 256; ++ch) {
		if (strchr("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!\"#$%&'()*+,-./"
		           ":;<=>?@[\\]^_`{|}~",
		           ch)) {
			assert(isgraph(ch));
		} else {
			assert(!isgraph(ch));
		}
	}
}

int main() {
	test_isalnum();
	test_isalpha();
	test_islower();
	test_isupper();
	test_isdigit();
	test_isxdigit();
	test_isspace();
	test_isblank();
	test_iscntrl();
	test_tolower();
	test_toupper();
	test_ispunct();
	test_isprint();
	test_isgraph();
	return 0;
}
