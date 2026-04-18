/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perf_counter_interface.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 17:38:05 by jaicastr          #+#    #+#             */
/*   Updated: 2026/04/18 20:41:30 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/ft_p_perf.h"

__attribute__((__nonnull__(1), __always_inline__))
inline void	ft_perf_counters_start(t_perf_counters __attribute__((unused)) c)
{
	ioctl((int)c[0], PERF_EVENT_IOC_ENABLE, 0);
}

__attribute__((__nonnull__(1), __always_inline__))
inline void	ft_perf_counters_stop(t_perf_counters __attribute__((unused)) c)
{
	ioctl((int)c[0], PERF_EVENT_IOC_DISABLE, 0);
}

__attribute__((__nonnull__(1), __always_inline__))
inline void	ft_perf_counters_reset(t_perf_counters c)
{
	ioctl((int)c[0], PERF_EVENT_IOC_RESET, 0);
}
