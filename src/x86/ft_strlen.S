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

#if	defined(__AVX512F__) && !defined(__LIBFT_SCALAR__)

.global ft_strlen
.type ft_strlen, @function
.text
ft_strlen:
	mov		%rdi, %rsi
	xor		%rax, %rax
.Lunaligned:
	test			$63, %rsi
	jz				.Laligned
	movb			(%rsi), %al
	test			%al, %al
	jz				.Lret
	inc				%rsi
	jmp				.Lunaligned
.Laligned:
	vpxord			%zmm1,%zmm1,%zmm1
.Laligned_loop:
	vmovdqa64		(%rsi),		%zmm0
	vpminub			64(%rsi),	%zmm0, %zmm1
	vmovdqa64		128(%rsi),	%zmm2
	vpminub			192(%rsi),	%zmm2, %zmm3
	vptestnmb		%zmm1,%zmm1,%k0
	vptestnmb		%zmm3,%zmm3,%k1
	kmovq			%k0, %r9
	test        	%r9, %r9
	jnz				.Lfound2
	kmovq			%k1, %r9
	test        	%r9, %r9
	jnz				.Lfound4
	add				$256,	%rsi
	jmp				.Laligned_loop
.Lfound2:
	vptestnmb		%zmm0,%zmm0,%k0
	kmovq			%k0, %r8
	test			%r8, %r8
	jnz				.Lfound1
	tzcnt			%r9, %r9
	add				%r9, %rsi
	add				$64, %rsi
	jmp				.Lret
.Lfound4:
	vptestnmb		%zmm2,%zmm2,%k0
	kmovq			%k0, %r8
	test			%r8, %r8
	jnz				.Lfound3		
	tzcnt			%r9, %r9
	add				%r9, %rsi
	add				$192, %rsi
	jmp				.Lret
.Lfound1:
	tzcnt			%r8, %r8
	add				%r8, %rsi
	jmp				.Lret
.Lfound3:
	tzcnt			%r8, %r8
	add				%r8, %rsi
	add				$128, %rsi
.Lret:
	mov	%rsi, %rax
	sub	%rdi, %rax
	ret
.section .note.GNU-stack,"",@progbits

#endif
