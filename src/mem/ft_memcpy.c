/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 22:55:19 by jaicastr          #+#    #+#             */
/*   Updated: 2026/02/19 21:01:55 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/ft_p_mem.h"

#if defined(__x86_64__) && defined(__AVX512VL__) && !defined(__LIBFT_PORTABLE__)

/*
 * see: ft_memcpy.S
 */

#elif defined(__AVX512VL__)

__attribute__((__nonnull__(1, 2)))
void	ft_memcpy(void *restrict dest,
	const void	*restrict const src, size_t n)
{
	if (n >= 512ULL)
		ft_memcpy_8x512(dest, src, n);
	else if (n >= 256ULL)
		ft_memcpy_8x256(dest, src, n);
	else if (n >= 128ULL)
		ft_memcpy_8x128(dest, src, n);
	else if (n >= 64ULL)
		ft_memcpy_8x64(dest, src, n);
	else
		ft_memcpy_naive(dest, src, n);
}

#elif defined(__AVX2__)

__attribute__((__nonnull__(1, 2)))
void	ft_memcpy(void *restrict dest,
	const void	*restrict const src, size_t n)
{
	if (n >= 512ULL)
		ft_memcpy_8x256(dest, src, n);
	else if (n >= 128ULL)
		ft_memcpy_8x128(dest, src, n);
	else if (n >= 64ULL)
		ft_memcpy_8x64(dest, src, n);
	else
		ft_memcpy_naive(dest, src, n);
}

#else

__attribute__((__nonnull__(1, 2)))
void	ft_memcpy(void *restrict dest,
	const void	*restrict const src, size_t n)
{
	if (n >= 128ULL)
		ft_memcpy_8x128(dest, src, n);
	else if (n >= 64ULL)
		ft_memcpy_8x64(dest, src, n);
	else
		ft_memcpy_naive(dest, src, n);
}

#endif
