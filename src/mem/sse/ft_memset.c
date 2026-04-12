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
inline void	ft_memset_128(void *restrict dest,
	const t_u8 b, size_t n)
{
	size_t		blks;
	size_t		i;
	size_t		rem;
	t_vu128a	msk;

	blks = n >> 4;
	i = 0;
	rem = n & 15;
	msk = get_mask128(b);
	while (i < blks)
	{
		ft_prefetchnta(dest, sizeof(t_vu128a) << 1);
		((t_blk128w)dest)[i] = msk;
		++i;
	}
	if (rem)
		*((t_blk128w)ft_overlap(dest, sizeof(t_vu128a), n)) = msk;
}
