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
inline void	ft_memcpy_128_noacc(void *restrict dest,
	const void	*restrict const src, size_t n, size_t blks)
{
	size_t	i;
	size_t	rem;

	i = 0;
	rem = n & 15;
	while (i < blks)
	{
		ft_prefetchnta(dest, sizeof(t_vu128a) << 1);
		ft_prefetchnta(src, sizeof(t_vu128a) << 1);
		((t_blk128wa)dest)[i] = ((t_blk128r)src)[i];
		++i;
	}
	if (rem)
		*((t_blk128w)ft_overlap(dest, sizeof(t_vu128a), n)) =
			*((t_blk128r)ft_overlap(src, sizeof(t_vu128a), n));
}

__attribute__((__nonnull__(1, 2), __always_inline__))
inline void	ft_memcpy_128_acc(void *restrict dest,
	const void	*restrict const src, size_t n)
{
	size_t		blks;
	size_t		i;
	t_vu128a	acc[4];

	blks = n >> 4;
	i = 0;
	while (i + 4 <= blks)
	{
		ft_prefetchnta(dest, sizeof(t_vu128a) << 1);
		ft_prefetchnta(src, sizeof(t_vu128a) << 1);
		acc[0] = ((t_blk128r)src)[i];
		acc[1] = ((t_blk128r)src)[i + 1];
		acc[2] = ((t_blk128r)src)[i + 2];
		acc[3] = ((t_blk128r)src)[i + 3];
		((t_blk128wa)dest)[i] = acc[0];
		((t_blk128wa)dest)[i + 1] = acc[1];
		((t_blk128wa)dest)[i + 2] = acc[2];
		((t_blk128wa)dest)[i + 3] = acc[3];
		i += 4;
	}
	ft_memcpy_128_noacc(dest, src, n, blks);
}

__attribute__((__nonnull__(1, 2), __always_inline__))
inline void	ft_memcpy_128(void *restrict dest,
	const void	*restrict const src, size_t n)
{
	t_u8	*d;
	t_u8	*s;
	size_t	delta;

	*(t_blk128w)dest = *(t_blk128r)src;
	delta = (-(t_uptr)dest) & 15;
	d = (t_u8 *)dest + delta;
	s = (t_u8 *)src + delta;
	ft_memcpy_128_acc(d, s, n - delta);
}
