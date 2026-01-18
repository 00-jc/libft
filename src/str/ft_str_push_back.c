/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_push_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:32:14 by jaicastr          #+#    #+#             */
/*   Updated: 2026/01/18 09:48:23 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

__attribute__((__nonnull__(1)))
int	ft_str_push_back(t_str *restrict str, const t_u8 byte)
{
	size_t	newcap;
	t_str	s;

	s = *str;
	if (s.len + 1 == s.capacity)
	{
		newcap = s.capacity << 1;
		s.data = ft_recalloc(s.data, s.capacity, newcap);
		if (s.data == NULL)
			return (0);
		s.capacity = newcap;
	}
	s.data[s.len++] = byte;
	s.data[s.len] = 0;
	*str = s;
	return (1);
}
