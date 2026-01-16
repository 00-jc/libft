/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:13:42 by jaicastr          #+#    #+#             */
/*   Updated: 2026/01/17 00:43:59 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

#if !defined(__LIBFT_SCALAR__) && defined(__AVX512F__)

__attribute__((__nonnull__(1), __always_inline__))
inline void	ft_memset_8x512(void *__restrict__ dest,
	const t_u8 b, size_t n)
{
	size_t	i;
	size_t	offst;
	size_t	chunks;
	t_vu512	msk;

	i = 0;
	chunks = n >> 9;
	msk = get_mask512(b);
	while (i < chunks)
	{
		offst = i << 3;
		((t_blk512w)dest)[offst + 0] = msk;
		((t_blk512w)dest)[offst + 1] = msk;
		((t_blk512w)dest)[offst + 2] = msk;
		((t_blk512w)dest)[offst + 3] = msk;
		((t_blk512w)dest)[offst + 4] = msk;
		((t_blk512w)dest)[offst + 5] = msk;
		((t_blk512w)dest)[offst + 6] = msk;
		((t_blk512w)dest)[offst + 7] = msk;
		++i;
	}
	ft_memset_tail(dest, chunks << 9, b, n);
}

__attribute__((__nonnull__(1), __always_inline__))
inline void	ft_memset_8x256(void *__restrict__ dest,
	const t_u8 b, size_t n)
{
	size_t	i;
	size_t	offst;
	size_t	chunks;
	t_vu256	msk;

	i = 0;
	chunks = n >> 8;
	msk = get_mask256(b);
	while (i < chunks)
	{
		offst = i << 3;
		((t_blk256w)dest)[offst + 0] = msk;
		((t_blk256w)dest)[offst + 1] = msk;
		((t_blk256w)dest)[offst + 2] = msk;
		((t_blk256w)dest)[offst + 3] = msk;
		((t_blk256w)dest)[offst + 4] = msk;
		((t_blk256w)dest)[offst + 5] = msk;
		((t_blk256w)dest)[offst + 6] = msk;
		((t_blk256w)dest)[offst + 7] = msk;
		++i;
	}
	ft_memset_tail(dest, chunks << 8, b, n);
}

__attribute__((__nonnull__(1), __always_inline__))
inline void	ft_memset_8x128(void *__restrict__ dest,
	const t_u8 b, size_t n)
{
	size_t	i;
	size_t	offst;
	size_t	chunks;
	t_vu128	msk;

	i = 0;
	chunks = n >> 7;
	msk = get_mask128(b);
	while (i < chunks)
	{
		offst = i << 3;
		((t_blk128w)dest)[offst + 0] = msk;
		((t_blk128w)dest)[offst + 1] = msk;
		((t_blk128w)dest)[offst + 2] = msk;
		((t_blk128w)dest)[offst + 3] = msk;
		((t_blk128w)dest)[offst + 4] = msk;
		((t_blk128w)dest)[offst + 5] = msk;
		((t_blk128w)dest)[offst + 6] = msk;
		((t_blk128w)dest)[offst + 7] = msk;
		++i;
	}
	ft_memset_tail(dest, chunks << 7, b, n);
}

__attribute__((__nonnull__(1)))
void	ft_memset(void *__restrict__ dest,
	const t_u8 b, size_t n)
{
	if (n >= 512ULL)
		ft_memset_8x512(dest, b, n);
	else if (n >= 256ULL)
		ft_memset_8x256(dest, b, n);
	else if (n >= 128ULL)
		ft_memset_8x128(dest, b, n);
	else if (n >= 64ULL)
		ft_memset_8x64(dest, b, n);
	else
		ft_memset_naive(dest, b, n);
}

#else

__attribute__((__nonnull__(1)))
void	ft_memset(void *__restrict__ dest,
	const t_u8 b, size_t n)
{
	ft_memset_8x64(dest, b, n);
}

#endif
