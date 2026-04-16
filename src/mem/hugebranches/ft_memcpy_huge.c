/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_huge.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 00:05:58 by jaicastr          #+#    #+#             */
/*   Updated: 2026/04/17 01:00:41 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/ft_p_mem.h"

__attribute__((__nonnull__(1, 2), __always_inline__))
inline void	ft__cascade_cpy(void *restrict dest,
	const void	*restrict const src, size_t i)
{
	t_vu512a	x[8];

	ft_prefetchnta(src, sizeof(t_vu512) << 1);
	ft_prefetchnta(src, sizeof(t_vu512) << 2);
	ft_prefetchnta(src, sizeof(t_vu512) << 3);
	ft_prefetchnta(dest, sizeof(t_vu512) << 1);
	ft_prefetchnta(dest, sizeof(t_vu512) << 2);
	ft_prefetchnta(dest, sizeof(t_vu512) << 3);
	x[0] = ((t_blk512r)src)[i + 0];
	x[1] = ((t_blk512r)src)[i + 1];
	x[2] = ((t_blk512r)src)[i + 2];
	x[3] = ((t_blk512r)src)[i + 3];
	x[4] = ((t_blk512r)src)[i + 4];
	x[5] = ((t_blk512r)src)[i + 5];
	x[6] = ((t_blk512r)src)[i + 6];
	x[7] = ((t_blk512r)src)[i + 7];
	((t_blk512wa)dest)[i + 0] = x[0];
	((t_blk512wa)dest)[i + 1] = x[1];
	((t_blk512wa)dest)[i + 2] = x[2];
	((t_blk512wa)dest)[i + 3] = x[3];
	((t_blk512wa)dest)[i + 4] = x[4];
	((t_blk512wa)dest)[i + 5] = x[5];
	((t_blk512wa)dest)[i + 6] = x[6];
	((t_blk512wa)dest)[i + 7] = x[7];
}

__attribute__((__nonnull__(1, 2), __always_inline__))
inline void	ft_memcpy_512_huge(void *restrict dest,
	const void	*restrict const src, size_t n)
{
	t_double_size	s;
	size_t			delta;
	t_u8			*d;
	const t_u8		*sr;

	*(t_blk512w)dest = *(t_blk512r)src;
	delta = (-(t_uptr)dest) & 63;
	d = (t_u8 *)dest + delta;
	sr = (const t_u8 *)src + delta;
	n -= delta;
	s.blks = n >> 6;
	s.i = 0;
	while (s.i + 8 <= s.blks)
	{
		ft__cascade_cpy(d, sr, s.i);
		s.i += 8;
	}
	while (s.i <= s.blks)
	{
		((t_blk512wa)dest)[s.i] = ((t_blk512r)src)[s.i];
		++s.i;
	}
	s.i <<= 6;
	ft_memcpy_256(d + s.i, sr + s.i, n - s.i);
}
