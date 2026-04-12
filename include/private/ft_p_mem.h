/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_mem.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 18:23:58 by jaicastr          #+#    #+#             */
/*   Updated: 2026/03/03 22:41:28 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_P_MEM_H
# define FT_P_MEM_H

# include "mem.h"
# include "private/ft_p_bmi.h"

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

void			*ft_memchr_minimal(const void *ptr,
					t_u8 c, size_t n)\
					__attribute__((__nonnull__(1)));

void			*ft_memchr_sse(const void *ptr,
					int c, size_t n)\
					__attribute__((__nonnull__(1)));

void			*ft_memchr_avx256(const void *ptr,
					int c, size_t n)\
					__attribute__((__nonnull__(1)));

void			*ft_memchr_avx512(const void *ptr,
					int c, size_t n)\
					__attribute__((__nonnull__(1)));

ssize_t			ft_memcmp_minimal(const void *restrict const ptr1,
					const void	*restrict const ptr2, size_t offst,\
					size_t n)\
					__attribute__((__nonnull__(1, 2)));

ssize_t			ft_memcmp_sse(const void *restrict const ptr1,
					const void	*restrict const ptr2, size_t n)\
					__attribute__((__nonnull__(1, 2)));

ssize_t			ft_memcmp_avx256(const void *restrict const ptr1,
					const void	*restrict const ptr2, size_t n)\
					__attribute__((__nonnull__(1, 2)));

ssize_t			ft_memcmp_avx512(const void *restrict const ptr1,
					const void	*restrict const ptr2, size_t n)\
					__attribute__((__nonnull__(1, 2)));

#endif
