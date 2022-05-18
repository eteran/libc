.code32
.text
.globl setjmp

setjmp:
	push %ebx
	mov 8(%esp), %ebx
	mov %edi, (%ebx)        /* buf->edi == 0(ebx) */
	mov %esi, 4(%ebx)       /* buf->esi == 4(ebx) */
	mov %ebp, 8(%ebx)       /* buf->ebp == 8(ebx) */
	mov %edx, 20(%ebx)      /* buf->edx == 20(ebx) */
	mov %ecx, 24(%ebx)      /* buf->ecx == 24(ebx) */
	mov %eax, 28(%ebx)      /* buf->eax == 28(ebx) */
	
	mov (%esp), %eax
	mov %eax, 16(%ebx)      /* buf->ebx == 16(ebx)  */
	
    lea 8(%esp), %eax
    mov %eax, 12(%ebx)      /* buf->esp == 12(ebx) */
	
    mov 4(%esp), %eax
    mov %eax, 32(%ebx)      /* buf->eip == 32(ebx) */
	
	pop %ebx
	
	xor %eax,%eax
	ret
