
#define _ELIBC_SOURCE
#include <limits.h>
#include <strings.h>

/*
0000 - 0
0001 - 1
0010 - 2
0011 - 1
0100 - 3
0101 - 1
0110 - 2
0111 - 1
1000 - 4
1001 - 1
1010 - 2
1011 - 1
1100 - 3
1101 - 1
1110 - 2
1111 - 1
*/

/**
 * @brief Find the first bit set in an integer
 *
 * @param i the integer to search in
 * @return int the index of the first bit set, or 0 if no bits are set
 * @note This function is not a standard C function. It is included for compatibility with other systems.
 */
int ffs(int i) {
	int ret = 0;
	int j   = 0;

	static const int _ffs_tab[] = {0, 1, 2, 1, 3, 1, 2, 1, 4, 1, 2, 1, 3, 1, 2, 1};

	while ((i != 0) && (ret == 0)) {
		ret = _ffs_tab[i & 0x0f];

		if (ret > 0) {
			break;
		}

		i >>= 4;
		j += 4;

		/* technically the sign bit could stay, so we mask it out to be sure */
		i &= INT_MAX;
	}

	if (ret != 0) {
		ret += j;
	}

	return ret;
}
