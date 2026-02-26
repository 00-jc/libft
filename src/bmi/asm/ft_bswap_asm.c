/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bswap_asm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 18:10:00 by jaicastr          #+#    #+#             */
/*   Updated: 2026/02/19 21:16:35 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bmi.h"

#ifdef __x86_64__

__attribute__((__always_inline__))
inline t_u16a	ft_bswap16(t_u16a x)
{
	t_u16a	new;

	__asm__ volatile (
		"xchg %b0, %h0"
		: "=Q"(new)
		: "0"(x)
	);
	return (new);
}

__attribute__((__always_inline__))
inline t_u32a	ft_bswap32(t_u32a x)
{
	t_u32a	new;

	__asm__ volatile (
		"bswap %k0"
		: "=r"(new)
		: "0"(x)
	);
	return (new);
}

__attribute__((__always_inline__))
inline t_u64a	ft_bswap64(t_u64a x)
{
	t_u64a	new;

	__asm__ volatile (
		"bswap %q0"
		: "=r"(new)
		: "0"(x)
	);
	return (new);
}

#endif
