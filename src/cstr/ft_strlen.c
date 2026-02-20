/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 02:19:01 by jaicastr          #+#    #+#             */
/*   Updated: 2026/02/20 19:41:38 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/ft_p_bmi.h"
#include "cstr.h"

#if !defined(__AVX512VL__) || !defined(__x86_64__) ||\
	defined(__LIBFT_PORTABLE__)

__attribute__((__nonnull__(1)))
size_t	ft_strlen(const char *restrict str)
{
	t_uptr						a;
	t_u16a						w;
	size_t						offst;
	const t_vu128a	*restrict	wp;
	t_vu128a					mask;

	a = (t_uptr)str;
	while (*str && ((t_uptr)str & 7))
		++str;
	if (!*str)
		return ((t_uptr)str - (t_uptr)a);
	wp = (t_blk128r)str;
	while (1)
	{
		mask = __hasz128(((t_blk128ra)wp)[0]) == get_high128();
		w = ft_bitpack128(mask);
		if (w)
		{
			offst = ft_memctz_u16(w);
			return (((t_uptr)wp + offst) - a);
		}
		++wp;
	}
}

#endif
