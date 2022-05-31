#undef NDEBUG
#define _ELIBC_SOURCE
#include <assert.h>
#include <locale.h>

int main(void) {
	setlocale(LC_ALL, "en_US.UTF-8");
	return 0;
}
