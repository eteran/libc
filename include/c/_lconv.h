
#ifndef _C_LCONV_H_20051228_
#define _C_LCONV_H_20051228_

struct lconv {
	/* mandatory fields */
	char *currency_symbol;
	char *decimal_point;
	char *grouping;
	char *int_curr_symbol;
	char *mon_decimal_point;
	char *mon_grouping;
	char *mon_thousands_sep;
	char *negative_sign;
	char *positive_sign;
	char *thousands_sep;
	char frac_digits;
	char int_frac_digits;
	char n_cs_precedes;
	char n_sep_by_space;
	char n_sign_posn;
	char p_cs_precedes;
	char p_sep_by_space;
	char p_sign_posn;

	char int_p_cs_precedes;  /* CHAR_MAX */
	char int_n_cs_precedes;  /* CHAR_MAX */
	char int_p_sep_by_space; /* CHAR_MAX */
	char int_n_sep_by_space; /* CHAR_MAX */
	char int_p_sign_posn;    /* CHAR_MAX */
	char int_n_sign_posn;    /* CHAR_MAX */
};

#endif
