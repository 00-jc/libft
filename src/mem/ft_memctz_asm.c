/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memctz_asm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 02:10:01 by jaicastr          #+#    #+#             */
/*   Updated: 2026/01/16 05:26:25 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

#ifdef __BMI__

__attribute__((hot, const, __always_inline__))
inline t_u8	ft_memctz_u32(t_u32 x)
{
	__asm__("tzcnt %1, %0" : "=r"(x) : "r"(x));
	return ((t_u8)x);
}

__attribute__((hot, const, __always_inline__))
inline t_u8	ft_memctz_u64(t_u64 x)
{
	__asm__("tzcnt %1, %0" : "=r"(x) : "r"(x));
	return ((t_u8)x);
}

__attribute__((hot, const, __always_inline__))
inline t_u8	ft_memctz_u128(t_u128 x)
{
	t_u64	low;
	t_u64	high;

	low = (t_u64)x;
	high = (t_u64)(x >> 64);
	__asm__("tzcnt %1, %0" : "=r"(low) : "r"(low));
	__asm__("tzcnt %1, %0" : "=r"(high) : "r"(high));
    return ((t_u8)(low + ((low >> 6) & high)));
}

#endif
