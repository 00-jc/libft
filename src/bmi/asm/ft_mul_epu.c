/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mul_epu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 04:45:33 by jaicastr          #+#    #+#             */
/*   Updated: 2026/04/12 07:16:27 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bmi.h"

#define MASK 0x00000000FFFFFFFF

__attribute__((const, __always_inline__))
inline t_512bits	ft_mul_epu512(t_512bits a, t_512bits b)
{
	t_vu64_512a	rr[3];

	rr[0] = *(t_vu64_512 *) & a;
	rr[1] = *(t_vu64_512 *) & b;
	rr[2] = (rr[0] & MASK) * (rr[1] & MASK);
	return (*(t_512bits *) & rr[2]);
}
