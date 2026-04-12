/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_push_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:32:14 by jaicastr          #+#    #+#             */
/*   Updated: 2026/04/13 01:46:09 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

__attribute__((__nonnull__(1), __always_inline__))
static inline int	ft_vec_grow_one(t_vec *restrict const vec, size_t type_size)
{
	size_t		nn;
	size_t		old_size;
	size_t		old_cap_bytes;

	__attribute__((assume(vec->data != NULL && vec->head != NULL)));
	{
		old_size = ft_vec_bytesize(vec);
		old_cap_bytes = vec->capacity * type_size;
		if (old_size <= old_cap_bytes)
			return (1);
		nn = old_cap_bytes << 1;
		vec->data = ft_recalloc((void *)vec->data, old_cap_bytes, nn);
		if (vec->data == NULL)
			return (0);
		vec->head = (t_u8 *)vec->data + old_size;
		vec->capacity = nn / type_size;
		return (1);
	}
}

__attribute__((__nonnull__(1, 2)))
int	ft_vec_push_back(t_vec *restrict const vec,
		const t_u8 *restrict const data, size_t type_size)
{
	__attribute__((assume(vec->data != NULL && vec->head != NULL)));
	{
		if (!ft_vec_grow_one(vec, type_size))
			return (0);
		ft_memcpy(vec->head, data, type_size);
		vec->head += type_size;
		return (1);
	}
}
