/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_extend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:32:14 by jaicastr          #+#    #+#             */
/*   Updated: 2026/02/17 15:57:24 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

__attribute__((__nonnull__(1), __always_inline__))
inline int	ft_vec_reserve(t_vec *restrict const vec,
		size_t type_size, size_t n)
{
	size_t		nn;
	size_t		old_size;
	size_t		old_cap_bytes;
	size_t		bytes_to_append;
	t_vec		v;

	v = *vec;
	old_size = ft_vec_bytesize(vec);
	old_cap_bytes = v.capacity * type_size;
	bytes_to_append = n * type_size;
	if (old_size + bytes_to_append >= old_cap_bytes)
	{
		nn = __maxu64(old_cap_bytes << 1, old_size + bytes_to_append);
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
int	ft_vec_extend(t_vec *restrict const vec,
		const t_u8 *restrict const data, size_t type_size, size_t n)
{
	t_vec		deref_v;
	size_t		growth;

	if (vec->data == NULL)
		return (0);
	if (!ft_vec_reserve(vec, type_size, n))
		return (0);
	deref_v = *vec;
	growth = n * type_size;
	ft_memcpy(deref_v.head, data, growth);
	deref_v.head += growth;
	*vec = deref_v;
	return (1);
}
