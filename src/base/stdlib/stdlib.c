
#define _ELIBC_SOURCE
#include <stdlib.h>

/**
 * @brief Get the maximum number of bytes in a multibyte character
 *
 * @return size_t the maximum number of bytes in a multibyte character
 */
size_t __ctype_get_mb_cur_max(void) {
	/* TODO(eteran): make this depend on the current locale */
	/* UTF-8 only supports up to at most 4-bytes */
	return 4;
}
