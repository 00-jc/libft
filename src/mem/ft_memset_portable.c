/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset_portable.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 21:35:17 by jaicastr          #+#    #+#             */
/*   Updated: 2026/01/15 08:21:05 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

__attribute__((__nonnull__(1), __always_inline__))
inline void	ft_memset_8x64(void *__restrict__ dest,
	const t_u8 c, size_t n)
{
	size_t	i;
	size_t	offst;
	size_t	chunks;
	t_u64	msk;

	i = 0;
	chunks = n >> 6;
	msk = __populate(c);
	while (i < chunks)
	{
		offst = i << 3;
		((t_blk64w)dest)[offst + 0] = msk;
		((t_blk64w)dest)[offst + 1] = msk;
		((t_blk64w)dest)[offst + 2] = msk;
		((t_blk64w)dest)[offst + 3] = msk;
		((t_blk64w)dest)[offst + 4] = msk;
		((t_blk64w)dest)[offst + 5] = msk;
		((t_blk64w)dest)[offst + 6] = msk;
		((t_blk64w)dest)[offst + 7] = msk;
		++i;
	}
	ft_memset_tail(dest, chunks << 6, c, n);
}

__attribute__((__nonnull__(1), __always_inline__))
inline void	ft_memset_tail(void *__restrict__ dest,
	size_t offst, const t_u8 c, size_t n)
{
	n -= offst;
	while (n-- > 0)
	{
		((t_blk8w)dest)[offst] = c;
		++offst;
	}
}

__attribute__((__nonnull__(1), __always_inline__))
inline void	ft_memset_naive(void *__restrict__ dest,
	const t_u8 c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((t_blk8w)dest)[i] = c;
		++i;
	}
}
