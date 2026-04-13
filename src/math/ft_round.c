/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:13:42 by jaicastr          #+#    #+#             */
/*   Updated: 2026/04/13 19:02:16 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"

__attribute__((__always_inline__, const))
inline float	ft_floorf(float x)
{
	long long	i;
	long long	cnd;

	i = (long long)x;
	cnd = (float)i > x;
	return ((float)(((cnd & (i - 1))
			| (~cnd & i))));
}

__attribute__((__always_inline__, const))
inline float	ft_ceilf(float x)
{
	long long	i;
	long long	cnd;

	i = (long long)x;
	cnd = (float)i < x;
	return ((float)(((cnd & (i + 1))
			| (~cnd & i))));
}

__attribute__((__always_inline__, const))
inline float	ft_roundf(float x, t_u8 n)
{
	float	p10;
	int		sign;
	float	offset;

	if (n > 7)
		n = 7;
	p10 = 0.1f;
	while (n--)
		p10 *= 10.0f;
	sign = (x < 0);
	offset = 0.5f - (float)sign;
	return ((ft_floorf(x * p10 + offset) * (float)(1 - sign)
		+ ft_ceilf(x * p10 + offset) * (float)sign) / p10);
}

__attribute__((__always_inline__, const))
inline float	ft_roundff(float x)
{
	return ((float)((x >= 0.0f) * (int)(x + 0.5f)
				| (x < 0.0f) * (int)(x - 0.5f)));
}
