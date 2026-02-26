/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 15:35:20 by jaicastr          #+#    #+#             */
/*   Updated: 2026/02/20 04:43:19 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "vec.h"
# include "private/ft_p_asm.h"

# ifndef MAP_INITIAL_SIZE
#  define MAP_INITIAL_SIZE	512
# endif

# define MAP_H2_MASK		0x7F
# define MAP_DELETED 		0x80
# define MAP_EMPTY			0xFF

# define H2		0
# define NBLK	1
# define GROUP	2
# define SIZE	3

typedef struct s_bucket
{
	t_u8		*key;
	t_u8		*value;
	size_t		key_len;
}	t_bucket;

typedef struct s_map
{
	size_t		table_size;
	size_t		count;
	t_bucket	*buckets;
	t_u8		*meta;
}	t_map;

t_map		ft_map_with(size_t capacity);
t_map		ft_map_new(void);
void		*ft_map_lookup(const t_map *restrict const map,
				t_u8 *restrict const mem, size_t size)\
				__attribute__((__nonnull__(1, 2)));
t_u32a		ft_map_insert(t_map	*restrict const map,
				t_u8 *restrict const key,
				size_t keylen,
				t_u8 *restrict const value)\
				__attribute__((__nonnull__(1, 2, 4)));
void		ft_map_destroy(t_map *restrict const map)\
				__attribute__((__nonnull__(1)));
void		ft_map_delete(t_map	*restrict const map,
				t_u8 *restrict const key, size_t keylen)\
				__attribute__((__nonnull__(1, 2)));

#endif
