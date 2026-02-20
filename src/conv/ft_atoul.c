/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoul.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:13:42 by jaicastr          #+#    #+#             */
/*   Updated: 2026/02/19 03:37:09 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lft.h"

__attribute__((__nonnull__(1)))
size_t	ft_atoul(const char *restrict const str)
{
	size_t		out;
	size_t		i;

	out = 0;
	i = 0;
	while (ft_isspace(str[i]))
		++i;
	if (str[i] == '+')
		++i;
	while (str[i] && ft_isdigit(str[i]))
	{
		out = (out << 1) + (out << 3)
			+ ((size_t)str[i++] - '0');
	}
	return (out);
}
