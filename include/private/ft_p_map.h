/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_map.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 02:33:42 by jaicastr          #+#    #+#             */
/*   Updated: 2026/02/20 15:49:00 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_P_MAP_H
# define FT_P_MAP_H

# include "map.h"

void		ft_map_insert_unchecked(t_map *restrict const map,\
				t_u8 *restrict const key, size_t keylen,\
				t_u8 *restrict const value)\
				__attribute__((__nonnull__(1, 2, 4)));

t_u32a		ft_map_rehash(t_map *restrict const map)\
				__attribute__((__nonnull__(1)));

size_t		ft__map_lookup_offset(const t_map *restrict const map,\
				const t_u8 *restrict const mem, size_t data[4])\
				__attribute__((__nonnull__(1, 2, 3)));

#endif
