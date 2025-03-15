
#define _ELIBC_SOURCE
#include <ctype.h>
#include <stdint.h>

/* TODO(eteran): locale awareness of any kind ? */

#define CTYPE_SPACE  0x0001
#define CTYPE_PRINT  0x0002
#define CTYPE_CNTRL  0x0004
#define CTYPE_UPPER  0x0008
#define CTYPE_LOWER  0x0010
#define CTYPE_DIGIT  0x0020
#define CTYPE_PUNCT  0x0040
#define CTYPE_XDIGIT 0x0080
#define CTYPE_BLANK  0x0100
#define CTYPE_ALPHA  (CTYPE_LOWER | CTYPE_UPPER)
#define CTYPE_ALNUM  (CTYPE_ALPHA | CTYPE_DIGIT)
#define CTYPE_GRAPH  (CTYPE_ALNUM | CTYPE_PUNCT)

/* a simple table, valid for "C" local only */
/* clang-format off */
static const uint16_t __elibc_ctype_tab[] = {
	0x0004, 0x0004, 0x0004, 0x0004, 0x0004, 0x0004, 0x0004, 0x0004,
	0x0004, 0x0105, 0x0005, 0x0005, 0x0005, 0x0005, 0x0004, 0x0004,
	0x0004, 0x0004, 0x0004, 0x0004, 0x0004, 0x0004, 0x0004, 0x0004,
	0x0004, 0x0004, 0x0004, 0x0004, 0x0004, 0x0004, 0x0004, 0x0004,
	0x0103, 0x0042, 0x0042, 0x0042, 0x0042, 0x0042, 0x0042, 0x0042,
	0x0042, 0x0042, 0x0042, 0x0042, 0x0042, 0x0042, 0x0042, 0x0042,
	0x00a2, 0x00a2, 0x00a2, 0x00a2, 0x00a2, 0x00a2, 0x00a2, 0x00a2,
	0x00a2, 0x00a2, 0x0042, 0x0042, 0x0042, 0x0042, 0x0042, 0x0042,
	0x0042, 0x008a, 0x008a, 0x008a, 0x008a, 0x008a, 0x008a, 0x000a,
	0x000a, 0x000a, 0x000a, 0x000a, 0x000a, 0x000a, 0x000a, 0x000a,
	0x000a, 0x000a, 0x000a, 0x000a, 0x000a, 0x000a, 0x000a, 0x000a,
	0x000a, 0x000a, 0x000a, 0x0042, 0x0042, 0x0042, 0x0042, 0x0042,
	0x0042, 0x0092, 0x0092, 0x0092, 0x0092, 0x0092, 0x0092, 0x0012,
	0x0012, 0x0012, 0x0012, 0x0012, 0x0012, 0x0012, 0x0012, 0x0012,
	0x0012, 0x0012, 0x0012, 0x0012, 0x0012, 0x0012, 0x0012, 0x0012,
	0x0012, 0x0012, 0x0012, 0x0042, 0x0042, 0x0042, 0x0042, 0x0004,
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

#define IS_CTYPE(name, type)                             \
	int name(int c) {                                    \
		if (_LIKELY((unsigned int)c < 0x100)) {          \
			return (__elibc_ctype_tab[c] & (type)) != 0; \
		}                                                \
		return 0;                                        \
	}

/**
 * @brief Checks if the given character is an alphanumeric character.
 *
 * @param c The character to check.
 * @return Returns a non-zero value if the character is alphanumeric, otherwise returns 0.
 */
IS_CTYPE(isalnum, CTYPE_ALNUM)

/**
 * @brief Checks if the given character is an alphabetic character.
 *
 * @param c The character to check.
 * @return Returns a non-zero value if the character is alphabetic, otherwise returns 0.
 */
IS_CTYPE(isalpha, CTYPE_ALPHA)

/**
 * @brief Checks if the given character is a control character.
 *
 * @param c The character to check.
 * @return Returns a non-zero value if the character is a control character, otherwise returns 0.
 */
IS_CTYPE(iscntrl, CTYPE_CNTRL)

/**
 * @brief Checks if the given character is a digit.
 *
 * @param c The character to check.
 * @return Returns a non-zero value if the character is a digit, otherwise returns 0.
 */
IS_CTYPE(isdigit, CTYPE_DIGIT)


/**
 * @brief Checks if the given character is a graphical character.
 *
 * @param c The character to check.
 * @return Returns a non-zero value if the character is a graphical character, otherwise returns 0.
 */
IS_CTYPE(isgraph, CTYPE_GRAPH)


/**
 * @brief Checks if the given character is a lowercase letter.
 *
 * @param c The character to check.
 * @return Returns a non-zero value if the character is a lowercase letter, otherwise returns 0.
 */
IS_CTYPE(islower, CTYPE_LOWER)


/**
 * @brief Checks if the given character is a printable character.
 *
 * @param c The character to check.
 * @return Returns a non-zero value if the character is printable, otherwise returns 0.
 */
IS_CTYPE(isprint, CTYPE_PRINT)


/**
 * @brief Checks if the given character is a punctuation character.
 *
 * @param c The character to check.
 * @return Returns a non-zero value if the character is punctuation, otherwise returns 0.
 */
IS_CTYPE(ispunct, CTYPE_PUNCT)


/**
 * @brief Checks if the given character is a whitespace character,
 * (space, form-feed, newline, carriage return, horizontal tab, or vertical tab).
 *
 * @param c The character to check.
 * @return Returns a non-zero value if the character is whitespace, otherwise returns 0.
 */
IS_CTYPE(isspace, CTYPE_SPACE)


/**
 * @brief Checks if the given character is an uppercase letter.
 *
 * @param c The character to check.
 * @return Returns a non-zero value if the character is an uppercase letter, otherwise returns 0.
 */
IS_CTYPE(isupper, CTYPE_UPPER)


/**
 * @brief Checks if the given character is a hexadecimal digit.
 *
 * @param c The character to check.
 * @return Returns a non-zero value if the character is a hexadecimal digit, otherwise returns 0.
 */
IS_CTYPE(isxdigit, CTYPE_XDIGIT)

/**
 * @brief Checks if the given character is a blank character (space or tab).
 *
 * @param c The character to check.
 * @return Returns a non-zero value if the character is a blank character, otherwise returns 0.
 */
IS_CTYPE(isblank, CTYPE_BLANK)

/**
 * @brief Converts a character to lowercase.
 *
 * @param c The character to convert.
 * @return Returns the lowercase equivalent of the character if it is an uppercase letter, otherwise returns the character unchanged.
 */
int tolower(int c) {
	if (_LIKELY(isupper(c))) {
		/* NOTE(eteran): ASCII specific */
		c |= 0x20;
	}
	return c;
}

/**
 * @brief Converts a character to uppercase.
 *
 * @param c The character to convert.
 * @return Returns the uppercase equivalent of the character if it is a lowercase letter, otherwise returns the character unchanged.
 */
int toupper(int c) {
	if (_LIKELY(islower(c))) {
		/* NOTE(eteran): ASCII specific */
		c &= ~0x20;
	}
	return c;
}

#undef IS_CTYPE
