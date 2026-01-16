/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 22:55:19 by jaicastr          #+#    #+#             */
/*   Updated: 2026/01/16 23:06:02 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

#if !defined(__LIBFT_SCALAR__) && !defined(__AVX512F__)

__attribute__((__nonnull__(1, 2)))
void	ft_memcpy(void *__restrict__ dest,
	const void	*__restrict__ const src, size_t n)
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

#elif !defined(__LIBFT_SCALAR__) && defined(__AVX512F__)

__attribute__((__nonnull__(1, 2)))
void	ft_memcpy(void *__restrict__ dest,
	const void	*__restrict__ const src, size_t n)
{
	if (__builtin_constant_p(n))
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
	else
		ft_cpy(dest, src, n);
	
}

#else

__attribute__((__nonnull__(1, 2)))
void	ft_memcpy(void *__restrict__ dest,
	const void	*__restrict__ const src, size_t n)
{
	ft_memcpy_8x64(dest, src, n);
}

#endif
