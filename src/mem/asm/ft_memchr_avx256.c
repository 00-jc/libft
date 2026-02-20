/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr_avx256.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 14:59:18 by jaicastr          #+#    #+#             */
/*   Updated: 2026/02/20 16:46:18 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/ft_p_mem.h"

#if (!defined(__AVX512F__) || !defined(__x86_64__)\
	|| defined(__LIBFT_PORTABLE__)) && defined(__AVX2__)

__attribute__ ((__nonnull__ (1), __always_inline__, pure))
static inline void	*__fix_last_w(const t_vu256 *ptr, size_t diff, t_vu256a msk)
{
	t_vu256a		w;
	t_u32a			packed;
	size_t			offst;

	if (diff == 0)
		return (NULL);
	w = __hasz256((*ptr ^ msk)) == get_high256();
	packed = ft_bitpack256(w);
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
	t_vu256a					msk;
	t_u32a						hasz;
	t_vu256a					w;
	const t_u8		*restrict	bp;
	t_vu256						*wptr;

	bp = (t_u8 *)ptr;
	msk = get_mask256((t_u8)c);
	wptr = (t_vu256a *)bp;
	while (n >= sizeof (t_vu256a))
	{
		w = __hasz256(*((t_blk256r)wptr) ^ msk);
		hasz = ft_bitpack256(w == get_high256());
		if (hasz)
			return ((void)(hasz = (t_u32a)ft_memctz_u32(hasz)),
			(void *)((t_uptr)wptr + hasz));
		wptr++;
		n -= sizeof (t_vu256);
	}
	return (__fix_last_w (wptr, n, msk));
}

#endif
