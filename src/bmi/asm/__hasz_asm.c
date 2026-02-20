/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __hasz_asm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 15:36:41 by jaicastr          #+#    #+#             */
/*   Updated: 2026/02/20 19:38:15 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/ft_p_bmi.h"

#ifdef __AVX2__

__attribute__((__always_inline__))
t_vu128	__hasz128(t_vu128 x)
{
	return ((x - get_lones128()) & ~x & get_high128());
}

__attribute__((__always_inline__))
t_vu256a	__hasz256(t_vu256a x)
{
	return ((x - get_lones256()) & ~x & get_high256());
}

#endif

#ifdef __AVX512F__

__attribute__((__always_inline__))
t_vu512a	__hasz512(t_vu512a x)
{
	return ((x - get_lones512()) & ~x & get_high512());
}

#endif
