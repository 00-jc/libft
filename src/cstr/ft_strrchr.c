/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:13:41 by jaicastr          #+#    #+#             */
/*   Updated: 2026/01/15 10:23:59 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cstr.h"

__attribute__((__nonnull__(1)))
char	*ft_strrchr(const char *haystack, int needle)
{
	t_u8	*l_o;
	size_t	s;

	l_o = NULL;
	s = ft_strlen(haystack);
	if (needle == '\0')
		return ((char *)&(haystack[s]));
	while (s--)
		if (haystack[s] == (char)needle)
			return ((char *)&(haystack[s]));
	return ((char *)l_o);
}
