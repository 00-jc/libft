/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:13:42 by jaicastr          #+#    #+#             */
/*   Updated: 2026/01/15 10:11:44 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

__attribute__((__nonnull__(1, 2)))
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	t_u8					*bd;
	const t_u8	*restrict	bs;

	if ((dest == src) && n != 0)
		return (NULL);
	if ((t_uptr)src < (t_uptr)dest
		&& (t_uptr)src + n >= (t_uptr)dest)
	{
		bd = (t_u8 *)dest + n;
		bs = (t_u8 *)src + n;
		while (n-- > 0)
			*--bd = *--bs;
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
