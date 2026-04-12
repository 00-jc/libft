/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xxh3_xorshift.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 07:28:14 by jaicastr          #+#    #+#             */
/*   Updated: 2026/04/12 07:32:59 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/ft_p_xxh3.h"

__attribute__((__always_inline__, const))
inline t_u64a	ft_xxh3_xorshift64(t_u64a x, int shift)
{
	__attribute__((assume(0 <= shift && shift < 64)));
	return (x ^ (x >> shift));
}
