/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow_signed.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:13:41 by jaicastr          #+#    #+#             */
/*   Updated: 2026/01/14 04:31:18 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"

__attribute__((__always_inline__, const))
int	ft_ipow(int x, t_u64 n)
{
	int	res;

	res = 1;
	while (n)
	{
		if ((n & 1) == 1)
			res *= x;
		x *= x;
		n >>= 1;
	}
	return (res);
}

__attribute__((__always_inline__, const))
long long	ft_lpow(long long x, t_u64 n)
{
	long long	res;

	res = 1;
	while (n)
	{
		if ((n & 1) == 1)
			res *= x;
		x *= x;
		n >>= 1;
	}
	return (res);
}

__attribute__((__always_inline__, const))
float	ft_fpow(float x, t_u64 n)
{
	float	res;

	res = 1;
	while (n)
	{
		if ((n & 1) == 1)
			res *= x;
		x *= x;
		n >>= 1;
	}
	return (res);
}

__attribute__((__always_inline__, const))
double	ft_dpow(double x, t_u64 n)
{
	double	res;

	res = 1.0;
	while (n)
	{
		if ((n & 1) == 1)
			res *= x;
		x *= x;
		n >>= 1;
	}
	return (res);
}
