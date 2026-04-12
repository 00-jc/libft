/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 21:35:17 by jaicastr          #+#    #+#             */
/*   Updated: 2026/04/12 19:14:41 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/ft_p_mem.h"

__attribute__((__nonnull__(1), __always_inline__))
inline void	ft_memset_naive(void *restrict dest,
	const t_u8 c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((t_blk8w)dest)[i] = c;
		++i;
	}
}

__attribute__((__nonnull__(1), __always_inline__))
inline void	ft_memset_64(void *restrict dest,
	const t_u8 c, size_t n)
{
	size_t		blks;
	size_t		i;
	size_t		rem;
	t_u64a		msk;

	blks = n >> 3;
	i = 0;
	rem = n & 7;
	msk = __populate(c);
	while (i < blks)
	{
		ft_prefetchnta(dest, sizeof(t_u64a));
		((t_blk64w)dest)[i] = msk;
		++i;
	}
	if (rem)
		*((t_blk64w)ft_overlap(dest, sizeof(t_u64a), n)) = msk;
}
