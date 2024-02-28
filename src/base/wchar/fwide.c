
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
		if (_FDATA(stream)->orientation_set == 0) {
			if (mode > 0) {
				_FDATA(stream)->orientation_set  = 1;
				_FDATA(stream)->orientation_wide = _ELIBC_FILE_WIDE;
			} else if (mode < 0) {
				_FDATA(stream)->orientation_set  = 1;
				_FDATA(stream)->orientation_wide = _ELIBC_FILE_NARROW;
			}
		}
	}

	if (!_FDATA(stream)->orientation_set) {
		return 0;
	}

	if (_FDATA(stream)->orientation_wide) {
		/* It returns a positive value if stream is wide-character oriented */
		return 1;
	} else {
		/* It returns a negative value if stream is byte oriented. */
		return -1;
	}
}

/*------------------------------------------------------------------------------
// Name: fwide
//----------------------------------------------------------------------------*/
int fwide(FILE *stream, int mode) {
	int r;
	__ELIBC_WITH_LOCK(__elibc_fwide(stream, mode), &r);
	return r;
}
