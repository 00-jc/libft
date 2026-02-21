/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_mem.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 18:23:58 by jaicastr          #+#    #+#             */
/*   Updated: 2026/02/21 04:48:19 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_P_MEM_H
# define FT_P_MEM_H

# include "mem.h"
# include "private/ft_p_bmi.h"

# define XXH_PRIME64_1  0x9E3779B185EBCA87ULL
# define XXH_PRIME64_2  0xC2B2AE3D27D4EB4FULL
# define XXH_PRIME64_3  0x165667B19E3779F9ULL
# define XXH_PRIME64_4  0x85EBCA77C2B2AE63ULL
# define XXH_PRIME64_5  0x27D4EB2F165667C5ULL  

void			ft_memcpy_tail(void *restrict dest,
					const void	*restrict const src,
					size_t offst, size_t n)\
					__attribute__((__nonnull__(1, 2)));

void			ft_memcpy_naive(void *restrict dest,
					const void	*restrict const src,
					size_t n)\
					__attribute__((__nonnull__(1, 2)));

void			ft_memcpy_8x64(void *restrict dest,
					const void	*restrict const src,
					size_t n)\
					__attribute__((__nonnull__(1, 2)));

void			ft_memset_tail(void *restrict dest,
					size_t offst, const t_u8 b, size_t n)\
					__attribute__((__nonnull__(1)));
void			ft_memset_naive(void *restrict dest,
					const t_u8 b, size_t n)\
					__attribute__((__nonnull__(1)));
void			ft_memset_8x64(void *restrict dest,
					const t_u8 b, size_t n)\
					__attribute__((__nonnull__(1)));

void			ft_memcpy_8x128(void *restrict dest,
					const void	*restrict const src,
					size_t n)\
					__attribute__((__nonnull__(1, 2)));
void			ft_memcpy_8x256(void *restrict dest,
					const void	*restrict const src,
					size_t n)\
					__attribute__((__nonnull__(1, 2)));
void			ft_memcpy_8x512(void *restrict dest,
					const void	*restrict const src,
					size_t n)\
					__attribute__((__nonnull__(1, 2)));

void			ft_memset_8x128(void *restrict dest,
					const t_u8 b, size_t n)\
					__attribute__((__nonnull__(1)));

void			ft_memset_8x256(void *restrict dest,
					const t_u8 b, size_t n)\
					__attribute__((__nonnull__(1)));

void			ft_memset_8x512(void *restrict dest,
					const t_u8 b, size_t n)\
					__attribute__((__nonnull__(1)));

t_u64a			rotl(t_u64a x, size_t r)\
					__attribute__((const, __always_inline__));

t_u64a			fmix64(t_u64a k)\
					__attribute__((const, __always_inline__));

#endif
