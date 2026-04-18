/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perf_create_counters.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 15:49:27 by jaicastr          #+#    #+#             */
/*   Updated: 2026/04/18 20:13:42 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/ft_p_perf.h"

__attribute__((const, __always_inline__))
static inline struct perf_event_attr	ft__getattr(t_u32a type, long conf)
{
	struct perf_event_attr	attr;

	ft_memset(&attr, 0, sizeof(attr));
	attr.read_format = PERF_FORMAT_TOTAL_TIME_ENABLED
		| PERF_FORMAT_TOTAL_TIME_RUNNING;
	attr.type = type;
	attr.inherit = 1;
	attr.inherit_thread = 1;
	attr.config = conf;
	attr.exclude_kernel = 1;
	attr.exclude_callchain_kernel = 1;
	attr.disabled = 1;
	attr.exclude_hv = 1;
	return (attr);
}

__attribute__((__nonnull__(1)))
static inline int	ft__init_hw(t_perf_counters c)
{
	size_t					i;
	struct perf_event_attr	attr;

	i = SW_COUNTERS_N;
	while (i < HW_COUNTERS_N + SW_COUNTERS_N)
	{
		attr = ft__getattr(PERF_TYPE_HARDWARE,
				get_hw_counters()[i - SW_COUNTERS_N]);
		c[i] = syscall(SYS_perf_event_open, &attr, 0, -1, -1,
				PERF_FLAG_FD_CLOEXEC);
		if (__builtin_expect(c[i] == -1, 0))
		{
			while (i)
				close((int)c[--i]);
			return (0);
		}
		++i;
	}
	return (1);
}

__attribute__((__nonnull__(1)))
static inline int	ft__init_sw(t_perf_counters c)
{
	size_t					i;
	struct perf_event_attr	attr;

	i = 0;
	while (i < SW_COUNTERS_N)
	{
		attr = ft__getattr(PERF_TYPE_SOFTWARE, get_sw_counters()[i]);
		c[i] = syscall(SYS_perf_event_open, &attr, 0, -1, -1,
				PERF_FLAG_FD_CLOEXEC);
		if (__builtin_expect(c[i] == -1, 0))
		{
			while (i)
				close((int)c[--i]);
			return (0);
		}
		++i;
	}
	return (1);
}

__attribute__((__nonnull__(1)))
int	ft_perf_create_counters(t_perf_counters c)
{
	if (__builtin_expect(ft__init_sw(c) == 0 || ft__init_hw(c) == 0, 0))
		return (0);
	return (1);
}
