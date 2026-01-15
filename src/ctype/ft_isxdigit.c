/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isxdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 00:46:25 by jaicastr          #+#    #+#             */
/*   Updated: 2026/01/15 09:18:41 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ctype.h"

__attribute__((const, __always_inline__, hot))
bool	ft_isxdigit(int c)
{
	return (ft_isdigit(c) || ((((t_u8)c | 32) - 'a') < 6));
}
