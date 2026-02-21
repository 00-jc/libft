/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr_avx512.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 14:59:18 by jaicastr          #+#    #+#             */
/*   Updated: 2026/02/21 03:36:05 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/ft_p_mem.h"

#if defined(__AVX512F__)

__attribute__ ((__nonnull__ (1), __always_inline__, pure))
static inline void	*ft__fix_last_w(const t_u8 *restrict const ptr,
	size_t n, t_vu512a msk)
{
	t_vu512a		w;
	t_vu512			*adjusted;
	t_u64a			packed;

	if (n == 0)
		return (NULL);
	adjusted = (t_vu512 *)(ptr + n - sizeof(msk));
	w = __hasz512(*(t_blk512r)adjusted ^ msk) == get_high512();
	packed = ft_bitpack512(w) & (0xFFFFFFFFFFFFFFFF << (sizeof(msk) - n));
	if (packed)
		return ((void *)((t_u8 *)adjusted + ft_memctz_u64(packed)));
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
	t_vu512a					msk;
	t_u64a						hasz;
	t_vu512a					w;
	const t_u8		*restrict	bp;
	t_vu512						*wptr;

	if (n < sizeof(t_vu512))
		return (ft_memchr_minimal(ptr, (t_u8)c, n));
	bp = (t_u8 *)ptr;
	msk = get_mask512((t_u8)c);
	wptr = (t_vu512a *)bp;
	while (n >= sizeof (t_vu512a))
	{
		w = __hasz512(*((t_blk512r)wptr) ^ msk);
		hasz = ft_bitpack512(w == get_high512());
		if (hasz)
			return ((void)(hasz = ft_memctz_u64(hasz)),
			(void *)((t_u8 *)wptr + hasz));
		wptr++;
		n -= sizeof (t_vu512);
	}
	return (ft__fix_last_w ((t_u8 *)wptr, n, msk));
}

#endif
