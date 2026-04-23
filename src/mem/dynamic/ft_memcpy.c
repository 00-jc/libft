/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 22:55:19 by jaicastr          #+#    #+#             */
/*   Updated: 2026/04/23 03:12:12 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/ft_p_mem.h"

__attribute__((__nonnull__(1, 2), __always_inline__))
static inline void	ft_memcpy_naive(void *restrict dest,
	const void	*restrict const src, size_t n)
{
	size_t	i[5];

	i[0] = -(1ULL < n) & 2;
	i[1] = -(2ULL < n) & 3;
	i[2] = -(3ULL < n) & 4;
	i[3] = -(4ULL < n) & 5;
	i[4] = -(5ULL < n) & 6;
	((t_blk8w)dest)[0] = ((t_blk8r)src)[0];
	((t_blk8w)dest)[0 < n] = ((t_blk8r)src)[0 < n];
	((t_blk8w)dest)[i[0]] = ((t_blk8r)src)[i[0]];
	((t_blk8w)dest)[i[1]] = ((t_blk8r)src)[i[1]];
	((t_blk8w)dest)[i[2]] = ((t_blk8r)src)[i[2]];
	((t_blk8w)dest)[i[3]] = ((t_blk8r)src)[i[3]];
	((t_blk8w)dest)[i[4]] = ((t_blk8r)src)[i[4]];
}

__attribute__((__nonnull__(1, 2)))
void	ft_memcpy(void *restrict dest,
	const void	*restrict const src, size_t n)
{
	if (__builtin_expect(n == 0, 0))
		return ;
	else if (n < 8)
		ft_memcpy_naive(dest, src, n);
	else if (n < 16)
		ft_memcpy_64(dest, src, n);
	else if (n < 32)
		ft_memcpy_128(dest, src, n);
	else if (n < 64)
		ft_memcpy_256(dest, src, n);
	else if (n < 128)
		ft_memcpy_512(dest, src, n);
	else
		ft_memcpy_512_huge(dest, src, n);
}
