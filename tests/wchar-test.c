#undef NDEBUG
#define _ELIBC_SOURCE
#include <assert.h>
#include <locale.h>
#include <wchar.h>

static void test_mbrtowc(void) {

	mbstate_t state = {0, 0, 0};

	/*    u8"z\u00df\u6c34\U0001F34C" */
	/* or u8"zß水🍌" */
	const char input[] = "\x7a\xc3\x9f\xe6\xb0\xb4\xf0\x9f\x8d\x8c";
	wchar_t output[sizeof(input)] = L"";
	const size_t in_sz = sizeof(input);
	const char *first = input;
	const char *last = input + in_sz;
	wchar_t *out_ptr = output;
	int rc;

	while ((rc = mbrtowc(out_ptr, first, last - first, &state)) > 0) {
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

int main(void) {

	/* TODO support close enough locales, such as "en_US.utf8" */
	setlocale(LC_ALL, "en_US.UTF-8");

	test_mbrtowc();

	return 0;
}
