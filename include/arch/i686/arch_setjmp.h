
#ifndef _ARCH_I686_ARCH_SETJMP_H_20051228_
#define _ARCH_I686_ARCH_SETJMP_H_20051228_

struct __elibc_jmp_buf_x86_t {
	unsigned long edi;
	unsigned long esi;
	unsigned long ebp;
	unsigned long esp;
	unsigned long ebx;
	unsigned long edx;
	unsigned long ecx;
	unsigned long eax;
	unsigned long eip;
};

typedef struct {
	struct __elibc_jmp_buf_x86_t state;
} jmp_buf[1];

#endif
