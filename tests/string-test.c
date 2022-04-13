#undef NDEBUG
#include <assert.h>
#include <string.h>

static void test_strcmp(void) {
	const char *string = "Hello World!";
	assert(strcmp(string, "Hello!") < 0);
	assert(strcmp(string, "Hello") > 0);
	assert(strcmp(string, "Hello there") < 0);
	assert(strcmp(&"Hello, everybody!"[12], &"Hello, somebody!"[11]) == 0);
}

static void test_strcpy(void) {
	char buffer[256];
	strcpy(buffer, "Hello, there!");
	assert(strcmp(buffer, "Hello, there!") == 0);
	assert(strcmp(buffer, "Hello there!") != 0);
}

static void test_strchr(void) {
	const char str[] = "Try not. Do, or do not. There is no try.";
	char target = 'T';
	const char *result = str;

	result = strchr(result, target);
	assert(strcmp(result, "Try not. Do, or do not. There is no try.") == 0);
	++result;

	result = strchr(result, target);
	assert(strcmp(result, "There is no try.") == 0);
	++result;

	result = strchr(result, target);
	assert(result == NULL);

	result = strchr(str, '\0');
	assert(result == &str[sizeof(str) - 1]);
}

static void test_memchr(void) {
	char str[] = "ABCDEFG";
	char *ps = memchr(str, 'D', sizeof(str) - 1);
	assert(*ps == 'D');
}

static void test_strlen(void) {
	assert(strlen("Hello, World!") == 13);
	assert(strlen("Hello") == 5);
	assert(strlen("H") == 1);
	assert(strlen("") == 0);
}

static void test_strrchr(void) {
	char filename[] = "foo/bar/foobar.txt";
	char *last_slash = strrchr(filename, '/');
	char *base_name = last_slash ? last_slash + 1 : filename;
	assert(strcmp(base_name, "foobar.txt") == 0);
}

static void test_strpbrk(void) {
	const char *str = "hello world, friend of mine!";
	const char sep[] = " ,!";

	unsigned int cnt = 0;
	do {
		str = strpbrk(str, sep);
		if (str)
			str += strspn(str, sep);
		++cnt;
	} while (str && *str);

	assert(cnt == 5);
}

static void test_strstr(void) {
	const char str[] = "one two three";
	assert((strstr(str, "") - str) == 0);
	assert((strstr(str, "two") - str) == 4);
	assert((strstr(str, "n") - str) == 1);
	assert(strstr(str, "nine") == NULL);
}

static void test_strspn(void) {
	const char string[] = "abcde312$#@";
	const char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
	const size_t spnsz = strspn(string, alphabet);
	assert(spnsz == 5);
}

static void test_memcmp(void) {
	const char a1[] = {'a', 'b', 'c'};
	const char a2[] = {'a', 'b', 'd'};

	assert(memcmp(a1, a2, 3) < 0);
	assert(memcmp(a2, a1, 3) > 0);
	assert(memcmp(a1, a1, 3) == 0);
}

static void test_memcpy(void) {
	const char source[] = "once upon a midnight dreary...";
	char dest[4];
	memcpy(dest, source, sizeof(dest));
	assert(memcmp(dest, "once", sizeof(dest)) == 0);
}

int main(void) {
	test_strcmp();
	test_strcpy();
	test_strchr();
	test_memchr();
	test_strlen();
	test_strrchr();
	test_strpbrk();
	test_strstr();
	test_strspn();
	test_memcmp();
	test_memcpy();
	return 0;
}
