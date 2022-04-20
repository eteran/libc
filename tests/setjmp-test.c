/* 100% Coverage */

#undef NDEBUG
#include <assert.h>
#include <setjmp.h>
#include <stdio.h>

static jmp_buf jump_buffer;

_Noreturn static void test_longjmp(int count) {
	/* will return count+1 out of setjmp */
	longjmp(jump_buffer, count + 1);
}

int main(void) {
	/* modified local vars in setjmp scope must be volatile */
	volatile int count = 0;

	if (setjmp(jump_buffer) != 5) {
		test_longjmp(++count);
	}

	assert(count == 4);
	return 0;
}
