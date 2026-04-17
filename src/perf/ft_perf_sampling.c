/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perf_sampling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 21:34:52 by jaicastr          #+#    #+#             */
/*   Updated: 2026/04/17 21:54:33 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/ft_p_perf.h"

__attribute__((__nonnull__(1, 2)))
void	ft_perf_start_sample(t_perf_counters c, t_perf_sample *t)
{
	ft_perf_counters_reset(c);
	ft_perf_counters_start(c);
	t->ns = ft_get_nanos();
}

__attribute__((__nonnull__(2, 3)))
int	ft_perf_collect_sample(size_t n,
	t_perf_counters c, t_perf_sample *s)
{
	t_u64	v[SW_COUNTERS_N + HW_COUNTERS_N];
	t_u64a	t;
	size_t	i;

	t = ft_get_nanos();
	ft_perf_counters_stop(c);
	i = 0;
	while (i < SW_COUNTERS_N + HW_COUNTERS_N)
	{
		if (__builtin_expect(read((int)c[i],
					&v[i], sizeof(t_u64)) == -1, 0))
			return (0);
		++i;
	}
	s->n = n;
	s->ns = t - s->ns;
	s->alignment_faults = v[1];
	s->page_faults = v[2];
	s->cycles = v[3];
	s->instr = v[4];
	s->cache_ll = v[5];
	s->cache_miss = v[6];
	s->branches = v[7];
	s->branch_miss = v[8];
	return (1);
}
