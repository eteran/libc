#undef NDEBUG
#include <assert.h>
#include <strings.h>
#include <string.h>

static void test_bcmp(void) {
    const char a1[] = {'a','b','c'};
    const char a2[] = {'a','b','d'};

	assert(bcmp(a1, a2, 3) != 0);
	assert(bcmp(a2, a1, 3) != 0);
	assert(bcmp(a1, a1, 3) == 0);
	assert(bcmp(a2, a2, 3) == 0);
}

static void test_bcopy(void) {
	const char source[] = "once upon a midnight dreary...";
	char dest[4];
	bcopy(source, dest, sizeof(dest));
	assert(bcmp(dest, "once", sizeof(dest)) == 0);
}

static void test_bzero(void) {
	size_t i;
	char buffer[] = "once upon a midnight dreary...";
	bzero(buffer, sizeof(buffer));
	for(i = 0; i < sizeof(buffer); ++i) {
		assert(buffer[i] == 0);
	}
}

static void test_strcasecmp(void) {
  const char *str1 = "STRING";
  const char *str2 = "string";
  assert(strcasecmp(str1, str2) == 0);
  assert(strcasecmp(&str1[1], str2) > 0);
  assert(strcasecmp(str1, &str2[1]) < 0);

}

static void test_index(void) {
	const char str[] = "Try not. Do, or do not. There is no try.";
	char target = 'T';
	const char *result = str;

	result = index(result, target);
	assert(strcmp(result, "Try not. Do, or do not. There is no try.") == 0);
	++result;

	result = index(result, target);
	assert(strcmp(result, "There is no try.") == 0);
	++result;

	result = index(result, target);
	assert(result == NULL);

	result = index(str, '\0');
	assert(result == &str[sizeof(str) - 1]);
}



#if 0
#include "c/ffs.h"
#include "c/rindex.h"
#include "c/strncasecmp.h"
#endif

int main(void) {
	test_bcmp();
	test_bcopy();
	test_bzero();
	test_strcasecmp();
	test_index();
	return 0;
}
