/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __hasz.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 04:05:57 by jaicastr          #+#    #+#             */
/*   Updated: 2026/02/20 04:33:41 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

__attribute__((__always_inline__))
inline t_u64	__hasz64(t_u64 x)
{
	return (((x)-LONES_64) & (~x) & HIGHS_64);
}

__attribute__((__always_inline__))
inline t_u128	__hasz128(t_u128 x)
{
	t_u64	low_part;
	t_u64	high_part;

	high_part = (t_u64)(x >> 64);
	low_part = (t_u64)x;
	return (__hasz64 (low_part)
		| ((t_u128)__hasz64 (high_part) << 64));
}
