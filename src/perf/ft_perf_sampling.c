/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perf_sampling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 19:01:33 by jaicastr          #+#    #+#             */
/*   Updated: 2026/04/17 20:40:26 by jaicastr         ###   ########.fr       */
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
	t_perf_read		buf;

	ft_perf_counters_stop(c);
	if (read((int)c[0], &buf, sizeof(t_perf_read)) == -1)
		return (0);
	s->ns = buf.kv[2].val;
	s->n = n;
	s->alignment_faults = buf.kv[1].val;
	s->page_faults = buf.kv[3].val;
	s->cycles = buf.kv[4].val;
	s->instr = buf.kv[5].val;
	s->cache_ll = buf.kv[6].val;
	s->cache_miss = buf.kv[7].val;
	s->branches = buf.kv[8].val;
	s->branch_miss = buf.kv[9].val;
	return (1);
}
