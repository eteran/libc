
#define _ELIBC_SOURCE
#include <assert.h>
#include <stdio.h>

/**
 * @brief Get the current position in a stream
 *
 * @param stream the stream to get the position of
 * @param pos a pointer to a fpos_t structure to store the position in
 * @return int 0 on success, or a negative value on error
 */
int fgetpos(FILE *stream, fpos_t *pos) {

	long ret;

	assert(stream);
	assert(pos);

	ret = ftell(stream);

	if (ret != -1) {
		pos->offset = ret;
		ret         = 0;
	}

	return (int)ret;
}
