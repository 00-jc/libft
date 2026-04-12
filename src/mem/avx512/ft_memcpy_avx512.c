/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_avx512.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 22:55:19 by jaicastr          #+#    #+#             */
/*   Updated: 2026/04/13 00:05:33 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/ft_p_mem.h"

__attribute__((__nonnull__(1, 2), __always_inline__))
inline void	ft_memcpy_512_noacc(void *restrict dest,
	const void	*restrict const src, size_t n, t_double_size s)
{
	while (s.i < s.blks)
	{
		ft_prefetchnta(dest, sizeof(t_vu512a) << 1);
		ft_prefetchnta(src, sizeof(t_vu512a) << 1);
		((t_blk512wa)dest)[s.i] = ((t_blk512r)src)[s.i];
		++s.i;
	}
	if (n & 63)
		*((t_blk512w)ft_overlap(dest, sizeof(t_vu512a), n)) =
			*((t_blk512r)ft_overlap(src, sizeof(t_vu512a), n));
}

__attribute__((__nonnull__(1, 2), __always_inline__))
inline void	ft_memcpy_512_acc(void *restrict dest,
	const void	*restrict const src, size_t n)
{
	t_double_size	s;
	t_vu512a		acc[4];

	s.blks = n >> 6;
	s.i = 0;
	while (s.i + 4 <= s.blks)
	{
		ft_prefetchnta(dest, sizeof(t_vu512a) << 2);
		ft_prefetchnta(src, sizeof(t_vu512a) << 2);
		acc[0] = ((t_blk512r)src)[s.i + 0];
		acc[1] = ((t_blk512r)src)[s.i + 1];
		acc[2] = ((t_blk512r)src)[s.i + 2];
		acc[3] = ((t_blk512r)src)[s.i + 3];
		((t_blk512wa)dest)[s.i + 0] = acc[0];
		((t_blk512wa)dest)[s.i + 1] = acc[1];
		((t_blk512wa)dest)[s.i + 2] = acc[2];
		((t_blk512wa)dest)[s.i + 3] = acc[3];
		s.i += 4;
	}
	ft_memcpy_512_noacc(dest, src, n, s);
}

__attribute__((__nonnull__(1, 2), __always_inline__))
inline void	ft_memcpy_512(void *restrict dest,
	const void	*restrict const src, size_t n)
{
	t_u8	*d;
	t_u8	*s;
	size_t	delta;

	*(t_blk512w)dest = *(t_blk512r)src;
	delta = (-(t_uptr)dest) & 63;
	d = (t_u8 *)dest + delta;
	s = (t_u8 *)src + delta;
	ft_memcpy_512_acc(d, s, n - delta);
}
