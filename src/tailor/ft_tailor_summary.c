/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tailor_summary.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 00:24:50 by jaicastr          #+#    #+#             */
/*   Updated: 2026/04/20 11:35:48 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "private/ft_p_tailor.h"
#include "io.h"
#include "bmi.h"

__attribute__((__nonnull__(1, 2), __always_inline__))
static inline void	ft_sum_counters(t_perf_sample *src, t_perf_sample *sum,
	size_t n)
{
	size_t	i;

	*sum = (t_perf_sample){0};
	i = 0;
	while (i < n)
	{
		sum->ns += src[i].ns;
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

static void	ft_print_head(t_perf_sample sum, t_plankb plan, t_blk8r name,
	t_u64a total_iters)
{
	ft_printf("%s\n"
		"  time         = %f ns per_call\n"
		"  cycles       = %f						instr=%f per_call\n"
		"  ipc          = %f\n",
		name,
		ft_dtern(total_iters != 0,
			(double)sum.ns / (double)total_iters, 0.0),
		(double)sum.cycles / (double)plan.dp.iters,
		(double)sum.instr / (double)plan.dp.iters,
		ft_dtern(sum.cycles != 0,
			(double)sum.instr / (double)sum.cycles, 0.0));
}

static void	ft_print_tail(t_perf_sample sum, t_plankb plan)
{
	double	bps;

	bps = ft_dtern(sum.ns != 0,
			(double)plan.dp.bytes_processed / (double)sum.ns * 1e9, 0.0) / 1e9;
	ft_printf(
		"  branch miss  = %f%%					        total_ratio=%lu/%lu\n"
		"  LL     miss  = %f%%					        total_ratio=%lu/%lu\n"
		"  align faults = %lu\n"
		"  page  faults = %lu\n"
		"  GB/sec       = %f\n",
		ft_dtern(sum.branches > 0,
			(double)sum.branch_miss / (double)sum.branches * 100.0, 0.0),
		sum.branch_miss, sum.branches,
		ft_dtern(sum.cache_ll > 0,
			(double)sum.cache_miss / (double)sum.cache_ll * 100.0, 0.0),
		sum.cache_miss, sum.cache_ll, sum.alignment_faults, sum.page_faults,
		bps);
}

__attribute__((__nonnull__(3, 4)))
void	ft_print_summary(t_buffer surv, t_plankb plan, t_blk8r name,
			t_u64a data[4])
{
	t_perf_sample	sum;
	t_u64a			total_iters;
	t_u64a			it;

	__attribute__((assume(surv.mem != NULL)));
	ft_sum_counters((t_perf_sample *)surv.mem, &sum, surv.size);
	total_iters = plan.k_runs * plan.dp.iters;
	it = plan.dp.iters;
	ft_print_head(sum, plan, name, total_iters);
	ft_print_tail(sum, plan);
	ft_printf("  total_iters  = %lu\n"
		"  med          = %luns [%lu, %lu] min=%luns\n"
		"  relevant     = %lu samples (burst of=%lu iters)\n",
		total_iters,
		data[0] / it, data[2] / it, data[3] / it, data[1] / it,
		(t_u64a)surv.size, (t_u64a)plan.dp.iters);
}
