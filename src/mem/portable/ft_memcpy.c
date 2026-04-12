/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 21:35:17 by jaicastr          #+#    #+#             */
/*   Updated: 2026/04/12 19:14:12 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/ft_p_mem.h"

__attribute__((__nonnull__(1, 2), __always_inline__))
inline void	ft_memcpy_naive(void *restrict dest,
	const void	*restrict const src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((t_blk8w)dest)[i] = ((t_blk8r)src)[i];
		++i;
	}
}

__attribute__((__nonnull__(1, 2), __always_inline__))
inline void	ft_memcpy_64_noacc(void *restrict dest,
	const void	*restrict const src, size_t n, size_t blks)
{
	size_t	i;
	size_t	rem;

	i = 0;
	rem = n & 7;
	while (i < blks)
	{
		((t_blk64wa)dest)[i] = ((t_blk64r)src)[i];
		++i;
	}
	if (rem)
		*((t_blk64w)ft_overlap(dest, sizeof(t_u64a), n)) =
			*((t_blk64r)ft_overlap(src, sizeof(t_u64a), n));
}

__attribute__((__nonnull__(1, 2), __always_inline__))
inline void	ft_memcpy_64_acc(void *restrict dest,
	const void	*restrict const src, size_t n)
{
	size_t	blks;
	size_t	i;
	t_u64a	acc[4];

	blks = n >> 3;
	i = 0;
	while (i + 4 <= blks)
	{
		acc[0] = ((t_blk64r)src)[i];
		acc[1] = ((t_blk64r)src)[i + 1];
		acc[2] = ((t_blk64r)src)[i + 2];
		acc[3] = ((t_blk64r)src)[i + 3];
		((t_blk64wa)dest)[i] = acc[0];
		((t_blk64wa)dest)[i + 1] = acc[1];
		((t_blk64wa)dest)[i + 2] = acc[2];
		((t_blk64wa)dest)[i + 3] = acc[3];
		i += 4;
	}
	ft_memcpy_64_noacc(dest, src, n, blks);
}

__attribute__((__nonnull__(1, 2), __always_inline__))
inline void	ft_memcpy_64(void *restrict dest,
	const void	*restrict const src, size_t n)
{
	t_u8	*d;
	t_u8	*s;
	size_t	delta;

	*(t_blk64w)dest = *(t_blk64r)src;
	delta = (-(t_uptr)dest) & 7;
	d = (t_u8 *)dest + delta;
	s = (t_u8 *)src + delta;
	ft_memcpy_64_acc(d, s, n - delta);
}
