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
	jz				.Laligned_loop
	movb			(%rsi), %al
	test			%al, %al
	jz				.Lret
	inc				%rsi
	jmp				.Lunaligned
.Laligned_loop:
	vmovdqa64		(%rsi),		%zmm0
	vpminub			64(%rsi),	%zmm0, %zmm1
	vmovdqa64		128(%rsi),	%zmm2
	vpminub			192(%rsi),	%zmm2, %zmm3
	vptestnmb		%zmm1,%zmm1,%k0
	vptestnmb		%zmm3,%zmm3,%k1
	ktestq			%k0,%k0
	jnz				.Lfound0				
	ktestq			%k1,%k1
	jnz				.Lfound1				
	add				$256,	%rsi
	jmp				.Laligned_loop
.Lfound0:
    xor             %r15,%r15
    mov             $64,%rax
    vptestnmb       %zmm0,%zmm0,%k1
    kmovq           %k1,%r9
    kmovq           %k0,%r8
    ktestq          %k1,%k1
    cmovz           %rax,%r15
    cmovz           %r8,%r9
    tzcnt           %r9,%r9
    add             %r9,%rsi
    add             %r15,%rsi
    jmp             .Lret
.Lfound1:
    mov             $128,%r15
    mov             $192,%rax
    vptestnmb       %zmm2,%zmm2,%k1
    kmovq           %k1,%r9
    kmovq           %k0,%r8
    ktestq          %k1,%k1
    cmovz           %rax,%r15
    cmovz           %r8,%r9
    tzcnt           %r9,%r9
    add             %r9,%rsi
    add             %r15,%rsi
.Lret:
	mov	%rsi, %rax
	sub	%rdi, %rax
	ret
.section .note.GNU-stack,"",@progbits

#endif
