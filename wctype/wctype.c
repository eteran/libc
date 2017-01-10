
/* So this basically assumes that wchar_t represents the UTF-32/16 code point
 * and that we only care about the results of characters which are in the ASCII
 * range...
 * I'm not sure that's correct.
 */

#define __ELIBC_SOURCE
#include <ctype.h>
#include <wchar.h>
#include <wctype.h>
#include <string.h>

/* TODO: locale awareness of any kind ? */

#define WCTYPE_ALNUM  0x0001
#define WCTYPE_ALPHA  0x0002
#define WCTYPE_CNTRL  0x0004
#define WCTYPE_DIGIT  0x0008
#define WCTYPE_GRAPH  0x0010
#define WCTYPE_LOWER  0x0020
#define WCTYPE_PRINT  0x0040
#define WCTYPE_PUNCT  0x0080
#define WCTYPE_SPACE  0x0100
#define WCTYPE_UPPER  0x0200
#define WCTYPE_XDIGIT 0x0400
#define WCTYPE_BLANK  0x0800

#define WCTRANS_UPPER 0xffff
#define WCTRANS_LOWER 0xfffe

#define __ISWCTYPE(class)          \
int isw ## class(wint_t wc) {      \
	return is ## class(wctob(wc)); \
}

/*------------------------------------------------------------------------------
// Name: iswalnum
//----------------------------------------------------------------------------*/
__ISWCTYPE(alnum)

/*------------------------------------------------------------------------------
// Name: iswalpha
//----------------------------------------------------------------------------*/
__ISWCTYPE(alpha)

/*------------------------------------------------------------------------------
// Name: iswcntrl
//----------------------------------------------------------------------------*/
__ISWCTYPE(cntrl)

/*------------------------------------------------------------------------------
// Name: iswdigit
//----------------------------------------------------------------------------*/
__ISWCTYPE(digit)

/*------------------------------------------------------------------------------
// Name: iswgraph
//----------------------------------------------------------------------------*/
__ISWCTYPE(graph)

/*------------------------------------------------------------------------------
// Name: iswlower
//----------------------------------------------------------------------------*/
__ISWCTYPE(lower)

/*------------------------------------------------------------------------------
// Name: iswprint
//----------------------------------------------------------------------------*/
__ISWCTYPE(print)

/*------------------------------------------------------------------------------
// Name: iswpunct
//----------------------------------------------------------------------------*/
__ISWCTYPE(punct)

/*------------------------------------------------------------------------------
// Name: iswspace
//----------------------------------------------------------------------------*/
__ISWCTYPE(space)

/*------------------------------------------------------------------------------
// Name: iswupper
//----------------------------------------------------------------------------*/
__ISWCTYPE(upper)

/*------------------------------------------------------------------------------
// Name: iswxdigit
//----------------------------------------------------------------------------*/
__ISWCTYPE(xdigit)

/*------------------------------------------------------------------------------
// Name: iswblank
//----------------------------------------------------------------------------*/
__ISWCTYPE(blank)

/*------------------------------------------------------------------------------
// Name: tolower
//----------------------------------------------------------------------------*/
wint_t towlower(wint_t c) {
	if(iswupper(c)) {
		/* NOTE: ASCII specific */
		c |= 0x20;
	}
	return c;
}

/*------------------------------------------------------------------------------
// Name: toupper
//----------------------------------------------------------------------------*/
wint_t towupper(wint_t c) {
	if(iswlower(c)) {
		/* NOTE: ASCII specific */
		c &= ~0x20;
	}
	return c;
}

/*------------------------------------------------------------------------------
// Name: wctrans
//----------------------------------------------------------------------------*/
wctrans_t wctrans(const char *str) {

	/* this would obviously be faster as a trie, but do we care? */

	if(strcmp(str, "toupper") == 0) {
		return WCTRANS_UPPER;
	} else if(strcmp(str, "tolower") == 0) {
		return WCTRANS_LOWER;
	}

	return 0;
}

/*------------------------------------------------------------------------------
// Name: wctype
//----------------------------------------------------------------------------*/
wctype_t wctype(const char *str) {

	/* this would obviously be faster as a trie, but do we care? */

	if(strcmp(str, "alnum") == 0) {
		return WCTYPE_ALNUM;
	} else if(strcmp(str, "alpha") == 0) {
		return WCTYPE_ALPHA;
	} else if(strcmp(str, "blank") == 0) {
		return WCTYPE_BLANK;
	} else if(strcmp(str, "cntrl") == 0) {
		return WCTYPE_CNTRL;
	} else if(strcmp(str, "digit") == 0) {
		return WCTYPE_DIGIT;
	} else if(strcmp(str, "graph") == 0) {
		return WCTYPE_GRAPH;
	} else if(strcmp(str, "lower") == 0) {
		return WCTYPE_LOWER;
	} else if(strcmp(str, "print") == 0) {
		return WCTYPE_PRINT;
	} else if(strcmp(str, "space") == 0) {
		return WCTYPE_SPACE;
	} else if(strcmp(str, "upper") == 0) {
		return WCTYPE_UPPER;
	} else if(strcmp(str, "xdigit") == 0) {
		return WCTYPE_XDIGIT;
	}

	return 0;
}

/*------------------------------------------------------------------------------
// Name: iswctype
//----------------------------------------------------------------------------*/
int iswctype(wint_t wc, wctype_t desc) {
	switch(desc) {
	case WCTYPE_ALNUM:  return iswalnum(wc);
	case WCTYPE_ALPHA:  return iswalpha(wc);
	case WCTYPE_CNTRL:  return iswcntrl(wc);
	case WCTYPE_DIGIT:  return iswdigit(wc);
	case WCTYPE_GRAPH:  return iswgraph(wc);
	case WCTYPE_LOWER:  return iswlower(wc);
	case WCTYPE_PRINT:  return iswprint(wc);
	case WCTYPE_PUNCT:  return iswpunct(wc);
	case WCTYPE_SPACE:  return iswspace(wc);
	case WCTYPE_UPPER:  return iswupper(wc);
	case WCTYPE_XDIGIT: return iswxdigit(wc);
	case WCTYPE_BLANK:  return iswblank(wc);
	default:
		return 0;
	}
}

/*------------------------------------------------------------------------------
// Name: towctrans
//----------------------------------------------------------------------------*/
wint_t towctrans(wint_t wc, wctrans_t desc) {
	switch(desc) {
	case WCTRANS_UPPER:  return towupper(wc);
	case WCTRANS_LOWER:  return towlower(wc);
	default:
		return 0;
	}
}
