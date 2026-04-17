/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perf_sampling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 21:34:52 by jaicastr          #+#    #+#             */
/*   Updated: 2026/04/17 21:35:16 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/ft_p_perf.h"

__attribute__((__nonnull__(1)))
void	ft_perf_start_sample(t_perf_counters c)
{
	ft_perf_counters_reset(c);
	ft_perf_counters_start(c);
}

__attribute__((__nonnull__(2, 3)))
int	ft_perf_collect_sample(size_t n,
	t_perf_counters c, t_perf_sample *s)
{
	t_u64	v[SW_COUNTERS_N + HW_COUNTERS_N];
	size_t	i;

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
	s->alignment_faults = v[1];
	s->ns = v[2];
	s->page_faults = v[3];
	s->cycles = v[4];
	s->instr = v[5];
	s->cache_ll = v[6];
	s->cache_miss = v[7];
	s->branches = v[8];
	s->branch_miss = v[9];
	return (1);
}
