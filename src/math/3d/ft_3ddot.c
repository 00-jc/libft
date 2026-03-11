/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3ddot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 01:26:57 by jaicastr          #+#    #+#             */
/*   Updated: 2026/03/11 01:30:34 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/ft_p_math.h"
#include "math.h"

__attribute__((__always_inline__, const))
inline double	ft_3ddot(t_3dcoords a, t_3dcoords b)
{
	t_v4da	va;
	t_v4da	vb;

	va = *(const t_v4da * restrict const) & a;
	vb = *(const t_v4da * restrict const) & b;
	va *= vb;
	return (va[0] + va[1] + va[2]);
}
