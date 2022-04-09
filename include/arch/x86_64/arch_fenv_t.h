
#ifndef _ARCH_X86_64_ARCH_FENV_T_H_20140319_
#define _ARCH_X86_64_ARCH_FENV_T_H_20140319_

typedef struct {
	/* +00 */ unsigned short __control_word;
	/* +02 */ unsigned short __unused1;
	/* +04 */ unsigned short __status_word;
	/* +06 */ unsigned short __unused2;
	/* +08 */ unsigned short __tag_word;
	/* +10 */ unsigned short __unused3;
	/* +12 */ unsigned int __ip;
	/* +16 */ unsigned short __cs_selector;
	/* +18 */ unsigned short __unused4;
	/* +20 */ unsigned int __operand_address;
	/* +24 */ unsigned short __data_segement;
	/* +26 */ unsigned short __unused5;
	/* +28 */ unsigned int __mxcsr;
} fenv_t;

#endif
