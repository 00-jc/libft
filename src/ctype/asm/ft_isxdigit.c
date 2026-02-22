/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isxdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 00:46:25 by jaicastr          #+#    #+#             */
/*   Updated: 2026/02/21 18:01:17 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/ft_p_ctype.h"

__attribute__((const, __always_inline__, hot))
t_u16a	ft_isxdigit128(t_vu128a c)
{
	return (ft_isdigit128(c) | ft_bitpack128((((c | 32) - 'a') < 6)));
}

#ifdef __AVX2__

__attribute__((const, __always_inline__, hot))
t_u32a	ft_isxdigit256(t_vu256a c)
{
	return (ft_isdigit256(c) | ft_bitpack256((((c | 32) - 'a') < 6)));
}

#endif

#ifdef __AVX512F__

__attribute__((const, __always_inline__, hot))
t_u64a	ft_isxdigit512(t_vu512a c)
{
	return (ft_isdigit512(c) | ft_bitpack512((((c | 32) - 'a') < 6)));
}

#endif
