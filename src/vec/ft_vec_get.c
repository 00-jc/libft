/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:14:07 by jaicastr          #+#    #+#             */
/*   Updated: 2026/01/19 04:38:34 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

__attribute__((__nonnull__(1), __always_inline__, pure))
const void	*ft_vec_get(const t_vec *restrict const vec,
		size_t idx, size_t type_size)
{
	size_t	sizeb;

	sizeb = ft_vec_bytesize(vec);
	idx = idx * type_size;
	return ((void *)((idx < sizeb) * ((t_uptr)vec->data + idx)));
}

__attribute__((__nonnull__(1), __always_inline__, pure))
void	*ft_vec_get_mut(const t_vec *restrict const vec,
		size_t idx, size_t type_size)
{
	size_t	sizeb;

	sizeb = ft_vec_bytesize(vec);
	idx = idx * type_size;
	return ((void *)((idx < sizeb) * ((t_uptr)vec->data + idx)));
}

__attribute__((__nonnull__(1), __always_inline__, pure))
const void	*ft_vec_peek_last(const t_vec *restrict const vec, size_t type_size)
{
	return ((t_u8 *)((vec->data != vec->head)
		* ((t_uptr)vec->head - type_size)));
}

__attribute__((__nonnull__(1), __always_inline__, pure))
void	*ft_vec_get_last(const t_vec *restrict const vec, size_t type_size)
{
	return ((t_u8 *)((vec->data != vec->head)
		* ((t_uptr)vec->head - type_size)));
}
