/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:13:41 by jaicastr          #+#    #+#             */
/*   Updated: 2026/02/21 17:47:11 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/ft_p_ctype.h"

__attribute__((const, __always_inline__, hot))
t_u16a	ft_isdigit128(t_vu128a c)
{
	return (ft_bitpack128((c - '0') < 0xA));
}

#ifdef __AVX2__

__attribute__((const, __always_inline__, hot))
t_u32a	ft_isdigit256(t_vu256a c)
{
	return (ft_bitpack256((c - '0') < 0xA));
}

#endif

#ifdef __AVX512F__

__attribute__((const, __always_inline__, hot))
t_u64a	ft_isdigit512(t_vu512a c)
{
	return (ft_bitpack512((c - '0') < 0xA));
}

#endif
