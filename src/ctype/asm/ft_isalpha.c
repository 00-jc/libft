/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:13:41 by jaicastr          #+#    #+#             */
/*   Updated: 2026/02/22 19:30:06 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/ft_p_ctype.h"

__attribute__((const, __always_inline__, hot))
t_u16a	ft_isalpha128(t_vu128a c)
{
	return (ft_bitpack128(((c | 32) - 'a') < 26u));
}

#ifdef __AVX2__

__attribute__((const, __always_inline__, hot))
t_u32a	ft_isalpha256(t_vu256a c)
{
	return (ft_bitpack256(((c | 32) - 'a') < 26u));
}

#endif

#ifdef __AVX512F__

__attribute__((const, __always_inline__, hot))
t_u64a	ft_isalpha512(t_vu512a c)
{
	return (ft_bitpack512(((c | 32) - 'a') < 26u));
}

#endif
