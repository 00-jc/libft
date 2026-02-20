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

#if	defined(__AVX512VL__) && defined(__x86_64__) && !defined(__LIBFT_PORTABLE__)

.global ft_strlen
.type ft_strlen, @function
.text
ft_strlen:
	endbr64
    mov           	%rdi, %rsi
    xor            	%rax, %rax
    vpxorq          %zmm15,%zmm15,%zmm15
    prefetcht1     	256(%rdi)
	test			$63, %rdi
	jz				.Laligned_loop
	vpcmpeqb		(%rsi),	%zmm15, %k0
	ktestq          %k0, %k0
	jz				.Laligned_loop_setup
	kmovq			%k0, %r8
	tzcnt			%r8, %r8
	add				%r8, %rsi
	jmp				.Lret
.Laligned_loop_setup:
	add    $64, %rsi
	and    $-64, %rsi 
.Laligned_loop:
    prefetcht1     	256(%rsi)
	vpcmpeqb		(%rsi),		%zmm15, %k0
	vpcmpeqb		64(%rsi),	%zmm15, %k1
	vpcmpeqb		128(%rsi),	%zmm15, %k3
	vpcmpeqb	   	192(%rsi),	%zmm15, %k4
	korq            %k0, %k1, %k2
	ktestq          %k2, %k2
	jnz				.Lfound1
	korq            %k3, %k4, %k5
	ktestq          %k5, %k5
	jnz				.Lfound2
	add				$256, %rsi
	jmp				.Laligned_loop
.Lfound1:
	xor				%r10, %r10
	movq			$64, %rax
	kmovq			%k0, %r8
	kmovq			%k1, %r9
	test			%r8, %r8
	cmovz			%r9, %r8
	cmovz			%rax, %r10
	tzcnt			%r8, %r8
	add				%r10, %rsi
	add				%r8,  %rsi
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
	add				%r10, %rsi
	add				%r8,  %rsi
.Lret:
	mov	%rsi, %rax
	sub	%rdi, %rax
	ret
.section .note.GNU-stack,"",@progbits

#endif
