.text
.globl setjmp

setjmp:
	mov %rdi, (%rdi)
	mov %rsi, 8(%rdi)
	mov %rbp, 16(%rdi)
	mov %rsp, 24(%rdi)
	mov %rbx, 32(%rdi)
	mov %rdx, 40(%rdi)
	mov %rcx, 48(%rdi)
	mov %rax, 56(%rdi)
	mov %r8, 72(%rdi)
	mov %r9, 80(%rdi)
	mov %r10, 88(%rdi)
	mov %r11, 96(%rdi)
	mov %r12, 104(%rdi)
	mov %r13, 112(%rdi)
	mov %r14, 120(%rdi)
	mov %r15, 128(%rdi)

	/* RIP */
	mov (%rsp), %rax
	mov %rax, 64(%rdi)
	
	xor %rax, %rax
	ret

