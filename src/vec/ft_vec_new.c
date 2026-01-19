/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:23:57 by jaicastr          #+#    #+#             */
/*   Updated: 2026/01/19 04:38:34 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

__attribute__((warn_unused_result("Allocation occurs at vec initialization")))
t_vec	ft_vec_new(size_t size, size_t type_size)
{
	const t_u8	*mem;
	size_t		mul;

	mul = size * type_size;
	if (mul == 0 || (mul / size != type_size))
		return ((t_vec){0});
	mem = ft_alloc(size * type_size);
	return ((t_vec)
		{
			.head = (t_u8 *)mem,
			.capacity = size,
			.data = mem,
		});
}
