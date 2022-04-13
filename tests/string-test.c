#undef NDEBUG
#include <assert.h>
#include <string.h>

static void test_strcmp(void) {
	const char *string = "Hello World!";
	assert(strcmp(string, "Hello!") < 0);
	assert(strcmp(string, "Hello") > 0);
	assert(strcmp(string, "Hello there") < 0);
	assert(strcmp("Hello, everybody!" + 12, "Hello, somebody!" + 11) == 0);
}

static void test_strcpy(void) {
	char buffer[256];
	strcpy(buffer, "Hello, there!");
	assert(strcmp(buffer, "Hello, there!") == 0);
	assert(strcmp(buffer, "Hello there!") != 0);
}

int main() {
	test_strcmp();
	test_strcpy();
	return 0;
}
