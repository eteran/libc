
#ifndef _ARCH_I686_ARCH_FENV_T_H_20140319_
#define _ARCH_I686_ARCH_FENV_T_H_20140319_

typedef struct {
	unsigned short __control_word;
	unsigned short __unused1;
	unsigned short __status_word;
	unsigned short __unused2;
	unsigned short __tags;
	unsigned short __unused3;
	unsigned int   __eip;
	unsigned short __cs_selector;
	unsigned int   __opcode:11;
	unsigned int   __unused4:5;
	unsigned int   __data_offset;
	unsigned short __data_selector;
	unsigned short __unused5;
	unsigned int   __mxcsr;
} fenv_t;

#endif
