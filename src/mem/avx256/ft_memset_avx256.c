/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset_avx256.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 03:43:11 by jaicastr          #+#    #+#             */
/*   Updated: 2026/04/12 19:14:34 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/ft_p_mem.h"

#if defined(__AVX2__)

__attribute__((__nonnull__(1), __always_inline__))
inline void	ft_memset_256(void *restrict dest,
	const t_u8 b, size_t n)
{
	size_t		blks;
	size_t		i;
	size_t		rem;
	t_vu256a	msk;

	blks = n >> 5;
	i = 0;
	rem = n & 31;
	msk = get_mask256(b);
	while (i < blks)
	{
		ft_prefetchnta(dest, sizeof(t_vu256a) << 1);
		((t_blk256w)dest)[i] = msk;
		++i;
	}
	if (rem)
		*((t_blk256w)ft_overlap(dest, sizeof(t_vu256a), n)) = msk;
}

#endif
