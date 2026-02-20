/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:13:42 by jaicastr          #+#    #+#             */
/*   Updated: 2026/02/20 16:10:15 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/ft_p_mem.h"

__attribute__((__nonnull__(1, 2), __always_inline__))
inline ssize_t	ft_memcmp_naive(const void *restrict const ptr1,
	const void	*restrict const ptr2, size_t offst, size_t n)
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

__attribute__((__nonnull__(1, 2)))
ssize_t	ft_memcmp(const void *restrict const ptr1,
	const void	*restrict const ptr2, size_t n)
{
	size_t	diff;
	size_t	offst;
	size_t	nw;
	t_u64	load0;
	t_u64	load1;

	offst = 0;
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
