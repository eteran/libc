
#define _ELIBC_SOURCE
#define _ELIBC_SAFE_STRING
#include <assert.h>
#include <limits.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* TODO(eteran): support restoring locales with overrides: setlocale(LC_ALL,
 * "LC_COLLATE=C;LC_CTYPE=C;LC_MONETARY=C;LC_NUMERIC=C;LC_TIME=C") */

static const struct locale_support_t {
	const char *const name;
	const int type;
	const struct lconv locale;
} __elibc_supported_locales[] = {
	{"C",
	 _ELIBC_ASCII,
	 {"", ".", "", "", "", "", "", "", "", "", CHAR_MAX, CHAR_MAX, CHAR_MAX, CHAR_MAX, CHAR_MAX,
	  CHAR_MAX, CHAR_MAX, CHAR_MAX}},
	{"POSIX",
	 _ELIBC_ASCII,
	 {"", ".", "", "", "", "", "", "", "", "", CHAR_MAX, CHAR_MAX, CHAR_MAX, CHAR_MAX, CHAR_MAX,
	  CHAR_MAX, CHAR_MAX, CHAR_MAX}},
	{"en_US",
	 _ELIBC_ASCII,
	 {"$", ".", "", "USD", ".", "", ",", "-", "", ",", 2, 2, 1, 0, 1, 1, 1, 1}},
	{"en_US.UTF-8",
	 _ELIBC_UTF8,
	 {"$", ".", "", "USD", ".", "", ",", "-", "", ",", 2, 2, 1, 0, 1, 1, 1, 1}},
	{0,
	 _ELIBC_ASCII,
	 {"", "", "", "", "", "", "", "", "", "", CHAR_MAX, CHAR_MAX, CHAR_MAX, CHAR_MAX, CHAR_MAX,
	  CHAR_MAX, CHAR_MAX, CHAR_MAX}}};

static struct locale_meta_t {
	const char *name;
	int type;
} __elibc_locale_meta[_ELIBC_LC_ALL + 1] = {
	{"", _ELIBC_ASCII},
	{"", _ELIBC_ASCII},
	{"", _ELIBC_ASCII},
	{"", _ELIBC_ASCII},
	{"", _ELIBC_ASCII},
	{"", _ELIBC_ASCII},
};

/*------------------------------------------------------------------------------
// Name: __elibc_categories_equal
//----------------------------------------------------------------------------*/
static int __elibc_categories_equal() {

	const char *const name = __elibc_locale_meta[_ELIBC_LC_ALL].name;
	int i;
	for (i = 0; i < _ELIBC_LC_ALL; ++i) {
		if (__elibc_locale_meta[i].name != name) {
			return 0;
		}
	}

	return 1;
}

/*------------------------------------------------------------------------------
// Name: __elibc_get_locale_type
//----------------------------------------------------------------------------*/
int __elibc_get_locale_type(int category) {
	return __elibc_locale_meta[category].type;
}

/*------------------------------------------------------------------------------
// Name: __elibc_setlocale
//----------------------------------------------------------------------------*/
static char *__elibc_setlocale(struct lconv *current_lconv, int category, const char *locname,
							   char *locale_name, size_t locale_name_size) {

	if (locname) {
		const struct locale_support_t *p = __elibc_supported_locales;
		while (p->name) {

			/* see if we match this locales name*/
			if ((strcmp(locname, p->name) == 0)) {

				if (category & LC_COLLATE) {
					__elibc_locale_meta[_ELIBC_LC_COLLATE].name = p->name;
					__elibc_locale_meta[_ELIBC_LC_COLLATE].type = p->type;
				}

				if (category & LC_CTYPE) {
					__elibc_locale_meta[_ELIBC_LC_CTYPE].name = p->name;
					__elibc_locale_meta[_ELIBC_LC_CTYPE].type = p->type;
				}

				if (category & LC_MONETARY) {
					current_lconv->currency_symbol               = p->locale.currency_symbol;
					current_lconv->int_curr_symbol               = p->locale.int_curr_symbol;
					current_lconv->mon_decimal_point             = p->locale.mon_decimal_point;
					current_lconv->mon_grouping                  = p->locale.mon_grouping;
					current_lconv->mon_thousands_sep             = p->locale.mon_thousands_sep;
					current_lconv->negative_sign                 = p->locale.negative_sign;
					current_lconv->positive_sign                 = p->locale.positive_sign;
					current_lconv->frac_digits                   = p->locale.frac_digits;
					current_lconv->int_frac_digits               = p->locale.int_frac_digits;
					current_lconv->n_cs_precedes                 = p->locale.n_cs_precedes;
					current_lconv->n_sep_by_space                = p->locale.n_sep_by_space;
					current_lconv->n_sign_posn                   = p->locale.n_sign_posn;
					current_lconv->p_cs_precedes                 = p->locale.p_cs_precedes;
					current_lconv->p_sep_by_space                = p->locale.p_sep_by_space;
					current_lconv->p_sign_posn                   = p->locale.p_sign_posn;
					__elibc_locale_meta[_ELIBC_LC_MONETARY].name = p->name;
					__elibc_locale_meta[_ELIBC_LC_MONETARY].type = p->type;
				}

				if (category & LC_NUMERIC) {
					current_lconv->decimal_point                = p->locale.decimal_point;
					current_lconv->grouping                     = p->locale.grouping;
					current_lconv->thousands_sep                = p->locale.thousands_sep;
					__elibc_locale_meta[_ELIBC_LC_NUMERIC].name = p->name;
					__elibc_locale_meta[_ELIBC_LC_NUMERIC].type = p->type;
				}

				if (category & LC_TIME) {
					__elibc_locale_meta[_ELIBC_LC_TIME].name = p->name;
					__elibc_locale_meta[_ELIBC_LC_TIME].type = p->type;
				}

				if (category == LC_ALL) {
					__elibc_locale_meta[_ELIBC_LC_ALL].name = p->name;
					__elibc_locale_meta[_ELIBC_LC_ALL].type = p->type;
				}

				strlcpy(locale_name, p->name, locale_name_size);
				return locale_name;
			}
			++p;
		}
	}
	return 0;
}

/*------------------------------------------------------------------------------
// Name: setlocale
//----------------------------------------------------------------------------*/
char *setlocale(int category, const char *locname) {

	/* ugly, but prevents us from returning a writeable pointer to an entry in
	 * that table! */
	static _Thread_local char locale_name[256];

	/* get the global locale structure */
	struct lconv *const current_lconv = localeconv();
	assert(current_lconv);

	/* are we setting the locale info? */
	if (locname) {
		/* empty string should pull values from environment */
		if (locname[0] == '\0') {
			switch (category) {
			case LC_COLLATE:
				return __elibc_setlocale(current_lconv, LC_COLLATE, getenv("LC_COLLATE"),
										 locale_name, sizeof(locale_name));
			case LC_CTYPE:
				return __elibc_setlocale(current_lconv, LC_CTYPE, getenv("LC_CTYPE"), locale_name,
										 sizeof(locale_name));
			case LC_MONETARY:
				return __elibc_setlocale(current_lconv, LC_MONETARY, getenv("LC_MONETARY"),
										 locale_name, sizeof(locale_name));
			case LC_NUMERIC:
				return __elibc_setlocale(current_lconv, LC_NUMERIC, getenv("LC_NUMERIC"),
										 locale_name, sizeof(locale_name));
			case LC_TIME:
				return __elibc_setlocale(current_lconv, LC_TIME, getenv("LC_TIME"), locale_name,
										 sizeof(locale_name));
			case LC_ALL: {
				char *ret = __elibc_setlocale(current_lconv, LC_ALL, getenv("LC_ALL"), locale_name,
											  sizeof(locale_name));
				if (!ret) {
					/* TODO(eteran): fetch each category from the environment here, but
					 * first check they are all valid before doing anything since POSIX
					 * says so
					 */

					if (!ret) {
						ret = __elibc_setlocale(current_lconv, LC_ALL, getenv("LANG"), locale_name,
												sizeof(locale_name));
						if (!ret) {
							ret = __elibc_setlocale(current_lconv, LC_ALL, getenv("_LOCALE"),
													locale_name, sizeof(locale_name));
						}
					}
				}

				return ret;
			}
			default:
				return 0;
			}
		} else {
			return __elibc_setlocale(current_lconv, category, locname, locale_name,
									 sizeof(locale_name));
		}
	} else {
		if (category == LC_ALL) {

			if (__elibc_categories_equal()) {
				snprintf(locale_name, sizeof(locale_name), "%s",
						 __elibc_locale_meta[_ELIBC_LC_ALL].name);
			} else {
				snprintf(locale_name, sizeof(locale_name),
						 "%s;LC_COLLATE=%s;LC_CTYPE=%s;LC_MONETARY=%s;LC_NUMERIC=%s;LC_"
						 "TIME=%s",
						 __elibc_locale_meta[_ELIBC_LC_ALL].name,
						 __elibc_locale_meta[_ELIBC_LC_COLLATE].name,
						 __elibc_locale_meta[_ELIBC_LC_CTYPE].name,
						 __elibc_locale_meta[_ELIBC_LC_MONETARY].name,
						 __elibc_locale_meta[_ELIBC_LC_NUMERIC].name,
						 __elibc_locale_meta[_ELIBC_LC_TIME].name);
			}
		} else {
			switch (category) {
			case LC_COLLATE:
				strlcpy(locale_name, __elibc_locale_meta[_ELIBC_LC_COLLATE].name,
						sizeof(locale_name));
				break;
			case LC_CTYPE:
				strlcpy(locale_name, __elibc_locale_meta[_ELIBC_LC_CTYPE].name,
						sizeof(locale_name));
				break;
			case LC_MONETARY:
				strlcpy(locale_name, __elibc_locale_meta[_ELIBC_LC_MONETARY].name,
						sizeof(locale_name));
				break;
			case LC_NUMERIC:
				strlcpy(locale_name, __elibc_locale_meta[_ELIBC_LC_NUMERIC].name,
						sizeof(locale_name));
				break;
			case LC_TIME:
				strlcpy(locale_name, __elibc_locale_meta[_ELIBC_LC_TIME].name, sizeof(locale_name));
				break;
			default:
				return 0;
			}
		}
		return locale_name;
	}
}
