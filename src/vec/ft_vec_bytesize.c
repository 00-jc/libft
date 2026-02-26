/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_bytesize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:29:11 by jaicastr          #+#    #+#             */
/*   Updated: 2026/01/19 04:38:34 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

__attribute__((__nonnull__(1), __always_inline__, pure))
inline size_t	ft_vec_bytesize(const t_vec *restrict const v)
{
	return ((t_uptr)v->head - (t_uptr)v->data);
}

__attribute__((__nonnull__(1), __always_inline__, pure))
inline size_t	ft_vec_len(const t_vec *restrict const v, size_t type_size)
{
	return (ft_vec_bytesize(v) / type_size);
}
