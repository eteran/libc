
#ifndef _LCONV_20051228_H_
#define _LCONV_20051228_H_

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
};

#endif
