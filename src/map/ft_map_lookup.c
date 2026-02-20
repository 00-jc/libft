/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_lookup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 02:35:25 by jaicastr          #+#    #+#             */
/*   Updated: 2026/02/20 04:42:00 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

__attribute__((__nonnull__(1, 2, 3)))
static inline void	*ft__map_lookup(const t_map *restrict const map,
	const t_u8 *restrict const mem, size_t data[4])
{
	t_vu128		sse[3];
	t_u16a		mask;
	t_bucket	bucket;
	size_t		i;

	sse[0] = ((t_blk128r)map->meta)[data[GROUP]];
	sse[1] = get_mask128((t_u8)data[H2]);
	sse[2] = ~get_z128();
	while (1)
	{
		mask = ft_bitpack128(sse[0] == sse[1]);
		while (mask)
		{
			i = ft_memctz_u16(mask);
			bucket = map->buckets[(data[GROUP] << 4) + i];
			if (bucket.key_len == data[SIZE]
				&& !ft_memcmp(mem, bucket.key, bucket.key_len))
				return (bucket.value);
			mask &= mask - 1;
		}
		if ((t_u128a)(sse[0] == sse[2]))
			return (NULL);
		data[GROUP] = (data[GROUP] + 1) % data[NBLK];
		sse[0] = ((t_blk128r)map->meta)[data[GROUP]];
	}
}

__attribute__((__nonnull__(1, 2)))
void	*ft_map_lookup(const t_map *restrict const map,
	t_u8 *restrict const mem, size_t size)
{
	t_u128a		hash;
	t_u8		h2;
	size_t		group;
	size_t		nblks;

	hash = ft_murmur3(mem, size);
	h2 = hash & MAP_H2_MASK;
	nblks = map->table_size >> 4;
	group = (hash >> 64) % nblks;
	return (ft__map_lookup(map, mem,
			(size_t [4]){h2, nblks, group, size}));
}
