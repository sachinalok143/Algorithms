	.file	"assi0.cpp"
	.globl	k
	.bss
	.align 4
	.type	k, @object
	.size	k, 4
k:
	.zero	4
	.globl	i
	.align 4
	.type	i, @object
	.size	i, 4
i:
	.zero	4
	.section	.rodata
.LC0:
	.string	"+++++%d\n"
.LC1:
	.string	"%d"
.LC2:
	.string	"%i\n"
	.text
	.globl	_Z6getNumiiiPi
	.type	_Z6getNumiiiPi, @function
_Z6getNumiiiPi:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movl	%edi, -20(%rbp)
	movl	%esi, -24(%rbp)
	movl	%edx, -28(%rbp)
	movq	%rcx, -40(%rbp)
	movl	-28(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	cmpl	$0, -24(%rbp)
	jle	.L18
	cmpl	$0, -28(%rbp)
	js	.L18
	cmpl	$0, -28(%rbp)
	jne	.L5
	movl	k(%rip), %eax
	cltq
	salq	$3, %rax
	movq	%rax, %rdi
	call	malloc
	movq	%rax, -8(%rbp)
	movl	$0, i(%rip)
.L7:
	movl	i(%rip), %eax
	cmpl	$9, %eax
	jg	.L6
	movl	i(%rip), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-40(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-8(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %edx
	addl	$1, %edx
	movl	%edx, (%rax)
	movl	i(%rip), %eax
	addl	$1, %eax
	movl	%eax, i(%rip)
	jmp	.L7
.L6:
	movl	$0, i(%rip)
.L13:
	movl	i(%rip), %eax
	cmpl	$9, %eax
	jg	.L19
	movl	i(%rip), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-40(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %edx
	movl	i(%rip), %eax
	cltq
	leaq	0(,%rax,4), %rcx
	movq	-8(%rbp), %rax
	addq	%rcx, %rax
	movl	(%rax), %eax
	cmpl	%eax, %edx
	jne	.L20
	movl	k(%rip), %eax
	leal	-1(%rax), %edx
	movl	i(%rip), %eax
	cmpl	%eax, %edx
	jne	.L10
	movl	$0, i(%rip)
.L12:
	movl	i(%rip), %eax
	cmpl	$9, %eax
	jg	.L11
	movl	i(%rip), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-40(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	%eax, %esi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	movl	i(%rip), %eax
	addl	$1, %eax
	movl	%eax, i(%rip)
	jmp	.L12
.L11:
	movl	$10, %edi
	call	putchar
.L10:
	movl	i(%rip), %eax
	addl	$1, %eax
	movl	%eax, i(%rip)
	jmp	.L13
.L20:
	nop
	jmp	.L19
.L5:
	movl	$0, i(%rip)
.L16:
	movl	i(%rip), %eax
	cmpl	$9, %eax
	jg	.L21
	movl	i(%rip), %eax
	movl	-28(%rbp), %edx
	subl	%eax, %edx
	movl	%edx, %eax
	testl	%eax, %eax
	js	.L15
	movl	i(%rip), %eax
	movl	%eax, %esi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	movl	-20(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-40(%rbp), %rax
	addq	%rax, %rdx
	movl	i(%rip), %eax
	movl	%eax, (%rdx)
	addl	$1, -20(%rbp)
	movl	i(%rip), %eax
	movl	-28(%rbp), %edx
	movl	%edx, %edi
	subl	%eax, %edi
	movl	-24(%rbp), %eax
	leal	-1(%rax), %esi
	movq	-40(%rbp), %rdx
	movl	-20(%rbp), %eax
	movq	%rdx, %rcx
	movl	%edi, %edx
	movl	%eax, %edi
	call	_Z6getNumiiiPi
.L15:
	movl	i(%rip), %eax
	addl	$1, %eax
	movl	%eax, i(%rip)
	jmp	.L16
.L18:
	nop
	jmp	.L1
.L19:
	nop
	jmp	.L1
.L21:
	nop
.L1:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	_Z6getNumiiiPi, .-_Z6getNumiiiPi
	.globl	_Z7getNum1iPi
	.type	_Z7getNum1iPi, @function
_Z7getNum1iPi:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	movq	%rsi, -32(%rbp)
	movl	$1, -4(%rbp)
.L25:
	cmpl	$9, -4(%rbp)
	jg	.L26
	movl	-20(%rbp), %eax
	subl	-4(%rbp), %eax
	testl	%eax, %eax
	js	.L24
	movq	-32(%rbp), %rax
	movl	-4(%rbp), %edx
	movl	%edx, (%rax)
	movl	-20(%rbp), %eax
	subl	-4(%rbp), %eax
	movl	-20(%rbp), %edx
	leal	-2(%rdx), %esi
	movq	-32(%rbp), %rdx
	movq	%rdx, %rcx
	movl	%eax, %edx
	movl	$1, %edi
	call	_Z6getNumiiiPi
.L24:
	addl	$1, -4(%rbp)
	jmp	.L25
.L26:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	_Z7getNum1iPi, .-_Z7getNum1iPi
	.globl	main
	.type	main, @function
main:
.LFB4:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	leaq	-24(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	scanf
	movl	-24(%rbp), %eax
	movl	%eax, k(%rip)
	movl	-24(%rbp), %eax
	cltq
	salq	$3, %rax
	movq	%rax, %rdi
	call	malloc
	movq	%rax, -16(%rbp)
	movl	$0, -20(%rbp)
.L29:
	movl	-24(%rbp), %eax
	cmpl	%eax, -20(%rbp)
	jge	.L28
	movl	-20(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-16(%rbp), %rax
	addq	%rdx, %rax
	movl	$0, (%rax)
	addl	$1, -20(%rbp)
	jmp	.L29
.L28:
	movl	-24(%rbp), %eax
	movq	-16(%rbp), %rdx
	movq	%rdx, %rsi
	movl	%eax, %edi
	call	_Z7getNum1iPi
	movl	$0, %eax
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L31
	call	__stack_chk_fail
.L31:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.5) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
