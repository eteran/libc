
/* So this basically assumes that wchar_t represents the UTF-32/16 code point
 * and that we only care about the results of characters which are in the ASCII
 * range...
 * I'm not sure that's correct.
 */

#define _ELIBC_SOURCE
#include <ctype.h>
#include <string.h>
#include <wchar.h>
#include <wctype.h>

/* TODO(eteran): locale awareness of any kind ? */

#define WCTYPE_SPACE  0x0001
#define WCTYPE_PRINT  0x0002
#define WCTYPE_CNTRL  0x0004
#define WCTYPE_UPPER  0x0008
#define WCTYPE_LOWER  0x0010
#define WCTYPE_ALPHA  0x0020
#define WCTYPE_DIGIT  0x0040
#define WCTYPE_PUNCT  0x0080
#define WCTYPE_XDIGIT 0x0100
#define WCTYPE_BLANK  0x0200
#define WCTYPE_ALNUM  (WCTYPE_ALPHA | WCTYPE_DIGIT)
#define WCTYPE_GRAPH  (WCTYPE_ALNUM | WCTYPE_PUNCT)

#define WCTRANS_UPPER 0xffff
#define WCTRANS_LOWER 0xfffe

#define IS_WCTYPE(class)             \
	int isw##class(wint_t wc) {      \
		return is##class(wctob(wc)); \
	}

/**
 * @brief Checks if the given wide-character is an alphanumeric character.
 *
 * @param wc The wide-character to check.
 * @return Returns a non-zero value if the wide-character is alphanumeric, otherwise returns 0.
 */
IS_WCTYPE(alnum)

/**
 * @brief Checks if the given wide-character is an alphabetic character.
 *
 * @param wc The wide-character to check.
 * @return Returns a non-zero value if the wide-character is alphabetic, otherwise returns 0.
 */
IS_WCTYPE(alpha)

/**
 * @brief Checks if the given wide-character is a control character.
 *
 * @param wc The wide-character to check.
 * @return Returns a non-zero value if the wide-character is a control character, otherwise returns 0.
 */
IS_WCTYPE(cntrl)

/**
 * @brief Checks if the given wide-character is a digit.
 *
 * @param wc The wide-character to check.
 * @return Returns a non-zero value if the wide-character is a digit, otherwise returns 0.
 */
IS_WCTYPE(digit)

/**
 * @brief Checks if the given wide-character is a graphical character.
 *
 * @param wc The wide-character to check.
 * @return Returns a non-zero value if the wide-character is a graphical character, otherwise returns 0.
 */
IS_WCTYPE(graph)

/**
 * @brief Checks if the given wide-character is a lowercase letter.
 *
 * @param wc The wide-character to check.
 * @return Returns a non-zero value if the wide-character is a lowercase letter, otherwise returns 0.
 */
IS_WCTYPE(lower)

/**
 * @brief Checks if the given wide-character is a printable character.
 *
 * @param wc The wide-character to check.
 * @return Returns a non-zero value if the wide-character is printable, otherwise returns 0.
 */
IS_WCTYPE(print)

/**
 * @brief Checks if the given wide-character is a punctuation character.
 *
 * @param wc The wide-character to check.
 * @return Returns a non-zero value if the wide-character is a punctuation character, otherwise returns 0.
 */
IS_WCTYPE(punct)

/**
 * @brief Checks if the given wide-character is a whitespace character,
 * (space, form-feed, newline, carriage return, horizontal tab, or vertical tab).
 *
 * @param wc The wide-character to check.
 * @return Returns a non-zero value if the wide-character is whitespace, otherwise returns 0.
 */
IS_WCTYPE(space)

/**
 * @brief Checks if the given wide-character is an uppercase letter.
 *
 * @param wc The wide-character to check.
 * @return Returns a non-zero value if the wide-character is an uppercase letter, otherwise returns 0.
 */
IS_WCTYPE(upper)

/**
 * @brief Checks if the given wide-character is a hexadecimal digit.
 *
 * @param wc The wide-character to check.
 * @return Returns a non-zero value if the wide-character is a hexadecimal digit, otherwise returns 0.
 */
IS_WCTYPE(xdigit)

/**
 * @brief Checks if the given wide-character is a blank character (space or tab).
 *
 * @param wc The wide-character to check.
 * @return Returns a non-zero value if the wide-character is a blank character, otherwise returns 0.
 */
IS_WCTYPE(blank)

/**
 * @brief Converts a wide-character to lowercase.
 *
 * @param wc The wide-character to convert.
 * @return Returns the lowercase equivalent of the wide-character if it exists, otherwise returns the original wide-character.
 */
wint_t towlower(wint_t c) {
	if (iswupper(c)) {
		/* NOTE: ASCII specific */
		c |= 0x20;
	}
	return c;
}

/**
 * @brief Converts a wide-character to uppercase.
 *
 * @param wc The wide-character to convert.
 * @return Returns the uppercase equivalent of the wide-character if it exists, otherwise returns the original wide-character.
 */
wint_t towupper(wint_t c) {
	if (iswlower(c)) {
		/* NOTE: ASCII specific */
		c &= (wint_t)~0x20;
	}
	return c;
}

/**
 * @brief Returns a wide-character translation mapping, given by its name.
 *
 * @param str The name of the translation mapping.
 * @return Returns a wide-character translation mapping if the name is valid, otherwise returns 0.
 * @note The function supports two mappings: "toupper" and "tolower".
 */
wctrans_t wctrans(const char *str) {

	/* this would obviously be faster as a trie, but do we care? */

	if (strcmp(str, "toupper") == 0) {
		return WCTRANS_UPPER;
	} else if (strcmp(str, "tolower") == 0) {
		return WCTRANS_LOWER;
	}

	return 0;
}

/**
 * @brief Returns a wide-character class, given by its name.
 *
 * @param st The name of the wide-character class.
 * @return Returns a wide-character class if the name is valid, otherwise returns 0.
 * @note The function supports various classes such as "alnum", "alpha", "blank", "cntrl", "digit", "graph", "lower", "print", "space", "upper", and "xdigit".
 */
wctype_t wctype(const char *str) {

	/* this would obviously be faster as a trie, but do we care? */

	if (strcmp(str, "alnum") == 0) {
		return WCTYPE_ALNUM;
	} else if (strcmp(str, "alpha") == 0) {
		return WCTYPE_ALPHA;
	} else if (strcmp(str, "blank") == 0) {
		return WCTYPE_BLANK;
	} else if (strcmp(str, "cntrl") == 0) {
		return WCTYPE_CNTRL;
	} else if (strcmp(str, "digit") == 0) {
		return WCTYPE_DIGIT;
	} else if (strcmp(str, "graph") == 0) {
		return WCTYPE_GRAPH;
	} else if (strcmp(str, "lower") == 0) {
		return WCTYPE_LOWER;
	} else if (strcmp(str, "print") == 0) {
		return WCTYPE_PRINT;
	} else if (strcmp(str, "space") == 0) {
		return WCTYPE_SPACE;
	} else if (strcmp(str, "upper") == 0) {
		return WCTYPE_UPPER;
	} else if (strcmp(str, "xdigit") == 0) {
		return WCTYPE_XDIGIT;
	}

	return 0;
}

/**
 * @brief Checks if the given wide-character belongs to the specified character class.
 *
 * @param wc The wide-character to check.
 * @param desc The character class to check against.
 * @return Returns a non-zero value if the wide-character belongs to the specified class, otherwise returns 0.
 */
int iswctype(wint_t wc, wctype_t desc) {
	switch (desc) {
	case WCTYPE_ALNUM:
		return iswalnum(wc);
	case WCTYPE_ALPHA:
		return iswalpha(wc);
	case WCTYPE_CNTRL:
		return iswcntrl(wc);
	case WCTYPE_DIGIT:
		return iswdigit(wc);
	case WCTYPE_GRAPH:
		return iswgraph(wc);
	case WCTYPE_LOWER:
		return iswlower(wc);
	case WCTYPE_PRINT:
		return iswprint(wc);
	case WCTYPE_PUNCT:
		return iswpunct(wc);
	case WCTYPE_SPACE:
		return iswspace(wc);
	case WCTYPE_UPPER:
		return iswupper(wc);
	case WCTYPE_XDIGIT:
		return iswxdigit(wc);
	case WCTYPE_BLANK:
		return iswblank(wc);
	default:
		return 0;
	}
}

/**
 * @brief Converts a wide-character to its corresponding character using the specified translation mapping.
 *
 * @param wc The wide-character to convert.
 * @param desc The translation mapping to use.
 * @return Returns the converted wide-character if the mapping is valid, otherwise returns 0.
 */
wint_t towctrans(wint_t wc, wctrans_t desc) {
	switch (desc) {
	case WCTRANS_UPPER:
		return towupper(wc);
	case WCTRANS_LOWER:
		return towlower(wc);
	default:
		return 0;
	}
}
