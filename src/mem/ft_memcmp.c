/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:13:42 by jaicastr          #+#    #+#             */
/*   Updated: 2026/01/15 08:21:05 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

__attribute__((__nonnull__(1, 2), __always_inline__))
inline ssize_t	ft_memcmp_naive(const void *__restrict__ const ptr1,
	const void	*__restrict__ const ptr2, size_t offst, size_t n)
{
	ssize_t	diff;

	while (offst < n)
	{
		diff = ((t_blk8r)ptr1)[offst] - ((t_blk8r)ptr2)[offst];
		if (diff)
			return (diff);
		++offst;
	}
	return (0);
}

#ifndef __LIBFT_SCALAR__

__attribute__((__always_inline__, const))
static inline size_t	handle_simd_tail(const t_u128 qw[4])
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

__attribute__((__nonnull__(1, 2)))
ssize_t	ft_memcmp(const void *__restrict__ const ptr1,
	const void	*__restrict__ const ptr2, size_t n)
{
	t_vu512					diff;
	size_t					offst;
	size_t					nw;
	t_vu512					load0;
	t_vu512					load1;

	offst = 0;
	nw = n >> 9;
	while (offst < nw)
	{
		load0 = ((t_blk512r)ptr1)[offst];
		load1 = ((t_blk512r)ptr2)[offst];
		diff = load0 ^ load1;
		if ((((const t_u128 *)&diff)[0]) || (((const t_u128 *)&diff)[1])
				|| (((const t_u128 *)&diff)[2]) || (((const t_u128 *)&diff)[3]))
		{
			offst = handle_simd_tail((const t_u128 * restrict const) & diff);
			return (load0[offst] - load1[offst]);
		}
		++offst;
	}
	return (ft_memcmp_naive(ptr1, ptr2, offst << 9, n));
}

#else

__attribute__((__nonnull__(1, 2)))
ssize_t	ft_memcmp(const void *__restrict__ const ptr1,
	const void	*__restrict__ const ptr2, size_t n)
{
	size_t	diff;
	size_t	offst;
	size_t	nw;
	t_u64	load0;
	t_u64	load1;

	offst = 0;
	diff = 0;
	nw = n >> 3;
	while (offst < nw)
	{
		load0 = ((t_blk64r)ptr1)[offst];
		load1 = ((t_blk64r)ptr2)[offst];
		diff = load0 ^ load1;
		if (diff)
		{
			diff = ft_memctz_u64(diff);
			return ((ssize_t)(((load0 >> diff) & 0xFF)
				- ((load1 >> diff) & 0xFF)));
		}
		++offst;
	}
	return (ft_memcmp_naive(ptr1, ptr2, offst << 3, n));
}

#endif
