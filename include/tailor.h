/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tailor.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 19:32:06 by jaicastr          #+#    #+#             */
/*   Updated: 2026/04/18 19:35:45 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TAILOR_H
# define TAILOR_H

# include "perf.h"
# include "alloc.h"
# include "mem.h"

typedef void	(*t_tailor_fn)(void *);

typedef struct s_tailor
{
	t_arena				arena;
	t_tailor_fn			fns;
	size_t				n_fns;
	t_perf_counters		counters;
}	t_tailor;

#endif
