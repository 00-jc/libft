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

#if	defined(__AVX512VL__) && defined(__x86_64__) && !defined(__LIBFT_SCALAR__)

.global ft_memchr
.type ft_memchr, @function
.text

ft_memchr:
	endbr64
	prefetcht1	512(%rdi)
	xor		%rax,	%rax
	vmovq			%rsi, %xmm0
	vpbroadcastb	%xmm0, %zmm15
	cmp				$64, %rdx
	jb				.Ltail
	test			$63, %rdi
	jz				.Laligned_loop_setup
	vmovdqu64		(%rdi),	%zmm0
	vpcmpeqb		%zmm0,	%zmm15, %k0
	ktestq          %k0, %k0
	jz				.Laligned_loop_setup
	kmovq			%k0, %r8
	tzcnt			%r8, %r8
	cmp				%rdx, %r8
	jae				.Lnotfound
	add				%r8, %rdi
	jmp				.Lret
.Laligned_loop_setup:
	mov    %rdi, %r10
	add    $64, %rdi
	and    $-64, %rdi
	sub    %r10, %rdi
	sub    %rdi, %rdx
	add    %r10, %rdi 
.Lmain_loop:
	cmp				$256,	%rdx
	jb				.Ltail
	vpcmpeqb		(%rdi),		%zmm15, %k0
	vpcmpeqb		64(%rdi),	%zmm15, %k1
	vpcmpeqb		128(%rdi),	%zmm15, %k3
	vpcmpeqb		192(%rdi),	%zmm15, %k4
	korq            %k0, %k1, %k2
	ktestq          %k2, %k2
	jnz				.Lfound1
	korq            %k3, %k4, %k5
	ktestq          %k5, %k5
	jnz				.Lfound2
	sub				$256, %rdx
	add				$256, %rdi
	jmp				.Lmain_loop
.Lfound1:
	xor				%r10, %r10
	movq			$64, %rax
	kmovq			%k0, %r8
	kmovq			%k1, %r9
	test			%r8, %r8
	cmovz			%r9, %r8
	cmovz			%rax, %r10
	tzcnt			%r8, %r8
	add				%r10, %rdi
	add				%r8,  %rdi
	jmp				.Lret
.Lfound2:
	movq			$128, %r10
	movq			$192, %rax
	kmovq			%k3, %r8
	kmovq			%k4, %r9
	test			%r8, %r8
	cmovz			%r9, %r8
	cmovz			%rax, %r10
	tzcnt			%r8, %r8
	add				%r10, %rdi
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
