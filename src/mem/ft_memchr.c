/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 04:07:01 by jaicastr          #+#    #+#             */
/*   Updated: 2026/02/20 19:43:59 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/ft_p_mem.h"

#if (!defined(__AVX512VL__) || !defined(__x86_64__) ||\
	defined(__LIBFT_PORTABLE__)) && !defined(__AVX2__)

__attribute__ ((__nonnull__ (1), __always_inline__, pure))
static inline void	*__fix_last_w(const t_vu128 *ptr, size_t diff, t_vu128a msk)
{
	t_vu128a		w;
	t_u16a			packed;
	size_t			offst;

	if (diff == 0)
		return (NULL);
	w = __hasz128((*ptr ^ msk)) == get_high128();
	packed = ft_bitpack128(w);
	if (packed)
	{
		offst = ft_memctz_u32(packed);
		return ((void *)((offst < diff) * ((t_uptr)ptr + offst)));
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

	bp = (t_u8 *)ptr;
	msk = get_mask128((t_u8)c);
	wptr = (t_vu128a *)bp;
	while (n >= sizeof (t_vu128a))
	{
		w = __hasz128(*((t_blk128r)wptr) ^ msk);
		hasz = ft_bitpack128(w == get_high128());
		if (hasz)
			return ((void)(hasz = (t_u32a)ft_memctz_u32(hasz)),
			(void *)((t_uptr)wptr + hasz));
		wptr++;
		n -= sizeof (t_vu128);
	}
	return (__fix_last_w (wptr, n, msk));
}

#endif
