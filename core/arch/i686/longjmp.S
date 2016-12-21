.code32
.text
.globl longjmp

longjmp:
	mov 4(%esp), %ecx
	mov 8(%esp), %eax

	test %eax, %eax
	jnz no_adjust
	inc %eax
no_adjust:

	mov (%ecx), %edi   /* buf->edi == 0(ecx) */
	mov 4(%ecx), %esi  /* buf->esi == 4(ecx) */
	mov 8(%ecx), %ebp  /* buf->ebp == 8(ecx) */
	mov 12(%ecx), %esp /* buf->esp == 20(ecx) */
	mov 16(%ecx), %ebx /* buf->ebx == 20(ecx) */
	mov 20(%ecx), %edx /* buf->edx == 20(ecx) */
#if 0
	mov 24(%ecx), %ecx /* buf->ecx == 24(ecx) */
	mov 28(%ebx), %eax /* buf->eax == 28(ecx) */
#endif

	add $4, %esp       /* pop the old return value off the stack */
	jmp *32(%ecx)      /* resume at previous eip */
