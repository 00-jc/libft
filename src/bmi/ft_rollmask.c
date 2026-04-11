/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rollmask.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 01:40:13 by jaicastr          #+#    #+#             */
/*   Updated: 2026/04/12 01:45:05 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bmi.h"

__attribute__((const, __always_inline__))
inline size_t	ft_roll_mask(size_t chunk_size, size_t n)
{
	return (-1ULL << (chunk_size - n));
}
