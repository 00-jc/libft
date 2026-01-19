/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset_avx256.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 03:43:11 by jaicastr          #+#    #+#             */
/*   Updated: 2026/01/19 04:38:34 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"
#include "lft_private.h"

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

#endif
