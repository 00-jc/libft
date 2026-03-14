/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3dmul.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 16:33:17 by jaicastr          #+#    #+#             */
/*   Updated: 2026/03/14 16:25:44 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/ft_p_math.h"
#include "math.h"

__attribute__((__always_inline__, const))
inline t_3dcoordsx8	ft_3dmul8(t_3dcoordsx8 a, t_3dcoordsx8 b)
{
	t_v8da	vec[4];

	vec[0] = *(t_v8da * restrict const) & a.a
		* *(t_v8da * restrict const) & b.a;
	vec[1] = *(t_v8da * restrict const) & a.c
		* *(t_v8da * restrict const) & b.c;
	vec[2] = *(t_v8da * restrict const) & a.e
		* *(t_v8da * restrict const) & b.e;
	vec[3] = *(t_v8da * restrict const) & a.g
		* *(t_v8da * restrict const) & b.g;
	return (*(const t_3dcoordsx8 * restrict const) & vec);
}

__attribute__((__always_inline__, const))
inline t_3dcoords	ft_3dmul(t_3dcoords a, t_3dcoords b)
{
	t_v4da	vec;

	vec = *(t_v4da * restrict const) & a * *(t_v4da * restrict const) & b;
	return (*(t_4packd * restrict const) & vec);
}
