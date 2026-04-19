/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tailor_summary.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 00:24:50 by jaicastr          #+#    #+#             */
/*   Updated: 2026/04/20 01:50:42 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "private/ft_p_tailor.h"
#include "io.h"
#include "bmi.h"
#include "private/ft_p_math.h"

__attribute__((__nonnull__(1, 2), __always_inline__))
static inline void	ft_sum_counters(t_perf_sample *src, t_perf_sample *sum,
	size_t n)
{
	size_t	i;

	*sum = (t_perf_sample){0};
	i = 0;
	while (i < n)
	{
		sum->cycles += src[i].cycles;
		sum->instr += src[i].instr;
		sum->cache_miss += src[i].cache_miss;
		sum->cache_ll += src[i].cache_ll;
		sum->branches += src[i].branches;
		sum->branch_miss += src[i].branch_miss;
		sum->alignment_faults += src[i].alignment_faults;
		sum->page_faults += src[i].page_faults;
		++i;
	}
}

__attribute__((__nonnull__(1, 2), __always_inline__))
static inline void	ft_percall(t_perf_sample *sum, t_v8da *v8d, double div)
{
	*v8d = (t_v8da){
		(double)sum->cycles, (double)sum->instr,
		(double)sum->cache_ll, (double)sum->cache_miss,
		(double)sum->branches, (double)sum->branch_miss,
		(double)sum->alignment_faults, (double)sum->page_faults};
	*v8d = *v8d / div;
}

static void	ft_print_body(t_perf_sample sum, t_v8da v8d, t_plankb plan,
	t_blk8r name)
{
	ft_printf("%s\n"
		"  cycles       = %f						instr=%f\n"
		"  ipc          = %f						(%lu/%lu)\n"
		"  LL     miss  = %f%%					(%f/%f per_call)\n"
		"  branch miss  = %f%%					(%f/%f per_call)\n"
		"  align faults = %f per_call\n"
		"  page  faults = %f per_call\n"
		"  total_iters  = %lu\n",
		name, v8d[0], v8d[1],
		ft_dtern(sum.cycles != 0,
			(double)sum.instr / (double)sum.cycles, 0.0),
		(unsigned long)sum.instr, (unsigned long)sum.cycles,
		ft_dtern(ft_fabs(v8d[2]) > 1e-9, (v8d[3] / v8d[2]) * 100.0, 0.0),
		v8d[3], v8d[2],
		ft_dtern(ft_fabs(v8d[4]) > 1e-9, (v8d[5] / v8d[4]) * 100.0, 0.0),
		v8d[5], v8d[4],
		v8d[6], v8d[7], plan.k_runs * plan.dp.iters);
}

__attribute__((__nonnull__(3, 4)))
void	ft_print_summary(t_buffer surv, t_plankb plan, t_blk8r name,
			t_u64a data[4])
{
	t_perf_sample	sum;
	t_v8da			v8d;
	size_t			it;

	__attribute__((assume(surv.mem != NULL)));
	ft_sum_counters((t_perf_sample *)surv.mem, &sum, surv.size);
	ft_percall(&sum, &v8d, (double)(surv.size * plan.dp.iters));
	it = plan.dp.iters;
	ft_print_body(sum, v8d, plan, name);
	ft_printf("  med          = %luns [%lu, %lu] min=%luns\n"
		"  relevant     = %lu samples (burst of=%lu iters)\n",
		data[0] / it, data[2] / it,
		data[3] / it, data[1] / it,
		surv.size, plan.dp.iters);
}
