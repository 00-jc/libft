/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 02:19:01 by jaicastr          #+#    #+#             */
/*   Updated: 2026/01/17 00:43:22 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cstr.h" 

#if !defined(__LIBFT_SCALAR__) && defined(__AVX512F__)

__attribute__((__always_inline__, const))
static inline size_t	handle_simd_tail(const t_u128a qw[4])
{
	t_u128a	segment;
	size_t	result;
	size_t	idx;

	idx = 0;
	segment = qw[idx];
	while (segment == 0)
		segment = qw[++idx];
	result = ft_memctz_u128(segment);
	return ((idx << 4) + (result >> 3));
}

__attribute__((__nonnull__(1)))
size_t	ft_strlen(const char *restrict str)
{
	t_uptr						a;
	t_vu512a					w;
	const t_u128a	*restrict	qw;
	t_u64						b64;
	const t_vu512a	*restrict	w_64;

	if (*str == 0)
		return (0);
	a = (t_uptr)str;
	while (*str && ((t_uptr)str & 63ULL))
		str++;
	w_64 = (t_vu512 *)str;
	while (1)
	{
		w = *((t_blk512ra)w_64);
		w = (((w) - get_lones512()) & (~w) & get_high512());
		qw = (const t_u128a * restrict const) & w;
		if (qw[0] || qw[1] || qw[2] || qw[3])
		{
			b64 = handle_simd_tail((const t_u128a * restrict const)qw);
			return (((t_uptr)w_64 + b64) - a);
		}
		++w_64;
	}
}

#else

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
		str++;
	w_64 = (const t_u64a *)str;
	while (1)
	{
		w = *((t_blk64r)w_64);
		w = (((w) - LONES_64) & (~w) & HIGHS_64);
		if (w)
		{
			w = ft_memctz_u64(w);
			return (((t_uptr)w_64 + (w >> 3)) - a);
		}
		++w_64;
	}
}

#endif
