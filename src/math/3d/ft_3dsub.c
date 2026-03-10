/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3dsub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 16:33:17 by jaicastr          #+#    #+#             */
/*   Updated: 2026/03/10 16:38:13 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/ft_p_math.h"
#include "math.h"

__attribute__((__always_inline__, const))
inline t_3DCoords	ft_3dsub(t_3DCoords a, t_3DCoords b)
{
	t_v4da	vec;

	vec = *(t_v4da * restrict const) & a - *(t_v4da * restrict const) & b;
	return (*(t_4packd * restrict const) & vec);
}
