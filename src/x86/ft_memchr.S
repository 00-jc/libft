# **************************************************************************** ;
#                                                                              ;
#                                                         :::      ::::::::    ;
#    ft_memchr.S                                        :+:      :+:    :+:    ;
#                                                     +:+ +:+         +:+      ;
#    By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+         ;
#                                                 +#+#+#+#+#+   +#+            ;
#    Created: 2026/01/17 08:16:13 by jaicastr          #+#    #+#              ;
#    Updated: 2026/01/17 08:16:13 by jaicastr         ###   ########.fr        ;
#                                                                              ;
# **************************************************************************** ;

#if	defined(__AVX512VL__) && !defined(__LIBFT_SCALAR__)

.global ft_memchr
.type ft_memchr, @function
.text

ft_memchr:
	xor		%rax,	%rax
.align_loop:
	test	$63,%rdi
	jz		.Lvec_setup
	test	%rdx,%rdx
	jz		.Lnotfound
	movb	(%rdi), %al
	cmp		%sil,	%al
	je		.Lret
	inc		%rdi
	dec		%rdx
	jmp		.align_loop
.Lvec_setup:
	vmovq			%rsi, %xmm0
	vpbroadcastb	%xmm0, %zmm15
.Lmain_loop:
	cmp				$128,	%rdx
	jb				.Ltail
	vpcmpeqb		(%rdi),		%zmm15, %k0
	vpcmpeqb		64(%rdi),	%zmm15, %k1
	korq            %k0, %k1, %k2
	ktestq          %k2, %k2
	jnz				.Lfound
	sub				$128, %rdx
	add				$128, %rdi
	jmp				.Lmain_loop
.Lfound:
	xor				%r15, %r15
	movq			$64, %rax
	kmovq			%k0, %r8
	kmovq			%k1, %r9
	test			%r8, %r8
	cmovz			%r9, %r8
	cmovz			%rax, %r15
	tzcnt			%r8, %r8
	add				%r15, %rdi
	add				%r8,  %rdi
	jmp				.Lret
.Ltail:
	test	%rdx, %rdx
	jz		.Lnotfound
	movb	(%rdi), %al
	cmp		%sil,	%al
	je		.Lret
	inc		%rdi
	dec		%rdx
	jmp		.Ltail
.Lret:
	mov				%rdi, %rax
	ret
.Lnotfound:
	xor		%rax,%rax
	ret
.section .note.GNU-stack,"",@progbits

#endif
