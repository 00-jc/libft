/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3dunit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 01:14:50 by jaicastr          #+#    #+#             */
/*   Updated: 2026/03/11 01:23:01 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/ft_p_math.h"
#include "math.h"

__attribute__((__always_inline__, const))
inline t_3dcoords	ft_3dunit(t_3dcoords c)
{
	t_v4da		v1;
	t_v4da		v2;

	v1 = *(const t_v4da * restrict const ) & c;
	v2 = v1;
	v1 *= v1;
	v2 *= ft_drsqrt(v1[0] + v1[1] + v1[2]);
	return (*(const t_3dcoords * restrict const) & v2);
}
