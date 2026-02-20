/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:14:01 by jaicastr          #+#    #+#             */
/*   Updated: 2026/02/19 21:25:21 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEM_H
# define MEM_H

# include <sys/types.h>
# include <stdlib.h>
# include <limits.h>
# include "types.h"
# include "bmi.h"

# define LONES_64 0x0101010101010101ULL
# define HIGHS_64 0x8080808080808080ULL

void			ft_bzero(void *restrict ptr, size_t n)\
					__attribute__((__nonnull__(1)));

void			ft_memset(void *restrict s, const t_u8 c, size_t n)\
					__attribute__((__nonnull__(1)));

void			ft_memcpy(void *restrict dest,
					const void *restrict src, size_t n)\
					__attribute__((__nonnull__(1, 2)));

void			ft_set(void *restrict s, const t_u8 c, size_t n)\
					__attribute__((__nonnull__(1)));

void			ft_memtake(void *restrict dest,
					void *restrict src, size_t n)\
					__attribute__((__nonnull__(1, 2)));

void			*ft_memmove(void *restrict dest,
					const void *restrict src, size_t n)\
					__attribute__((__nonnull__(1, 2)));

void			*ft_memchr(const void *restrict ptr, int c, size_t n)\
					__attribute__((__nonnull__(1)));

ssize_t			ft_memcmp(const void *restrict const dest,
					const void *restrict src, size_t n)\
					__attribute__((__nonnull__(1, 2)));

void			*ft_memclone(void *restrict ptr, size_t size)\
					__attribute__((__nonnull__(1)));

void			*ft_memformat(void *restrict const ptr, size_t size)\
					__attribute__((__nonnull__(1)));

void			ft_membroadcast(void *dst, void *src, size_t chunks, size_t n)\
					__attribute__((__nonnull__(1, 2)));

t_u128a			ft_murmur3(const t_u8 *restrict mem, size_t size)\
					__attribute__((__nonnull__(1), pure));

t_u128a			ft_murmur3_with_seed(const t_u8 *restrict mem, size_t seed,
					size_t size) __attribute__((__nonnull__(1), pure));

void			ft_prefetch0(const void *restrict const ptr, size_t size)\
					__attribute__((__nonnull__(1), __always_inline__));

void			ft_prefetch1(const void *restrict const ptr, size_t size)\
					__attribute__((__nonnull__(1), __always_inline__));

void			ft_prefetch2(const void *restrict const ptr, size_t size)\
					__attribute__((__nonnull__(1), __always_inline__));

void			ft_prefetchnta(const void *restrict const ptr, size_t size)\
					__attribute__((__nonnull__(1), __always_inline__));

#endif
