/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:13:41 by jaicastr          #+#    #+#             */
/*   Updated: 2026/01/19 04:38:32 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cstr.h"

__attribute__((__nonnull__(1, 2)))
int	ft_strcmp(const char *a, const char *b)
{
	size_t	c;

	c = 0;
	while (a[c] && b[c])
	{
		if (a[c] != b[c])
			return (a[c] - b[c]);
		c++;
	}
	return (a[c] - b[c]);
}
