/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_huge.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 00:05:58 by jaicastr          #+#    #+#             */
/*   Updated: 2026/04/17 10:09:41 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/ft_p_mem.h"

__attribute__((__nonnull__(1, 2), __always_inline__))
inline void	ft_memcpy_hugetail(void *restrict dest,
	const void	*restrict const src, size_t n)
{
	size_t	i;

	if (__builtin_expect(n != 0, 1))
	{
		i = -(1 < n) & 2;
		((t_blk512wa)dest)[0] = ((t_blk512r)src)[0];
		((t_blk512wa)dest)[0 < n] = ((t_blk512r)src)[0 < n];
		((t_blk512wa)dest)[i] = ((t_blk512r)src)[i];
		*((t_blk512w)ft_overlap(dest, sizeof(t_vu512a), n)) =
			*((t_blk512r)ft_overlap(src, sizeof(t_vu512a), n));
	}
}

__attribute__((__nonnull__(1, 2, 4)))
inline void	ft__cascade_cpy(void *restrict dest,
	const void	*restrict const src, size_t i,
	t_vu512a * restrict const x)
{
	x[0] = ((t_blk512r)src)[i + 0];
	x[1] = ((t_blk512r)src)[i + 1];
	x[2] = ((t_blk512r)src)[i + 2];
	x[3] = ((t_blk512r)src)[i + 3];
	((t_blk512wa)dest)[i + 0] = x[0];
	((t_blk512wa)dest)[i + 1] = x[1];
	((t_blk512wa)dest)[i + 2] = x[2];
	((t_blk512wa)dest)[i + 3] = x[3];
}

__attribute__((__nonnull__(1, 2), __always_inline__))
inline void	ft_memcpy_512_huge(void *restrict dest,
	const void	*restrict const src, size_t n)
{
	t_double_size	s;
	size_t			delta;
	t_u8			*d;
	const t_u8		*sr;
	t_vu512a		x[4];

	delta = (-(t_uptr)dest) & 63;
	*(t_blk512w)dest = *(t_blk512r)src;
	d = (t_u8 *)dest + delta;
	sr = (const t_u8 *)src + delta;
	n -= delta;
	s.blks = n >> 6;
	s.i = 0;
	while (s.i + 4 < s.blks)
	{
		ft__cascade_cpy(d, sr, s.i, x);
		s.i += 4;
	}
	s.i <<= 6;
	ft_memcpy_hugetail(d + s.i, sr + s.i, n - s.i);
}
