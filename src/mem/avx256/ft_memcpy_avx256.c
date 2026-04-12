/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_avx256.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 22:55:19 by jaicastr          #+#    #+#             */
/*   Updated: 2026/04/12 20:08:55 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/ft_p_mem.h"

#if defined(__AVX2__)

__attribute__((__nonnull__(1, 2), __always_inline__))
inline void	ft_memcpy_256_noacc(void *restrict dest,
	const void	*restrict const src, size_t n, size_t blks)
{
	size_t		i;
	size_t		rem;

	i = 0;
	rem = n & 31;
	while (i < blks)
	{
		ft_prefetchnta(dest, sizeof(t_vu256a) << 1);
		ft_prefetchnta(src, sizeof(t_vu256a) << 1);
		((t_blk256wa)dest)[i] = ((t_blk256r)src)[i];
		++i;
	}
	if (rem)
		*((t_blk256w)ft_overlap(dest, sizeof(t_vu256a), n)) =
			*((t_blk256r)ft_overlap(src, sizeof(t_vu256a), n));
}

__attribute__((__nonnull__(1, 2), __always_inline__))
inline void	ft_memcpy_256_acc(void *restrict dest,
	const void	*restrict const src, size_t n)
{
	size_t		blks;
	size_t		i;
	t_vu256a	acc[4];

	blks = n >> 5;
	i = 0;
	while (i + 4 <= blks)
	{
		ft_prefetchnta(dest, sizeof(t_vu256a) << 2);
		ft_prefetchnta(src, sizeof(t_vu256a) << 2);
		acc[0] = ((t_blk256r)src)[i];
		acc[1] = ((t_blk256r)src)[i + 1];
		acc[2] = ((t_blk256r)src)[i + 2];
		acc[3] = ((t_blk256r)src)[i + 3];
		((t_blk256wa)dest)[i] = acc[0];
		((t_blk256wa)dest)[i + 1] = acc[1];
		((t_blk256wa)dest)[i + 2] = acc[2];
		((t_blk256wa)dest)[i + 3] = acc[3];
		i += 4;
	}
	ft_memcpy_256_noacc(dest, src, n, blks);
}

__attribute__((__nonnull__(1, 2), __always_inline__))
inline void	ft_memcpy_256(void *restrict dest,
	const void	*restrict const src, size_t n)
{
	t_u8	*d;
	t_u8	*s;
	size_t	delta;

	*(t_blk256w)dest = *(t_blk256r)src;
	delta = (-(t_uptr)dest) & 31;
	d = (t_u8 *)dest + delta;
	s = (t_u8 *)src + delta;
	ft_memcpy_256_acc(d, s, n - delta);
}

#endif
