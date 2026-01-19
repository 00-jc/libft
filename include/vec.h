/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:14:00 by jaicastr          #+#    #+#             */
/*   Updated: 2026/01/19 04:38:42 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file vec.h
 * @brief Header file for dynamic vector operations.
 *
 * This file contains the declarations and documentation for functions
 * that operate on dynamic vectors (t_vec).
 */

#ifndef VEC_H
# define VEC_H

# include "macros.h"
# include "mem.h"
# include "structs.h"
# include <stddef.h>

t_vec		ft_vec_new(size_t size, size_t type_size);

size_t		ft_vec_bytesize(const t_vec *restrict const v)\
				__attribute__((__nonnull__(1), __always_inline__, pure));

size_t		ft_vec_len(const t_vec *restrict const v, size_t type_size)\
				__attribute__((__nonnull__(1), __always_inline__, pure));

int			ft_vec_push_back(t_vec *restrict const vec,
				const t_u8 *restrict const data, size_t type_size)\
				__attribute__((__nonnull__(1, 2)));

const void	*ft_vec_get(const t_vec *restrict const vec, size_t idx,
				size_t type_size) __attribute__((__nonnull__(1),
					__always_inline__, pure));

void		*ft_vec_get_mut(const t_vec *restrict const vec, size_t idx,
				size_t type_size) __attribute__((__nonnull__(1),
					__always_inline__, pure));

void		*ft_vec_get_last(const t_vec *restrict const vec, size_t type_size)\
				__attribute__((__nonnull__(1), __always_inline__, pure));

const void	*ft_vec_peek_last(const t_vec *restrict const vec, size_t type_size)\
				__attribute__((__nonnull__(1), __always_inline__, pure));

int			ft_vec_reserve(t_vec *restrict const vec,
				size_t type_size, size_t n)\
				__attribute__((__nonnull__(1), __always_inline__));

int			ft_vec_extend(t_vec *restrict const vec,
				const t_u8 *restrict const data, size_t type_size, size_t n)\
				__attribute__((__nonnull__(1, 2)));

int			ft_vec_pop(t_vec *restrict const v, size_t type_size)\
				__attribute__((__always_inline__, __nonnull__(1)));

int			ft_vec_popmv(t_vec *restrict const v, void *const dest,
				size_t type_size) __attribute__((__always_inline__,
					__nonnull__(1)));

int			ft_vec_popf(t_vec *restrict const vec, size_t type_size,
				void (*f) (void *))\
				__attribute__((__nonnull__(1), __always_inline__));

void		ft_vec_free(t_vec *v)\
				__attribute__((__nonnull__(1)));

int			ft_vec_remove(t_vec *restrict const v, size_t i, size_t type_size)\
				__attribute__((__nonnull__(1)));

int			ft_vec_removef(t_vec *restrict const v, size_t i, size_t type_size,
				void (*f)(void *)) __attribute__((__nonnull__(1)));

void		ft_vec_clear(t_vec *restrict const v)\
				__attribute__((__nonnull__(1), __always_inline__));

#endif
