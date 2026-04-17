/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_nanos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 15:02:52 by jaicastr          #+#    #+#             */
/*   Updated: 2026/04/17 21:53:00 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "timing.h"

__attribute__((__always_inline__))
inline t_u64a	ft_get_nanos(void)
{
	struct timespec		ts;

	clock_gettime(CLOCK_MONOTONIC, &ts);
	return (((t_u64a)ts.tv_sec * 1000000000) + (t_u64a)ts.tv_nsec);
}
