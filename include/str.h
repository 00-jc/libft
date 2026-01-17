/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 01:17:48 by jaicastr          #+#    #+#             */
/*   Updated: 2026/01/17 22:39:24 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_H
# define STR_H

# include "mem.h"
# include "alloc.h"

t_str		ft_str_new(size_t n)\
		__attribute__((warn_unused_result\
				("Allocation occurs at vec initialization")));

int			ft_str_push_back(t_str *restrict str, const t_u8 byte)\
				__attribute__((__nonnull__(1)));

int			ft_str_extend(t_str *restrict str,
				const t_u8 *restrict const data, size_t n)\
				__attribute__((__nonnull__(1)));

int			ft_str_remove(t_str *str, size_t idx)\
				__attribute__((nonnull(1)));

void		ft_str_free(t_str *s);

#endif
