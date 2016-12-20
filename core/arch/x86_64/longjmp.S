.text
.globl longjmp

longjmp:

	/* rax is the return value, don't even bother restoring it */
	mov %rsi, %rax

	test %rax, %rax
	jnz no_adjust
	inc %rax
no_adjust:

#if 0
	/* this should always be self referenced, so don't bother */
	mov (%rdi), %rdi
#endif

	mov 8(%rdi), %rsi
	mov 16(%rdi), %rbp
	mov 24(%rdi), %rsp
	mov 32(%rdi), %rbx
	mov 40(%rdi), %rdx
	mov 48(%rdi), %rcx
	mov 72(%rdi), %r8
	mov 80(%rdi), %r9
	mov 88(%rdi), %r10
	mov 96(%rdi), %r11
	mov 104(%rdi), %r12
	mov 112(%rdi), %r13
	mov 120(%rdi), %r14
	mov 128(%rdi), %r15

	add $8, %rsp  /* pop the old return value off the stack */
	jmp *64(%rdi) /* resume at previous rip */
