/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perf_sampling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 21:34:52 by jaicastr          #+#    #+#             */
/*   Updated: 2026/04/18 20:17:10 by jaicastr         ###   ########.fr       */
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

__attribute__((__nonnull__(1, 2), __always_inline__))
static inline int	ft__get_sample_plexed(t_perf_counters c, t_u64 *v)
{
	size_t			i;
	t_perf_timing	t;

	i = 0;
	while (i < SW_COUNTERS_N + HW_COUNTERS_N)
	{
		if (__builtin_expect(read((int)c[i],
					&t, sizeof(t)) == -1, 0))
			return (0);
		else if (__builtin_expect(t.running == 0, 0))
			v[i] = 0;
		else if (t.running == t.enabled)
			v[i] = t.val;
		else
			v[i] = (t_u64)((double)t.val * (double)t.enabled
					/ (double)t.running);
		++i;
	}
	return (1);
}

__attribute__((__nonnull__(2, 3)))
int	ft_perf_collect_sample(size_t n,
	t_perf_counters c, t_perf_sample *s)
{
	t_u64a	v[SW_COUNTERS_N + HW_COUNTERS_N];
	t_u64a	t;

	t = ft_get_nanos();
	ft_perf_counters_stop(c);
	if (__builtin_expect(ft__get_sample_plexed(c, v) == 0, 0))
		return (0);
	s->n = n;
	s->ns = t - s->ns;
	s->alignment_faults = v[0];
	s->page_faults = v[1];
	s->cycles = v[2];
	s->instr = v[3];
	s->cache_ll = v[4];
	s->cache_miss = v[5];
	s->branches = v[6];
	s->branch_miss = v[7];
	return (1);
}
