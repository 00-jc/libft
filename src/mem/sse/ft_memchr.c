/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 04:07:01 by jaicastr          #+#    #+#             */
/*   Updated: 2026/02/21 14:39:59 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/ft_p_mem.h"

#ifndef __AVX2__

__attribute__ ((__nonnull__ (1), __always_inline__, pure))
static inline void	*ft__fix_last_w(const t_u8 *restrict const ptr,
	size_t n, t_vu128a msk)
{
	t_vu128a		w;
	t_vu128			*adjusted;
	t_u16a			packed;

	if (n == 0)
		return (NULL);
	adjusted = (t_vu128 *)(ptr + n - sizeof(msk));
	w = (*(t_blk128r)adjusted ^ msk) == get_z128();
	packed = ft_bitpack128(w) & (0xFFFF << (sizeof(msk) - n));
	if (packed)
		return ((void *)((t_u8 *)adjusted + ft_memctz_u16(packed)));
	return (NULL);
}

__attribute__((__nonnull__(1), __always_inline__))
static inline void	*ft_memchr_minimal(const void *restrict const ptr,
	t_u8 c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((t_blk8r)ptr)[i] == c)
			return ((void *)((t_u8 *)ptr + i));
		++i;
	}
	return (NULL);
}

__attribute__((__nonnull__ (1), __always_inline__, pure))
void	*ft_memchr(const void *restrict ptr, int c, size_t n)
{
	t_vu128a					msk;
	t_u16a						hasz;
	t_vu128a					w;
	const t_u8		*restrict	bp;
	t_vu128						*wptr;

	if (n < sizeof(t_vu128))
		return (ft_memchr_minimal(ptr, (t_u8)c, n));
	bp = (t_u8 *)ptr;
	msk = get_mask128((t_u8)c);
	wptr = (t_vu128a *)bp;
	while (n >= sizeof (t_vu128a))
	{
		ft_prefetch0(wptr, sizeof(t_vu128a) << 1);
		w = (*((t_blk128r)wptr) ^ msk) == get_z128();
		hasz = ft_bitpack128(w);
		if (hasz)
			return ((void)(hasz = (t_u16a)ft_memctz_u16(hasz)),
			(void *)((t_u8 *)wptr + hasz));
		wptr++;
		n -= sizeof (t_vu128);
	}
	return (ft__fix_last_w ((t_u8 *)wptr, n, msk));
}

#endif
