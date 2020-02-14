#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
	int arg1 = *(const int *)(a);
	int arg2 = *(const int *)(b);

	if (arg1 < arg2) return -1;
	if (arg1 > arg2) return 1;
	return 0;
}

int main(void) {

	size_t i;
	int a[] = {-2, 99, 0, -743, 2, INT_MIN, 4};

	const size_t size = sizeof(a) / sizeof(*a);

	qsort(a, size, sizeof(*a), compare);

	for (i = 0; i < size; ++i) {
		printf("%d ", a[i]);
	}

	printf("\n");

	return 0;
}
