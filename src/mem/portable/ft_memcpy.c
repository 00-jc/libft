/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 21:35:17 by jaicastr          #+#    #+#             */
/*   Updated: 2026/04/17 01:09:39 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/ft_p_mem.h"

__attribute__((__nonnull__(1, 2), __always_inline__))
inline void	ft_memcpy_naive(void *restrict dest,
	const void	*restrict const src, size_t n)
{
	size_t	i[5];

	if (__builtin_expect(n != 0, 1))
	{
		i[0] = -(1 < n) & 2;
		i[1] = -(2 < n) & 3;
		i[2] = -(3 < n) & 4;
		i[3] = -(4 < n) & 5;
		i[4] = -(5 < n) & 6;
		((t_blk8w)dest)[0] = ((t_blk8r)src)[0];
		((t_blk8w)dest)[0 < n] = ((t_blk8r)src)[0 < n];
		((t_blk8w)dest)[i[0]] = ((t_blk8r)src)[i[0]];
		((t_blk8w)dest)[i[1]] = ((t_blk8r)src)[i[1]];
		((t_blk8w)dest)[i[2]] = ((t_blk8r)src)[i[2]];
		((t_blk8w)dest)[i[3]] = ((t_blk8r)src)[i[3]];
		((t_blk8w)dest)[i[4]] = ((t_blk8r)src)[i[4]];
		((t_blk8w)dest)[i[5]] = ((t_blk8r)src)[i[5]];
	}
}

__attribute__((__nonnull__(1, 2), __always_inline__))
inline void	ft_memcpy_64(void *restrict dest,
	const void	*restrict const src, size_t n)
{
	((t_blk64w)dest)[0] = ((t_blk64r)src)[0];
	*((t_blk64w)ft_overlap(dest, sizeof(t_u64a), n)) =
		*((t_blk64r)ft_overlap(src, sizeof(t_u64a), n));
}
