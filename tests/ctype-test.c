/* 100% Coverage */

#undef NDEBUG
#define _ELIBC_SOURCE
#include <assert.h>
#include <ctype.h>
#include <string.h>

#define TEST_CTYPE(name, charset)                                                                  \
	static void test_##name(void) {                                                                \
		int ch;                                                                                    \
		for (ch = 1; ch < 256; ++ch) {                                                             \
			if (strchr(charset, ch)) {                                                             \
				assert(name(ch));                                                                  \
			} else {                                                                               \
				assert(!name(ch));                                                                 \
			}                                                                                      \
		}                                                                                          \
		assert(!name('\0'));                                                                       \
	}

TEST_CTYPE(isalnum, "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789")
TEST_CTYPE(isalpha, "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz")
TEST_CTYPE(islower, "abcdefghijklmnopqrstuvwxyz")
TEST_CTYPE(isupper, "ABCDEFGHIJKLMNOPQRSTUVWXYZ")
TEST_CTYPE(isdigit, "0123456789")
TEST_CTYPE(isxdigit, "0123456789ABCDEFabcdef")
TEST_CTYPE(isspace, " \t\f\n\r\v")
TEST_CTYPE(ispunct, "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~")
TEST_CTYPE(isprint, "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!\"#$%&'()*+,-./"
                    ":;<=>?@[\\]^_`{|}~ ")
TEST_CTYPE(isgraph, "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!\"#$%&'()*+,-./"
                    ":;<=>?@[\\]^_`{|}~")
TEST_CTYPE(isblank, " \t")


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

int main(void) {
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
