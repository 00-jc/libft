/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_perf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 17:23:23 by jaicastr          #+#    #+#             */
/*   Updated: 2026/04/17 20:06:28 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_P_PERF_H
# define FT_P_PERF_H

# include "perf.h"

const t_hw_counters		*get_hw_counters(void)\
							__attribute__((const));

const t_sw_counters		*get_sw_counters(void)\
							__attribute__((const));

#endif
