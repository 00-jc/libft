/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mosb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 00:01:18 by jaicastr          #+#    #+#             */
/*   Updated: 2026/04/17 01:59:22 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/ft_p_mem.h"

#ifdef __x86_64__

__attribute__((__nonnull__(1, 2), __always_inline__))
inline void	ft_movsb(void *restrict dest,
	const void	*restrict const src, size_t n)
{
	__asm__ volatile (
		"rep movsb"
		: "+D"(dest), "+c"(n)
		: "S"(src)
		: "memory"
	);
}

#else

__attribute__((__nonnull__(1, 2), __always_inline__))
inline void	ft_movsb(void *restrict dest,
	const void	*restrict const src, size_t n)
{
	ft_memcpy_naive(dest, src, n);
}

#endif
