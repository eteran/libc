#undef NDEBUG
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

static void test_snprintf(void) {
	char buffer[256];
    const char* s = "Hello";

    sprintf(buffer, "\t.%10s.\n\t.%-10s.\n\t.%*s.\n", s, s, 10, s);
	printf("%s", buffer);
	assert(strcmp(buffer,
		"\t.     Hello.\n"
        "\t.Hello     .\n"
        "\t.     Hello.\n") == 0);


    sprintf(buffer, "\t%.4s\n\t%.*s\n", s, 3, s);
	printf("%s", buffer);
	assert(strcmp(buffer,
		"\tHell\n"
        "\tHel\n") == 0);

    sprintf(buffer, "Characters:\t%c %%\n", 65);
	printf("%s", buffer);
	assert(strcmp(buffer, "Characters:\tA %\n") == 0);

    sprintf(buffer, "Decimal:\t%i %d %.6i %i %.0i %+i %i\n", 1, 2, 3, 0, 0, 4, -4);
	printf("%s", buffer);
	assert(strcmp(buffer, "Decimal:\t1 2 000003 0  +4 -4\n") == 0);

    sprintf(buffer, "Hexadecimal:\t%x %x %X %#x\n", 5, 10, 10, 6);
	printf("%s", buffer);
	assert(strcmp(buffer, "Hexadecimal:\t5 a A 0x6\n") == 0);

    sprintf(buffer, "Octal:\t\t%o %#o %#o\n", 10, 10, 4);
	printf("%s", buffer);
	assert(strcmp(buffer, "Octal:\t\t12 012 04\n") == 0);

    sprintf(buffer, "Rounding:\t%f %.0f %.32f\n", 1.5, 1.5, 1.3);
	/* NOTE(eteran): not asserted since we are slightly different from examples */
	printf("%s", buffer);

    sprintf(buffer, "Padding:\t%05.2f %.2f %5.2f\n", 1.5, 1.5, 1.5);
	printf("%s", buffer);
	assert(strcmp(buffer, "Padding:\t01.50 1.50  1.50\n") == 0);

    sprintf(buffer, "Scientific:\t%E %e\n", 1.5, 1.5);
	printf("%s", buffer);
	assert(strcmp(buffer, "Scientific:\t1.500000E+00 1.500000e+00\n") == 0);

#ifdef _HAS_C99
    sprintf(buffer, "Hexadecimal:\t%a %A\n", 1.5, 1.5);
	/* NOTE(eteran): not asserted since we don't implment hex floats yet */
	printf("%s", buffer);
#endif

    sprintf(buffer, "%+15.3f\n", 1234.5678);
	printf("%s", buffer);
	assert(strcmp(buffer, "      +1234.568\n") == 0);

    sprintf(buffer, "%+15.3f\n", -1234.5678);
	printf("%s", buffer);
	assert(strcmp(buffer, "      -1234.568\n") == 0);

	sprintf(buffer, "Scientific:\t%.8e\n", 54321.6789);
	printf("%s", buffer);
	assert(strcmp(buffer, "Scientific:\t5.43216789e+04\n") == 0);

    sprintf(buffer, "%d\n", INT_MIN);
	printf("%s", buffer);
	assert(strcmp(buffer, "-2147483648\n") == 0);

    sprintf(buffer, "%d\n", INT_MAX);
	printf("%s", buffer);
	assert(strcmp(buffer, "2147483647\n") == 0);

	sprintf(buffer, "%.5d\n", -3);  /* use of precision filed */
	printf("%s", buffer);
	assert(strcmp(buffer, "-00003\n") == 0);

	sprintf(buffer, "%05d\n", -3);  /* use of 0 flag to prepend with 0 */
	printf("%s", buffer);
	assert(strcmp(buffer, "-0003\n") == 0);
}

int main(void) {
	test_snprintf();
	return 0;
}
