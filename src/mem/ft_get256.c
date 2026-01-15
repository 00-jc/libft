/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get258.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 00:10:36 by jaicastr          #+#    #+#             */
/*   Updated: 2026/01/15 03:53:12 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

#ifndef __LIBFT_SCALAR__

__attribute__((const, __always_inline__))
t_vu256	get_high256(void)
{
	return ((t_vu256)
		{
			0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
			0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
			0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
			0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
		});
}

__attribute__((const, __always_inline__))
t_vu256	get_lones256(void)
{
	return ((t_vu256)
		{
			0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
			0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
			0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
			0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
		});
}

__attribute__((const, __always_inline__))
t_vu256	get_z256(void)
{
	return ((t_vu256)
		{
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		});
}

__attribute__((const, __always_inline__))
t_vu256	get_mask256(t_u8 x)
{
	return ((t_vu256)
		{
			x, x, x, x, x, x, x, x,
			x, x, x, x, x, x, x, x,
			x, x, x, x, x, x, x, x,
			x, x, x, x, x, x, x, x,
		});
}

#endif
