/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:13:41 by jaicastr          #+#    #+#             */
/*   Updated: 2026/02/23 17:12:36 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ctype.h"

__attribute__((const, __always_inline__, hot))
inline int	ft_isspace(int c)
{
	return ((c == 0x20) | ((c - 0x09) < 0x05));
}
