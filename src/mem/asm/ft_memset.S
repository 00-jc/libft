# **************************************************************************** ;
#                                                                              ;
#                                                         :::      ::::::::    ;
#    ft_memset.s                                        :+:      :+:    :+:    ;
#                                                     +:+ +:+         +:+      ;
#    By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+         ;
#                                                 +#+#+#+#+#+   +#+            ;
#    Created: 2026/01/16 23:26:38 by jaicastr          #+#    #+#              ;
#    Updated: 2026/01/16 23:33:19 by jaicastr         ###   ########.fr        ;
#                                                                              ;
# **************************************************************************** ;

#if	defined(__AVX512VL__) && defined(__x86_64__) && !defined(__LIBFT_PORTABLE__)

.global ft_memset
.type ft_memset, @function
.text
ft_memset:
	endbr64
	xor		   	%rax, %rax
	movzx		%sil, %eax
	movabs		$0x0101010101010101, %r9
	imul		%r9, %rax
    mov     	%rdi, %r8
    neg     	%r8
    and     	$63, %r8
    jz      	.Lcheck_size_init  
    cmp     	%rdx, %r8
    cmova   	%rdx, %r8
	prefetchw	(%rdi)
.Lalign_loop:
	cmp		$8, %r8
	jb		.Lalign_bytes
	mov		%rax,(%rdi)
	add		$8, %rdi
	sub		$8, %rdx
	sub		$8, %r8
	jmp		.Lalign_loop
.Lalign_bytes:
    test    %r8, %r8
    jz      .Lcheck_size_init
    movb    %al, (%rdi)
    inc     %rdi
    dec     %rdx
    dec     %r8
    jmp     .Lalign_bytes
.Lcheck_size_init:
	vmovq			%rax, %xmm0
	vpbroadcastb	%xmm0,%zmm0
	cmp		$512,	%rdx
	jb		.Laligned_512
	vpbroadcastb	%xmm0,%zmm1
	vpbroadcastb	%xmm0,%zmm2
	cmp		$1024,	%rdx
	jb		.Laligned_512
	cmp		$4096,	%rdx
	jb		.Laligned_512x2
	vpbroadcastb	%xmm0,%zmm3
	vpbroadcastb	%xmm0,%zmm4
	vpbroadcastb	%xmm0,%zmm5
	vpbroadcastb	%xmm0,%zmm6
	vpbroadcastb	%xmm0,%zmm7
	cmp		$8192,	%rdx
	jb		.Laligned_512x8
	vpbroadcastb	%xmm0,%zmm8
	vpbroadcastb	%xmm0,%zmm9
	vpbroadcastb	%xmm0,%zmm10
	vpbroadcastb	%xmm0,%zmm11
	vpbroadcastb	%xmm0,%zmm12
	vpbroadcastb	%xmm0,%zmm13
	vpbroadcastb	%xmm0,%zmm14
	vpbroadcastb	%xmm0,%zmm15
	cmp		$16384,	%rdx
	jb		.Laligned_512x16
	cmp		$65536,	%rdx
	jb		.Laligned_512x32
	jmp		.Laligned_512x128plus
.Lcheck_size_no_init:
	cmp		$1024,	%rdx
	jb		.Laligned_512
	cmp		$4096,	%rdx
	jb		.Laligned_512x2
	cmp		$8192,	%rdx
	jb		.Laligned_512x8
	cmp		$16384,	%rdx
	jb		.Laligned_512x16
	cmp		$65536,	%rdx
	jb		.Laligned_512x32
	jmp		.Laligned_512x128plus
.Laligned_512x128plus:
	cmp			$4096,	%rdx
	jb			.Lnt_done
	prefetchw	4096(%rdi)
	vmovntdq	%zmm0, (%rdi)
	vmovntdq	%zmm1, 64(%rdi)
	vmovntdq	%zmm2, 128(%rdi)
	vmovntdq	%zmm3, 192(%rdi)
	vmovntdq	%zmm4, 256(%rdi)
	vmovntdq	%zmm5, 320(%rdi)
	vmovntdq	%zmm6, 384(%rdi)
	vmovntdq	%zmm7, 448(%rdi)
	vmovntdq	%zmm8, 512(%rdi)
	vmovntdq	%zmm9, 576(%rdi)
	vmovntdq	%zmm10, 640(%rdi)
	vmovntdq	%zmm11, 704(%rdi)
	vmovntdq	%zmm12, 768(%rdi)
	vmovntdq	%zmm13, 832(%rdi)
	vmovntdq	%zmm14, 896(%rdi)
	vmovntdq	%zmm15, 960(%rdi)
	vmovntdq	%zmm0, 1024(%rdi)
	vmovntdq	%zmm1, 1088(%rdi)
	vmovntdq	%zmm2, 1152(%rdi)
	vmovntdq	%zmm3, 1216(%rdi)
	vmovntdq	%zmm4, 1280(%rdi)
	vmovntdq	%zmm5, 1344(%rdi)
	vmovntdq	%zmm6, 1408(%rdi)
	vmovntdq	%zmm7, 1472(%rdi)
	vmovntdq	%zmm8, 1536(%rdi)
	vmovntdq	%zmm9, 1600(%rdi)
	vmovntdq	%zmm10, 1664(%rdi)
	vmovntdq	%zmm11, 1728(%rdi)
	vmovntdq	%zmm12, 1792(%rdi)
	vmovntdq	%zmm13, 1856(%rdi)
	vmovntdq	%zmm14, 1920(%rdi)
	vmovntdq	%zmm15, 1984(%rdi)
	vmovntdq	%zmm0, 2048(%rdi)
	vmovntdq	%zmm1, 2112(%rdi)
	vmovntdq	%zmm2, 2176(%rdi)
	vmovntdq	%zmm3, 2240(%rdi)
	vmovntdq	%zmm4, 2304(%rdi)
	vmovntdq	%zmm5, 2368(%rdi)
	vmovntdq	%zmm6, 2432(%rdi)
	vmovntdq	%zmm7, 2496(%rdi)
	vmovntdq	%zmm8, 2560(%rdi)
	vmovntdq	%zmm9, 2624(%rdi)
	vmovntdq	%zmm10, 2688(%rdi)
	vmovntdq	%zmm11, 2752(%rdi)
	vmovntdq	%zmm12, 2816(%rdi)
	vmovntdq	%zmm13, 2880(%rdi)
	vmovntdq	%zmm14, 2944(%rdi)
	vmovntdq	%zmm15, 3008(%rdi)
	vmovntdq	%zmm0, 3072(%rdi)
	vmovntdq	%zmm1, 3136(%rdi)
	vmovntdq	%zmm2, 3200(%rdi)
	vmovntdq	%zmm3, 3264(%rdi)
	vmovntdq	%zmm4, 3328(%rdi)
	vmovntdq	%zmm5, 3392(%rdi)
	vmovntdq	%zmm6, 3456(%rdi)
	vmovntdq	%zmm7, 3520(%rdi)
	vmovntdq	%zmm8, 3584(%rdi)
	vmovntdq	%zmm9, 3648(%rdi)
	vmovntdq	%zmm10, 3712(%rdi)
	vmovntdq	%zmm11, 3776(%rdi)
	vmovntdq	%zmm12, 3840(%rdi)
	vmovntdq	%zmm13, 3904(%rdi)
	vmovntdq	%zmm14, 3968(%rdi)
	vmovntdq	%zmm15, 4032(%rdi)
	add		$4096, %rdi
	sub		$4096, %rdx
	jmp		.Laligned_512x128plus
.Lnt_done:
	sfence
	jmp		.Lcheck_size_no_init
.Laligned_512x32:
	cmp			$2048,	%rdx
	jb			.Lcheck_size_no_init
	prefetchw	2048(%rdi)
	vmovdqa64   %zmm0, (%rdi)
	vmovdqa64   %zmm1, 64(%rdi)
	vmovdqa64   %zmm2, 128(%rdi)
	vmovdqa64   %zmm3, 192(%rdi)
	vmovdqa64   %zmm4, 256(%rdi)
	vmovdqa64   %zmm5, 320(%rdi)
	vmovdqa64   %zmm6, 384(%rdi)
	vmovdqa64   %zmm7, 448(%rdi)
	vmovdqa64   %zmm8, 512(%rdi)
	vmovdqa64   %zmm9, 576(%rdi)
	vmovdqa64   %zmm10, 640(%rdi)
	vmovdqa64   %zmm11, 704(%rdi)
	vmovdqa64   %zmm12, 768(%rdi)
	vmovdqa64   %zmm13, 832(%rdi)
	vmovdqa64   %zmm14, 896(%rdi)
	vmovdqa64   %zmm15, 960(%rdi)
	vmovdqa64   %zmm0, 1024(%rdi)
	vmovdqa64   %zmm1, 1088(%rdi)
	vmovdqa64   %zmm2, 1152(%rdi)
	vmovdqa64   %zmm3, 1216(%rdi)
	vmovdqa64   %zmm4, 1280(%rdi)
	vmovdqa64   %zmm5, 1344(%rdi)
	vmovdqa64   %zmm6, 1408(%rdi)
	vmovdqa64   %zmm7, 1472(%rdi)
	vmovdqa64   %zmm8, 1536(%rdi)
	vmovdqa64   %zmm9, 1600(%rdi)
	vmovdqa64   %zmm10, 1664(%rdi)
	vmovdqa64   %zmm11, 1728(%rdi)
	vmovdqa64   %zmm12, 1792(%rdi)
	vmovdqa64   %zmm13, 1856(%rdi)
	vmovdqa64   %zmm14, 1920(%rdi)
	vmovdqa64	%zmm15, 1984(%rdi)
	add		$2048, %rdi
	sub		$2048, %rdx
	jmp		.Laligned_512x32
.Laligned_512x16:
	cmp			$1024,	%rdx
	jb			.Lcheck_size_no_init
	prefetchw	1024(%rdi)
	vmovdqa64   %zmm0, (%rdi)
	vmovdqa64   %zmm1, 64(%rdi)
	vmovdqa64   %zmm2, 128(%rdi)
	vmovdqa64   %zmm3, 192(%rdi)
	vmovdqa64   %zmm4, 256(%rdi)
	vmovdqa64   %zmm5, 320(%rdi)
	vmovdqa64   %zmm6, 384(%rdi)
	vmovdqa64   %zmm7, 448(%rdi)
	vmovdqa64   %zmm8, 512(%rdi)
	vmovdqa64   %zmm9, 576(%rdi)
	vmovdqa64   %zmm10, 640(%rdi)
	vmovdqa64   %zmm11, 704(%rdi)
	vmovdqa64   %zmm12, 768(%rdi)
	vmovdqa64   %zmm13, 832(%rdi)
	vmovdqa64   %zmm14, 896(%rdi)
	vmovdqa64   %zmm15, 960(%rdi)
	add		$1024, %rdi
	sub		$1024, %rdx
	jmp		.Laligned_512x16
.Laligned_512x8:
	cmp			$512,	%rdx
	jb			.Lcheck_size_no_init
	prefetchw	512(%rdi)
	vmovdqa64   %zmm0, (%rdi)
	vmovdqa64   %zmm1, 64(%rdi)
	vmovdqa64   %zmm2, 128(%rdi)
	vmovdqa64   %zmm3, 192(%rdi)
	vmovdqa64   %zmm4, 256(%rdi)
	vmovdqa64   %zmm5, 320(%rdi)
	vmovdqa64   %zmm6, 384(%rdi)
	vmovdqa64   %zmm7, 448(%rdi)
	add			$512,	%rdi  
	sub			$512,	%rdx
	jmp			.Laligned_512x8
.Laligned_512x2:
	cmp			$128,	%rdx
	jb			.Lcheck_size_no_init
	vmovdqa64   %zmm0, (%rdi)
	vmovdqa64   %zmm1, 64(%rdi)
	add			$128,	%rdi  
	sub			$128,	%rdx
	jmp			.Laligned_512x2	
.Laligned_512:
    cmp				$64, %rdx
    jb				.Ltail
	vmovdqa64   	%zmm0, (%rdi)
	add				$64,	%rdi  
	sub				$64,	%rdx
	jmp		     	.Laligned_512
.Ltail:
    test			%rdx, %rdx
    jz				.Lret
    vmovq			%rax, %xmm0
    vpbroadcastq	%xmm0, %ymm0
    cmp				$32, %rdx
    jb				.Ltail_16
    vmovdqu			%ymm0, (%rdi)
    vmovdqu			%ymm0, -32(%rdi,%rdx)
    ret
.Ltail_16:
    cmp			$16, %rdx
    jb			.Ltail_8
    vmovdqu		%xmm0, (%rdi)
    vmovdqu		%xmm0, -16(%rdi,%rdx)
    ret
.Ltail_8:
    cmp			$8, %rdx
    jb			.Ltail_4
    mov			%rax, (%rdi)
    mov			%rax, -8(%rdi,%rdx)
    ret
.Ltail_4:
    cmp			$4, %rdx
    jb          .Ltail_2
    mov			%eax, (%rdi)
    mov			%eax, -4(%rdi,%rdx)
    ret
.Ltail_2:
    cmp			$2, %rdx
    jb			.Ltail_1
    mov			%ax, (%rdi)
    mov			%ax, -2(%rdi,%rdx)
    ret
.Ltail_1:
    mov			%al, (%rdi)
.Lret:
    ret
.section .note.GNU-stack,"",@progbits
#endif
