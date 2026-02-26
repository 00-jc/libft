/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_remove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 22:33:53 by jaicastr          #+#    #+#             */
/*   Updated: 2026/01/19 04:38:34 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

__attribute__((nonnull(1)))
int	ft_str_remove(t_str *str, size_t idx)
{
	if (idx >= str->len)
		return (0);
	ft_memcpy(str->data + idx, str->data + idx + 1,
		str->len - idx - 1);
	str->data[--str->len] = 0;
	return (1);
}
