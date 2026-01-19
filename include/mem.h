/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:14:01 by jaicastr          #+#    #+#             */
/*   Updated: 2026/01/19 20:47:23 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEM_H
# define MEM_H

# include <sys/types.h>
# include <stdlib.h>
# include <limits.h>
# include "alloc.h"
# include "structs.h"
# include "macros.h"

# define LONES_64 0x0101010101010101ULL
# define HIGHS_64 0x8080808080808080ULL

void			ft_bzero(void *__restrict__ ptr, size_t n)\
					__attribute__((__nonnull__(1)));

void			ft_memset(void *__restrict__ s, const t_u8 c, size_t n)\
					__attribute__((__nonnull__(1)));

void			ft_memcpy(void *__restrict__ dest,
					const void *__restrict__ src, size_t n)\
					__attribute__((__nonnull__(1, 2)));

void			ft_set(void *__restrict__ s, const t_u8 c, size_t n)\
					__attribute__((__nonnull__(1)));

void			ft_memtake(void *__restrict__ dest,
					void *__restrict__ src, size_t n)\
					__attribute__((__nonnull__(1, 2)));

void			*ft_memmove(void *__restrict__ dest,
					const void *__restrict__ src, size_t n)\
					__attribute__((__nonnull__(1, 2)));

void			*ft_memchr(const void *__restrict__ ptr, int c, size_t n)\
					__attribute__((__nonnull__(1)));

ssize_t			ft_memcmp(const void *__restrict__ const dest,
					const void *__restrict__ src, size_t n)\
					__attribute__((__nonnull__(1, 2)));

void			*ft_memclone(void *__restrict__ ptr, size_t size)\
					__attribute__((__nonnull__(1)));

void			*ft_memformat(void *restrict const ptr, size_t size)\
					__attribute__((__nonnull__(1)));

void			ft_membroadcast(void *dst, void *src, size_t chunks, size_t n)\
					__attribute__((__nonnull__(1, 2)));

t_u128			__hasz128(t_u128 x);
t_u64			__hasz64(t_u64 x);
t_u64			__populate(t_u8 y);

size_t			ft_memctz_u32(t_u32 x);
size_t			ft_memctz_u64(t_u64 x);
size_t			ft_memctz_u128(t_u128 x);

size_t			__max_s(size_t x, size_t y);
t_u8			__maxu8(t_u8 x, t_u8 y);
t_u32			__maxu32(t_u32 x, t_u32 y);
t_u64			__maxu64(t_u64 x, t_u64 y);
t_u128			__maxu128(t_u128 x, t_u128 y);

t_u128a			ft_murmur3(const t_u8 *restrict mem, size_t size)\
					__attribute__((__nonnull__(1), pure));
t_u128a			ft_murmur3_with_seed(const t_u8 *restrict mem, size_t seed,
					size_t size) __attribute__((__nonnull__(1), pure));

#endif
