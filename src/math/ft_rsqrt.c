/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rsqrt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 04:38:46 by jaicastr          #+#    #+#             */
/*   Updated: 2026/02/24 03:19:42 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"

#ifdef __x86_64__

__attribute__((__always_inline__, const))
inline float	ft_rsqrt(float number)
{
	__asm__("rsqrtss %1, %0" : "=x"(number) : "x"(number));
	return (number);
}

__attribute__ ((__always_inline__, const))
inline double	ft_drsqrt(double number)
{
	t_u64a	i;
	double	x2;
	double	y;
	double	threehalfs;

	threehalfs = 1.5;
	x2 = number * 0.5;
	y = number;
	i = (t_dp){.f = y}.i;
	i = 0x5FE6EC85E7DE30DA - (i >> 1);
	y = (t_dp){.i = i}.f;
	y = y * (threehalfs - (x2 * y * y));
	y = y * (threehalfs - (x2 * y * y));
	return (y);
}

#else

__attribute__ ((__always_inline__, const))
inline float	ft_rsqrt(float number)
{
	t_u32a		i;
	float		x2;
	float		y;
	float		threehalfs;

	threehalfs = 1.5F;
	x2 = number * 0.5F;
	y = number;
	i = (t_fp){.f = y}.i;
	i = 0x5F3759DF - (i >> 1);
	y = (t_fp){.i = i}.f;
	y = y * (threehalfs - (x2 * y * y));
	y = y * (threehalfs - (x2 * y * y));
	return (y);
}

__attribute__ ((__always_inline__, const))
inline double	ft_drsqrt(double number)
{
	t_u64a	i;
	double	x2;
	double	y;
	double	threehalfs;

	threehalfs = 1.5;
	x2 = number * 0.5;
	y = number;
	i = (t_dp){.f = y}.i;
	i = 0x5FE6EC85E7DE30DA - (i >> 1);
	y = (t_dp){.i = i}.f;
	y = y * (threehalfs - (x2 * y * y));
	y = y * (threehalfs - (x2 * y * y));
	return (y);
}

#endif
