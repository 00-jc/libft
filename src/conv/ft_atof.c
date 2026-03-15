/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:13:42 by jaicastr          #+#    #+#             */
/*   Updated: 2026/03/15 15:35:59 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conv.h"

__attribute__((const, __always_inline__, __nonnull__(1)))
static inline float	__eat_decimal(const char *s)
{
	float	c;
	float	out;

	c = 0.1f;
	out = 0;
	while (*s && (*s >= '0' && *s <= '9'))
	{
		out += c * (float)(*s++ - '0');
		c *= 0.1f;
	}
	return (out);
}

__attribute__((pure, __nonnull__(1)))
float	ft_atof(const char *s)
{
	int		neg;
	float	out;

	out = 0;
	neg = 1;
	if (*s == '-')
	{
		neg = -1;
		s++;
	}
	else if (*s == '+')
		s++;
	while (*s && *s != '.' && (*s >= '0' && *s <= '9'))
		out = (out * 10) + (float)(*s++ - '0');
	if (*s == '.')
		s++;
	out += __eat_decimal(s);
	return (out * (float)neg);
}
