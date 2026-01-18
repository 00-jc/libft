/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 04:07:01 by jaicastr          #+#    #+#             */
/*   Updated: 2026/01/18 10:26:14 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

#if !defined(__AVX512VL__) || !defined(__x86_64__) || defined(__LIBFT_SCALAR__)

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
		return ((void *)((w <= diff) * ((t_uptr)ptr + w)));
	}
	return (NULL);
}

__attribute__((__nonnull__ (1), __always_inline__, pure))
void	*ft_memchr(const void *__restrict__ ptr, int c, size_t n)
{
	t_u64a						msk;
	t_u64a						w;
	const t_u8		*restrict	bp;
	const t_u64a	*restrict	w_64;

	if (n == 0)
		return (NULL);
	bp = (t_u8 *)ptr;
	msk = __populate ((t_u8)c);
	while (n-- > 0 && *bp != c && ((t_uptr)bp & (sizeof (t_u64a) - 1)))
		++bp;
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
