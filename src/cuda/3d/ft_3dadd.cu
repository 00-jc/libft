/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3dadd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 16:33:17 by jaicastr          #+#    #+#             */
/*   Updated: 2026/04/11 19:47:11 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/ft_p_math.h"

__device__ __forceinline__ __constant__
t_3dcoords	ft_cu3dadd(t_3dcoords a, t_3dcoords b)
{
	return ((t_3dcoords){a.x + b.x, a.y + b.y, a.z + b.z, 0});
}
