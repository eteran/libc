#undef NDEBUG
#define _ELIBC_SOURCE
#include <assert.h>
#include <wchar.h>
#include <wctype.h>

#define TEST_CTYPE(name, charset)               \
	static void test_##name(void) {             \
		wint_t ch;                              \
		for (ch = 1; ch < 256; ++ch) {          \
			if (wcschr(charset, (wchar_t)ch)) { \
				assert(name(ch));               \
			} else {                            \
				assert(!name(ch));              \
			}                                   \
		}                                       \
		assert(!name(L'\0'));                   \
	}

TEST_CTYPE(iswalnum, L"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789")
TEST_CTYPE(iswalpha, L"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz")
TEST_CTYPE(iswlower, L"abcdefghijklmnopqrstuvwxyz")
TEST_CTYPE(iswupper, L"ABCDEFGHIJKLMNOPQRSTUVWXYZ")
TEST_CTYPE(iswdigit, L"0123456789")
TEST_CTYPE(iswxdigit, L"0123456789ABCDEFabcdef")
TEST_CTYPE(iswspace, L" \t\f\n\r\v")
TEST_CTYPE(iswpunct, L"!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~")
TEST_CTYPE(iswprint,
		   L"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!\"#$%&'()*+,-./"
		   L":;<=>?@[\\]^_`{|}~ ")
TEST_CTYPE(iswgraph,
		   L"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!\"#$%&'()*+,-./"
		   L":;<=>?@[\\]^_`{|}~")
TEST_CTYPE(iswblank, L" \t")

static void test_iswcntrl(void) {
	wint_t ch;
	for (ch = 0; ch < 256; ++ch) {
		if (ch < 0x20 || ch == 0x7f) {
			assert(iswcntrl(ch));
		} else {
			assert(!iswcntrl(ch));
		}
	}
}

static void test_towlower(void) {
	wint_t ch;
	for (ch = 0; ch < 256; ++ch) {
		if (iswupper(ch)) {
			assert(iswlower(towlower(ch)));
		}
	}
}

static void test_towupper(void) {
	wint_t ch;
	for (ch = 0; ch < 256; ++ch) {
		if (iswlower(ch)) {
			assert(iswupper(towupper(ch)));
		}
	}
}

void test_wctype(void) {
	assert(wctype("alnum") != 0);
	assert(wctype("alpha") != 0);
	assert(wctype("blank") != 0);
	assert(wctype("cntrl") != 0);
	assert(wctype("digit") != 0);
	assert(wctype("graph") != 0);
	assert(wctype("lower") != 0);
	assert(wctype("print") != 0);
	assert(wctype("space") != 0);
	assert(wctype("upper") != 0);
	assert(wctype("xdigit") != 0);
	assert(wctype("test") == 0);
}

int main(void) {
	test_iswalnum();
	test_iswalpha();
	test_iswlower();
	test_iswupper();
	test_iswdigit();
	test_iswxdigit();
	test_iswspace();
	test_iswblank();
	test_iswcntrl();
	test_towlower();
	test_towupper();
	test_iswpunct();
	test_iswprint();
	test_iswgraph();
	return 0;
}
