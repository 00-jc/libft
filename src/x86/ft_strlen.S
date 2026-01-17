# **************************************************************************** ;
#                                                                              ;
#                                                         :::      ::::::::    ;
#    ft_strlen.S                                        :+:      :+:    :+:    ;
#                                                     +:+ +:+         +:+      ;
#    By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+         ;
#                                                 +#+#+#+#+#+   +#+            ;
#    Created: 2026/01/17 07:33:59 by jaicastr          #+#    #+#              ;
#    Updated: 2026/01/17 07:33:59 by jaicastr         ###   ########.fr        ;
#                                                                              ;
# **************************************************************************** ;

#if	defined(__AVX512VL__) && !defined(__LIBFT_SCALAR__)

.global ft_strlen
.type ft_strlen, @function
.text
ft_strlen:
	mov			%rdi, %rsi
	xor			%rax, %rax
	prefetcht1	256(%rdi)
.Lunaligned:
	test			$63, %rsi
	jz				.Laligned_loop_setup
	movb			(%rsi), %al
	test			%al, %al
	jz				.Lret
	inc				%rsi
	jmp				.Lunaligned
.Laligned_loop_setup:
	vpxorq			%zmm15,%zmm15,%zmm15
.Laligned_loop:
	vptestnmb		(%rsi),		%zmm15, %k0
	vptestnmb		64(%rsi),	%zmm15, %k1
	vptestnmb		128(%rsi),	%zmm15, %k3
	vptestnmb		192(%rsi),	%zmm15, %k4
	korq            %k0, %k1, %k2
	ktestq          %k2, %k2
	jnz				.Lfound1
	korq            %k3, %k4, %k5
	ktestq          %k5, %k5
	jnz				.Lfound2
	add				$256, %rsi
	jmp				.Laligned_loop
.Lfound1:
	xor				%r15, %r15
	movq			$64, %rax
	kmovq			%k0, %r8
	kmovq			%k1, %r9
	test			%r8, %r8
	cmovz			%r9, %r8
	cmovz			%rax, %r15
	tzcnt			%r8, %r8
	add				%r15, %rsi
	add				%r8,  %rsi
	jmp				.Lret
.Lfound2:
	movq			$128, %r15
	movq			$192, %rax
	kmovq			%k3, %r8
	kmovq			%k4, %r9
	test			%r8, %r8
	cmovz			%r9, %r8
	cmovz			%rax, %r15
	tzcnt			%r8, %r8
	add				%r15, %rsi
	add				%r8,  %rsi
.Lret:
	mov	%rsi, %rax
	sub	%rdi, %rax
	ret
.section .note.GNU-stack,"",@progbits

#endif
