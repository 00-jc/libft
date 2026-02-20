/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_push_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:32:14 by jaicastr          #+#    #+#             */
/*   Updated: 2026/02/17 15:45:15 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

__attribute__((__nonnull__(1), __always_inline__))
static inline int	ft_vec_grow_one(t_vec *restrict const vec, size_t type_size)
{
	size_t		nn;
	size_t		old_size;
	size_t		old_cap_bytes;
	t_vec		v;

	v = *vec;
	old_size = ft_vec_bytesize(vec);
	old_cap_bytes = v.capacity * type_size;
	if (old_size == old_cap_bytes)
	{
		nn = old_cap_bytes << 1;
		v.data = ft_recalloc((void *)v.data, old_cap_bytes, nn);
		if (v.data == NULL)
			return (0);
		v.head = (t_u8 *)v.data + old_size;
		v.capacity = nn / type_size;
	}
	*vec = v;
	return (1);
}

__attribute__((__nonnull__(1, 2)))
int	ft_vec_push_back(t_vec *restrict const vec,
		const t_u8 *restrict const data, size_t type_size)
{
	t_vec		deref_v;

	if (vec->data == NULL)
		return (0);
	if (!ft_vec_grow_one(vec, type_size))
		return (0);
	deref_v = *vec;
	ft_memcpy(deref_v.head, data, type_size);
	deref_v.head += type_size;
	*vec = deref_v;
	return (1);
}
