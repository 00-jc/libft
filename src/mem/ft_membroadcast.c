/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_membroadcast.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:13:42 by jaicastr          #+#    #+#             */
/*   Updated: 2026/01/15 10:11:20 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

__attribute__((__nonnull__(1, 2)))
void	ft_membroadcast(void *dst, void *src, size_t chunk_size, size_t n)
{
	t_u8	*d;

	if (!chunk_size || !n)
		return ;
	d = (t_u8 *)dst;
	while (n-- > 0)
	{
		ft_memcpy(d, src, chunk_size);
		d += chunk_size;
	}
}
