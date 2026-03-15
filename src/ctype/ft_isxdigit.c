/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isxdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 00:46:25 by jaicastr          #+#    #+#             */
/*   Updated: 2026/03/15 14:56:32 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ctype.h"

__attribute__((const, __always_inline__, hot))
inline int	ft_isxdigit(int c)
{
	return ((unsigned)ft_isdigit(c)
		|| (((unsigned char)c | 32u) - (unsigned)'a' < 6u));
}
