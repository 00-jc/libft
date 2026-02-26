/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_isblob.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 00:54:01 by jaicastr          #+#    #+#             */
/*   Updated: 2026/01/19 04:38:32 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cstr.h"

__attribute__((__nonnull__(1)))
int	ft_s_isblob(char *s)
{
	while (*s)
	{
		if (ft_isspace(*s) || !ft_isalnum(*s))
			return (0);
		s++;
	}
	return (1);
}
