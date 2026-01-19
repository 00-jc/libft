/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lft_private.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 04:30:00 by jaicastr          #+#    #+#             */
/*   Updated: 2026/01/19 20:38:21 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LFT_PRIVATE_H
# define LFT_PRIVATE_H

# include "structs.h"
# include <sys/types.h>

typedef t_u8 * restrict const										t_blk8w;
typedef const t_u8 * restrict const									t_blk8r;

typedef t_u64 * restrict const __attribute__((aligned(1)))			t_blk64w;
typedef const t_u64 * restrict const __attribute__((aligned(1)))	t_blk64r;

typedef t_u64a * restrict const										t_blk64wa;
typedef const t_u64a * restrict const								t_blk64ra;

void			ft_memcpy_tail(void *__restrict__ dest,
					const void	*__restrict__ const src,
					size_t offst, size_t n)\
					__attribute__((__nonnull__(1, 2)));
void			ft_memcpy_naive(void *__restrict__ dest,
					const void	*__restrict__ const src,
					size_t n)\
					__attribute__((__nonnull__(1, 2)));
void			ft_memcpy_8x64(void *__restrict__ dest,
					const void	*__restrict__ const src,
					size_t n)\
					__attribute__((__nonnull__(1, 2)));

void			ft_memset_tail(void *__restrict__ dest,
					size_t offst, const t_u8 b, size_t n)\
					__attribute__((__nonnull__(1)));
void			ft_memset_naive(void *__restrict__ dest,
					const t_u8 b, size_t n)\
					__attribute__((__nonnull__(1)));
void			ft_memset_8x64(void *__restrict__ dest,
					const t_u8 b, size_t n)\
					__attribute__((__nonnull__(1)));

t_u64a			rotl(t_u64a x, size_t r)\
					__attribute__((const, __always_inline__));

t_u64a			fmix64(t_u64a k)\
					__attribute__((const, __always_inline__));

# ifndef __LIBFT_SCALAR__

void			ft_memcpy_8x128(void *__restrict__ dest,
					const void	*__restrict__ const src,
					size_t n)\
					__attribute__((__nonnull__(1, 2)));
void			ft_memcpy_8x256(void *__restrict__ dest,
					const void	*__restrict__ const src,
					size_t n)\
					__attribute__((__nonnull__(1, 2)));
void			ft_memcpy_8x512(void *__restrict__ dest,
					const void	*__restrict__ const src,
					size_t n)\
					__attribute__((__nonnull__(1, 2)));

void			ft_memset_8x128(void *__restrict__ dest,
					const t_u8 b, size_t n)\
					__attribute__((__nonnull__(1)));
void			ft_memset_8x256(void *__restrict__ dest,
					const t_u8 b, size_t n)\
					__attribute__((__nonnull__(1)));
void			ft_memset_8x512(void *__restrict__ dest,
					const t_u8 b, size_t n)\
					__attribute__((__nonnull__(1)));

typedef __attribute__((vector_size(16), aligned(1))) t_u8			t_vu128;
typedef t_vu128 * restrict const __attribute__((aligned(1)))		t_blk128w;
typedef const t_vu128 * restrict const __attribute__((aligned(1)))	t_blk128r;

typedef __attribute__((vector_size(32), aligned(1))) t_u8			t_vu256;
typedef t_vu256 * restrict const __attribute__((aligned(1)))		t_blk256w;
typedef const t_vu256 * restrict const __attribute__((aligned(1)))	t_blk256r;

typedef __attribute__((vector_size(64), aligned(1))) t_u8			t_vu512;
typedef t_vu512 * restrict const __attribute__((aligned(1)))		t_blk512w;
typedef const t_vu512 * restrict const __attribute__((aligned(1)))	t_blk512r;

typedef __attribute__((vector_size(16))) t_u8						t_vu128a;
typedef t_vu128 * restrict const									t_blk128wa;
typedef const t_vu128 * restrict const								t_blk128ra;

typedef __attribute__((vector_size(32))) t_u8						t_vu256a;
typedef t_vu256 * restrict const									t_blk256wa;
typedef const t_vu256 * restrict const								t_blk256ra;

typedef __attribute__((vector_size(64))) t_u8						t_vu512a;
typedef t_vu512 * restrict const									t_blk512wa;
typedef const t_vu512 * restrict const								t_blk512ra;

t_vu512			get_high512(void);
t_vu512			get_lones512(void);
t_vu512			get_z512(void);
t_vu512			get_mask512(t_u8 x);

t_vu256			get_high256(void);
t_vu256			get_lones256(void);
t_vu256			get_z256(void);
t_vu256			get_mask256(t_u8 x);

t_vu128			get_high128(void);
t_vu128			get_lones128(void);
t_vu128			get_z128(void);
t_vu128			get_mask128(t_u8 x);

# endif

#endif
