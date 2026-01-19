/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 02:19:01 by jaicastr          #+#    #+#             */
/*   Updated: 2026/01/19 05:59:20 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cstr.h"
#include "lft_private.h"

#if !defined(__AVX512VL__) || !defined(__x86_64__) || defined(__LIBFT_SCALAR__)

__attribute__((__nonnull__(1)))
size_t	ft_strlen(const char *restrict str)
{
	t_uptr						a;
	t_u64a						w;
	const t_u64a	*restrict	w_64;

	if (*str == 0)
		return (0);
	a = (t_uptr)str;
	while (*str && ((t_uptr)str & 7))
		++str;
	w_64 = (const t_u64a *)str;
	while (1)
	{
		w = __hasz64(*((t_blk64ra)w_64));
		if (w)
		{
			w = ft_memctz_u64(w);
			return (((t_uptr)w_64 + (w >> 3)) - a);
		}
		++w_64;
	}
}

#endif
