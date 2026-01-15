/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 16:14:35 by jaicastr          #+#    #+#             */
/*   Updated: 2026/01/15 16:58:44 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

__attribute__((__nonnull__(1)))
void	ft_vec_free(t_vec *v)
{
	ft_free((void **)&v->data);
	*v = (t_vec){0};
}

__attribute__((__nonnull__(1), __always_inline__))
void	ft_vec_clear(t_vec *restrict const v)
{
	v->head = (t_u8 *)v->data;
}
