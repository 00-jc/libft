/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 22:55:19 by jaicastr          #+#    #+#             */
/*   Updated: 2026/04/12 18:49:26 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/ft_p_mem.h"

#if defined(__AVX512VL__)

__attribute__((__nonnull__(1, 2)))
void	ft_memcpy(void *restrict dest,
	const void	*restrict const src, size_t n)
{
	if (n >= 64)
		ft_memcpy_512(dest, src, n);
	else if (n >= 32)
		ft_memcpy_256(dest, src, n);
	else if (n >= 16)
		ft_memcpy_128(dest, src, n);
	else if (n >= 8)
		ft_memcpy_64(dest, src, n);
	else
		ft_memcpy_naive(dest, src, n);
}

#elif defined(__AVX2__)

__attribute__((__nonnull__(1, 2)))
void	ft_memcpy(void *restrict dest,
	const void	*restrict const src, size_t n)
{
	if (n >= 32)
		ft_memcpy_256(dest, src, n);
	else if (n >= 16)
		ft_memcpy_128(dest, src, n);
	else if (n >= 8)
		ft_memcpy_64(dest, src, n);
	else
		ft_memcpy_naive(dest, src, n);
}

#else

__attribute__((__nonnull__(1, 2)))
void	ft_memcpy(void *restrict dest,
	const void	*restrict const src, size_t n)
{
	if (n >= 16)
		ft_memcpy_128(dest, src, n);
	else if (n >= 8)
		ft_memcpy_64(dest, src, n);
	else
		ft_memcpy_naive(dest, src, n);
}

#endif
