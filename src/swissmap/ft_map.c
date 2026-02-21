/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 22:43:01 by jaicastr          #+#    #+#             */
/*   Updated: 2026/02/20 04:04:24 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

t_map	ft_map_with(size_t capacity)
{
	t_u8		*meta;
	t_bucket	*buckets;

	if (capacity & 15)
		return ((t_map){0});
	meta = ft_alloc(capacity);
	if (!meta)
		return ((t_map){0});
	ft_memset(meta, MAP_EMPTY, capacity);
	buckets = ft_calloc(capacity, sizeof(t_bucket));
	if (!buckets)
		return (ft_free((void **)&(void *){meta}), (t_map){0});
	return ((t_map)
		{
			.buckets = buckets,
			.meta = meta,
			.count = 0,
			.table_size = capacity,
		});
}

t_map	ft_map_new(void)
{
	return (ft_map_with(MAP_INITIAL_SIZE));
}

__attribute__((__nonnull__(1)))
void	ft_map_destroy(t_map *restrict const map)
{
	ft_free((void **)&(void *){map->buckets});
	ft_free((void **)&(void *){map->meta});
}
