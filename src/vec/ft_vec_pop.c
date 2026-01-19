/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_pop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:50:40 by jaicastr          #+#    #+#             */
/*   Updated: 2026/01/19 04:38:34 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

__attribute__((__always_inline__, __nonnull__(1)))
int	ft_vec_pop(t_vec *restrict const v, size_t type_size)
{
	t_uptr	prev;

	prev = (t_uptr)v->head;
	v->head = (t_u8 *)((((v->data != v->head) * ((t_uptr)v->head - type_size))
				| (v->data == v->head) * prev));
	return ((t_uptr)v->head != prev);
}

__attribute__((__always_inline__, __nonnull__(1)))
int	ft_vec_popmv(t_vec *restrict const v, void *const dest, size_t type_size)
{
	t_u8	*last;

	last = ft_vec_get_last(v, type_size);
	if (!last)
		return (0);
	ft_memcpy(dest, last, type_size);
	return (ft_vec_pop(v, type_size));
}

__attribute__((__always_inline__, __nonnull__(1)))
int	ft_vec_popf(t_vec *restrict const v, size_t type_size, void (*f)(void *))
{
	t_u8	*last;

	last = ft_vec_get_last(v, type_size);
	if (last)
	{
		f(last);
		return (ft_vec_pop(v, type_size));
	}
	return (0);
}
