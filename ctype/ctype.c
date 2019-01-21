
#define __ELIBC_SOURCE
#include <ctype.h>

/* TODO: locale awareness of any kind ? */

#define CTYPE_ALNUM  0x0001
#define CTYPE_ALPHA  0x0002
#define CTYPE_CNTRL  0x0004
#define CTYPE_DIGIT  0x0008
#define CTYPE_GRAPH  0x0010
#define CTYPE_LOWER  0x0020
#define CTYPE_PRINT  0x0040
#define CTYPE_PUNCT  0x0080
#define CTYPE_SPACE  0x0100
#define CTYPE_UPPER  0x0200
#define CTYPE_XDIGIT 0x0400
#define CTYPE_BLANK  0x0800

/* a simple table, valid for "C" local only */
static const unsigned short __elibc_ctype_tab[] = {
	0x0004, 0x0004, 0x0004, 0x0004, 0x0004, 0x0004, 0x0004, 0x0004,
	0x0004, 0x0904, 0x0104, 0x0104, 0x0104, 0x0104, 0x0004, 0x0004,
	0x0004, 0x0004, 0x0004, 0x0004, 0x0004, 0x0004, 0x0004, 0x0004,
	0x0004, 0x0004, 0x0004, 0x0004, 0x0004, 0x0004, 0x0004, 0x0004,
	0x0940, 0x00d0, 0x00d0, 0x00d0, 0x00d0, 0x00d0, 0x00d0, 0x00d0,
	0x00d0, 0x00d0, 0x00d0, 0x00d0, 0x00d0, 0x00d0, 0x00d0, 0x00d0,
	0x0459, 0x0459, 0x0459, 0x0459, 0x0459, 0x0459, 0x0459, 0x0459,
	0x0459, 0x0459, 0x00d0, 0x00d0, 0x00d0, 0x00d0, 0x00d0, 0x00d0,
	0x00d0, 0x0653, 0x0653, 0x0653, 0x0653, 0x0653, 0x0653, 0x0253,
	0x0253, 0x0253, 0x0253, 0x0253, 0x0253, 0x0253, 0x0253, 0x0253,
	0x0253, 0x0253, 0x0253, 0x0253, 0x0253, 0x0253, 0x0253, 0x0253,
	0x0253, 0x0253, 0x0253, 0x00d0, 0x00d0, 0x00d0, 0x00d0, 0x00d0,
	0x00d0, 0x0473, 0x0473, 0x0473, 0x0473, 0x0473, 0x0473, 0x0073,
	0x0073, 0x0073, 0x0073, 0x0073, 0x0073, 0x0073, 0x0073, 0x0073,
	0x0073, 0x0073, 0x0073, 0x0073, 0x0073, 0x0073, 0x0073, 0x0073,
	0x0073, 0x0073, 0x0073, 0x00d0, 0x00d0, 0x00d0, 0x00d0, 0x0004,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
};

#define IS_CTYPE(name, type)                         \
int name(int c) {                                    \
	if((unsigned int)c < 0x100) {                    \
		return (__elibc_ctype_tab[c] & (type)) != 0; \
	}                                                \
	return 0;                                        \
}

/*------------------------------------------------------------------------------
// Name: isalnum
//----------------------------------------------------------------------------*/
IS_CTYPE(isalnum, CTYPE_ALNUM)

/*------------------------------------------------------------------------------
// Name: isalpha
//----------------------------------------------------------------------------*/
IS_CTYPE(isalpha, CTYPE_ALPHA)

/*------------------------------------------------------------------------------
// Name: iscntrl
//----------------------------------------------------------------------------*/
IS_CTYPE(iscntrl, CTYPE_CNTRL)

/*------------------------------------------------------------------------------
// Name: isdigit
//----------------------------------------------------------------------------*/
IS_CTYPE(isdigit, CTYPE_DIGIT)

/*------------------------------------------------------------------------------
// Name: isgraph
//----------------------------------------------------------------------------*/
IS_CTYPE(isgraph, CTYPE_GRAPH)

/*------------------------------------------------------------------------------
// Name: islower
//----------------------------------------------------------------------------*/
IS_CTYPE(islower, CTYPE_LOWER)

/*------------------------------------------------------------------------------
// Name: isprint
//----------------------------------------------------------------------------*/
IS_CTYPE(isprint, CTYPE_PRINT)

/*------------------------------------------------------------------------------
// Name: ispunct
//----------------------------------------------------------------------------*/
IS_CTYPE(ispunct, CTYPE_PUNCT)

/*------------------------------------------------------------------------------
// Name: isspace
//----------------------------------------------------------------------------*/
IS_CTYPE(isspace, CTYPE_SPACE)

/*------------------------------------------------------------------------------
// Name: isupper
//----------------------------------------------------------------------------*/
IS_CTYPE(isupper, CTYPE_UPPER)

/*------------------------------------------------------------------------------
// Name: isxdigit
//----------------------------------------------------------------------------*/
IS_CTYPE(isxdigit, CTYPE_XDIGIT)

/*------------------------------------------------------------------------------
// Name: isblank
//----------------------------------------------------------------------------*/
IS_CTYPE(isblank, CTYPE_BLANK)

/*------------------------------------------------------------------------------
// Name: tolower
//----------------------------------------------------------------------------*/
int tolower(int c) {
	if(isupper(c)) {
		/* NOTE: ASCII specific */
		c |= 0x20;
	}
	return c;
}

/*------------------------------------------------------------------------------
// Name: toupper
//----------------------------------------------------------------------------*/
int toupper(int c) {
	if(islower(c)) {
		/* NOTE: ASCII specific */
		c &= ~0x20;
	}
	return c;
}

#undef IS_CTYPE
