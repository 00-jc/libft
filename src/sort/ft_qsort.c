/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 22:35:18 by jaicastr          #+#    #+#             */
/*   Updated: 2026/04/20 01:39:17 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

__attribute__((__nonnull__(1, 2, 3), __always_inline__))
static inline void	ft__swap(t_u8 *a, t_u8 *b, t_u8 *buf, size_t size)
{
	ft_memcpy(buf, a, size);
	ft_memcpy(a, b, size);
	ft_memcpy(b, buf, size);
}

__attribute__((__nonnull__(1, 2), __always_inline__))
static inline ssize_t	ft_tailor_sort_internal(t_u8 *arr, t_qsort_ctx *c,
	ssize_t l, ssize_t h)
{
	t_u8		*pivot;
	ssize_t		i;
	ssize_t		j;

	pivot = arr + (size_t)l * c->size;
	i = l + 1;
	j = h;
	while (i <= j)
	{
		while (i <= h && c->cmp(arr + (size_t)i * c->size, pivot) <= 0)
			++i;
		while (j >= l && c->cmp(arr + (size_t)j * c->size, pivot) > 0)
			--j;
		if (i < j)
		{
			ft__swap(arr + (size_t)i * c->size,
				arr + (size_t)j * c->size, c->buf, c->size);
			++i;
			--j;
		}
	}
	ft__swap(arr + (size_t)l * c->size,
		arr + (size_t)j * c->size, c->buf, c->size);
	return (j);
}

__attribute__((__nonnull__(1, 2)))
void	ft_qsort(t_u8 *arr, t_qsort_ctx *c, size_t l, size_t h)
{
	ssize_t	p;

	if (l + 1 >= h || c->size == 0)
		return ;
	p = ft_tailor_sort_internal(arr, c, (ssize_t)l, (ssize_t)h - 1);
	if ((size_t)p > l)
		ft_qsort(arr, c, l, (size_t)p);
	ft_qsort(arr, c, (size_t)(p + 1), h);
}
