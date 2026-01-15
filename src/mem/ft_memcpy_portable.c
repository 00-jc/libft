/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_portable.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 21:35:17 by jaicastr          #+#    #+#             */
/*   Updated: 2026/01/15 08:21:05 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

__attribute__((__nonnull__(1, 2), __always_inline__))
inline void	ft_memcpy_8x64(void *__restrict__ dest,
	const void	*__restrict__ const src, size_t n)
{
	size_t	i;
	size_t	offst;
	size_t	chunks;

	i = 0;
	chunks = n >> 6;
	while (i < chunks)
	{
		offst = i << 3;
		((t_blk64w)dest)[offst + 0] = ((t_blk64r)src)[offst + 0];
		((t_blk64w)dest)[offst + 1] = ((t_blk64r)src)[offst + 1];
		((t_blk64w)dest)[offst + 2] = ((t_blk64r)src)[offst + 2];
		((t_blk64w)dest)[offst + 3] = ((t_blk64r)src)[offst + 3];
		((t_blk64w)dest)[offst + 4] = ((t_blk64r)src)[offst + 4];
		((t_blk64w)dest)[offst + 5] = ((t_blk64r)src)[offst + 5];
		((t_blk64w)dest)[offst + 6] = ((t_blk64r)src)[offst + 6];
		((t_blk64w)dest)[offst + 7] = ((t_blk64r)src)[offst + 7];
		++i;
	}
	ft_memcpy_tail(dest, src, chunks << 6, n);
}

__attribute__((__nonnull__(1, 2), __always_inline__))
inline void	ft_memcpy_tail(void *__restrict__ dest,
	const void	*__restrict__ const src, size_t offst, size_t n)
{
	n -= offst;
	while (n-- > 0)
	{
		((t_blk8w)dest)[offst] = ((t_blk8r)src)[offst];
		++offst;
	}
}

__attribute__((__nonnull__(1, 2), __always_inline__))
inline void	ft_memcpy_naive(void *__restrict__ dest,
	const void	*__restrict__ const src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((t_blk8w)dest)[i] = ((t_blk8r)src)[i];
		++i;
	}
}
