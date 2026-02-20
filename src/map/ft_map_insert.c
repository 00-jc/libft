/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 02:53:03 by jaicastr          #+#    #+#             */
/*   Updated: 2026/02/20 04:55:45 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "private/ft_p_map.h"

__attribute__((__nonnull__(1)))
static inline size_t	ft__get_empty(const t_map *restrict const map,
	size_t group, size_t nblks)
{
	t_u16a		mask;

	while (1)
	{
		mask = ft_bitpack128(
				(((t_blk128r)map->meta)[group] >= get_high128())
				);
		if (mask)
			return ((group << 4) + ft_memctz_u16(mask));
		group = (group + 1) % nblks;
	}
}

__attribute__((__always_inline__, __nonnull__(1)))
static inline void	ft__interbuck(t_map *restrict const map,
	t_bucket buck, size_t empty_lot, t_u128a hash)
{
	map->buckets[empty_lot] = buck;
	map->meta[empty_lot] = hash & MAP_H2_MASK;
}

__attribute__((__nonnull__(1, 2, 4)))
t_u32a	ft_map_insert(t_map	*restrict const map,
	t_u8 *restrict const key,
	size_t keylen,
	t_u8 *restrict const value)
{
	size_t		empty_lot;
	t_bucket	buck;
	t_u128a		hash;
	size_t		nblks;
	size_t		group;

	if (((double)map->count / (double)map->table_size >= 0.85f)
		&& !ft_map_rehash(map))
		return (0);
	hash = ft_murmur3(key, keylen);
	nblks = map->table_size >> 4;
	group = (hash >> 64) % nblks;
	empty_lot = ft__map_lookup_offset(map, key,
			(size_t [4]){hash & MAP_H2_MASK, nblks, group, keylen});
	buck = (t_bucket){
		.key = key,
		.key_len = keylen,
		.value = value,
	};
	if (empty_lot <= map->table_size)
		return (ft__interbuck(map, buck, empty_lot, hash), 1);
	empty_lot = ft__get_empty(map, group, nblks);
	ft__interbuck(map, buck, empty_lot, hash);
	map->count++;
	return (1);
}
