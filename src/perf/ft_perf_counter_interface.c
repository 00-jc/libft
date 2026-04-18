/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perf_counter_interface.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 17:38:05 by jaicastr          #+#    #+#             */
/*   Updated: 2026/04/18 20:13:44 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/ft_p_perf.h"

__attribute__((__nonnull__(1), __always_inline__))
inline void	ft_perf_counters_start(t_perf_counters __attribute__((unused)) c)
{
	prctl(PR_TASK_PERF_EVENTS_ENABLE);
}

__attribute__((__nonnull__(1), __always_inline__))
inline void	ft_perf_counters_stop(t_perf_counters __attribute__((unused)) c)
{
	prctl(PR_TASK_PERF_EVENTS_DISABLE);
}

__attribute__((__nonnull__(1), __always_inline__))
inline void	ft_perf_counters_reset(t_perf_counters c)
{
	size_t	i;

	i = 0;
	while (i < HW_COUNTERS_N + SW_COUNTERS_N)
		ioctl((int)c[i++], PERF_EVENT_IOC_RESET, 0);
}
