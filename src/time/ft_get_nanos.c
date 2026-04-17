/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_nanos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 15:02:52 by jaicastr          #+#    #+#             */
/*   Updated: 2026/04/17 19:47:29 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "timing.h"

t_u64a	ft_get_nanos(void)
{
	struct timespec		ts;

	clock_gettime(CLOCK_MONOTONIC, &ts);
	return (((t_u64a)ts.tv_sec * 1000000000) + (t_u64a)ts.tv_nsec);
}
