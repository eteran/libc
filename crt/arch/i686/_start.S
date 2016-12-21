.code32
.text
.globl _start

_start:
	/* get argc from stack */
	pop %ecx

	/* esp now equals argv */
	mov %esp, %ebx

	/* &argv[argc + 1] == envp */
	lea 4(%esp, %ecx, 4), %eax

	push %eax /* envp */
	push %ebx /* argv */
	push %ecx /* argc */

	call __elibc_init
