
#define _ELIBC_SOURCE
#include <assert.h>
#include <stdio.h>
#include <wchar.h>

/*------------------------------------------------------------------------------
// Name: __elibc_fwide
//----------------------------------------------------------------------------*/
int __elibc_fwide(FILE *stream, int mode) {

	assert(stream);

	/* When mode is nonzero, we first attempt to set the orientation */
	if (mode != 0) {
		if (_FDATA(stream)->orientation == _ELIBC_FILE_ORIENTATION_NONE) {
			if (mode > 0) {
				_FDATA(stream)->orientation = _ELIBC_FILE_ORIENTATION_WIDE;
			} else if (mode < 0) {
				_FDATA(stream)->orientation = _ELIBC_FILE_ORIENTATION_NARROW;
			}
		}
	}

	switch (_FDATA(stream)->orientation) {
	case _ELIBC_FILE_ORIENTATION_NONE:
		return 0;
	case _ELIBC_FILE_ORIENTATION_NARROW:
		/* It returns a negative value if stream is byte oriented. */
		return -1;
	case _ELIBC_FILE_ORIENTATION_WIDE:
		/* It returns a positive value if stream is wide-character oriented */
		return 1;
	case _ELIBC_FILE_ORIENTATION_INVALID:
	default:
		/* invalid */
		assert(0);
		return 0;
	}
}

/*------------------------------------------------------------------------------
// Name: fwide
//----------------------------------------------------------------------------*/
int fwide(FILE *stream, int mode) {
	int r;
	__ELIBC_WITH_LOCK(__elibc_fwide(stream, mode));
	return r;
}
