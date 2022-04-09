
#define _ELIBC_SOURCE
#include <ctype.h>
#include <stdint.h>

/* TODO(eteran): locale awareness of any kind ? */

#define CTYPE_SPACE  0x0001
#define CTYPE_PRINT  0x0002
#define CTYPE_CNTRL  0x0004
#define CTYPE_UPPER  0x0008
#define CTYPE_LOWER  0x0010
#define CTYPE_ALPHA  0x0020
#define CTYPE_DIGIT  0x0040
#define CTYPE_PUNCT  0x0080
#define CTYPE_XDIGIT 0x0100
#define CTYPE_BLANK  0x0200
#define CTYPE_ALNUM  (CTYPE_ALPHA | CTYPE_DIGIT)
#define CTYPE_GRAPH  (CTYPE_ALNUM | CTYPE_PUNCT)

/* a simple table, valid for "C" local only */
/* clang-format off */
static const uint16_t __elibc_ctype_tab[] = {
	0x0004, 0x0004, 0x0004, 0x0004, 0x0004, 0x0004, 0x0004, 0x0004,
	0x0004, 0x0205, 0x0005, 0x0005, 0x0005, 0x0005, 0x0004, 0x0004,
	0x0004, 0x0004, 0x0004, 0x0004, 0x0004, 0x0004, 0x0004, 0x0004,
	0x0004, 0x0004, 0x0004, 0x0004, 0x0004, 0x0004, 0x0004, 0x0004,
	0x0203, 0x0082, 0x0082, 0x0082, 0x0082, 0x0082, 0x0082, 0x0082,
	0x0082, 0x0082, 0x0082, 0x0082, 0x0082, 0x0082, 0x0082, 0x0082,
	0x0142, 0x0142, 0x0142, 0x0142, 0x0142, 0x0142, 0x0142, 0x0142,
	0x0142, 0x0142, 0x0082, 0x0082, 0x0082, 0x0082, 0x0082, 0x0082,
	0x0082, 0x012a, 0x012a, 0x012a, 0x012a, 0x012a, 0x012a, 0x002a,
	0x002a, 0x002a, 0x002a, 0x002a, 0x002a, 0x002a, 0x002a, 0x002a,
	0x002a, 0x002a, 0x002a, 0x002a, 0x002a, 0x002a, 0x002a, 0x002a,
	0x002a, 0x002a, 0x002a, 0x0082, 0x0082, 0x0082, 0x0082, 0x0082,
	0x0082, 0x0132, 0x0132, 0x0132, 0x0132, 0x0132, 0x0132, 0x0032,
	0x0032, 0x0032, 0x0032, 0x0032, 0x0032, 0x0032, 0x0032, 0x0032,
	0x0032, 0x0032, 0x0032, 0x0032, 0x0032, 0x0032, 0x0032, 0x0032,
	0x0032, 0x0032, 0x0032, 0x0082, 0x0082, 0x0082, 0x0082, 0x0004,
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
/* clang-format on */

#define IS_CTYPE(name, type)                                                                       \
	int name(int c) {                                                                              \
		if ((unsigned int)c < 0x100) {                                                             \
			return (__elibc_ctype_tab[c] & (type)) != 0;                                           \
		}                                                                                          \
		return 0;                                                                                  \
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
	if (isupper(c)) {
		/* NOTE(eteran): ASCII specific */
		c |= 0x20;
	}
	return c;
}

/*------------------------------------------------------------------------------
// Name: toupper
//----------------------------------------------------------------------------*/
int toupper(int c) {
	if (islower(c)) {
		/* NOTE(eteran): ASCII specific */
		c &= ~0x20;
	}
	return c;
}

#undef IS_CTYPE
