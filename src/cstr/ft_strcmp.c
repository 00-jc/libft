/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:13:41 by jaicastr          #+#    #+#             */
/*   Updated: 2026/01/14 02:10:11 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cstr.h"

int	ft_strcmp(const char *a, const char *b)
{
	size_t	c;

	if ((!a && b) || (a && !b))
		return (-1);
	if (!a && !b)
		return (0);
	c = 0;
	while (a[c] && b[c])
	{
		if (a[c] != b[c])
			return (a[c] - b[c]);
		c++;
	}
	return (a[c] - b[c]);
}
