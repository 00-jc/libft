/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:13:41 by jaicastr          #+#    #+#             */
/*   Updated: 2026/02/17 18:07:03 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alloc.h"

__attribute__((__nonnull__(1)))
void	ft_free(void **ptr)
{
	if (!*ptr)
		return ;
	free(((void **)*ptr)[-1]);
	*ptr = NULL;
}

__attribute__((__nonnull__(1)))
void	ft_free_array(void ***arr)
{
	size_t	i;

	if (!*arr)
		return ;
	i = 0;
	while ((*arr)[i])
		ft_free(&((*arr)[i++]));
	ft_free((void **)arr);
}
