/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 01:17:24 by jaicastr          #+#    #+#             */
/*   Updated: 2026/01/17 02:52:26 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

__attribute__((warn_unused_result("Allocation occurs at vec initialization")))
t_str	ft_str_new(size_t n)
{
	return ((t_str)
		{
			.len = 0,
			.capacity = n,
			.data = ft_alloc(n),
		});
}

void	ft_str_free(t_str *s)
{
	ft_free((void **)&s->data);
	*s = (t_str){0};
}
