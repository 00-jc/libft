/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memclone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:13:42 by jaicastr          #+#    #+#             */
/*   Updated: 2026/01/15 08:32:34 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

void	*ft_memclone(void *__restrict__ ptr, size_t size)
{
	void	*new_reg;

	if (!ptr || size == 0)
		return (NULL);
	new_reg = ft_alloc(size);
	if (!new_reg)
		return (NULL);
	ft_memmove(new_reg, ptr, size);
	return (new_reg);
}
