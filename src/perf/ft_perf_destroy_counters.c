/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perf_destroy_counters.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 19:55:48 by jaicastr          #+#    #+#             */
/*   Updated: 2026/04/17 20:29:06 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/ft_p_perf.h"

__attribute__((__nonnull__(1)))
void	ft_perf_destroy_counters(t_perf_counters c)
{
	size_t	i;

	i = 0;
	while (i < HW_COUNTERS_N + SW_COUNTERS_N)
		close((int)c[i++]);
}
