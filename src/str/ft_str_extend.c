/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_extend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 01:34:34 by jaicastr          #+#    #+#             */
/*   Updated: 2026/01/19 04:38:34 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

__attribute__((__nonnull__(1)))
int	ft_str_extend(t_str *restrict str,
		const t_u8 *restrict const data, size_t n)
{
	size_t	newcap;
	t_str	s;

	s = *str;
	if (s.len + n + 1 == s.capacity)
	{
		newcap = __max_s(s.capacity << 1, s.capacity + n);
		s.data = ft_recalloc(s.data, s.capacity, newcap);
		if (s.data == NULL)
			return (0);
		s.capacity = newcap;
	}
	ft_memcpy(s.data + s.len, data, n + 1);
	s.len += n + 1;
	*str = s;
	return (1);
}
