
#define __ELIBC_SOURCE
#include <stdio.h>
#include <wchar.h>
#include <assert.h>

/*------------------------------------------------------------------------------
// Name: __elibc_fwide
//----------------------------------------------------------------------------*/
int __elibc_fwide(FILE *stream, int mode) {

	assert(stream);
	
	/* When mode is nonzero, we first attempt to set the orientation */
	if(mode != 0) {
		if(_FDATA(stream)->orientation == 0) {
			if(mode > 0) {
				_FDATA(stream)->orientation = 3;
			} else if(mode < 0) {
				_FDATA(stream)->orientation = 2;
			}
		}
	}
	
	switch(_FDATA(stream)->orientation) {
	case 0: /* unset */
		return 0;
	case 1: /* invalid */
		assert(0);
	case 2: /* char */
		/* It returns a negative value if stream is byte oriented. */
		return -1;
	case 3: /* wchar */
		/* It returns a positive value if stream is wide-character oriented */
		return 1;
	}
}

/*------------------------------------------------------------------------------
// Name: fwide
//----------------------------------------------------------------------------*/
int fwide(FILE *stream, int mode) {
	int r;
	__elibc_lock_stream(stream);
	r = __elibc_fwide(stream, mode);
	__elibc_unlock_stream(stream);
	return r;
}
