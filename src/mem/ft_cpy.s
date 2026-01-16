# **************************************************************************** ;
#                                                                              ;
#                                                         :::      ::::::::    ;
#    ft_cpy.s                                           :+:      :+:    :+:    ;
#                                                     +:+ +:+         +:+      ;
#    By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+         ;
#                                                 +#+#+#+#+#+   +#+            ;
#    Created: 2026/01/16 23:26:38 by jaicastr          #+#    #+#              ;
#    Updated: 2026/01/16 23:33:19 by jaicastr         ###   ########.fr        ;
#                                                                              ;
# **************************************************************************** ;

.global ft_cpy
.text
ft_cpy:
    mov     %rsi, %r8
    neg     %r8
    and     $63, %r8
    jz      .Lcheck_size  
    cmp     %rdx, %r8
    cmova   %rdx, %r8
.Lalign_loop:
    test    %r8, %r8
    jz      .Lcheck_size
    movb    (%rsi), %al
    movb    %al, (%rdi)
    inc     %rsi
    inc     %rdi
    dec     %rdx
    dec     %r8
    jmp     .Lalign_loop
.Lcheck_size:
	mov			%rdx,	%r8
	shr			$9,		%r8
	cmp			$32,	%r8
	jae			.Laligned_512x32
	cmp			$16,	%r8
	jae			.Laligned_512x16
	cmp			$8,		%r8
	jae			.Laligned_512x8
	cmp			$2,		%r8
	jae			.Laligned_512x2
	cmp			$1,		%r8
	je			.Laligned_512
	jmp			.Ltail
.Laligned_512x32:
	prefetch	(%rsi)
	prefetchw	(%rdi)
.Laligned_512x32_loop:
	cmp			$2048,	%rdx
	jb			.Lcheck_size
	prefetch	2048(%rsi)
	prefetchw	2048(%rdi)
	vmovdqa64	(%rsi), %zmm0
	vmovdqa64   %zmm0, (%rdi)
	vmovdqa64	64(%rsi), %zmm1
	vmovdqa64   %zmm1, 64(%rdi)
	vmovdqa64	128(%rsi), %zmm2
	vmovdqa64   %zmm2, 128(%rdi)
	vmovdqa64	192(%rsi), %zmm3
	vmovdqa64   %zmm3, 192(%rdi)
	vmovdqa64	256(%rsi), %zmm4
	vmovdqa64   %zmm4, 256(%rdi)
	vmovdqa64	320(%rsi), %zmm5
	vmovdqa64   %zmm5, 320(%rdi)
	vmovdqa64	384(%rsi), %zmm6
	vmovdqa64   %zmm6, 384(%rdi)
	vmovdqa64	448(%rsi), %zmm7
	vmovdqa64   %zmm7, 448(%rdi)
	vmovdqa64	512(%rsi), %zmm8
	vmovdqa64   %zmm8, 512(%rdi)
	vmovdqa64	576(%rsi), %zmm9
	vmovdqa64   %zmm9, 576(%rdi)
	vmovdqa64	640(%rsi), %zmm10
	vmovdqa64   %zmm10, 640(%rdi)
	vmovdqa64	704(%rsi), %zmm11
	vmovdqa64   %zmm11, 704(%rdi)
	vmovdqa64	768(%rsi), %zmm12
	vmovdqa64   %zmm12, 768(%rdi)
	vmovdqa64	832(%rsi), %zmm13
	vmovdqa64   %zmm13, 832(%rdi)
	vmovdqa64	896(%rsi), %zmm14
	vmovdqa64   %zmm14, 896(%rdi)
	vmovdqa64	960(%rsi), %zmm15
	vmovdqa64   %zmm15, 960(%rdi)
	vmovdqa64	1024(%rsi), %zmm0
	vmovdqa64   %zmm0, 1024(%rdi)
	vmovdqa64	1088(%rsi), %zmm1
	vmovdqa64   %zmm1, 1088(%rdi)
	vmovdqa64	1152(%rsi), %zmm2
	vmovdqa64   %zmm2, 1152(%rdi)
	vmovdqa64	1216(%rsi), %zmm3
	vmovdqa64   %zmm3, 1216(%rdi)
	vmovdqa64	1280(%rsi), %zmm4
	vmovdqa64   %zmm4, 1280(%rdi)
	vmovdqa64	1344(%rsi), %zmm5
	vmovdqa64   %zmm5, 1344(%rdi)
	vmovdqa64	1408(%rsi), %zmm6
	vmovdqa64   %zmm6, 1408(%rdi)
	vmovdqa64	1472(%rsi), %zmm7
	vmovdqa64   %zmm7, 1472(%rdi)
	vmovdqa64	1536(%rsi), %zmm8
	vmovdqa64   %zmm8, 1536(%rdi)
	vmovdqa64	1600(%rsi), %zmm9
	vmovdqa64   %zmm9, 1600(%rdi)
	vmovdqa64	1664(%rsi), %zmm10
	vmovdqa64   %zmm10, 1664(%rdi)
	vmovdqa64	1728(%rsi), %zmm11
	vmovdqa64   %zmm11, 1728(%rdi)
	vmovdqa64	1792(%rsi), %zmm12
	vmovdqa64   %zmm12, 1792(%rdi)
	vmovdqa64	1856(%rsi), %zmm13
	vmovdqa64   %zmm13, 1856(%rdi)
	vmovdqa64	1920(%rsi), %zmm14
	vmovdqa64   %zmm14, 1920(%rdi)
	vmovdqa64	1984(%rsi), %zmm15
	vmovdqa64	%zmm15, 1984(%rdi)
	add		$2048, %rsi
	add		$2048, %rdi
	sub		$2048, %rdx
	jmp		.Laligned_512x32_loop
.Laligned_512x16:
	cmp			$1024,	%rdx
	jb			.Lcheck_size
	prefetch	1024(%rsi)
	prefetchw	1024(%rdi)
	vmovdqa64	(%rsi), %zmm0
	vmovdqa64   %zmm0, (%rdi)
	vmovdqa64	64(%rsi), %zmm1
	vmovdqa64   %zmm1, 64(%rdi)
	vmovdqa64	128(%rsi), %zmm2
	vmovdqa64   %zmm2, 128(%rdi)
	vmovdqa64	192(%rsi), %zmm3
	vmovdqa64   %zmm3, 192(%rdi)
	vmovdqa64	256(%rsi), %zmm4
	vmovdqa64   %zmm4, 256(%rdi)
	vmovdqa64	320(%rsi), %zmm5
	vmovdqa64   %zmm5, 320(%rdi)
	vmovdqa64	384(%rsi), %zmm6
	vmovdqa64   %zmm6, 384(%rdi)
	vmovdqa64	448(%rsi), %zmm7
	vmovdqa64   %zmm7, 448(%rdi)
	vmovdqa64	512(%rsi), %zmm8
	vmovdqa64   %zmm8, 512(%rdi)
	vmovdqa64	576(%rsi), %zmm9
	vmovdqa64   %zmm9, 576(%rdi)
	vmovdqa64	640(%rsi), %zmm10
	vmovdqa64   %zmm10, 640(%rdi)
	vmovdqa64	704(%rsi), %zmm11
	vmovdqa64   %zmm11, 704(%rdi)
	vmovdqa64	768(%rsi), %zmm12
	vmovdqa64   %zmm12, 768(%rdi)
	vmovdqa64	832(%rsi), %zmm13
	vmovdqa64   %zmm13, 832(%rdi)
	vmovdqa64	896(%rsi), %zmm14
	vmovdqa64   %zmm14, 896(%rdi)
	vmovdqa64	960(%rsi), %zmm15
	vmovdqa64	%zmm15, 960(%rdi)
	add		$1024, %rsi
	add		$1024, %rdi
	sub		$1024, %rdx
	jmp		.Laligned_512x16
.Laligned_512x8:
	cmp			$512,	%rdx
	jb			.Lcheck_size
	prefetchw	512(%rdi)
	prefetch	512(%rsi)
	vmovdqa64	(%rsi), %zmm0
	vmovdqa64	%zmm0, (%rdi)
	vmovdqa64	64(%rsi), %zmm1
	vmovdqa64	%zmm1, 64(%rdi)
	vmovdqa64	128(%rsi), %zmm2
	vmovdqa64	%zmm2, 128(%rdi)
	vmovdqa64	192(%rsi), %zmm3
	vmovdqa64	%zmm3, 192(%rdi)
	vmovdqa64	256(%rsi), %zmm4
	vmovdqa64	%zmm4, 256(%rdi)
	vmovdqa64	320(%rsi), %zmm5
	vmovdqa64	%zmm5, 320(%rdi)
	vmovdqa64	384(%rsi), %zmm6
	vmovdqa64	%zmm6, 384(%rdi)
	vmovdqa64	448(%rsi), %zmm7
	vmovdqa64	%zmm7, 448(%rdi)
	add			$512,	%rsi  
	add			$512,	%rdi  
	sub			$512,	%rdx
	jmp			.Laligned_512x8
.Laligned_512x2:
	cmp			$128,	%rdx
	jb			.Lcheck_size
	vmovdqa64	(%rsi), %zmm0
	vmovdqa64	%zmm0, (%rdi)
	vmovdqa64	64(%rsi), %zmm1
	vmovdqa64	%zmm1, 64(%rdi)
	add			$128,	%rsi  
	add			$128,	%rdi  
	sub			$128,	%rdx
	jmp			.Laligned_512x2	
.Laligned_512:
    cmp			$64, %rdx
    jb			.Ltail
	vmovdqa64	(%rsi), %zmm0
	vmovdqa64	%zmm0, (%rdi)
	add			$64,	%rsi  
	add			$64,	%rdi  
	sub			$64,	%rdx
	jmp     .Laligned_512 
.Ltail:
	test		%rdx, %rdx
	jz			.Lret
	
	cmp			$32, %rdx
	jb			.Ltail_16
	vmovdqu		(%rsi), %ymm0
	vmovdqu		-32(%rsi,%rdx), %ymm1
	vmovdqu		%ymm0, (%rdi)
	vmovdqu		%ymm1, -32(%rdi,%rdx)
	ret
.Ltail_16:
	cmp			$16, %rdx
	jb			.Ltail_8
	vmovdqu		(%rsi), %xmm0
	vmovdqu		-16(%rsi,%rdx), %xmm1
	vmovdqu		%xmm0, (%rdi)
	vmovdqu		%xmm1, -16(%rdi,%rdx)
	ret
.Ltail_8:
	cmp			$8, %rdx
	jb			.Ltail_bytes
	mov			(%rsi), %rax
	mov			-8(%rsi,%rdx), %rcx
	mov			%rax, (%rdi)
	mov			%rcx, -8(%rdi,%rdx)
	ret
.Ltail_bytes:
	movb		(%rsi), %al
	movb		%al, (%rdi)
	inc			%rsi
	inc			%rdi
	dec			%rdx
	jnz			.Ltail_bytes
.Lret:
	ret
.section .note.GNU-stack,"",@progbits
