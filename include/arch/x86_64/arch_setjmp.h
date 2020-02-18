
#ifndef _ARCH_X86_64_ARCH_SETJMP_H_20051228_
#define _ARCH_X86_64_ARCH_SETJMP_H_20051228_

struct __elibc_jmp_buf_x86_64_t {
	unsigned long rdi; /* 000 */
	unsigned long rsi; /* 008 */
	unsigned long rbp; /* 016 */
	unsigned long rsp; /* 024 */
	unsigned long rbx; /* 032 */
	unsigned long rdx; /* 040 */
	unsigned long rcx; /* 048 */
	unsigned long rax; /* 056 */
	unsigned long rip; /* 064 */
	unsigned long r8;  /* 072 */
	unsigned long r9;  /* 080 */
	unsigned long r10; /* 088 */
	unsigned long r11; /* 096 */
	unsigned long r12; /* 104 */
	unsigned long r13; /* 112 */
	unsigned long r14; /* 120 */
	unsigned long r15; /* 128 */
};

typedef struct {
	struct __elibc_jmp_buf_x86_64_t state;
} jmp_buf[1];

#endif
