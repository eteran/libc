
#define _ELIBC_SOURCE
#include <assert.h>
#include <limits.h>
#include <stdio.h>

/**
 * @brief Set the position indicator of a stream
 *
 * @param stream the stream to set the position of
 * @param pos a pointer to a fpos_t structure containing the new position
 * @return int 0 on success, or a negative value on error
 */
int fsetpos(FILE *stream, const fpos_t *pos) {

	assert(stream);
	assert(pos);

	/* TODO(eteran): catch any errors */
	fseek(stream, pos->offset, SEEK_SET);
	return 0;
}
