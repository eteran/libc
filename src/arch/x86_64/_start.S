.text
.globl _start

_start:
	/* get argc from stack */
	pop %rdi

	/* esp now equals argv */
	mov %rsp, %rsi

	/* &argv[argc + 1] == envp */
	lea 8(%rsp, %rdi, 8), %rdx

	jmp __elibc_init
