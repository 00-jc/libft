/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:13:42 by jaicastr          #+#    #+#             */
/*   Updated: 2026/01/17 04:12:22 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

#if !defined(__LIBFT_SCALAR__)

/*
 *	like memcpy, this is for
 *	when we know the size of
 *	the buffer, if not use
 *	ft_set()
 */

__attribute__((__nonnull__(1)))
void	ft_memset(void *__restrict__ dest,
	const t_u8 b, size_t n)
{
	if (n >= 512ULL)
		ft_memset_8x512(dest, b, n);
	else if (n >= 256ULL)
		ft_memset_8x256(dest, b, n);
	else if (n >= 128ULL)
		ft_memset_8x128(dest, b, n);
	else if (n >= 64ULL)
		ft_memset_8x64(dest, b, n);
	else
		ft_memset_naive(dest, b, n);
}

#else

__attribute__((__nonnull__(1)))
void	ft_memset(void *__restrict__ dest,
	const t_u8 b, size_t n)
{
	ft_memset_8x64(dest, b, n);
}

#endif
