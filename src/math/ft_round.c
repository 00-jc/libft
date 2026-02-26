/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:13:42 by jaicastr          #+#    #+#             */
/*   Updated: 2026/01/19 04:38:34 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"

__attribute__((__always_inline__, const))
inline float	ft_floorf(float x)
{
	long long	i;

	i = (long long)x;
	return ((float)(((i > x) * (i - 1)) | ((i <= x) * i)));
}

__attribute__((__always_inline__, const))
inline float	ft_ceilf(float x)
{
	long long	i;

	i = (long long)x;
	return ((float)(((i > x) * (i + 1)) | ((i <= x) * i)));
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
	return ((ft_floorf(x * p10 + offset) * (1 - sign)
			+ ft_ceilf(x * p10 + offset) * sign) / p10);
}

__attribute__((__always_inline__, const))
inline float	ft_roundff(float x)
{
	return ((float)((x >= 0.0f) * (int)(x + 0.5f)
				| (x < 0.0f) * (int)(x - 0.5f)));
}
