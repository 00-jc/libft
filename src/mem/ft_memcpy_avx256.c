/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_avx256.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:13:42 by jaicastr          #+#    #+#             */
/*   Updated: 2026/01/19 21:19:05 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"
#include "lft_private.h"

#if !defined(__LIBFT_SCALAR__) && !defined(__AVX512F__)

__attribute__((__nonnull__(1, 2), __always_inline__))
inline void	ft_memcpy_8x512(void *restrict dest,
	const void	*restrict const src, size_t n)
{
	size_t	i;
	size_t	offst;
	size_t	chunks;

	i = 0;
	chunks = n >> 9;
	while (i < chunks)
	{
		offst = i << 3;
		((t_blk512w)dest)[offst + 0] = ((t_blk512r)src)[offst + 0];
		((t_blk512w)dest)[offst + 1] = ((t_blk512r)src)[offst + 1];
		((t_blk512w)dest)[offst + 2] = ((t_blk512r)src)[offst + 2];
		((t_blk512w)dest)[offst + 3] = ((t_blk512r)src)[offst + 3];
		((t_blk512w)dest)[offst + 4] = ((t_blk512r)src)[offst + 4];
		((t_blk512w)dest)[offst + 5] = ((t_blk512r)src)[offst + 5];
		((t_blk512w)dest)[offst + 6] = ((t_blk512r)src)[offst + 6];
		((t_blk512w)dest)[offst + 7] = ((t_blk512r)src)[offst + 7];
		++i;
	}
	offst = chunks << 9;
	ft_memcpy_8x256((t_u8 *)dest + offst, (const t_u8 *)src + offst, n - offst);
}

__attribute__((__nonnull__(1, 2), __always_inline__))
inline void	ft_memcpy_8x256(void *restrict dest,
	const void	*restrict const src, size_t n)
{
	size_t	i;
	size_t	offst;
	size_t	chunks;

	i = 0;
	chunks = n >> 8;
	while (i < chunks)
	{
		offst = i << 3;
		((t_blk256w)dest)[offst + 0] = ((t_blk256r)src)[offst + 0];
		((t_blk256w)dest)[offst + 1] = ((t_blk256r)src)[offst + 1];
		((t_blk256w)dest)[offst + 2] = ((t_blk256r)src)[offst + 2];
		((t_blk256w)dest)[offst + 3] = ((t_blk256r)src)[offst + 3];
		((t_blk256w)dest)[offst + 4] = ((t_blk256r)src)[offst + 4];
		((t_blk256w)dest)[offst + 5] = ((t_blk256r)src)[offst + 5];
		((t_blk256w)dest)[offst + 6] = ((t_blk256r)src)[offst + 6];
		((t_blk256w)dest)[offst + 7] = ((t_blk256r)src)[offst + 7];
		++i;
	}
	offst = chunks << 8;
	ft_memcpy_8x128((t_u8 *)dest + offst, (const t_u8 *)src + offst, n - offst);
}

__attribute__((__nonnull__(1, 2), __always_inline__))
inline void	ft_memcpy_8x128(void *restrict dest,
	const void	*restrict const src, size_t n)
{
	size_t	i;
	size_t	offst;
	size_t	chunks;

	i = 0;
	chunks = n >> 7;
	while (i < chunks)
	{
		offst = i << 3;
		((t_blk128w)dest)[offst + 0] = ((t_blk128r)src)[offst + 0];
		((t_blk128w)dest)[offst + 1] = ((t_blk128r)src)[offst + 1];
		((t_blk128w)dest)[offst + 2] = ((t_blk128r)src)[offst + 2];
		((t_blk128w)dest)[offst + 3] = ((t_blk128r)src)[offst + 3];
		((t_blk128w)dest)[offst + 4] = ((t_blk128r)src)[offst + 4];
		((t_blk128w)dest)[offst + 5] = ((t_blk128r)src)[offst + 5];
		((t_blk128w)dest)[offst + 6] = ((t_blk128r)src)[offst + 6];
		((t_blk128w)dest)[offst + 7] = ((t_blk128r)src)[offst + 7];
		++i;
	}
	offst = chunks << 7;
	ft_memcpy_8x64((t_u8 *)dest + offst, (const t_u8 *)src + offst, n - offst);
}

#endif
