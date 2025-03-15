/* 100% coverage, but locale sensitive functions not testing locale support */
#undef NDEBUG
#define _ELIBC_SOURCE
#define _ELIBC_SAFE_STRING
#include "test_util.h"
#include <assert.h>
#include <errno.h>
#include <stdint.h>
#include <stdlib.h>
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
	const char str[]   = "Try not. Do, or do not. There is no try.";
	char target        = 'T';
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

static void test_strrchr(void) {
	const char str[]   = "Try not. Do, or do not. There is no try.";
	char target        = 'T';
	const char *result = str;

	result = strrchr(str, target);
	assert(strcmp(result, "There is no try.") == 0);

	result = strrchr(str, 'W');
	assert(result == NULL);

	result = strrchr(str, '\0');
	assert(result == &str[sizeof(str) - 1]);
}

static void test_memchr(void) {
	char str[] = "ABCDEFG";
	char *ps   = memchr(str, 'D', sizeof(str) - 1);
	assert(*ps == 'D');
}

static void test_strlen(void) {
	assert(strlen("Hello, World!") == 13);
	assert(strlen("Hello") == 5);
	assert(strlen("H") == 1);
	assert(strlen("") == 0);
}

static void test_strpbrk(void) {
	const char *str  = "hello world, friend of mine!";
	const char sep[] = " ,!";

	unsigned int cnt = 0;
	do {
		str = strpbrk(str, sep);
		if (str) {
			str += strspn(str, sep);
		}
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
	const char string[]   = "abcde312$#@";
	const char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
	const size_t spnsz    = strspn(string, alphabet);
	assert(spnsz == 5);
}

static void test_memcmp(void) {
	const char a1[] = {'a', 'b', 'c'};
	const char a2[] = {'a', 'b', 'd'};

	assert(memcmp(a1, a2, 3) < 0);
	assert(memcmp(a2, a1, 3) > 0);
	assert(memcmp(a1, a1, 3) == 0);
}

static void test_memcmp_simd(void) {
	const char a1[] = "abcdefghijklmopqrstuvwxyz012345";
	const char a2[] = "abcdefghijklmopqsstuvwxyz012345";

	assert(memcmp(a1, a2, 32) < 0);
	assert(memcmp(a2, a1, 32) > 0);
	assert(memcmp(a1, a1, 32) == 0);
}

static void test_memswp(void) {
	char str1[] = "1234567890";
	char str2[] = "abcdefghij";
	assert(strcmp(str1, "1234567890") == 0);
	assert(strcmp(str2, "abcdefghij") == 0);
	memswp(str1, str2, 10);
	assert(strcmp(str1, "abcdefghij") == 0);
	assert(strcmp(str2, "1234567890") == 0);

	uint32_t nums1[] = {1, 2, 3, 4, 5, 6, 7, 8};
	uint32_t nums2[] = {9, 10, 11, 12, 13, 14, 15, 16};
	memswp(nums1, nums2, sizeof(nums1));

	for (size_t i = 0; i < 8; ++i) {
		assert(nums1[i] == (9 + i));
		assert(nums2[i] == (1 + i));
	}
}

static void test_memcpy(void) {
	const char source[] = "once upon a midnight dreary...";
	char dest[4];
	memcpy(dest, source, sizeof(dest));
	assert(memcmp(dest, "once", sizeof(dest)) == 0);
}

static void test_memset(void) {
	char buffer[32];
	int i;
	for (i = 0; i < 256; ++i) {
		size_t j;
		memset(buffer, (char)i, sizeof(buffer));
		for (j = 0; j < sizeof(buffer); ++j) {
			assert(buffer[j] == (char)i);
		}
	}
}

static void test_strcat(void) {
	char buffer[256] = "";
	assert(strcmp(buffer, "") == 0);
	strcat(buffer, "Hello");
	assert(strcmp(buffer, "Hello") == 0);
	strcat(buffer, ", ");
	assert(strcmp(buffer, "Hello, ") == 0);
	strcat(buffer, "World");
	assert(strcmp(buffer, "Hello, World") == 0);
	strcat(buffer, "!");
	assert(strcmp(buffer, "Hello, World!") == 0);
}

static void test_strdup(void) {
	char *p = strdup("Hello, World");
	assert(p);
	assert(strlen(p) == 12);
	assert(strcmp(p, "Hello, World") == 0);
	free(p);
}

static void test_strndup(void) {
	char *p = strndup("Hello, World", 5);
	assert(p);
	assert(strlen(p) == 5);
	assert(strcmp(p, "Hello") == 0);
	free(p);
}

static void test_strlcat(void) {
	char buffer[10] = "";
	size_t n        = 0;
	assert(strcmp(buffer, "") == 0);
	n = strlcat(buffer, "Hello", sizeof(buffer));
	assert(strcmp(buffer, "Hello") == 0);
	assert(n == 5);
	n = strlcat(buffer, ", ", sizeof(buffer));
	assert(strcmp(buffer, "Hello, ") == 0);
	assert(n == 7);
	n = strlcat(buffer, "World", sizeof(buffer));
	assert(n == 12);
	assert(strcmp(buffer, "Hello, Wo") == 0);
	n = strlcat(buffer, "!", sizeof(buffer));
	assert(strcmp(buffer, "Hello, Wo") == 0);
	assert(n == 10);
	n = strlcat(buffer, "!", 0);
	assert(strcmp(buffer, "Hello, Wo") == 0);
	assert(n == 1);
}

static void test_strlcpy(void) {
	char buffer[10] = "";
	size_t n        = 0;
	assert(strcmp(buffer, "") == 0);
	n = strlcpy(buffer, "Hello", sizeof(buffer));
	assert(n == 5);
	assert(strcmp(buffer, "Hello") == 0);
	n = strlcpy(buffer, "World", sizeof(buffer));
	assert(n == 5);
	assert(strcmp(buffer, "World") == 0);
	n = strlcpy(buffer, "Hello, World", sizeof(buffer));
	assert(n == 12);
	assert(strcmp(buffer, "Hello, Wo") == 0);
}

static void test_memmove(void) {
	char str[] = "1234567890";
	assert(strcmp(str, "1234567890") == 0);
	memmove(str + 4, str + 3, 3);
	assert(strcmp(str, "1234456890") == 0);
}

static void test_strcoll(void) {
	/* TODO(eteran): implement/test locale aspect of this function */
	const char *string = "Hello World!";
	assert(strcoll(string, "Hello!") < 0);
	assert(strcoll(string, "Hello") > 0);
	assert(strcoll(string, "Hello there") < 0);
	assert(strcoll(&"Hello, everybody!"[12], &"Hello, somebody!"[11]) == 0);
}

static void test_strcspn(void) {
	const char *string  = "abcde312$#@";
	const char *invalid = "*$#";

	size_t valid_len = strcspn(string, invalid);
	assert(valid_len != strlen(string));
	assert(valid_len == 8);
}

static void test_strncat(void) {
	char str[50]  = "Hello ";
	char str2[50] = "World!";
	strcat(str, str2);
	strncat(str, " Goodbye World!", 3);
	assert(strcmp(str, "Hello World! Go") == 0);
}

static void test_strtok(void) {
	char *tokens[32];
	size_t count = 0;
	char input[] = "A bird came down the walk";
	char *token  = strtok(input, " ");
	while (token) {
		tokens[count++] = token;
		token           = strtok(NULL, " ");
	}

	assert(count == 6);
	assert(strcmp(tokens[0], "A") == 0);
	assert(strcmp(tokens[1], "bird") == 0);
	assert(strcmp(tokens[2], "came") == 0);
	assert(strcmp(tokens[3], "down") == 0);
	assert(strcmp(tokens[4], "the") == 0);
	assert(strcmp(tokens[5], "walk") == 0);
}

static void test_strncpy(void) {
	char src[]   = "hi";
	char dest[6] = "abcdef";
	char dest2[2];

	strncpy(dest, src, 5);
	assert(memcmp(dest, "hi\0\0\0f", 6) == 0);

	strncpy(dest2, src, 2);
	assert(memcmp(dest, "hi", 2) == 0);
}

static void test_strncmp(void) {
	const char *string = "Hello World!";
	assert(strncmp(string, "Hello!", 5) == 0);
	assert(strncmp(string, "Hello", 10) > 0);
	assert(strncmp(string, "Hello there", 10) < 0);
	assert(strncmp(("Hello, everybody!") + 12, ("Hello, somebody!") + 11, 5) == 0);
}

static void test_strerror(void) {

	typedef struct {
		int errnum;
		const char *str;
	} strerror_table_t;

	const strerror_table_t table[] = {
		/* clang-format off */
		{0, "Success"},
		{EPERM, "Operation not permitted"},
		{ERANGE, "Numerical result out of range"},
		{ENOENT, "No such file or directory"},
		{ESRCH, "No such process"},
		{EINTR, "Interrupted system call"},
		{EIO, "Input/output error"},
		{ENXIO, "No such device or address"},
		{E2BIG, "Argument list too long"},
		{ENOEXEC, "Exec format error"},
		{EBADF, "Bad file descriptor"},
		{ECHILD, "No child processes"},
		{EAGAIN, "Resource temporarily unavailable"},
		{ENOMEM, "Cannot allocate memory"},
		{EACCES, "Permission denied"},
		{EFAULT, "Bad address"},
		{ENOTBLK, "Block device required"},
		{EBUSY, "Device or resource busy"},
		{EEXIST, "File exists"},
		{EXDEV, "Invalid cross-device link"},
		{ENODEV, "No such device"},
		{ENOTDIR, "Not a directory"},
		{EISDIR, "Is a directory"},
		{EINVAL, "Invalid argument"},
		{ENFILE, "Too many open files in system"},
		{EMFILE, "Too many open files"},
		{ENOTTY, "Inappropriate ioctl for device"},
		{ETXTBSY, "Text file busy"},
		{EFBIG, "File too large"},
		{ENOSPC, "No space left on device"},
		{ESPIPE, "Illegal seek"},
		{EROFS, "Read-only file system"},
		{EMLINK, "Too many links"},
		{EPIPE, "Broken pipe"},
		{EDOM, "Numerical argument out of domain"},
		{EILSEQ, "Invalid or incomplete multibyte or wide-character"},
		{-1, NULL}
		/* clang-format on */
	};

	const strerror_table_t *ptr = table;
	while (ptr->errnum != -1) {
		char *error = strerror(ptr->errnum);
		assert(strcmp(error, ptr->str) == 0);
		++ptr;
	}
}

static void test_strxfrm(void) {
	char src[10] = "hi";
	char dest[6] = "abcdef";
	char dest2[2];
	size_t n;

	n = strxfrm(dest, src, 5);
	/* NOTE(eteran): writes at most 3 characters to the buffer */
	assert(memcmp(dest, "hi\0def", 5) == 0);
	assert(n == 2);

	n = strxfrm(dest2, src, 2);
	assert(memcmp(dest2, "h", 1) == 0);
	assert(n == 1);
}

int main(void) {

	TYPE_DEFINED(size_t);
	_Static_assert(IS_SAME_TYPE(NULL, void *), "");

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
	test_memcmp_simd();
	test_memcpy();
	test_memset();
	test_strcat();
	test_strdup();
	test_strndup();
	test_strlcat();
	test_strlcpy();
	test_memmove();
	test_strcoll();
	test_strcspn();
	test_strncat();
	test_strtok();
	test_strncpy();
	test_strncmp();
	test_strerror();
	test_strxfrm();
	test_memswp();
	return 0;
}
