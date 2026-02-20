/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 04:07:01 by jaicastr          #+#    #+#             */
/*   Updated: 2026/02/20 03:45:38 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/ft_p_mem.h"

#if !defined(__AVX512VL__) || !defined(__x86_64__) ||\
	defined(__LIBFT_PORTABLE__)

__attribute__ ((__nonnull__ (1), __always_inline__, pure))
static inline void	*__fix_last_w(const t_u64a *ptr, size_t diff, t_u64a msk)
{
	t_u64a	w;

	if (diff == 0)
		return (NULL);
	w = __hasz64((*ptr ^ msk));
	if (w)
	{
		w = ft_memctz_u64(w);
		w >>= 3;
		return ((void *)((w < diff) * ((t_uptr)ptr + w)));
	}
	return (NULL);
}

__attribute__((__nonnull__ (1), __always_inline__, pure))
void	*ft_memchr(const void *restrict ptr, int c, size_t n)
{
	t_u64a						msk;
	t_u64a						w;
	const t_u8		*restrict	bp;
	const t_u64a	*restrict	w_64;

	bp = (t_u8 *)ptr;
	msk = __populate ((t_u8)c);
	while (n > 0 && *bp != (t_u8)c && ((t_uptr)bp & 7))
	{
		++bp;
		--n;
	}
	w_64 = (const t_u64a *)bp;
	while (n >= sizeof (t_u64))
	{
		w = __hasz64(*((t_blk64ra)w_64) ^ msk);
		if (w)
		{
			w = ft_memctz_u64(w);
			return ((void *)((t_uptr)w_64 + (w >> 3)));
		}
		w_64++;
		n -= sizeof (t_u64);
	}
	return (__fix_last_w (w_64, n, msk));
}

#endif
