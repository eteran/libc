#undef NDEBUG
#include <assert.h>
#include <strings.h>

static void test_bcmp(void) {
    const char a1[] = {'a','b','c'};
    const char a2[] = {'a','b','d'};

	assert(bcmp(a1, a2, 3) != 0);
	assert(bcmp(a2, a1, 3) != 0);
	assert(bcmp(a1, a1, 3) == 0);
	assert(bcmp(a2, a2, 3) == 0);
}



#if 0
#include "c/bcopy.h"
#include "c/bzero.h"
#include "c/ffs.h"
#include "c/index.h"
#include "c/rindex.h"
#include "c/strcasecmp.h"
#include "c/strncasecmp.h"
#endif

int main(void) {
	test_bcmp();
	return 0;
}
