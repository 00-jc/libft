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

#if	defined(__AVX512F__) && !defined(__LIBFT_SCALAR__)

.global ft_cpy
.type ft_cpy, @function
.text
ft_cpy:
    mov     %rdi, %r8
    neg     %r8
    and     $63, %r8
    jz      .Lcheck_size  
    cmp     %rdx, %r8
    cmova   %rdx, %r8
	prefetcht1	(%rsi)
	prefetchw	(%rdi)
.Lalign_loop:
	cmp		$8, %r8
	jb		.Lalign_bytes
	mov		(%rsi), %rax
	mov		%rax, (%rdi)
	add		$8, %rsi
	add		$8, %rdi
	sub		$8, %rdx
	sub		$8, %r8
	jmp		.Lalign_loop
.Lalign_bytes:
    test    %r8, %r8
    jz      .Lcheck_size
    movb    (%rsi), %al
    movb    %al, (%rdi)
    inc     %rsi
    inc     %rdi
    dec     %rdx
    dec     %r8
    jmp     .Lalign_bytes
.Lcheck_size:
	cmp		$65536,	%rdx
	jae		.Laligned_512x128plus
	cmp		$16384,	%rdx
	jae		.Laligned_512x32
	cmp		$8192,	%rdx
	jae		.Laligned_512x16
	cmp		$4096,	%rdx
	jae		.Laligned_512x8
	cmp		$1024,	%rdx
	jae		.Laligned_512x2
	cmp		$512,	%rdx
	jae		.Laligned_512
	jmp		.Ltail
.Laligned_512x128plus:
	cmp			$4096,	%rdx
	jb			.Lnt_done
	prefetch	4096(%rsi)
	prefetchw	4096(%rdi)
	vmovdqu64	(%rsi), %zmm0
	vmovntdq	%zmm0, (%rdi)
	vmovdqu64	64(%rsi), %zmm1
	vmovntdq	%zmm1, 64(%rdi)
	vmovdqu64	128(%rsi), %zmm2
	vmovntdq	%zmm2, 128(%rdi)
	vmovdqu64	192(%rsi), %zmm3
	vmovntdq	%zmm3, 192(%rdi)
	vmovdqu64	256(%rsi), %zmm4
	vmovntdq	%zmm4, 256(%rdi)
	vmovdqu64	320(%rsi), %zmm5
	vmovntdq	%zmm5, 320(%rdi)
	vmovdqu64	384(%rsi), %zmm6
	vmovntdq	%zmm6, 384(%rdi)
	vmovdqu64	448(%rsi), %zmm7
	vmovntdq	%zmm7, 448(%rdi)
	vmovdqu64	512(%rsi), %zmm8
	vmovntdq	%zmm8, 512(%rdi)
	vmovdqu64	576(%rsi), %zmm9
	vmovntdq	%zmm9, 576(%rdi)
	vmovdqu64	640(%rsi), %zmm10
	vmovntdq	%zmm10, 640(%rdi)
	vmovdqu64	704(%rsi), %zmm11
	vmovntdq	%zmm11, 704(%rdi)
	vmovdqu64	768(%rsi), %zmm12
	vmovntdq	%zmm12, 768(%rdi)
	vmovdqu64	832(%rsi), %zmm13
	vmovntdq	%zmm13, 832(%rdi)
	vmovdqu64	896(%rsi), %zmm14
	vmovntdq	%zmm14, 896(%rdi)
	vmovdqu64	960(%rsi), %zmm15
	vmovntdq	%zmm15, 960(%rdi)
	vmovdqu64	1024(%rsi), %zmm0
	vmovntdq	%zmm0, 1024(%rdi)
	vmovdqu64	1088(%rsi), %zmm1
	vmovntdq	%zmm1, 1088(%rdi)
	vmovdqu64	1152(%rsi), %zmm2
	vmovntdq	%zmm2, 1152(%rdi)
	vmovdqu64	1216(%rsi), %zmm3
	vmovntdq	%zmm3, 1216(%rdi)
	vmovdqu64	1280(%rsi), %zmm4
	vmovntdq	%zmm4, 1280(%rdi)
	vmovdqu64	1344(%rsi), %zmm5
	vmovntdq	%zmm5, 1344(%rdi)
	vmovdqu64	1408(%rsi), %zmm6
	vmovntdq	%zmm6, 1408(%rdi)
	vmovdqu64	1472(%rsi), %zmm7
	vmovntdq	%zmm7, 1472(%rdi)
	vmovdqu64	1536(%rsi), %zmm8
	vmovntdq	%zmm8, 1536(%rdi)
	vmovdqu64	1600(%rsi), %zmm9
	vmovntdq	%zmm9, 1600(%rdi)
	vmovdqu64	1664(%rsi), %zmm10
	vmovntdq	%zmm10, 1664(%rdi)
	vmovdqu64	1728(%rsi), %zmm11
	vmovntdq	%zmm11, 1728(%rdi)
	vmovdqu64	1792(%rsi), %zmm12
	vmovntdq	%zmm12, 1792(%rdi)
	vmovdqu64	1856(%rsi), %zmm13
	vmovntdq	%zmm13, 1856(%rdi)
	vmovdqu64	1920(%rsi), %zmm14
	vmovntdq	%zmm14, 1920(%rdi)
	vmovdqu64	1984(%rsi), %zmm15
	vmovntdq	%zmm15, 1984(%rdi)
	vmovdqu64	2048(%rsi), %zmm0
	vmovntdq	%zmm0, 2048(%rdi)
	vmovdqu64	2112(%rsi), %zmm1
	vmovntdq	%zmm1, 2112(%rdi)
	vmovdqu64	2176(%rsi), %zmm2
	vmovntdq	%zmm2, 2176(%rdi)
	vmovdqu64	2240(%rsi), %zmm3
	vmovntdq	%zmm3, 2240(%rdi)
	vmovdqu64	2304(%rsi), %zmm4
	vmovntdq	%zmm4, 2304(%rdi)
	vmovdqu64	2368(%rsi), %zmm5
	vmovntdq	%zmm5, 2368(%rdi)
	vmovdqu64	2432(%rsi), %zmm6
	vmovntdq	%zmm6, 2432(%rdi)
	vmovdqu64	2496(%rsi), %zmm7
	vmovntdq	%zmm7, 2496(%rdi)
	vmovdqu64	2560(%rsi), %zmm8
	vmovntdq	%zmm8, 2560(%rdi)
	vmovdqu64	2624(%rsi), %zmm9
	vmovntdq	%zmm9, 2624(%rdi)
	vmovdqu64	2688(%rsi), %zmm10
	vmovntdq	%zmm10, 2688(%rdi)
	vmovdqu64	2752(%rsi), %zmm11
	vmovntdq	%zmm11, 2752(%rdi)
	vmovdqu64	2816(%rsi), %zmm12
	vmovntdq	%zmm12, 2816(%rdi)
	vmovdqu64	2880(%rsi), %zmm13
	vmovntdq	%zmm13, 2880(%rdi)
	vmovdqu64	2944(%rsi), %zmm14
	vmovntdq	%zmm14, 2944(%rdi)
	vmovdqu64	3008(%rsi), %zmm15
	vmovntdq	%zmm15, 3008(%rdi)
	vmovdqu64	3072(%rsi), %zmm0
	vmovntdq	%zmm0, 3072(%rdi)
	vmovdqu64	3136(%rsi), %zmm1
	vmovntdq	%zmm1, 3136(%rdi)
	vmovdqu64	3200(%rsi), %zmm2
	vmovntdq	%zmm2, 3200(%rdi)
	vmovdqu64	3264(%rsi), %zmm3
	vmovntdq	%zmm3, 3264(%rdi)
	vmovdqu64	3328(%rsi), %zmm4
	vmovntdq	%zmm4, 3328(%rdi)
	vmovdqu64	3392(%rsi), %zmm5
	vmovntdq	%zmm5, 3392(%rdi)
	vmovdqu64	3456(%rsi), %zmm6
	vmovntdq	%zmm6, 3456(%rdi)
	vmovdqu64	3520(%rsi), %zmm7
	vmovntdq	%zmm7, 3520(%rdi)
	vmovdqu64	3584(%rsi), %zmm8
	vmovntdq	%zmm8, 3584(%rdi)
	vmovdqu64	3648(%rsi), %zmm9
	vmovntdq	%zmm9, 3648(%rdi)
	vmovdqu64	3712(%rsi), %zmm10
	vmovntdq	%zmm10, 3712(%rdi)
	vmovdqu64	3776(%rsi), %zmm11
	vmovntdq	%zmm11, 3776(%rdi)
	vmovdqu64	3840(%rsi), %zmm12
	vmovntdq	%zmm12, 3840(%rdi)
	vmovdqu64	3904(%rsi), %zmm13
	vmovntdq	%zmm13, 3904(%rdi)
	vmovdqu64	3968(%rsi), %zmm14
	vmovntdq	%zmm14, 3968(%rdi)
	vmovdqu64	4032(%rsi), %zmm15
	vmovntdq	%zmm15, 4032(%rdi)
	add		$4096, %rsi
	add		$4096, %rdi
	sub		$4096, %rdx
	jmp		.Laligned_512x128plus
.Lnt_done:
	sfence
	jmp		.Lcheck_size
.Laligned_512x32:
	cmp			$2048,	%rdx
	jb			.Lcheck_size
	prefetcht1	2048(%rsi)
	prefetchw	2048(%rdi)
	vmovdqu64	(%rsi), %zmm0
	vmovdqa64   %zmm0, (%rdi)
	vmovdqu64	64(%rsi), %zmm1
	vmovdqa64   %zmm1, 64(%rdi)
	vmovdqu64	128(%rsi), %zmm2
	vmovdqa64   %zmm2, 128(%rdi)
	vmovdqu64	192(%rsi), %zmm3
	vmovdqa64   %zmm3, 192(%rdi)
	vmovdqu64	256(%rsi), %zmm4
	vmovdqa64   %zmm4, 256(%rdi)
	vmovdqu64	320(%rsi), %zmm5
	vmovdqa64   %zmm5, 320(%rdi)
	vmovdqu64	384(%rsi), %zmm6
	vmovdqa64   %zmm6, 384(%rdi)
	vmovdqu64	448(%rsi), %zmm7
	vmovdqa64   %zmm7, 448(%rdi)
	vmovdqu64	512(%rsi), %zmm8
	vmovdqa64   %zmm8, 512(%rdi)
	vmovdqu64	576(%rsi), %zmm9
	vmovdqa64   %zmm9, 576(%rdi)
	vmovdqu64	640(%rsi), %zmm10
	vmovdqa64   %zmm10, 640(%rdi)
	vmovdqu64	704(%rsi), %zmm11
	vmovdqa64   %zmm11, 704(%rdi)
	vmovdqu64	768(%rsi), %zmm12
	vmovdqa64   %zmm12, 768(%rdi)
	vmovdqu64	832(%rsi), %zmm13
	vmovdqa64   %zmm13, 832(%rdi)
	vmovdqu64	896(%rsi), %zmm14
	vmovdqa64   %zmm14, 896(%rdi)
	vmovdqu64	960(%rsi), %zmm15
	vmovdqa64   %zmm15, 960(%rdi)
	vmovdqu64	1024(%rsi), %zmm0
	vmovdqa64   %zmm0, 1024(%rdi)
	vmovdqu64	1088(%rsi), %zmm1
	vmovdqa64   %zmm1, 1088(%rdi)
	vmovdqu64	1152(%rsi), %zmm2
	vmovdqa64   %zmm2, 1152(%rdi)
	vmovdqu64	1216(%rsi), %zmm3
	vmovdqa64   %zmm3, 1216(%rdi)
	vmovdqu64	1280(%rsi), %zmm4
	vmovdqa64   %zmm4, 1280(%rdi)
	vmovdqu64	1344(%rsi), %zmm5
	vmovdqa64   %zmm5, 1344(%rdi)
	vmovdqu64	1408(%rsi), %zmm6
	vmovdqa64   %zmm6, 1408(%rdi)
	vmovdqu64	1472(%rsi), %zmm7
	vmovdqa64   %zmm7, 1472(%rdi)
	vmovdqu64	1536(%rsi), %zmm8
	vmovdqa64   %zmm8, 1536(%rdi)
	vmovdqu64	1600(%rsi), %zmm9
	vmovdqa64   %zmm9, 1600(%rdi)
	vmovdqu64	1664(%rsi), %zmm10
	vmovdqa64   %zmm10, 1664(%rdi)
	vmovdqu64	1728(%rsi), %zmm11
	vmovdqa64   %zmm11, 1728(%rdi)
	vmovdqu64	1792(%rsi), %zmm12
	vmovdqa64   %zmm12, 1792(%rdi)
	vmovdqu64	1856(%rsi), %zmm13
	vmovdqa64   %zmm13, 1856(%rdi)
	vmovdqu64	1920(%rsi), %zmm14
	vmovdqa64   %zmm14, 1920(%rdi)
	vmovdqu64	1984(%rsi), %zmm15
	vmovdqa64	%zmm15, 1984(%rdi)
	add		$2048, %rsi
	add		$2048, %rdi
	sub		$2048, %rdx
	jmp		.Laligned_512x32
.Laligned_512x16:
	cmp			$1024,	%rdx
	jb			.Lcheck_size
	prefetcht1	1024(%rsi)
	prefetchw	1024(%rdi)
	vmovdqu64	(%rsi), %zmm0
	vmovdqa64   %zmm0, (%rdi)
	vmovdqu64	64(%rsi), %zmm1
	vmovdqa64   %zmm1, 64(%rdi)
	vmovdqu64	128(%rsi), %zmm2
	vmovdqa64   %zmm2, 128(%rdi)
	vmovdqu64	192(%rsi), %zmm3
	vmovdqa64   %zmm3, 192(%rdi)
	vmovdqu64	256(%rsi), %zmm4
	vmovdqa64   %zmm4, 256(%rdi)
	vmovdqu64	320(%rsi), %zmm5
	vmovdqa64   %zmm5, 320(%rdi)
	vmovdqu64	384(%rsi), %zmm6
	vmovdqa64   %zmm6, 384(%rdi)
	vmovdqu64	448(%rsi), %zmm7
	vmovdqa64   %zmm7, 448(%rdi)
	vmovdqu64	512(%rsi), %zmm8
	vmovdqa64   %zmm8, 512(%rdi)
	vmovdqu64	576(%rsi), %zmm9
	vmovdqa64   %zmm9, 576(%rdi)
	vmovdqu64	640(%rsi), %zmm10
	vmovdqa64   %zmm10, 640(%rdi)
	vmovdqu64	704(%rsi), %zmm11
	vmovdqa64   %zmm11, 704(%rdi)
	vmovdqu64	768(%rsi), %zmm12
	vmovdqa64   %zmm12, 768(%rdi)
	vmovdqu64	832(%rsi), %zmm13
	vmovdqa64   %zmm13, 832(%rdi)
	vmovdqu64	896(%rsi), %zmm14
	vmovdqa64   %zmm14, 896(%rdi)
	vmovdqu64	960(%rsi), %zmm15
	vmovdqa64   %zmm15, 960(%rdi)
	add		$1024, %rsi
	add		$1024, %rdi
	sub		$1024, %rdx
	jmp		.Laligned_512x16
.Laligned_512x8:
	cmp			$512,	%rdx
	jb			.Lcheck_size
	prefetchw	512(%rdi)
	prefetcht0	512(%rsi)
	vmovdqu64	(%rsi), %zmm0
	vmovdqa64   %zmm0, (%rdi)
	vmovdqu64	64(%rsi), %zmm1
	vmovdqa64   %zmm1, 64(%rdi)
	vmovdqu64	128(%rsi), %zmm2
	vmovdqa64   %zmm2, 128(%rdi)
	vmovdqu64	192(%rsi), %zmm3
	vmovdqa64   %zmm3, 192(%rdi)
	vmovdqu64	256(%rsi), %zmm4
	vmovdqa64   %zmm4, 256(%rdi)
	vmovdqu64	320(%rsi), %zmm5
	vmovdqa64   %zmm5, 320(%rdi)
	vmovdqu64	384(%rsi), %zmm6
	vmovdqa64   %zmm6, 384(%rdi)
	vmovdqu64	448(%rsi), %zmm7
	vmovdqa64   %zmm7, 448(%rdi)
	add			$512,	%rsi  
	add			$512,	%rdi  
	sub			$512,	%rdx
	jmp			.Laligned_512x8
.Laligned_512x2:
	cmp			$128,	%rdx
	jb			.Lcheck_size
	vmovdqu64	(%rsi), %zmm0
	vmovdqa64   %zmm0, (%rdi)
	vmovdqu64	64(%rsi), %zmm1
	vmovdqa64   %zmm1, 64(%rdi)
	add			$128,	%rsi  
	add			$128,	%rdi  
	sub			$128,	%rdx
	jmp			.Laligned_512x2	
.Laligned_512:
    cmp			$64, %rdx
    jb			.Ltail
	vmovdqu64	(%rsi), %zmm0
	vmovdqa64   %zmm0, (%rdi)
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
	jb			.Ltail_4
	mov			(%rsi), %rax
	mov			-8(%rsi,%rdx), %rcx
	mov			%rax, (%rdi)
	mov			%rcx, -8(%rdi,%rdx)
	ret
.Ltail_4:
	cmp			$4, %rdx
	jb			.Ltail_2
	mov			(%rsi), %eax
	mov			-4(%rsi,%rdx), %ecx
	mov			%eax, (%rdi)
	mov			%ecx, -4(%rdi,%rdx)
	ret
.Ltail_2:
	cmp			$2, %rdx
	jb			.Ltail_1
	movzwl		(%rsi), %eax
	movzwl		-2(%rsi,%rdx), %ecx
	mov			%ax, (%rdi)
	mov			%cx, -2(%rdi,%rdx)
	ret
.Ltail_1:
	test		%rdx, %rdx
	jz			.Lret
	movb		(%rsi), %al
	movb		%al, (%rdi)
.Lret:
	ret
.section .note.GNU-stack,"",@progbits

#endif
