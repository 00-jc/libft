/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 04:07:01 by jaicastr          #+#    #+#             */
/*   Updated: 2026/01/17 00:45:32 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

#if defined(__LIBFT_SCALAR__) || !defined(__AVX512F__)

__attribute__ ((__nonnull__ (1), __always_inline__, pure))
static inline void	*__fix_last_w(const t_u64a *ptr, size_t diff, t_u64a msk)
{
	t_u64a	w;

	if (diff == 0)
		return (NULL);
	w = (*ptr ^ msk);
	w = (((w)-LONES_64) & (~w) & HIGHS_64);
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
		w = *((t_blk64ra)w_64) ^ msk;
		w = (((w) - LONES_64) & (~w) & HIGHS_64);
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

#else

__attribute__((__always_inline__, const))
static inline size_t	handle_simd_tail(const t_u128a qw[4])
{
	t_u128	segment;
	size_t	result;
	size_t	idx;

	idx = 0;
	segment = qw[idx];
	while (segment == 0)
		segment = qw[++idx];
	result = ft_memctz_u128(segment);
	return ((idx << 4) + (result >> 3));
}

__attribute__ ((__nonnull__ (1), __always_inline__, pure))
static inline void	*__fix_last_w(const t_vu512 *ptr, size_t diff, t_vu512 msk)
{
	t_vu512a					w;
	size_t						result;
	const t_u128	*restrict	qw;

	if (diff == 0)
		return (NULL);
	w = *((t_blk512ra)ptr) ^ msk;
	w = (((w) - get_lones512()) & (~w) & get_high512());
	qw = (const t_u128 * restrict const) & w;
	if (qw[0] || qw[1] || qw[2] || qw[3])
	{
		result = handle_simd_tail((const t_u128a * restrict const)qw);
		return ((void *)((result <= diff) * ((t_uptr)ptr + result)));
	}
	return (NULL);
}

__attribute__((__nonnull__ (1), __always_inline__, pure))
void	*ft_memchr(const void *__restrict__ ptr, int c, size_t n)
{
	t_vu512a					msk;
	t_vu512a					w;
	const t_u8		*restrict	bp;
	const t_vu512	*restrict	w_64;
	const t_u128	*restrict	qw;

	if (n == 0)
		return (NULL);
	bp = (t_u8 *)ptr;
	msk = get_mask512 ((t_u8)c);
	while (n-- > 0 && *bp != c && ((t_uptr)bp & 63))
		++bp;
	w_64 = (const t_vu512 *)bp;
	while (n >= sizeof (t_vu512))
	{
		w = *((t_blk512ra)w_64) ^ msk;
		w = (((w) - get_lones512()) & (~w) & get_high512());
		qw = (const t_u128 * restrict const) & w;
		if (qw[0] || qw[1] || qw[2] || qw[3])
			return ((void *)((t_uptr)w_64 + handle_simd_tail((t_u128 *)qw)));
		w_64++;
		n -= sizeof (t_vu512);
	}
	return (__fix_last_w (w_64, n, msk));
}

#endif
