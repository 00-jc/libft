/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset_avx512.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 03:43:11 by jaicastr          #+#    #+#             */
/*   Updated: 2026/04/12 19:14:34 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/ft_p_mem.h"

#if defined(__AVX512F__)

__attribute__((__nonnull__(1), __always_inline__))
inline void	ft_memset_512(void *restrict dest,
	const t_u8 b, size_t n)
{
	size_t		blks;
	size_t		i;
	size_t		rem;
	t_vu512a	msk;

	blks = n >> 6;
	i = 0;
	rem = n & 63;
	msk = get_mask512(b);
	while (i < blks)
	{
		ft_prefetchnta(dest, sizeof(t_vu512a) << 1);
		((t_blk512w)dest)[i] = msk;
		++i;
	}
	if (rem)
		*((t_blk512w)ft_overlap(dest, sizeof(t_vu512a), n)) = msk;
}

#endif
