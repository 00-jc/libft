/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:14:01 by jaicastr          #+#    #+#             */
/*   Updated: 2026/01/19 03:56:04 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEM_H
# define MEM_H

# include <sys/types.h>
# include <stdlib.h>
# include <limits.h>
# include "alloc.h"
# include "structs.h"
# include "macros.h"

# define LONES_64 0x0101010101010101ULL
# define HIGHS_64 0x8080808080808080ULL

void			ft_bzero(void *__restrict__ ptr, size_t n)\
					__attribute__((__nonnull__(1)));

void			ft_memset(void *__restrict__ s, const t_u8 c, size_t n)\
					__attribute__((__nonnull__(1)));

void			ft_memcpy(void *__restrict__ dest,
					const void *__restrict__ src, size_t n)\
					__attribute__((__nonnull__(1, 2)));

void			ft_set(void *__restrict__ s, const t_u8 c, size_t n)\
					__attribute__((__nonnull__(1)));

void			ft_memtake(void *__restrict__ dest,
					void *__restrict__ src, size_t n)\
					__attribute__((__nonnull__(1, 2)));

t_u8			ft_memswap(void *__restrict__ p1,
					void *__restrict__ p2, size_t n)\
					__attribute__((__nonnull__(1, 2)));

t_u8			ft_memswap_extern(void *__restrict__ p1,
					void *__restrict__ p2, size_t n,
					void *__restrict__ buf)\
					__attribute__((__nonnull__(1, 2, 4)));

void			*ft_memmove(void *__restrict__ dest,
					const void *__restrict__ src, size_t n)\
					__attribute__((__nonnull__(1, 2)));

void			*ft_memchr(const void *__restrict__ ptr, int c, size_t n)\
					__attribute__((__nonnull__(1)));

ssize_t			ft_memcmp(const void *__restrict__ const dest,
					const void *__restrict__ src, size_t n)\
					__attribute__((__nonnull__(1, 2)));

void			*ft_memclone(void *__restrict__ ptr, size_t size)\
					__attribute__((__nonnull__(1)));

void			*ft_memformat(void *restrict const ptr, size_t size)\
					__attribute__((__nonnull__(1)));

void			ft_membroadcast(void *dst, void *src, size_t chunks, size_t n)\
					__attribute__((__nonnull__(1, 2)));

t_u128			__hasz128(t_u128 x);
t_u64			__hasz64(t_u64 x);
t_u64			__populate(t_u8 y);

size_t			ft_memctz_u32(t_u32 x);
size_t			ft_memctz_u64(t_u64 x);
size_t			ft_memctz_u128(t_u128 x);

size_t			__max_s(size_t x, size_t y);
t_u8			__maxu8(t_u8 x, t_u8 y);
t_u32			__maxu32(t_u32 x, t_u32 y);
t_u64			__maxu64(t_u64 x, t_u64 y);
t_u128			__maxu128(t_u128 x, t_u128 y);

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

typedef t_u8 * restrict const										t_blk8w;
typedef const t_u8 * restrict const									t_blk8r;

typedef t_u64 * restrict const __attribute__((aligned(1)))			t_blk64w;
typedef const t_u64 * restrict const __attribute__((aligned(1)))	t_blk64r;

typedef t_u64a * restrict const										t_blk64wa;
typedef const t_u64a * restrict const								t_blk64ra;

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
